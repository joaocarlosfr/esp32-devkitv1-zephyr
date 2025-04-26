/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc. 
 *
 * Modified by joaocarlosfr in 2025.
 * 
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>

int main(void)
{
	printf("Hello World, board was successful compiled! Lets see some details...\n");
	printf("Board compiled: %s\n", CONFIG_BOARD_TARGET);
	printf("Architecture: %s\n", CONFIG_ARCH);
	printf("Ending code execution and returning 0, bye!\n");
	return 0;
}
