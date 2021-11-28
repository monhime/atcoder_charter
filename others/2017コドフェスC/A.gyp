import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    for i in range(len(s)-1):
        if s[i:i+2]=="AC":
            print("Yes")
            break
    else:print("No")

if __name__=='__main__':
    main()