import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    k=int(input())
    len_s=len(s)
    new_s=""
    for i,ss in enumerate(s[:-1]):
        t=ord('z')-ord(ss)+1
        if t<=k and ss!='a':
            k-=t
            new_s+='a'
        else:
            new_s+=ss
    if ord(s[-1])+k%26<=ord('z'):
        new_s+=chr(ord(s[-1])+k%26)
    else:
        new_s+=chr(ord(s[-1])+k%26-26) 
    print(new_s)

if __name__=='__main__':
    main()