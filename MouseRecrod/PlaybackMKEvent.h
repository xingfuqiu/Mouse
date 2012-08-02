// PlaybackMKEvent.h: interface for the CPlaybackMKEvent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLAYBACKMKEVENT_H__298B02BC_AA82_4BE2_B1AC_DA3C2580567D__INCLUDED_)
#define AFX_PLAYBACKMKEVENT_H__298B02BC_AA82_4BE2_B1AC_DA3C2580567D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CPlaybackMKEvent  
{
public:
	CPlaybackMKEvent();
	virtual ~CPlaybackMKEvent();

public:
	void StartPlayBack(HWND hWnd, int nClearPlaybackEvent);
	void StopPlayBack();
};

#endif // !defined(AFX_PLAYBACKMKEVENT_H__298B02BC_AA82_4BE2_B1AC_DA3C2580567D__INCLUDED_)
