#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

//Describe the program usage if not enough args are provided
void usage(char *prog_name, char *filename){
	printf("Usage: %s <data to add to %s>\n", prog_name, filename);
	exit(0);
}

//Function declarations on top
void fatal(char *);
void *ec_malloc(unsigned int);

int main(int argc, char *argv[]){
	int descriptor;
	char *buffer, *datafile;

	//Allocate 100 bytes, and 20 bytes of memory for both char pointers
	buffer = (char *) ec_malloc(100);
	datafile = (char *) ec_malloc(20);

	strcpy(datafile, "notes");

	if (argc < 2)
		usage(argv[0], datafile);
	
	strcpy(buffer, argv[1]);

	printf("[DEBUG] bugger @ %p \'%s\'\n", buffer, buffer);
	printf("[DEBUG] datafile @ %p \'%s\'\n", datafile, datafile);

	//Add an escape character 
	strncat(buffer, "\n", 1);

	//open takes the a char pointer describing the location of the file to open
	//Takes in flags (bits) as other arguments denoting what mode to open the file in,
	//and what permissions to open/create it with
	descriptor = open(datafile, O_WRONLY|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR);

	if(descriptor == -1)
		fatal("In main() while opening file");
	
	printf("[DEBUG] file descriptor is %d\n", descriptor);

	//write takes the file descriptor, the buffer to write
	//, and the length of the buffer to know how many bytes to write.
	if(write(descriptor, buffer, strlen(buffer)) == -1)
		fatal("in main() while writing buffer to the file");

	//Close the file out
	if(close(descriptor) == -1)
		fatal("in main() while closing file");

	//Free both the buffer and datafile char pointers
	free(buffer);
	free(datafile);
}

//Prints an error and then exits the program in the event of
//something going fatally wrong.
void fatal(char *message){
	char error_message[100];

	strcpy(error_message, "[!!] Fatal Error ");
	strncat(error_message, message, 83);
	perror(error_message);
	exit(-1);
}

//Error checked malloc() wrapper
void *ec_malloc(unsigned int size){
	void *ptr;
	ptr = malloc(size);

	if(ptr == NULL){
		fatal("in ec_malloc() on memory allocation");
	}
	return ptr;
}