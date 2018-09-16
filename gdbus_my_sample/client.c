
#include <gio/gio.h>    /** GIO for dbus*/
#include <glib-2.0/glib.h>  /** GLIB for main loop*/  
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <gio/gio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "generated-code.h"

//#define TRUE 1
//#define FALSE 0

#define MY_BUS_NAME "a.example"
#define MY_BUS_OBJECT_PATH "/a/example" 

#define RET_SIGNAL_HANDLE_SIZE 4

static gulong g_RetSignalHandler[RET_SIGNAL_HANDLE_SIZE];
static GMainLoop *pLoop = NULL;

static exampleAExample * pProxy = NULL;

static gboolean My_Signal_a_Handler(exampleAExample *object, const gchar *arg, gpointer userdata)
{	
    g_print("Signal_1_Callback: Paramater value: %s.\n", arg);
    return TRUE;
}

static gboolean My_Signal_b_Handler(exampleAExample *object,  GVariant *arg, gpointer userdata)
{
    /** get the value from GVariant */
    gint int_arg = 0;
    gchar *char_arg = NULL;

    g_variant_get(arg, "(is)", &int_arg, &char_arg);

    g_print("Signal_2_Callback: Int value: %d, String value: %s\n", int_arg, char_arg);

    g_free(char_arg);

    return TRUE;
}

static void cb_OwnerNameChangedNotify(GObject *object, GParamSpec *pspec, gpointer userdata)
{
    gchar *pname_owner = NULL;
    pname_owner = g_dbus_proxy_get_name_owner((GDBusProxy*)object);

    if (NULL != pname_owner){
        g_print("DBus service is ready!\n");
        g_free(pname_owner);
    }
    else{
        g_print("DBus service is NOT ready!\n");
        g_free(pname_owner);
    }
}

int registerClientSignalHander(exampleAExample* pProxy )
{
	g_printf("resigter client signal handler \n");
	g_RetSignalHandler[0] = g_signal_connect(pProxy, "notify::g-name-owner", G_CALLBACK(cb_OwnerNameChangedNotify), NULL);
        g_RetSignalHandler[1] = g_signal_connect(pProxy, "my-signal-a", G_CALLBACK(My_Signal_a_Handler), NULL);
        g_RetSignalHandler[2] = g_signal_connect(pProxy, "my-signal-b", G_CALLBACK(My_Signal_b_Handler), NULL);
        return TRUE;
}

void InitGdbus()
{
	GError *pConnError = NULL;
	GError *pProxyError = NULL;	
	GDBusConnection * pConnection = NULL;	
//	exampleAExample * pProxy = NULL;
	int bRect;

	g_type_init();
	g_printf("client start\n");
	
	do {
		bRect = TRUE;
		pLoop = g_main_loop_new( NULL, FALSE);
		
		pConnection = g_bus_get_sync(/*G_BUS_TYPE_SEESION*/2 ,NULL,&pConnError );
		
		if( NULL == pConnError ){
			pProxy = example_a_example_proxy_new_sync( pConnection,
							G_DBUS_PROXY_FLAGS_NONE,
							MY_BUS_NAME,
							MY_BUS_OBJECT_PATH,
							NULL,
							&pProxyError );
			if( 0 == pProxy){
				g_printf(" failed to create proxy : %s\n",pProxyError->message);
				g_error_free( pProxyError);
				bRect = FALSE;
			}

		}else{
			g_printf(" failed to cnn dbus : %s\n",pConnError->message);
			g_error_free( pConnError);
			bRect = FALSE;
		}

	} while(bRect == FALSE);

	registerClientSignalHander( pProxy );
	
	//	g_main_loop_run(pLoop );
	//thread_create();
}

int IsReady()
{
    gchar *owner_name = NULL;
    owner_name = g_dbus_proxy_get_name_owner((GDBusProxy*)pProxy);
    if(NULL != owner_name)
    {
        g_print("Owner Name: %s\n", owner_name);        
        g_free(owner_name);
        return TRUE;
    }	   
}



