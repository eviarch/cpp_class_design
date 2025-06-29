//
// Created by eviarch on 2023/12/7.
//

#include "corefunc.h"
#include "funclib.h"
#include "Student.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <list>

using namespace std;

#define prim_txt "primary_student.txt"
#define high_txt "high_student.txt"
#define col_txt "college_student.txt"

//链表存储文件名
list<string> prim_list = { prim_txt };
list<string> high_list = { high_txt };
list<string> col_list = { col_txt };
string store_content[3] = { prim_list.front(),high_list.front(),col_list.front() };

int prim_num;
int high_num;
int col_num;

//显示选择菜单
void show_menu() {
    cout << "---------------------------------" << endl;
    cout << "------- 1. 添加学生信息  --------" << endl;
    cout << "------- 2. 查询学生信息  --------" << endl;
    cout << "------- 3. 显示所有学生  --------" << endl;
    cout << "------- 4. 编辑学生信息  --------" << endl;
    cout << "------- 5. 删除学生信息  --------" << endl;
    cout << "------- 6. 统计学生信息  --------" << endl;
    cout << "------- 7. 学生成绩排名  --------" << endl;
    cout << "------- 0. 退出程序      --------" << endl;
    cout << "---------------------------------" << endl;
}

//程序初始化
void init() {
    system("chcp 65001");
    prim_num = 0;
    high_num = 0;
    col_num = 0;

    bool chk_p, chk_h, chk_c;
    chk_p = checkfile(store_content[0]);
    chk_h = checkfile(store_content[1]);
    chk_c = checkfile(store_content[2]);
    int final = chk_c + chk_p + chk_h;
    if (final == 3) {
        cout << "文件检查完毕" << endl;
    }
    else {
        cout << "文件项缺失，请添加必要文件！" << endl;
        if (!chk_p) {
            cout << "缺失小学生记录文件(" << store_content[0] << ")" << endl;
            init_prim_file();
        }
        if (!chk_h) {
            cout << "缺失中学生记录文件(" << store_content[1] << ")" << endl;
            init_high_file();
        }
        if (!chk_c) {
            cout << "缺失大学生记录文件(" << store_content[2] << ")" << endl;
            init_col_file();
        }
        return init();
    }
    load_prim_file();
    load_high_file();
    load_col_file();

    cout << "欢迎使用本系统，已初始化完毕！" << endl;
    system("pause");
    system("cls");
    printf("NNNNNNNN        NNNNNNNN EEEEEEEEEEEEEEEEEEEEEE UUUUUUUU     UUUUUUUU      QQQQQQQQQ      \n");
    printf("N:::::::N       N::::::N E::::::::::::::::::::E U::::::U     U::::::U    QQ:::::::::QQ    \n");
    printf("N::::::::N      N::::::N E::::::::::::::::::::E U::::::U     U::::::U  QQ:::::::::::::QQ  \n");
    printf("N:::::::::N     N::::::N EE::::::EEEEEEEEE::::E UU:::::U     U:::::UU Q:::::::QQQ:::::::Q \n");
    printf("N::::::::::N    N::::::N   E:::::E       EEEEEE  U:::::U     U:::::U  Q::::::O   Q::::::Q \n");
    printf("N:::::::::::N   N::::::N   E:::::E               U:::::D     D:::::U  Q:::::O     Q:::::Q \n");
    printf("N:::::::N::::N  N::::::N   E::::::EEEEEEEEEE     U:::::D     D:::::U  Q:::::O     Q:::::Q \n");
    printf("N::::::N N::::N N::::::N   E:::::::::::::::E     U:::::D     D:::::U  Q:::::O     Q:::::Q \n");
    printf("N::::::N  N::::N:::::::N   E:::::::::::::::E     U:::::D     D:::::U  Q:::::O     Q:::::Q \n");
    printf("N::::::N   N:::::::::::N   E::::::EEEEEEEEEE     U:::::D     D:::::U  Q:::::O     Q:::::Q \n");
    printf("N::::::N    N::::::::::N   E:::::E               U:::::D     D:::::U  Q:::::O  QQQQ:::::Q \n");
    printf("N::::::N     N:::::::::N   E:::::E       EEEEEE  U::::::U   U::::::U  Q::::::O Q::::::::Q \n");
    printf("N::::::N      N::::::::N EE::::::EEEEEEEE:::::E  U:::::::UUU:::::::U  Q:::::::QQ::::::::Q \n");
    printf("N::::::N       N:::::::N E::::::::::::::::::::E   UU:::::::::::::UU    QQ::::::::::::::Q  \n");
    printf("N::::::N        N::::::N E::::::::::::::::::::E     UU:::::::::UU        QQ:::::::::::Q   \n");
    printf("NNNNNNNN         NNNNNNN EEEEEEEEEEEEEEEEEEEEEE       UUUUUUUUU            QQQQQQQQ::::QQ \n");
    printf("                                                                                   Q:::::Q\n");
    printf("                                                                                    QQQQQQ\n");
    printf("\n");
    printf("\n");
    printf("                         _   _                    ________    ___               \n");
    printf("              /\\        | | | |                _ |___  / \\ \\ / / |           \n");
    printf("             /  \\  _   _| |_| |__   ___  _ __ (_)   / /   \\ V /| |            \n");
    printf("            / /\\ \\| | | | __| '_ \\ / _ \\| '__|     / /     > < | |          \n");
    printf("           / ____ \\ |_| | |_| | | | (_) | |    _  /  /__  / . \\| |____        \n");
    printf("          /_/    \\_\\__,_|\\__|_| |_|\\___/|_|   (_) \\_____|/_/ \\_\\\\_____| \n");
    system("pause");
    return;
}
void init_prim_file() {
    cout << "请添加一位小学生以继续" << endl;
    primary_student* new_student = new primary_student;
    new_student->add_func();
    delete new_student;
    cout << "您已添加" << 1 << "位小学生数据" << endl;
    return;
}
void init_high_file() {
    cout << "请添加一位中学生以继续" << endl;
    high_student* new_student = new high_student;
    new_student->add_func();
    delete new_student;
    cout << "您已添加" << 1 << "位小学生数据" << endl;
    return;
}
void init_col_file() {
    cout << "请添加一位大学生以继续" << endl;
    college_student* new_student = new college_student;
    new_student->add_func();
    delete new_student;
    cout << "您已添加" << 1 << "位大学生数据" << endl;
    return;
}
//********************************************************

