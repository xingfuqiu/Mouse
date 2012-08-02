// RecordMKEvent.cpp: implementation of the CRecordMKEvent class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RecordMKEvent.h"
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

CRecordMKEvent::CRecordMKEvent()
{

}

CRecordMKEvent::~CRecordMKEvent()
{

}

// 开始录制
void CRecordMKEvent::StartRecord(HWND hWnd, int nOnlyKeyboardEvent) 
{
	CHookManager HookManager;

	if ( HookManager.HMStartRecord(hWnd,nOnlyKeyboardEvent))
    {
		return;
	}
}

// 停止录制
void CRecordMKEvent::StopRecord() 
{
	CHookManager HookManager;
	HookManager.HMStopRecord();
}