# mkfifo ff
# python fast.py < ff &
# yes | tee ff | python slow.py
# rm ff


mkfifo ff
python slow.py < ff &
yes | tee ff | python fast.py
rm ff
