import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    dic=dict()
    dic["S"],dic["H"],dic["D"],dic["C"]=0,0,0,0
    i=0
    while True:
        ss=s[i]
        s_num=s[i+1]
        if s_num in ["A","J","1","Q","K"]:
            dic[ss]+=1
            i+=2
            if s_num=="1":
                i+=1
            if dic[ss]==5:
                break
        else:
            i+=2
    ans=""
    i=0
    while True:
        ssx=s[i]
        s_numx=s[i+1]
        if s_numx in ["A","J","1","Q","K"]:
            if ssx!=ss:
                ans+=ssx+s_numx
                if s_numx=="1":
                    ans+=s[i+2]
            i+=2
            if s_numx=="1":
                i+=1
            if ssx==ss and s_numx==s_num:
                break
        else:
            ans+=ssx+s_numx
            i+=2
    if ans=="":
        print(0)
    else:
        print(ans)

if __name__=='__main__':
    main()