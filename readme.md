# Steps to adding your syscall to the kernel.

Base directory: `/usr/src/kernels/{uname -r}/source`

1. Find the last syscall number and append your syscall.

In `arch/x86/include/asm/unistd_64.h`:

append

```c
#define __NR_mycall                             307
__SYSCALL(__NR_mycall, sys_mycall)
```

in my case, it's at line 680.

2. Mkdir `mycall` and in `mycall/Makefile`:

```Makefile
obj-y:=mycall.o
```

3. In Makefile (in the base directory), find the line started with `core-y` and append your syscall source code directory.

```Makefile
core-y          += kernel/ mm/ fs/ ipc/ security/ crypto/ block/ mycall/
```

in my case, it's at line 688.

4. Compile the kernel.

- `make config` or `make menuconfig`
- `make`
- `make modules_install`
- `make install`
- `sync && sudo reboot` 

5. Test your syscall.

Sample code (test_call.c):
```c
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
```

- `gcc test_call.c -o test_call`

