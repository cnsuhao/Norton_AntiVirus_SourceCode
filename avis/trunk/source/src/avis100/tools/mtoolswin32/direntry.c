#include "sysincludes.h"
#include "msdos.h"
#include "stream.h"
#include "file.h"
#include "mtoolsDirentry.h"

void initializeDirentry(direntry_t *entry, Stream_t *Dir)
{
	entry->entry = -1;
/*	entry->parent = getDirentry(Dir);*/
	entry->Dir = Dir;
}

int isNotFound(direntry_t *entry)
{
	return entry->entry == -2;
}

void rewindEntry(direntry_t *entry)
{
	entry->entry = -1;
}


direntry_t *getParent(direntry_t *entry)
{
	return getDirentry(entry->Dir);
}


static int getPathLen(direntry_t *entry)
{
	int length=0;

	while(1) {
		if(entry->entry == -3) /* rootDir */
			return length + 3;
		
		length += 1 + strlen(entry->name);
		entry = getDirentry(entry->Dir);
	}
}

static char *sprintPwd(direntry_t *entry, char *ptr)
{
	if(entry->entry == -3) {
		*ptr++ = getDrive(entry->Dir);
		*ptr++ = ':';
/*		*ptr++ = '/'; */
		*ptr++ = '\\';
		*ptr   = '\0';
	} else {
		ptr = sprintPwd(getDirentry(entry->Dir), ptr);
/*		if(ptr[-1] != '/')
			*ptr++ = '/'; */
		if(ptr[-1] != '\\')
			*ptr++ = '\\';
		strcpy(ptr, entry->name);
		ptr += strlen(entry->name);
	}
	return ptr;		
}


static void _fprintPwd(FILE *f, direntry_t *entry, int recurs)
{
	if(entry->entry == -3) {
		putc(getDrive(entry->Dir), f);
		putc(':', f);
		if(!recurs)
/*			putc('/', f); */
			putc('\\', f);
	} else {
		_fprintPwd(f, getDirentry(entry->Dir), 1);
/*		fprintf(f, "/%s", entry->name); */
		fprintf(f, "\\%s", entry->name);
	}
}

void fprintPwd(FILE *f, direntry_t *entry)
{
	_fprintPwd(f, entry, 0);
}

char *getPwd(direntry_t *entry)
{
	int size;
	char *ret;

	size = getPathLen(entry);
	ret = (char *)malloc(size+1);
	if(!ret)
		return 0;
	sprintPwd(entry, ret);
	return ret;
}

int isSubdirOf(Stream_t *inside, Stream_t *outside)
{
	while(1) {
		if(inside == outside) /* both are the same */
			return 1;
		if(getDirentry(inside)->entry == -3) /* root directory */
			return 0;
		/* look further up */
		inside = getDirentry(inside)->Dir;
	}			
}
