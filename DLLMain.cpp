<<<<<<< HEAD
#include "Cheat.h"

#include "C:\Program Files\VMProtect Ultimate\Include\C\VMProtectSDK.h"

=======
#include "Cheat.h"

#include "C:\Program Files\VMProtect Ultimate\Include\C\VMProtectSDK.h"

>>>>>>> 4d5615fbb2fcbb0d8657fa851f63b1f3d1b78c6f
#define JUNKS \
__asm _emit 0x86 \
__asm _emit 0x28 \
__asm _emit 0x20 \
__asm _emit 0x05 \
__asm _emit 0x47 \
__asm _emit 0x44 \
__asm _emit 0x87 \
__asm _emit 0x75 \
__asm _emit 0x79 \
__asm _emit 0x71 \
// Don't change this!
<<<<<<< HEAD
#define _JUNK_BLOCK(s) __asm jmp s JUNKS __asm s:

void CheatThread()
{
	VMProtectBeginUltra("CT");

	_JUNK_BLOCK(jmp_label1)
	/*auto BuildNumber = I::Engine->GetEngineBuildNumber();
	if (BuildNumber != 13615)
	{
		MessageBox(0, "Update Detected, please Contact Ferrity", "FH4x", MB_OK);
		I::Engine->ClientCmd_Unrestricted("cl_mouseenable 1", 0);
		I::Engine->ClientCmd_Unrestricted("crosshair 1", 0);
		I::Engine->ClientCmd_Unrestricted("clear", 0);
		exit(0);
	}
	else*/
	{
		_JUNK_BLOCK(jmp_label2)
=======
#define _JUNK_BLOCK(s) __asm jmp s JUNKS __asm s:

void CheatThread()
{
	VMProtectBeginUltra("CT");

	_JUNK_BLOCK(jmp_label1)
	/*auto BuildNumber = I::Engine->GetEngineBuildNumber();
	if (BuildNumber != 13615)
	{
		MessageBox(0, "Update Detected, please Contact Ferrity", "FH4x", MB_OK);
		I::Engine->ClientCmd_Unrestricted("cl_mouseenable 1", 0);
		I::Engine->ClientCmd_Unrestricted("crosshair 1", 0);
		I::Engine->ClientCmd_Unrestricted("clear", 0);
		exit(0);
	}
	else*/
	{
		_JUNK_BLOCK(jmp_label2)
>>>>>>> 4d5615fbb2fcbb0d8657fa851f63b1f3d1b78c6f
		FLASHWINFO fi;
		fi.cbSize = sizeof( FLASHWINFO );
		fi.hwnd = G::Window;
		fi.dwFlags = FLASHW_ALL | FLASHW_TIMERNOFG;
		fi.uCount = 0;
		fi.dwTimeout = 0;
<<<<<<< HEAD
		FlashWindowEx( &fi );
		_JUNK_BLOCK(jmp_label3)
		if (GetForegroundWindow() != G::Window)
			ShowWindow(G::Window, SW_RESTORE);
		SetActiveWindow(G::Window);
		/*MessageBox(0, "FH4x Private CS:GO Bot", "Enjoy", MB_OK);*/
		_JUNK_BLOCK(jmp_label4)
		U::Setup();
		/*AllocConsole();*/
		freopen("CONIN$", "r", stdin);
		freopen("CONOUT$", "w", stdout);
		freopen("CONOUT$", "w", stderr);
		SetConsoleTitle("FH4x Debug Console");
		Security->CheckAllPorcesses();
        I::Engine->ClientCmd_Unrestricted("toggleconsole", 0);
		/*I::Engine->ClientCmd_Unrestricted("net_graph 1", 0);*/
		Sleep(100);
		I::Engine->ClientCmd_Unrestricted("clear", 0);
		I::Engine->ClientCmd_Unrestricted("echo -----------------------------------------------", 0);
		I::Engine->ClientCmd_Unrestricted("echo FH4x DEV-LOG | Updated: 10.12.17", 0);
		I::Engine->ClientCmd_Unrestricted("echo -----------------------------------------------", 0);
		I::Engine->ClientCmd_Unrestricted("echo  ", 0);
		//I::Engine->ClientCmd_Unrestricted("echo + Added Auto Resolver[Beta] under Ragebot", 0);
	/*	I::Engine->ClientCmd_Unrestricted("echo  ", 0);*/
		I::Engine->ClientCmd_Unrestricted("echo + Added pAutostop", 0);
		I::Engine->ClientCmd_Unrestricted("echo  ", 0);
		I::Engine->ClientCmd_Unrestricted("echo + Added New Antiaim System", 0);
		I::Engine->ClientCmd_Unrestricted("echo  ", 0);
		I::Engine->ClientCmd_Unrestricted("echo -----------------------------------------------", 0);
		Sleep(100);
		I::Engine->ClientCmd_Unrestricted("crosshair 1", 0);
		_JUNK_BLOCK(jmp_label5)


		while (!G::PressedKeys[VK_END])
		{
			Security->CheckAllPorcesses();

			E::Misc->Panic();

			Sleep(1000);
		}

		VMProtectEnd();

	}
	
}


DWORD WINAPI DllMain( HMODULE hDll, DWORD dwReason, LPVOID lpReserved )
{
	_JUNK_BLOCK(jmp_label6)
	switch( dwReason )
	{
	case DLL_PROCESS_ATTACH:
	{
		/*Beep(659, 200);
		Beep(659, 200);
		Sleep(200);
		Beep(659, 200);
		Sleep(100);
		Beep(523, 200);
		Beep(659, 200);
		Sleep(200);
		Beep(783, 200);
		Sleep(400);
		Beep(391, 200);*/
		_JUNK_BLOCK(jmp_label7)
		Security->HideModuleFromPEB(hDll);
		Security->HideModuleXta(hDll);
		Security->RemovePeHeader((DWORD)hDll);
		Security->DestroyModuleHeader(hDll);
		Security->HideMod(hDll);
		DisableThreadLibraryCalls(hDll);
		_JUNK_BLOCK(jmp_label8)
		Security->Check();
		_JUNK_BLOCK(jmp_label9)
		while( !( G::Window = FindWindowA( charenc( "Valve001" ), NULL ) ) ) Sleep( 200 );

		Hooks::oldWindowProc = ( WNDPROC )SetWindowLongPtr( G::Window, GWL_WNDPROC, ( LONG_PTR )Hooks::WndProc );

		CreateThread( NULL, NULL, ( LPTHREAD_START_ROUTINE )CheatThread, NULL, NULL, NULL );

		G::Dll = hDll;

		return TRUE;
	}
	case DLL_PROCESS_DETACH:
	{
		return TRUE;
	}

	return FALSE;
	}
=======
		FlashWindowEx( &fi );
		_JUNK_BLOCK(jmp_label3)
		if (GetForegroundWindow() != G::Window)
			ShowWindow(G::Window, SW_RESTORE);
		SetActiveWindow(G::Window);
		/*MessageBox(0, "FH4x Private CS:GO Bot", "Enjoy", MB_OK);*/
		_JUNK_BLOCK(jmp_label4)
		U::Setup();
		/*AllocConsole();*/
		freopen("CONIN$", "r", stdin);
		freopen("CONOUT$", "w", stdout);
		freopen("CONOUT$", "w", stderr);
		SetConsoleTitle("FH4x Debug Console");
		Security->CheckAllPorcesses();
        I::Engine->ClientCmd_Unrestricted("toggleconsole", 0);
		/*I::Engine->ClientCmd_Unrestricted("net_graph 1", 0);*/
		Sleep(100);
		I::Engine->ClientCmd_Unrestricted("clear", 0);
		I::Engine->ClientCmd_Unrestricted("echo -----------------------------------------------", 0);
		I::Engine->ClientCmd_Unrestricted("echo FH4x DEV-LOG | Updated: 10.12.17", 0);
		I::Engine->ClientCmd_Unrestricted("echo -----------------------------------------------", 0);
		I::Engine->ClientCmd_Unrestricted("echo  ", 0);
		//I::Engine->ClientCmd_Unrestricted("echo + Added Auto Resolver[Beta] under Ragebot", 0);
	/*	I::Engine->ClientCmd_Unrestricted("echo  ", 0);*/
		I::Engine->ClientCmd_Unrestricted("echo + Added pAutostop", 0);
		I::Engine->ClientCmd_Unrestricted("echo  ", 0);
		I::Engine->ClientCmd_Unrestricted("echo + Added New Antiaim System", 0);
		I::Engine->ClientCmd_Unrestricted("echo  ", 0);
		I::Engine->ClientCmd_Unrestricted("echo -----------------------------------------------", 0);
		Sleep(100);
		I::Engine->ClientCmd_Unrestricted("crosshair 1", 0);
		_JUNK_BLOCK(jmp_label5)


		while (!G::PressedKeys[VK_END])
		{
			Security->CheckAllPorcesses();

			E::Misc->Panic();

			Sleep(1000);
		}

		VMProtectEnd();

	}
	
}


DWORD WINAPI DllMain( HMODULE hDll, DWORD dwReason, LPVOID lpReserved )
{
	_JUNK_BLOCK(jmp_label6)
	switch( dwReason )
	{
	case DLL_PROCESS_ATTACH:
	{
		/*Beep(659, 200);
		Beep(659, 200);
		Sleep(200);
		Beep(659, 200);
		Sleep(100);
		Beep(523, 200);
		Beep(659, 200);
		Sleep(200);
		Beep(783, 200);
		Sleep(400);
		Beep(391, 200);*/
		_JUNK_BLOCK(jmp_label7)
		Security->HideModuleFromPEB(hDll);
		Security->HideModuleXta(hDll);
		Security->RemovePeHeader((DWORD)hDll);
		Security->DestroyModuleHeader(hDll);
		Security->HideMod(hDll);
		DisableThreadLibraryCalls(hDll);
		_JUNK_BLOCK(jmp_label8)
		Security->Check();
		_JUNK_BLOCK(jmp_label9)
		while( !( G::Window = FindWindowA( charenc( "Valve001" ), NULL ) ) ) Sleep( 200 );

		Hooks::oldWindowProc = ( WNDPROC )SetWindowLongPtr( G::Window, GWL_WNDPROC, ( LONG_PTR )Hooks::WndProc );

		CreateThread( NULL, NULL, ( LPTHREAD_START_ROUTINE )CheatThread, NULL, NULL, NULL );

		G::Dll = hDll;

		return TRUE;
	}
	case DLL_PROCESS_DETACH:
	{
		return TRUE;
	}

	return FALSE;
	}
>>>>>>> 4d5615fbb2fcbb0d8657fa851f63b1f3d1b78c6f
}