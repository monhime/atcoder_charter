import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    T = input()
    len_t = len(T)
    S = ""
    for t in T:
        if t == "?":
            S += "D"
        else:
            S += t
    print(S)


if __name__=='__main__':
    main()