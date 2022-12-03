//
// Created by 33559 on 2022/11/28.
//

#include "Student.h"
void Operation::showOne(Node *&head)
{
    cout << "Name\t" <<  "IdNumber\t" << "C_language\t"
         << "Math\t" << "English\t" << "Sum" << endl;
    Node *cur = head;
    cout << cur ->student.StudentName << "\t" ;
    cout << cur ->student.Student_iD << "\t\t";
    cout << cur ->student.grade.C_Lan << "\t\t"
         << cur ->student.grade.math << "\t"
         << cur ->student.grade.English << "\t";
    cur -> student.grade.Sum =
            cur ->student.grade.C_Lan+
            cur ->student.grade.math +
            cur ->student.grade.English;
    cout << cur ->student.grade.Sum <<endl;
}
void Operation::testDisplay(Node *&head)
{
    Node *cur = head;
    cur = cur -> next;
    cout << "Name\t" <<  "IdNumber\t" << "C_language\t"
    << "Math\t" << "English\t" << "Sum" << endl;
    while(cur)
    {
        cout << cur ->student.StudentName << "\t" ;
        cout << cur ->student.Student_iD << "\t\t";
        cout << cur ->student.grade.C_Lan << "\t\t"
             << cur ->student.grade.math << "\t"
             << cur ->student.grade.English << "\t";
        cur -> student.grade.Sum =
                cur ->student.grade.C_Lan+
                cur ->student.grade.math +
                cur ->student.grade.English;
        cout << cur ->student.grade.Sum <<endl;
        cur = cur ->next;
    }
}
void Operation::NewFileDisplay(Node *&head)
{
    ofstream ofs;
    ofs.open("D:\\Homework\\C\\Rank.txt",ios::out);
    Node *cur = head;
    cur = cur -> next;
    ofs << "Name\t" <<  "IdNumber\t" << "C_language\t"
         << "Math\t" << "English\t" << "Sum" << endl;
    while(cur)
    {
        ofs << cur ->student.StudentName << "\t" ;
        ofs << cur ->student.Student_iD << "\t\t";
        ofs << cur ->student.grade.C_Lan << "\t\t"
             << cur ->student.grade.math << "\t"
             << cur ->student.grade.English << "\t";
        cur -> student.grade.Sum =
                cur ->student.grade.C_Lan+
                cur ->student.grade.math +
                cur ->student.grade.English;
        ofs << cur ->student.grade.Sum <<endl;
        cur = cur ->next;
    }
    ofs.close();
}



void Operation::initStudent(Node *&head)
{
    Node *cur = head;
    for (int i = 0; i < 2; ++i) {
        Node *temp = new Node;
        temp ->student.Student_iD = 101 + i;
        temp ->student.StudentName = "Zhou";
        temp ->student.grade.English = 99+i;
        temp ->student.grade.math = 99+i;
        temp ->student.grade.C_Lan = 10;
        cur ->next = temp;
        cur = temp;
        temp ->next = nullptr;
    }
    head ->next->next->student.StudentName = "Zhao";
}

bool Operation::addStudent(Node *&head)
{
    cout << "***** Add Student *****" <<endl <<endl;
    Node *cur = head;
    while (cur ->next)
    {
        cur = cur ->next;
    }
    cout << "How many Student you wanna add?";
    int size;
    cin >> size;
    for (int i = 0; i < size; ++i) {
        Node *temp = new Node;
        cout << "please enter your number:";
        cin >> temp ->student.Student_iD;
        cout << "please enter your name:";
        cin >> temp ->student.StudentName;
        cout << "Please enter your C_Lan grade:";
        cin >> temp->student.grade.C_Lan ;
        cout << "Please enter your math grade:" ;
        cin >> temp ->student.grade.math ;
        cout << "Please enter your English grade:" ;
        cin >> temp ->student.grade.English;
        cur->next = temp;
        cur = temp;
        temp ->next = nullptr;
        cout << endl << "Add Successfully!" <<endl << endl;
        if (i < size - 1)
            cout << "Please enter the " << i + 2 << " Student" << endl;
    }
    cout << endl;
    return true;
}

bool Operation::eraseStudent(Node *&head)
{
    cout << "*****  Erase Student  *****" << endl <<endl;
    Node *prev = head;
    Node *delP = head->next;
    cout << "You delete the student by entering the name or ID?" << endl;
    string way;
    cin >> way;
    if (way == "name")
    {
        cout << "Please enter(name or ID) the student you want to delete:";
        string name;
        cin >> name;
        while(delP)
        {
            if (delP->student.StudentName == name)
            {
                prev ->next = delP ->next;
                delete delP;
            }
            else if (delP ->next == nullptr)
                return false;
            delP = delP ->next;
            prev = prev ->next;
        }
    }
    else
    {
        cout << "Please enter(name or ID) the student you want to delete:";
        int id;
        cin >> id;
        while(delP)
        {
            if (delP->student.Student_iD == id)
            {
                prev ->next = delP ->next;
                delete delP;
            }
            else if (delP ->next == nullptr)
                return false;
            delP = delP ->next;
            prev = prev ->next;
        }
    }
    return true;
}

