import sys
def input(): return sys.stdin.readline().rstrip()
import bisect
def main():
    s=input()
    t=input()
    s_abc=[]
    for i in range(26):
        s_abc.append([j for j,ss in enumerate(s) if ord(ss)==ord('a')+i])
    cur=-1
    loop=0
    for tt in t:
        tt_num=ord(tt)-ord('a')
        if s_abc[tt_num]==[]:
            print(-1)
            sys.exit()
        next_idx=bisect.bisect(s_abc[tt_num],cur)
        if next_idx==len(s_abc[tt_num]) or s_abc[tt_num][next_idx]<=cur:
            loop+=1
            cur=s_abc[tt_num][0]
        else:
            cur=s_abc[tt_num][next_idx]
    print(len(s)*loop+cur+1)


if __name__=='__main__':
    main()