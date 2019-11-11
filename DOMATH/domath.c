// your code here
#include <stdio.h>

#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdlib.h>

int main(int argc, char** argv){
	if (argc<3) {
		printf("Too few args.\n");
		exit(1);
	}

	pid_t forth = fork();
	if(forth == 0){
		int x = atoi(argv[1]);
		int y = atoi(argv[2]);
		printf("child4: %d / %d = %d\n",x,y,x/y);
		exit(0);}

	pid_t third = fork();
	if(third == 0){
		int x = atoi(argv[1]);
		int y = atoi(argv[2]);
		printf("child3: %d * %d = %d\n",x,y,x*y);
		exit(0);}

	pid_t second = fork();
	if(second == 0){
		int x = atoi(argv[1]);
		int y = atoi(argv[2]);
		printf("child2: %d - %d = %d\n",x,y,x-y);
		exit(0);}

	pid_t first = fork();
	if(first == 0){
		int x = atoi(argv[1]);
		int y = atoi(argv[2]);
		printf("child1: %d + %d = %d\n",x,y,x+y);
		exit(0);}

	
	waitpid(first, NULL, 0);
  waitpid(second, NULL, 0);
  waitpid(third, NULL, 0);
  waitpid(forth, NULL, 0);

	printf("parent: done.\n");
}
