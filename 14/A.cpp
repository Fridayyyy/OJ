#include <iostream>
#include <iomanip>
using namespace std;
const double wuCha=0.00001;

double find(double d){
    double left=0,right=d,temp;
    double mid=(left+right)/2;

    while (left<right){
        temp=mid*mid-d;
        if (abs(temp)<wuCha){
            break;
        } else if (temp<0){
            left=mid;

        } else if (temp>0){
            right=mid;
        }
        mid=(left+right)/2;
    }
    return mid;
}
int main(){
    int t;
    cin>>t;
    while (t--){
        int num;
        cin>>num;
        cout<<setiosflags(ios::fixed)<<setprecision(3)<<find(num)<<endl;
    }
}