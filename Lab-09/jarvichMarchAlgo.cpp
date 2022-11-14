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

vector<int> convexHull(vector<Point *> points,int n){
    if(3>n)
        return {};

    vector<int> ch;
    int lowest_x = 0;

    for(int i=1;i<n;i++){
        if(points[i]->x < points[lowest_x]->x){
            lowest_x = i;
        }
    }

    int p = lowest_x,q=0;

    do{
        ch.push_back(p);
        q = (q+1)%n;
        for(int i=0;i<n;i++){
            if(0 > direction(points[p],points[i],points[q])){
                q = i;
            }
        }
        p = q;

    }while(p!=lowest_x);

    return ch;
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

    auto solution = convexHull(points,n);

    cout<<"convex hull points:-"<<endl;
    for(int i : solution){
        cout<<points[i]->x<<" "<<points[i]->y<<endl;
    }

    return 0;
}

/*
// input-1
7
0 3
2 2
1 1
2 1
3 0
0 0
3 3
// output-1
convex hull points:-
0 3
0 0
3 0
3 3
*/


7
0 0
3 1
4 4
1 2
0 5
2 2
-1 3