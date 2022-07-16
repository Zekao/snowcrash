## Level 08
In this level, we have a level08 file and a token file in our home directory.
When we launch the program with ltrace we see that the program use strstr to avoid token filename.

```bash
level08@SnowCrash:~$ ltrace ./level08 token
__libc_start_main(0x8048554, 2, 0xbffff7d4, 0x80486b0, 0x8048720 <unfinished ...>
strstr("token", "token")                         = "token"
printf("You may not access '%s'\n", "token"You may not access 'token'
)     = 27
exit(1 <unfinished ...>
+++ exited (status 1) +++
```

We only have to do a symbolic link to bypass this restriction

```bash
level08@SnowCrash:~$ ln -s /home/user/level08/token /tmp/link && ./level08 /tmp/link
quif5eloekouj29ke0vouxean
```
