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
////#define FALSE 0
//
#define MY_BUS_NAME "a.example"
#define MY_BUS_OBJECT_PATH "/a/example" 
//
#define RET_SIGNAL_HANDLE_SIZE 4
//
static gulong g_RetSignalHandler[RET_SIGNAL_HANDLE_SIZE];

static exampleAExample * pProxy = NULL;
static GMainLoop         *pLoop     = NULL;

static exampleAExample *pSkeleton = NULL; 

static int callNum = 0;


static gboolean My_MethodA(exampleAExample     *object,
                               GDBusMethodInvocation *invocation,
                               const gchar           *in_arg,
                               gpointer               user_data)
{
    g_print("Server MyMethod1 call. Parameter: %s.\n", in_arg);

    in_arg = "Server My_Method1 to output.";

    example_a_example_complete_my_method_a(object, invocation, in_arg);

    return TRUE;
}

static gboolean My_MethodB(exampleAExample     *object,
                               GDBusMethodInvocation *invocation,
                               GVariant           *in_arg,
                               gpointer               user_data)
{
  gint in_arg1 = 0;
  gint in_arg2 = 0;
  gint out_arg2 = 0;
  gchar *out_arg1 = "Server MyMethod2 to output.";
  GVariant *out_arg = NULL;

  /** Get the input parameters */
  g_variant_get(in_arg, "(ii)", &in_arg1, &in_arg2);

  g_print("Server MyMethod2 call. Parameter: in_arg1 = %d , in_arg2 = %d.\n", in_arg1, in_arg2);

  /** Generate the output parameters */
  out_arg2 = in_arg1 + in_arg2;
  out_arg = g_variant_new("(si)", out_arg1, out_arg2);
   
  sleep(3);
   
  example_a_example_complete_my_method_b(object, invocation, out_arg);

  return TRUE;

}

static void bus_acquired_cb(GDBusConnection *connection,
                                const gchar     *bus_name,
                                gpointer         user_data)
{
    GError *pError = NULL;

    /** Second step: Try to get a connection to the given bus. */
    pSkeleton = example_a_example_skeleton_new();

    /** Third step: Attach to dbus signals. */
    (void) g_signal_connect(pSkeleton, "handle-my-method-a", G_CALLBACK(My_MethodA), NULL);
    (void) g_signal_connect(pSkeleton, "handle-my-method-b", G_CALLBACK(My_MethodB), NULL);
  
   g_printf("start to exprt\n");
  
    /** Fourth step: Export interface skeleton. */
    (void) g_dbus_interface_skeleton_export(G_DBUS_INTERFACE_SKELETON(pSkeleton),
                                              connection,
                                              MY_BUS_OBJECT_PATH,
                                              &pError);
    if(pError != NULL){
        g_print("Error: Failed to export object. Reason: %s.\n", pError->message);
        g_error_free(pError);
        g_main_loop_quit(pLoop);
    }
  
  g_printf("end exprt \n");
}

static void name_acquired_cb(GDBusConnection *connection,
                                     const gchar     *bus_name,
                                     gpointer         user_data)
{
    g_print("name_acquired_cb call, Acquired bus name: %s.\n", MY_BUS_NAME);
}

static void name_lost_cb(GDBusConnection *connection,
                             const gchar     *bus_name,
                             gpointer         user_data)
{
    if(connection == NULL)
    {
        g_print("name_lost_cb call, Error: Failed to connect to dbus.\n");
    }
    else
    {
        g_print("name_lost_cb call, Error: Failed to obtain bus name: %s.\n", MY_BUS_NAME);
    }

    g_main_loop_quit(pLoop);
}



static gboolean Emit_My_signalA(gconstpointer p)
{
    g_print("Emit_My_SignalA() is called.\n");

    gchar buf[20];
    memset(buf, 0, 20);
    callNum++;
    sprintf(buf, "Server Signal1(%d)", callNum);

    example_a_example_emit_my_signal_a (pSkeleton, buf);

    return TRUE;
}

static gboolean Emit_My_SignalB(gconstpointer p)
{
    g_print("Emit_My_SignalB() is called.\n");

    callNum++;
    GVariant *payload = g_variant_new("(is)", callNum, "Server Signal2");

    example_a_example_emit_my_signal_b(pSkeleton, payload);

    return TRUE;
}





int main()
{
	g_type_init();
	pLoop = g_main_loop_new( NULL,FALSE);
	g_bus_own_name( 2,
			 MY_BUS_NAME,
			G_BUS_NAME_OWNER_FLAGS_NONE,
			&bus_acquired_cb,
			&name_acquired_cb,
			&name_lost_cb,
			NULL,
			NULL);	

	g_timeout_add(1000, (GSourceFunc)Emit_My_signalA, NULL);
        g_timeout_add(2000, (GSourceFunc)Emit_My_SignalB, NULL);
	
	g_main_loop_run( pLoop);
	
        return 0;
}
