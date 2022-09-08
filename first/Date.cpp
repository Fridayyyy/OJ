//
// Created by 常贵杰 on 2022/8/25.
//
#include <iostream>
#include <iomanip>
using namespace std;
class Date{
    int year,month,day;
public:
    Date();
    Date(int y,int m,int d);
    int getYear();
    int getMonth();
    int getDay();

    void setDate(int y,int m,int d);
    void print();
    void addOneDay();
};
Date::Date() {

}
Date::Date(int y, int m, int d) {
    this->year=y;
    this->month=m;
    this->day=d;
}

int Date::getYear() {
    return this->year;
}
int Date::getMonth() {
    return this->month;
}
int Date::getDay() {
    return this->day;
}
void Date::setDate(int y, int m, int d) {
    this->year=y;
    this->month=m;
    this->day=d;
}
void Date::print() {
    cout<<"Today is "<<getYear()<<"/";
    cout<<setfill('0')<<setw(2)<<getMonth();
    cout<<"/";
    cout<<setfill('0')<<setw(2)<<getDay()<<endl;

    addOneDay();

    cout<<"Tomorrow is "<<getYear()<<"/";
    cout<<setfill('0')<<setw(2)<<getMonth();
    cout<<"/";
    cout<<setfill('0')<<setw(2)<<getDay()<<endl;
}
void Date::addOneDay() {
    if(getMonth()==2&&getDay()==28){
        //闰年2月份
        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
            this->day++;
        }else{
            this->month++;
            this->day=1;
        }
    } else if((getMonth()==4||getMonth()==6||getMonth()==9||getMonth()==11)&&getDay()==30){
        //30天
        this->month++;
        this->day=1;
    } else if((getMonth()==1||getMonth()==3||getMonth()==5||getMonth()==7||getMonth()==8||getMonth()==10)&&getDay()==31){
        //31天
        this->month++;
        this->day=1;
    } else if(getMonth()==12&&getDay()==31){
        //跨年
        this->year++;
        this->month=1;
        this->day=1;
    } else{
        this->day++;
    }
}

int main(){
    int n,y,m,d;
    bool helper= true;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>y>>m>>d;
        if(helper){
            Date date(y,m,d);
            date.print();
        } else{
            Date date;
            date.setDate(y,m,d);
            date.print();
        }
        helper=!helper;
    }
}
