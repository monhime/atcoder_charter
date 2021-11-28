#include<cstdio>

int main(){
    int n;
    int h,m,s;

    scanf("%d",&n);

    s=n%60;
    m=((n-s)%3600)/60;
    h= (n-60*m-s)/3600;
    
    printf("%d:%d:%d\n",h,m,s);
    return 0;

}
