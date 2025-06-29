//
// Created by eviarch on 2023/12/7.
//
/*外周服务函数*/

#ifndef C___FUNCLIB_H
#define C___FUNCLIB_H
#pragma once

#include "Student.h"
#include "corefunc.h"
#include <iostream>
#include <vector>
#include <list>
using namespace std;

extern string store_content[3];

//显示选择菜单
void show_menu();
//用户选择，并跳转至对应功能
void user_selection();
//程序初始化
void init();
void init_prim_file();
void init_high_file();
void init_col_file();
//程序退出检查
void end_check();

//**********************
//******用户选择功能******
//**********************
//1. 添加学生信息
void add_student();
//分别添加对应的学生类
void add_prim_stu();
void add_high_stu();
void add_college_stu();
//*******************

//2. 查询学生信息
void find_student();

//3. 显示所有学生数据
void show_all_stu();
//*******************

//4. 编辑学生信息
void edit_student();
//分别编辑对应学生类中学生
void edit_prim_stu();
void edit_high_stu();
void edit_col_stu();

//5. 删除学生信息
void delete_stu_info();
//5.1 删除对应学生类型文件
//corefunc中delete_file()
//5.2 删除单个学生信息
int delete_stu();
//分别删除对应学生类中学生
void delete_prim_stu();
void delete_high_stu();
void delete_col_stu();
//*******************

//6. 统计学生信息
void statitic();
//*******************

//8. 读取文件信息
void read_student();
//*******************

//9. 学生成绩排名
//9.1 总分排名
bool cmp_prim(primary_student& a, primary_student& b);
bool cmp_high(high_student& a,high_student& b);
bool cmp_col(college_student& a,college_student& b);
void sort_student();
//9.2 单科排名
void sort_prim();
bool cmp_prim_chi(primary_student& a, primary_student& b);
bool cmp_prim_math(primary_student& a, primary_student& b);
bool cmp_prim_eng(primary_student& a, primary_student& b);

void sort_high();
bool cmp_high_chi(high_student& a,high_student& b);
bool cmp_high_math(high_student& a,high_student& b);
bool cmp_high_eng(high_student& a,high_student& b);
bool cmp_high_geo(high_student& a,high_student& b);
bool cmp_high_his(high_student& a,high_student& b);

void sort_col();
bool cmp_col_pro(college_student& a,college_student& b);
bool cmp_col_eng(college_student& a,college_student& b);
bool cmp_col_des(college_student& a,college_student& b);
bool cmp_col_math(college_student& a,college_student& b);
//*******************

//显示操作对象
int show_operate_obj();
//功能组件
//void misc_function();



#endif //C___FUNCLIB_H
