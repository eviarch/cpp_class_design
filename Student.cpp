//
// Created by eviarch on 2023/12/5.
//
#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"
#include "corefunc.h"
using namespace std;


extern string store_content[3];
vector<primary_student> prim_stu;
vector<high_student> high_stu;
vector<college_student> col_stu;

//求和函数，用于求总分
template<typename... T>
auto sum_score(T... s){
    return (... + s);
}

//构造函数重载
primary_student::primary_student (long long iID, string sName, string sSex, int iAge, string sCLass, int iEng, int iMath, int iChi) {
    ID = iID;
    Name = sName;
    Sex = sSex;
    Age = iAge;
    Class = sCLass;
    english_grade = iEng;
    math_grade = iMath;
    chinese_grade = iChi;
}
high_student::high_student(long long iID, string sName, string sSex, int iAge, string sCLass, int iEng, int iMath, int iChi, int iGeo, int iHis) {
    ID = iID;
    Name = sName;
    Sex = sSex;
    Age = iAge;
    Class = sCLass;
    english_grade = iEng;
    math_grade = iMath;
    chinese_grade = iChi;
    geography_grade = iGeo;
    history_grade = iHis;
}
college_student::college_student(long long iID, string sName, string sSex, int iAge, string sCLass, int iPro, int iEng, int iDes, int iMath){
    ID = iID;
    Name = sName;
    Sex = sSex;
    Age = iAge;
    Class = sCLass;
    profession_grade = iPro;
    pro_eng_grade = iEng;
    program_design_grade = iDes;
    pro_math_grade = iMath;
}

//集成了写文件函数的添加函数
void primary_student::add_func() {
    cout<<"请依次输入：学号、姓名、性别、年龄、班级、英语成绩、数学成绩、语文成绩"<<endl;
    long long p_ID;
    string p_Name;
    string p_Sex;
    int p_Age;
    string p_Class;
    int p_english_grade,p_math_grade,p_chinese_grade;

    cin>>p_ID>>p_Name>>p_Sex>>p_Age>>p_Class
    >>p_english_grade>>p_math_grade>>p_chinese_grade;

    writefile(p_ID, p_Name, p_Sex, p_Age, p_Class, p_english_grade, p_math_grade, p_chinese_grade);
}
void high_student::add_func() {
    cout<<"请依次输入：学号、姓名、性别、年龄、班级、英语成绩、数学成绩、语文成绩、地理成绩、历史成绩"<<endl;
    long long p_ID;
    string p_Name;
    string p_Sex;
    int p_Age;
    string p_Class;
    int p_english_grade,p_math_grade,p_chinese_grade,p_geography_grade,p_history_grade;
    cin>>p_ID>>p_Name>>p_Sex>>p_Age>>p_Class
       >>p_english_grade>>p_math_grade>>p_chinese_grade>>p_geography_grade>>p_history_grade;

    writefile(p_ID, p_Name, p_Sex, p_Age, p_Class,
              p_english_grade, p_math_grade, p_chinese_grade, p_geography_grade, p_history_grade);
}
void college_student::add_func() {
    cout<<"请依次输入：学号、姓名、性别、年龄、班级、专业成绩、大英成绩、课设成绩、高数成绩"<<endl;
    long long p_ID;
    string p_Name;
    string p_Sex;
    int p_Age;
    string p_Class;
    int p_profession_grade,p_pro_eng_grade,p_program_design_grade,p_pro_math_grade;
    cin>>p_ID>>p_Name>>p_Sex>>p_Age>>p_Class
       >>p_profession_grade>>p_pro_eng_grade>>p_program_design_grade>>p_pro_math_grade;

    writefile(p_ID, p_Name, p_Sex, p_Age, p_Class,
              p_profession_grade, p_pro_eng_grade, p_program_design_grade, p_pro_math_grade);
}

//显示成员值的函数
void primary_student::display_info() {
    cout<<"ID:"<<ID<<' '<<"Name:"<<Name<<' '<<"Sex:"<<Sex<<' '<<"Age:"<<Age<<' '<<"Class:"<<Class<<' '
    <<"english_grade:"<<english_grade<<' '<<"math_grade:"<<math_grade<<' '<<"chinese_grade:"<<chinese_grade<<endl;
}
void high_student::display_info() {
    cout<<"ID:"<<ID<<' '<<"Name:"<<Name<<' '<<"Sex:"<<Sex<<' '<<"Age:"<<Age<<' '<<"Class:"<<Class<<' '
    <<"english_grade:"<<english_grade<<' '<<"math_grade:"<<math_grade<<' '<<"chinese_grade:"<<chinese_grade<<' '
    <<"geography_grade:"<<geography_grade<<' '<<"history_grade"<<history_grade<<endl;
}
void college_student::display_info() {
    cout<<"ID:"<<ID<<' '<<"Name:"<<Name<<' '<<"Sex:"<<Sex<<' '<<"Age:"<<Age<<' '<<"Class:"<<Class<<' '
    <<"profession_grade:"<<profession_grade<<' '<<"pro_eng_grade:"<<pro_eng_grade<<' '<<"program_design_grade:"<<program_design_grade<<' '
    <<"pro_math_grade:"<<pro_math_grade<<endl;
}

//获取总分(使用不定参数函数模板)
int primary_student::getscore() {
    return sum_score(english_grade, chinese_grade, math_grade);
}
int high_student::getscore() {
    return sum_score(english_grade, chinese_grade, math_grade, geography_grade, history_grade);
}
int college_student::getscore() {
    return sum_score(profession_grade, pro_eng_grade, program_design_grade, pro_math_grade);
}

