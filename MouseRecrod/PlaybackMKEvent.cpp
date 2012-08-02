// PlaybackMKEvent.cpp: implementation of the CPlaybackMKEvent class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "PlaybackMKEvent.h"
#include "HookManager.h"
#include "CommDef.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPlaybackMKEvent::CPlaybackMKEvent()
{

}

CPlaybackMKEvent::~CPlaybackMKEvent()
{

}

// 开始回放
void CPlaybackMKEvent::StartPlayBack(HWND hWnd, int nClearPlaybackEvent)
{
	CHookManager HookManager;

	if (HookManager.HMStartPlayBack(hWnd,nClearPlaybackEvent))
    {
		OutputDebugStringA("你没有录制，还不能回放!");
		return;
	}
}

// 停止回放
void CPlaybackMKEvent::StopPlayBack()
{
	CHookManager HookManager;
	HookManager.HMStopRecord();
}
