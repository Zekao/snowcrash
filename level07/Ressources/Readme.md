## Level 07

In this exercice, we have a compiled program, with nm and strings we don't have a lot of informations about it.


with ltrace, we can see that the programe will recover an environnement variable called LOGNAME which is set as level07, if we change the value of this variable by getflag, when we execute the level07, it will display getflag because the program just display the logname.
If we add a ; and a new command, technically it will display getflag AND execute our command 

                export LOGNAME="; getflag"

./level07

```Check flag.Here is your token : fiumuikeil55xe9cu4dood66h```