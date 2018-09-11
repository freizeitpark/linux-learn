/*
 * Generated by gdbus-codegen 2.54.2. DO NOT EDIT.
 *
 * The license of this code is the same as for the source it was derived from.
 */

#ifndef __MINMINBUS_H__
#define __MINMINBUS_H__

#include <gio/gio.h>

G_BEGIN_DECLS


/* ------------------------------------------------------------------------ */
/* Declarations for com.fatminmin.GDBUS */

#define MIN_MIN_BUS_TYPE_GDBUS (min_min_bus_gdbus_get_type ())
#define MIN_MIN_BUS_GDBUS(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), MIN_MIN_BUS_TYPE_GDBUS, MinMinBusGDBUS))
#define MIN_MIN_BUS_IS_GDBUS(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), MIN_MIN_BUS_TYPE_GDBUS))
#define MIN_MIN_BUS_GDBUS_GET_IFACE(o) (G_TYPE_INSTANCE_GET_INTERFACE ((o), MIN_MIN_BUS_TYPE_GDBUS, MinMinBusGDBUSIface))

struct _MinMinBusGDBUS;
typedef struct _MinMinBusGDBUS MinMinBusGDBUS;
typedef struct _MinMinBusGDBUSIface MinMinBusGDBUSIface;

struct _MinMinBusGDBUSIface
{
  GTypeInterface parent_iface;

  gboolean (*handle_hello_world) (
    MinMinBusGDBUS *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_greeting);

};

GType min_min_bus_gdbus_get_type (void) G_GNUC_CONST;

GDBusInterfaceInfo *min_min_bus_gdbus_interface_info (void);
guint min_min_bus_gdbus_override_properties (GObjectClass *klass, guint property_id_begin);


/* D-Bus method call completion functions: */
void min_min_bus_gdbus_complete_hello_world (
    MinMinBusGDBUS *object,
    GDBusMethodInvocation *invocation,
    const gchar *response);



/* D-Bus method calls: */
void min_min_bus_gdbus_call_hello_world (
    MinMinBusGDBUS *proxy,
    const gchar *arg_greeting,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean min_min_bus_gdbus_call_hello_world_finish (
    MinMinBusGDBUS *proxy,
    gchar **out_response,
    GAsyncResult *res,
    GError **error);

gboolean min_min_bus_gdbus_call_hello_world_sync (
    MinMinBusGDBUS *proxy,
    const gchar *arg_greeting,
    gchar **out_response,
    GCancellable *cancellable,
    GError **error);



/* ---- */

#define MIN_MIN_BUS_TYPE_GDBUS_PROXY (min_min_bus_gdbus_proxy_get_type ())
#define MIN_MIN_BUS_GDBUS_PROXY(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), MIN_MIN_BUS_TYPE_GDBUS_PROXY, MinMinBusGDBUSProxy))
#define MIN_MIN_BUS_GDBUS_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), MIN_MIN_BUS_TYPE_GDBUS_PROXY, MinMinBusGDBUSProxyClass))
#define MIN_MIN_BUS_GDBUS_PROXY_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), MIN_MIN_BUS_TYPE_GDBUS_PROXY, MinMinBusGDBUSProxyClass))
#define MIN_MIN_BUS_IS_GDBUS_PROXY(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), MIN_MIN_BUS_TYPE_GDBUS_PROXY))
#define MIN_MIN_BUS_IS_GDBUS_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), MIN_MIN_BUS_TYPE_GDBUS_PROXY))

typedef struct _MinMinBusGDBUSProxy MinMinBusGDBUSProxy;
typedef struct _MinMinBusGDBUSProxyClass MinMinBusGDBUSProxyClass;
typedef struct _MinMinBusGDBUSProxyPrivate MinMinBusGDBUSProxyPrivate;

struct _MinMinBusGDBUSProxy
{
  /*< private >*/
  GDBusProxy parent_instance;
  MinMinBusGDBUSProxyPrivate *priv;
};

struct _MinMinBusGDBUSProxyClass
{
  GDBusProxyClass parent_class;
};

GType min_min_bus_gdbus_proxy_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (MinMinBusGDBUSProxy, g_object_unref)
#endif

void min_min_bus_gdbus_proxy_new (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
MinMinBusGDBUS *min_min_bus_gdbus_proxy_new_finish (
    GAsyncResult        *res,
    GError             **error);
MinMinBusGDBUS *min_min_bus_gdbus_proxy_new_sync (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);

void min_min_bus_gdbus_proxy_new_for_bus (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
MinMinBusGDBUS *min_min_bus_gdbus_proxy_new_for_bus_finish (
    GAsyncResult        *res,
    GError             **error);
MinMinBusGDBUS *min_min_bus_gdbus_proxy_new_for_bus_sync (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);


/* ---- */

#define MIN_MIN_BUS_TYPE_GDBUS_SKELETON (min_min_bus_gdbus_skeleton_get_type ())
#define MIN_MIN_BUS_GDBUS_SKELETON(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), MIN_MIN_BUS_TYPE_GDBUS_SKELETON, MinMinBusGDBUSSkeleton))
#define MIN_MIN_BUS_GDBUS_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), MIN_MIN_BUS_TYPE_GDBUS_SKELETON, MinMinBusGDBUSSkeletonClass))
#define MIN_MIN_BUS_GDBUS_SKELETON_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), MIN_MIN_BUS_TYPE_GDBUS_SKELETON, MinMinBusGDBUSSkeletonClass))
#define MIN_MIN_BUS_IS_GDBUS_SKELETON(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), MIN_MIN_BUS_TYPE_GDBUS_SKELETON))
#define MIN_MIN_BUS_IS_GDBUS_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), MIN_MIN_BUS_TYPE_GDBUS_SKELETON))

typedef struct _MinMinBusGDBUSSkeleton MinMinBusGDBUSSkeleton;
typedef struct _MinMinBusGDBUSSkeletonClass MinMinBusGDBUSSkeletonClass;
typedef struct _MinMinBusGDBUSSkeletonPrivate MinMinBusGDBUSSkeletonPrivate;

struct _MinMinBusGDBUSSkeleton
{
  /*< private >*/
  GDBusInterfaceSkeleton parent_instance;
  MinMinBusGDBUSSkeletonPrivate *priv;
};

struct _MinMinBusGDBUSSkeletonClass
{
  GDBusInterfaceSkeletonClass parent_class;
};

GType min_min_bus_gdbus_skeleton_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (MinMinBusGDBUSSkeleton, g_object_unref)
#endif

MinMinBusGDBUS *min_min_bus_gdbus_skeleton_new (void);


G_END_DECLS

#endif /* __MINMINBUS_H__ */
