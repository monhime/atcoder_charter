import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s = input()
    t = input()
    cunt=0
    for i, ss in enumerate(s):
        if ss != t[i]:
            cunt+=1
    print(cunt)

if __name__=='__main__':
    main()