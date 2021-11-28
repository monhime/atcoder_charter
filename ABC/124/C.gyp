import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    cunt1=0
    for i,ss in enumerate(s):
        if int(ss)==i%2:cunt1+=1
    cunt2=0
    for i,ss in enumerate(s):
        if int(ss)!=i%2:cunt2+=1   
    print(min(cunt1,cunt2))

if __name__=='__main__':
    main()