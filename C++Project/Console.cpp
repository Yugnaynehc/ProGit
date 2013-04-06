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
    if(student!=NULL) delete student;//�ͷ�ѧ����Ϣ

    int i;
    for(i=0;i<ocNum;i++)
	delete oc[i];//�ͷ����еı��޿γ�
    for(i=0;i<ecNum;i++)
	delete ec[i];//�ͷ����е�ѡ�޿γ�
}

int Console::run()
{
    int choice;
    bool flag = false;

    buildCourse();  //�������еĿ�ѡ�γ̶���
    cout << "��ѡ��ѧ����Ϣ�����뷽ʽ" << endl
	 << "\t1. �ֶ�����" << endl
	 << "\t2. ���ļ�Student.in�ж���" << endl;
    cin >> choice;

    if (choice!=1 && choice!=2)
    {
	cout << "������󣬳��򽫱�����ֹ" << endl;
	return 1;
    }
    while (!flag)
    {
	try
	{
	    if (choice == 1)
	    {
		buildStudent(); //����ѧ������
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
                cout << "�����쳣�˳�!\n";
                return 1;
            }
	}
    }

    choice=displayMenu();
    while (choice!=0)
    {
	switch (choice)
	{
	case 1: //ѡ���޿�
	    student->addCourse(selectObligatoryCourse());
	    break;
	case 2: //ѡѡ�޿�
	    student->addCourse(selectElectiveCourse());
	    break;
	case 3:
	    AutoSelect();
	    break;
	case 4: //���ѧ��ѡ����Ϣ���������ɼ���
	    student->printChoice();
	    break;
	case 5: //����ѧ���ɼ�
	    setCourseScore();
	    break;
	case 6: //��ѯ���ſγ̳ɼ�
	    student->printEveryChoice();
	    break;
	case 7: //��ѯ����ɼ�
	    student->printCalcCredit();
	    break;
	case 8: //��ѯѧ��������Ϣ
	    cout << *student;
	    break;
	case 9: //���ѧ��������Ϣ
	{
	    ofstream fout("Student.out", ios::out);
	    fout<<*student;
	    cout << "ѧ����Ϣ�ѱ����µ��ļ�Student.out��\n";
	    fout.close();
	    break;
	}
	case 10: //��ѯĳ�ſγ̳ɼ��������ã�
	{
	    int t;
	    bool flag = false;
	    cout << "���пγ�������" << student->getCourseNumber() << endl;

	    while (!flag)
	    {
		cout << "������γ̴���(0��ʼ)��";
		try
                {
                    cin >> t;
                    if (cin.fail())
                    {
                        cin.clear();		//���������
                        cin.ignore();	    //�Ƴ������ַ�
                        throw TypeError();
                    }
                    cout << (*student)[t] << '\t' << "�ɼ�: " << (*student)[t].getScore() << endl;
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
    cout<<" ---------��ª��ѧ��ѡ��ϵͳ-���˵�---------\n"
	<<"|\t1. ѡ���޿γ�                       |\n"
	<<"|\t2. ѡѡ�޿γ�                       |\n"
	<<"|\t3. ���ļ�Select.in�л�ȡѡ����Ϣ    |\n"
	<<"|\t4. �鿴ѡ�����                     |\n"
	<<"|\t5. ���ÿγ̳ɼ�                     |\n"
	<<"|\t6. ��ѯ�γ̳ɼ�                     |\n"
	<<"|\t7. ��ѯ����ɼ�                     |\n"
	<<"|\t8. ��ѯѧ��������Ϣ                 |\n"
	<<"|\t9. ���ѧ��������Ϣ                 |\n"
	<<"|\t10. ��ѯĳ�ſγ̳ɼ��������ã�      |\n"
	<<"|\t0. �˳�ϵͳ                         |\n"
	<<" -------------------------------------------\n"
	<<"��ѡ������Ĳ���(0~10)��";
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
            cout << "�ļ�Select.in���ڴ��󣬵���ѡ����Ϣʧ��" << endl;
            break;
        }
    }

}

ObligatoryCourse* Console::selectObligatoryCourse()     //ѡ�α��޿Σ����ؿγ̵�ַ
{
    int i, choice = -1;
    cout  << '\t' << "������б��޿γ���ѡ��һ�ſγ�:\n";
    while((choice>ocNum)||(choice<0))
    {
	for(i=0;i<ocNum;++i)
	{
	    cout << "\t" << i+1 << "." << *oc[i] << '\n';
	}
	cout<<"\t0.ȡ������ѡ��\n";
	cout<<"��Ҫѡ�ı��޿γ��ǣ�";
	cin>>choice;
    }
    if (choice!=0)
        if (!ocFlag[choice-1])
        {
            ocFlag[choice-1] = true;
            return oc[choice-1];
        }
        else
            cout << "���γ��ѱ�ѡ��\n";
    else;
    return NULL;
}

ElectiveCourse* Console::selectElectiveCourse()     //ѡ��ѡ�޿Σ����ؿγ̵�ַ
{
    int i, choice = -1;
    cout  << '\t' <<  "�������ѡ�޿γ���ѡ��һ�ſγ�:\n";
    while((choice>ecNum)||(choice<0))
    {
	for(i=0;i<ecNum;++i)
	{
	    cout << "\t" << i+1 << "." << *ec[i] << '\n';   //�����ƺ�<<���̳��ˣ���Ԫ�ļ̳У���
	}
	cout<<"\t0.ȡ������ѡ��\n";
	cout<<"��Ҫѡ��ѡ�޿γ��ǣ�";
	cin>>choice;
    }
    if (choice!=0)
        if (!ecFlag[choice-1])
        {
            ecFlag[choice-1] = true;
            return ec[choice-1];
        }
        else
            cout << "���γ��ѱ�ѡ��\n";
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

    cout << "������ѧ������: ";
    cin >> name;
    cout << "������ѧ������: ";
    cin >> birthDate;
    student=new Student(name, birthDate);
    return *this;
}

Console& Console::buildStudent_fromfile()
{
    char name[50];
    CDate birthDate;

    ifstream fin("Student.in", ios::in);
    //cout << "������ѧ������: ";
    fin >> name;
    //cout << "������ѧ������";
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
