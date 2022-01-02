#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "pwm.h"
#include "key.h"


//ALIENTEK ̽����STM32F407������ ʵ��9
//PWM���ʵ��-�⺯���汾
//����֧�֣�www.openedv.com
//�Ա����̣�http://eboard.taobao.com  
//������������ӿƼ����޹�˾  
//���ߣ�����ԭ�� @ALIENTEK

int main(void)
{ 
//	u16 led0pwmval=0;    
//	u8 dir=1;
	u8 key;           //�����ֵ
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);  //��ʼ����ʱ����
	KEY_Init();  
	uart_init(115200);//��ʼ�����ڲ�����Ϊ115200
 	TIM14_PWM_Init(200-1,8400-1);	//84M/84=1Mhz�ļ���Ƶ��,��װ��ֵ500������PWMƵ��Ϊ 1M/500=2Khz.     
   while(1) //ʵ�ֱȽ�ֵ��0-300��������300���300-0�ݼ���ѭ��
	{
		key=KEY_Scan(0);		//�õ���ֵ
	   	if(key)
		{						   
			switch(key)
			{				 
				case WKUP_PRES:	//���Ʒ�����
					TIM_SetCompare1(TIM14,5);
				delay_ms(40);
				//TIM_SetCompare1(TIM14,15);
					break;
				case KEY0_PRES:	//����LED0��ת
					TIM_SetCompare1(TIM14,10);
				            delay_ms(40);
					break;
				case KEY1_PRES:	//����LED1��ת	 
					TIM_SetCompare1(TIM14,20);
				delay_ms(20);
					break;
				case KEY2_PRES:	//ͬʱ����LED0,LED1��ת 
					TIM_SetCompare1(TIM14,25);
				delay_ms(20);
//					LED1=!LED1;
					break;
			}
		}else TIM_SetCompare1(TIM14,15);
	}
// 		delay_ms(100);	 
//		TIM_SetCompare1(TIM14,5);	//�޸ıȽ�ֵ���޸�ռ�ձ�
//		 		delay_ms(100);	 
//		TIM_SetCompare1(TIM14,10);	//�޸ıȽ�ֵ���޸�ռ�ձ�
//		 		delay_ms(100);	 
//		TIM_SetCompare1(TIM14,15);	//�޸ıȽ�ֵ���޸�ռ�ձ�
//		 		delay_ms(100);	 
//		TIM_SetCompare1(TIM14,20);	//�޸ıȽ�ֵ���޸�ռ�ձ�
//		 		delay_ms(100);	 
//		TIM_SetCompare1(TIM14,25);	//�޸ıȽ�ֵ���޸�ռ�ձ�
//	}
}
