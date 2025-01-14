case $CONFIG in
'')
	if test -f config.sh; then TOP=.;
	elif test -f ../config.sh; then TOP=..;
	elif test -f ../../config.sh; then TOP=../..;
	elif test -f ../../../config.sh; then TOP=../../..;
	elif test -f ../../../../config.sh; then TOP=../../../..;
	else
		echo "Can't find config.sh."; exit 1
	fi
	. $TOP/config.sh
	;;
esac
case "$0" in
*/*) cd `expr X$0 : 'X\(.*\)/'` ;;
esac
echo "Extracting config.h (with variable substitutions)"
sed <<!GROK!THIS! >config.h -e 's!^#undef\(.*/\)\*!/\*#define\1 \*!' -e 's!^#un-def!#undef!'
/*
 * This file was produced by running the config_h.SH script, which
 * gets its values from config.sh, which is generally produced by
 * running Configure.
 *
 * Feel free to modify any of this as the need arises.  Note, however,
 * that running config_h.SH again will wipe out any changes you've made.
 * For a more permanent change edit config.sh and rerun config_h.SH.
 *
 * \$Id: Config_h.U,v 3.0.1.4 1995/09/25 09:10:49 ram Exp $
 */

/* Configuration time: $cf_time
 * Configured by: $cf_by
 * Target system: $myuname
 */

#ifndef _config_h_
#define _config_h_

/* MEM_ALIGNBYTES:
 *	This symbol contains the number of bytes required to align a
 *	double. Usual values are 2, 4 and 8.
 *	On NeXT starting with 3.2, you can build "Fat" Multiple Architecture
 *	Binaries (MAB) for targets with varying alignment.  This only matters
 *	for perl, where the config.h can be generated and installed on one
 *	system, and used by a different architecture to build an extension.
 *	The default is eight, for safety.
 */
#ifndef NeXT
#define MEM_ALIGNBYTES $alignbytes	/**/
#else  /* NeXT */
#ifdef __m68k__
#define MEM_ALIGNBYTES 2
#else
#ifdef __i386__
#define MEM_ALIGNBYTES 4
#else /* __hppa__, __sparc__ and default for unknown architectures */
#define MEM_ALIGNBYTES 8
#endif /* __i386__ */
#endif /* __m68k__ */
#endif /* NeXT */

/* ARCHNAME:
 *	This symbol holds a string representing the architecture name.
 *	It may be used to construct an architecture-dependant pathname
 *	where library files may be held under a private library, for
 *	instance.
 */
#define ARCHNAME "$archname"		/**/

/* BIN:
 *	This symbol holds the path of the bin directory where the package will
 *	be installed. Program must be prepared to deal with ~name substitution.
 */
/* BIN_EXP:
 *	This symbol is the filename expanded version of the BIN symbol, for
 *	programs that do not want to deal with that at run-time.
 */
#define BIN "$bin"	/**/
#define BIN_EXP "$binexp"	/**/

/* CAT2:
 *	This macro catenates 2 tokens together.
 */
/* STRINGIFY:
 *	This macro surrounds its token with double quotes.
 */
#if $cpp_stuff == 1
#define CAT2(a,b)a/**/b
#define CAT3(a,b,c)a/**/b/**/c
#define CAT4(a,b,c,d)a/**/b/**/c/**/d
#define CAT5(a,b,c,d,e)a/**/b/**/c/**/d/**/e
#define STRINGIFY(a)"a"
		/* If you can get stringification with catify, tell me how! */
#endif
#if $cpp_stuff == 42
#define CAT2(a,b)a ## b
#define CAT3(a,b,c)a ## b ## c
#define CAT4(a,b,c,d)a ## b ## c ## d
#define CAT5(a,b,c,d,e)a ## b ## c ## d ## e
#define StGiFy(a)# a
#define STRINGIFY(a)StGiFy(a)
#define SCAT2(a,b)StGiFy(a) StGiFy(b)
#define SCAT3(a,b,c)StGiFy(a) StGiFy(b) StGiFy(c)
#define SCAT4(a,b,c,d)StGiFy(a) StGiFy(b) StGiFy(c) StGiFy(d)
#define SCAT5(a,b,c,d,e)StGiFy(a) StGiFy(b) StGiFy(c) StGiFy(d) StGiFy(e)
#endif
#ifndef CAT2
#include "Bletch: How does this C preprocessor catenate tokens?"
#endif

/* CPPSTDIN:
 *	This symbol contains the first part of the string which will invoke
 *	the C preprocessor on the standard input and produce to standard
 *	output.	 Typical value of "cc -E" or "/lib/cpp", but it can also
 *	call a wrapper. See CPPRUN.
 */
/* CPPMINUS:
 *	This symbol contains the second part of the string which will invoke
 *	the C preprocessor on the standard input and produce to standard
 *	output.  This symbol will have the value "-" if CPPSTDIN needs a minus
 *	to specify standard input, otherwise the value is "".
 */
#define CPPSTDIN "$cppstdin"
#define CPPMINUS "$cppminus"

/* HAS_ALARM:
 *	This symbol, if defined, indicates that the alarm routine is
 *	available.
 */
#$d_alarm HAS_ALARM		/**/

/* HASATTRIBUTE:
 *	This symbol indicates the C compiler can check for function attributes,
 *	such as printf formats. This is normally only supported by GNU cc.
 */
#$d_attribut HASATTRIBUTE 	/**/
#ifndef HASATTRIBUTE
#define __attribute__(_arg_)
#endif

/* HAS_BCMP:
 *	This symbol is defined if the bcmp() routine is available to
 *	compare blocks of memory.
 */
#$d_bcmp HAS_BCMP	/**/

/* HAS_BCOPY:
 *	This symbol is defined if the bcopy() routine is available to
 *	copy blocks of memory.
 */
#$d_bcopy HAS_BCOPY	/**/

/* HAS_BZERO:
 *	This symbol is defined if the bzero() routine is available to
 *	set a memory block to 0.
 */
#$d_bzero HAS_BZERO	/**/

/* CASTI32:
 *	This symbol is defined if the C compiler can cast negative
 *	or large floating point numbers to 32-bit ints.
 */
#$d_casti32	CASTI32		/**/

/* CASTNEGFLOAT:
 *	This symbol is defined if the C compiler can cast negative
 *	numbers to unsigned longs, ints and shorts.
 */
/* CASTFLAGS:
 *	This symbol contains flags that say what difficulties the compiler
 *	has casting odd floating values to unsigned long:
 *		0 = ok
 *		1 = couldn't cast < 0
 *		2 = couldn't cast >= 0x80000000
 *		4 = couldn't cast in argument expression list
 */
#$d_castneg	CASTNEGFLOAT		/**/
#define CASTFLAGS $castflags		/**/

/* HAS_CHOWN:
 *	This symbol, if defined, indicates that the chown routine is
 *	available.
 */
#$d_chown HAS_CHOWN		/**/

/* HAS_CHROOT:
 *	This symbol, if defined, indicates that the chroot routine is
 *	available.
 */
#$d_chroot HAS_CHROOT		/**/

/* HAS_CHSIZE:
 *	This symbol, if defined, indicates that the chsize routine is available
 *	to truncate files.  You might need a -lx to get this routine.
 */
#$d_chsize	HAS_CHSIZE		/**/

/* VOID_CLOSEDIR:
 *	This symbol, if defined, indicates that the closedir() routine
 *	does not return a value.
 */
#$d_void_closedir VOID_CLOSEDIR		/**/

/* HASCONST:
 *	This symbol, if defined, indicates that this C compiler knows about
 *	the const type. There is no need to actually test for that symbol
 *	within your programs. The mere use of the "const" keyword will
 *	trigger the necessary tests.
 */
#$d_const HASCONST	/**/
#ifndef HASCONST
#define const
#endif

/* HAS_CRYPT:
 *	This symbol, if defined, indicates that the crypt routine is available
 *	to encrypt passwords and the like.
 */
#$d_crypt HAS_CRYPT		/**/

/* HAS_CUSERID:
 *	This symbol, if defined, indicates that the cuserid routine is
 *	available to get character login names.
 */
#$d_cuserid HAS_CUSERID		/**/

