#include<iostream>
#include<math.h>
#include<float.h>
#include<cstdio>
#include<vector>
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
//点の内包
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
int main(){
    Polygon g;
    Point p;
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>p.x>>p.y;
        g.push_back(p);
    }
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p.x>>p.y;
        cout<<contains(g,p)<<"\n";
    }
    return 0;
}
    
