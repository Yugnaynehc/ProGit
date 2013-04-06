#include "Console.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "CDate.h"
#include "DateError.h"
#include "TypeError.h"
#include <fstream>
#include <iostream>

using namespace std;

Console::Console()
{
    //ctor
    ocNum=0;
    ecNum=0;
}

Console::~Console()
{
    //dtor
    if(student!=NULL) delete student;//释放学生信息

    int i;
    for(i=0;i<ocNum;i++)
	delete oc[i];//释放所有的必修课程
    for(i=0;i<ecNum;i++)
	delete ec[i];//释放所有的选修课程
}

int Console::run()
{
    int choice;
    bool flag = false;

    buildCourse();  //构造所有的可选课程对象
    cout << "请选择学生信息的输入方式" << endl
	 << "\t1. 手动输入" << endl
	 << "\t2. 从文件Student.in中读入" << endl;
    cin >> choice;

    if (choice!=1 && choice!=2)
    {
	cout << "输入错误，程序将被迫终止" << endl;
	return 1;
    }
    while (!flag)
    {
	try
	{
	    if (choice == 1)
	    {
		buildStudent(); //构造学生对象
		flag = true;
	    }
	    else if (choice == 2)
	    {
		buildStudent_fromfile();
		flag = true;
	    }
	}
	catch (MyException &er)
	{
	    cout << er.what() << endl;
	    if (choice == 1)
                continue;
            else
            {
                cout << "程序异常退出!\n";
                return 1;
            }
	}
    }

    choice=displayMenu();
    while (choice!=0)
    {
	switch (choice)
	{
	case 1: //选必修课
	    student->addCourse(selectObligatoryCourse());
	    break;
	case 2: //选选修课
	    student->addCourse(selectElectiveCourse());
	    break;
	case 3:
	    AutoSelect();
	    break;
	case 4: //输出学生选课信息（不包括成绩）
	    student->printChoice();
	    break;
	case 5: //设置学生成绩
	    setCourseScore();
	    break;
	case 6: //查询各门课程成绩
	    student->printEveryChoice();
	    break;
	case 7: //查询积点成绩
	    student->printCalcCredit();
	    break;
	case 8: //查询学生所有信息
	    cout << *student;
	    break;
	case 9: //输出学生所有信息
	{
	    ofstream fout("Student.out", ios::out);
	    fout<<*student;
	    cout << "学生信息已被更新到文件Student.out中\n";
	    fout.close();
	    break;
	}
	case 10: //查询某门课程成绩（测试用）
	{
	    int t;
	    bool flag = false;
	    cout << "共有课程门数：" << student->getCourseNumber() << endl;

	    while (!flag)
	    {
		cout << "请输入课程代号(0起始)：";
		try
                {
                    cin >> t;
                    if (cin.fail())
                    {
                        cin.clear();		//清除错误标记
                        cin.ignore();	    //移除错误字符
                        throw TypeError();
                    }
                    cout << (*student)[t] << '\t' << "成绩: " << (*student)[t].getScore() << endl;
                    flag = true;
                }
                catch (MyException &er)
                {
                    cout << er.what() << endl;
                }
	    }
	}
	default:
	    break;
	}
	choice=displayMenu();
    }

    return 0;
}

int Console::displayMenu() const
{
    int choice=0;
    cout << '\n';
    cout<<" ---------简陋的学生选课系统-主菜单---------\n"
	<<"|\t1. 选必修课程                       |\n"
	<<"|\t2. 选选修课程                       |\n"
	<<"|\t3. 从文件Select.in中获取选课信息    |\n"
	<<"|\t4. 查看选课情况                     |\n"
	<<"|\t5. 设置课程成绩                     |\n"
	<<"|\t6. 查询课程成绩                     |\n"
	<<"|\t7. 查询积点成绩                     |\n"
	<<"|\t8. 查询学生所有信息                 |\n"
	<<"|\t9. 输出学生所有信息                 |\n"
	<<"|\t10. 查询某门课程成绩（测试用）      |\n"
	<<"|\t0. 退出系统                         |\n"
	<<" -------------------------------------------\n"
	<<"请选择所需的操作(0~10)：";
    cin>>choice;

    return choice;
}

