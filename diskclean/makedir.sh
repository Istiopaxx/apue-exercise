#!/bin/bash

fakename=$1
startdir=$2
function makedir {
    mkdir "dir${fakename}"
    touch "file${fakename}1"
    touch "file${fakename}2"
    touch "file${fakename}3"
    cd "dir${fakename}"
}

cd $startdir
makedir
makedir
makedir
makedir
makedir
