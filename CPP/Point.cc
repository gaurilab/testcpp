
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
class Point{
    private:
        int _x;
        int _y;
        int _z;
        friend class lineSegment;
        friend class Vector;
    public:
        Point(int x =0 , int y=0, int z=0):_x(x),_y(y),_z(z){}
        Point(const Point& p):_x(p._x),_y(p._y),_z(p._z){}
        friend const Point operator+(const Point& A, const Point& B ){
            int x_sum = A._x + B._x;
            int y_sum = A._y + B._y;
            int z_sum = A._z + B._z;
            return Point(x_sum,y_sum,z_sum);
        }
        friend const Point operator-(const Point& A, const Point& B ){
            int x_diff = A._x - B._x;
            int y_diff = A._y - B._y;
            int z_diff = A._z - B._z;
            return Point(x_diff,y_diff,z_diff);
        }

        friend ostream& operator<<(ostream& out, const Point& p){
                out<<"("<<p._x<<","<<p._y<<","<<p._z<<")"<<endl;
                return out;
        }


};

class Vector{
    private:
        int _x;
        int _y;
    public:
        Vector():_x(0),_y(0){}
        Vector(const Vector& v):_x(v._x),_y(v._y){}
        Vector(const Point& A,const Point& B):_x(B._x - A._x),_y(B._y - A._y){}
        Vector(int A,int B):_x(A),_y(B){}

        friend const Vector operator+(const Vector& A, const Vector& B ){
            int x = A._x + B._x ;
            int y = A._y + B._y ;
            return Vector(x,y);
        }

        friend const Vector operator-(const Vector& A, const Vector& B ){
            int x = A._x - B._x ;
            int y = A._y - B._y ;
            return Vector(x,y);
        }

        friend const int operator*(const Vector& A, const Vector& B ){

            return ( A._x * B._x + A._y * B._y) ;
        }

        friend const int operator%(const Vector& A, const Vector& B ){
            return ( B._y * A._x - B._x * A._y) ;
        }

        friend ostream& operator<<(ostream& out, const Vector& p){
                out<<"["<<p._x<<","<<p._y<<"]"<<endl;
                return out;
        }
};


class lineSegment{

    public:
        lineSegment(Point a, Point b):A(a),B(b){
            Point dist = B-A;
            length = sqrt(dist._x*dist._x + dist._y*dist._y);
        }
        lineSegment(){length = 0;}
    private:
        Point A;
        Point B;
        uint32_t length;
};

typedef std::vector<Point> pointListT;
typedef std::vector<Point>::iterator pointListIt;

class polygon{
    public:
        polygon(pointListT points):_pointList(points){}
        uint32_t area(){
            for (pointListIt it = _pointList.begin();
                    it != _pointList.end();
                    it ++){
            }
        }
        pointListT  _pointList;

};

int main (){

Point p0;
Point p1(5,5);
Point p2(15,17);
Point p3 =p2-p1;
Point p4 =p2+p1;
cout<<p0;
cout<<p1;
cout<<p2;
cout<<p3;
cout<<p4;
cout<<"Vectors\n";
Vector v1;
#if 1
Vector v2(p1,p2);
Vector v3(v1+v2);
cout<<v1;
cout<<v2;
cout<<v1-v2;
cout<<v3*v2<<endl;
cout<<v3%v2;
//cout<<v3^v2;
cout<<v3;
#endif
return 0;
}
