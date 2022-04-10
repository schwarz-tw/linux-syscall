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

  str = malloc(200);
  strcpy(str, "0000000000111111111122222222223333333333444444444455555555556666666666777777777788888888889999999999aaaaaaaaaabbbbbbbbbb");
 
  ret = syscall(__NR_mycall, str, 120);
  printf("System call sys_mycall returned %ld\n", ret); 

  return 0;
 
}