void Console::AutoSelect()
{
    int choice, course;
    ifstream fin("Select.in", ios::in);
    while (fin >> choice >> course)
    {
        if (choice == 1)
        {
            student->addCourse(oc[course-1]);
            ocFlag[choice-1] = true;
        }

        else if (choice == 2)
        {
            student->addCourse(ec[course-1]);
            ecFlag[choice-1] = true;
        }

        else
        {
            cout << "文件Select.in存在错误，导入选课信息失败" << endl;
            break;
        }
    }

}

ObligatoryCourse* Console::selectObligatoryCourse()     //选课必修课，返回课程地址
{
    int i, choice = -1;
    cout  << '\t' << "请从下列必修课程中选择一门课程:\n";
    while((choice>ocNum)||(choice<0))
    {
	for(i=0;i<ocNum;++i)
	{
	    cout << "\t" << i+1 << "." << *oc[i] << '\n';
	}
	cout<<"\t0.取消本次选课\n";
	cout<<"您要选的必修课程是：";
	cin>>choice;
    }
    if (choice!=0)
        if (!ocFlag[choice-1])
        {
            ocFlag[choice-1] = true;
            return oc[choice-1];
        }
        else
            cout << "本课程已被选过\n";
    else;
    return NULL;
}

ElectiveCourse* Console::selectElectiveCourse()     //选课选修课，返回课程地址
{
    int i, choice = -1;
    cout  << '\t' <<  "请从下列选修课程中选择一门课程:\n";
    while((choice>ecNum)||(choice<0))
    {
	for(i=0;i<ecNum;++i)
	{
	    cout << "\t" << i+1 << "." << *ec[i] << '\n';   //这里似乎<<被继承了？友元的继承？？
	}
	cout<<"\t0.取消本次选课\n";
	cout<<"您要选的选修课程是：";
	cin>>choice;
    }
    if (choice!=0)
        if (!ecFlag[choice-1])
        {
            ecFlag[choice-1] = true;
            return ec[choice-1];
        }
        else
            cout << "本课程已被选过\n";
    else;
    return NULL;
}


bool Console::setCourseScore()
{

    for(int i=0;i<student->getCourseNumber();++i)
    {
	bool flag = false;
	while (!flag)
	{
	    try
            {
                cout << '\t' << *(student->getcourseList(i))<< '\t';
                student->getcourseList(i)->setScore();
                flag = true;
            }
            catch (MyException &er)
            {
                cout << er.what() << endl;
                continue;
            }
	}
    }

    return true;
}

Console& Console::buildStudent()
{
    char name[50];
    CDate birthDate;

    cout << "请输入学生姓名: ";
    cin >> name;
    cout << "请输入学生生日: ";
    cin >> birthDate;
    student=new Student(name, birthDate);
    return *this;
}

Console& Console::buildStudent_fromfile()
{
    char name[50];
    CDate birthDate;

    ifstream fin("Student.in", ios::in);
    //cout << "请输入学生姓名: ";
    fin >> name;
    //cout << "请输入学生生日";
    fin >> birthDate;
    student=new Student(name, birthDate);
    return *this;
}

Console& Console::buildCourse()
{
    char name[20];
    int credit;

    ifstream fin("ObCourse.in",ios::in);
    while (fin >> name >> credit)
    {
        oc[ocNum] = new ObligatoryCourse(name, credit);
        ocNum++;
    }
    for (int i=0;i<ocNum;++i)
        ocFlag[i] = false;
    fin.close();


    fin.open("ElCourse.in",ios::in);
    while (fin >> name >> credit)
    {
        ec[ecNum] = new ElectiveCourse(name, credit);
        ecNum++;
    }
    for (int i=0;i<ecNum;++i)
        ecFlag[i] = false;
    fin.close();

    return *this;
}