void myMethod_a(const gchar *in_arg, gchar** out_arg, GError** pError)
{

  example_a_example_call_my_method_a_sync (pProxy, in_arg, out_arg, NULL, pError);
/*
 96 gboolean example_a_example_call_my_method_a_sync (
 97     exampleAExample *proxy,
 98     const gchar *arg_InArg,
 99     gchar **out_OutArg,
100     GCancellable *cancellable,
101     GError **error);
*/
 
    if (*pError == NULL){
        g_print("client myMethod_1 call, in_arg = %s out_arg = %s.\n", in_arg, *out_arg);
            g_free(*out_arg);
    }
    else{
            g_print("client myMethod_1: Failed to call method. Reason: %s.\n", (*pError)->message);
            g_error_free(*pError);
    }

    return; 
}

//-----------------------------------------------------------------------------------------

static void MethodCallback_b(GObject* source_object, GAsyncResult* res, gpointer user_data)
{
    g_print("client MethodCallback_b call.\n");

    GVariant *out_arg = NULL;
    GError *pError = NULL;
    gchar *out_arg1 = NULL;
    gint out_arg2 = 0;

    example_a_example_call_my_method_b_finish(pProxy, &out_arg, res, &pError);
    if (NULL == pError){
        /** get the result from the output paramter */
        	g_variant_get(out_arg, "(si)", &out_arg1, &out_arg2);
            
                g_print("Signal_2_Callback: Int value: %d, String value: %s\n", out_arg2, out_arg1);
		
		g_free(out_arg1);
    }
    else{
        g_error_free(pError);
    }
   
   g_printf("   asyn call finish. \n");
}

void myMethodAsync_b(const gint in_arg1, const gint in_arg2)
{
    g_print("client myMethodAsync_b call, in_arg1 = %d, in_arg2 = %d.\n", in_arg1, in_arg2);

    GVariant *in_arg = g_variant_new("(ii)", in_arg1, in_arg2);
   example_a_example_call_my_method_b(pProxy, in_arg, NULL, MethodCallback_b, NULL);

    return;
}

void  myMethod_asyn()
{
    g_printf(" asyn call 2 \n ");
    gint asyncMethod2Arg1 = 10;
    gint asyncMethod2Arg2 = 21;
    myMethodAsync_b(asyncMethod2Arg1, asyncMethod2Arg2);

}

// ---------------------------------------------------------------------------------------------
void* Call(void* arg)
{

    while(1) {
      
      g_printf(" call ..\n");  
    
      const gchar *syncMehtod1Arg = "method1 synchronize call.";
      gchar *syncMethod1Out = NULL;
      GError *syncMethodError = NULL;

      myMethod_a(syncMehtod1Arg, &syncMethod1Out, &syncMethodError);
      myMethod_asyn();
      sleep(10);
   }

    return ((void*)0);
}

void *run(void* arg)
{
    g_print("run call in the client.\n");
    /** start the main event loop which manages all available sources of events */
    g_main_loop_run(pLoop);

    return ((void*)0);
}

int thread_create(pthread_t* thr)
{
    int err;
  //dd  pthread_t thr;

    pthread_create(thr, NULL, run, NULL);

    if(0 != err){
            g_print("Can't create thread: %s\n", strerror(err));
    }
    else{       
            g_print("New thread created: %s\n", strerror(err));
    }

    return err;
}

int thread_create_call(pthread_t* thr)
{
    int err;
  //dd  pthread_t thr;

    pthread_create(thr, NULL, Call, NULL);

    if(0 != err){
            g_print("Can't create thread call: %s\n", strerror(err));
    }
    else{       
            g_print("New thread created call: %s\n", strerror(err));
    }

    return err;
}


int main()
{
	printf(" gdbus main \n");
	
	InitGdbus();
          
        pthread_t pSignal = NULL ;
        thread_create(&pSignal);        
	
	IsReady();
	
        pthread_t pFunc = NULL ;
        thread_create_call(&pFunc);
           
         int * tmp;        

        pthread_join(pSignal,(void**)&tmp);
        pthread_join(pFunc,(void**)&tmp);
                    

	return 0;

}
