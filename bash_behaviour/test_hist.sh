#!/bin/bash

terr () {
    PS=("${PIPESTATUS[@]}"); 
    for (( i = 0 ; i < ${#PS[@]} ; i++ )) ; do 
        echo "${PS[i]}" 
    done 
}

tdbg () { 
    echo DBG "$BASH_COMMAND" 
    BC="$BASH_COMMAND"
}

HISTFILE=""
set -o history

trap terr ERR
trap tdbg DEBUG

true | true
history

false | true
