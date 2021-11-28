import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    for i in range(len(s)//2):
        if s[i]!=s[-1-i]:
            print("NO")
            break
    else:print("YES")

if __name__=='__main__':
    main()