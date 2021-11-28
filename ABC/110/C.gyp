import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    t=input()
    s_lis=[[] for _ in range(32)]
    t_lis=[[] for _ in range(32)]
    for i,ss in enumerate(s):
        s_lis[ord(ss)-ord('a')].append(i)
    for i,tt in enumerate(t):
        t_lis[ord(tt)-ord('a')].append(i)
    ss_lis=[sl for sl in s_lis if len(sl)>0]
    tt_lis=[tl for tl in t_lis if len(tl)>0] 
    ss_lis.sort()
    tt_lis.sort()
    if all([True if x==y else False for x,y in zip(ss_lis,tt_lis)]):
        print("Yes")
    else:
        print("No")

if __name__=='__main__':
    main()