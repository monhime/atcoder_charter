#include<iostream>
#include<algorithm>
#include<math.h>
#include<float.h>
#include<cstdio>
#include<vector>          
#include<set>
//#include<bits/stdc++.h>
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
//円
class Circle{
    public:
        Point c;
        double r;
        Circle(Point c=Point(),double r=0.0):c(c),r(r){}
};
//多角形
typedef vector<Point> Polygon;
//内積
double dot(Vector a,Vector b){ return a.x*b.x+a.y*b.y; }
//外戚
double cross(Vector a,Vector b){ return a.x*b.y-a.y*b.x; }
//直交
bool isOrthogonal(Vector a,Vector b){ return equals(dot(a,b),0.0); }
bool isOrthogonal(Point a1,Point a2,Point b1,Point b2){ return isOrthogonal(a1-a2,b1-b2); }
bool isOrthogonal(Segment s1,Segment s2){ return equals(dot(s1.p1-s1.p2,s2.p1-s2.p2),0.0); }
//平行
bool isParallel(Vector a,Vector b){ return equals(cross(a,b),0.0); }
bool isParallel(Point a1,Point a2,Point b1,Point b2){ return isParallel(a1-a2,b1-b2); }
bool isParallel(Segment s1,Segment s2){ return equals(cross(s1.p2-s1.p1,s2.p2-s2.p1),0.0); }
//射影
Point project(Segment s,Point p){ //射影　p377
    Vector base=s.p2-s.p1;
    double r=dot(p-s.p1,base)/norm(base);
    return s.p1+base*r;
}
//反射　p379
Point reflect(Segment s,Point p){return p+(project(s,p)-p)*2.0;}
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
//交差判定　p389
bool intersect(Point p1,Point p2,Point p3,Point p4){
    return ( ccw(p1,p2,p3)*ccw(p1,p2,p4)<=0&&
            ccw(p3,p4,p1)*ccw(p3,p4,p2)<=0);//p1,p2,p3,p4の順で一直線になるのを除く
}
bool intersect(Segment s1,Segment s2){
    return intersect(s1.p1,s1.p2,s2.p1,s2.p2);
}
//交点の座標　p392
Point getCrossPoint(Segment s1,Segment s2){ 
    Vector base=s2.p2-s2.p1;
    double d1=abs(cross(base,s1.p1-s2.p1));
    double d2=abs(cross(base,s1.p2-s2.p1));
    double t=d1/(d1+d2);
    return s1.p1+(s1.p2-s1.p1)*t;
}
//距離p380
double getDistance(Point a,Point b){ return abs(a-b);} //点aと点b
double getDistanceLP(Line l,Point p){//直線lと点p
    return abs(cross(l.p2-l.p1,p-l.p1)/abs(l.p2-l.p1));
}
double getDistanceSP(Segment s,Point p){//線分sと点p
    if(dot(s.p2-s.p1,p-s.p1)<0.0)return abs(p-s.p1);
    if(dot(s.p1-s.p2,p-s.p2)<0.0)return abs(p-s.p2);
    return getDistanceLP(s,p);
}
double getDistance(Segment s1,Segment s2){ //線分s1と線分s2
    if(intersect(s1,s2))return 0.0;
    return min(min(getDistanceSP(s1,s2.p1),getDistanceSP(s1,s2.p2)),
            min(getDistanceSP(s2,s1.p1),getDistanceSP(s2,s1.p2)));
}
//円　交点
pair<Point,Point> getCrossPoints(Circle c,Line l){
    //asert(intersect(c,l));   交点を持つことの確認
    Vector pr =project(l,c.c);
    Vector e=(l.p2-l.p1)/abs(l.p2-l.p1);
    double base=sqrt(c.r*c.r-norm(pr-c.c));
    return make_pair(pr+e*base,pr-e*base);
}
//２つの円の交点
double arg(Vector p){ return atan2(p.y,p.x); }
Vector polar(double a,double r){ return Point(cos(r)*a,sin(r)*a);}
pair<Point,Point> getCrossPoints(Circle c1,Circle c2){
    //assert(intersect(c1,c2));
    double d=abs(c1.c-c2.c);
    double a=acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));
    double t=arg(c2.c-c1.c);
    return make_pair(c1.c+polar(c1.r,t+a),c1.c+polar(c1.r,t-a));
}
//点の内包p398
int contains(Polygon g,Point p){
    int n=g.size();
    bool x=false;
    for(int i=0;i<n;i++){
        Point a=g[i]-p;
        Point b=g[(i+1)%n]-p;
        if( abs(cross(a,b))<EPS&&dot(a,b)<EPS)return 1;
        if(a.y>b.y)swap(a,b);
        if(a.y<EPS&&EPS<b.y&&cross(a,b)>EPS)x=!x;
    }
    return (x?2:0);
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
        //        for(int n=l.size();n>=2&&ccw(l[n-2],l[n-1],s[i])!=CLOCKWISE;n--)//辺上を含まない
        for(int n=l.size();n>=2&&ccw(l[n-2],l[n-1],s[i])==COUNTER_CLOCKWISE;n--) 
            l.pop_back();
        l.push_back(s[i]);    
    }
    reverse(l.begin(),l.end());
    for(int i=u.size()-2;i>=1;i--)l.push_back(u[i]);
    return l;
}
//平面走査p408
static const int BOTTOM=0;
static const int LEFT=1;
static const int RIGHT=2;
static const int TOP=3;
class EndPoint{
    public:
        Point p;
        int seg,st;
        EndPoint(){}
        EndPoint(Point p,int seg,int st):p(p),seg(seg),st(st){}
        bool operator < (const EndPoint &ep) const{
            if(p.y==ep.p.y)
                return st<ep.st;//BOTTOM,LEFT,RIGHT,TOP
            else
                return p.y<ep.p.y;
        }
};
EndPoint EP[2*100000];
int manhattanIntersection(vector<Segment> S){
    int n=S.size();
    for(int i=0,k=0;i<n;i++){
        if(S[i].p1.y==S[i].p2.y){
            if(S[i].p1.x>S[i].p2.x)
                swap(S[i].p1,S[i].p2);
        }else if(S[i].p1.y>S[i].p2.y)
            swap(S[i].p1,S[i].p2);

        if(S[i].p1.y==S[i].p2.y){
            EP[k++]=EndPoint(S[i].p1,i,LEFT);
            EP[k++]=EndPoint(S[i].p2,i,RIGHT);
        }else{
            EP[k++]=EndPoint(S[i].p1,i,BOTTOM);
            EP[k++]=EndPoint(S[i].p2,i,TOP);
        }
    }
    sort(EP,EP+(2*n));
    set<int> BT;
    BT.insert(1000000001);
    int cnt=0;
    for(int i=0;i<2*n;i++){
        if(EP[i].st==TOP)
            BT.erase(EP[i].p.x);
        else if(EP[i].st==BOTTOM)
            BT.insert(EP[i].p.x);
        else if(EP[i].st==LEFT){
            set<int>::iterator b=BT.lower_bound(S[EP[i].seg].p1.x);
            set<int>::iterator e=BT.upper_bound(S[EP[i].seg].p2.x);
            cnt+=distance(b,e);//bからeまでの数
        }    
    }
    return cnt;
}
int main(){
    int n,cnt;
    cin>>n;
    Segment s;
    vector<Segment> S;
    for(int i=0;i<n;i++){
        Point p1,p2;
        cin>>p1.x>>p1.y>>p2.x>>p2.y;
        s.p1=p1;
        s.p2=p2;
        S.push_back(s);
    }
    cnt =manhattanIntersection(S);
    cout<<cnt<<"\n";
    return 0;
}
