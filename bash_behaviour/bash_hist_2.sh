# try to clean background processes on failure
# do not know if this works.
function exit_trap {
    jobs -p | xargs -tr kill || true
}

function err_trap {
    PS=("${PIPESTATUS[@]}")
    echo BASH_ERROR: "${PS[@]}" 1>&2
    echo BASH_ERROR: "$(caller)" 1>&2
}

trap err_trap ERR
trap exit_trap EXIT

sleep 5 &

true | true

# echo 123 \
# | false \
# | true

exit 1
