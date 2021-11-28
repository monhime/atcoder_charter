import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    c=input()
    if c=="O" or c=="P" or c=="K" or c=="L":
        print("Right")
    else:
        print("Left")

if __name__=='__main__':
    main()