bool Operation::modifyStudent(Node *&head)
{
    //输入之前的学号或者名字然后再选择修改啥
    cout << "***** Modify Student *****" << endl << endl;
    Node *modify = head;
    cout << "Enter the way of modify(name or id):";
    string way;
    cin >> way;
    if (way == "name")
    {
        cout << "Enter the name you wanna find" << endl;
        string name;
        cin >> name;
        while(modify)
        {
            if (modify->student.StudentName == name)
            {
                Operation::showOne(modify);
                cout << "Enter 1 -> name ;"
                        "Enter 2 -> ID "<< endl;
                int num ;
                cin >> num;
                int change_id;
                string find_name;
                switch (num) {
                    case 1:
                        cout << "Enter what you wanna change:";
                        cin >> find_name;
                        modify->student.StudentName = find_name;
                        break;
                    case 2:
                        cout << "Enter what you wanna change:";
                        cin >> change_id;
                        modify->student.Student_iD = change_id;
                        break;
                    default:
                        cout << "Bad Enter!" <<endl;
                }
            }
            else if (modify ->next == nullptr)
                return false;
            modify = modify ->next;
        }
    }
    else
    {
        cout << "Enter the id you wanna find" << endl;
        int id;
        cin >> id;
        while(modify)
        {
            if (modify->student.Student_iD == id)
            {
                Operation::showOne(modify);
                cout << "Enter 1 -> name ;"
                        "Enter 2 -> ID "<< endl;
                int num ;
                cin >> num;
                int change_id;
                string find_name;
                switch (num) {
                    case 1:
                        cout << "Enter what you wanna change:";
                        cin >> find_name;
                        modify->student.StudentName = find_name;
                        break;
                    case 2:
                        cout << "Enter what you wanna change:";
                        cin >> change_id;
                        modify->student.Student_iD = change_id;
                        break;
                    default:
                        cout << "Bad Enter!" <<endl;
                }
            }
            else if (modify ->next == nullptr)
                return false;
            modify = modify ->next;
        }
    }
    return true;
}
void Operation::show_find_id(Node *head, int id)
{
    head = head ->next;
    while(head->student.Student_iD != id)
    {
        head = head ->next;
    }
    showOne(head);
}
void Operation::show_find_name(Node *head, string name) {
    head = head ->next;
    while(head->student.StudentName != name)
    {
        head = head ->next;
    }
    showOne(head);
}
bool Operation::findStudent(Node *&head)
{
    cout << "*****  Find   Student  *****" <<endl << endl;
    Node *find = head;
    cout << "Enter the student's id or name that you wanna find" << endl;
    cout << "If you enter the name enter 1 ,enter the id enter the 2 please" <<endl;
    int num ;
    cin >> num;
    string find_name;
    int find_id;
    switch (num) {
        case 1:
            cout << "Enter what you wanna find:";
            cin >> find_name;
            show_find_name(find,find_name);
            break;

        case 2:
            cout << "Enter what you wanna find:";
            cin >> find_id;
            show_find_id(find,find_id);
            break;

        default:
            cout << "Bad Enter!" <<endl;            
    }
}

void Operation::find_OneClassTheSunk(Node *head, int className)
{
    cout << "***** Show Student Grade < 60  *****" <<endl << endl;
    Node *cur = head ->next;
    if (className == 1)
    {
        int count = 0;
        while(cur)
        {
            if (cur ->student.grade.C_Lan < 60)
            {
                showOne(cur);
                count ++;
            }
            cur = cur ->next;
        }
        if (count == 0)
            cout << "congratulation! There is No One Fail!" <<endl << endl;
    }
    else if (className == 2)
    {
        int count = 0;
        while(cur)
        {
            if (cur ->student.grade.math < 60)
            {
                showOne(cur);
                count++;
            }
            cur = cur ->next;
        }
        if (count == 0)
            cout << "congratulation! There is No One Fail!" <<endl <<endl;
    }
    else if(className == 3)
    {
        int count = 0;
        while(cur)
        {
            if (cur ->student.grade.English < 60)
            {
                showOne(cur);
                count ++;
            }
            cur = cur ->next;
        }
        if (count == 0)
            cout << "congratulation! There is No One Fail!" <<endl <<endl;
    }
}

