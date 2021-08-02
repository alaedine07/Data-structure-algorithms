#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void cutter(void) __attribute__((constructor));
/**
 * cutter - prints a string before execution of main
 * Return: void
 */
void cutter(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
