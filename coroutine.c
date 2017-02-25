#include "coroutine.h"

unsigned char CurentCoroutine;
static unsigned char pCoroutineCount = 0;
static pCoroutine pCoroutineList[MaxCoroutineSuport];
unsigned int CoroutineLine[MaxCoroutineSuport];
unsigned char addCoroutine(pCoroutine task)
{
	if(pCoroutineCount<MaxCoroutineSuport)
	{
		pCoroutineList[pCoroutineCount] = task;
		CoroutineLine[pCoroutineCount] = 0;
		pCoroutineCount++;
		return 1;
	}
	else
	{
		return 0;
	}
}
void runCoroutine(void)
{
	while(1)
	{
		CurentCoroutine = (CurentCoroutine+1)%pCoroutineCount;
		pCoroutineList[CurentCoroutine]();
	}
}
