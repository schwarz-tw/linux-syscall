#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#define __NR_mycall 307
#include <string.h>
#include <stdlib.h>
int main(int argc,char **argv)
{
  char *str = malloc(20);
  strcpy(str, "123456");
  long int ret;
  
  ret = syscall(__NR_mycall, str, 6);
  printf("System call sys_mycall returned %ld\n", ret); 

  return 0;
 
}
