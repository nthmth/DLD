/*
 * dig_inouts.h
 */

#ifndef INOUTS_H_
#define INOUTS_H_
#include <stm32f4xx.h>

//INPUTS

#define PING_RCC RCC_AHB1Periph_GPIOE

#define PINGBUT_pin GPIO_Pin_5
#define PINGBUT_GPIO GPIOE
#define PINGBUT (!(PINGBUT_GPIO->IDR & PINGBUT_pin))

#define PINGJACK_pin GPIO_Pin_2
#define PINGJACK_GPIO GPIOE
#define PINGJACK (PINGJACK_GPIO->IDR & PINGJACK_pin)

#define EXTI_PINGJACK_GPIO EXTI_PortSourceGPIOE
#define EXTI_PINGJACK_pin EXTI_PinSource2
#define EXTI_PINGJACK_line EXTI_Line2
#define EXTI_PINGJACK_IRQ EXTI2_IRQn

/*Pin 111, adjacent to PA15/I2S3.WS
#define EXTI_CLOCK_GPIO EXTI_PortSourceGPIOC
#define EXTI_CLOCK_pin EXTI_PinSource10
#define EXTI_CLOCK_line EXTI_Line10
#define EXTI_CLOCK_IRQ EXTI15_10_IRQn
*/
//Same pin as WS clock of I2S2 (LRCLK), as defined in codec.h
#define EXTI_CLOCK_GPIO EXTI_PortSourceGPIOB
#define EXTI_CLOCK_pin EXTI_PinSource12
#define EXTI_CLOCK_line EXTI_Line12
#define EXTI_CLOCK_IRQ EXTI15_10_IRQn


// Infinite Repeat Button and Jack
#define INF_RCC RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOG | RCC_AHB1Periph_GPIOD

#define INF1BUT_pin GPIO_Pin_13
#define INF1BUT_GPIO GPIOD
#define INF1BUT (!(INF1BUT_GPIO->IDR & INF1BUT_pin))

#define INF1JACK_pin GPIO_Pin_7
#define INF1JACK_GPIO GPIOD
#define INF1JACK (!(INF1JACK_GPIO->IDR & INF1JACK_pin))


#define INF2BUT_pin GPIO_Pin_9
#define INF2BUT_GPIO GPIOA
#define INF2BUT (!(INF2BUT_GPIO->IDR & INF2BUT_pin))

#define INF2JACK_pin GPIO_Pin_3
#define INF2JACK_GPIO GPIOG
#define INF2JACK (!(INF2JACK_GPIO->IDR & INF2JACK_pin))


#define REV_RCC RCC_AHB1Periph_GPIOD

#define REV1JACK_pin GPIO_Pin_2
#define REV1JACK_GPIO GPIOD
#define REV1JACK (!(REV1JACK_GPIO->IDR & REV1JACK_pin))

#define REV2JACK_pin GPIO_Pin_3
#define REV2JACK_GPIO GPIOD
#define REV2JACK (!(REV2JACK_GPIO->IDR & REV2JACK_pin))



#define REVSW_RCC RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOG

#define REV1SW_pin GPIO_Pin_10
#define REV1SW_GPIO GPIOG
#define REVSW_CH1 (!(REV1SW_GPIO->IDR & REV1SW_pin))

#define REV2SW_pin GPIO_Pin_1
#define REV2SW_GPIO GPIOA
#define REVSW_CH2 (!(REV2SW_GPIO->IDR & REV2SW_pin))


#define TIMESW_RCC RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOE

#define TIMESW_CH1_T1_pin GPIO_Pin_11
#define TIMESW_CH1_T1_GPIO GPIOG
#define TIMESW_CH1_T2_pin GPIO_Pin_12
#define TIMESW_CH1_T2_GPIO GPIOG
#define TIMESW_CH1 ((TIMESW_CH1_T2_GPIO->IDR & TIMESW_CH1_T2_pin) ? 0b10:0b00) | ((TIMESW_CH1_T1_GPIO->IDR & TIMESW_CH1_T1_pin) ? 0b01:0b00)

#define TIMESW_CH2_T1_pin GPIO_Pin_2
#define TIMESW_CH2_T1_GPIO GPIOA
#define TIMESW_CH2_T2_pin GPIO_Pin_2
#define TIMESW_CH2_T2_GPIO GPIOB
#define TIMESW_CH2 ((TIMESW_CH2_T2_GPIO->IDR & TIMESW_CH2_T2_pin) ? 0b10:0b00) | ((TIMESW_CH2_T1_GPIO->IDR & TIMESW_CH2_T1_pin) ? 0b01:0b00)


