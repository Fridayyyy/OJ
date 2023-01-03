#include "M.h";

using namespace std;

class BE{
    M m;
public:
    BE(){
        m.CreateIndex();
    }

    //������������
    vector<Res> search(string str){
        return m.queryProcess(str);
    }

    //����������ַ���
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

//�����������Ϊ�ĵ���ŵ�����
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
        while(i<list1.size() && j<list2.size()){//ͬʱ���֣�ֻ����һ��
            if(list1[i].doc==list2[j].doc){
                res.push_back(list1[i]);
                i++;
                j++;
            }
                //ָ���С����ָ����ƣ�����vector��
            else if(list1[i].doc<list2[j].doc){
                res.push_back(list1[i]);
                i++;
            }else{
                res.push_back(list2[j]);
                j++;
            }
        }
        //����δ���������ַ�

        for (; i < list1.size(); ++i) {
            res.push_back(list1[i]);
        }
        for (; j < list2.size(); ++j) {
            res.push_back(list2[j]);
        }
        return res;
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

        return que;
    }
//���㲨��ʽ
    vector<Res> getRPN(queue<string> que){

        stack<vector<Res>> stk3;

        //�����沨��ʽ��������
        while (!que.empty()){
            //����stk2�ĸ���ջ

            string temp=que.front();
            que.pop();
            if (temp=="AND" || temp=="OR"){
                //��stk3���������ȡ����
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
                //�������Ľ���Ž�stack
                auto s=search(temp);
//                for (int i = 0; i < s.size(); ++i) {
//                    cout<<s[i].first<<" "<<s[i].second<<endl;
//                }
                stk3.push(s);
            }
        }
        return stk3.top();
    }

    //���ǰ��4�ַ�
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
            //�����沨��ʽ
            res=be.getRPN(temp);
        }
        //�õ��沨��ʽ

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


