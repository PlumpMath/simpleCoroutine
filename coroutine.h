#ifndef __COROUTINE_H_
#define __COROUTINE_H_

#ifdef __cplusplus
extern "C" {
#endif

#define MaxCoroutineSuport 10
extern unsigned char CurentCoroutine;
extern unsigned int CoroutineLine[MaxCoroutineSuport];

typedef void (*pCoroutine)(void);
unsigned char addCoroutine(pCoroutine task);
void runCoroutine(void);

#define routineSupport() {char Coroutine_YIELD_FLAG=1;switch(CoroutineLine[CurentCoroutine]){case 0:
#define yield() do{Coroutine_YIELD_FLAG=0;CoroutineLine[CurentCoroutine]=__LINE__;case __LINE__:;if(Coroutine_YIELD_FLAG==0){return;}}while(0)
#define while_(x) while(x);}}

#ifdef __cplusplus
}
#endif  

#endif /* __COROUTINE_H_ */
