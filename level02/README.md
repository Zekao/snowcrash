## Level 02
When we are logged as level02, we can see level02.pcap file in our home directory.

```bash
level02@SnowCrash:~$ ls -l
total 12
----r--r-- 1 flag02 level02 8302 Aug 30  2015 level02.pcap
```

So, we can use the following command to export level02.pcap file into our computer:

```bash
➜ scp -P 4242 level02@192.168.56.101:~/level02.pcap ~/Desktop
```
When we try to open it, we can see that we didn't have permission; we can run the following command to open it:

```bash
➜  Desktop chmod 666 level02.pcap
➜  Desktop ls -l level02.pcap
-rw-rw-rw- 1 nabentay 2021_paris 8302 Jul 15 22:19 level02.pcap
```

We can use tshark to follow the TCP stream of the packet send and received:

```bash
tshark -q -r level02/level02.pcap -z follow,tcp,hex,0
...
       000000D6  00 0d 0a 50 61 73 73 77  6f 72 64 3a 20           ...Passw ord:
000000B9  66                                                f
000000BA  74                                                t
000000BB  5f                                                _
000000BC  77                                                w
000000BD  61                                                a
000000BE  6e                                                n
000000BF  64                                                d
000000C0  72                                                r
000000C1  7f                                                .
000000C2  7f                                                .
000000C3  7f                                                .
000000C4  4e                                                N
000000C5  44                                                D
000000C6  52                                                R
000000C7  65                                                e
000000C8  6c                                                l
000000C9  7f                                                .
000000CA  4c                                                L
000000CB  30                                                0
000000CC  4c                                                L
000000CD  0d                                                .
...
```

After this, we can see that the password contains DEL key press (7f). When we remove all the deleted letters, we get: <mark>ft_waNDReL0L</mark>

