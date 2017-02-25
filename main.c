#include <stdio.h>
#include "coroutine.h"

void task1(void)
{
	static unsigned int count = 0;
	routineSupport();
	printf("task1 ready!\n");
	do
	{
		printf("Task1 enter %d\n",count++);
		yield();
	}
	while_(1);
}
void task2(void)
{
	static unsigned int count = 0;
	routineSupport();
	printf("Task2 ready!\n");
	do
	{
		printf("task2 enter %d\n",count++);
		yield();
	}
	while_(1);
}
void task3(void)
{
	static unsigned int count = 0;
	routineSupport();
	printf("task3 ready!\n");
	do
	{
		printf("task3 enter %d\n",count++);
		yield();
	}
	while_(1);
}

int main(void)
{
	addCoroutine(task1);
	addCoroutine(task2);
	addCoroutine(task3);
	runCoroutine();
}
