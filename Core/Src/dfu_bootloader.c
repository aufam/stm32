#include "tim.h"
#include "FreeRTOS.h"

// bootloader for DFU
#if defined(STM32F3)
#define BOOT_ADDR	0x1FFFD800
#endif

#if defined(STM32F4) || defined(STM32F2)
#define BOOT_ADDR	0x1FFF0000
#endif

#if defined(STM32F7)
#define BOOT_ADDR	0x1FF00000
#endif

struct boot_vectable_ {
    uint32_t Initial_SP;
    void (*Reset_Handler)(void);
};

#define TIM_TICK    TIM11
#define BOOTVTAB	((volatile struct boot_vectable_ *)BOOT_ADDR)

void dfu_bootloader(void) {
    // remap memory ?
	SYSCFG->MEMRMP = 0x01;

	// disable interrupts
	__disable_irq();

	// disable systick tim base
	#ifdef TIM_TICK
	if ((TIM_TICK->CCER & (TIM_CCER_CCxE_MASK | TIM_CCER_CCxNE_MASK)) == 0UL)
		TIM_TICK->CR1 &= ~(TIM_CR1_CEN); 
	
	TIM_TICK->DIER &= ~TIM_IT_UPDATE;
	#endif

	SysTick->CTRL = 0;

	// deinit clock
	HAL_RCC_DeInit();

	// clear interrupt enable register and pending register
    for (uint16_t i = 0; i < sizeof(NVIC->ICER) / sizeof(NVIC->ICER[0]); i++) {
		NVIC->ICER[i] = 0xFFFFFFFF;
		NVIC->ICPR[i] = 0xFFFFFFFF;
    }

	// reenable interrupt (?)
	__enable_irq();

	// set the stack pointer
	__set_MSP(BOOTVTAB->Initial_SP);

	// jump to bootloader
	BOOTVTAB->Reset_Handler();
}