/* HAS_DBL_DIG:
 *	This symbol, if defined, indicates that this system's <float.h>
 *	or <limits.h> defines the symbol DBL_DIG, which is the number
 *	of significant digits in a double precision number.  If this
 *	symbol is not defined, a guess of 15 is usually pretty good.
 */
#$d_dbl_dig HAS_DBL_DIG 	/* */

/* HAS_DIFFTIME:
 *	This symbol, if defined, indicates that the difftime routine is
 *	available.
 */
#$d_difftime HAS_DIFFTIME		/**/

/* HAS_DLERROR:
 *	This symbol, if defined, indicates that the dlerror routine is
 *	available to return a string describing the last error that
 *	occurred from a call to dlopen(), dlclose() or dlsym().
 */
#$d_dlerror HAS_DLERROR	/**/

/* HAS_DUP2:
 *	This symbol, if defined, indicates that the dup2 routine is
 *	available to duplicate file descriptors.
 */
#$d_dup2 HAS_DUP2	/**/

/* HAS_FCHMOD:
 *	This symbol, if defined, indicates that the fchmod routine is available
 *	to change mode of opened files.  If unavailable, use chmod().
 */
#$d_fchmod HAS_FCHMOD		/**/

/* HAS_FCHOWN:
 *	This symbol, if defined, indicates that the fchown routine is available
 *	to change ownership of opened files.  If unavailable, use chown().
 */
#$d_fchown HAS_FCHOWN		/**/

/* HAS_FCNTL:
 *	This symbol, if defined, indicates to the C program that
 *	the fcntl() function exists.
 */
#$d_fcntl HAS_FCNTL		/**/

/* HAS_FGETPOS:
 *	This symbol, if defined, indicates that the fgetpos routine is
 *	available to get the file position indicator, similar to ftell().
 */
#$d_fgetpos HAS_FGETPOS	/**/

/* FLEXFILENAMES:
 *	This symbol, if defined, indicates that the system supports filenames
 *	longer than 14 characters.
 */
#$d_flexfnam	FLEXFILENAMES		/**/

/* HAS_FLOCK:
 *	This symbol, if defined, indicates that the flock routine is
 *	available to do file locking.
 */
#$d_flock HAS_FLOCK		/**/

/* HAS_FORK:
 *	This symbol, if defined, indicates that the fork routine is
 *	available.
 */
#$d_fork HAS_FORK		/**/

/* HAS_FSETPOS:
 *	This symbol, if defined, indicates that the fsetpos routine is
 *	available to set the file position indicator, similar to fseek().
 */
#$d_fsetpos HAS_FSETPOS	/**/

/* HAS_GETTIMEOFDAY:
 *	This symbol, if defined, indicates that the gettimeofday() system
 *	call is available for a sub-second accuracy clock. Usually, the file
 *	<sys/resource.h> needs to be included (see I_SYS_RESOURCE).
 *	The type "Timeval" should be used to refer to "struct timeval".
 */
#$d_gettimeod HAS_GETTIMEOFDAY	/**/
#ifdef HAS_GETTIMEOFDAY
#define Timeval struct timeval	/* Structure used by gettimeofday() */
#endif

/* HAS_GETGROUPS:
 *	This symbol, if defined, indicates that the getgroups() routine is
 *	available to get the list of process groups.  If unavailable, multiple
 *	groups are probably not supported.
 */
/* HAS_SETGROUPS:
 *	This symbol, if defined, indicates that the setgroups() routine is
 *	available to set the list of process groups.  If unavailable, multiple
 *	groups are probably not supported.
 */
#$d_getgrps HAS_GETGROUPS		/**/
#$d_setgrps HAS_SETGROUPS		/**/

/* HAS_GETHOSTENT:
 *	This symbol, if defined, indicates that the gethostent routine is
 *	available to lookup host names in some data base or other.
 */
#$d_gethent HAS_GETHOSTENT		/**/

/* HAS_UNAME:
 *	This symbol, if defined, indicates that the C program may use the
 *	uname() routine to derive the host name.  See also HAS_GETHOSTNAME
 *	and PHOSTNAME.
 */
#$d_uname HAS_UNAME		/**/

/* HAS_GETLOGIN:
 *	This symbol, if defined, indicates that the getlogin routine is
 *	available to get the login name.
 */
#$d_getlogin HAS_GETLOGIN		/**/

/* HAS_GETPGRP2:
 *	This symbol, if defined, indicates that the getpgrp2() (as in DG/UX)
 *	routine is available to get the current process group.
 */
#$d_getpgrp2 HAS_GETPGRP2		/**/

/* HAS_GETPPID:
 *	This symbol, if defined, indicates that the getppid routine is
 *	available to get the parent process ID.
 */
#$d_getppid HAS_GETPPID		/**/

/* HAS_GETPRIORITY:
 *	This symbol, if defined, indicates that the getpriority routine is
 *	available to get a process's priority.
 */
#$d_getprior HAS_GETPRIORITY		/**/

/* HAS_HTONL:
 *	This symbol, if defined, indicates that the htonl() routine (and
 *	friends htons() ntohl() ntohs()) are available to do network
 *	order byte swapping.
 */
/* HAS_HTONS:
 *	This symbol, if defined, indicates that the htons() routine (and
 *	friends htonl() ntohl() ntohs()) are available to do network
 *	order byte swapping.
 */
/* HAS_NTOHL:
 *	This symbol, if defined, indicates that the ntohl() routine (and
 *	friends htonl() htons() ntohs()) are available to do network
 *	order byte swapping.
 */
/* HAS_NTOHS:
 *	This symbol, if defined, indicates that the ntohs() routine (and
 *	friends htonl() htons() ntohl()) are available to do network
 *	order byte swapping.
 */
#$d_htonl HAS_HTONL		/**/
#$d_htonl HAS_HTONS		/**/
#$d_htonl HAS_NTOHL		/**/
#$d_htonl HAS_NTOHS		/**/

/* HAS_ISASCII:
 *	This manifest constant lets the C program know that isascii 
 *	is available.
 */
#$d_isascii HAS_ISASCII		/**/

/* HAS_KILLPG:
 *	This symbol, if defined, indicates that the killpg routine is available
 *	to kill process groups.  If unavailable, you probably should use kill
 *	with a negative process number.
 */
#$d_killpg HAS_KILLPG	/**/

/* HAS_LINK:
 *	This symbol, if defined, indicates that the link routine is
 *	available to create hard links.
 */
#$d_link HAS_LINK	/**/

/* HAS_LOCALECONV:
 *	This symbol, if defined, indicates that the localeconv routine is
 *	available for numeric and monetary formatting conventions.
 */
#$d_locconv HAS_LOCALECONV	/**/

/* HAS_LOCKF:
 *	This symbol, if defined, indicates that the lockf routine is
 *	available to do file locking.
 */
#$d_lockf HAS_LOCKF		/**/

/* HAS_LSTAT:
 *	This symbol, if defined, indicates that the lstat routine is
 *	available to do file stats on symbolic links.
 */
#$d_lstat HAS_LSTAT		/**/

/* HAS_MBLEN:
 *	This symbol, if defined, indicates that the mblen routine is available
 *	to find the number of bytes in a multibye character.
 */
#$d_mblen HAS_MBLEN		/**/

/* HAS_MBSTOWCS:
 *	This symbol, if defined, indicates that the mbstowcs routine is
 *	available to covert a multibyte string into a wide character string.
 */
#$d_mbstowcs	HAS_MBSTOWCS		/**/

/* HAS_MBTOWC:
 *	This symbol, if defined, indicates that the mbtowc routine is available
 *	to covert a multibyte to a wide character.
 */
#$d_mbtowc HAS_MBTOWC		/**/

/* HAS_MEMCMP:
 *	This symbol, if defined, indicates that the memcmp routine is available
 *	to compare blocks of memory.
 */
#$d_memcmp HAS_MEMCMP	/**/

/* HAS_MEMCPY:
 *	This symbol, if defined, indicates that the memcpy routine is available
 *	to copy blocks of memory.
 */
#$d_memcpy HAS_MEMCPY	/**/

