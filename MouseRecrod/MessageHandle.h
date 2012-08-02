// MessageHandle.h: interface for the CMessageHandle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MESSAGEHANDLE_H__A9F090DD_5C50_4024_B232_C04621D80FE6__INCLUDED_)
#define AFX_MESSAGEHANDLE_H__A9F090DD_5C50_4024_B232_C04621D80FE6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMessageHandle  
{
public:
	CMessageHandle();
	virtual ~CMessageHandle();

	LPCTSTR GetMessageName(UINT);
};

#endif // !defined(AFX_MESSAGEHANDLE_H__A9F090DD_5C50_4024_B232_C04621D80FE6__INCLUDED_)
