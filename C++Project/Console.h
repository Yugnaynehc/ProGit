#ifndef CONSOLE_H
#define CONSOLE_H

#include "Student.h"
#include "Course.h"

//����̨�࣬ʵ���û�����
class Console
{
    public:
        int run();    //���п���̨

        Console();
        virtual ~Console();
    protected:

    private:
        int displayMenu() const;    //��ʾϵͳ���˵�
        ObligatoryCourse* selectObligatoryCourse();     //ѡ�α��޿Σ����ؿγ̵�ַ
		ElectiveCourse* selectElectiveCourse();     //ѡ��ѡ�޿Σ����ؿγ̵�ַ
		void AutoSelect();  //���ļ�Select.in�л��ѡ����Ϣ
        bool setCourseScore();       //�������еĿγ̳ɼ�

        Console& buildStudent();//����ѧ������
        Console& buildStudent_fromfile();
        Console& buildCourse();//�������еĿ�ѡ�γ̣��������޺�ѡ�޿Σ�

        Student *student;           //��ǰѧ������
        ObligatoryCourse *oc[MAX_SIZE];		//ȫ����ѡ�ı��޿γ��嵥
        ElectiveCourse *ec[MAX_SIZE];		//ȫ����ѡ��ѡ�޿γ��嵥
        bool ocFlag[MAX_SIZE];  //���޿�ѡ����
        bool ecFlag[MAX_SIZE];  //ѡ�޿�ѡ����
        int ocNum;      //��ѡ�ı��޿γ�ʵ������
        int ecNum;	//��ѡ��ѡ�޿γ�ʵ������
};

#endif // CONSOLE_H
