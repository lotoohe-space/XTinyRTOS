
#include "delay.h"
#include "sys.h"
#include "usart.h"	 
#include "tim3.h"
#include "net_init.h"
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
	//RTOSUserInit();
	OSStart();
	while(1);
}
////放到主函数的初始化中初始化
//void Timer1CountInitial(void)
//{
//	NVIC_InitTypeDef NVIC_InitStructure;
//	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//	TIM_DeInit(TIM1);	/*复位TIM1定时器*/
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);	/*开时钟*/
//	TIM_TimeBaseStructure.TIM_Period = 100;	/*时钟滴答的次数，够数中断这里是1ms中断一次*/     
//	TIM_TimeBaseStructure.TIM_Prescaler = 720-1;	/* 分频720*/       
//	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;  	 
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	/*计数方向向上计数*/
//	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
//	/* Clear TIM1 update pending flag  清除TIM1溢出中断标志]  */
//	TIM_ClearFlag(TIM1, TIM_FLAG_Update);
//	NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn;	/*溢出中断*/
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 4;  
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(&NVIC_InitStructure);
//	TIM_ITConfig(TIM1, TIM_IT_Update, ENABLE);	/* Enable TIM1 Update interrupt TIM1溢出中断允许*/
//	TIM1->CR1 |= TIM_CR1_CEN;	/*开启Timer1计数*/
//}


//void TIM1_UP_IRQHandler(void)
//{        
//	//TIM_TimeBaseStructure.TIM_Period = 100-1;//自动重装值（此时进中断的周期为100ms）
//	if (TIM_GetITStatus(TIM1, TIM_IT_Update) != RESET)
//	{  
//		sys_tick++;
//		TIM_ClearITPendingBit(TIM1,TIM_IT_Update);
//	}
//}








































/************************************************************************/

//电阻触摸屏测试
 
//DevEBox  大越创新
//淘宝店铺：mcudev.taobao.com
//淘宝店铺：shop389957290.taobao.com	

/************************************************************************/








