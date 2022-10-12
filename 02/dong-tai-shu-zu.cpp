//
// Created by 常贵杰 on 2022/8/31.
//
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        char type;
        int counts;

        priority_queue<char> queue;
        int sum=0;
        float minNum=999.9;

        cin>>type;
        switch (type) {
            case 'C':
                cin>>counts;

                for (int j = 0; j < counts; ++j) {
                    char c;
                    cin>>c;
                    queue.push(c);
                }
                cout<<queue.top()<<endl;
                break;
            case 'I':
                cin>>counts;
                for (int j = 0; j < counts; ++j) {
                    int num;
                    cin>>num;
                    sum+=num;
                }
                cout<<sum/counts<<endl;
                break;
            case 'F':
                cin>>counts;
                for (int j = 0; j < counts; ++j) {
                    float flt;
                    cin>>flt;
                    minNum=min(flt,minNum);
                }
                cout<<minNum<<endl;
                break;
            default:
                break;
        }
    }
}