//程序退出检查
void end_check() {
    prim_num = 0;
    prim_stu.clear();
    high_num = 0;
    high_stu.clear();
    col_num = 0;
    col_stu.clear();
    bool chk_p, chk_h, chk_c;
    chk_p = checkfile(store_content[0]);
    chk_h = checkfile(store_content[1]);
    chk_c = checkfile(store_content[2]);
    int final = chk_c + chk_p + chk_h;
    if (final == 3) {
        cout << "文件检查完毕,所有文件完整" << endl;
        system("pause");
        exit(0);
    }
    else {
        if (!chk_p) {
            cout << store_content[0] << "缺失，下次使用该程序时将要添加" << endl;
            system("pause");
            exit(0);
        }
        if (!chk_h) {
            cout << store_content[1] << "缺失，下次使用该程序时将要添加" << endl;
            system("pause");
            exit(0);
        }
        if (!chk_c) {
            cout << store_content[2] << "缺失，下次使用该程序时将要添加" << endl;
            system("pause");
            exit(0);
        }
    }
}

//用户选择，并跳转至对应功能
void user_selection() {
    system("cls");
    show_menu();
    int select;
    cin >> select;
    if ((select < 0) || (select > 7)) {
        cout << "请输入0-7的整数!" << endl;
        system("cls");
        show_menu();
        return user_selection();
    }
    switch (select) {
        case 1:     //添加学生信息[+]
            system("cls");
            add_student();
            break;
        case 2:     //查询学生信息[+]
            system("cls");
            find_student();
            break;
        case 3:     //显示所有学生[+]
            system("cls");
            show_all_stu();
            break;
        case 4:     //编辑学生信息[+]
            system("cls");
            edit_student();
            break;
        case 5:     //删除学生信息[+]
            system("cls");
            delete_stu_info();
            break;
        case 6:     //统计学生信息[+]
            system("cls");
            statitic();
            break;
        case 7:     //学生成绩排名[+]
            system("cls");
            sort_student();
            break;
        case 0:     //退出程序[+]
            cout << "感谢您使用本系统" << endl;
            return;
        default:
            break;
    }
    return user_selection();
}
//********************************************************

//功能组件
//void misc_function(){
//
//}
//********************************************************

//1. 添加学生信息
void add_student() {
    int select;
    select = show_operate_obj();
    switch (select) {
        case 1:
            add_prim_stu();
            break;
        case 2:
            add_high_stu();
            break;
        case 3:
            add_college_stu();
            break;
        case 0:
            return;
        default:
            break;
    }
}
//分别添加对应的学生类
void add_prim_stu() {
    int n;
    cout << "请输入要添加的人数" << endl;
    cout << "若要退出请输入-1" << endl;
    cin >> n;
    if (n == -1) {
        return;
    }
    if (n < -1) {
        cout << "错误的数字范围，请按下任意键重新输入！" << endl;
        system("pause");
        system("cls");
        return add_prim_stu();
    }

    int fault = 0;
    bool control = false;
    int check = 0;
    primary_student* new_student = new primary_student;
    for (int i = 0; i < n; ++i) {
        new_student->cin_func();
        for (int j = 0; j < prim_stu.size(); ++j) {     //检查ID重复
            if (prim_stu.at(j).get_ID() == new_student->get_ID()) {
                cout << "warning:该ID已经存在！ " << i + 1 << "号学生添加失败" << endl;
                fault++;
                check++;
            }
            control = false;
        }
        if (check == 0) {
            control = true;
        }
        if (control) {
            prim_stu.push_back(*new_student);
            new_student->write_to_file();
            cout << i + 1 << "号学生添加成功" << endl;
            control = false;
        }
        check = 0;
        control = false;
    }
    delete new_student;
    prim_num += n - fault;

    cout << "您已添加" << n - fault << "位小学生数据" << endl;
    cout << fault << "个学生添加失败" << endl;
    system("pause");
    system("cls");
}
void add_high_stu() {
    int n;
    cout << "请输入要添加的人数" << endl;
    cout << "若要退出请输入-1" << endl;
    cin >> n;
    if (n == -1) {
        return;
    }
    if (n < 0) {
        cout << "错误的数字范围，请按下任意键重新输入！" << endl;
        system("pause");
        system("cls");
        return add_high_stu();
    }

    int fault = 0;
    bool control = false;
    int check = 0;
    high_student* new_student = new high_student;
    for (int i = 0; i < n; ++i) {
        new_student->cin_func();
        for (int j = 0; j < high_stu.size(); ++j) {     //检查ID重复
            if (high_stu.at(j).get_ID() == new_student->get_ID()) {
                cout << "warning:该ID已经存在！ " << i + 1 << "号学生添加失败" << endl;
                fault++;
                check = false;
            }
            control = false;
        }
        if (check == 0) {
            control = true;
        }
        if (control) {
            high_stu.push_back(*new_student);
            new_student->write_to_file();
            cout << i + 1 << "号学生添加成功" << endl;
            control = false;
        }
        check = 0;
        control = false;
    }
    delete new_student;
    high_num += n - fault;

    cout << "您已添加" << n << "位中学生数据" << endl;
    cout << fault << "个学生添加失败" << endl;
    system("pause");
    system("cls");
}
void add_college_stu() {
    int n;
    cout << "请输入要添加的人数" << endl;
    cout << "若要退出请输入-1" << endl;
    cin >> n;
    if (n == -1) {
        return;
    }
    if (n < 0) {
        cout << "错误的数字范围，请按下任意键重新输入！" << endl;
        system("pause");
        system("cls");
        return add_college_stu();
    }

    int fault = 0;
    bool control = false;
    int check = 0;
    college_student* new_student = new college_student;
    for (int i = 0; i < n; ++i) {
        new_student->cin_func();
        for (int j = 0; j < col_stu.size(); ++j) {     //检查ID重复
            if (col_stu.at(j).get_ID() == new_student->get_ID()) {
                cout << "warning:该ID已经存在！ " << i + 1 << "号学生添加失败" << endl;
                fault++;
                check = true;
            }
            control = false;
        }
        if (check == 0) {
            control = true;
        }
        if (control) {
            col_stu.push_back(*new_student);
            new_student->write_to_file();
            cout << i + 1 << "号学生添加成功" << endl;
            control = false;
        }
        check = 0;
        control = false;
    }
    delete new_student;
    col_num += n - fault;

    cout << "您已添加" << n << "位大学生数据" << endl;
    cout << fault << "个学生添加失败" << endl;
    system("pause");
    system("cls");
}
//********************************************************

