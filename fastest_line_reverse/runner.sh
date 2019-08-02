#!/bin/bash
t() { 
    echo -n $1 $2 " "
    yes $3 | head -1000000 | env time -v $1 $2 2>&1 1> /dev/null | grep Elapsed 
}
for ll in 5 50 500; do
    str=$(for (( i = 0; i < $ll; i++ )); do echo -n a; done)
    # echo $str
    for tr in 1 5 50; do
        t "bash sed.sh" $tr $str
        t "bash rev.sh" $tr $str
        t "python3 rtrim2.py" $tr $str
        t "bash c.sh" $tr $str
    done
done
