#include<iostream>

#include<cstdio>
#include<math.h>
#include<float.h>
using namespace std;
#define equals(a,b) fabs((a)-(b))<DBL_EPSILON*fmax(1,fmax(fabs(a),fabs(b)))
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
struct Segment{
    Point p1,p2;
};
typedef Segment Line;
double dot(Vector a,Vector b){//内積
    return a.x*b.x+a.y*b.y;
}
Point project(Segment s,Point p){ //射影　p377
    Vector base=s.p2-s.p1;
    double r=dot(p-s.p1,base)/base.norm();
    return s.p1+base*r;
}
Point reflect(Segment s,Point p){return p+(project(s,p)-p)*2.0;}
int main(){
    int q;
    Point p1,p2;
    scanf("%lf %lf %lf %lf",&p1.x,&p1.y,&p2.x,&p2.y);
    Segment s;
    s.p1=p1;  s.p2=p2;
    cin>>q;
    Point p,pp;
    for(int i=0;i<q;i++){
        cin>>p.x>>p.y;
        pp=reflect(s,p);
        printf("%.10f %.10f\n",pp.x,pp.y);
    }
    return 0;
}
