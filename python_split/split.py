def do(s, sep='_'):
    print(repr(s), s.split(sep))

for s in ['', '_', 'a', 'a_b', 'a_', '_b', 'a__b', 'a__']:
    do(s)
