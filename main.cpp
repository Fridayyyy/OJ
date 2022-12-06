#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

vector<string> search(string str){
    vector<string> vec;
    return vec;
}

//输入输出参数为文档编号的数组
vector<string> And(vector<string> list1,vector<string> list2){
    vector<string> res;
    int i=0,j=0;

    while (i<list1.size() && j<list2.size()){
        if (list1[i]==list2[j]){
            res.push_back(list1[i]);
            i++;
            j++;
        } else if (list1[i]<list2[j]){
            i++;
        } else{
            j++;
        }
    }
    return res;
}

vector<string> Or(vector<string> list1,vector<string> list2){
    int i=0; int j=0;
    vector<string> res;
    while(i<list1.size()&&j<list2.size()){//同时出现，只加入一次
        if(list1[i]==list2[j]){
            res.push_back(list1[i]);
            i++;
            j++;
        }
            //指向较小数的指针后移，加入vector中
        else if(list1[i]<list2[j]){
            res.push_back(list1[i]);
            i++;
        }else{
            res.push_back(list2[j]);
            j++;
        }
    }
    //加入未遍历到的字符
    if(j==list2.size()){
        for(;;i++){
            res.insert(res.end(),list1[i]);
        }
    }else{
        for(;;j++){
            res.insert(res.end(),list2[j]);
        }
    }
}

//将表达式转为字符串数字，比如 word3 OR word1 AND word2 ，就是{“word3”,"OR" …… , “word2”}
//输出参数为文档编号的数组
//逆波兰式
queue<string> RPN(vector<string> str){
    //stk1为运算符，stk2为逆波兰式的存放栈
    stack<string> stk;
    queue<string> que;
    for (auto temp : str) {
        //如果是运算符号
        if (temp=="OR" || temp=="AND" || temp=="("){
            stk.push(temp);
        } else if (temp==")"){
            //直到找到（符号
            while (!stk.empty()){
                string a=stk.top();
                stk.pop();
                if (a=="("){
                    break;
                }
                que.push(a);
            }
        } else{
            que.push(temp);
        }
    }
    //将stk1中剩余的符号加入stk2
    while (!stk.empty()){
        string temp=stk.top();
        stk.pop();
        que.push(temp);
    }


    while (!que.empty()){
        cout<<que.front()<<" ";
        que.pop();
    }

    return que;
}
//计算波兰式
vector<string> getRPN(queue<string> que){

    stack<vector<string>> stk3;

    //按照逆波兰式进行运算
    while (!que.empty()){
        //运算stk2的辅助栈

        string temp=que.front();
        que.pop();
        if (temp=="AND" || temp=="OR"){
            //将stk3上面的两个取出；
            vector<string> vec1=stk3.top();
            stk3.top();
            vector<string> vec2=stk3.top();
            stk3.top();

            if (temp=="AND") {
                stk3.push(And(vec1,vec2));
            } else{
                stk3.push(Or(vec1,vec2));
            }
        }else{
            //将搜索的结果放进stack
            stk3.push(search(temp));
        }
    }
    return stk3.top();
}

int main(){
    vector<string> vec={"word3","OR","(","word1","AND","word2",")","OR","word5","AND","word6"};
    //得到逆波兰式
    auto temp=RPN(vec);
    //解析逆波兰式
    getRPN(temp);
}


