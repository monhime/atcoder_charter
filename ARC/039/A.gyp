import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    a,b=input().split()
    if a[0]!="9":
        if b[0]!="1":
            print(max(int("9"+a[1:])-int(b),int(a)-int("1"+b[1:])))
        elif b[1]!="0":
            print(max(int("9"+a[1:])-int(b),int(a)-int(b[0]+"0"+b[2])))
        else:
            print(max(int("9"+a[1:])-int(b),int(a)-int(b[:2]+"0")))
    elif a[1]!="9":
        if b[0]!="1":
            print(max(int(a[0]+"9"+a[2])-int(b),int(a)-int("1"+b[1:])))
        elif b[1]!="0":
            print(max(int(a[0]+"9"+a[2])-int(b),int(a)-int(b[0]+"0"+b[2])))
        else:
            print(max(int(a[0]+"9"+a[2])-int(b),int(a)-int(b[:2]+"0")))  
    else: 
        if b[0]!="1":
            print(max(int(a[:2]+"9")-int(b),int(a)-int("1"+b[1:])))
        elif b[1]!="0":
            print(max(int(a[:2]+"9")-int(b),int(a)-int(b[0]+"0"+b[2])))
        else:
            print(max(int(a[:2]+"9")-int(b),int(a)-int(b[:2]+"0")))              

if __name__=='__main__':
    main()