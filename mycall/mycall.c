#include <linux/kernel.h>
asmlinkage long sys_mycall(void)
{
  printk("mycall..\n");
  return 0;
}

