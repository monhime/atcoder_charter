#include<cstdio>
int main(){
    char a[5];
    int i;

    for(i=0;i<6;i++)
         scanf("%c",&a[i]);
    if((a[0]=='y'&&a[1]=='a'&&a[2]=='h')&&(a[3]==a[4]))
        printf("YES");
    else
        printf("NO");
    return 0;
            
}
