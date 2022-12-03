#include "Student.h"
#include "Login.h"
#include "Window.h"
int main()
{
    cout << "Please enter account and password"<<endl;
    Node *StudentManage = new Node;
    StudentManage ->next = nullptr;
    Operation op;
    op.initStudent(StudentManage);

    while(1)
    {
        int count = 0;
        for (int i = 0; i < 3; ++i) {
            if (login())
                break;
            count ++;
        }
        if (count == 3)
            break;
        window();
        int num;
        while(cin >> num)
        {
            if (num == 1)
                op.addStudent(StudentManage);
            else if (num == 2)
                op.testDisplay(StudentManage);
            else if (num == 3)
                op.findStudent(StudentManage);
            else if (num == 4)
                op.modifyStudent(StudentManage);
            else if (num == 5)
                op.eraseStudent(StudentManage);
            else if (num == 6)
                op.insertStudent(StudentManage);
            else if (num == 7)
                op.newFile_AllRank(StudentManage);
            else if (num == 8)
            {
                int className;
                function();
                cin >> className;
                int max = op.find_maxGrade(StudentManage,className);
                op.show_find_maxGrade(StudentManage,max,className);
            }
            else if (num == 9)
            {
                int className;
                double average;
                function();
                cin >> className;
                average = op.find_OneClassAverageGrade(StudentManage,className);
                cout << average << endl << endl;
            }
            else if (num == 10)
            {
                int className;
                function();
                cin >> className;
                op.find_OneClassMoreNinety(StudentManage,className);
            }
            else if (num == 11)
            {
                int className;
                function();
                cin >> className;
                op.find_OneClassTheSunk(StudentManage,className);
            }
            else if (num == 0)
                break;
            else
                cout << "Wrong Entering!Again please!" <<endl;

            cout << "Operating is Okay.."<<endl;
            cout << "Come back the main List now ....." <<endl;
            cout << "Please enter the ENTER" << endl;
            cin.get();
            if (cin.get() == '\n')
                window();
        }
        break;
    }
    cout << "Welcome next time" <<endl;
    return 0;
}
