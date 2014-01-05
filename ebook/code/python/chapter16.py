import itertools
if __name__ == "__main__":
    line = raw_input("please input some char:\n")
    for i in itertools.permutations(list(line)):
        print "".join(i)