//2. 查询学生信息
void find_student() {
    read_student();
    cout << "请输入要查找的标签与值(如：Name:James)" << endl;
    cout << "若要退出，请输入exit" << endl;
    string target;
    cin >> target;
    if (target.empty() || target == "exit") {
        return;
    }
    cout << "正在查询小学生类" << endl;
    vector<string> temp_prim_local = readfile(store_content[0]);
    int check = 0;
    for (int i = 0; i < temp_prim_local.size(); ++i) {
        string temp = temp_prim_local.at(i);
        if (temp.find(target) != string::npos) {
            cout << temp << endl;
            check++;
        }
    }
    if (check > 0) {
        cout << "在小学生中找到了" << check << "符合项" << endl;
    }
    else {
        cout << "小学生中未找到符合项" << endl;
    }
    cout<<endl;
    check = 0;
    cout << "正在查询中学生类" << endl;
    vector<string> temp_high_local = readfile(store_content[1]);
    for (int i = 0; i < temp_high_local.size(); ++i) {
        string temp = temp_high_local.at(i);
        if (temp.find(target) != string::npos) {
            cout << temp << endl;
            check++;
        }
    }
    if (check > 0) {
        cout << "在中学生中找到了" << check << "符合项" << endl;
    }
    else {
        cout << "在中学生中未找到符合项" << endl;
    }
    cout<<endl;
    check = 0;
    cout << "正在查询大学生类" << endl;
    vector<string> temp_college_local = readfile(store_content[2]);
    for (int i = 0; i < temp_college_local.size(); ++i) {
        string temp = temp_college_local.at(i);
        if (temp.find(target) != string::npos) {
            cout << temp << endl;
            check++;
        }
    }
    if (check > 0) {
        cout << "在大学生中找到了" << check << "符合项" << endl;
    }
    else {
        cout << "在大学生中未找到符合项" << endl;
    }
    prim_num = 0;
    prim_stu.clear();
    load_prim_file();
    high_num = 0;
    high_stu.clear();
    load_high_file();
    col_num = 0;
    col_stu.clear();
    load_col_file();

    system("pause");
}
//********************************************************

//3. 显示所有学生
void show_all_stu() {
    cout << "正在显示所有小学生信息：" << endl;
    vector<string> buf = readfile(store_content[0]);
    for (int i = 0; i < buf.size(); ++i) {
        cout << buf.at(i);
        cout << endl;
    }
    vector<string>().swap(buf);     //clean buffer space
    cout << "正在显示所有中学生信息：" << endl;
    buf = readfile(store_content[1]);
    for (int i = 0; i < buf.size(); ++i) {
        cout << buf.at(i);
        cout << endl;
    }
    vector<string>().swap(buf);     //clean buffer space
    cout << "正在显示所有大学生信息：" << endl;
    buf = readfile(store_content[2]);
    for (int i = 0; i < buf.size(); ++i) {
        cout << buf.at(i);
        cout << endl;
    }
    system("pause");
}
//********************************************************