/* HAS_MEMMOVE:
 *	This symbol, if defined, indicates that the memmove routine is available
 *	to copy potentially overlapping blocks of memory. This should be used
 *	only when HAS_SAFE_BCOPY is not defined. If neither is there, roll your
 *	own version.
 */
#$d_memmove HAS_MEMMOVE	/**/

/* HAS_MEMSET:
 *	This symbol, if defined, indicates that the memset routine is available
 *	to set blocks of memory.
 */
#$d_memset HAS_MEMSET	/**/

/* HAS_MKDIR:
 *	This symbol, if defined, indicates that the mkdir routine is available
 *	to create directories.  Otherwise you should fork off a new process to
 *	exec /bin/mkdir.
 */
#$d_mkdir HAS_MKDIR		/**/

/* HAS_MKFIFO:
 *	This symbol, if defined, indicates that the mkfifo routine is
 *	available to create FIFOs. Otherwise, mknod should be able to
 *	do it for you. However, if mkfifo is there, mknod might require
 *	super-user privileges which mkfifo will not.
 */
#$d_mkfifo HAS_MKFIFO		/**/

/* HAS_MKTIME:
 *	This symbol, if defined, indicates that the mktime routine is
 *	available.
 */
#$d_mktime HAS_MKTIME		/**/

/* HAS_MSG:
 *	This symbol, if defined, indicates that the entire msg*(2) library is
 *	supported (IPC mechanism based on message queues).
 */
#$d_msg HAS_MSG		/**/

/* HAS_NICE:
 *	This symbol, if defined, indicates that the nice routine is
 *	available.
 */
#$d_nice HAS_NICE		/**/

/* HAS_OPEN3:
 *	This manifest constant lets the C program know that the three
 *	argument form of open(2) is available.
 */
#$d_open3 HAS_OPEN3		/**/

/* HAS_PATHCONF:
 *	This symbol, if defined, indicates that pathconf() is available
 *	to determine file-system related limits and options associated
 *	with a given filename.
 */
/* HAS_FPATHCONF:
 *	This symbol, if defined, indicates that pathconf() is available
 *	to determine file-system related limits and options associated
 *	with a given open file descriptor.
 */
#$d_pathconf HAS_PATHCONF		/**/
#$d_fpathconf HAS_FPATHCONF		/**/

/* HAS_PAUSE:
 *	This symbol, if defined, indicates that the pause routine is
 *	available to suspend a process until a signal is received.
 */
#$d_pause HAS_PAUSE		/**/

/* HAS_PIPE:
 *	This symbol, if defined, indicates that the pipe routine is
 *	available to create an inter-process channel.
 */
#$d_pipe HAS_PIPE		/**/

/* HAS_POLL:
 *	This symbol, if defined, indicates that the poll routine is
 *	available to poll active file descriptors.
 */
#$d_poll HAS_POLL		/**/

/* HAS_READDIR:
 *	This symbol, if defined, indicates that the readdir routine is
 *	available to read directory entries. You may have to include
 *	<dirent.h>. See I_DIRENT.
 */
#$d_readdir HAS_READDIR		/**/

/* HAS_SEEKDIR:
 *	This symbol, if defined, indicates that the seekdir routine is
 *	available. You may have to include <dirent.h>. See I_DIRENT.
 */
#$d_seekdir HAS_SEEKDIR		/**/

/* HAS_TELLDIR:
 *	This symbol, if defined, indicates that the telldir routine is
 *	available. You may have to include <dirent.h>. See I_DIRENT.
 */
#$d_telldir HAS_TELLDIR		/**/

/* HAS_REWINDDIR:
 *	This symbol, if defined, indicates that the rewinddir routine is
 *	available. You may have to include <dirent.h>. See I_DIRENT.
 */
#$d_rewinddir HAS_REWINDDIR		/**/

/* HAS_READLINK:
 *	This symbol, if defined, indicates that the readlink routine is
 *	available to read the value of a symbolic link.
 */
#$d_readlink HAS_READLINK		/**/

/* HAS_RENAME:
 *	This symbol, if defined, indicates that the rename routine is available
 *	to rename files.  Otherwise you should do the unlink(), link(), unlink()
 *	trick.
 */
#$d_rename HAS_RENAME	/**/

/* HAS_RMDIR:
 *	This symbol, if defined, indicates that the rmdir routine is
 *	available to remove directories. Otherwise you should fork off a
 *	new process to exec /bin/rmdir.
 */
#$d_rmdir HAS_RMDIR		/**/

/* HAS_SAFE_BCOPY:
 *	This symbol, if defined, indicates that the bcopy routine is available
 *	to copy potentially overlapping memory blocks. Otherwise you should
 *	probably use memmove() or memcpy(). If neither is defined, roll your
 *	own version.
 */
#$d_safebcpy HAS_SAFE_BCOPY	/**/

/* HAS_SAFE_MEMCPY:
 *	This symbol, if defined, indicates that the memcpy routine is available
 *	to copy potentially overlapping memory blocks. Otherwise you should
 *	probably use memmove() or memcpy(). If neither is defined, roll your
 *	own version.
 */
#$d_safemcpy HAS_SAFE_MEMCPY	/**/

/* HAS_SANE_MEMCMP:
 *	This symbol, if defined, indicates that the memcmp routine is available
 *	and can be used to compare relative magnitudes of chars with their high
 *	bits set.  If it is not defined, roll your own version.
 */
#$d_sanemcmp HAS_SANE_MEMCMP	/**/

/* HAS_SELECT:
 *	This symbol, if defined, indicates that the select routine is
 *	available to select active file descriptors. If the timeout field
 *	is used, <sys/time.h> may need to be included.
 */
#$d_select HAS_SELECT	/**/

/* HAS_SEM:
 *	This symbol, if defined, indicates that the entire sem*(2) library is
 *	supported.
 */
#$d_sem HAS_SEM		/**/

/* HAS_SETEGID:
 *	This symbol, if defined, indicates that the setegid routine is available
 *	to change the effective gid of the current program.
 */
#$d_setegid HAS_SETEGID		/**/

/* HAS_SETEUID:
 *	This symbol, if defined, indicates that the seteuid routine is available
 *	to change the effective uid of the current program.
 */
#$d_seteuid HAS_SETEUID		/**/

/* HAS_SETLINEBUF:
 *	This symbol, if defined, indicates that the setlinebuf routine is
 *	available to change stderr or stdout from block-buffered or unbuffered
 *	to a line-buffered mode.
 */
#$d_setlinebuf HAS_SETLINEBUF		/**/

/* HAS_SETLOCALE:
 *	This symbol, if defined, indicates that the setlocale routine is
 *	available to handle locale-specific ctype implementations.
 */
#$d_setlocale HAS_SETLOCALE	/**/

/* HAS_SETPGRP2:
 *	This symbol, if defined, indicates that the setpgrp2() (as in DG/UX)
 *	routine is available to set the current process group.
 */
#$d_setpgrp2 HAS_SETPGRP2		/**/

/* HAS_SETPRIORITY:
 *	This symbol, if defined, indicates that the setpriority routine is
 *	available to set a process's priority.
 */
#$d_setprior HAS_SETPRIORITY		/**/

/* HAS_SETREGID:
 *	This symbol, if defined, indicates that the setregid routine is
 *	available to change the real and effective gid of the current
 *	process.
 */
/* HAS_SETRESGID:
 *	This symbol, if defined, indicates that the setresgid routine is
 *	available to change the real, effective and saved gid of the current
 *	process.
 */
#$d_setregid HAS_SETREGID		/**/
#$d_setresgid HAS_SETRESGID		/**/

/* HAS_SETREUID:
 *	This symbol, if defined, indicates that the setreuid routine is
 *	available to change the real and effective uid of the current
 *	process.
 */
/* HAS_SETRESUID:
 *	This symbol, if defined, indicates that the setresuid routine is
 *	available to change the real, effective and saved uid of the current
 *	process.
 */
#$d_setreuid HAS_SETREUID		/**/
#$d_setresuid HAS_SETRESUID		/**/

/* HAS_SETRGID:
 *	This symbol, if defined, indicates that the setrgid routine is available
 *	to change the real gid of the current program.
 */
#$d_setrgid HAS_SETRGID		/**/

