function exit_trap {
    jobs -p | xargs -tr kill || true
}

trap exit_trap EXIT

{
strace -o py -e write stdbuf -eL python3 -c '
import sys
while True:
    print(sys.argv[1], file=sys.stderr)
' aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa \
2> >( strace -o ga -e write stdbuf -oL gawk '{ print strftime("%Y-%m-%dT%H:%M:%S%z - a -"), $0 }' 1>&2 ) &

stdbuf -eL python3 -c '
import sys
while True:
    print(sys.argv[1], file=sys.stderr)
' bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb \
2> >( stdbuf -oL gawk '{ print strftime("%Y-%m-%dT%H:%M:%S%z - b -"), $0 }' 1>&2 ) & 

 } 

sleep 1
