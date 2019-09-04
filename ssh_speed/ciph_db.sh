#!/bin/env bash
set -euo pipefail
set -x

COUNT=100

mv cipher.csv{,.old} || true

echo 'cipher,elapsed,%cpu' > cipher.csv

# not working raw tcp attempt
#dd if=/dev/zero bs=8M count="$COUNT" | env time -o pcpu -f '%P' nc -l 8858 &
#sleep 1
#ssh evaben@dice02 'env time -f %e nc 129.94.14.74 8858 > /dev/null < /dev/null' 2> /tmp/elaps
# echo netcat,$(cat /tmp/elaps),$(tr -d '%'  < /tmp/pcpu) | tee -a /tmp/cipher.csv

# can't find reliable way to get available ciphers

# nmap --script ssh2-enum-algos -sV -p <port> <host>
# for cipher in aes128-ctr aes192-ctr aes256-ctr arcfour256 arcfour128 aes128-cbc 3des-cbc blowfish-cbc cast128-cbc aes192-cbc aes256-cbc arcfour rijndael-cbc@lysator.liu.se ; do
# for cipher in $(ssh -vv ${1} exit 2>&1 | grep -i kex_parse_kexinit | grep aes | head -1 | cut -d: -f3- | tr ',' ' ') ; do
for cipher in $(ssh -Q cipher | cat - serv | sort | uniq -d) ; do
    for i in 1 ; do
        echo
        echo "Cipher: $cipher (try $i)"
         
        dd if=/dev/zero bs=8M count="$COUNT" 2>dd.txt | pv --size "${COUNT}"M | env time -o pcpu -f '%P' ssh -c "$cipher" ${1} 'env time -f %e cat > /dev/null' 2> elaps
        grep -v records /tmp/dd.txt
        echo $cipher,$(cat elaps),$(tr -d '%' < pcpu) | tee -a cipher.csv
    done
done

for cipher in aes128-ctr aes256-ctr aes128-cbc aes256-cbc twofish256-cbc twofish-cbc twofish128-cbc 3des-ctr 3des-cbc ; do
    for i in 1 ; do
        echo
        echo "Cipher: $cipher (try $i)"
         
        dd if=/dev/zero bs=8M count="$COUNT" 2>dd.txt | pv --size "${COUNT}"M | env time -o pcpu -f %P dbclient -c "$cipher" ${1} 'env time -f %e cat > /dev/null' 2> elaps
        grep -v records dd.txt
        echo db-$cipher,$(cat elaps),$(tr -d '%'  < pcpu) | tee -a cipher.csv
    done
done
