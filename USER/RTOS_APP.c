#include "RTOS_APP.h"
#include "RTOS_task.h"
#include "RTOS_sem.h"
#include "RTOS_mutex.h"
#include "RTOS_msg.h"
#include "RTOS_timer.h"
#include "usart.h"
PTASK_TCB task0;
PTASK_TCB task1;
PTIMER_CB usartTimer;
PSEM_CB		usartSem;
PMUTEX_CB usartMutex;
PMSG_CB usartMsg;
void Task0(void* arg){
	uint32* msg;
	char sendCache;
	arg=arg;
	while(1){
		//SemPend(usartSem,0);
		//uart_send_bytes("1234\r\n",7);
		
//		MutexLock(usartMutex,0);
//		uart_send_bytes("1234\r\n",7);	
//		MutexUnlock(usartMutex);
//		OSTaskDelay(300);
		
			MsgGet(usartMsg,(void**)&msg,0);
			sendCache = ((*msg)%10+'0');
			uart_send_bytes(&sendCache,1);	
			OSTaskDelay(20);
	}
}
void Task1(void* arg){
	uint32 msg=1;
	arg=arg;
	while(1){
		//SemPost(usartSem);
		//OSTaskDelay(100);
		
//		MutexLock(usartMutex,0);
//		uart_send_bytes("5678\r\n",7);
//		MutexUnlock(usartMutex);
//		OSTaskDelay(1000);
		
		MsgPut(usartMsg,&msg,0);
		msg++;
		OSTaskDelay(200);
	}
}
void TaskTimer(void* arg){
	arg=arg;
	uart_send_bytes("hello\r\n",8);
	//OSScheduleCTRL(FALSE);
}

void TaskInit(void* arg){
	arg=arg;
	task0=OSCreateTask(Task0,NULL,5,128);
	task1=OSCreateTask(Task1,NULL,5,128);
	usartTimer=TimerCreate(TaskTimer,NULL,5,128,TIMER_MODE_ONCE,180);
	TimerStart(usartTimer);
	usartSem=SemCreate(0,6);
	usartMutex=MutexCreate();
	usartMsg=MsgCreate();
}

void RTOSUserInit(void){
	OSCreateTask(TaskInit,NULL,5,128);
	
}

