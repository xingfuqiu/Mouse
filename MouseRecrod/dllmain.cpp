// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
#include "PlaybackMKEvent.h"
#include "RecordMKEvent.h"
#include "CommDef.h"
#include "HookManager.h"
#include "MessageHandle.h"

extern HINSTANCE gInstance;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{	
	gInstance = hModule;
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

extern "C" BOOL __stdcall MR_StartRecord(HWND ahWnd, int nOnlyKeyborad)
{
	CRecordMKEvent RecordMKEvent;
	RecordMKEvent.StartRecord(ahWnd, nOnlyKeyborad);
	return TRUE;
}

extern "C" BOOL __stdcall MR_StopRecord()
{
	CRecordMKEvent RecordMKEvent;
	RecordMKEvent.StopRecord();
	return TRUE;
}

extern "C" BOOL __stdcall MR_StartPlayBack(HWND ahWnd, int nDoClear)
{
	CPlaybackMKEvent PlaybackMKEvent;
	PlaybackMKEvent.StartPlayBack(ahWnd, nDoClear);
	return TRUE;
}

extern "C" BOOL __stdcall MR_StopPlayBack()
{
	CPlaybackMKEvent PlaybackMKEvent;
	PlaybackMKEvent.StopPlayBack();
	return TRUE;
}

