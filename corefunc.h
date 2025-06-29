//
// Created by eviarch on 2023/12/7.
//
/*核心函数*/

#ifndef C___COREFUNC_H
#define C___COREFUNC_H
#pragma once
#include "Student.h"
#include "funclib.h"
#include <vector>
#include <typeinfo>

extern string store_content[3];
void delay(int time);


//文件写入操作(使用了函数重载)
void writefile(long long ID, const string &Name, const string &Sex, int Age, const string &Class, int english_grade, int math_grade, int chinese_grade);
void writefile(long long ID, const string &Name, const string& Sex,int Age,const string& Class,int english_grade,int math_grade,int chinese_grade,
               int geography_grade,int history_grade);
void writefile(long long ID, const string &Name, const string& Sex,int Age,const string& Class,
               int profession_grade,int pro_eng_grade,int program_design_grade,int pro_math_grade);

//文件读取操作
bool checkfile(const string &filename = store_content[0]);      //默认参数
vector<string> readfile(const string &filename);
//将文件读入vector中
void load_prim_file();
void load_high_file();
void load_col_file();

//删除文件操作
int delete_file();
void remvfile(const string &filename);




#endif //C___COREFUNC_H
