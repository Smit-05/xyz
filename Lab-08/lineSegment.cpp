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

int direction(Point *pi,Point *pj,Point *pk){
    Point *ref = new Point(pj->x-pi->x,pj->y-pi->y);
    Point *t = new Point(pk->x-pi->x,pk->y-pi->y);

    int d = (t->x*ref->y) - (t->y*ref->x);
    return d;
}

bool onSegment(Point *pi,Point *pj,Point *pk){
    if(min(pi->x,pj->x)<=pk->x and max(pi->x,pj->x)>=pk->x and min(pi->y,pj->y)<=pk->y and max(pi->y,pj->y)>=pk->y)
        return true;
    return false;
}

bool isLineSegmentIntersect(vector<Point *> &points){
    int d1 = direction(points[2],points[3],points[0]);
    int d2 = direction(points[2],points[3],points[1]);
    int d3 = direction(points[0],points[1],points[2]);
    int d4 = direction(points[0],points[1],points[3]);

    if(0>d1*d2 and 0>d3*d4){
        return true;
    }else if(0==d1 and onSegment(points[2],points[3],points[0])){
        return true;
    }else if(0==d2 and onSegment(points[2],points[3],points[1])){
        return true;
    }else if(0==d3 and onSegment(points[0],points[1],points[2])){
        return true;
    }else if(0==d4 and onSegment(points[0],points[1],points[3])){
        return true;
    }

    return false;
}

int main(){
    vector<Point *> points(4);
    for(int i=0;i<4;i++){
        int x,y;
        cin>>x>>y;
        points[i] = new Point(x,y);
    }

    if(isLineSegmentIntersect(points)){
        cout<<"line segment p1p2 intersect with p3p4"<<endl;
    }else{
        cout<<"line segment p1p2 not intersect with p3p4"<<endl;
    }
        

    return 0;
}


// case1 : line segment p1p2 intersect with p3p4
// 1 1
// 4 8
// 2 6
// 6 3

// case2 : line segment p1p2 intersect with p3p4
// 1 1
// 8 8
// 3 6
// 5 5

// case3: line segment p1p2 intersect with p3p4
// 1 1
// 5 5
// 3 3
// 8 8

// case4: line segment p1p2 not intersect with p3p4
// 2 2
// 8 3
// 1 4
// 6 5