/* HAS_SETRUID:
 *	This symbol, if defined, indicates that the setruid routine is available
 *	to change the real uid of the current program.
 */
#$d_setruid HAS_SETRUID		/**/

/* HAS_SETSID:
 *	This symbol, if defined, indicates that the setsid routine is
 *	available to set the process group ID.
 */
#$d_setsid HAS_SETSID	/**/

/* HAS_SHM:
 *	This symbol, if defined, indicates that the entire shm*(2) library is
 *	supported.
 */
#$d_shm HAS_SHM		/**/

/* Shmat_t:
 *	This symbol holds the return type of the shmat() system call.
 *	Usually set to 'void *' or 'char *'.
 */
/* HAS_SHMAT_PROTOTYPE:
 *	This symbol, if defined, indicates that the sys/shm.h includes
 *	a prototype for shmat().  Otherwise, it is up to the program to
 *	guess one.  Shmat_t shmat _((int, Shmat_t, int)) is a good guess,
 *	but not always right so it should be emitted by the program only
 *	when HAS_SHMAT_PROTOTYPE is not defined to avoid conflicting defs.
 */
#define Shmat_t $shmattype	/**/
#$d_shmatprototype HAS_SHMAT_PROTOTYPE	/**/

/* HAS_SIGACTION:
 *	This symbol, if defined, indicates that Vr4's sigaction() routine
 *	is available.
 */
#$d_sigaction HAS_SIGACTION	/**/

/* HAS_SOCKET:
 *	This symbol, if defined, indicates that the BSD socket interface is
 *	supported.
 */
/* HAS_SOCKETPAIR:
 *	This symbol, if defined, indicates that the BSD socketpair() call is
 *	supported.
 */
#$d_socket HAS_SOCKET		/**/
#$d_sockpair HAS_SOCKETPAIR	/**/

/* USE_STAT_BLOCKS:
 *	This symbol is defined if this system has a stat structure declaring
 *	st_blksize and st_blocks.
 */
#$d_statblks USE_STAT_BLOCKS 	/**/

/* USE_STDIO_PTR:
 *	This symbol is defined if the _ptr and _cnt fields (or similar)
 *	of the stdio FILE structure can be used to access the stdio buffer
 *	for a file handle.  If this is defined, then the FILE_ptr(fp)
 *	and FILE_cnt(fp) macros will also be defined and should be used
 *	to access these fields.
 */
/* FILE_ptr:
 *	This macro is used to access the _ptr field (or equivalent) of the
 *	FILE structure pointed to by its argument. This macro will always be
 *	defined if USE_STDIO_PTR is defined.
 */
/* STDIO_PTR_LVALUE:
 *	This symbol is defined if the FILE_ptr macro can be used as an
 *	lvalue.
 */
/* FILE_cnt:
 *	This macro is used to access the _cnt field (or equivalent) of the
 *	FILE structure pointed to by its argument. This macro will always be
 *	defined if USE_STDIO_PTR is defined.
 */
/* STDIO_CNT_LVALUE:
 *	This symbol is defined if the FILE_cnt macro can be used as an
 *	lvalue.
 */
#$d_stdstdio USE_STDIO_PTR 	/**/
#ifdef USE_STDIO_PTR
#define FILE_ptr(fp)	$stdio_ptr
#$d_stdio_ptr_lval STDIO_PTR_LVALUE 		/**/
#define FILE_cnt(fp)	$stdio_cnt
#$d_stdio_cnt_lval STDIO_CNT_LVALUE 		/**/
#endif

/* USE_STDIO_BASE:
 *	This symbol is defined if the _base field (or similar) of the
 *	stdio FILE structure can be used to access the stdio buffer for
 *	a file handle.  If this is defined, then the FILE_base(fp) macro
 *	will also be defined and should be used to access this field.
 *	Also, the FILE_bufsiz(fp) macro will be defined and should be used
 *	to determine the number of bytes in the buffer.  USE_STDIO_BASE
 *	will never be defined unless USE_STDIO_PTR is.
 */
/* FILE_base:
 *	This macro is used to access the _base field (or equivalent) of the
 *	FILE structure pointed to by its argument. This macro will always be
 *	defined if USE_STDIO_BASE is defined.
 */
/* FILE_bufsiz:
 *	This macro is used to determine the number of bytes in the I/O
 *	buffer pointed to by _base field (or equivalent) of the FILE
 *	structure pointed to its argument. This macro will always be defined
 *	if USE_STDIO_BASE is defined.
 */
#$d_stdiobase USE_STDIO_BASE 	/**/
#ifdef USE_STDIO_BASE
#define FILE_base(fp)	$stdio_base
#define FILE_bufsiz(fp)	$stdio_bufsiz
#endif

/* HAS_STRCHR:
 *	This symbol is defined to indicate that the strchr()/strrchr()
 *	functions are available for string searching. If not, try the
 *	index()/rindex() pair.
 */
/* HAS_INDEX:
 *	This symbol is defined to indicate that the index()/rindex()
 *	functions are available for string searching.
 */
#$d_strchr HAS_STRCHR	/**/
#$d_index HAS_INDEX	/**/

/* HAS_STRCOLL:
 *	This symbol, if defined, indicates that the strcoll routine is
 *	available to compare strings using collating information.
 */
#$d_strcoll HAS_STRCOLL	/**/

/* USE_STRUCT_COPY:
 *	This symbol, if defined, indicates that this C compiler knows how
 *	to copy structures.  If undefined, you'll need to use a block copy
 *	routine of some sort instead.
 */
#$d_strctcpy	USE_STRUCT_COPY	/**/

/* HAS_STRERROR:
 *	This symbol, if defined, indicates that the strerror routine is
 *	available to translate error numbers to strings. See the writeup
 *	of Strerror() in this file before you try to define your own.
 */
/* HAS_SYS_ERRLIST:
 *	This symbol, if defined, indicates that the sys_errlist array is
 *	available to translate error numbers to strings. The extern int
 *	sys_nerr gives the size of that table.
 */
/* Strerror:
 *	This preprocessor symbol is defined as a macro if strerror() is
 *	not available to translate error numbers to strings but sys_errlist[]
 *	array is there.
 */
#$d_strerror HAS_STRERROR		/**/
#$d_syserrlst HAS_SYS_ERRLIST	/**/
#define Strerror(e) $d_strerrm

/* HAS_STRTOD:
 *	This symbol, if defined, indicates that the strtod routine is
 *	available to provide better numeric string conversion than atof().
 */
#$d_strtod HAS_STRTOD	/**/

/* HAS_STRTOL:
 *	This symbol, if defined, indicates that the strtol routine is available
 *	to provide better numeric string conversion than atoi() and friends.
 */
#$d_strtol HAS_STRTOL	/**/

/* HAS_STRTOUL:
 *	This symbol, if defined, indicates that the strtoul routine is
 *	available to provide conversion of strings to unsigned long.
 */
#$d_strtoul HAS_STRTOUL	/**/

/* HAS_STRXFRM:
 *	This symbol, if defined, indicates that the strxfrm() routine is
 *	available to transform strings.
 */
#$d_strxfrm HAS_STRXFRM	/**/

/* HAS_SYMLINK:
 *	This symbol, if defined, indicates that the symlink routine is available
 *	to create symbolic links.
 */
#$d_symlink HAS_SYMLINK	/**/

/* HAS_SYSCALL:
 *	This symbol, if defined, indicates that the syscall routine is
 *	available to call arbitrary system calls. If undefined, that's tough.
 */
#$d_syscall HAS_SYSCALL	/**/

/* HAS_SYSCONF:
 *	This symbol, if defined, indicates that sysconf() is available
 *	to determine system related limits and options.
 */
#$d_sysconf HAS_SYSCONF	/**/

/* HAS_SYSTEM:
 *	This symbol, if defined, indicates that the system routine is
 *	available to issue a shell command.
 */
#$d_system HAS_SYSTEM	/**/

/* HAS_TCGETPGRP:
 *	This symbol, if defined, indicates that the tcgetpgrp routine is
 *	available to get foreground process group ID.
 */
#$d_tcgetpgrp HAS_TCGETPGRP		/**/

/* HAS_TCSETPGRP:
 *	This symbol, if defined, indicates that the tcsetpgrp routine is
 *	available to set foreground process group ID.
 */
