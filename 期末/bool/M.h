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

//最后输出的结果
class Res{
public:
    int doc;//第几个文档
    int pos;//第一个出现的位置
    Res(){
        doc=0;
        pos=0;
    }
    Res(int d,int p){
        doc=d;
        pos=p;
    }

};


class DocMes {//储存文件信息的类
public:
    int TF = 0;      //词频
    string pos = "";     //在文档出现的 所有 位置
    vector<string> ans;//前后字符
};

/*模板类的类型定义方法:
  typedef map<int,CString> UDT_MAP_INT_CSTRING;
  UDT_MAP_INT_CSTRING enumMap;*/
typedef map<string, map<int, DocMes>> IndexMap;//定义multiMap类型
typedef map<int, DocMes> invertMap;//倒排列表



class M{
    IndexMap index;
public:
    //把int转为String(便于拼接存储在DocMes的pos变量中)
    string IntToString(int a) {
        string res;
        stringstream ss;
        ss << a;
        ss >> res;
        return res;
    }

//寻找a对应的文件名
    string FindTxtName(int a) {
        return DocList[a];
    }

    //建表
    void CreateIndex() {
        ifstream fileIn;
        for (int i = 1;i <= 10;i++) {
            string filepath = "C:\\Users\\Administrator\\Desktop\\1.InvertIndexes(2)\\"+FindTxtName(i) + ".txt";//文件名拼接
            fileIn.open(filepath); //读文件 (c中为：fileIn.open(filepath.c_str())将string转为c中字符串格式)
            string temp;//记录每一个目标词
            int posNum = 0;//记录单词出现的位置
            while (fileIn >> temp) {//每次取filepath文件的（一行？）的值
                posNum++;

                index[temp][i].TF++;//multiMap类型的体现 i表示该temp值对应的第i个DocMes，意为遍历到字符串temp时 第i个文件temp的频数+1
                //index[temp][i].pos += IntToString(posNum) + " ";//遍历到temp时 利用IntToString()函数把单词出现的位置posNum转化为string类型 加逗号后拼接至DocMes的pos中
                if (index[temp][i].pos.empty()){
                    index[temp][i].pos += IntToString(posNum) + " ";
                }
                if (index[temp][i].ans.empty()){
                    index[temp][i].ans.push_back(IntToString(posNum));
                }
                /*
                一个for循环代表遍历 一个文件
                index是multiMap类型,在一次while循环中，temp是键，DocMes是值，负责存储temp在 该次for循环的文件中 出现的频数和出现的位置
                因此一个键temp对应多个DocMes值 第i个值存储第i个文件中temp的词频和位置
                */
            }
            fileIn.close();
        }
    }

//查找位置并输出结果
    vector<Res> queryProcess(string query) {

        vector<Res> vec;

        if (index.find(query) == index.end()) {//未找到输入的元素query
            return vec;
            //cout << "ERROR: Can't find " << query << " ! ,please check up your words" << endl;
        }

        invertMap::iterator it;
        it = index[query].begin();
        while (it != index[query].end()) {
            string firstPos;
            //获取第一个pos
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
