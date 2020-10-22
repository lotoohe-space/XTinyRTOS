
#include "delay.h"
#include "sys.h"
#include "usart.h"	 
#include "tim3.h"
#include "net_init.h"
#include "sdio_sdcard.h"
#include <stdlib.h>

#include "RTOS_task.h"
#include "RTOS_APP.h"
#include "lwip/apps/httpd.h"
#include "lwip/apps/lwiperf.h"

 int main(void)
 {	 		     
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
	uart_init(115200);	 	//串口初始化为115200
	
	 
	OSInit();
	SysTick_Config(SystemCoreClock / OS_TICKS_PER_SEC);
	 
	if(lwip_comm_init()==0){
		//printf("网络初始化成功..\r\n");
	}
	httpd_init();
	RTOSUserInit();
	OSStart();
	while(1);
}





































/************************************************************************/

//电阻触摸屏测试
 
//DevEBox  大越创新
//淘宝店铺：mcudev.taobao.com
//淘宝店铺：shop389957290.taobao.com	

/************************************************************************/