//将成员的值写入文件中
void primary_student::write_to_file() {
    ofstream ofs;
    ofs.open(store_content[0],ios::out|ios::app);
    ofs<<"ID:"<<ID<<' '<<"Name:"<<Name<<' '<<"Sex:"<<Sex<<' '<<"Age:"<<Age<<' '<<"Class:"<<Class<<' '
       <<"english_grade:"<<english_grade<<' '<<"math_grade:"<<math_grade<<' '<<"chinese_grade:"<<chinese_grade<<endl;
    ofs.close();
}
void high_student::write_to_file() {
    ofstream ofs;
    ofs.open(store_content[1],ios::out|ios::app);
    ofs<<"ID:"<<ID<<' '<<"Name:"<<Name<<' '<<"Sex:"<<Sex<<' '<<"Age:"<<Age<<' '<<"Class:"<<Class<<' '
       <<"english_grade:"<<english_grade<<' '<<"math_grade:"<<math_grade<<' '<<"chinese_grade:"<<chinese_grade
       <<' '<<"geography_grade:"<<geography_grade<<' '<<"history_grade:"<<history_grade<<endl;
}
void college_student::write_to_file() {
    ofstream ofs;
    ofs.open(store_content[2],ios::out|ios::app);
    ofs<<"ID:"<<ID<<' '<<"Name:"<<Name<<' '<<"Sex:"<<Sex<<' '<<"Age:"<<Age<<' '<<"Class:"<<Class<<' '
       <<"profession_grade:"<<profession_grade<<' '<<"pro_eng_grade:"<<pro_eng_grade<<' '<<"program_design_grade:"<<program_design_grade<<' '<<"pro_math_grade:"<<pro_math_grade<<endl;
    ofs.close();
}
//集成了输入操作的初始化对象的函数
void primary_student::cin_func() {
    cout<<"请依次输入：学号、姓名、性别、年龄、班级、英语成绩、数学成绩、语文成绩"<<endl;
    long long p_ID;
    string p_Name;
    string p_Sex;
    int p_Age;
    string p_Class;
    int p_english_grade,p_math_grade,p_chinese_grade;
    cin>>p_ID>>p_Name>>p_Sex>>p_Age>>p_Class
       >>p_english_grade>>p_math_grade>>p_chinese_grade;
    this->ID = p_ID;
    this->Name = p_Name;
    this->Sex = p_Sex;
    this->Age = p_Age;
    this->Class = p_Class;
    this->english_grade = p_english_grade;
    this->math_grade = p_math_grade;
    this->chinese_grade = p_chinese_grade;
    
}
void high_student::cin_func() {
    cout<<"请依次输入：学号、姓名、性别、年龄、班级、英语成绩、数学成绩、语文成绩、地理成绩、历史成绩"<<endl;
    long long p_ID;
    string p_Name;
    string p_Sex;
    int p_Age;
    string p_Class;
    int p_english_grade,p_math_grade,p_chinese_grade,p_geography_grade,p_history_grade;
    cin>>p_ID>>p_Name>>p_Sex>>p_Age>>p_Class
       >>p_english_grade>>p_math_grade>>p_chinese_grade>>p_geography_grade>>p_history_grade;
    this->ID = p_ID;
    this->Name = p_Name;
    this->Sex = p_Sex;
    this->Age = p_Age;
    this->Class = p_Class;
    this->english_grade = p_english_grade;
    this->math_grade = p_math_grade;
    this->chinese_grade = p_chinese_grade;
    this->geography_grade = p_geography_grade;
    this->history_grade = p_history_grade;
}


void college_student::cin_func() {
    cout<<"请依次输入：学号、姓名、性别、年龄、班级、专业成绩、大英成绩、课设成绩、高数成绩"<<endl;
    long long p_ID;
    string p_Name;
    string p_Sex;
    int p_Age;
    string p_Class;
    int p_profession_grade,p_pro_eng_grade,p_program_design_grade,p_pro_math_grade;
    cin>>p_ID>>p_Name>>p_Sex>>p_Age>>p_Class
       >>p_profession_grade>>p_pro_eng_grade>>p_program_design_grade>>p_pro_math_grade;
    this->ID = p_ID;
    this->Name = p_Name;
    this->Sex = p_Sex;
    this->Age = p_Age;
    this->Class = p_Class;
    this->profession_grade = p_profession_grade;
    this->pro_eng_grade = p_pro_eng_grade;
    this->program_design_grade = p_program_design_grade;
    this->pro_math_grade = p_pro_math_grade;
}
//获取对象姓名
string primary_student::get_name() {
    return this->Name;
}
string high_student::get_name() {
    return this->Name;
}
string college_student::get_name() {
    return this->Name;
}
long long primary_student::get_ID() {
    return this->ID;
}
long long high_student::get_ID() {
    return this->ID;
}
long long college_student::get_ID() {
    return this->ID;
}

//获得每个分数

int primary_student::getEnglishGrade() const {
    return english_grade;
}
int primary_student::getMathGrade() const {
    return math_grade;
}
int primary_student::getChineseGrade() const {
    return chinese_grade;
}
int high_student::getEnglishGrade() const {
    return english_grade;
}
int high_student::getMathGrade() const {
    return math_grade;
}
int high_student::getChineseGrade() const {
    return chinese_grade;
}
int high_student::getGeographyGrade() const {
    return geography_grade;
}
int high_student::getHistoryGrade() const {
    return history_grade;
}
int college_student::getProfessionGrade() const {
    return profession_grade;
}
int college_student::getProEngGrade() const {
    return pro_eng_grade;
}
int college_student::getProgramDesignGrade() const {
    return program_design_grade;
}
int college_student::getProMathGrade() const {
    return pro_math_grade;
}

//友元函数
void access_high_stu(class high_student& h_stu) {
    h_stu.display_info();
}
