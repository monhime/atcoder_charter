import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    w=int(input())
    ss=""
    for i in range(-(-len(s)//w)):
        ss+=s[w*i]
    print(ss)

if __name__=='__main__':
    main()