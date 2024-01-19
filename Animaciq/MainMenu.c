#include "Declarations.h"

void ExitProgram();

void ExitProgram()
{
	set_cursor_visible(1);
	clrScr();
	exit(1);
}


HANDLE gDoneEvent=NULL;
HANDLE hTimer = NULL;
HANDLE hTimerQueue = NULL;


VOID CALLBACK TimerRoutine(PVOID lpParam, BOOLEAN TimerOrWaitFired)
{
         
   	put_screen(&coord, mainchInfo);
      
    SetEvent(gDoneEvent);
}

int SetTimerFun()
{

    int arg = 0;

    // Use an event object to track the TimerRoutine execution
    gDoneEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
    if (NULL == gDoneEvent)
    {
        printf("CreateEvent failed (%d)\n", GetLastError());
        return 1;
    }

    // Create the timer queue.
    hTimerQueue = CreateTimerQueue();
    if (NULL == hTimerQueue)
    {
        printf("CreateTimerQueue failed (%d)\n", GetLastError());
        return 2;
    }

    // Set a timer to call the timer routine in 10 seconds.
    if (!CreateTimerQueueTimer( &hTimer, hTimerQueue, (WAITORTIMERCALLBACK)TimerRoutine, NULL , 3*18, 3*18, 0)) // approx. 100 ms
    {
        printf("CreateTimerQueueTimer failed (%d)\n", GetLastError());
        return 3;
    }

 
  
	


    return 0;
}

void DeleteTimer()
{	
	DeleteTimerQueueTimer(  hTimerQueue, hTimer, NULL);
    CloseHandle(gDoneEvent);

    // Delete all timers in the timer queue.
    if (!DeleteTimerQueue(hTimerQueue))
        printf("DeleteTimerQueue failed (%d)\n", GetLastError());
}