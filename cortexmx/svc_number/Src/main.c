/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include<stdint.h>
#include<stdio.h>

void SVC_Handler_c(uint32_t *);

int main(void)
{
    __asm("SVC #8");

    uint32_t data;

    __asm volatile ("MOV %0,R0": "=r"(data) ::);

    printf("\ndata = %ld\n",data);

	for(;;);
}


__attribute__ ((naked)) void SVC_Handler(void)
{
	__asm("MRS R0, MSP");
	__asm("B SVC_Handler_c");

}

void SVC_Handler_c(uint32_t *pBaseStackFrame)
{
	puts("in SVC_Handler\n");

	uint8_t *pReturnAddress = (uint8_t *)pBaseStackFrame[6];

	pReturnAddress -= 2;

	//*pReturnAddress += 4;

	uint8_t svc_number = *pReturnAddress;

	printf("\nSvc number is %d\n", svc_number);

	svc_number += 4;

	pBaseStackFrame[0] = svc_number;

}



