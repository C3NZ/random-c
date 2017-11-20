#include <stdio.h>
#include <string.h>

int main(){
	char message[14];
	int count, i;

	strcpy(message, "Hello, world!");

	//scanf requires arguments passed by reference
	printf("Repeat how many times? ");
	scanf("%d", &count);

	for(i=0; i < count; i++){
		printf("%3d - %s\n", i, message);
	}
}