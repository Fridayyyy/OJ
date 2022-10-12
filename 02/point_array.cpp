//
// Created by 常贵杰 on 2022/8/31.
//
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;
class Point{
    double x,y;
public:
    Point();
    Point(double x_value,double y_value);
    ~Point();
    double getX();
    double getY();
    void setY(double x1,double y1){x=x1;y=y1;};
    void setX(double x_value);
    void setY(double y_value);
    double getDisTo(const Point &p);

};
Point::Point() {

}
Point::~Point() {
    cout<<"Distructor."<<endl;
}
Point::Point(double x_value, double y_value) {
    this->x=x_value;
    this->y=y_value;
}

double Point::getX() {
    return this->x;
}
double Point::getY() {
    return this->y;
}
void Point::setX(double x_value) {
    this->x=x_value;
}
void Point::setY(double y_value) {
    this->y=y_value;
}
double Point::getDisTo(const Point &p) {
    return hypot(p.x- this->x,p.y- this->y);
}

class res{
private:
    double distance;
    int i;
    int j;

public:
    void setI(int i){
        this->i=i;
    }
    int getI(){
        return this->i;
    }
    void setJ(int j){
        this->j=j;
    }
    int getJ(){
        return this->j;
    }
    void setDistance(double distance){
        this->distance=distance;
    }

    double getDistance(){
        return this->distance;
    }

};

res* helper(vector<Point*> vec){
    res* r=new res();
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = i+1; j < vec.size(); ++j) {
            double x= hypot(vec[i]->getX()-vec[j]->getX(),vec[i]->getY()-vec[j]->getY());
            if (x>r->getDistance()){
                r->setDistance(x);
                r->setI(i);
                r->setJ(j);
            }
        }
    }

    return r;
}
int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int counts;
        cin>>counts;
        vector<Point*> vec;

        for (int j = 0; j < counts; ++j) {
            double x,y;
            cin>>x;
            cin>>y;
            Point *point = new Point(x,y);
            cout<<"Constructor."<<endl;
            vec.push_back(point);
        }
        res* r= helper(vec);
        cout<<"The longeset distance is ";
        cout<<fixed<<setprecision(2)<<r->getDistance();
        cout<<",between p["+to_string(r->getI())+"] and p["+to_string(r->getJ())+"]."<<endl;
        for (int j = 0; j < counts; ++j) {
            delete vec[j];
        }
    }
}
