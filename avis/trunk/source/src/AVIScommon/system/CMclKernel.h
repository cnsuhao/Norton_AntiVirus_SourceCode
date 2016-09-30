//
// FILE: CMclKernel.h
//
// Copyright (c) 1997 by Aaron Michael Cohen and Mike Woodring
//
/////////////////////////////////////////////////////////////////////////
#ifndef __CMCLKERNEL_H__
#define __CMCLKERNEL_H__

#include "CMclGlobal.h"
#include "CMclWaitableObject.h"

class AVISCOMMON_API CMclKernel : public CMclWaitableObject {
protected:
    HANDLE m_hHandle;
    DWORD m_dwStatus;

protected:
    // constructor...
    CMclKernel();

    // error handling...
    void ThrowError( DWORD dwStatus);

public:
    // destructor is virtual to make CMclKernel an abstract base class...
    virtual ~CMclKernel() = 0;

    // read the creation status of the internal kernel object...
    DWORD Status(void) const;

    // wait on the current kernel object...
    DWORD Wait( DWORD dwMilliseconds);

    // wait on the current object and one other...
    DWORD WaitForTwo( CMclWaitableObject &rCMclWaitableObject, BOOL bWaitAll, DWORD dwMilliseconds);

    // get the internal handle...
    HANDLE GetHandle(void) const;

    // another way to get the internal handle...
    operator HANDLE() const;

private:
    // these functions have no implementation since they can 
    // never be called...

    // copying and passing by copy are not allowed...
    // this prevents confusion of internal object ownership...
    CMclKernel(CMclKernel & rhs);

    // assigning one object to another is not allowed,
    // this prevents confusion of internal object ownership...
    CMclKernel & operator= (CMclKernel & rhs);
};

#endif
