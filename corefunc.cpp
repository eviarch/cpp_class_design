//
// Created by eviarch on 2023/12/7.
//

#include "corefunc.h"
#include "Student.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

extern string store_content[3];

//存储实例
vector<string> temp_prim;
vector<string> temp_high;
vector<string> temp_col;
extern int prim_num;
extern int high_num;
extern int col_num;

void delay(int time)
{
    clock_t  now = clock();
    while(clock() - now < time);
}

//文件写入操作
void writefile(long long ID, const string &Name, const string &Sex, int Age, const string &Class, int english_grade, int math_grade, int chinese_grade) {
    ofstream ofs;
    ofs.open(store_content[0],ios::out|ios::app);
    ofs<<"ID:"<<ID<<' '<<"Name:"<<Name<<' '<<"Sex:"<<Sex<<' '<<"Age:"<<Age<<' '<<"Class:"<<Class<<' '
       <<"english_grade:"<<english_grade<<' '<<"math_grade:"<<math_grade<<' '<<"chinese_grade:"<<chinese_grade<<endl;
    ofs.close();
}
void writefile(long long ID, const string &Name, const string& Sex,int Age,const string& Class,
               int english_grade,int math_grade,int chinese_grade,int geography_grade,int history_grade){
    ofstream ofs;
    ofs.open(store_content[1],ios::out|ios::app);
    ofs<<"ID:"<<ID<<' '<<"Name:"<<Name<<' '<<"Sex:"<<Sex<<' '<<"Age:"<<Age<<' '<<"Class:"<<Class<<' '
       <<"english_grade:"<<english_grade<<' '<<"math_grade:"<<math_grade<<' '<<"chinese_grade:"<<chinese_grade
       <<' '<<"geography_grade:"<<geography_grade<<' '<<"history_grade:"<<history_grade<<endl;
    ofs.close();
}
void writefile(long long ID, const string &Name, const string& Sex,int Age,const string& Class,
               int profession_grade,int pro_eng_grade,int program_design_grade,int pro_math_grade){
    ofstream ofs;
    ofs.open(store_content[2],ios::out|ios::app);
    ofs<<"ID:"<<ID<<' '<<"Name:"<<Name<<' '<<"Sex:"<<Sex<<' '<<"Age:"<<Age<<' '<<"Class:"<<Class<<' '
       <<"profession_grade:"<<profession_grade<<' '<<"pro_eng_grade:"<<pro_eng_grade<<' '<<"program_design_grade:"<<program_design_grade<<' '<<"pro_math_grade:"<<pro_math_grade<<endl;
    ofs.close();
}

//文件读取操作
bool checkfile(const string &filename){
    int check = 0;
    for (int i = 0; i < 3; ++i) {   //检查文件名是否正确
        if(filename == store_content[i]){
            check++;
        }
    }
    if(check == 0){
        cout<<"incorrect filename!"<<endl;
        return false;
    }

    ifstream ifs;
    ifs.open(filename,ios::in);

    if(!ifs.is_open()){     //检测文件是否存在
        cout<<"The file have not created yet!"<<endl;
        ifs.close();
        return false;
    }
    char ch;
    ifs >> ch;
    if(ifs.eof()){      //检查文件是否为空
        cout<<"The file is empty!"<<endl;
        ifs.close();
        return false;
    }
    ifs.close();
    return true;
}
vector<string> readfile (const string &filename){
    if(!checkfile(filename)){
        cout<<"file check failed!"<<endl;
        vector<string> error;
        return error;
    }
    ifstream ifs;
    ifs.open(filename,ios::in);
    string buf;
    vector<string> temp;
    while (getline(ifs,buf)){
        temp.push_back(buf);
    }
    ifs.close();
    return temp;
}

