// HookManager.cpp: implementation of the CHookManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HookManager.h"
#include "malloc.h"
#include "CommDef.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

HHOOK g_hHookRecord = NULL;
HHOOK g_hHookPlayBack = NULL;

S_ENODE *g_lpEventHead	= NULL;  // 已录制的事件头

static	HWND  g_hWndManager	= NULL;
static	BOOL  g_bNoMouse = FALSE;
static	BOOL  g_bDoClear = FALSE;
static	BOOL  g_bSysModalOn	= FALSE;

extern HINSTANCE gInstance;

// 消息函数
LRESULT CALLBACK JournalRecorderFunc(int nCode, WPARAM wParam, LPARAM lParam );
LRESULT CALLBACK JournalPlaybackFunc(int nCode, WPARAM wParam, LPARAM lParam );
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CHookManager::CHookManager()
{

}

CHookManager::~CHookManager()
{

}

///////////////////////////////////////////////////////////////////////////////

// 释放所有事件
void CHookManager::HMFreeAllEvents()
{
	while ( g_lpEventHead ) // 是事件头
    {
		S_ENODE* p = g_lpEventHead->lpNext;
		free( g_lpEventHead );
		g_lpEventHead = p;
	}
    
	g_lpEventTail = NULL;
	g_lpPlayEvent = NULL;
}

// 开始录制
int CHookManager::HMStartRecord(HWND hWnd,BOOL bNoMouse)
{
	if ( g_hHookRecord != 0 )
    {
        return -1;
    }
		
	HMFreeAllEvents();	// 释放所有事件

	g_hWndManager = hWnd;
	g_bSysModalOn = FALSE;
	g_bNoMouse	  = bNoMouse;
    
    // 需要监视系统消息时要调用SetWindowsHookEx对消息进行监视。
    // 通过SetwindowsHookEx函数将消息函数JournalRecorderFunc()加入到消息监视链中就可以处理消息了
    // WH_JOURNALRECORD是监视函数类型，获得鼠标、键盘动作消息。
    // 建立键盘鼠标操作消息纪录回放链
	g_hHookRecord = SetWindowsHookEx( WH_JOURNALRECORD, 
                                      JournalRecorderFunc, 
									  GetModuleHandle(NULL), 
                                      0 );

	return 0;
}


// JournalRecorderFunc为消息函数；
// CALLBACK说明该消息函数被系统调用。
// 系统会调用该函数并将消息值传递给该函数供处理。
// code为系统指示标记，wParam和lParam为附加参数，根据不同的消息监视类型而不同
// WPARAM   A value passed as a parameter to a window procedure or callback function: 16 bits on Windows versions 3.0 and 3.1; 32 bits on Win32
// LPARAM 32-bit message parameter 
// JournalRecorderFunc是记录操作的消息函数，每当有鼠标键盘消息发生时，系统都会调用该函数，消息信息就保存在地址lParam中，我们可以讲消息保存在一个数组中
LRESULT CALLBACK JournalRecorderFunc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if ( !g_hHookRecord )
    {
        return 0;
    }

	CHookManager HookManager;

	if ( nCode == HC_SYSMODALON )
    {
        g_bSysModalOn = TRUE;
    }		
	else if ( nCode == HC_SYSMODALOFF )
    {
        g_bSysModalOn = FALSE;
    }		
	else if ( nCode == HC_ACTION && g_hHookPlayBack )	 
    { 
		// 当回放时，跳过录制
		
		HookManager.HMStopRecord(RECORD_BUSY);
		
		return 0;
	}
    else
    {
        // 这里不需要做任何事情.
    }

	if ( nCode == HC_ACTION && !g_bSysModalOn ) 
    {
		LPEVENTMSG lpEvent= (LPEVENTMSG)lParam;

		// 通过按CTRL + BREAK键，可以停止录制
		if ( lpEvent->message == WM_KEYDOWN && 
             LOBYTE(lpEvent->paramL) == VK_CANCEL ) 
        {			
			HookManager.HMStopRecord(RECORD_DONE);
			
			return 0;
		}
		
        // 分配内存
		S_ENODE *lpEventNode = (S_ENODE*)malloc(sizeof(S_ENODE));

		if ( lpEventNode == NULL ) 
        {	
            // 内存不足
			HookManager.HMStopRecord(RECORD_MEMORY);
            
			return 0;
		}

		if ( g_lpEventTail == NULL )
        {
            g_lpEventHead = lpEventNode;
        }			
		else
        {
            g_lpEventTail->lpNext = lpEventNode;
        }
			
		g_lpEventTail = lpEventNode;
		g_lpEventTail->lpNext = NULL;

		g_lpEventTail->Event.message = lpEvent->message;
		g_lpEventTail->Event.paramL	= lpEvent->paramL;
		g_lpEventTail->Event.paramH	= lpEvent->paramH;
		g_lpEventTail->Event.time = GetTickCount();
		g_lpEventTail->Event.hwnd = NULL;

		// 通知事件已被录制
		PostMessage( g_hWndManager, 
                     WM_MANAGER_INFO, 
                     RECORD_EVENT, 
                     (LPARAM)g_lpEventTail );
		
		return 0;
	}

   return ( CallNextHookEx(g_hHookRecord, nCode, wParam, lParam) );
}

