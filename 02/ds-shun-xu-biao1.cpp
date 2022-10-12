//
// Created by 常贵杰 on 2022/9/1.
//
#include <iostream>
#include <vector>
using namespace std;
void disPlay(vector<int> vec){
    cout<<vec.size()<<" ";
    for (int i = 0; i < vec.size(); ++i) {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> vec;

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        vec.push_back(val);
    }
    disPlay(vec);

    int a, b, c, d, e, f, g, h;
    cin >> a >> b;
    if (vec.size()+1<a||a<=0){
        cout << "error" << endl;
    } else{
        vec.insert(vec.begin()+a-1,b);
        disPlay(vec);
    }


    cin >> c >> d;
    if (vec.size()+1<c||c<=0) {
        cout << "error" << endl;
    } else{
        vec.insert(vec.begin()+c-1,d);
        disPlay(vec);
    }

    //删除
    cin >> e;

    if (vec.size()<e||e<=0)
        cout << "error" << endl;
    else {
        vec.erase(vec.begin()+e-1);
        disPlay(vec);
    }

    //删除
    cin >> f;
    if (vec.size()<f||f<=0) {
        cout << "error" << endl;
    } else {
        vec.erase(vec.begin()+e-1);
        disPlay(vec);
    }

    //查找
    cin >> h;
    if (vec.size()<h||h<=0) {
        cout <<"error"<< endl;
    } else
        cout<<vec[h-1]<<endl;

    //查找
    cin >> g;
    if (vec.size()<g||g<=0)
        cout <<"error"<< endl;
    else
        cout<<vec[g-1]<<endl;
    return 0;
}
