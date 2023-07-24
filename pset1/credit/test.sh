#!/bin/bash

second() {
    echo $2
}
while read l; do
   echo "$l"
   cc=$(second $l)
   ./credit "$cc"
done < ./cards.txt
