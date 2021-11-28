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
int ccw(Point p0,Point p1,Point p2){
    Vector a=p1-p0;
    Vector b=p2-p0;
    if(cross(a,b)>EPS) return 1;//p0,p1,p2が反時計回り
    if(cross(a,b)<-EPS) return -1;//p0,p1,p2が時計回り
    if(dot(a,b)<-EPS) return 2;//p1,p0,p2の順で一直線
    if(norm(a)<norm(b)) return -2;//p0,p1,p2の順で一直線
    return 0; //p0,p2,p1の順で一直線
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
int main(){
    int q;
    double pp;
    Point p1,p2;
    cin>>q;
    Point p[4];
    Segment s1,s2;
    for(int i=0;i<q;i++){
        cin>>p[0].x>>p[0].y>>p[1].x>>p[1].y;
        cin>>p[2].x>>p[2].y>>p[3].x>>p[3].y;
        s1.p1=p[0]; s1.p2=p[1];
        s2.p1=p[2]; s2.p2=p[3];
        pp=getDistance(s1,s2);
        printf("%.10f\n",pp);
    }
    return 0;
}
