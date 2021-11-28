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
int main(){
    int q,flag;
    Point p1,p2;
    scanf("%lf %lf %lf %lf",&p1.x,&p1.y,&p2.x,&p2.y);
    cin>>q;
    Point p;
    for(int i=0;i<q;i++){
        cin>>p.x>>p.y;
        flag=ccw(p1,p2,p);
        switch (flag){
            case 1:
                cout<<"COUNTER_CLOCKWISE";
                break;
            case -1:
                cout<<"CLOCKWISE";
                break;
            case 2:
                cout<<"ONLINE_BACK";
                break;
            case -2:
                cout<<"ONLINE_FRONT";
                break;
            default:    
                cout<<"ON_SEGMENT";
                
        }
        cout<<"\n";
    }
    return 0;
}
