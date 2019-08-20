// Scan.c ... scanning operations

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "Globals.h"
#include "Scan.h"
#include "Page.h"

// startScan: start a scan on an open file
// - returns a pointer to a newly created Scan object
// - if Scan object can't be created, return NULL
// - if Scan object is created, initialise it appropriately
//   - which includes making a copy of the file descriptor
Scan *startScan(int file)
{
    Scan *new = malloc(sizeof(Scan));
    new->file = file;
    new->cur_page = 0;
    new->cur_tup = -1;
    readPage(file,0,&new->page);
    return new;
}

// nextTuple: get the tuple during a scan
// - if no more tuples, return NONE
// - if finds an invalid tuple offset, return NONE
// - otherwise advance to next tuple
//   - may have to move to next page
//   - may have to skip empty pages
//   - may eventually discover "no more tuples"
// - copy next tuple string into buf and return OK
int nextTuple(Scan *s, char *buf)
{
    if(s->cur_tup+1 < s->page.ntuples){
        int of = s->page.offset[s->cur_tup+1];
        strcpy(buf,&s->page.tuples[of]);
        s->cur_tup++;
        return OK;
    }
    if(readPage(s->file,s->cur_page+1,&s->page)!=NONE){
        s->cur_tup = -1;
        s->cur_page++;
        return nextTuple(s,buf);
    }
	return NONE; // replace this line
}

// closeScan: clean up after a scan finishes
void closeScan(Scan *s)
{
	if (s != NULL) free(s);
}
