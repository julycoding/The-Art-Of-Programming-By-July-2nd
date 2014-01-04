if __name__ == "__main__":
    line = raw_input("please input some char:\n")
    import itertools
    for i in itertools.permutations(list(line)):
        print "".join(i)
