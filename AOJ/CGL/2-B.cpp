//点、ベクトル、線分を表すクラス　p371~377
#include<iostream>
#include<math.h>
#include<float.h>
#include<cstdio>
using namespace std;
#define EPS (1e-10)
#define equals(a,b) fabs((a)-(b))<DBL_EPSILON*fmax(1,fmax(fabs(a),fabs(b)))
//点のクラス
class Point{
    public:
        double x,y;
        Point(double x=0,double y=0):x(x),y(y){}

        Point operator + (Point p){return Point(x+p.x,y+p.y);}
        Point operator - (Point p){return Point(x-p.x,y-p.y);}
        Point operator * (double a){return Point(a*x,a*y);}
        Point operator / (double a){return Point(x/a,y/a);}

        double norm(){return x*x+y*y;}
        double abs(){return sqrt(norm());}    

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
//内積
double dot(Vector a,Vector b){ return a.x*b.x+a.y*b.y; }
//外戚
double cross(Vector a,Vector b){ return a.x*b.y-a.y*b.x; }
//ベクトルa,bの位置関係
int ccw(Point p0,Point p1,Point p2){
    Vector a=p1-p0;
    Vector b=p2-p0;
    if(cross(a,b)>EPS) return 1;//p0,p1,p2が反時計回り
    if(cross(a,b)<-EPS) return -1;//p0,p1,p2が時計回り
    if(dot(a,b)<-EPS) return 2;//p1,p0,p2の順で一直線
    if(a.norm()<b.norm()) return -2;//p0,p1,p2の順で一直線
    return 0; //p0,p2,p1の順で一直線
}
//交差判定　p389
bool intersect(Point p1,Point p2,Point p3,Point p4){
    return ( ccw(p1,p2,p3)*ccw(p1,p2,p4)<=0&&
            ccw(p3,p4,p1)*ccw(p3,p4,p2)<=0);//p1,p2,p3,p4の順で一直線になるのを除く
}
int main(){
    int q;
    cin>>q;
    Point p[4];
    for(int i=0;i<q;i++){
        cin>>p[0].x>>p[0].y>>p[1].x>>p[1].y;
        cin>>p[2].x>>p[2].y>>p[3].x>>p[3].y;
        if(intersect(p[0],p[1],p[2],p[3]))cout<<1<<"\n";
        else cout<<0<<"\n";
    }
    return 0;
}
