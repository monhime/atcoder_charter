#include<iostream>
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
double cross(Vector a,Vector b){//外積
    return a.x*b.y-a.y*b.x;
}

bool isOrthogonal(Point a1,Point a2,Point b1,Point b2){//直角条件
    return equals(dot(a1-a2,b1-b2),0.0);
}
bool isParallel(Point a1,Point a2,Point b1,Point b2){//平行条件
    return equals(cross(a1-a2,b1-b2),0.0);
}

int main(){
    int q;

    cin>>q;
    Point p[4];
    for(int i=0;i<q;i++){
        cin>>p[0].x>>p[0].y>>p[1].x>>p[1].y;
        cin>>p[2].x>>p[2].y>>p[3].x>>p[3].y;
        if(isOrthogonal(p[0],p[1],p[2],p[3]))cout<<1<<"\n";
        else if(isParallel(p[0],p[1],p[2],p[3]))cout<<2<<"\n";
        else cout<<0<<"\n";
    }
    return 0;

}

