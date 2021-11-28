#include<iostream>
#include<algorithm>
#include<math.h>
#include<float.h>
#include<cstdio>
#include<vector>
//#include <bits/stdc++.h>
using namespace std;
#define EPS (1e-10)
#define equals(a,b) fabs((a)-(b))<DBL_EPSILON*fmax(1,fmax(fabs(a),fabs(b)))
//点
class Point{
    public:
        double x,y;
        Point(double x=0,double y=0):x(x),y(y){}

        Point operator + (Point p){return Point(x+p.x,y+p.y);}
        Point operator - (Point p){return Point(x-p.x,y-p.y);}
        Point operator * (double a){return Point(a*x,a*y);}
        Point operator / (double a){return Point(x/a,y/a);}

        double norm(Point p){return p.x*p.x+p.y*p.y;}
        double abs(Point p){return sqrt(norm(p));}    
        bool operator < (const Point &p)const{
            return x!=p.x?x<p.x:y<p.y;
        }
        bool operator == (const Point &p)const{
            return equals(x,p.x)&&equals(y,p.y);
        }
};
typedef Point Vector;
struct Segment{ Point p1,p2; };
typedef Segment Line;
double norm(Vector v){return v.x*v.x+v.y*v.y;} 
double abs(Vector v){return sqrt(norm(v));}    
//多角形
typedef vector<Point> Polygon;
//内積
double dot(Vector a,Vector b){ return a.x*b.x+a.y*b.y; }
//外戚
double cross(Vector a,Vector b){ return a.x*b.y-a.y*b.x; }
//ベクトルa,bの位置関係
static const int COUNTER_CLOCKWISE=1;//反時計回り
static const int CLOCKWISE=-1;//時計回り
static const int ONLINE_BACK=2;//p2,p0,p1の順で一直線上
static const int ONLINE_FRONT=-2;//p0,p1,p2の順で一直線上
static const int ON_SEGMENT=0;//p0,p2,p1の順で一直線上
int ccw(Point p0,Point p1,Point p2){
    Vector a=p1-p0;
    Vector b=p2-p0;
    if(cross(a,b)>EPS) return COUNTER_CLOCKWISE;
    if(cross(a,b)<-EPS) return CLOCKWISE;
    if(dot(a,b)<-EPS) return ONLINE_BACK;
    if(norm(a)<norm(b)) return ONLINE_FRONT;
    return ON_SEGMENT;
}
//凸包　アンドリューのアルゴリズム
Polygon andrewScan(Polygon s){
    Polygon u,l;
    if(s.size()<3)return s;
    sort(s.begin(),s.end());
    u.push_back(s[0]);
    u.push_back(s[1]);
    l.push_back(s[s.size()-1]);
    l.push_back(s[s.size()-2]);
    //凸包の上部を生成
    for(int i=2;i<s.size();i++){
//        for(int n=u.size();n>=2&&ccw(u[n-2],u[n-1],s[i])!=CLOCKWISE;n--) //辺上を含まない
        for(int n=u.size();n>=2&&ccw(u[n-2],u[n-1],s[i])==COUNTER_CLOCKWISE;n--)
            u.pop_back();
        u.push_back(s[i]);   
    }
    //凸包の下部を生成
    for(int i=s.size()-3;i>=0;i--){
//        for(int n=l.size();n>=2&&ccw(l[n-2],l[n-1],s[i])!=CLOCKWISE;n--)//返上を含まない
        for(int n=l.size();n>=2&&ccw(l[n-2],l[n-1],s[i])==COUNTER_CLOCKWISE;n--) 
            l.pop_back();
        l.push_back(s[i]);    
    }
    reverse(l.begin(),l.end());
    for(int i=u.size()-2;i>=1;i--)l.push_back(u[i]);
    return l;
}
int main(){
    int n;
    cin>>n;
    Point p;
    Polygon s,l;
    for(int i=0;i<n;i++){
        cin>>p.x>>p.y;
        s.push_back(p);
    }
    l=andrewScan(s);
    cout<<l.size()<<"\n";
    int min_num=10000;
    vector<Point>::iterator it,min;
    for(it=l.begin();it!=l.end();it++){
        if(it->y<min_num){
            min_num=it->y;
            min=it;
        }
        else if(it->y==min_num&&it->x<min->x)
            min=it;
    }
    for(it=min;it!=l.end();it++)    
        cout<<it->x<<" "<<it->y<<"\n";
    for(it=l.begin();it!=min;it++)   
        cout<<it->x<<" "<<it->y<<"\n";
    return 0;
        
}
