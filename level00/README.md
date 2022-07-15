## Level 00

We can see with the following command two files where the owner is flag00.

```bash
find / -user flag00 2> /dev/null
```

After checking with ls -l, we can see we only have read access on them.

```bash
level00@SnowCrash:~$ find / -user flag00 2> /dev/null
/usr/sbin/john
/rofs/usr/sbin/john
```

```bash
level00@SnowCrash:~$ ls -l /usr/sbin/john /rofs/usr/sbin/john
----r--r-- 1 flag00 flag00 15 Mar  5  2016 /rofs/usr/sbin/john
----r--r-- 1 flag00 flag00 15 Mar  5  2016 /usr/sbin/john
```

When we look at the file's content, there is the following text: cdiiddwpgswtgt.

```bash
level00@SnowCrash:~$ cat /usr/sbin/john
cdiiddwpgswtgt
```

After using CyberChef, we can see the text use ROT11 to hide the next password: nottoohardhere

https://gchq.github.io/CyberChef/#recipe=ROT13(true,true,false,11)&input=Y2RpaWRkd3Bnc3d0Z3Q
