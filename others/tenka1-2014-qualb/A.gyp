import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    for i in range(len(s)-5):
        if s[i:i+6]=="HAGIYA":
            print(s[:i]+"HAGIXILE"+s[i+6:])
            break

if __name__=='__main__':
    main()