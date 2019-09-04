set -euo pipefail
set -x

mv /tmp/cipher.csv{,.old} || true

echo cipher,elapsed,%cpu > /tmp/cipher.csv

for cipher in aes128-ctr aes256-ctr aes128-cbc aes256-cbc 3des-cbc ; do
    for i in 1 ; do
        echo
        echo "cipher: $cipher (try $i)"
         
        dd if=/dev/zero bs=8M count=1000 2>/tmp/dd.txt | pv --size 8g | env time -o /tmp/pcpu -f %p ./dbclient -i ~/.ssh/id_dropbear -c "$cipher" ${1} 'env time -o /tmp/ebtime -f %e cat > /dev/null; cat /tmp/ebtime' > /tmp/elaps
        grep -v records /tmp/dd.txt
        echo db-$cipher,$(cat /tmp/elaps),$(tr -d '%'  < /tmp/pcpu) | tee -a /tmp/cipher.csv
    done
done

# for cipher in $(ssh -Q cipher) ; do
for cipher in $(ssh -vv ${1} exit 2>&1 | grep -i kex_parse_kexinit | grep aes | head -1 | cut -d: -f3- | tr ',' ' ') ; do
    for i in 1 ; do
        echo
        echo "cipher: $cipher (try $i)"
         
        dd if=/dev/zero bs=8M count=1000 2>/tmp/dd.txt | pv --size 8g | env time -o /tmp/pcpu -f %p ssh -x -c "$cipher" ${1} 'env time -o /tmp/ebtime -f %e cat > /dev/null; cat /tmp/ebtime' > /tmp/elaps
        grep -v records /tmp/dd.txt
        echo $cipher,$(cat /tmp/elaps),$(tr -d '%'  < /tmp/pcpu) | tee -a /tmp/cipher.csv
    done
done

graph --bar /tmp/cipher.csv --ycol 2
graph --bar /tmp/cipher.csv --ycol 3

