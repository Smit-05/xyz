#include <bits/stdc++.h>
using namespace std;

class Point{
    public:
    int x,y;
    Point(int x,int y){
        this->x = x;
        this->y = y;
    }
};

pair<pair<Point *,Point *>,double> findClosestPairOfPoint(vector<Point *> points){
    Point *p1,*p2;
    int dmin = INT_MAX;
    for(int i=0;points.size()>i;i++){
        Point *pi = points[i];
        for(int j=i+1;points.size()>j;j++){
            Point *pj = points[j];
            int d = pow((pi->x-pj->x),2)+pow((pi->y-pj->y),2);
            if(d<dmin){
                p1 = pi;
                p2 = pj;
                dmin = d;
            }
        }
    }
    return {{p1,p2},sqrt(dmin)};
}

int main(){
    int n;
    cin>>n;
    vector<Point *> points(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        points[i] = new Point(x,y);
    }

    pair<pair<Point *,Point *>,double> cp = findClosestPairOfPoint(points);

    cout<<"closest pair of points are : "<<endl;
    cout<<"p1("<<cp.first.first->x<<","<<cp.first.first->y<<")"<<endl;
    cout<<"p2("<<cp.first.second->x<<","<<cp.first.second->y<<")"<<endl;
    cout<<"Distance : "<<cp.second<<endl;
    return 0;
}

// case1:
// 3
// 1 2
// 1 3
// 2 3

// o/p:
// closest pair of points are : 
// p1(1,2)
// p2(1,3)
// Distance : 1
