import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    if n%10==2 or n%10==4 or n%10==5 or n%10==7 or n%10==9:
        print("hon")
    elif n%10==0 or n%10==1 or n%10==6 or n%10==8:
        print("pon")
    else:
        print("bon")
if __name__=='__main__':
    main()