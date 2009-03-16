/*
  Free Download Manager Copyright (c) 2003-2007 FreeDownloadManager.ORG
*/    

#if !defined(AFX_FSINTERNETFILELISTMGR_H__B6B6A23E_9022_462E_A29B_7D4978517BCB__INCLUDED_)
#define AFX_FSINTERNETFILELISTMGR_H__B6B6A23E_9022_462E_A29B_7D4978517BCB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsInternetSession.h"  

enum fsInternetFileListMgrEvent
{
	FLME_CONNECTING,					
	FLME_CONNECTED,						
	FLME_GETTINGLIST,					
	FLME_DONE,							
	FLME_DONE_FROM_CACHE,				
	FLME_ERROR,							
	FLME_PAUSE,							
	FLME_CONNECTIONWASLOST_RESTORE,		
	FLME_HTTP_LISTREAD,					
	FLME_HTTP_STARTBUILDLIST,			
	FLME_HTTP_FINISHBUILDLIST,			
	FLME_STOPPED,						
	
	FLME_TRYINGTOUSESITEMGRLOGIN	
};  

typedef void (*fsFileListMgrFunc) (class fsInternetFileListMgr*, fsInternetFileListMgrEvent ev, LPVOID);

class fsInternetFileListMgr
{
public:
	
	fsInternetResult GetList (LPCTSTR pszUrl, LPCTSTR pszUser, LPCTSTR pszPassword);
	
	fsInternetResult Refresh();
	
	LPCTSTR GetCurrentPath();
	
	
	
	
	void GetCurrentUrl (LPTSTR pszUrl, DWORD dwLen, BOOL bIncludeUser = TRUE, BOOL bIncludePassword = TRUE);
	
	void GetParentFolderUrl (LPTSTR pszUrl);
	
	void FolderToUrl (LPCTSTR pszFolder, LPTSTR pszUrl);
	
	void ReadSettings();
	
	void Disconnect();
	
	void FtpPassiveMode (BOOL b);
	
	void RetreiveInfoWhileGettingList (BOOL b);
	BOOL RetreiveInfoWhileGettingList ();
	
	BOOL IsConnected();
	
	
	
	fsInternetResult GetFullUrl (LPCTSTR pszRelOrNotUrl, fsString& strUrl);
	
	fsInternetResult GoFolder (LPCTSTR pszFolder);
	
	fsInternetResult GoParentFolder();
	
	LPCTSTR GetLastErrorDesc();
	
	BOOL IsCurrentPathRoot ();
	
	fsFileInfo* GetFileInfo (UINT uIndex);
	
	UINT GetFileCount();
	fsInternetResult GetLastError();
	
	void SetEventsFunc (fsFileListMgrFunc pfn, LPVOID lpParam);
	
	BOOL IsRunning();
	
	
	void Stop(BOOL bWaitStop = TRUE);

	fsInternetFileListMgr();
	virtual ~fsInternetFileListMgr();

protected:
	
	BOOL AskForLogin(LPCTSTR pszHostName);
	
	static void _HttpEvents (class fsHttpFiles* pFiles, fsHttpFilesEvent enEvent, LPVOID lpParam);
	
	void SleepInterval ();
	BOOL m_bAbort;			
	BOOL m_bConnected;		
	
	
	void Free(BOOL bStopBeforeFree = TRUE);
	
	int FindFiles (LPCTSTR pszFilesUrl);
	BOOL m_bCurPathIsRoot;	
	vmsInternetSession m_session;
	fsInternetURLServer m_server;	
	
	void Event (fsInternetFileListMgrEvent ev);
	
	static DWORD WINAPI _threadGetList (LPVOID lp);
	
	void Start();
	volatile BOOL m_bThread;	

	
	
	fs::list <fsInternetURLFiles*> m_vFiles;

	fsInternetURLFiles* m_files;	
	
	
	fsFileListMgrFunc m_pfnEvents;
	LPVOID m_lpEventsParam;

	
	fsInternetResult m_lastError;
	
	
	fsString _strUrl, _strUser, _strPassword;
	
	fsString m_strUser, m_strPassword;
	
	BOOL m_bFtpPassiveMode;
	BOOL m_bRetreiveInfoWhileGettingList;
};

#endif 
