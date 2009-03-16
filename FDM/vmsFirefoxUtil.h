/*
  Free Download Manager Copyright (c) 2003-2007 FreeDownloadManager.ORG
*/        

#if !defined(AFX_VMSFIREFOXUTIL_H__510F0D32_5282_41CB_8282_4F76D2D32FAF__INCLUDED_)
#define AFX_VMSFIREFOXUTIL_H__510F0D32_5282_41CB_8282_4F76D2D32FAF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "fslist.h"
#include <fsString.h>
typedef fs::list <fsString> FU_STRINGLIST;

class vmsFirefoxUtil  
{
public:
	
	static bool GetDefaultProfilePath (LPTSTR pszPath);
	
	
	static bool GetProfilesPathes (FU_STRINGLIST& v, int& nDefaultProfile);
	
	static void GetDataPath (LPTSTR pszPath);
	
	static void GetProfilesPath (LPTSTR pszPath);

	vmsFirefoxUtil();
	virtual ~vmsFirefoxUtil();

};

#endif 