//4. 编辑学生信息
void edit_student() {
    cout << "警告：您正在执行编辑操作！" << endl;
    int select = show_operate_obj();
    switch (select) {
        case 1:
            system("cls");
            edit_prim_stu();
            break;
        case 2:
            system("cls");
            edit_high_stu();
            break;
        case 3:
            system("cls");
            edit_col_stu();
            break;
        case 0:
            return;
        default:
            break;
    }
    system("pause");
}
//分别编辑对应学生类中学生
void edit_prim_stu() {
    if (prim_stu.size() != prim_num) {       //检查是否更新了对象
        load_prim_file();
        cout << "prim_file automatically loaded" << endl;
    }
    if (!checkfile(store_content[0])) {
        return;
    }
    for (int i = 0; i < prim_stu.size(); ++i) {     //列出其中对象信息，方便编辑
        cout << left << setw(4) << i + 1;
        prim_stu.at(i).display_info();
    }
    cout << "请输入要编辑的学生序号" << endl;
    cout << "若要退出请输入-1" << endl;
    int m;
    cin >> m;
    if (m == -1) {  //检查是否要退出
        system("cls");
        cout << "exit!" << endl;
        return;
    }
    if (m<-1 || m>prim_stu.size()) {     //检查输入序号是否正确
        cout << "错误的序号范围！" << endl;
        system("pause");
        system("cls");
        return edit_prim_stu();
    }

    primary_student* new_stu = new primary_student;     //new一个小学生对象
    new_stu->cin_func();

    for (int i = 0; i < prim_stu.size(); ++i) {     //检查ID重复
        if (prim_stu.at(i).get_ID() == new_stu->get_ID()) {
            cout << "该ID已经存在！" << endl;
            system("pause");
            system("cls");
            delete new_stu;
            return edit_prim_stu();
        }
    }

    prim_stu.erase(prim_stu.begin() + m - 1);

    prim_num--;
    if (prim_num == 0) {
        prim_stu.push_back(*new_stu);
    }
    else {
        prim_stu.insert(prim_stu.begin() + m - 1, *new_stu);     //将编辑后的内容加入容器
    }
    prim_num++;
    delete new_stu;

    remvfile(store_content[0]);     //删去文件，方便重写
    for (int i = 0; i < prim_stu.size(); ++i) {
        prim_stu.at(i).write_to_file();
    }
    cout << "编辑成功！" << endl;
    for (int i = 0; i < prim_stu.size(); ++i) {
        cout << i + 1;
        prim_stu.at(i).display_info();
    }
}
void edit_high_stu() {
    if (high_stu.size() != high_num) {
        load_high_file();
        cout << "high_file automatically loaded" << endl;
    }
    if (!checkfile(store_content[1])) {
        return;
    }
    for (int i = 0; i < high_stu.size(); ++i) {
        cout << left << setw(4) << i + 1;
        high_stu.at(i).display_info();
    }
    cout << "请输入要编辑的学生序号" << endl;
    cout << "若要退出请输入-1" << endl;
    int m;
    cin >> m;
    if (m == -1) {
        system("cls");
        cout << "exit!" << endl;
        return;
    }
    if (m<-1 || m>high_stu.size()) {
        cout << "错误的序号范围！" << endl;
        system("pause");
        system("cls");
        return edit_high_stu();
    }

    high_student* new_stu = new high_student;     //new一个小学生对象
    new_stu->cin_func();

    for (int i = 0; i < high_stu.size(); ++i) {     //检查ID重复
        if (high_stu.at(i).get_ID() == new_stu->get_ID()) {
            cout << "该ID已经存在！" << endl;
            system("pause");
            system("cls");
            delete new_stu;
            return edit_high_stu();
        }
    }

    high_stu.erase(high_stu.begin() + m - 1);

    high_num--;
    if (high_num == 0) {
        high_stu.push_back(*new_stu);
    }
    else {
        high_stu.insert(high_stu.begin() + m - 1, *new_stu);     //将编辑后的内容加入容器
    }
    high_num++;

    delete new_stu;
    remvfile(store_content[1]);     //删去文件，方便重写
    for (int i = 0; i < high_stu.size(); ++i) {
        high_stu.at(i).write_to_file();
    }

    cout << "编辑成功！" << endl;
    for (int i = 0; i < high_stu.size(); ++i) {
        cout << i + 1;
        high_stu.at(i).display_info();
    }
}
void edit_col_stu() {
    if (col_stu.size() != col_num) {
        load_col_file();
        cout << "col_file automatically loaded" << endl;
    }
    if (!checkfile(store_content[2])) {
        return;
    }
    for (int i = 0; i < col_stu.size(); ++i) {
        cout << left << setw(4) << i + 1;
        col_stu.at(i).display_info();
    }
    cout << "请输入要编辑的学生序号" << endl;
    cout << "若要退出请输入-1" << endl;
    int m;
    cin >> m;
    if (m == -1) {
        system("cls");
        cout << "exit!" << endl;
        return;
    }
    if (m<-1 || m>col_stu.size()) {
        cout << "错误的序号范围！" << endl;
        system("pause");
        system("cls");
        return edit_col_stu();
    }

    college_student* new_stu = new college_student;     //new一个小学生对象
    new_stu->cin_func();

    for (int i = 0; i < col_stu.size(); ++i) {     //检查ID重复
        if (col_stu.at(i).get_ID() == new_stu->get_ID()) {
            cout << "该ID已经存在！" << endl;
            system("pause");
            system("cls");
            delete new_stu;
            return edit_col_stu();
        }
    }

    col_stu.erase(col_stu.begin() + m - 1);

    col_num--;
    if (col_num == 0) {
        col_stu.push_back(*new_stu);
    }
    else {
        col_stu.insert(col_stu.begin() + m - 1, *new_stu);     //将编辑后的内容加入容器
    }
    col_num++;

    delete new_stu;

    remvfile(store_content[2]);     //删去文件，方便重写
    for (int i = 0; i < col_stu.size(); ++i) {
        col_stu.at(i).write_to_file();
    }

    cout << "编辑成功！" << endl;
    for (int i = 0; i < col_stu.size(); ++i) {
        cout << i + 1;
        col_stu.at(i).display_info();
    }
}
//********************************************************

