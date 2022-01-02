#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "pwm.h"
#include "key.h"


//ALIENTEK 探索者STM32F407开发板 实验9
//PWM输出实验-库函数版本
//技术支持：www.openedv.com
//淘宝店铺：http://eboard.taobao.com  
//广州市星翼电子科技有限公司  
//作者：正点原子 @ALIENTEK

int main(void)
{ 
//	u16 led0pwmval=0;    
//	u8 dir=1;
	u8 key;           //保存键值
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);  //初始化延时函数
	KEY_Init();  
	uart_init(115200);//初始化串口波特率为115200
 	TIM14_PWM_Init(200-1,8400-1);	//84M/84=1Mhz的计数频率,重装载值500，所以PWM频率为 1M/500=2Khz.     
   while(1) //实现比较值从0-300递增，到300后从300-0递减，循环
	{
		key=KEY_Scan(0);		//得到键值
	   	if(key)
		{						   
			switch(key)
			{				 
				case WKUP_PRES:	//控制蜂鸣器
					TIM_SetCompare1(TIM14,5);
				delay_ms(40);
				//TIM_SetCompare1(TIM14,15);
					break;
				case KEY0_PRES:	//控制LED0翻转
					TIM_SetCompare1(TIM14,10);
				            delay_ms(40);
					break;
				case KEY1_PRES:	//控制LED1翻转	 
					TIM_SetCompare1(TIM14,20);
				delay_ms(20);
					break;
				case KEY2_PRES:	//同时控制LED0,LED1翻转 
					TIM_SetCompare1(TIM14,25);
				delay_ms(20);
//					LED1=!LED1;
					break;
			}
		}else TIM_SetCompare1(TIM14,15);
	}
// 		delay_ms(100);	 
//		TIM_SetCompare1(TIM14,5);	//修改比较值，修改占空比
//		 		delay_ms(100);	 
//		TIM_SetCompare1(TIM14,10);	//修改比较值，修改占空比
//		 		delay_ms(100);	 
//		TIM_SetCompare1(TIM14,15);	//修改比较值，修改占空比
//		 		delay_ms(100);	 
//		TIM_SetCompare1(TIM14,20);	//修改比较值，修改占空比
//		 		delay_ms(100);	 
//		TIM_SetCompare1(TIM14,25);	//修改比较值，修改占空比
//	}
}
