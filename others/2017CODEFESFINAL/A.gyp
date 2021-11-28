import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    if s in ["KIHBR","AKIHBR","KIHABR","KIHBAR","KIHBRA","AKIHABR","AKIHBAR","AKIHBRA","KIHABAR","KIHABRA","KIHBARA","AKIHABAR","AKIHABRA","AKIHBARA","KIHABARA","AKIHABARA"]:
        print("YES")
    else:print("NO")

if __name__=='__main__':
    main()