//5. 删除学生信息
void delete_stu_info() {
    cout << "警告：您正在执行删除操作！" << endl;
    cout << "1. 删除文件" << endl;
    cout << "2. 删除某类学生单个数据" << endl;
    cout << "0. 返回上一级" << endl;
    int select;
    cin >> select;
    if (select < 0 || select>2) {
        cout << "错误的数字范围，请按下任意键重新输入！" << endl;
        system("pause");
        system("cls");
        return delete_stu_info();
    }
    int choice = -1;
    switch (select) {
        case 1:
            system("cls");
            choice = delete_file();
            if (choice == 0) {
                system("cls");
                return delete_stu_info();
            }
            break;
        case 2:
            system("cls");
            choice = delete_stu();
            if (choice == 0) {
                system("cls");
                return delete_stu_info();
            }
            break;
        case 0:
            return;
        default:
            break;
    }
    system("pause");
}
//5.1 删除对应学生类型文件
//corefunc中delete_file()
//5.2 删除单个学生信息
int delete_stu() {
    int select = show_operate_obj();
    switch (select) {
        case 1:
            delete_prim_stu();
            break;
        case 2:
            delete_high_stu();
            break;
        case 3:
            delete_col_stu();
            break;
        case 0:
            return 0;
        default:
            return select;
    }
    return -1;
}
void delete_prim_stu() {
    if (prim_stu.size() != prim_num) {
        load_prim_file();
        cout << "prim_file automatically loaded" << endl;
    }
    if (!checkfile(store_content[0])) {
        return;
    }
    for (int i = 0; i < prim_stu.size(); ++i) {
        cout << left << setw(4) << i + 1;
        prim_stu.at(i).display_info();
    }
    cout << "请输入要删除的学生的序号区间 [x,y]" << endl;
    cout << "若只删除一个学生信息，请输入两遍该序列号" << endl;
    cout << "若退出此功能请输入两次-1" << endl;
    int m, n;
    cin >> m >> n;
    if ((m == -1) && (n == -1)) {
        cout << "exit!" << endl;
        return;
    }
    if (n < m) {
        cout << "m不得大于n" << endl;
        return delete_prim_stu();
    }
    if (m<-1 || m>prim_stu.size()) {
        cout << "第一个序号范围错误！" << endl;
        system("pause");
        system("cls");
        return delete_prim_stu();
    }
    if (n<-1 || n>prim_stu.size()) {
        cout << "第二个序号范围错误！" << endl;
        system("pause");
        system("cls");
        return delete_prim_stu();
    }

    if ((m == n) && (m != -1)) {
        prim_stu.erase(prim_stu.begin() + m - 1);
        cout << "已删除" << m << "号学生信息" << endl;
        remvfile(store_content[0]);
        for (int i = 0; i < prim_stu.size(); ++i) {
            prim_stu.at(i).write_to_file();
        }
        prim_num--;
    }
    if (m != n) {
        prim_stu.erase(prim_stu.begin() + m - 1, prim_stu.begin() + n);
        cout << "已删除" << m << "至" << n << "之间的学生信息" << endl;
        remvfile(store_content[0]);
        for (int i = 0; i < prim_stu.size(); ++i) {
            prim_stu.at(i).write_to_file();
        }
        prim_num = prim_num - n + m;
    }

    for (int i = 0; i < prim_stu.size(); ++i) {
        cout << i + 1;
        prim_stu.at(i).display_info();
    }
}
void delete_high_stu() {
    if (high_stu.size() != high_num) {
        load_high_file();
        cout << "high_file automatically loaded" << endl;
    }
    if (!checkfile(store_content[1])) {
        return;
    }
    for (int i = 0; i < high_stu.size(); ++i) {
        cout << left << setw(4) << i + 1;
        high_stu.at(i).display_info();
    }
    cout << "请输入要删除的学生的序号区间 [x,y]" << endl;
    cout << "若只删除一个学生信息，请输入两遍该序列号" << endl;
    cout << "若退出此功能请输入两次-1" << endl;
    int m, n;
    cin >> m >> n;
    if ((m == -1) && (n == -1)) {
        cout << "exit!" << endl;
        return;
    }
    if (n < m) {
        cout << "m不得大于n" << endl;
        return delete_high_stu();
    }
    if (m<-1 || m>high_stu.size()) {
        cout << "第一个序号范围错误！" << endl;
        system("pause");
        system("cls");
        return delete_high_stu();
    }
    if (n<-1 || n>high_stu.size()) {
        cout << "第二个序号范围错误！" << endl;
        system("pause");
        system("cls");
        return delete_high_stu();
    }
    if ((m == n) && (m != -1)) {
        high_stu.erase(high_stu.begin() + m - 1);
        cout << "已删除" << m << "号学生信息" << endl;
        remvfile(store_content[1]);
        for (int i = 0; i < high_stu.size(); ++i) {
            high_stu.at(i).write_to_file();
        }
        high_num--;
    }
    if (m != n) {
        high_stu.erase(high_stu.begin() + m - 1, high_stu.begin() + n);
        cout << "已删除" << m << "至" << n << "之间的学生信息" << endl;
        remvfile(store_content[1]);
        for (int i = 0; i < high_stu.size(); ++i) {
            high_stu.at(i).write_to_file();
        }
        high_num = high_num - n + m;
    }

    for (int i = 0; i < high_stu.size(); ++i) {
        cout << i + 1;
        high_stu.at(i).display_info();
    }
}
void delete_col_stu() {
    if (col_stu.size() != col_num) {
        load_col_file();
        cout << "col_file automatically loaded" << endl;
    }
    if (!checkfile(store_content[2])) {
        return;
    }
    for (int i = 0; i < col_stu.size(); ++i) {
        cout << left << setw(4) << i + 1;
        col_stu.at(i).display_info();
    }
    cout << "请输入要删除的学生的序号区间 [x,y]" << endl;
    cout << "若只删除一个学生信息，请输入两遍该序列号" << endl;
    cout << "若退出此功能请输入两次-1" << endl;
    int m, n;
    cin >> m >> n;
    if ((m == -1) && (n == -1)) {
        cout << "exit!" << endl;
        return;
    }
    if (n < m) {
        cout << "m不得大于n" << endl;
        return delete_col_stu();
    }
    if (m<-1 || m>col_stu.size()) {
        cout << "第一个序号范围错误！" << endl;
        system("pause");
        system("cls");
        return delete_col_stu();
    }
    if (n<-1 || n>col_stu.size()) {
        cout << "第二个序号范围错误！" << endl;
        system("pause");
        system("cls");
        return delete_col_stu();
    }
    if ((m == n) && (m != -1)) {
        col_stu.erase(col_stu.begin() + m - 1);
        cout << "已删除" << m << "号学生信息" << endl;
        remvfile(store_content[2]);
        for (int i = 0; i < col_stu.size(); ++i) {
            col_stu.at(i).write_to_file();
        }
        col_num--;
    }
    if (m != n) {
        col_stu.erase(col_stu.begin() + m - 1, col_stu.begin() + n);
        cout << "已删除" << m << "至" << n << "之间的学生信息" << endl;
        remvfile(store_content[2]);
        for (int i = 0; i < col_stu.size(); ++i) {
            col_stu.at(i).write_to_file();
        }
        col_num = col_num - n + m;
    }

    for (int i = 0; i < col_stu.size(); ++i) {
        cout << i + 1;
        col_stu.at(i).display_info();
    }
}
//********************************************************

