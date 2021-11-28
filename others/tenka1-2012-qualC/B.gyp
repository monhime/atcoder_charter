import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    S,H,D,C=[],[],[],[]
    i=0
    cunt=0
    flag=""
    while i<len(s):
        if s[i]=="S":
            if s[i+1]=="1" and not("10" in S):
                S.append("10")
                i+=3
            elif (s[i+1]=="J" or s[i+1]=="Q" or s[i+1]=="K" or s[i+1]=="A") and (not s[i+1] in S):
                S.append(s[i+1])
                i+=2
            cunt+=1
            if len(S)==5:
                flag="S"
                break
        elif s[i]=="H":
            if s[i+1]=="1" and not("10" in H):
                H.append("10")
                i+=3
            elif (s[i+1]=="J" or s[i+1]=="Q" or s[i+1]=="K" or s[i+1]=="A") and not s[i+1] in H:
                H.append(s[i+1])
                i+=2      
            cunt+=1
            if len(H)==5:
                flag="H"
                break  
        elif s[i]=="D":
            if s[i+1]=="1" and not("10" in D):
                D.append("10")
                i+=3
            elif (s[i+1]=="J" or s[i+1]=="Q" or s[i+1]=="K" or s[i+1]=="A") and  not s[i+1] in D:
                D.append(s[i+1])
                i+=2 
            cunt+=1
            if len(D)==5:
                flag="D"
                break
        elif s[i]=="C":
            if s[i+1]=="1" and not("10" in C):
                C.append("10")
                i+=3
            elif (s[i+1]=="J" or s[i+1]=="Q" or s[i+1]=="K" or s[i+1]=="A")  and not s[i+1] in C:
                C.append(s[i+1])
                i+=2        
            cunt+=1
            if len(C)==5:
                flag="C"
                break
    ans=""
    i=0
    while cunt:
        if s[i]!=flag:
            if s[i+1]=="1":
                ans+=s[i:i+3]
                i+=3
            elif s[i+1]=="J" or s[i+1]=="Q" or s[i+1]=="K" or s[i+1]=="A":
                ans+=s[i:i+2]
                i+=2
        else:
            if s[i+1]=="1":i+=3
            else:i+=2
        cunt-=1
    if ans=="":
        print(0)
    else:
        print(ans)


if __name__=='__main__':
    main()