void Operation::find_OneClassMoreNinety(Node *&head, int className)
{
      cout << "*****  Show Student Grade >=90  *****" <<endl << endl;

    Node *cur = head ->next;
    if (className == 1)
    {
        int count = 0;
        while(cur)
        {
            if (cur ->student.grade.C_Lan >= 90)
            {
                showOne(cur);
                count++;
            }
            cur = cur ->next;
        }
        if (count == 0)
            cout << "Terribly! There is No One fantastic in this exam!" <<endl <<endl;
    }
    else if (className == 2)
    {
        int count = 0;
        while(cur)
        {
            if (cur ->student.grade.math >= 90)
            {
                showOne(cur);
                count++;
            }
            cur = cur ->next;
        }
        if (count == 0)
            cout << "Terribly! There is No One fantastic in this exam!" <<endl <<endl;
    }
    else if(className == 3)
    {
        int count = 0;
        while(cur)
        {
            if (cur ->student.grade.English >= 90)
            {
                showOne(cur);
                count++;
            }
            cur = cur ->next;
        }
        if (count == 0)
            cout << "Terribly! There is No One fantastic in this exam!" <<endl <<endl;
    }
}

void Operation::show_find_maxGrade(Node *head, int max, int className)
{
    Node *cur = head ->next;
    if (className == 1)
    {
        while(cur)
        {
            if (cur ->student.grade.C_Lan >= max)
            {
                showOne(cur);
            }
            cur = cur ->next;
        }
    }
    else if (className == 2)
    {
        while(cur)
        {
            if (cur ->student.grade.math >= max)
            {
                showOne(cur);
            }
            cur = cur ->next;
        }
    }
    else if(className == 3)
    {
        while(cur)
        {
            if (cur ->student.grade.English >= max)
            {
                showOne(cur);
            }
            cur = cur ->next;
        }
    }
}

int Operation::find_maxGrade(Node *head, int className) {
    cout << "***** Find The Best Student  *****" <<endl << endl;
    int maxGrade = 0;
    Node *cur = head ->next;
    if (className == 1)
    {
        while(cur)
        {
            if (cur ->student.grade.C_Lan > maxGrade)
                maxGrade = cur ->student.grade.C_Lan;
            cur = cur ->next;
        }
    }
    if (className == 2)
    {
        while(cur)
        {
            if (cur ->student.grade.math > maxGrade)
                maxGrade = cur ->student.grade.math;
            cur = cur ->next;
        }
    }
    if (className == 3)
    {
        while(cur)
        {
            if (cur ->student.grade.English > maxGrade)
                maxGrade = cur ->student.grade.English;
            cur = cur ->next;
        }
    }
    return maxGrade;
}

double Operation::find_OneClassAverageGrade(Node *head, int className)
{
    cout << "***** Show One Class Average  *****" <<endl << endl;
    double sum = 0;
    int count = 0;
    Node *cur = head ->next;
    if (className == 1)
    {
        while(cur)
        {
            sum += cur ->student.grade.C_Lan;
            count ++;
            cur = cur ->next;
        }
    }
    if (className == 2)
    {
        while(cur)
        {
            sum += cur ->student.grade.math;
            count ++;
            cur = cur ->next;
        }
    }
    if (className == 3)
    {
        while(cur)
        {
            sum += cur ->student.grade.English;
            count ++;
            cur = cur ->next;
        }
        cout << "Average of English grade is :";
    }
    return sum / count;
}

void Operation::newFile_AllRank(Node *head)
{
    Node *prev = head;
    Node *cur = head->next;
    Node *ter = nullptr;
    while (cur != ter)
    {
        while (cur->next != ter)//不让它(cur)碰到最后的ter = nullpter
        {
            cur -> student.grade.Sum =
                    cur ->student.grade.C_Lan+
                    cur ->student.grade.math +
                    cur ->student.grade.English;
            if (cur->student.grade.Sum > cur->next -> student.grade.Sum)
            {
                prev = cur;
                cur = cur->next;
            }
            else//结点交换位置
            {
                Node *temp = cur->next;//用temp来保存好cur ->next的值
                cur->next = cur->next->next;
                temp->next = cur;
                prev->next = temp;
                prev = temp;
            }
        }
        ter = cur;//终点前置

        //起点重置
        prev = head;
        cur = head->next;
    }
    NewFileDisplay(head);
}

bool Operation::insertStudent(Node *&head)
{
    cout << "*****  Insert Student  *****" <<endl << endl;
    Node *cur = head;
    while (cur ->next)
    {
        cur = cur ->next;
    }
    int size = 1;
    for (int i = 0; i < size; ++i)
    {
        Node *temp = new Node;
        cout << "please enter your number:";
        cin >> temp ->student.Student_iD;
        cout << "please enter your name:";
        cin >> temp ->student.StudentName;
        cout << "Please enter your C_Lan grade:";
        cin >> temp->student.grade.C_Lan ;
        cout << "Please enter your math grade:" ;
        cin >> temp ->student.grade.math ;
        cout << "Please enter your English grade:" ;
        cin >> temp ->student.grade.English;
        cur->next = temp;
        cur = temp;
        temp ->next = nullptr;
    }
}




/*
cout << "Please choose what class you wanna find the best one?" << endl;
cout << "1 -> C_language , 2 -> math , 3 -> English " << endl;
*/
