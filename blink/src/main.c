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

#define GPIO_SET_OFFSET 16

#define setPinLow(pin) (1 << pin)

#define setPinHigh(pin) (1 << (pin + GPIO_SET_OFFSET))

#define getMode(pin, mode) (mode << (pin * 2))

#define PUSH_PULL 0
#define OPEN_DRAIN 1

#define GPIO_OTYPER_OFFSET 0x0004

#define LOW_SPEED 0
#define MEDIUM_SPEED 1
#define FAST_SPEED 2
#define HIGH_SPEED 3

#define GPIO_OSPEEDR_OFFSET 0x0008

#define NO_PULL 0
#define PULL_UP 1
#define PULL_DOWN 2

#define GPIO_PUPDR_OFFSET 0x000C

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdlib.h>
#include <stdint.h>

/****************************************************************************
 * Public Functions
 ****************************************************************************/

void wait(int time);

/****************************************************************************
 * Name: main
 ****************************************************************************/

int main(int argc, char *argv[])
{

	uint32_t reg;

	uint32_t *pRCC_AHB1ENR = (uint32_t *)(RCC_BASE + RCC_AHB1_OFFSET);

	reg = *pRCC_AHB1ENR;

	reg = (reg | (1 << 2));

	*pRCC_AHB1ENR = reg;

	uint32_t *pGPIOC_MODER = (uint32_t *)(GPIOC_BASE + GPIO_MODER_OFFSET);

	reg = *pGPIOC_MODER;

	reg = (reg | getMode(13, OUTPUT));

	*pGPIOC_MODER = reg;

	uint32_t *pGPIOC_OTYPER = (uint32_t *)(GPIOC_BASE + GPIO_OTYPER_OFFSET);

	reg = *pGPIOC_OTYPER;

	reg = (reg | (PUSH_PULL << 13));

	*pGPIOC_OTYPER = reg;

	uint32_t *pGPIOC_OSPEEDR = (uint32_t *)(GPIOC_BASE + GPIO_OSPEEDR_OFFSET);

	reg = *pGPIOC_OSPEEDR;

	reg = (reg | (LOW_SPEED << 26));

	*pGPIOC_OSPEEDR = reg;

	uint32_t *pGPIOC_SETRESET = (uint32_t *)(GPIOC_BASE + GPIO_SETRESET_OFFSET);

	reg = *pGPIOC_SETRESET;

	int LedDelay = 10000000;

	while (1)
	{
		reg &= setPinHigh(13);
		wait(LedDelay);
		reg &= setPinLow(13);
		wait(LedDelay);
	}

	/* Nao deveria chegar aqui */

	return EXIT_SUCCESS;
}

void wait(int time)
{
	for (int i = 0; i < time; i++)
	{
	}
	return;
}