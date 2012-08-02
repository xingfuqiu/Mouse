// RecordMKEvent.h: interface for the CRecordMKEvent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RECORDMKEVENT_H__5B341CD8_3C32_4F77_A332_8230468C7D4D__INCLUDED_)
#define AFX_RECORDMKEVENT_H__5B341CD8_3C32_4F77_A332_8230468C7D4D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CRecordMKEvent  
{
public:
	CRecordMKEvent();
	virtual ~CRecordMKEvent();

public:
	void StartRecord(HWND hWnd, int nOnlyKeyboardEvent);
	void StopRecord(); 
};

#endif // !defined(AFX_RECORDMKEVENT_H__5B341CD8_3C32_4F77_A332_8230468C7D4D__INCLUDED_)
