//************************************************************************
//
// $Header:   S:/GRENLEAF/VCS/STATUS.H_v   1.0   12 Mar 1998 12:13:02   DCHI  $
//
// Description:
//  Greenleaf ArchiveLib 2.0
//
//************************************************************************
// $Log:   S:/GRENLEAF/VCS/STATUS.H_v  $
// 
//    Rev 1.0   12 Mar 1998 12:13:02   DCHI
// Initial revision.
// 
//************************************************************************

/*
 * STATUS.H
 *
 *  Header file for ArchiveLib 2.0
 *
 *  Copyright (c) 1994-1996 Greenleaf Software, Inc.
 *  All Rights Reserved
 *
 * DESCRIPTION
 *
 *  This header file contains the class declaration for ALStatus. 
 *  This is a utility class that is used as a data member in many
 *  different types of objects.  It holds the current error status
 *  of an object.
 * 
 * CLASS DEFINITIONS:
 *
 *  ALStatus
 *
 * MACROS
 *
 *   ostream& operator << ( ostream& stream, const ALStatus &status )
 * 
 * REVISION HISTORY
 *
 *  May 26, 1994  1.0A  : First release
 *
 *  February 14, 1996  2.0A : New release
 */

#ifndef _STATUS_H
#define _STATUS_H

#if defined( __cplusplus )

/*
 * class ALStatus
 *
 * DESCRIPTION
 *
 *  ALStatus is a utility class that is used as a data member of several
 *  other classes.  It provides an integer member that keeps track
 *  of the current status of the object, with AL_SUCCESS meaning
 *  everything is okay, and a code < 0 meaning the object has
 *  experienced an error.
 *
 *  The object also contains a character pointer to a detailed error
 *  message.  Usually when an error occurs in ArchiveLib, the
 *  routine that detects the error generates a detailed message that
 *  can be stored to provide additional information.
 *
 *  Error states in ArchiveLib are "sticky".  Once an object is flagged
 *  as being in error, it will stay that way until the programmer
 *  resets it, which means it will fail most ordinary operations.
 *  When you want to clear the error statue of an object, call
 *  SetError() with AL_SUCCESS as the error code.
 *
 * DATA MEMBERS
 *
 *  miStatus             : The current status of the object, with AL_SUCCESS
 *                         being a good value.  You can get at this easily
 *                         by casting ALStatus to type int.
 *
 *  miStatusDetailLength : This member keeps track of the length of the
 *                         status detail.  The status detail buffer
 *                         is dynamically allocated when it is needed.
 *                         Keeping this member is really kind of dumb, I
 *                         need to just allocate as much space as necessary
 *                         when the error detail is created.  Look for this
 *                         data member to go away in an upcoming release.
 *
 *  mszStatusDetail      : The detailed error message.  It will be set to
 *                         0 until a message is generated, when it
 *                         is dynamically allocated.  Cleaned up if necessary
 *                         in the destructor.

 *
 * MEMBER FUNCTIONS
 *
 *  ALStatus()          : The default and only constructor.
 *  ~ALStatus()         : The destructor, has to clean up detail string.
 *  operator new()      : Memory allocation operator, allocates space
 *                        for the class object when the library is in
 *                        the DLL.
 *  SetError()          : Sets the error code to a value, and writes
 *                        new data into the detail string.
 *  GetStatusCode()     : Returns the current integer status code,
 *                        just like operator int().
 *  GetStatusString()   : Returns the short string translation.
 *  GetStatusDetail()   : Returns the detailed status message, created
 *                        at the point the error took place.
 *  operator int()      : The casting operator, used all over ArchiveLib
 *                        when testing a status for a value < AL_SUCCESS.
 *  operator=()         : Assignment operator, easy here.
 *
 * REVISION HISTORY
 *
 *  May 26, 1994  1.0A  : First release
 *
 *  February 14, 1996  2.0A : New release
 */

class AL_CLASS_TYPE ALStatus {  /* Tag public class */
/*
 * Constructors, destructors, assignment operators, and declarations
 */
    public :
        AL_PROTO ALStatus();
        AL_PROTO ~ALStatus();
#if defined( AL_USING_DLL ) || defined( AL_BUILDING_DLL )
        void AL_DLL_FAR * AL_PROTO operator new( size_t size );
#endif
/*
 * I don't want to allow the copy constructor, although I probably could
 * support it without too much trouble.
 */
    protected :
        AL_PROTO ALStatus( ALStatus AL_DLL_FAR & );
/*
 * Member functions
 */
    public :
        int AL_PROTO SetError( int error, const char AL_DLL_FAR *fmt, ... );
        int AL_PROTO GetStatusCode();
        const char AL_DLL_FAR * AL_PROTO GetStatusString();
        const char AL_DLL_FAR * AL_PROTO GetStatusDetail() const;
        AL_PROTO operator int();
        ALStatus AL_DLL_FAR & AL_PROTO operator = ( ALStatus AL_DLL_FAR & );
/*
 * Data members
 */
    protected :
        int miStatus;
        const int miStatusDetailLength;
        char AL_DLL_FAR *mszStatusDetail;

};

#include "status.inl"

#endif /* #if defined( __cplusplus ) */

#endif /* #ifdef _STATUS_H           */

