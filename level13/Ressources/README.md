## Level 13

We can reverse the program with Ghidra and see that the flag is in a function named ft_des.

```c
#include <sys/types.h>

uid_t getuid(void) {
	return 4242;
}
```

```bash
level13@SnowCrash:/tmp$ gcc /tmp/getuid.c -shared -o getuid.so
```

```bash
➜  Documents ./a.out
2A31L79asukciNyi8uppkEuSx
```

```bash
level13@SnowCrash:/tmp$ export LD_PRELOAD=/tmp/getuid.so
```
