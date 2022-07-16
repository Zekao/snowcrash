## Level 08

In this level we have 2 files, an executable level08 and a token that we're not able to read

ls -l

        -rwsr-s---+ 1 flag08 level08 8617 Mar  5  2016 level08
        -rw-------  1 flag08 flag08    26 Mar  5  2016 token

When we use ltrace, we can see that the program will do an strstr with ouf file and "token"

        ltrace ./level08 token 
        __libc_start_main(0x8048554, 2, 0xbffff7d4, 0x80486b0, 0x8048720 <unfinished ...>
        strstr("token", "token")                                                              = "token"
        printf("You may not access '%s'\n", "token"You may not access 'token'
        )

We can do a shortcut for our file in another path to bypass the strstr and be able to read the flag

ln -s /home/user/level08/token /tmp/pass

./level08 /tmp/pass

        quif5eloekouj29ke0vouxean

su flag08 -> quif5eloekouj29ke0vouxean
getflag

                           Check flag.Here is your token : 25749xKZ8L7DkSCwJkT9dyv6f