// 停止录制
int CHookManager::HMStopRecord(int nNotifyCode)
{
	if (g_hHookRecord == 0)
    {
        return -1;
    }
	
    // 在不需要监视系统消息时要调用UnHookWindowsHookEx来解除对消息的监视。
	UnhookWindowsHookEx( g_hHookRecord );
	
	g_hHookRecord = NULL;

	g_lpEventTail = NULL;
	g_lpPlayEvent = NULL;

	if (nNotifyCode != 0)
    {
        // 发送指定的消息给窗口 
        SendMessage( g_hWndManager, 
                     WM_MANAGER_INFO, 
                     RECORD_STOP, 
                     nNotifyCode );
    }
		
	return 0;
}

// 开始回放
int CHookManager::HMStartPlayBack(HWND hWnd,BOOL bDoClear)
{
	if ( g_hHookPlayBack != 0 )
    {
        return -1;
    }

	g_hWndManager = hWnd;
	g_bSysModalOn = FALSE;
	g_bDoClear = bDoClear;

	g_lpEventTail = NULL;
	g_lpPlayEvent = NULL;

	// 需要监视系统消息时要调用SetWindowsHookEx对消息进行监视。
    // 通过SetwindowsHookEx函数将消息函数JournalPlaybackFunc()加入到消息监视链中就可以处理消息了
    // WH_JOURNALPLAYBACK是监视函数类型，回放鼠标键盘消息。
    // 建立键盘鼠标操作消息纪录回放链
    g_hHookPlayBack = SetWindowsHookEx( WH_JOURNALPLAYBACK, 
                                       JournalPlaybackFunc, 
									   GetModuleHandle(NULL), 
                                       0 );
	return 0;
}

// JournalPlaybackFunc为消息函数；
// CALLBACK说明该消息函数被系统调用。
// 系统会调用该函数并将消息值传递给该函数供处理。
// code为系统指示标记，wParam和lParam为附加参数，根据不同的消息监视类型而不同
// WPARAM   A value passed as a parameter to a window procedure or callback function: 16 bits on Windows versions 3.0 and 3.1; 32 bits on Win32
// LPARAM 32-bit message parameter 
// JournalPlaybackFunc是消息回放函数，当系统可以执行消息回放时调用该函数，程序就将先前记录的消息值返回到lParam指向的区域中，系统就会执行该消息，从而实现了消息回放

