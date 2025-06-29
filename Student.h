//
// Created by eviarch on 2023/12/4.
//
/*学生类父类及其子类*/

#ifndef C___STUDENT_H
#define C___STUDENT_H


#pragma once

#include <iostream>
#include <vector>
using namespace std;



//bass class for all kinds' of students
class Student{
public:
    Student() = default;
    virtual ~Student()= default;    //虚析构函数
    virtual void cin_func()=0;  //集成了输入操作的初始化对象的函数
    virtual void add_func()=0;  //集成了写文件函数的添加函数
    virtual void display_info()=0;  //显示成员值的函数
    virtual int getscore()=0;   //获取总分(使用不定参数函数模板)
    virtual void write_to_file()=0; //将成员的值写入文件中
    virtual string get_name()=0;    //获取对象姓名
    virtual long long get_ID()=0;     //获取对象姓名
protected:
    long long ID;
    string Name;
    string Sex;
    int Age;
    string Class;
};

//primary school students
class primary_student:virtual public Student{
public:
    primary_student() = default;
    primary_student(long long iID, string sName, string sSex, int iAge, string sCLass, int iEng, int iMath, int iChi);
    virtual void cin_func()override;
    virtual void add_func()override;
    virtual void display_info()override;
    virtual int getscore()override;
    virtual void write_to_file()override;
    virtual string get_name()override;
    virtual long long get_ID()override;
    int getEnglishGrade() const;
    int getMathGrade() const;
    int getChineseGrade() const;
    friend void access_high_stu(class high_student& h_stu);      //友元函数
protected:
    int english_grade;
    int math_grade;
    int chinese_grade;
};

//high school students
class high_student:virtual public Student{
public:
    high_student() = default;
    high_student(long long iID, string sName, string sSex, int iAge, string sCLass, int iEng, int iMath, int iChi, int iGeo, int iHis);
    virtual void cin_func()override;
    virtual void add_func()override;
    virtual void display_info()override;
    virtual int getscore()override;
    virtual void write_to_file()override;
    virtual string get_name()override;
    virtual long long get_ID()override;
    int getEnglishGrade() const;
    int getMathGrade() const;
    int getChineseGrade() const;
    int getGeographyGrade() const;
    int getHistoryGrade() const;

protected:
    int english_grade;
    int math_grade;
    int chinese_grade;
    int geography_grade;
    int history_grade;
};

//college students
class college_student:public primary_student,public high_student{
public:
    college_student() = default;
    college_student (long long iID, string sName, string sSex, int iAge, string sCLass, int iPro, int iEng, int iDes, int iMath);
    virtual void cin_func()override;
    virtual void add_func()override;
    virtual void display_info()override;
    virtual int getscore()override;
    virtual void write_to_file()override;
    virtual string get_name()override;
    virtual long long get_ID()override;
    int getProfessionGrade() const;
    int getProEngGrade() const;
    int getProgramDesignGrade() const;
    int getProMathGrade() const;
private:
    int profession_grade;
    int pro_eng_grade;
    int program_design_grade;
    int pro_math_grade;
};

//求和函数，用于求总分
template<typename... T>     //不定参数模板
auto sum_score(T... s);
extern vector<primary_student> prim_stu;
extern vector<high_student> high_stu;
extern vector<college_student> col_stu;
#endif //C___STUDENT_H