// your code here
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){

	char input[1000];
	char* arr[100];

	arr[0] = "/bin/bash";
	arr[1] = "-c";
	arr[3] = NULL;
	while(1){
		printf("$ Enter your command: ");
		fgets(input, 1000, stdin);
		char *pch = strtok(input, "\n");
		arr[2] = input;

		if(strcmp(pch, "Exit ") == 0){
		break;
		}

		pid_t qwe = fork();
		if (qwe == 0){
			execvp(arr[0], arr);
		}

		waitpid(qwe, NULL,0);
	}
	return 0;

}