#$d_tcsetpgrp HAS_TCSETPGRP		/**/

/* Time_t:
 *	This symbol holds the type returned by time(). It can be long,
 *	or time_t on BSD sites (in which case <sys/types.h> should be
 *	included).
 */
#define Time_t $timetype		/* Time type */

/* HAS_TIMES:
 *	This symbol, if defined, indicates that the times() routine exists.
 *	Note that this became obsolete on some systems (SUNOS), which now
 * use getrusage(). It may be necessary to include <sys/times.h>.
 */
#$d_times HAS_TIMES		/**/

/* HAS_TRUNCATE:
 *	This symbol, if defined, indicates that the truncate routine is
 *	available to truncate files.
 */
#$d_truncate HAS_TRUNCATE	/**/

/* HAS_TZNAME:
 *	This symbol, if defined, indicates that the tzname[] array is
 *	available to access timezone names.
 */
#$d_tzname HAS_TZNAME		/**/

/* HAS_UMASK:
 *	This symbol, if defined, indicates that the umask routine is
 *	available to set and get the value of the file creation mask.
 */
#$d_umask HAS_UMASK		/**/

/* HAS_VFORK:
 *	This symbol, if defined, indicates that vfork() exists.
 */
#$d_vfork HAS_VFORK	/**/

/* Signal_t:
 *	This symbol's value is either "void" or "int", corresponding to the
 *	appropriate return type of a signal handler.  Thus, you can declare
 *	a signal handler using "Signal_t (*handler)()", and define the
 *	handler using "Signal_t handler(sig)".
 */
#define Signal_t $signal_t	/* Signal handler's return type */

/* HASVOLATILE:
 *	This symbol, if defined, indicates that this C compiler knows about
 *	the volatile declaration.
 */
#$d_volatile	HASVOLATILE	/**/
#ifndef HASVOLATILE
#define volatile
#endif

/* HAS_VPRINTF:
 *	This symbol, if defined, indicates that the vprintf routine is available
 *	to printf with a pointer to an argument list.  If unavailable, you
 *	may need to write your own, probably in terms of _doprnt().
 */
/* USE_CHAR_VSPRINTF:
 *	This symbol is defined if this system has vsprintf() returning type
 *	(char*).  The trend seems to be to declare it as "int vsprintf()".  It
 *	is up to the package author to declare vsprintf correctly based on the
 *	symbol.
 */
#$d_vprintf HAS_VPRINTF	/**/
#$d_charvspr USE_CHAR_VSPRINTF 	/**/

/* HAS_WAIT4:
 *	This symbol, if defined, indicates that wait4() exists.
 */
#$d_wait4 HAS_WAIT4	/**/

/* HAS_WAITPID:
 *	This symbol, if defined, indicates that the waitpid routine is
 *	available to wait for child process.
 */
#$d_waitpid HAS_WAITPID	/**/

/* HAS_WCSTOMBS:
 *	This symbol, if defined, indicates that the wcstombs routine is
 *	available to convert wide character strings to multibyte strings.
 */
#$d_wcstombs HAS_WCSTOMBS	/**/

/* HAS_WCTOMB:
 *	This symbol, if defined, indicates that the wctomb routine is available
 *	to covert a wide character to a multibyte.
 */
#$d_wctomb HAS_WCTOMB		/**/

/* Fpos_t:
 *	This symbol holds the type used to declare file positions in libc.
 *	It can be fpos_t, long, uint, etc... It may be necessary to include
 *	<sys/types.h> to get any typedef'ed information.
 */
#define Fpos_t $fpostype		/* File position type */

/* Gid_t:
 *	This symbol holds the return type of getgid() and the type of
 *	argument to setrgid() and related functions.  Typically,
 *	it is the type of group ids in the kernel. It can be int, ushort,
 *	uid_t, etc... It may be necessary to include <sys/types.h> to get
 *	any typedef'ed information.
 */
#define Gid_t $gidtype		/* Type for getgid(), etc... */

/* Groups_t:
 *	This symbol holds the type used for the second argument to
 *	[gs]etgroups().  Usually, this is the same of gidtype, but
 *	sometimes it isn't.  It can be int, ushort, uid_t, etc... 
 *	It may be necessary to include <sys/types.h> to get any 
 *	typedef'ed information.  This is only required if you have
 *	getgroups() or setgroups().
 */
#if defined(HAS_GETGROUPS) || defined(HAS_SETGROUPS)
#define Groups_t $groupstype	/* Type for 2nd arg to [gs]etgroups() */
#endif

/* DB_Prefix_t:
 *	This symbol contains the type of the prefix structure element
 *	in the <db.h> header file.  In older versions of DB, it was
 *	int, while in newer ones it is u_int32_t.
 */
/* DB_Hash_t:
 *	This symbol contains the type of the prefix structure element
 *	in the <db.h> header file.  In older versions of DB, it was
 *	int, while in newer ones it is size_t.
 */
#define DB_Hash_t	$db_hashtype		/**/
#define DB_Prefix_t	$db_prefixtype  	/**/

/* I_DIRENT:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <dirent.h>. Using this symbol also triggers the definition
 *	of the Direntry_t define which ends up being 'struct dirent' or
 *	'struct direct' depending on the availability of <dirent.h>.
 */
/* DIRNAMLEN:
 *	This symbol, if defined, indicates to the C program that the length
 *	of directory entry names is provided by a d_namlen field.  Otherwise
 *	you need to do strlen() on the d_name field.
 */
/* Direntry_t:
 *	This symbol is set to 'struct direct' or 'struct dirent' depending on
 *	whether dirent is available or not. You should use this pseudo type to
 *	portably declare your directory entries.
 */
#$i_dirent I_DIRENT		/**/
#$d_dirnamlen DIRNAMLEN	/**/
#define Direntry_t $direntrytype

/* I_DLFCN:
 *	This symbol, if defined, indicates that <dlfcn.h> exists and should
 *	be included.
 */
#$i_dlfcn I_DLFCN		/**/

/* I_FCNTL:
 *	This manifest constant tells the C program to include <fcntl.h>.
 */
#$i_fcntl I_FCNTL	/**/

/* I_FLOAT:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <float.h> to get definition of symbols like DBL_MAX or
 *	DBL_MIN, i.e. machine dependent floating point values.
 */
#$i_float I_FLOAT		/**/

/* I_GRP:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <grp.h>.
 */
#$i_grp I_GRP		/**/

/* I_LIMITS:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <limits.h> to get definition of symbols like WORD_BIT or
 *	LONG_MAX, i.e. machine dependant limitations.
 */
#$i_limits I_LIMITS		/**/

/* I_MATH:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <math.h>.
 */
#$i_math I_MATH		/**/

/* I_MEMORY:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <memory.h>.
 */
#$i_memory I_MEMORY		/**/

/* I_NDBM:
 *	This symbol, if defined, indicates that <ndbm.h> exists and should
 *	be included.
 */
#$i_ndbm I_NDBM	/**/

/* I_NET_ERRNO:
 *	This symbol, if defined, indicates that <net/errno.h> exists and 
 *	should be included.
 */
#$i_neterrno I_NET_ERRNO		/**/

/* I_NETINET_IN:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <netinet/in.h>. Otherwise, you may try <sys/in.h>.
 */
#$i_niin I_NETINET_IN	/**/

/* I_PWD:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <pwd.h>.
 */
/* PWQUOTA:
 *	This symbol, if defined, indicates to the C program that struct passwd
 *	contains pw_quota.
 */
/* PWAGE:
 *	This symbol, if defined, indicates to the C program that struct passwd
 *	contains pw_age.
 */
/* PWCHANGE:
 *	This symbol, if defined, indicates to the C program that struct passwd
 *	contains pw_change.
 */
/* PWCLASS:
 *	This symbol, if defined, indicates to the C program that struct passwd
 *	contains pw_class.
 */
/* PWEXPIRE:
 *	This symbol, if defined, indicates to the C program that struct passwd
 *	contains pw_expire.
 */
/* PWCOMMENT:
 *	This symbol, if defined, indicates to the C program that struct passwd
 *	contains pw_comment.
 */
