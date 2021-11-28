import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    h,w=map(int,input().split())
    for i in range(h):
        s=[_ for _ in input().split()]
        for j in range(w):
            if s[j]=="snuke":
                print(chr(ord('A')+j)+str(i+1))
                sys.exit()

if __name__=='__main__':
    main()