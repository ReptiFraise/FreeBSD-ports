--- gpu/vulkan/semaphore_handle.cc.orig	2023-10-21 11:51:27 UTC
+++ gpu/vulkan/semaphore_handle.cc
@@ -39,7 +39,7 @@ SemaphoreHandle::SemaphoreHandle(gfx::GpuFenceHandle f
   // https://fuchsia.dev/reference/fidl/fuchsia.ui.scenic.
   Init(VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_ZIRCON_EVENT_BIT_FUCHSIA,
        std::move(fence_handle.owned_event));
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   Init(VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT_KHR,
        std::move(fence_handle.owned_fd));
 #elif BUILDFLAG(IS_POSIX)
@@ -64,7 +64,7 @@ gfx::GpuFenceHandle SemaphoreHandle::ToGpuFenceHandle(
   // VkSemaphore, which can then be used to submit present work, see
   // https://fuchsia.dev/reference/fidl/fuchsia.ui.scenic.
   fence_handle.owned_event = TakeHandle();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   if (type_ == VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT_KHR) {
     fence_handle.owned_fd = TakeHandle();
   } else {
