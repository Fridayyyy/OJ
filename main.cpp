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

//�����������Ϊ�ĵ���ŵ�����
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
    while(i<list1.size()&&j<list2.size()){//ͬʱ���֣�ֻ����һ��
        if(list1[i]==list2[j]){
            res.push_back(list1[i]);
            i++;
            j++;
        }
            //ָ���С����ָ����ƣ�����vector��
        else if(list1[i]<list2[j]){
            res.push_back(list1[i]);
            i++;
        }else{
            res.push_back(list2[j]);
            j++;
        }
    }
    //����δ���������ַ�
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

//�����ʽתΪ�ַ������֣����� word3 OR word1 AND word2 ������{��word3��,"OR" ���� , ��word2��}
//�������Ϊ�ĵ���ŵ�����
//�沨��ʽ
queue<string> RPN(vector<string> str){
    //stk1Ϊ�������stk2Ϊ�沨��ʽ�Ĵ��ջ
    stack<string> stk;
    queue<string> que;
    for (auto temp : str) {
        //������������
        if (temp=="OR" || temp=="AND" || temp=="("){
            stk.push(temp);
        } else if (temp==")"){
            //ֱ���ҵ�������
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
    //��stk1��ʣ��ķ��ż���stk2
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
//���㲨��ʽ
vector<string> getRPN(queue<string> que){

    stack<vector<string>> stk3;

    //�����沨��ʽ��������
    while (!que.empty()){
        //����stk2�ĸ���ջ

        string temp=que.front();
        que.pop();
        if (temp=="AND" || temp=="OR"){
            //��stk3���������ȡ����
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
            //�������Ľ���Ž�stack
            stk3.push(search(temp));
        }
    }
    return stk3.top();
}

int main(){
    vector<string> vec={"word3","OR","(","word1","AND","word2",")","OR","word5","AND","word6"};
    //�õ��沨��ʽ
    auto temp=RPN(vec);
    //�����沨��ʽ
    getRPN(temp);
}


