import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    cunt1=0
    cunt2=0
    for ss in s:
        if ss=='1':cunt1+=1
        else:cunt2+=1
    print(min(cunt1,cunt2)*2)

if __name__=='__main__':
    main()