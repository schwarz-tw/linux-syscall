#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#define __NR_mycall 307
#include <string.h>
#include <stdlib.h>
int main(int argc,char **argv)
{
 
  long int ret;
  ret = syscall(__NR_mycall);
 
  return 0;
 
}