#$i_pwd I_PWD		/**/
#$d_pwquota PWQUOTA	/**/
#$d_pwage PWAGE	/**/
#$d_pwchange PWCHANGE	/**/
#$d_pwclass PWCLASS	/**/
#$d_pwexpire PWEXPIRE	/**/
#$d_pwcomment PWCOMMENT	/**/

/* I_STDDEF:
 *	This symbol, if defined, indicates that <stddef.h> exists and should
 *	be included.
 */
#$i_stddef I_STDDEF	/**/

/* I_STDLIB:
 *	This symbol, if defined, indicates that <stdlib.h> exists and should
 *	be included.
 */
#$i_stdlib I_STDLIB		/**/

/* I_STRING:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <string.h> (USG systems) instead of <strings.h> (BSD systems).
 */
#$i_string I_STRING		/**/

/* I_SYS_DIR:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/dir.h>.
 */
#$i_sysdir I_SYS_DIR		/**/

/* I_SYS_FILE:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/file.h> to get definition of R_OK and friends.
 */
#$i_sysfile I_SYS_FILE		/**/

/* I_SYS_IOCTL:
 *	This symbol, if defined, indicates that <sys/ioctl.h> exists and should
 *	be included. Otherwise, include <sgtty.h> or <termio.h>.
 */
#$i_sysioctl	I_SYS_IOCTL		/**/

/* I_SYS_NDIR:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/ndir.h>.
 */
#$i_sysndir I_SYS_NDIR	/**/

/* I_SYS_PARAM:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/param.h>.
 */
#$i_sysparam I_SYS_PARAM		/**/

/* I_SYS_RESOURCE:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/resource.h>.
 */
#$i_sysresrc I_SYS_RESOURCE		/**/

/* I_SYS_SELECT:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/select.h> in order to get definition of struct timeval.
 */
#$i_sysselct I_SYS_SELECT	/**/

/* I_SYS_TIMES:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/times.h>.
 */
#$i_systimes	I_SYS_TIMES		/**/

/* I_SYS_TYPES:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/types.h>.
 */
#$i_systypes	I_SYS_TYPES		/**/

/* I_SYS_UN:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/un.h> to get UNIX domain socket definitions.
 */
#$i_sysun I_SYS_UN		/**/

/* I_SYS_WAIT:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/wait.h>.
 */
#$i_syswait I_SYS_WAIT	/**/

/* I_TERMIO:
 *	This symbol, if defined, indicates that the program should include
 *	<termio.h> rather than <sgtty.h>.  There are also differences in
 *	the ioctl() calls that depend on the value of this symbol.
 */
/* I_TERMIOS:
 *	This symbol, if defined, indicates that the program should include
 *	the POSIX termios.h rather than sgtty.h or termio.h.
 *	There are also differences in the ioctl() calls that depend on the
 *	value of this symbol.
 */
/* I_SGTTY:
 *	This symbol, if defined, indicates that the program should include
 *	<sgtty.h> rather than <termio.h>.  There are also differences in
 *	the ioctl() calls that depend on the value of this symbol.
 */
#$i_termio I_TERMIO		/**/
#$i_termios I_TERMIOS		/**/
#$i_sgtty I_SGTTY		/**/

/* I_TIME:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <time.h>.
 */
/* I_SYS_TIME:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/time.h>.
 */
/* I_SYS_TIME_KERNEL:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/time.h> with KERNEL defined.
 */
#$i_time I_TIME		/**/
#$i_systime I_SYS_TIME		/**/
#$i_systimek I_SYS_TIME_KERNEL		/**/

/* I_UNISTD:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <unistd.h>.
 */
#$i_unistd I_UNISTD		/**/

/* I_UTIME:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <utime.h>.
 */
#$i_utime I_UTIME		/**/

/* I_STDARG:
 *	This symbol, if defined, indicates that <stdarg.h> exists and should
 *	be included.
 */
/* I_VARARGS:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <varargs.h>.
 */
#$i_stdarg I_STDARG		/**/
#$i_varargs I_VARARGS	/**/

/* I_VFORK:
 *	This symbol, if defined, indicates to the C program that it should
 *	include vfork.h.
 */
#$i_vfork I_VFORK	/**/

/* INTSIZE:
 *	This symbol contains the value of sizeof(int) so that the C
 *	preprocessor can make decisions based on it.
 */
/* LONGSIZE:
 *	This symbol contains the value of sizeof(long) so that the C
 *	preprocessor can make decisions based on it.
 */
/* SHORTSIZE:
 *	This symbol contains the value of sizeof(short) so that the C
 *	preprocessor can make decisions based on it.
 */
#define INTSIZE $intsize		/**/
#define LONGSIZE $longsize		/**/
#define SHORTSIZE $shortsize		/**/

/* Off_t:
 *	This symbol holds the type used to declare offsets in the kernel.
 *	It can be int, long, off_t, etc... It may be necessary to include
 *	<sys/types.h> to get any typedef'ed information.
 */
#define Off_t $lseektype		/* <offset> type */

/* Mode_t:
 *	This symbol holds the type used to declare file modes 
 *	for systems calls.  It is usually mode_t, but may be
 *	int or unsigned short.  It may be necessary to include <sys/types.h>
 *	to get any typedef'ed information.
 */
#define Mode_t $modetype	 /* file mode parameter for system calls */

/* VAL_O_NONBLOCK:
 *	This symbol is to be used during open() or fcntl(F_SETFL) to turn on
 *	non-blocking I/O for the file descriptor. Note that there is no way
 *	back, i.e. you cannot turn it blocking again this way. If you wish to
 *	alternatively switch between blocking and non-blocking, use the
 *	ioctl(FIOSNBIO) call instead, but that is not supported by all devices.
 */
/* VAL_EAGAIN:
 *	This symbol holds the errno error code set by read() when no data was
 *	present on the non-blocking file descriptor.
 */
/* RD_NODATA:
 *	This symbol holds the return code from read() when no data is present
 *	on the non-blocking file descriptor. Be careful! If EOF_NONBLOCK is
 *	not defined, then you can't distinguish between no data and EOF by
 *	issuing a read(). You'll have to find another way to tell for sure!
 */
/* EOF_NONBLOCK:
 *	This symbol, if defined, indicates to the C program that a read() on
 *	a non-blocking file descriptor will return 0 on EOF, and not the value
 *	held in RD_NODATA (-1 usually, in that case!).
 */
#define VAL_O_NONBLOCK $o_nonblock
#define VAL_EAGAIN $eagain
#define RD_NODATA $rd_nodata
#$d_eofnblk EOF_NONBLOCK

/* CAN_PROTOTYPE:
 *	If defined, this macro indicates that the C compiler can handle
 *	function prototypes.
 */
/* _:
 *	This macro is used to declare function parameters for folks who want
 *	to make declarations with prototypes using a different style than
 *	the above macros.  Use double parentheses.  For example:
 *
 *		int main _((int argc, char *argv[]));
 */
#$prototype	CAN_PROTOTYPE	/**/
#ifdef CAN_PROTOTYPE
#define	_(args) args
#else
#define	_(args) ()
#endif

/* RANDBITS:
 *	This symbol contains the number of bits of random number the rand()
 *	function produces.  Usual values are 15, 16, and 31.
 */
#define RANDBITS $randbits		/**/

/* Select_fd_set_t:
 *	This symbol holds the type used for the 2nd, 3rd, and 4th
 *	arguments to select.  Usually, this is 'fd_set *', if HAS_FD_SET
 *	is defined, and 'int *' otherwise.  This is only useful if you 
 *	have select(), of course.
 */
#define Select_fd_set_t 	$selecttype	/**/

/* Size_t:
 *	This symbol holds the type used to declare length parameters
 *	for string functions.  It is usually size_t, but may be
 *	unsigned long, int, etc.  It may be necessary to include
 *	<sys/types.h> to get any typedef'ed information.
 */
#define Size_t $sizetype	 /* length paramater for string functions */

/* SSize_t:
 *	This symbol holds the type used by functions that return
 *	a count of bytes or an error condition.  It must be a signed type.
 *	It is usually ssize_t, but may be long or int, etc.
 *	It may be necessary to include <sys/types.h> or <unistd.h>
 *	to get any typedef'ed information.
 *	We will pick a type such that sizeof(SSize_t) == sizeof(Size_t).
 */
