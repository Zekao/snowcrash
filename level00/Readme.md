                                            find -O3 / -user "flag00" 2>/dev/null

First of all, we have to find created by a user called flag00
-> https://www.plesk.com/blog/various/find-files-in-linux-via-command-line/
so basically you have to use find but with specific flags such as -O3
    -> O3 – Allow find to automatically re-order the search based on efficient use of resources and likelihood of success after
    -> -user to check files from a user with a specific name
    -> 2>/dev/null to move all garbages error commands to the /dev/null
now, we have some folders, /usr/sbin/john and /rofs/usr/sbin/johh, both contains a text
    -> cdiiddwpgswtgt
After, i've called by best friendo called google chrome and went to dcode, entered the flag and it said me that is was cesar code.
So, i've trusted him and he said me nottoohardhere

su flag00 -> password : nottoohardhere

getflag
Check flag.Here is your token : -   x24ti5gi3x0ol2eh4esiuxias
