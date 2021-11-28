#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>

#define LEN 100005
using namespace std;

typedef struct pp{
    char name[100];
    int t;
}P;

P Q[LEN];
int head,tail,n;

void enqueue(P x){
    Q[tail]=x;
    tail=(tail+1)%LEN;
}

P dequeue(){
    P x=Q[head];
    head=(head+1)%LEN;
    return x;
}

int main(){
    int elaps=0,c;
    int i,q;
    P u;
    scanf("%d %d",&n,&q);

    for(i=1;i<n;i++){
        scanf("%s",Q[i].name);
        scanf("%d",&Q[i].t);

    }
    head=1;              
    tail=n+1;

    while(head!=tail){
        u=dequeue();
        c=min(q,u.t);
        u.t-=c;
        elaps+=c;
        if(u.t>0)
            enqueue(u);
        else
            printf("%s %d\n",u.name,elaps);
    }
    return 0;
}                       Last login: Thu Mar  1 15:54:29 on console
YHnoMacbook-pro:~ derodontus$ ls
AnacondaProjects	Untitled.ipynb		Untitled6.ipynb
Applications		Untitled1.ipynb		Untitled7.ipynb
Desktop			Untitled10.ipynb	Untitled8.ipynb
Documents		Untitled11.ipynb	Untitled9.ipynb
Downloads		Untitled12.ipynb	VirtualBox VMs
Dropbox			Untitled13.ipynb	anaconda
Library			Untitled14.ipynb	cache.ga
Movies			Untitled2.ipynb		enthought
Music			Untitled3.ipynb		installer.sh
Pictures		Untitled4.ipynb		test.txt
Public			Untitled5.ipynb		xh.pdf
YHnoMacbook-pro:~ derodontus$ cd Desktop
YHnoMacbook-pro:Desktop derodontus$ ls
1.cpp				自炊
2.php				言語
VirtualBox.app			音楽
a.out				ウイルス対策
~$彼らが太る前.docxx		同期ファイル
画像				応用情報技術者
YHnoMacbook-pro:Desktop derodontus$ cd 言語
YHnoMacbook-pro:言語 derodontus$ ls
C		Excel		MEIKAIC1S	python		vim
C++		Java		R		swift
YHnoMacbook-pro:言語 derodontus$ cd C++
YHnoMacbook-pro:C++ derodontus$ ls
AOJ	contest	test
YHnoMacbook-pro:C++ derodontus$ cd contest test
YHnoMacbook-pro:contest derodontus$ cd beginner
YHnoMacbook-pro:beginner derodontus$ cd /Users/derodontus/Desktop/言語/C++/contest/beginner/089 
YHnoMacbook-pro:089 derodontus$ vim A.cpp
YHnoMacbook-pro:089 derodontus$ vim B.cpp
YHnoMacbook-pro:089 derodontus$ vim C.cpp
YHnoMacbook-pro:089 derodontus$ vim D.cpp
YHnoMacbook-pro:089 derodontus$ cd ..
YHnoMacbook-pro:beginner derodontus$ mkdir 088
YHnoMacbook-pro:beginner derodontus$ cd 088
YHnoMacbook-pro:088 derodontus$ vim A.cpp
YHnoMacbook-pro:088 derodontus$ vim B.cpp
YHnoMacbook-pro:088 derodontus$ vim C.cpp







