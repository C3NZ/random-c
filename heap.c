#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	
	char *char_ptr;
	int *int_ptr;
	int mem_size;


	if (argc < 2)
		mem_size = 50;
	else
		mem_size = atoi(argv[1]);

	//if no args are provided by the user allocate 50 bytes of memory, otherwise
	//allocate the memory specified by the user
	printf("\t[+] allocating %d bytes of memory on the heap for char_ptr\n", mem_size);
	char_ptr = (char *) malloc(mem_size);

	//Check to see if malloc failed for char_ptr
	if(char_ptr == NULL){
		fprintf(stderr, "Error: could not allocate heap memory.\n");
		exit(-1);
	}

	//store chars into char_ptr
	strcpy(char_ptr, "This is memory located on the heap.");
	printf("char_ptr (%p) --> '%s'\n", char_ptr, char_ptr);

	//allocate 12 bytes of memory for int_ptr
	printf("\t[+] allocating 12 bytes of memory on the heap for int_ptr\n");
	int_ptr = (int *) malloc(12);

	//Check to see if malloc didn't fail for int_ptr
	if(int_ptr == NULL){
		fprintf(stderr, "Error: could not allocate heap memory.\n");
		exit(-1);
	}

	*int_ptr = 31337;
	printf("int_ptr (%p) --> %d\n", int_ptr, *int_ptr);

	//Free char_ptr from memory
	printf("\t[-] freeing char_ptr's heap memory...\n");
	free(char_ptr);

	//allocate 15 bytes for char_ptr
	printf("\t[+]allocating another 15 bytes for char_ptr\n");
	char_ptr = (char *) malloc(15);

	//Check to see if malloc didn't fail for char_ptr
	if(char_ptr == NULL){
		fprintf(stderr, "Error: could not allocate heap memory");
		exit(-1);
	}

	//store chars into char_ptr
	strcpy(char_ptr, "new memory");
	printf("char_ptr (%p) --> '%s'\n", char_ptr, char_ptr);

	//Free all memory after the program is done executing
	printf("\t[-] freeing int_ptr's heap memory...\n");
	free(int_ptr);
	printf("\t[-] freeing char_ptr's heap memory...\n");
	free(char_ptr);


}