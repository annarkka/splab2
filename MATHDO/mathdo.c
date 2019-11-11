#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
int main(int argc, char *argv[]){

	int forth = fork();
	if (forth == 0) {
		execlp("bash", "bash", "multiply.sh", argv[1], argv[2], NULL);
		exit(0);} 

    	int third = fork();
	if (third == 0) {
		execlp("nodejs", "nodejs", "minus.js", argv[1], argv[2], NULL);
		exit(0);}
	
	int second = fork();
	if (second == 0) {
		execlp("java", "java", "divide", argv[1], argv[2], NULL);
		exit(0);} 
  
	int first = fork();
	if (first == 0) {
		execlp("python", "python3", "add.py", argv[1], argv[2], NULL);
		exit(0);}    
	
	  
    	waitpid(first, NULL, 0);
    	waitpid(second, NULL, 0);
    	waitpid(third, NULL, 0);
    	waitpid(forth, NULL, 0);
	printf("parent: done.\n");
	

	//5
    //24 25 26 


}