#define JUMPER_RCC RCC_AHB1Periph_GPIOG

#define JUMPER_1_GPIO GPIOG
#define JUMPER_1_pin GPIO_Pin_9
#define JUMPER_1 (!(JUMPER_1_GPIO->IDR & JUMPER_1_pin))

#define JUMPER_2_GPIO GPIOG
#define JUMPER_2_pin GPIO_Pin_13
#define JUMPER_2 (!(JUMPER_2_GPIO->IDR & JUMPER_2_pin))

#define JUMPER_3_GPIO GPIOG
#define JUMPER_3_pin GPIO_Pin_14
#define JUMPER_3 (!(JUMPER_3_GPIO->IDR & JUMPER_3_pin))

//OUTPUTS

//CLK OUT
#define CLKOUT_RCC RCC_AHB1Periph_GPIOE | RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOC

#define CLKOUT_pin GPIO_Pin_3
#define CLKOUT_GPIO GPIOE
#define CLKOUT_ON CLKOUT_GPIO->BSRRL = CLKOUT_pin
#define CLKOUT_OFF CLKOUT_GPIO->BSRRH = CLKOUT_pin
#define CLKOUT_TRIG_TIME 960 /*20ms*/

#define CLKOUT1_pin GPIO_Pin_8
#define CLKOUT1_GPIO GPIOC
#define CLKOUT1_ON CLKOUT1_GPIO->BSRRL = CLKOUT1_pin
#define CLKOUT1_OFF CLKOUT1_GPIO->BSRRH = CLKOUT1_pin


//p3 board has this wired to PC9, manually cut and moved to PA5
//should be PC5 in p4
#define CLKOUT2_pin GPIO_Pin_5
#define CLKOUT2_GPIO GPIOC
#define CLKOUT2_ON CLKOUT2_GPIO->BSRRL = CLKOUT2_pin
#define CLKOUT2_OFF CLKOUT2_GPIO->BSRRH = CLKOUT2_pin

//PING Button LED
#define PINGBUTLED_RCC RCC_AHB1Periph_GPIOE

#define LED_PINGBUT_pin GPIO_Pin_4
#define LED_PINGBUT_GPIO GPIOE
#define LED_PINGBUT_ON LED_PINGBUT_GPIO->BSRRL = LED_PINGBUT_pin
#define LED_PINGBUT_OFF LED_PINGBUT_GPIO->BSRRH = LED_PINGBUT_pin

//INF REPEAT Button LED
#define INF1_BUTLED_RCC RCC_AHB1Periph_GPIOD
#define LED_INF1_pin GPIO_Pin_4
#define LED_INF1_GPIO GPIOD
#define LED_INF1_ON LED_INF1_GPIO->BSRRL = LED_INF1_pin
#define LED_INF1_OFF LED_INF1_GPIO->BSRRH = LED_INF1_pin

#define INF2_BUTLED_RCC RCC_AHB1Periph_GPIOA
#define LED_INF2_pin GPIO_Pin_10
#define LED_INF2_GPIO GPIOA
#define LED_INF2_ON LED_INF2_GPIO->BSRRL = LED_INF2_pin
#define LED_INF2_OFF LED_INF2_GPIO->BSRRH = LED_INF2_pin




//OVLD LEDs
#define LED_RCC RCC_AHB1Periph_GPIOA

#define LED_OVLD1 GPIO_Pin_11
#define LED_OVLD2 GPIO_Pin_12
#define LED_GPIO GPIOA
#define LED_OVLD1_ON LED_GPIO->BSRRL = LED_OVLD1
#define LED_OVLD1_OFF LED_GPIO->BSRRH = LED_OVLD1
#define LED_OVLD2_ON LED_GPIO->BSRRL = LED_OVLD2
#define LED_OVLD2_OFF LED_GPIO->BSRRH = LED_OVLD2

//DEBUG pins
#define DEBUG_RCC RCC_AHB1Periph_GPIOA

#define DEBUG0 GPIO_Pin_4
#define DEBUG0_GPIO GPIOA
#define DEBUG0_ON DEBUG0_GPIO->BSRRL = DEBUG0
#define DEBUG0_OFF DEBUG0_GPIO->BSRRH = DEBUG0

void init_dig_inouts(void);
void update_ping_ledbut(void);
void init_EXTI_inputs(void);
void update_channel_leds(uint8_t channel);
void update_inf_ledbut(uint8_t channel);
inline void update_instant_params(uint8_t channel);
void init_inputread_timer(void);


#endif /* INOUTS_H_ */
