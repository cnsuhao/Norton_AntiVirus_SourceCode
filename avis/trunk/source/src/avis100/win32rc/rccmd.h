/*******************************************************************
*                                                                  *
* File name:     rcecheck.h                                         *
*                                                                  *
* Description:   RCCheck class definition file                     *
*                                                                  *
*                                                                  *
* Statement:     Licensed Materials - Property of IBM              *
*                (c) Copyright IBM Corp. 1999                      *
*                                                                  *
* Author:        Alla Segal                                        *
*                                                                  *
*                U.S. Government Users Restricted Rights - use,    *
*                duplication or disclosure restricted by GSA ADP   *
*                Schedule Contract with IBM Corp.                  *
*                                                                  *
*                                                                  *
********************************************************************
*                                                                  *
* Function:      class definition for rc checkup processor          *
*                                                                  *
*******************************************************************/
#ifndef RCCHECK_H
#define RCHECK_H
class RCCheck {

  public:

     RCCheck(CString DirName, CString WindowsDir, BOOL trace);
	 void InitFileList();
	 void CheckFiles(CStringList* pNewFiles, CStringList *pChangedFiles);
     ~RCCheck();   
       
  private:
	 RCFileList m_FileList;
	 CStringList *m_pNewFiles;
	 CStringList *m_pChangedFiles;
     CString m_TmpGoatsDir;
	 CString m_WindowsDir;
	 BOOL m_trace;
	 RCError rcTrace;
      
	 poly *m_crc_table;
     poly GetCrc(CString FileName);
	 void ProcessDir(CString DirName, BOOL check_subdirs, BOOL initialize);
	 BOOL IncludedFile(CString FileName);
};
#endif


