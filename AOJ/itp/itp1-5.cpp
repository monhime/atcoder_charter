#include<cstdio>
#include<iostream>

int main(){
    int i,j,h,w;
    bool flag,FALG,tmp,TMP;

    while(scanf("%d %d",&h,&w)&&(h||w)){
        for(i=1;i<h+1;i++){
            for(j=1;j<w+1;j++){
                if((i+j)%2)
                    putchar('.');
                else
                    putchar('#');

            }
            putchar('\n');
        }
        putchar('\n');
    }
}