//删除文件操作
int delete_file(){
    cout<<"choose the file(s) you need to delete"<<endl;
    cout<<"1. primary_student.txt"<<endl;
    cout<<"2. high_student.txt"<<endl;
    cout<<"3. college_student.txt"<<endl;
    cout<<"4. All"<<endl;
    cout<<"0. Go back to the previous level"<<endl;
    int select;
    cin>>select;
    if (select == 0) {
        return 0;
    }
    if (select<0 || select>4){
        cout << "错误的序号范围！" << endl;
        system("pause");
        system("cls");
        return delete_file();
    }
    switch (select) {
        case 1:
            remvfile(store_content[0]);
            vector <primary_student>().swap(prim_stu);
            prim_num = 0;
            break;
        case 2:
            remvfile(store_content[1]);
            vector <high_student>().swap(high_stu);
            high_num = 0;
            break;
        case 3:
            remvfile(store_content[2]);
            vector <college_student>().swap(col_stu);
            col_num = 0;
            break;
        case 4:
            remvfile(store_content[0]);
            vector <primary_student>().swap(prim_stu);
            prim_num = 0;
            remvfile(store_content[1]);
            vector <high_student>().swap(high_stu);
            high_num = 0;
            remvfile(store_content[2]);
            vector <college_student>().swap(col_stu);
            col_num = 0;
            break;
        default:
            break;
    }
    return select;
}
void remvfile(const string &filename){
    remove(filename.c_str());
}
void load_prim_file(){
    if(!checkfile()){      //load prim_stu
        cout<<"file check failed!"<<endl;
        vector<string> error;
        return;
    }

    temp_prim = readfile(store_content[0]);
    for (int i = 0; i < temp_prim.size(); ++i) {
        string sID, sName, sSex, sAge, sCLass, s_english_grade, s_math_grade, s_chinese_grade;
        long long iID;
        int iAge,iEng,iMAth,iChi;
        string temp = temp_prim.at(i);
        int a = 0;
        while (temp[temp.find("ID:")+3+a] != ' ') {
            sID = sID + temp[temp.find("ID:") + 3 + a];
            a++;
        }
        iID = atoll(sID.c_str());
        a = 0;
        while (temp[temp.find("Name:")+5+a] != ' ') {
            sName = sName + temp[temp.find("Name:") + 5 + a];
            a++;
        }
        a = 0;
        while (temp[temp.find("Sex:")+4+a] != ' ') {
            sSex = sSex + temp[temp.find("Sex:") + 4 + a];
            a++;
        }
        a = 0;
        while (temp[temp.find("Age:")+4+a] != ' ') {
            sAge = sAge + temp[temp.find("Age:") + 4 + a];
            a++;
        }
        iAge = atoi(sAge.c_str());
        a = 0;
        while (temp[temp.find("Class:")+6+a] != ' ') {
            sCLass = sCLass + temp[temp.find("Class:") + 6 + a];
            a++;
        }
        a = 0;
        while (temp[temp.find("english_grade:")+14+a] != ' ') {
            s_english_grade = s_english_grade + temp[temp.find("english_grade:") + 14 + a];
            a++;
        }
        iEng = atoi(s_english_grade.c_str());
        a = 0;
        while (temp[temp.find("math_grade:")+11+a] != ' ') {
            s_math_grade = s_math_grade + temp[temp.find("math_grade:") + 11 + a];
            a++;
        }
        iMAth = atoi(s_math_grade.c_str());
        a = 0;
        while (temp[temp.find("chinese_grade:")+14+a] != ' ') {
            s_chinese_grade = s_chinese_grade + temp[temp.find("chinese_grade:") + 14 + a];
            a++;
        }
        iChi = atoi(s_chinese_grade.c_str());
        primary_student *p_new_prim = new primary_student(iID,sName,sSex,iAge,sCLass,iEng,iMAth,iChi);
        prim_stu.push_back(*p_new_prim);
        prim_num++;
        delete p_new_prim;
    }
//    for (int i = 0; i < prim_stu.size(); ++i) {
//        prim_stu.at(i).display_info();
//    }
}
void load_high_file(){
    if(!checkfile(store_content[1])){      //load high_stu
        cout<<"file check failed!"<<endl;
        vector<string> error;
        return;
    }
    temp_high = readfile(store_content[1]);
    for (int i = 0; i < temp_high.size(); ++i) {
        string sID, sName, sSex, sAge, sCLass, s_english_grade, s_math_grade, s_chinese_grade , s_geography_grade , s_history_grade;
        long long iID;
        int iAge,iEng,iMAth,iChi,iGeo,iHis;
        string temp = temp_high.at(i);
        int a = 0;
        while (temp[temp.find("ID:")+3+a] != ' ') {
            sID = sID + temp[temp.find("ID:") + 3 + a];
            a++;
        }
        iID = atoll(sID.c_str());
        a = 0;
        while (temp[temp.find("Name:")+5+a] != ' ') {
            sName = sName + temp[temp.find("Name:") + 5 + a];
            a++;
        }
        a = 0;
        while (temp[temp.find("Sex:")+4+a] != ' ') {
            sSex = sSex + temp[temp.find("Sex:") + 4 + a];
            a++;
        }
        a = 0;
        while (temp[temp.find("Age:")+4+a] != ' ') {
            sAge = sAge + temp[temp.find("Age:") + 4 + a];
            a++;
        }
        iAge = atoi(sAge.c_str());
        a = 0;
        while (temp[temp.find("Class:")+6+a] != ' ') {
            sCLass = sCLass + temp[temp.find("Class:") + 6 + a];
            a++;
        }
        a = 0;
        while (temp[temp.find("english_grade:")+14+a] != ' ') {
            s_english_grade = s_english_grade + temp[temp.find("english_grade:") + 14 + a];
            a++;
        }
        iEng = atoi(s_english_grade.c_str());
        a = 0;
        while (temp[temp.find("math_grade:")+11+a] != ' ') {
            s_math_grade = s_math_grade + temp[temp.find("math_grade:") + 11 + a];
            a++;
        }
        iMAth = atoi(s_math_grade.c_str());
        a = 0;
        while (temp[temp.find("chinese_grade:")+14+a] != ' ') {
            s_chinese_grade = s_chinese_grade + temp[temp.find("chinese_grade:") + 14 + a];
            a++;
        }
        iChi = atoi(s_chinese_grade.c_str());
        a = 0;
        while (temp[temp.find("geography_grade:")+16+a] != ' ') {
            s_geography_grade = s_geography_grade + temp[temp.find("geography_grade:") + 16 + a];
            a++;
        }
        iGeo = atoi(s_geography_grade.c_str());
        a = 0;
        while (temp[temp.find("history_grade:")+14+a] != ' ') {
            s_history_grade = s_history_grade + temp[temp.find("history_grade:") + 14 + a];
            a++;
        }
        iHis = atoi(s_history_grade.c_str());
        high_student *p_new_high = new high_student(iID,sName,sSex,iAge,sCLass,iEng,iMAth,iChi,iGeo,iHis);
        high_stu.push_back(*p_new_high);
        high_num++;
        delete p_new_high;
    }
//    for (int i = 0; i < prim_stu.size(); ++i) {
//        high_stu.at(i).display_info();
//    }
}
void load_col_file(){
    if(!checkfile(store_content[2])){      //load college_stu
        cout<<"file check failed!"<<endl;
        vector<string> error;
        return;
    }
    temp_col = readfile(store_content[2]);
    for (int i = 0; i < temp_col.size(); ++i) {
        string sID, sName, sSex, sAge, sCLass, s_profession_grade, s_pro_eng_grade, s_program_design_grade, s_pro_math_grade;
        long long iID;
        int iAge,iPro,iEng,iDes,iMath;
        string temp = temp_col.at(i);
        int a = 0;
        while (temp[temp.find("ID:")+3+a] != ' ') {
            sID = sID + temp[temp.find("ID:") + 3 + a];
            a++;
        }
        iID = atoll(sID.c_str());
        a = 0;
        while (temp[temp.find("Name:")+5+a] != ' ') {
            sName = sName + temp[temp.find("Name:") + 5 + a];
            a++;
        }
        a = 0;
        while (temp[temp.find("Sex:")+4+a] != ' ') {
            sSex = sSex + temp[temp.find("Sex:") + 4 + a];
            a++;
        }
        a = 0;
        while (temp[temp.find("Age:")+4+a] != ' ') {
            sAge = sAge + temp[temp.find("Age:") + 4 + a];
            a++;
        }
        iAge = atoi(sAge.c_str());
        a = 0;
        while (temp[temp.find("Class:")+6+a] != ' ') {
            sCLass = sCLass + temp[temp.find("Class:") + 6 + a];
            a++;
        }
        a = 0;
        while (temp[temp.find("profession_grade:")+17+a] != ' ') {
            s_profession_grade = s_profession_grade + temp[temp.find("profession_grade:") + 17 + a];
            a++;
        }
        iPro = atoi(s_profession_grade.c_str());
        a = 0;
        while (temp[temp.find("pro_eng_grade:")+14+a] != ' ') {
            s_pro_eng_grade = s_pro_eng_grade + temp[temp.find("pro_eng_grade:") + 14 + a];
            a++;
        }
        iEng = atoi(s_pro_eng_grade.c_str());
        a = 0;
        while (temp[temp.find("program_design_grade:")+21+a] != ' ') {
            s_program_design_grade = s_program_design_grade + temp[temp.find("program_design_grade:") + 21 + a];
            a++;
        }
        iDes = atoi(s_program_design_grade.c_str());
        a = 0;
        while (temp[temp.find("pro_math_grade:")+15+a] != ' ') {
            s_pro_math_grade = s_pro_math_grade + temp[temp.find("pro_math_grade:") + 15 + a];
            a++;
        }
        iMath = atoi(s_pro_math_grade.c_str());

        college_student *p_new_col = new college_student(iID,sName,sSex,iAge,sCLass,iPro,iEng,iDes,iMath);
        col_stu.push_back(*p_new_col);
        col_num++;
        delete p_new_col;
    }
//    for (int i = 0; i < prim_stu.size(); ++i) {
//        col_stu.at(i).display_info();
//    }
}