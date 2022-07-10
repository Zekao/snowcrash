                                cat /etc/passwd
                                cat /etc/passwd | grep flag01
This time, there is no file of the user flag01, in /etc/passwd you can see a lot of level and flag and there is something for the flag01 which is not an ```x```
like others lines, we can see written ```42hDRfypTqqnw```
It's an hashed password but we're not able to decode it with stuff like dcode.
How are we supposed to get it? With a magic tool called

                                John the Ripper.

What is John? This website with explain it better than me https://linuxhint.com/john_ripper_ubuntu/
so basically we have to enter the token that we got to john
echo  42hDRfypTqqnw > tmp
john tmp

```Loaded 1 password hash (descrypt, traditional crypt(3) [DES 128/128 SSE2-16])```
```Will run 4 OpenMP threads```
```Press 'q' or Ctrl-C to abort, almost any other key for status```
```abcdefg          (?)```
```1g 0:00:00:00 100% 2/3 100.0g/s 1638Kp/s 1638Kc/s 1638KC/s 123456..betabeta```
```Use the "--show" option to display all of the cracked passwords reliably```
```Session completed```

john tmp --show

```?:abcdefg```

su flag00 -> password : abcdefg

getflag
Check flag.Here is your token : -   f2av5il02puano7naaf6adaaf