We have a level02.pcap file in this level.

To use this type of file, we have to install Wireshark

We will open the level02.pcap file with wireshark, after checking few frames, we see that the frame 43 have 
```Pas sword:``` on it so i've made an analyze of TCP stream
-> Analyze -> Follow -> TCP Stream
    ```Password: ft_wandr...NDRel.L0L```
We have to understand what . means in the paasword
. stands for a non printable character, after searching in few packages, we can see that some of them finish with 7f and in the ascii table, 7f stands for DEL
so we have to replace all . by a DEL
    ```Password: ft_waNDReL0L```
    
Check flag.Here is your token : kooda2puivaav1idi4f57q8iq
