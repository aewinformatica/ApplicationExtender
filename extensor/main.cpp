#include "main.h"
#include <windows.h>
#include <winuser.h>

SPLASH g_SplashScreen;
CHookManager g_HookManager;
	
extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpvReserved)
{
    switch (dwReason)
    {
        case DLL_PROCESS_ATTACH:
		{
							// g_SplashScreen.Init(NULL, hInstance, IDB_BITMAP3);
				// g_SplashScreen.Show();
				// HWND firefox = FindWindow("Windows Application", NULL);
  	 //   	        SetWindowText(firefox, "Found it!!");
				// g_SplashScreen.Hide();
				// g_HookManager.WriteCall(0x64418E, COtherAction::CreateWindowExWHook, 1);
		}
            
            break;
         case DLL_PROCESS_DETACH:
            // detach from process
            break;
        case DLL_THREAD_ATTACH:
            // attach to thread
            break;
        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE;// succesful
}