#include <bits/stdc++.h>
using namespace std;
struct Point
{
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y){}

};
struct Line
{
    double A,B,C;
    Line(){}
    Line(double A,double B,double C):A(A),B(B),C(C){}
    Line(Point p1,Point p2)
    {
        A = p2.y-p1.y;
        B = p1.x-p2.x;
        C = (p1.y-p2.y)*p1.x-p1.y*(p1.x-p2.x);
    }

};

Point f(Line L1,Line L2)
{
    Point res;
    double A1 = L1.A,A2 = L2.A,B1 = L1.B,B2 = L2.B,C1 = L1.C,C2 = L2.C;
    res.y = 1.0*(C2*A1-C1*A2)/(A2*B1-A1*B2);
    res.x = -1.0*(C1+B1*res.y)/A1;
    return res;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        double x[3],y[3];
        cin>>x[0]>>y[0]>>x[1]>>y[1]>>x[2]>>y[2];
        if(x[1] == x[2])
        {
            Point res(x[1],y[0]);
            printf("%.7lf %.7lf\n",res.x,res.y);
            continue;
        }
        Point P1(x[1],y[1]),P2(x[2],y[2]);
        Line L1(P1,P2);
        Line L2(L1.B,-L1.A,y[0]*L1.A-L1.B*x[0]);
        Point res = f(L1,L2);
        printf("%.7lf %.7lf\n",res.x,res.y);
    }
}