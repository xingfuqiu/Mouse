// HookManager.h: interface for the CHookManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HOOKMANAGER_H__CDFFD3CF_937D_4B4E_A77E_351F2B6CA2F9__INCLUDED_)
#define AFX_HOOKMANAGER_H__CDFFD3CF_937D_4B4E_A77E_351F2B6CA2F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// 事件列表结构体
struct S_ENODE 
{
	EVENTMSG Event;
	S_ENODE	 *lpNext;
};

// 事件头指针
extern S_ENODE *g_lpEventHead;  

// 录制和回放钩子
extern HHOOK g_hHookRecord;
extern HHOOK g_hHookPlayBack;

static	S_ENODE *g_lpEventTail = NULL;  // 已录制的事件的末尾
static	S_ENODE *g_lpPlayEvent = NULL;  // 当前正在播放的事件

class CHookManager  
{
public:
	CHookManager();
	virtual ~CHookManager();

public:
	int HMStartRecord(HWND hWnd,BOOL bNoMouse);
	int	HMStopRecord(int nNotifyCode = 0);

	int	HMStartPlayBack(HWND hWnd,BOOL bDoClear);
	int	HMStopPlayBack(int nNotifyCode = 0);
	
	void HMFreeAllEvents();
};

#endif // !defined(AFX_HOOKMANAGER_H__CDFFD3CF_937D_4B4E_A77E_351F2B6CA2F9__INCLUDED_)
