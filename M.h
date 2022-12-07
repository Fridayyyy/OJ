#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <iostream>
#include <map>
#include <fstream>
#include <map>
#include <sstream>

using namespace std;

#ifndef A_CPP_M_H
#define A_CPP_M_H

string DocList[11] = { " ","apple","cherry","grape","mangosteen","orange","peach","pear","pineapple","pomelo","watermelon" };

//�������Ľ��
class Res{
public:
    int doc;//�ڼ����ĵ�
    int pos;//��һ�����ֵ�λ��
    Res(){
        doc=0;
        pos=0;
    }
    Res(int d,int p){
        doc=d;
        pos=p;
    }

};


class DocMes {//�����ļ���Ϣ����
public:
    int TF = 0;      //��Ƶ
    string pos = "";     //���ĵ����ֵ� ���� λ��
    vector<string> ans;//ǰ���ַ�
};

/*ģ��������Ͷ��巽��:
  typedef map<int,CString> UDT_MAP_INT_CSTRING;
  UDT_MAP_INT_CSTRING enumMap;*/
typedef map<string, map<int, DocMes>> IndexMap;//����multiMap����
typedef map<int, DocMes> invertMap;//�����б�



class M{
    IndexMap index;
public:
    //��intתΪString(����ƴ�Ӵ洢��DocMes��pos������)
    string IntToString(int a) {
        string res;
        stringstream ss;
        ss << a;
        ss >> res;
        return res;
    }

//Ѱ��a��Ӧ���ļ���
    string FindTxtName(int a) {
        return DocList[a];
    }

    //����
    void CreateIndex() {
        ifstream fileIn;
        for (int i = 1;i <= 10;i++) {
            string filepath = "C:\\Users\\Administrator\\Desktop\\1.InvertIndexes(2)\\"+FindTxtName(i) + ".txt";//�ļ���ƴ��
            fileIn.open(filepath); //���ļ� (c��Ϊ��fileIn.open(filepath.c_str())��stringתΪc���ַ�����ʽ)
            string temp;//��¼ÿһ��Ŀ���
            int posNum = 0;//��¼���ʳ��ֵ�λ��
            while (fileIn >> temp) {//ÿ��ȡfilepath�ļ��ģ�һ�У�����ֵ
                posNum++;

                index[temp][i].TF++;//multiMap���͵����� i��ʾ��tempֵ��Ӧ�ĵ�i��DocMes����Ϊ�������ַ���tempʱ ��i���ļ�temp��Ƶ��+1
                //index[temp][i].pos += IntToString(posNum) + " ";//������tempʱ ����IntToString()�����ѵ��ʳ��ֵ�λ��posNumת��Ϊstring���� �Ӷ��ź�ƴ����DocMes��pos��
                if (index[temp][i].pos.empty()){
                    index[temp][i].pos += IntToString(posNum) + " ";
                }
                if (index[temp][i].ans.empty()){
                    index[temp][i].ans.push_back(IntToString(posNum));
                }
                /*
                һ��forѭ��������� һ���ļ�
                index��multiMap����,��һ��whileѭ���У�temp�Ǽ���DocMes��ֵ������洢temp�� �ô�forѭ�����ļ��� ���ֵ�Ƶ���ͳ��ֵ�λ��
                ���һ����temp��Ӧ���DocMesֵ ��i��ֵ�洢��i���ļ���temp�Ĵ�Ƶ��λ��
                */
            }
            fileIn.close();
        }
    }

//����λ�ò�������
    vector<Res> queryProcess(string query) {

        vector<Res> vec;

        if (index.find(query) == index.end()) {//δ�ҵ������Ԫ��query
            return vec;
            //cout << "ERROR: Can't find " << query << " ! ,please check up your words" << endl;
        }

        invertMap::iterator it;
        it = index[query].begin();
        while (it != index[query].end()) {
            string firstPos;
            //��ȡ��һ��pos
            for (int i = 0; i < it->second.pos.size(); ++i) {
                char ch=it->second.pos[i];
                if (ch==' '){
                    break;
                } else{
                    firstPos.push_back(ch);
                }
            }
            size_t iPos{};
            int p=stoi(firstPos, &iPos);


            vec.emplace_back(Res(it->first,p));
            //cout <<it->first <<"-" << FindTxtName(it->first) << ".txt : TF=" << it->second.TF << " ; pos = [" << it->second.pos <<"]" << endl;
            it++;
        }

        return vec;
    }

};


#endif //A_CPP_M_H
