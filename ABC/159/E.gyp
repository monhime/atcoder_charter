import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    h,w,k=map(int,input().split())
    S=[input() for _ in range(h)]
    final_ans=10**10
    for row_lis in range(1<<(h-1)):
        lst=[0]*h
        q,ans=0,0
        for r in range(h-1):
            if (row_lis>>r)&1==0:
                lst[r+1]=q
            else:
                q+=1
                lst[r+1]=q
                ans+=1
        data=[0]*h
        for j in range(w):
            for i in range(h):
                data[lst[i]]+=int(S[i][j])
                if data[lst[i]]>k:
                    ans+=1
                    break
            else:
                continue
            data=[0]*h
            for i in range(h):
                data[lst[i]]+=int(S[i][j])
                if data[lst[i]]>k:
                    break
            else:
                continue
            break
        else:
            final_ans=min(final_ans,ans)
    print(final_ans)


if __name__=='__main__':
    main()