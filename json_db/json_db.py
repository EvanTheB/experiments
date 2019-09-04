from contextlib import contextmanager
import os
import json
import shutil


@contextmanager
def json_db(fname, factory=dict):
    class JsonDBError(Exception): pass
    crash_name = fname + '.crash'
    if os.path.exists(crash_name):
        raise JsonDBError(f"There has been a crash, reconcile {crash_name}")
    if os.path.exists(fname):
        with open(fname) as f:
            data = json.load(f)
    else:
        data = factory()
    try:
        yield data
    except BaseException as e:
        to_write = json.dumps(data)
        if os.path.exists(crash_name):
            shutil.move(crash_name, crash_name + '.bak')
        with open(crash_name, 'w') as f:
            f.write(to_write)
        raise e
    else:
        if os.path.exists(fname):
            shutil.move(fname, fname + '.bak')
        # need 2 steps here so failure to serialise
        # doesnt truncate the file
        to_write = json.dumps(data)
        with open(fname, 'w') as f:
            f.write(to_write)

def main():
    import random
    import time
    with json_db('json_db.json', factory=lambda: {'abc':'def'}) as d:
        d[random.random()] = random.random()
        # raise Exception



if __name__ == '__main__':
    main()
