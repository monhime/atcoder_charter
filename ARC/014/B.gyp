import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    W=[]
    s=input()
    W.append(s)
    for i in range(n-1):
        s=input()
        if (s in W) or W[i][-1]!=s[0]:
            if i%2==0:
                print("WIN")
                break
            else:
                print("LOSE")
                break
        W.append(s)
    else:
        print("DRAW")
        
        
if __name__=='__main__':
    main()