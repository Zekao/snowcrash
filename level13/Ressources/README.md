## Level 13


# First method
In this level, we have two different ways to get the flag:

The program will check the UID of the user, and if it is the same as the one in the flag, it will print the flag.
The first way is to replace the getuid function called in the program with your own that will return 4242

```c
#include <sys/types.h>

uid_t getuid(void) {
	return 4242;
}
```

```bash
level13@SnowCrash:~$ cd /tmp
level13@SnowCrash:/tmp$ gcc /tmp/getuid.c -shared -o getuid.so
```

```bash
level13@SnowCrash:/tmp$ export LD_PRELOAD=/tmp/getuid.so
```

```bash
level13@SnowCrash:~$ cd ~
level13@SnowCrash:~$ ltrace ./level13
__libc_start_main(0x804858c, 1, 0xbffff7d4, 0x80485f0, 0x8048660 <unfinished ...>
getuid()                                         = 4242
strdup("boe]!ai0FB@.:|L6l@A?>qJ}I")              = 0x0804b008
printf("your token is %s\n", "2A31L79asukciNyi8uppkEuSx"your token is 2A31L79asukciNyi8uppkEuSx
) = 40
+++ exited (status 40) +++
```

# Second method


We can reverse the program with Ghidra and see that the flag is in a function named ft_des.

```bash
➜  Documents ./a.out
2A31L79asukciNyi8uppkEuSx
```

