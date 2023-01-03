#include "M.h";

using namespace std;

class BE{
    M m;
public:
    BE(){
        m.CreateIndex();
    }

    //构建的索引表
    vector<Res> search(string str){
        return m.queryProcess(str);
    }

    //处理输入的字符串
    vector<string> parseLine(string str){
        vector<string> res;
        string temp;
        for (int i = 0; i < str.size(); ++i) {
            char ch=str.at(i);
            if (ch=='('||ch==')'){
                if (!temp.empty()){
                    res.push_back(temp);
                    temp.clear();
                }
                temp.push_back(ch);
                res.push_back(temp);
                temp.clear();
            }
            if (ch==' '){
                res.push_back(temp);
                temp.clear();
            } else{
                temp.push_back(ch);
            }
        }
        res.push_back(temp);
        return res;
    }

//输入输出参数为文档编号的数组
    vector<Res> And(vector<Res> list1,vector<Res> list2){
        vector<Res> res;
        int i=0,j=0;

        while (i<list1.size() && j<list2.size()){
            if (list1[i].doc==list2[j].doc){
                res.push_back(list1[i]);
                i++;
                j++;
            } else if (list1[i].doc<list2[j].doc){
                i++;
            } else{
                j++;
            }
        }
        return res;
    }

    vector<Res> Or(vector<Res> list1,vector<Res> list2){
        int i=0; int j=0;
        vector<Res> res;
        while(i<list1.size() && j<list2.size()){//同时出现，只加入一次
            if(list1[i].doc==list2[j].doc){
                res.push_back(list1[i]);
                i++;
                j++;
            }
                //指向较小数的指针后移，加入vector中
            else if(list1[i].doc<list2[j].doc){
                res.push_back(list1[i]);
                i++;
            }else{
                res.push_back(list2[j]);
                j++;
            }
        }
        //加入未遍历到的字符

        for (; i < list1.size(); ++i) {
            res.push_back(list1[i]);
        }
        for (; j < list2.size(); ++j) {
            res.push_back(list2[j]);
        }
        return res;
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

        return que;
    }
//计算波兰式
    vector<Res> getRPN(queue<string> que){

        stack<vector<Res>> stk3;

        //按照逆波兰式进行运算
        while (!que.empty()){
            //运算stk2的辅助栈

            string temp=que.front();
            que.pop();
            if (temp=="AND" || temp=="OR"){
                //将stk3上面的两个取出；
                auto vec1=stk3.top();
                stk3.pop();
                auto vec2=stk3.top();
                stk3.pop();

                if (temp=="AND") {
                    stk3.push(And(vec1,vec2));
                } else{
                    stk3.push(Or(vec1,vec2));
                }
            }else{
                //将搜索的结果放进stack
                auto s=search(temp);
//                for (int i = 0; i < s.size(); ++i) {
//                    cout<<s[i].first<<" "<<s[i].second<<endl;
//                }
                stk3.push(s);
            }
        }
        return stk3.top();
    }

    //输出前后4字符
//    string parseOUt(int doc,int pos){
//        string res;
//        ifstream fileIn;
//        string filepath = "C:\\Users\\Administrator\\Desktop\\1.InvertIndexes(2)\\"+m.FindTxtName(doc) + ".txt";
//        fileIn.open(filepath);
//
//
//
//        for (int i = 0; i < 8; ++i) {
//            fileIn.seekg(pos-4+i,ios::beg);
//            char ch;
//            fileIn>>ch;
//            res.push_back(ch);
//        }
//        return res;
//
//    }


};

int main(){
    //vector<string> vec={"word3","OR","(","word1","AND","word2",")","OR","word5","AND","word6"};
    vector<string> vec1={"apple","OR","banana"};
    BE be;

    while (true){
        string line;
        getline(cin,line);

        if (line=="exit")
            break;
//        auto temp=be.parseLine(line);
//        for (int i = 0; i < temp.size(); ++i) {
//            cout<<temp[i]<<"-";
//        }
//        cout<<endl;
        vector<Res> res;
        auto s=be.parseLine(line);
        if (s.size()==1){

            res= be.search(s[0]);

        } else{
            auto temp=be.RPN(s);
            //解析逆波兰式
            res=be.getRPN(temp);
        }
        //得到逆波兰式

        if (res.size()==0){
            cout<<"no result"<<endl;
        } else{
            for (int i = 0; i < res.size(); ++i) {
                //<<" "<<be.parseOUt(res[i].doc,res[i].pos)
                cout<<res[i].doc<<"-"<<DocList[res[i].doc]<<endl;
            }
        }

    }

}


