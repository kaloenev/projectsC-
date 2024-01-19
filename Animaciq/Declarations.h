#ifndef __DECLARTIONS_H__
#define __DECLARTIONS_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#define WINVER 0x0600   //win7
//#define _WIN32_WINNT 0x0600

#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <direct.h>
#include <time.h>

typedef enum Alignment_ {alLeft, alCenter, alRight} Alignment;
extern int GetKey();

#define MAX 255

#include "keys.h"
//#include "uObjects.h"
#include "Globals.h"
#include "cons.h"
//#include "Colors.h"
//#include "uFunctions.h"

// possible values for color attribute are (multiple of these can be used with bitwise OR):

#define FOREGROUND_BLUE      0x0001 // text color contains blue.
#define FOREGROUND_GREEN     0x0002 // text color contains green.
#define FOREGROUND_RED       0x0004 // text color contains red.
#define FOREGROUND_INTENSITY 0x0008 // text color is intensified.
#define BACKGROUND_BLUE      0x0010 // background color contains blue.
#define BACKGROUND_GREEN     0x0020 // background color contains green.
#define BACKGROUND_RED       0x0040 // background color contains red.
#define BACKGROUND_INTENSITY 0x0080 // background color is intensified.

#define FOREGROUND_WHITE     0x0007 // text color contains dark white.
#define FOREGROUND_INTENSIVEWHITE     0x000F // text color contains intensive white

#endif /* __DECLARTIONS_H__ */