YHnoMacbook-pro:088 derodontus$ vim D.cpp
YHnoMacbook-pro:088 derodontus$ cd..
-bash: cd..: command not found
YHnoMacbook-pro:088 derodontus$ cd ..
YHnoMacbook-pro:beginner derodontus$ mkdir 087
YHnoMacbook-pro:beginner derodontus$ cd 087
YHnoMacbook-pro:087 derodontus$ vim A.cpp
YHnoMacbook-pro:087 derodontus$ vim B.cpp
YHnoMacbook-pro:087 derodontus$ vim C.cpp
YHnoMacbook-pro:087 derodontus$ cd ../086
-bash: cd: ../086: No such file or directory
YHnoMacbook-pro:087 derodontus$ cd ..
YHnoMacbook-pro:beginner derodontus$ mkdir 086
YHnoMacbook-pro:beginner derodontus$ cd 086
YHnoMacbook-pro:086 derodontus$ vim A.cpp
YHnoMacbook-pro:086 derodontus$ vim B.cpp
YHnoMacbook-pro:086 derodontus$ vim C.cpp
YHnoMacbook-pro:086 derodontus$ cd ..
YHnoMacbook-pro:beginner derodontus$ mkdir 085
YHnoMacbook-pro:beginner derodontus$ cd 085
YHnoMacbook-pro:085 derodontus$ vim A.cpp
YHnoMacbook-pro:085 derodontus$ vim B.cpp
YHnoMacbook-pro:085 derodontus$ vim B1.cpp
YHnoMacbook-pro:085 derodontus$ vim C.cpp
YHnoMacbook-pro:085 derodontus$ cd ..
YHnoMacbook-pro:beginner derodontus$ cd ..
YHnoMacbook-pro:contest derodontus$ l
-bash: l: command not found
YHnoMacbook-pro:contest derodontus$ ls
2:10		beginner	regular		企業
JOI		grand		typical		非公式
YHnoMacbook-pro:contest derodontus$ cd regular
YHnoMacbook-pro:regular derodontus$ ls
YHnoMacbook-pro:regular derodontus$ mkdeir 091
-bash: mkdeir: command not found
YHnoMacbook-pro:regular derodontus$ mkdir 091
YHnoMacbook-pro:regular derodontus$ ls
091
YHnoMacbook-pro:regular derodontus$ cd ..
YHnoMacbook-pro:contest derodontus$ ls
2:10		beginner	regular		企業
JOI		grand		typical		非公式
YHnoMacbook-pro:contest derodontus$ cd beginner
YHnoMacbook-pro:beginner derodontus$ ls
085	086	087	088	089
YHnoMacbook-pro:beginner derodontus$ mkdir 090
YHnoMacbook-pro:beginner derodontus$ cd 090
YHnoMacbook-pro:090 derodontus$ vim A.cpp
YHnoMacbook-pro:090 derodontus$ vim B.cpp
YHnoMacbook-pro:090 derodontus$ vim C.cpp
YHnoMacbook-pro:090 derodontus$ vim A.cpp
YHnoMacbook-pro:090 derodontus$ vim B.cpp
YHnoMacbook-pro:090 derodontus$ vim D.cpp
YHnoMacbook-pro:090 derodontus$ vim D.cpp
YHnoMacbook-pro:090 derodontus$ vim D.cpp
YHnoMacbook-pro:090 derodontus$ vim C.cpp
YHnoMacbook-pro:090 derodontus$ vim C1.cpp
YHnoMacbook-pro:090 derodontus$ vim D1.cpp
YHnoMacbook-pro:090 derodontus$ pwd
/Users/derodontus/Desktop/言語/C++/contest/beginner/090
YHnoMacbook-pro:090 derodontus$ cd ..
YHnoMacbook-pro:beginner derodontus$ ls
085	086	087	088	089	090
YHnoMacbook-pro:beginner derodontus$ mkdir 084
YHnoMacbook-pro:beginner derodontus$ cd 088
YHnoMacbook-pro:088 derodontus$ ls
A.cpp	B.cpp	C.cpp	a.out
YHnoMacbook-pro:088 derodontus$ vim D.cpp
YHnoMacbook-pro:088 derodontus$ cd ...
-bash: cd: ...: No such file or directory
YHnoMacbook-pro:088 derodontus$ cd ..
YHnoMacbook-pro:beginner derodontus$ ls
084	085	086	087	088	089	090
YHnoMacbook-pro:beginner derodontus$ pwd
/Users/derodontus/Desktop/言語/C++/contest/beginner
YHnoMacbook-pro:beginner derodontus$ cd ..
YHnoMacbook-pro:contest derodontus$ ls
2:10		beginner	regular		企業
JOI		grand		typical		非公式
YHnoMacbook-pro:contest derodontus$ cd ..
YHnoMacbook-pro:C++ derodontus$ ls
AOJ	contest	test
YHnoMacbook-pro:C++ derodontus$ cd AOJ
YHnoMacbook-pro:AOJ derodontus$ ls
1-4a.cpp	a[i][j]		itp1-5.cpp	itp1-8a.cpp
59.c		b[j][k]		itp1-5a.cpp	itp1-8b.cpp
59.cpp		itp1-2.cpp	itp1-5b.cpp	itp1-8c.cpp
63.cpp		itp1-2b.cpp	itp1-5d.cpp	itp1-8d.cpp
69.cpp		itp1-2c.cpp	itp1-6a.cpp	itp1-9a.cpp
72-1.cpp	itp1-2d.cpp	itp1-6b.cpp	itr1-1.cpp
72.cpp		itp1-3.cpp	itp1-6c.cpp	l
73.cpp		itp1-3b.cpp	itp1-6ctest.cpp	m
86		itp1-3c.cpp	itp1-6d.cpp	n
86-1.cpp	itp1-3d.cpp	itp1-7a.cpp	test-1.cpp
86.cpp		itp1-4b.cpp	itp1-7b.cpp	test.cpp
a.out		itp1-4c.cpp	itp1-7c.cpp	test59-1.c
a[i]		itp1-4d.cpp	itp1-7d.cpp	test63-1.cpp
YHnoMacbook-pro:AOJ derodontus$ ls
86		a[i][j]		itr1-1.cpp	test-1.cpp
86-1.cpp	alds1		l		test.cpp
a.out		b[j][k]		m		test59-1.c
a[i]		itp		n		test63-1.cpp
YHnoMacbook-pro:AOJ derodontus$ cd alds1
YHnoMacbook-pro:alds1 derodontus$ vim 1-3a.cpp
YHnoMacbook-pro:alds1 derodontus$ vim 1-3b.cpp

#include<iostream>                                               
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>

#define LEN 100005
using namespace std;

typedef struct pp{
    char name[100];
    int t;
}P;

P Q[LEN];
int head,tail,n;

void enqueue(P x){
    Q[tail]=x;
    tail=(tail+1)%LEN;
}

P dequeue(){
    P x=Q[head];
    head=(head+1)%LEN;
    return x;
}

int main(){
    int elaps=0,c;
    int i,q;
    P u;
    scanf("%d %d",&n,&q);

    for(i=1;i<n;i++){
        scanf("%s",Q[i].name);
        scanf("%d",&Q[i].t);

    }
    head=1;              
    tail=n+1;

    while(head!=tail){
        u=dequeue();
        c=min(q,u.t);
        u.t-=c;
        elaps+=c;
        if(u.t>0)
            enqueue(u);
        else
            printf("%s %d\n",u.name,elaps);
    }
    return 0;
}    