#define SSize_t $ssizetype	 /* signed count of bytes */

/* STDCHAR:
 *	This symbol is defined to be the type of char used in stdio.h.
 *	It has the values "unsigned char" or "char".
 */
#define STDCHAR $stdchar	/**/

/* Uid_t:
 *	This symbol holds the type used to declare user ids in the kernel.
 *	It can be int, ushort, uid_t, etc... It may be necessary to include
 *	<sys/types.h> to get any typedef'ed information.
 */
#define Uid_t $uidtype		/* UID type */

/* LOC_SED:
 *	This symbol holds the complete pathname to the sed program.
 */
#define LOC_SED 	"$full_sed"	/**/

/* OSNAME:
 *	This symbol contains the name of the operating system, as determined
 *	by Configure.  You shouldn't rely on it too much; the specific
 *	feature tests from Configure are generally more reliable.
 */
#define OSNAME "$osname"		/**/

/* ARCHLIB:
 *	This variable, if defined, holds the name of the directory in
 *	which the user wants to put architecture-dependent public
 *	library files for $package.  It is most often a local directory
 *	such as /usr/local/lib.  Programs using this variable must be
 *	prepared to deal with filename expansion.  If ARCHLIB is the
 *	same as PRIVLIB, it is not defined, since presumably the
 *	program already searches PRIVLIB.
 */
/* ARCHLIB_EXP:
 *	This symbol contains the ~name expanded version of ARCHLIB, to be used
 *	in programs that are not prepared to deal with ~ expansion at run-time.
 */
#$d_archlib ARCHLIB "$archlib"		/**/
#$d_archlib ARCHLIB_EXP "$archlibexp"		/**/

/* BINCOMPAT3:
 *	This symbol, if defined, indicates that Perl 5.004 should be
 *	binary-compatible with Perl 5.003.
 */
#$d_bincompat3 BINCOMPAT3			/**/

/* BYTEORDER:
 *	This symbol holds the hexadecimal constant defined in byteorder,
 *	i.e. 0x1234 or 0x4321, etc...
 *	On NeXT 3.2 (and greater), you can build "Fat" Multiple Architecture
 *	Binaries (MAB) on either big endian or little endian machines.
 *	The endian-ness is available at compile-time.  This only matters
 *	for perl, where the config.h can be generated and installed on 
 *	one system, and used by a different architecture to build an
 *	extension.  Older versions of NeXT that might not have
 *	defined either *_ENDIAN__ were all on Motorola 680x0 series,
 *	so the default case (for NeXT) is big endian to catch them. 
 *	This might matter for NeXT 3.0.
 */
#ifndef NeXT
#define BYTEORDER 0x$byteorder	/* large digits for MSB */
#else  /* NeXT */
#ifdef __LITTLE_ENDIAN__
#define BYTEORDER 0x1234
#else /* __BIG_ENDIAN__ */
#define BYTEORDER 0x4321
#endif /* ENDIAN CHECK */
#endif /* NeXT */

/* CSH:
 *	This symbol, if defined, indicates that the C-shell exists.
 *	If defined, contains the full pathname of csh.
 */
#$d_csh CSH "$full_csh"		/**/

/* DLSYM_NEEDS_UNDERSCORE:
 *	This symbol, if defined, indicates that we need to prepend an
 *	underscore to the symbol name before calling dlsym().  This only
 *	makes sense if you *have* dlsym, which we will presume is the
 *	case if you're using dl_dlopen.xs.
 */
#$d_dlsymun 	DLSYM_NEEDS_UNDERSCORE 	/**/

/* SETUID_SCRIPTS_ARE_SECURE_NOW:
 *	This symbol, if defined, indicates that the bug that prevents
 *	setuid scripts from being secure is not present in this kernel.
 */
/* DOSUID:
 *	This symbol, if defined, indicates that the C program should
 *	check the script that it is executing for setuid/setgid bits, and
 *	attempt to emulate setuid/setgid on systems that have disabled
 *	setuid #! scripts because the kernel can't do it securely.
 *	It is up to the package designer to make sure that this emulation
 *	is done securely.  Among other things, it should do an fstat on
 *	the script it just opened to make sure it really is a setuid/setgid
 *	script, it should make sure the arguments passed correspond exactly
 *	to the argument on the #! line, and it should not trust any
 *	subprocesses to which it must pass the filename rather than the
 *	file descriptor of the script to be executed.
 */
#$d_suidsafe SETUID_SCRIPTS_ARE_SECURE_NOW	/**/
#$d_dosuid DOSUID		/**/

/* Gconvert:
 *	This preprocessor macro is defined to convert a floating point
 *	number to a string without a trailing decimal point.  This
 *	emulates the behavior of sprintf("%g"), but is sometimes much more
 *	efficient.  If gconvert() is not available, but gcvt() drops the
 *	trailing decimal point, then gcvt() is used.  If all else fails,
 *	a macro using sprintf("%g") is used. Arguments for the Gconvert
 *	macro are: value, number of digits, whether trailing zeros should
 *	be retained, and the output buffer.
 *	Possible values are:
 *		d_Gconvert='gconvert((x),(n),(t),(b))'
 *		d_Gconvert='gcvt((x),(n),(b))'
 *		d_Gconvert='sprintf((b),"%.*g",(n),(x))'
 *	The last two assume trailing zeros should not be kept.
 */
#define Gconvert(x,n,t,b) $d_Gconvert

/* HAS_GETPGID:
 *	This symbol, if defined, indicates to the C program that 
 *	the getpgid(pid) function is available to get the
 *	process group id.
 */
#$d_getpgid HAS_GETPGID		/**/

/* HAS_GETPGRP:
 *	This symbol, if defined, indicates that the getpgrp routine is
 *	available to get the current process group.
 */
/* USE_BSD_GETPGRP:
 *	This symbol, if defined, indicates that getpgrp needs one
 *	arguments whereas USG one needs none.
 */
#$d_getpgrp HAS_GETPGRP		/**/
#$d_bsdgetpgrp USE_BSD_GETPGRP	/**/

/* HAS_INET_ATON:
 *	This symbol, if defined, indicates to the C program that the
 *	inet_aton() function is available to parse IP address "dotted-quad"
 *	strings.
 */
#$d_inetaton HAS_INET_ATON		/**/

/* HAS_SETPGID:
 *	This symbol, if defined, indicates to the C program that 
 *	the setpgid(pid, gpid) function is available to set the
 *	process group id.
 */
#$d_setpgid HAS_SETPGID		/**/

/* HAS_SETPGRP:
 *	This symbol, if defined, indicates that the setpgrp routine is
 *	available to set the current process group.
 */
/* USE_BSD_SETPGRP:
 *	This symbol, if defined, indicates that setpgrp needs two
 *	arguments whereas USG one needs none.  See also HAS_SETPGID
 *	for a POSIX interface.
 */
/* USE_BSDPGRP:
 *	This symbol, if defined, indicates that the BSD notion of process
 *	group is to be used. For instance, you have to say setpgrp(pid, pgrp)
 *	instead of the USG setpgrp().  This should be obsolete since
 *	there are systems which have BSD-ish setpgrp but USG-ish getpgrp.
 */
#$d_setpgrp HAS_SETPGRP		/**/
#$d_bsdsetpgrp USE_BSD_SETPGRP	/**/
#$d_bsdpgrp USE_BSDPGRP		/**/

/* USE_SFIO:
 *	This symbol, if defined, indicates that sfio should
 *	be used.
 */
#$d_sfio	USE_SFIO		/**/

/* Sigjmp_buf:
 *	This is the buffer type to be used with Sigsetjmp and Siglongjmp.
 */
/* Sigsetjmp:
 *	This macro is used in the same way as sigsetjmp(), but will invoke
 *	traditional setjmp() if sigsetjmp isn't available.
 *	See HAS_SIGSETJMP.
 */
/* Siglongjmp:
 *	This macro is used in the same way as siglongjmp(), but will invoke
 *	traditional longjmp() if siglongjmp isn't available.
 *	See HAS_SIGSETJMP.
 */
