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
double norm(Vector v){return v.x*v.x+v.y*v.y;} 
double abs(Vector v){return sqrt(norm(v));}    
//円
class Circle{
    public:
        Point c;
        double r;
        Circle(Point c=Point(),double r=0.0):c(c),r(r){}
};
double arg(Vector p){ return atan2(p.y,p.x); }
Vector polar(double a,double r){ return Point(cos(r)*a,sin(r)*a);}
pair<Point,Point> getCrossPoints(Circle c1,Circle c2){
    //assert(intersect(c1,c2));
    double d=abs(c1.c-c2.c);
    double a=acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));
    double t=arg(c2.c-c1.c);
    return make_pair(c1.c+polar(c1.r,t+a),c1.c+polar(c1.r,t-a));
}
int main(){ 
    Circle c1,c2;
    cin>>c1.c.x>>c1.c.y>>c1.r;
    cin>>c2.c.x>>c2.c.y>>c2.r;
    pair<Point,Point> pp;
    pp=getCrossPoints(c1,c2);
    if(pp.first.x>pp.second.x)
        swap(pp.first,pp.second);
    else if(pp.first.x==pp.second.x&&pp.first.y>pp.second.y)
        swap(pp.first,pp.second);

    printf("%.10f %.10f %.10f %.10f\n",pp.first.x,pp.first.y,pp.second.x,pp.second.y);    
    return 0;
}
