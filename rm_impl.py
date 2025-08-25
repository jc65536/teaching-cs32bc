import shutil
import sys


def rm_impl(path: str):
    with open(path) as inp, open(path + ".working", "w") as out:
        rm_section = False
        for line in inp:
            if rm_section:
                if "RM_END" in line:
                    rm_section = False
            else:
                if "RM_START" in line:
                    rm_section = True
                else:
                    out.write(line)

    shutil.move(path, path + ".orig")
    shutil.move(path + ".working", path)


for path in sys.argv[1:]:
    rm_impl(path)
