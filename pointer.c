#include <stdio.h>
#include <string.h>

int main() {
	char str_a[20];
	char *pointer;
	char *pointer2;

	//Set pointer one to the beginning of the char array
	strcpy(str_a, "Hello, world!\n");
	pointer = str_a;
	printf(pointer);

	//set pointer2 two bytes further than the first pointer
	pointer2 = pointer + 2;
	printf(pointer2);
	strcpy(pointer2, "y you guys!\n");
	printf(pointer);
}