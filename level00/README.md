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

When we look at the file's content, there is the following text: cdiiddwpgswtgt. After using CyberChef, we can see the text use ROT11 to hide the next password: nottoohardhere

https://gchq.github.io/CyberChef/#recipe=ROT13(true,true,false,11)&input=Y2RpaWRkd3Bnc3d0Z3Q
