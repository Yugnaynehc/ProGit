#ifndef CONSOLE_H
#define CONSOLE_H

#include "Student.h"
#include "Course.h"

//控制台类，实现用户界面
class Console
{
    public:
        int run();    //运行控制台

        Console();
        virtual ~Console();
    protected:

    private:
        int displayMenu() const;    //显示系统主菜单
        ObligatoryCourse* selectObligatoryCourse();     //选课必修课，返回课程地址
		ElectiveCourse* selectElectiveCourse();     //选课选修课，返回课程地址
		void AutoSelect();  //从文件Select.in中获得选项信息
        bool setCourseScore();       //设置所有的课程成绩

        Console& buildStudent();//构造学生对象
        Console& buildStudent_fromfile();
        Console& buildCourse();//构造所有的可选课程（包括必修和选修课）

        Student *student;           //当前学生对象
        ObligatoryCourse *oc[MAX_SIZE];		//全部可选的必修课程清单
        ElectiveCourse *ec[MAX_SIZE];		//全部可选的选修课程清单
        bool ocFlag[MAX_SIZE];  //必修课选择标记
        bool ecFlag[MAX_SIZE];  //选修课选择标记
        int ocNum;      //可选的必修课程实际数量
        int ecNum;	//可选的选修课程实际数量
};

#endif // CONSOLE_H
