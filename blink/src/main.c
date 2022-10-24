/****************************************************************************
 * main.c
 *
 *   Authors: Rodrigo Henrique Alves Ferreira <rodrigohferreira@ufu.br>
 *
 ****************************************************************************/

/****************/

/**********************************************************	******************
 * Pre-processor Definitions
 ****************************************************************************/

#define RCC_BASE 0x40023800

#define RCC_AHB1_OFFSET 0x30

#define GPIOC_BASE 0x40020800

#define GPIO_MODER_OFFSET 0x00

#define INPUT 0
#define OUTPUT 1
#define ALTERNATE 2
#define ANALOG 3

#define GPIO_SETRESET_OFFSET 0x18

#define GPIO_RESET_OFFSET 16

#define setPinHigh(pin) (1 << pin)

#define setPinLow(pin) (1 << (pin + GPIO_RESET_OFFSET))

#define getMode(pin, mode) (mode << (pin * 2))

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdlib.h>
#include <stdint.h>

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: main
 ****************************************************************************/

void wait(int time)
{
	for (int i = 0; i < time; i++)
	{
	}
	return;
}

int main(int argc, char *argv[])
{

	uint32_t reg;

	uint32_t *pRCC_AHB1ENR = (uint32_t *)RCC_BASE + RCC_AHB1_OFFSET;

	reg = *pRCC_AHB1ENR;

	reg = (reg | (1 << 2));

	uint32_t *pGPIOC_MODER = (uint32_t *)GPIOC_BASE + GPIO_MODER_OFFSET;

	reg = *pGPIOC_MODER;

	reg = (reg | getMode(13, OUTPUT));

	uint32_t *pGPIOC_SETRESET = (uint32_t *)GPIOC_BASE + GPIO_SETRESET_OFFSET;

	reg = *pGPIOC_SETRESET;

	while (1)
	{
		reg = (reg | setPinHigh(13));
		*pGPIOC_SETRESET = reg;
		wait(5000);
		reg = (reg | setPinLow(13));
		*pGPIOC_SETRESET = reg;
		wait(5000);
	}

	/* Nao deveria chegar aqui */

	return EXIT_SUCCESS;
}