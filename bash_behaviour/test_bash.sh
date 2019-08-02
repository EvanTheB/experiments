set -exuo pipefail

echo yes
true
# false

# (false)

[ false ]

echo abc >(false)

echo $(false)

false &

(false &)

(sleep 1 ; true) &
(sleep 2 ; false) &
wait

echo END