//6. 统计学生信息
void statitic() {
    //统计学生人数
    cout << "****************统计学生人数****************" << endl;
    cout << endl;
    vector <string> temp_prim_local = readfile(store_content[0]);
    prim_num = 0;
    for (int i = 0; i < temp_prim_local.size(); ++i) {
        string temp = temp_prim_local.at(i);
        if (temp.find("Name:") != string::npos) {
            prim_num++;
        }
    }
    cout << "                小学生有" << prim_num << "人" << endl;
    high_num = 0;
    vector<string> temp_high_local = readfile(store_content[1]);  //统计学生人数
    for (int i = 0; i < temp_high_local.size(); ++i) {
        string temp = temp_high_local.at(i);
        if (temp.find("Name:") != string::npos) {
            high_num++;
        }
    }
    cout << "                中学生有" << high_num << "人" << endl;
    col_num = 0;
    vector<string> temp_col_local = readfile(store_content[2]);  //统计学生人数
    for (int i = 0; i < temp_col_local.size(); ++i) {
        string temp = temp_col_local.at(i);
        if (temp.find("Name:") != string::npos) {
            col_num++;
        }
    }
    cout << "                大学生有" << col_num << "人" << endl;
    cout << endl;
    //统计学生总分
    cout << "****************统计学生总分****************" << endl;
    cout << endl;
    cout << "小学生各人总分：" << endl;
    //cout<<prim_stu.size()<<endl;
    for (int i = 0; i < prim_num; ++i) {
        int prim_sum = prim_stu.at(i).getscore();
        cout << "              " << left << setw(6) << prim_stu.at(i).get_name() << "的总分为：" << right << setw(4) << prim_sum << endl;
    }
    cout << "中学生各人总分：" << endl;
    //cout<<high_stu.size()<<endl;
    for (int i = 0; i < high_num; ++i) {
        int high_sum = high_stu.at(i).getscore();
        cout << "              " << left << setw(6) << high_stu.at(i).get_name() << "的总分为：" << right << setw(4) << high_num << endl;
    }
    cout << "大学生各人总分：" << endl;
    //cout<<col_stu.size()<<endl;
    for (int i = 0; i < col_num; ++i) {
        int col_sum = col_stu.at(i).getscore();
        cout << "              " << left << setw(6) << col_stu.at(i).get_name() << "的总分为：" << right << setw(4) << col_sum << endl;
    }
    cout << endl;
    cout << "**************统计学生单科成绩**************" << endl;
    cout << endl;
    cout << "       ********小学生语文成绩********       " << endl;
    if (checkfile(store_content[0])) {
        float prim_chi = 0;
        for (int i = 0; i < prim_stu.size(); ++i) {
            prim_chi += (float)prim_stu.at(i).getChineseGrade();
        }
        prim_chi /= (float)prim_num;
        cout << "                    " << prim_chi << endl;
        cout << endl;
        cout << "       ********小学生数学成绩********       " << endl;
        float prim_math = 0;
        for (int i = 0; i < prim_stu.size(); ++i) {
            prim_math += (float)prim_stu.at(i).getMathGrade();
        }
        prim_math /= (float)prim_num;
        cout << "                    " << prim_math << endl;
        cout << endl;
        cout << "       ********小学生英语成绩********       " << endl;
        float prim_eng = 0;
        for (int i = 0; i < prim_stu.size(); ++i) {
            prim_eng += (float)prim_stu.at(i).getEnglishGrade();
        }
        prim_eng /= (float)prim_num;
        cout << "                    " << prim_eng << endl;
    }

    cout << endl;
    cout << endl;

    cout << "       ********中学生语文成绩********       " << endl;
    if (checkfile(store_content[1])) {
        float high_chi = 0;
        for (int i = 0; i < high_stu.size(); ++i) {
            high_chi += (float)high_stu.at(i).getChineseGrade();
        }
        high_chi /= (float)high_num;
        cout << "                    " << high_chi << endl;
        cout << endl;
        cout << "       ********中学生数学成绩********       " << endl;
        float high_math = 0;
        for (int i = 0; i < high_stu.size(); ++i) {
            high_math += (float)high_stu.at(i).getMathGrade();
        }
        high_math /= (float)high_num;
        cout << "                    " << high_math << endl;
        cout << endl;
        cout << "       ********中学生英语成绩********       " << endl;
        float high_eng = 0;
        for (int i = 0; i < high_stu.size(); ++i) {
            high_eng += (float)high_stu.at(i).getEnglishGrade();
        }
        high_eng /= (float)high_num;
        cout << "                    " << high_eng << endl;
        cout << endl;
        cout << "       ********中学生地理成绩********       " << endl;
        float high_geo = 0;
        for (int i = 0; i < high_stu.size(); ++i) {
            high_geo += (float)high_stu.at(i).getGeographyGrade();
        }
        high_geo /= (float)high_num;
        cout << "                    " << high_geo << endl;
        cout << endl;
        cout << "       ********中学生历史成绩********       " << endl;
        float high_his = 0;
        for (int i = 0; i < high_stu.size(); ++i) {
            high_his += (float)high_stu.at(i).getHistoryGrade();
        }
        high_his /= (float)high_num;
        cout << "                    " << high_his << endl;
    }

    cout << endl;
    cout << endl;

    cout << "       ********大学生专业课成绩********       " << endl;
    if (checkfile(store_content[2])) {
        float col_pro = 0;
        for (int i = 0; i < col_stu.size(); ++i) {
            col_pro += (float)col_stu.at(i).getProfessionGrade();
        }
        col_pro /= (float)col_num;
        cout << "                    " << col_pro << endl;
        cout << endl;
        cout << "       ********大学生英语课成绩********       " << endl;
        float col_eng = 0;
        for (int i = 0; i < col_stu.size(); ++i) {
            col_eng += (float)col_stu.at(i).getProEngGrade();
        }
        col_eng /= (float)col_num;
        cout << "                    " << col_eng << endl;
        cout << endl;
        cout << "      ********大学生课程设计成绩********       " << endl;
        float col_des = 0;
        for (int i = 0; i < col_stu.size(); ++i) {
            col_des += (float)col_stu.at(i).getProgramDesignGrade();
        }
        col_des /= (float)col_num;
        cout << "                    " << col_des << endl;
        cout << endl;
        cout << "       ********大学生高数课成绩********       " << endl;
        float col_math = 0;
        for (int i = 0; i < col_stu.size(); ++i) {
            col_math += (float)col_stu.at(i).getProMathGrade();
        }
        col_math /= (float)col_num;
        cout << "                    " << col_math << endl;
    }
    cout << endl;
    system("pause");
}

