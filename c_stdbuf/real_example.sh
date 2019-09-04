function exit_trap {
    #jobs -p | xargs -tr kill || true
    kill -- -$$ 
}

trap exit_trap EXIT

function timestamper {
    # if no gawk see https://serverfault.com/a/814095/488147
    # need line buf to merge streams nicely, should be more responsive too
    exec stdbuf -oL gawk '{ print strftime("%Y-%m-%dT%H:%M:%S%z - '"$1"' -"), $0 }'
}

function cmd_wrapper() {
    # first arg is a name, rest is a command
    local name
    name="$1"
    shift
    # stderr is fully buffered, this is probably OK
    exec env time -v -o "$name".time "$@" 2> >(timestamper "$name" 1>&2)
    #strace -o "$name.strace" -e write "$@" 
}


cmd_wrapper a ./err_writer aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa &
cmd_wrapper b ./err_writer bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb &

sleep 1
ps -j f