#$d_sigsetjmp HAS_SIGSETJMP	/**/
#ifdef HAS_SIGSETJMP
#define Sigjmp_buf sigjmp_buf
#define Sigsetjmp(buf,save_mask) sigsetjmp((buf),(save_mask))
#define Siglongjmp(buf,retval) siglongjmp((buf),(retval))
#else
#define Sigjmp_buf jmp_buf
#define Sigsetjmp(buf,save_mask) setjmp((buf))
#define Siglongjmp(buf,retval) longjmp((buf),(retval))
#endif

/* USE_DYNAMIC_LOADING:
 *	This symbol, if defined, indicates that dynamic loading of
 *	some sort is available.
 */
#$usedl USE_DYNAMIC_LOADING		/**/

/* I_DBM:
 *	This symbol, if defined, indicates that <dbm.h> exists and should
 *	be included.
 */
/* I_RPCSVC_DBM:
 *	This symbol, if defined, indicates that <rpcsvc/dbm.h> exists and
 *	should be included.
 */
#$i_dbm I_DBM	/**/
#$i_rpcsvcdbm I_RPCSVC_DBM	/**/

/* I_LOCALE:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <locale.h>.
 */
#$i_locale	I_LOCALE		/**/

/* I_SFIO:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sfio.h>.
 */
#$i_sfio	I_SFIO		/**/

/* I_SYS_STAT:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/stat.h>.
 */
#$i_sysstat	I_SYS_STAT		/**/

/* I_VALUES:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <values.h> to get definition of symbols like MINFLOAT or
 *	MAXLONG, i.e. machine dependant limitations.  Probably, you
 *	should use <limits.h> instead, if it is available.
 */
#$i_values I_VALUES		/**/

/* Free_t:
 *	This variable contains the return type of free().  It is usually
 * void, but occasionally int.
 */
/* Malloc_t:
 *	This symbol is the type of pointer returned by malloc and realloc.
 */
#define Malloc_t $malloctype			/**/
#define Free_t $freetype			/**/

/* MYMALLOC:
 *	This symbol, if defined, indicates that we're using our own malloc.
 */
#$d_mymalloc MYMALLOC			/**/

/* OLDARCHLIB:
 *	This variable, if defined, holds the name of the directory in
 *	which the user has perl5.000 or perl5.001 architecture-dependent
 *	public library files for $package.  For the most part, these
 *	files will work with 5.002 (and later), but that is not
 *	guaranteed.
 */
/* OLDARCHLIB_EXP:
 *	This symbol contains the ~name expanded version of OLDARCHLIB, to be
 *	used in programs that are not prepared to deal with ~ expansion at 
 *	run-time.
 */
#$d_oldarchlib OLDARCHLIB "$oldarchlib"		/**/
#$d_oldarchlib OLDARCHLIB_EXP "$oldarchlibexp"		/**/

/* PRIVLIB:
 *	This symbol contains the name of the private library for this package.
 *	The library is private in the sense that it needn't be in anyone's
 *	execution path, but it should be accessible by the world.  The program
 *	should be prepared to do ~ expansion.
 */
/* PRIVLIB_EXP:
 *	This symbol contains the ~name expanded version of PRIVLIB, to be used
 *	in programs that are not prepared to deal with ~ expansion at run-time.
 */
#define PRIVLIB "$privlib"		/**/
#define PRIVLIB_EXP "$privlibexp"		/**/

/* SH_PATH:
 *	This symbol contains the full pathname to the shell used on this
 *	on this system to execute Bourne shell scripts.  Usually, this will be
 *	/bin/sh, though it's possible that some systems will have /bin/ksh,
 *	/bin/pdksh, /bin/ash, /bin/bash, or even something such as
 *	D:/bin/sh.exe.
 */
#define SH_PATH "$sh"  /**/

/* SIG_NAME:
 *	This symbol contains a list of signal names in order of
 *	signal number. This is intended
 *	to be used as a static array initialization, like this:
 *		char *sig_name[] = { SIG_NAME };
 *	The signals in the list are separated with commas, and each signal
 *	is surrounded by double quotes. There is no leading SIG in the signal
 *	name, i.e. SIGQUIT is known as "QUIT".
 *	Gaps in the signal numbers (up to NSIG) are filled in with NUMnn,
 *	etc., where nn is the actual signal number (e.g. NUM37).
 *	The signal number for sig_name[i] is stored in sig_num[i].
 *	The last element is 0 to terminate the list with a NULL.  This
 *	corresponds to the 0 at the end of the sig_num list.
 */
/* SIG_NUM:
 *	This symbol contains a list of signal numbers, in the same order as the
 *	SIG_NAME list. It is suitable for static array initialization, as in:
 *		int sig_num[] = { SIG_NUM };
 *	The signals in the list are separated with commas, and the indices
 *	within that list and the SIG_NAME list match, so it's easy to compute
 *	the signal name from a number or vice versa at the price of a small
 *	dynamic linear lookup. 
 *	Duplicates are allowed, but are moved to the end of the list.
 *	The signal number corresponding to sig_name[i] is sig_number[i].
 *	if (i < NSIG) then sig_number[i] == i.  
 *	The last element is 0, corresponding to the 0 at the end of
 *	the sig_name list.
 */
#define SIG_NAME "`echo $sig_name | sed 's/ /","/g'`",0	/**/
#define SIG_NUM `echo $sig_num 0 | sed 's/ /,/g'`	/**/

/* SITEARCH:
 *	This symbol contains the name of the private library for this package.
 *	The library is private in the sense that it needn't be in anyone's
 *	execution path, but it should be accessible by the world.  The program
 *	should be prepared to do ~ expansion.
 *	The standard distribution will put nothing in this directory.
 *	Individual sites may place their own extensions and modules in
 *	this directory.
 */
/* SITEARCH_EXP:
 *	This symbol contains the ~name expanded version of SITEARCH, to be used
 *	in programs that are not prepared to deal with ~ expansion at run-time.
 */
#define SITEARCH "$sitearch"		/**/
#define SITEARCH_EXP "$sitearchexp"		/**/

/* SITELIB:
 *	This symbol contains the name of the private library for this package.
 *	The library is private in the sense that it needn't be in anyone's
 *	execution path, but it should be accessible by the world.  The program
 *	should be prepared to do ~ expansion.
 *	The standard distribution will put nothing in this directory.
 *	Individual sites may place their own extensions and modules in
 *	this directory.
 */
/* SITELIB_EXP:
 *	This symbol contains the ~name expanded version of SITELIB, to be used
 *	in programs that are not prepared to deal with ~ expansion at run-time.
 */
#define SITELIB "$sitelib"		/**/
#define SITELIB_EXP "$sitelibexp"		/**/

/* STARTPERL:
 *	This variable contains the string to put in front of a perl
 *	script to make sure (one hopes) that it runs with perl and not
 *	some shell.
 */
#define STARTPERL "$startperl"		/**/

/* USE_PERLIO:
 *	This symbol, if defined, indicates that the PerlIO abstraction should
 *	be used throughout.  If not defined, stdio should be
 *	used in a fully backward compatible manner.
 */
#$useperlio	USE_PERLIO		/**/

/* VOIDFLAGS:
 *	This symbol indicates how much support of the void type is given by this
 *	compiler.  What various bits mean:
 *
 *	    1 = supports declaration of void
 *	    2 = supports arrays of pointers to functions returning void
 *	    4 = supports comparisons between pointers to void functions and
 *		    addresses of void functions
 *	    8 = suports declaration of generic void pointers
 *
 *	The package designer should define VOIDUSED to indicate the requirements
 *	of the package.  This can be done either by #defining VOIDUSED before
 *	including config.h, or by defining defvoidused in Myinit.U.  If the
 *	latter approach is taken, only those flags will be tested.  If the
 *	level of void support necessary is not present, defines void to int.
 */
#ifndef VOIDUSED
#define VOIDUSED $defvoidused
#endif
#define VOIDFLAGS $voidflags
#if (VOIDFLAGS & VOIDUSED) != VOIDUSED
#define void int		/* is void to be avoided? */
#define M_VOID			/* Xenix strikes again */
#endif

#endif
!GROK!THIS!