//********************************************************

//8. 读取文件数据
//载入对应类的数组中
void read_student() {
    if (prim_stu.size() != prim_num) load_prim_file();
    if (high_stu.size() != prim_num) load_high_file();
    if (col_stu.size() != prim_num) load_col_file();

    bool chk_p, chk_h, chk_c;
    chk_p = checkfile(store_content[0]);
    chk_h = checkfile(store_content[1]);
    chk_c = checkfile(store_content[2]);
    int final = chk_c + chk_p + chk_h;
    if (final == 3) {
        cout << "文件加载完成" << endl;
    }
}
//********************************************************

//9. 学生成绩排名
//9.1 总分排名
//排名函数
bool cmp_prim(primary_student& a, primary_student& b) {
    return a.getscore() > b.getscore();
}
bool cmp_high(high_student& a, high_student& b) {
    return a.getscore() > b.getscore();
}
bool cmp_col(college_student& a, college_student& b) {
    return a.getscore() > b.getscore();
}

void sort_student() {
    sort(prim_stu.begin(), prim_stu.end(), cmp_prim);
    sort(high_stu.begin(), high_stu.end(), cmp_high);
    sort(col_stu.begin(), col_stu.end(), cmp_col);
    cout << "**************各学生总分排名**************" << endl;
    cout << "小学生：" << endl;
    if (checkfile(store_content[0])) {
        for (int i = 0; i < prim_stu.size(); ++i) {
            cout << left << setw(4) << i + 1;
            prim_stu.at(i).display_info();
        }
    }
    cout << "中学生：" << endl;
    if (checkfile(store_content[1])) {
        for (int i = 0; i < high_stu.size(); ++i) {
            cout << left << setw(4) << i + 1;
            high_stu.at(i).display_info();
        }
    }
    cout << "大学生：" << endl;
    if (checkfile(store_content[1])) {
        for (int i = 0; i < col_stu.size(); ++i) {
            cout << left << setw(4) << i + 1;
            col_stu.at(i).display_info();
        }
    }

    cout << "**************各学生单科排名**************" << endl;
    cout<<endl;
    cout<<"         ********小学生排名********         "<<endl;
    if (checkfile(store_content[0])) {
        sort_prim();
    }
    cout<<endl;
    cout<<"         ********中学生排名********         "<<endl;
    if (checkfile(store_content[1])) {
        sort_high();
    }
    cout<<endl;
    cout<<"         ********大学生排名********         "<<endl;
    if (checkfile(store_content[2])) {
        sort_col();
    }
    system("pause");
}

