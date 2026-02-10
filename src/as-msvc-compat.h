/* as-msvc-compat.h - Compatibility macros for building AppStream with MSVC
 *
 * MSVC does not support __attribute__((cleanup)), which GLib uses for
 * g_autoptr, g_autofree, and g_auto macros. On MSVC, GLib leaves these
 * macros undefined.
 *
 * This header provides compatibility definitions that expand these macros
 * to plain variable declarations. The automatic cleanup behavior is lost,
 * meaning variables declared with these macros will NOT be automatically
 * freed when they go out of scope.
 *
 * NOTE: This is a pragmatic workaround to enable compilation on MSVC.
 * Functions using these macros should ideally have manual cleanup added
 * at their exit points for production use.
 */

#ifndef __AS_MSVC_COMPAT_H
#define __AS_MSVC_COMPAT_H

#ifdef _MSC_VER

/* MSVC does not provide POSIX ssize_t. Use Windows SSIZE_T. */
#include <basetsd.h>
#ifndef _SSIZE_T_DEFINED
typedef SSIZE_T ssize_t;
#define _SSIZE_T_DEFINED
#endif

#ifndef g_autoptr
#define g_autoptr(TypeName) TypeName *
#endif

#ifndef g_autofree
#define g_autofree
#endif

#ifndef g_auto
#define g_auto(TypeName) TypeName
#endif

#ifndef g_autolist
#define g_autolist(TypeName) GList *
#endif

#ifndef g_autoslist
#define g_autoslist(TypeName) GSList *
#endif

#ifndef g_autoqueue
#define g_autoqueue(TypeName) GQueue *
#endif

/* GLib may not define these on MSVC since cleanup isn't supported */
#ifndef G_DEFINE_AUTOPTR_CLEANUP_FUNC
#define G_DEFINE_AUTOPTR_CLEANUP_FUNC(TypeName, func)
#endif

#ifndef G_DEFINE_AUTO_CLEANUP_CLEAR_FUNC
#define G_DEFINE_AUTO_CLEANUP_CLEAR_FUNC(TypeName, func)
#endif

#ifndef G_DEFINE_AUTO_CLEANUP_FREE_FUNC
#define G_DEFINE_AUTO_CLEANUP_FREE_FUNC(TypeName, func, none)
#endif

#endif /* _MSC_VER */

#endif /* __AS_MSVC_COMPAT_H */