LRESULT CALLBACK JournalPlaybackFunc (int nCode, WPARAM wParam, LPARAM lParam )
{
	static S_ENODE *lpPrevPlayedEvent;
    static DWORD dwLastEventTime;
	static DWORD dwDelay = 0;

	if ( !g_hHookPlayBack )
    {
        return 0;
    }

	CHookManager HookManager;
		
	if ( nCode == HC_SYSMODALON )
    {
        g_bSysModalOn = TRUE;
    }		
	else if ( nCode == HC_SYSMODALOFF )
    {
        g_bSysModalOn = FALSE;
    }		
	else if ( nCode >= 0 )    
    {
		if ( g_lpEventHead == NULL ) 
        {	
            // 没有录制的事件			
			HookManager.HMStopPlayBack(PLAYBACK_EMPTY);
			
			return 0;
		}

		if ( g_hHookRecord ) // 正在录制
        {	            
			g_bDoClear = TRUE;	// 阻止录制的事件被清除
			
			HookManager.HMStopPlayBack(PLAYBACK_BUSY);
			
			return ( (int)CallNextHookEx( g_hHookPlayBack, nCode, wParam, lParam) );
		}

        if ( g_lpPlayEvent == NULL ) 
        {	
            // 第一个事件正被播放
            dwDelay = 0;

            g_lpPlayEvent	= g_lpEventHead;
            g_lpEventTail	= NULL;	 // 为下一次我们开始录制

            dwLastEventTime = g_lpPlayEvent->Event.time;

            lpPrevPlayedEvent = NULL;

            // 发送消息后，立即返回
            PostMessage( g_hWndManager, 
                         WM_MANAGER_INFO, 
                         PLAYBACK_START, 
                         (LPARAM)dwLastEventTime );
        }

        if ( nCode == HC_SKIP ) 
        {

			if ( g_lpPlayEvent->lpNext == NULL ) 
            {	
                // 做过录制
				if ( g_bDoClear ) 
                {
					free( g_lpEventHead );
					g_lpEventHead = NULL;
				}
				
				g_lpPlayEvent = NULL;
				g_lpEventTail = NULL;

				HookManager.HMStopPlayBack(PLAYBACK_DONE);

			} 
            else 
            {				
				dwDelay++;
				if ( dwDelay == 0 )
					dwDelay = 1;

				dwLastEventTime = g_lpPlayEvent->Event.time;
				g_lpPlayEvent = g_lpPlayEvent->lpNext;
				
				if ( g_bDoClear ) 
                {
					free( g_lpEventHead );
					g_lpEventHead = g_lpPlayEvent;
				}

				// 发送消息后，立即返回
                PostMessage( g_hWndManager, 
                             WM_MANAGER_INFO, 
                             PLAYBACK_SKIP, 
                             0 );
			}

			return 0;

		} 
        else if ( nCode == HC_GETNEXT ) 
        {			  
			LPEVENTMSG lpEvent= (LPEVENTMSG)lParam;

			lpEvent->message = g_lpPlayEvent->Event.message;
			lpEvent->paramL = g_lpPlayEvent->Event.paramL;
			lpEvent->paramH = g_lpPlayEvent->Event.paramH;
			lpEvent->time = g_lpPlayEvent->Event.time + GetTickCount();

			long lReturnValue= 0;
			
			if ( dwDelay ) 
            {
				dwDelay = 0;

				lReturnValue = g_lpPlayEvent->Event.time - dwLastEventTime;

				if ( lReturnValue < 0L )
                {
                    lReturnValue = 1L;
                }
					
			}

			if ( lReturnValue != 0 )
            {
                // 发送消息后，立即返回
                PostMessage( g_hWndManager, 
                             WM_MANAGER_INFO, 
                             PLAYBACK_WAIT, 
                             lReturnValue );
            }				
			else if ( lpPrevPlayedEvent != g_lpPlayEvent ) 
            {			
				// 发送消息后，立即返回
                PostMessage( g_hWndManager, 
                             WM_MANAGER_INFO, 
                             PLAYBACK_PLAY, 
                             (LPARAM)g_lpPlayEvent->Event.message );
				lpPrevPlayedEvent = g_lpPlayEvent;
			}
            else
            {
                // 这里不需要做任何事情
            }

			return lReturnValue;
        }
        else
        {
            // 这里不需要做任何事情
        }
	}
    else
    {
        // 这里不需要做任何事情
    }
    
	return( CallNextHookEx(g_hHookPlayBack, nCode, wParam, lParam) );
}

// 停止回放
int CHookManager::HMStopPlayBack(int nNotifyCode)
{
	if ( g_hHookPlayBack == 0 )
    {
        return -1;
    }
	
	// 在不需要监视系统消息时要调用UnHookWindowsHookEx来解除对消息的监视。
    UnhookWindowsHookEx( g_hHookPlayBack );
	
	g_hHookPlayBack = NULL;

	if ( g_bDoClear )
    {
        HMFreeAllEvents();
    }		

	if ( nNotifyCode != 0 )
    {
        // 发送指定的消息给窗口
        SendMessage( g_hWndManager, 
                     WM_MANAGER_INFO, 
                     PLAYBACK_STOP, 
                     nNotifyCode );
    }
		
	return 0;
}