//9.2 单科排名
void sort_prim() {
    cout << "       ********小学生语文排名********       " << endl;
    sort(prim_stu.begin(), prim_stu.end(), cmp_prim_chi);
    for (int i = 0; i < prim_stu.size(); ++i) {
        cout << left << setw(4) << i + 1;
        prim_stu.at(i).display_info();
    }
    cout << endl;
    cout << "       ********小学生数学排名********       " << endl;
    sort(prim_stu.begin(), prim_stu.end(), cmp_prim_math);
    for (int i = 0; i < prim_stu.size(); ++i) {
        cout << left << setw(4) << i + 1;
        prim_stu.at(i).display_info();
    }
    cout << endl;
    cout << "       ********小学生英语排名********       " << endl;
    sort(prim_stu.begin(), prim_stu.end(), cmp_prim_eng);
    for (int i = 0; i < prim_stu.size(); ++i) {
        cout << left << setw(4) << i + 1;
        prim_stu.at(i).display_info();
    }
    cout << endl;
    cout << endl;
}
void sort_high() {
    cout << "       ********中学生语文排名********       " << endl;
    sort(high_stu.begin(), high_stu.end(), cmp_high_chi);
    for (int i = 0; i < high_stu.size(); ++i) {
        cout << left << setw(4) << i + 1;
        high_stu.at(i).display_info();
    }
    cout << endl;
    cout << "       ********中学生数学排名********       " << endl;
    sort(high_stu.begin(), high_stu.end(), cmp_high_math);
    for (int i = 0; i < high_stu.size(); ++i) {
        cout << left << setw(4) << i + 1;
        high_stu.at(i).display_info();
    }
    cout << endl;
    cout << "       ********中学生英语排名********       " << endl;
    sort(high_stu.begin(), high_stu.end(), cmp_high_eng);
    for (int i = 0; i < high_stu.size(); ++i) {
        cout << left << setw(4) << i + 1;
        high_stu.at(i).display_info();
    }
    cout << endl;
    cout << "       ********中学生地理排名********       " << endl;
    sort(high_stu.begin(), high_stu.end(), cmp_high_geo);
    for (int i = 0; i < high_stu.size(); ++i) {
        cout << left << setw(4) << i + 1;
        high_stu.at(i).display_info();
    }
    cout << endl;
    cout << "       ********中学生历史排名********       " << endl;
    sort(high_stu.begin(), high_stu.end(), cmp_high_his);
    for (int i = 0; i < high_stu.size(); ++i) {
        cout << left << setw(4) << i + 1;
        high_stu.at(i).display_info();
    }
    cout << endl;
    cout << endl;
}
void sort_col() {
    cout << "       ******** 大学生专业排名********       " << endl;
    sort(col_stu.begin(), col_stu.end(), cmp_col_pro);
    for (int i = 0; i < col_stu.size(); ++i) {
        cout << left << setw(4) << i + 1;
        col_stu.at(i).display_info();
    }
    cout << endl;
    cout << "       ******** 大学生英语排名********       " << endl;
    sort(col_stu.begin(), col_stu.end(), cmp_col_eng);
    for (int i = 0; i < col_stu.size(); ++i) {
        cout << left << setw(4) << i + 1;
        col_stu.at(i).display_info();
    }
    cout << endl;
    cout << "       ******** 大学生课设排名********       " << endl;
    sort(col_stu.begin(), col_stu.end(), cmp_col_des);
    for (int i = 0; i < col_stu.size(); ++i) {
        cout << left << setw(4) << i + 1;
        col_stu.at(i).display_info();
    }
    cout << endl;
    cout << "       ******** 大学生高数排名********       " << endl;
    sort(col_stu.begin(), col_stu.end(), cmp_col_math);
    for (int i = 0; i < col_stu.size(); ++i) {
        cout << left << setw(4) << i + 1;
        col_stu.at(i).display_info();
    }
}
//排名函数
bool cmp_prim_chi(primary_student& a, primary_student& b) {
    return a.getChineseGrade() > b.getChineseGrade();
}
bool cmp_prim_math(primary_student& a, primary_student& b) {
    return a.getMathGrade() > b.getMathGrade();
}
bool cmp_prim_eng(primary_student& a, primary_student& b) {
    return a.getEnglishGrade() > b.getEnglishGrade();
}

bool cmp_high_chi(high_student& a, high_student& b) {
    return a.getChineseGrade() > b.getChineseGrade();
}
bool cmp_high_math(high_student& a, high_student& b) {
    return a.getMathGrade() > b.getMathGrade();
}
bool cmp_high_eng(high_student& a, high_student& b) {
    return a.getEnglishGrade() > b.getEnglishGrade();
}
bool cmp_high_geo(high_student& a, high_student& b) {
    return a.getGeographyGrade() > b.getGeographyGrade();
}
bool cmp_high_his(high_student& a, high_student& b) {
    return a.getHistoryGrade() > b.getHistoryGrade();
}

bool cmp_col_pro(college_student& a, college_student& b) {
    return a.getProfessionGrade() > b.getProfessionGrade();
}
bool cmp_col_eng(college_student& a, college_student& b) {
    return a.getProEngGrade() > b.getProEngGrade();
}
bool cmp_col_des(college_student& a, college_student& b) {
    return a.getProgramDesignGrade() > b.getProgramDesignGrade();
}
bool cmp_col_math(college_student& a, college_student& b) {
    return a.getProMathGrade() > b.getProMathGrade();
}

//********************************************************

//显示操作对象
int show_operate_obj() {
    cout << "请选择要操作的学生类" << endl;
    cout << "1. 小学生" << endl;
    cout << "2. 中学生" << endl;
    cout << "3. 大学生" << endl;
    cout << "0. 返回上一级" << endl;
    int n;
    cin >> n;
    if ((n >= 1) && (n <= 3)) {
        return  n;
    }
    else if (n == 0) {
        return 0;
    }
    else {
        cout << "请输入0-3的整数！" << endl;
        system("pause");
        system("cls");
        return show_operate_obj();
    }
}


