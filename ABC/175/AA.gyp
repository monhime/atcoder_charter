import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    S = input()
    if S == "RRR":
        print(3)
    elif ((S[0] != 'R') ^ (S[2] != 'R')) and S[1]=='R':
        print(2)
    elif S == "SSS":
        print(0)
    else:
        print(1)

if __name__=='__main__':
    main()