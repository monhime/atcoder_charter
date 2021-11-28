import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    k=int(input())
    for i in range(min(100,k)):
        if s[i]!='1':
            print(s[i])
            break
    else:print(1)

if __name__=='__main__':
    main()