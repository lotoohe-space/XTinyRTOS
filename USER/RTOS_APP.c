#include "RTOS_APP.h"
#include "RTOS_task.h"
#include "RTOS_sem.h"
#include "RTOS_mutex.h"
#include "RTOS_msg.h"
#include "RTOS_timer.h"
#include "usart.h"
#include "ff.h"
PTASK_TCB task0;
PTASK_TCB task1;
PTASK_TCB task2;
PTASK_TCB task3;
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
		
			MsgGet(usartMsg,(void**)&msg,0xFFFFFFFF);
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
		
		MsgPut(usartMsg,&msg,0xFFFFFFFF);
		msg++;
		OSTaskDelay(200);
	}
}
void Task2(void* arg){
	arg=arg;
	
}
void TaskTimer(void* arg){
	arg=arg;
	uart_send_bytes("hello\r\n",8);
	//OSScheduleCTRL(FALSE);
}

FATFS fs0;
FIL fp;
void fatfsTest(void* arg){
	FRESULT fr;
	UINT bw=0,br;
	f_mount(&fs0, "0:", 1);
	/* Create destination file on the drive 0 */
	fr = f_open(&fp, "0:file.text", FA_WRITE | FA_CREATE_ALWAYS);
	if (fr) return ;
	br=4;
	f_write(&fp, "1234", br, &bw);            /* Write it to the destination file */
	if (bw < br) {
		f_close(&fp);
		return; /* error or disk full */
	}
	f_close(&fp);
}
void TaskInit(void* arg){
	arg=arg;
//	task0=OSCreateTask(Task0,NULL,6,128);
//	task1=OSCreateTask(Task1,NULL,6,128);
//	task2=OSCreateTask(Task2,NULL,6,128);
//	usartTimer=TimerCreate(TaskTimer,NULL,6,128,TIMER_MODE_ONCE,180);
//	TimerStart(usartTimer);
//	usartSem=SemCreate(0,6);
//	usartMutex=MutexCreate();
//	usartMsg=MsgCreate();
	
	task3=OSCreateTask(fatfsTest,NULL,6,256);
	
}

void RTOSUserInit(void){
	OSCreateTask(TaskInit,NULL,5,128);
	
}

