//
// Created by 33559 on 2022/11/28.
//

#ifndef STUDENT_STUDENT_H
#define STUDENT_STUDENT_H
#include <fstream>
#include <iostream>
#include "Student.h"
using namespace std;

class Grade{
public:
    int C_Lan;
    int math;
    int English;
    int Sum ;
};

class Student{
public:
    int Student_iD;
    string StudentName;
    Grade grade;
};

struct Node{
    Student student;
    Node *next;
};

class Operation{
public:
    void initStudent(Node *&head);
    bool addStudent(Node *&head);//包含录入，保存 -- 通过这个类间接访问Student类//还要写文件操作
    bool eraseStudent(Node *&head);//输入学号删，输入名字删
    bool modifyStudent(Node *&head);//只能改学号和名字//输入学号改，输入名字改
    bool findStudent(Node *&head);
    bool insertStudent(Node *&head);
    void newFile_AllRank(Node *head);
    void find_OneClassTheSunk(Node *head,int className);
    void find_OneClassMoreNinety(Node *&head,int className);
    int find_maxGrade(Node *head , int className);
    double find_OneClassAverageGrade(Node *head,int className);


    void testDisplay(Node *&head);
    void NewFileDisplay(Node *&head);
    void showOne(Node *&head);
    void show_find_id(Node *head ,int id);//改
    void show_find_name(Node *head ,string name);
    void show_find_maxGrade(Node *head ,int max, int className);
};

#endif //STUDENT_STUDENT_H
