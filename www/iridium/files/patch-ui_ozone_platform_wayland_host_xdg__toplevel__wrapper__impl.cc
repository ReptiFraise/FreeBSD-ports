--- ui/ozone/platform/wayland/host/xdg_toplevel_wrapper_impl.cc.orig	2023-10-21 11:51:27 UTC
+++ ui/ozone/platform/wayland/host/xdg_toplevel_wrapper_impl.cc
@@ -308,7 +308,7 @@ void XDGToplevelWrapperImpl::OnToplevelConfigure(void*
           CheckIfWlArrayHasValue(states, XDG_TOPLEVEL_STATE_ACTIVATED),
   };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   if (xdg_toplevel_get_version(toplevel) >=
       XDG_TOPLEVEL_STATE_TILED_LEFT_SINCE_VERSION) {
     // All four tiled states have the same since version, so it is enough to
