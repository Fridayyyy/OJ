//
// Created by ³£¹ó½Ü on 2022/9/8.
//
#include <vector>
#include <iostream>
void reverse(std::vector<int> &vec,int begin,int end){
    while (begin<end){
        int temp = vec[begin];
        vec[begin]=vec[end];
        vec[end]=temp;
        begin++;
        end--;
    }
}

void xunHuan(int type,int offset,std::vector<int> &vec){

    if (type==0){
        int k=vec.size()-offset%vec.size();
        reverse(vec,0,vec.size()-k-1);
        reverse(vec,vec.size()-k,vec.size()-1);
        reverse(vec,0,vec.size()-1);
    } else if (type==1){
        int k=offset%vec.size();
        reverse(vec,0,vec.size()-k-1);
        reverse(vec,vec.size()-k,vec.size()-1);
        reverse(vec,0,vec.size()-1);
    }
}
void display(std::vector<int> vec){
    for (int i = 0; i < vec.size(); ++i) {
        std::cout<<vec[i]<<" ";
    }
    std::cout<<std::endl;
}
int main(){
    int n;
    std::cin>>n;
    std::vector<int> vec;
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin>>val;
        vec.push_back(val);
    }
    display(vec);

    int x1,x2,num1,num2;
    std::cin>>x1>>num1;
    xunHuan(x1,num1,vec);
    display(vec);

    std::cin>>x2>>num2;
    xunHuan(x2,num2,vec);
    display(vec);
}