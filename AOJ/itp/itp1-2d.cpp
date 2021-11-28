#include<cstdio>

int main(){
    int H,W,x,y,r;

    scanf("%d %d %d %d %d",&W,&H,&x,&y,&r);
    if(((r<=y)&&(y<=H-r))&&((r<=x)&&(x<=W-r)))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;


}
