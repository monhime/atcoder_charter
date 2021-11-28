import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    if len(s)%2==1:
        print("No")
        sys.exit()
    for i in range(len(s)//2):
        if s[2*i:2*i+2]!="hi":
            print("No")
            break
    else:print("Yes")

if __name__=='__main__':
    main()