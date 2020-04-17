#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#define STUSIDE 9    //学生端
#define TEACHSIDE 11   //教师端
#define INTRODUCTION 13   //规则
#define DECLARE 15    //介绍
#define LEAVE 17    //退出
#define ACCOUNT_IN 5  //  登录账户
#define PSWD_IN 8   //   登录密码
#define _OK 11  //  按钮“登录”
#define SIGN_UP 14  //注册
#define FORGET_PSWD 17  //忘记密码
#define _CANCEL 20//  按钮“取消”
#define WINDOW_X 80   //控制台窗口宽度
#define WINDOW_Y 25   //控制台窗口高度
#define DOWN 80    //键盘上键
#define UP 72     //键盘下键
#define ENTER 13  //键盘回车
#define _INPUT 3  //输入密码
#define MAKE_SURE 6  //确认密码
#define _QUESTION 9  //密保
#define _ANSWER 12   //答案
#define _YES 15 // 确认
#define _NO 18  //取消;

#define VIEW 7  //查看成绩
#define INCREASE 9 //增加成绩
#define MODIFY 11 //修改成绩
#define DELETE_GRADE 13//删除成绩
#define MODIFY_PSWD 15//修改密码
#define MODIFY_STU_PSWD 17//修改学生密码
#define LEAVE_TEACH_SIDE 19//退出教师端
typedef struct Student{
    int id;
    char pswd[11];
    char name[20];
    int c_grade;
    int math_grade;
    int english_grade;
}Student;

typedef struct node{//定义节点，数据域是一个Student类型的变量
    Student stu;
    struct node *next;
}Node;
////////////////////////////////////////////////////////链表和文件操作函数
void myExchange(Node * ,Node *);                  //将两个节点的数据域交换
Node* listSort(Node *head,const char *grade_file_name);//将文件的数据排序（从高到低）
Node* readAndWrite(Node *head,const char *file_name);//读文件到指定链表
Node* writeAndRead(Node *head,const char *file_name);//从指定链表写进文件
Node* getMinNode(Node* head);           //返回一个链表中的数据域最小的节点指针
Node* creatList(const char* file);    //创建链表
void printList(Node *head);//打印
void deleteList(Node *head);//删除整个链表
//void deleteNode(Node* head, int n);//删除单个节点
void insertNode(Node*  , const char* );//插入单个节点
/**遍历链表的函数**/
Node* searchStudentNode(Node* head ,int id);    //查找对应id的节点
Node* modifyStudentInfo(Node* head ,const char *file_name);// 修改学生信息
Node* deleteNode(Node* head, const char* file_name);
void searchCgrade(Node* head ,int id, int grade);//查找C语言成绩
void searchMgrade(Node* head ,int id, int grade);//查找数学成绩

////////////////////////////////////////////登录前函数

typedef struct teacherMesg Teacher;
struct teacherMesg{//     定义结构体：教师账号信息
    char account[11] ;
    char pswd[11] ;
    char question[50];     //密保
    char answer[30];       //答案
}teacher_mesg;

typedef struct teacherNode{
    Teacher teach;
    struct teacherNode *next;
}tNode;

void noticeCopyright();//   版权声明
void setConsoleSize();//   设置控制台大小
void printCorlor(int corlor);//   控制字体或背景颜色
void cursorGoto(int x , int y);//   控制光标
void isCursorActive(int state);//  光标是否可见
void outputContents();//    玩家登录游戏内界面
void gameUI(int color);    //   游戏装饰花边
void funnyThing();//   一些有趣的东西
int warningDialog(const char *text , const char *title ,const char *opResult);//  弹窗提示  参数：内容、标题、操作成功打印内容
void printArrow(int x , int y);//  游戏操作箭头（代替鼠标）
int choiceReact();//    一个接口 玩家在选择后处理
void moveNotice(int x,int y,const char* text);//   一个箭头操作的提示
void gameBuffer();//   仿真动态游戏界面加载
void inputAccountFace();//  打印显示用户登录界面
void signUpFace();//打印用户注册界面
void forgetPswdFace();//打印忘记密码界面
void userUI();//   用户登录账号页面及接口实现
void goToAccount();//用来输入账号及显示与否
void goToPswd();// 用来输入密码及显示与否
void saveOrNot(int is_not);//是否显示账号密码
void WelcomeUI();//玩家登录后界面
void creatAccountFace();//玩家注册页面
void creatAccount();//注册账号接口
void findPswd();//   找回密码接口
void drawItem(int face_x , int face_y,const char*);
void creatImplement(int number);
void repeatPrintPswd();//重新打印注册页面输入框内信息
void clearList(char *list,int index);//清除字符串，赋值为空串

///////////////////////////////////////登录后操作函数

void teacherOpUI();//教师端登录后操作页面框架
void teacherOPImplement();//教师操作具体实现函数
FILE *teacher_file = NULL;  //用来读写老师信息文件的指针
FILE *student_file = NULL;//指向存储学生信息的文件
char pswd1[11];  //注册框两个密码
char pswd2[11];
char question[41];     //密保
char answer[21];       //答案
int press_times;
/*游戏中有一两个小的bug影响到了美观性，但是为了不影响到其他模块正常作用，不再进行修补*/

///////////////////////////////////////////主函数
int main()
{
    //Node *head = NULL;
    srand(time(0));
    //int i = rand()%9;
    //printf("%d",i);
    setConsoleSize();//设置控制台大小
    isCursorActive(0);//光标不可见
    //printCorlor(14);//字体为黄色
    //funnyThing();//佛祖保佑..
    //system("cls");
    //gameBuffer();
    //system("cls");
    userUI();//用户登录账号密码界面
    //WelcomeUI();//用户游戏内界面
    //deleteList(head);//清除分配的链表内存
    //teacherOpUI();
    //teacherOPImplement("1779249225");
    //listSort(head,"6985924183.txt");
    //deleteList(head);
    return 0;

}
///////////////////////////////////////////登录前函数

void WelcomeUI(){//    deeperUserUI()     登录后界面及其接口
    while(1){
        int i;
        outputContents();
        i = choiceReact(32,9,2,STUSIDE,LEAVE,outputContents);
        switch(i){
          case STUSIDE :
                        break;

        case TEACHSIDE :    Sleep(1000);
                            userUI();
                        break;

     case INTRODUCTION :    system("cls");
                        break;

          case DECLARE :    system("cls");
                            noticeCopyright();
                        break;

            case LEAVE :    if(warningDialog("您确定要退出系统吗？","退出提醒","您已退出系统")){
                                exit(1);
                            }
                        break;
        }
    }
}

void drawItem(int face_x , int face_y,const char* item){//    drawItem()     在坐标(face_x,face_y)处打印一个指定字符串常量
    cursorGoto(face_x , face_y);
    printf("%s",item);
}

void noticeCopyright(){//    noticeCopyright()     输出版权信息声明及要求
    //printf("\n\n");
    gameUI(0x02);
    printCorlor(12);
    cursorGoto(2,3);
    printf("该程序原创自19级软工专业问题求解程序设计课堂实践，禁止用于一切商业用途。\n");
    cursorGoto(2,4);
    printf("如需转载请附上此声明并注明出处:\n\n");
    cursorGoto(2,5);
    printf("https://github.com/Prograper/FirstRepository/blob/master/ClassTest\n\n");
    cursorGoto(2,8);
    isCursorActive(0);
    printf("虽然这个程序又小又烂，但是我们一定要尊重版权。^_^");
    cursorGoto(2,10);
    system("pause");
    system("cls");
}

void printCorlor(int corlor){//  PrintCorlor()    接口： 输入控制控制台background和foreground颜色，以及text颜色

    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hOut,corlor);
    //CloseHandle(hOut);
    /**下面是一些参数**/
    /*
    *SetConsoleTextAttribute函数是靠一个字节的低四位来控制前景色，高四位来控制背景色
    *FOREGROUND_BLUE      字体：蓝         对应值：0X01
    *FOREGROUND_GREEN    字体：绿     对应值：0X02
    *FOREGROUND_RED       字体：红    对应值：0X04
    *FOREGROUND_INTENSITY    前景高亮   对应值：0X08
    *BACKGROUND_BLUE     背景：蓝   对应值：0X10
    *BACKGROUND_GREEN   背景：绿   对应值：0X20
    *BACKGROUND_RED     背景：红    对应值：0X40
    *BACKGROUND_INTENSITY   背景高亮   对应值：0X80
    *12  为橙色    9  为靛蓝色    14  为黄色   13  为紫色  7  为系统色（以上均是文字颜色）
    */
}

void setConsoleSize(){//    setConsoleSize()    初始化控制台尺寸为宽80   高25
    system("mode con cols=80 lines=25");
}

void cursorGoto(int x , int y){//    cursorGoto()     接口：输入控制控制台光标移动到坐标点x,y

    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD myCoord;
    myCoord.X = x;
    myCoord.Y = y;

    SetConsoleCursorPosition(hOut,myCoord);
    /****/
    //CloseHandle(hOut);
}

void isCursorActive(int state){//    isCursorActive()    接口： 输入一个值来决定光标是否隐藏,0隐藏，1显示

    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor;

    GetConsoleCursorInfo(hOut,&cursor);
    cursor.bVisible = state;
    SetConsoleCursorInfo(hOut,&cursor);
}

void outputContents(){//    outputContents()     游戏目录   接口：玩家选择目录的数字输入


    isCursorActive(0);
    //gameUI(14);
    printCorlor(13);
    cursorGoto(14,1);
    printf("                ╔════════════════╗ ");
    cursorGoto(14,2);
    printf("****************║学生成绩管理系统║ ***************");
    cursorGoto(14,3);
    printf("                ╚════════════════╝ ");
    cursorGoto(35,9);
    printf("学生端");
    cursorGoto(35,11);
    printf("教师端");
    cursorGoto(35,13);
    printf("功能介绍");
    cursorGoto(35,15);
    printf("版权声明");
    cursorGoto(35,17);
    printf("退出系统");
    moveNotice(10,23,"Tips:请用键盘上下键来控制箭头上下移动，按回车进行选择。");
}
//choiceReact()   五个参数分别是目录第一行的x，y坐标;目录间隔gap，上下端目录值(sorry 函数耦合严重)，要打印的框架函数
int choiceReact(int content_x,int content_y,int gap,int up_lim,int down_lim, void (*fOut)()){//    choicReact()
/***函数有六个参数，1、2是首行目录坐标，参数3是目录间隔，参数4、5是上、下端纵坐标，参数6是指针函数***/
    //content_x = 30;     //退三格                 //    在开始目录输出箭头指定玩家下一步操作，返回一个玩家的选择int值
    //content_y = 11;
    int sub = down_lim - up_lim;
    int user_keyboard;     //用户操作键盘键位值
    int user_choice = up_lim;
    printCorlor(14);
    printArrow(content_x , content_y);
    printCorlor(12);
    moveNotice(10,23,"Tips:请用键盘上下键来控制箭头上下移动，按回车进行选择。");
    while(1){
        fOut();
        if((user_keyboard = getch())){
            switch(user_keyboard){

                case UP: if(user_choice == up_lim){
                             system("cls");
                             fOut();
                             printCorlor(14);
                             printArrow(content_x , content_y + sub);
                             user_choice = down_lim;
                             content_y = down_lim;
                         }
                         else{
                            system("cls");
                            fOut();
                            printCorlor(14);
                            printArrow(content_x , content_y - gap);
                            content_y -= gap;
                            user_choice -= gap;
                         }
                         break;
             case DOWN: if(user_choice == down_lim){
                            system("cls");
                            fOut();
                            printCorlor(14);
                            printArrow(content_x , content_y - sub);
                            user_choice = up_lim;
                            content_y = up_lim;
                        }
                        else{
                            system("cls");
                            fOut();
                            printCorlor(14);
                            printArrow(content_x , content_y + gap);
                            content_y += gap;
                            user_choice += gap;
                        }
                        break;
            case ENTER: Sleep(400);
                        system("cls");
                        return user_choice;
                        break;
            }
        }
    }
}

void printArrow(int x , int y){//    printArrow()     这个函数输出箭头,相当于鼠标（sorry，严重耦合）
    cursorGoto(x,y);
    printf(">>>");
}

void moveNotice(int x,int y,const char* text){//    moveNotice()     用来提示箭头移动的用法
    isCursorActive(0);
    printCorlor(0x02);
    cursorGoto(x,y);
    printf("%s",text);
}

void gameUI(int color){//    gameUI()     为控制台打印出花边   参数代表颜色
    int i,j;
    printCorlor(color);
    for(i=0;i<79;i++){//     打印出一圈小花花
        for(j=0;j<=24;j++){
            if(i==0||i==78){
                drawItem(i,j,"■");
            }
            if(j==24){
                drawItem(i,j,"■");
            }
        }
    }
    printCorlor(7);
}

int warningDialog(const char *text , const char *title , const char *opResult){//    warningDialog()     退出游戏进行提示
    int result =
    MessageBox(NULL,text,TEXT(title),MB_ICONINFORMATION|MB_OKCANCEL);

        if(result == IDOK){
            printCorlor(7);
            system("cls");
            printf("\n\n%s\n\n\n\n",opResult);
            return 1;
        }
        //else if(result == IDCANCEL){}
        return 0;
}

void funnyThing(){//    funnyThing()     在首页打印出一些有趣的东西
    cursorGoto(15,0);
    printf("                   _ooOoo_\n");
    cursorGoto(15,1);
    printf("                  o8888888o\n");
    cursorGoto(15,2);
    printf("                  88\" . \"88\n");
    cursorGoto(15,3);
    printf("                  (| -_- |)\n");
    cursorGoto(15,4);
    printf("                  O\\  =  /O\n");
    cursorGoto(15,5);
    printf("               ____/`---'\\____\n");
    cursorGoto(15,6);
    printf("             .'  \\\\|     |//  `.\n");
    cursorGoto(15,7);
    printf("            /  \\\\|||  :  |||//  \\\n");
    cursorGoto(15,8);
    printf("           /  _||||| -:- |||||-  \\\n");
    cursorGoto(15,9);
    printf("           |   | \\\\\\  -  /// |   |\n");
    cursorGoto(15,10);
    printf("           | \\_|  ''\\---/''  |   |\n");
    cursorGoto(15,11);
    printf("           \\  .-\\__  `-`  ___/-. /\n");
    cursorGoto(15,12);
    printf("         ___`. .'  /--.--\\  `. . __\n");
    cursorGoto(15,13);
    printf("      .\"\" '<  `.___\\_<|>_/___.'  >'\"\".\n");
    cursorGoto(15,14);
    printf("     | | :  `- \\`.;`\\ _ /`;.`/ - ` : | |\n");
    cursorGoto(15,15);
    printf("     \\  \\ `-.   \\_ __\\ /__ _/   .-` /  /\n");
    cursorGoto(15,16);
    printf("======`-.____`-.___\\_____/___.-`____.-'======\n");
    cursorGoto(15,17);
    printf("                   `=---='\n");
    cursorGoto(15,18);
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    cursorGoto(15,19);
    printf("         佛祖保佑       永无BUG\n");
    cursorGoto(15,23);
    system("pause");

}

void gameBuffer(){//    gameBuffer()    自制 模拟进入游戏界面的缓冲效果
    int i;

    system("cls");
    gameUI(7);
    cursorGoto(7,7);
    printf("____________________________________________________________");
    cursorGoto(6,8);
    printf("||");
    cursorGoto(66,8);
    printf("||");
    cursorGoto(7,9);
    printf("￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣");
    printCorlor(9);
    cursorGoto(25,10);
    printf("加载中...加载过程不耗费流量");
    cursorGoto(7,8);
    printCorlor(12);
    Sleep(1000);
    for(i = 0; i < 30; i++){
        if(i == 2){
            Sleep(1000);
        }
        if(i > 10 && i < 24){
            Sleep(200);
        }
        if(i > 25) {
            Sleep(1500);
        }
        printf("■");
    }
    Sleep(800);
    printCorlor(9);
    cursorGoto(25,10);
    printf("加载完成。                 ");
    Sleep(2000);
    printCorlor(7);
    system("cls");
}

void userUI(){//    userUI()     用户登录界面的操作过程
    char verify_account[11];
    char verify_pswd[11];
    char verify_question[41];
    char verify_answer[21];
    int break1 = 1;//用于跳出while，标志变量
    int break2 = 1;
    int break3 = 1;
    /*int i ;
    for(i = 0; i < 10; i ++){
        teacher_mesg.account[i] = ' ';
        teacher_mesg.pswd[i] = ' ';
    }*/
    strcpy(teacher_mesg.account,"");
    strcpy(teacher_mesg.pswd,"");
    while(break1){
        int to_achieve;
        to_achieve = choiceReact(21,5,3,ACCOUNT_IN,_CANCEL,inputAccountFace);
        press_times = 0;
        switch(to_achieve){

        case ACCOUNT_IN: inputAccountFace();
                          goToAccount();
                          break;
          case PSWD_IN : inputAccountFace();
                          goToPswd();
                          break;
              case _OK : if(strcmp(teacher_mesg.account,"")==0){
                             inputAccountFace();
                             cursorGoto(52,5);
                             printCorlor(0x04);
                             printf("！请输入账号");
                         }else if(strcmp(teacher_mesg.pswd,"")==0){
                            inputAccountFace();
                            printCorlor(0x04);
                            cursorGoto(52,8);
                            printf("！请输入密码");
                         }else{/**一个文件操作，用来判断账号密码是否正确**/
                            teacher_file = fopen("Teacher.txt","r");
                            if(teacher_file == NULL){
                                warningDialog("登录失败，文件操作失误","登录失败","");
                            }else{
                                while((fscanf(teacher_file,"%s %s %s %s\n",verify_account,verify_pswd,verify_question,verify_answer)) != EOF){
                                    if(strcmp(teacher_mesg.account,verify_account) == 0){
                                            break2 = 0;
                                        if(strcmp(teacher_mesg.pswd,verify_pswd) == 0){
                                               // printf("%s\n%s\n%s",verify_account,verify_pswd,teacher_mesg.pswd);
                                                //system("pause");
                                      /**/      teacherOPImplement(verify_account);
                                            cursorGoto(31,5);
                                            printf("登录成功");
                                            break3 = 0;
                                            break;
                                        }
                                    }

                                }
                                fclose(teacher_file);
                                if(break2){
                                    warningDialog("此账号还未注册","登录失败","");
                        /***/            printf("%s\n%s\n%s",verify_account,verify_pswd,teacher_mesg.pswd);
                                    break;
                                }else{
                                    if(break3){
                                        warningDialog("密码错误，请重新检查密码","登录失败","");
                       /***/                 printf("%s\n%s\n%s",verify_account,verify_pswd,teacher_mesg.pswd);
                                        break;
                                    }

                                }

                            }

                             //gameBuffer();
                             break1 = 0;
                         }
                        /*cursorGoto(10,21);
                        printf("%styu",teacher_mesg.account);
                        cursorGoto(10,22);
                        printf("%swer",teacher_mesg.pswd);*/

                         break;
          case _CANCEL: if(warningDialog("您要放弃登录吗？","放弃登录提醒","")){
                            break1 = 0;
                        }
                         break;
         case SIGN_UP : creatAccount();
                         break;
     case FORGET_PSWD : findPswd();
                         break;
        }
    }
}

void inputAccountFace(){//    inputAccountFace()     打印用户登录界面

    printCorlor(14);
    isCursorActive(0);
    //gameUI(14);
    printCorlor(0x02);
    cursorGoto(18,1);
    printf("tips:账号为10位数字，密码由字母和数字组成");
    printCorlor(9);
    cursorGoto(24,5);
    printf("账号：");
    cursorGoto(31,4);
    printf("____________________");
    cursorGoto(30,5);
    printf("|");
    cursorGoto(51,5);
    printf("|");
    cursorGoto(31,6);
    printf("￣￣￣￣￣￣￣￣￣￣");
    cursorGoto(24,8);
    printf("密码：");
    cursorGoto(31,7);
    printf("____________________");
    cursorGoto(30,8);
    printf("|");
    cursorGoto(51,8);
    printf("|");
    cursorGoto(31,9);
    printf("￣￣￣￣￣￣￣￣￣￣");
    cursorGoto(24,11);
    printf("登录");
    printCorlor(12);
    cursorGoto(24,14);
    printf("还没有账户吗，创建一个。");
    cursorGoto(24,17);
    printCorlor(13);
    printf("忘记密码？");
    printCorlor(7);
    cursorGoto(24,20);
    printf("取消");
    moveNotice(10,23,"Tips:请用键盘上下键来控制箭头上下移动，按回车进行选择。");
    saveOrNot(1);
}

void findPswd(){/**该框架还没有实现**/
    cursorGoto(38,8);
    printf("该功能尚未开放");
    system("pause");
    system("cls");
}

void creatAccount(){//    creatAccount()     实现注册账号的接口
    int mark = 1;    //用来跳出循环的标记变量
    strcpy(pswd1,"");  //每次都清空字符
    strcpy(pswd2,"");
    strcpy(question,"");
    strcpy(answer,"");
    while(mark){
        int reciever;
        printCorlor(7);
        reciever = choiceReact(17,3,3,_INPUT,_NO,creatAccountFace);
        switch(reciever){
            case _INPUT : creatAccountFace();
                          creatImplement(1);
                          break;
         case MAKE_SURE : creatAccountFace();
                          creatImplement(2);
                          break;
         case _QUESTION : creatAccountFace();
                          creatImplement(4);
                          break;
           case _ANSWER : creatAccountFace();
                          creatImplement(5);
                          break;
              case _YES : creatAccountFace();
                          creatImplement(3);
                          /*cursorGoto(10,21);
                          printf("%sqwe %s[[",pswd1,question);
                          cursorGoto(10,22);
                          printf("%syui %s[[",pswd2,answer);*/
                          break;
               case _NO : if(warningDialog("您确定要放弃注册了吗？","放弃提醒","")){
                             strcpy(pswd1,"");
                             strcpy(pswd2,"");
                             mark = 0;
                         }
                         break;
        }
    }
}

void creatAccountFace(){//    creatAccountFace()     打印一个注册账号页面
    printCorlor(7);
    cursorGoto(18,1);
    printCorlor(12);
    printf("密码须设为字母和数字混合型，且不大于10位。");
    printCorlor(7);
    cursorGoto(20,3);
    printf("输入密码：");
    cursorGoto(31,2);
    printf("____________________");
    cursorGoto(30,3);
    printf("|");
    cursorGoto(51,3);
    printf("|");
    cursorGoto(31,4);
    printf("￣￣￣￣￣￣￣￣￣￣");
    cursorGoto(20,6);
    printf("确认密码：");
    cursorGoto(31,5);
    printf("____________________");
    cursorGoto(30,6);
    printf("|");
    cursorGoto(51,6);
    printf("|");
    cursorGoto(31,7);
    printf("￣￣￣￣￣￣￣￣￣￣");
    repeatPrintPswd();
    cursorGoto(20,9);
    printf("设置密保：");
    cursorGoto(31,8);
    printf("________________________________");
    cursorGoto(30,9);
    printf("|");
    cursorGoto(63,9);
    printf("|");
    cursorGoto(31,10);
    printf("￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣");
    cursorGoto(20,12);
    printf("设置答案：");
    cursorGoto(31,11);
    printf("____________________");
    cursorGoto(30,12);
    printf("|");
    cursorGoto(51,12);
    printf("|");
    cursorGoto(31,13);
    printf("￣￣￣￣￣￣￣￣￣￣");
    cursorGoto(20,15);
    printf("确认");
    cursorGoto(20,18);
    printf("取消");
    printCorlor(0x02);
    cursorGoto(28,15);
    printf("Tips:");
    cursorGoto(28,17);
    printf("密保问题和答案尽量简短且用英文。");
    printCorlor(7);
    cursorGoto(28,19);
    printf("例如：what's your QQ number? : 177****225");
    moveNotice(10,23,"Tips:请用键盘上下键来控制箭头上下移动，按回车进行选择。");
}

void saveOrNot(int is_not){//    saveOrNot()     是否显示账号密码
    int i = 0;
    if(is_not){
        cursorGoto(31,5);
        printf("%s",teacher_mesg.account);
        if(*teacher_mesg.pswd != ' '){
            cursorGoto(31,8);
            for(;i < press_times; i ++){
                printf("*");
            }
            cursorGoto(41,5);
            printf("          ");
        }
    }
}

void goToAccount(){//    goToAccount()     输入账号接口实现函数
    int i = 0;
    int j = 31;
    char str;
    isCursorActive(1);
    strcpy(teacher_mesg.account,"");
    cursorGoto(31,5);
    printf("                    ");
    while(1){
        if(i == 10){
            break;
        }
        cursorGoto(j,5);
        str = getch();
        if( str >= '0' && str <= '9'){
            teacher_mesg.account[i] = str;
            printf("%c",teacher_mesg.account[i]);
            i ++;
            j ++;
        }
        else{
            cursorGoto(52,5);
            printCorlor(0x04);
            printf("！请输入有效数字");
            printCorlor(0x02);
        }
    }
}

void goToPswd(){//    goToPswd()    输入密码接口实现函数
    int i = 0;
    int j = 31;
    char str;
    press_times = 0;
    isCursorActive(1);
    strcpy(teacher_mesg.pswd,"");
    cursorGoto(31,8);
    printf("                    ");
    while(1){
        if(i == 10){
            break;
        }
        cursorGoto(j,8);
        str = getch();
        if(str == ENTER){
            //strcpy(teacher_mesg.account,temp);
            /*strcpy(temp,teacher_mesg.account);
            int k = 0;
            for(;k < 10; k ++){
                teacher_mesg.account[k] = temp[k];
            }*/
            break;
        }
        if((str>='0' && str<='9') || ((str>='A' && str<='Z') || (str>='a' && str<='z'))){
            teacher_mesg.pswd[i] = str;
            printf("%c",teacher_mesg.pswd[i]);
            i ++;
            j ++;
            ++ press_times;
        }
        else{
            cursorGoto(52,8);
            printCorlor(0x04);
            printf("！请输入有效数字");
            printCorlor(0x02);
        }
    }
}

void creatImplement(int number){//    creatPswd()    注册时输入密码接口
    int i = 0;
    int j = 31;
    char str;
    //strcpy(pswd1,"");  //每次都清空字符
    //strcpy(pswd2,"");
    isCursorActive(1);
    if(number == 1){
        cursorGoto(31,3);
        //strcpy(pswd1,"");/**字符重复赋值问题bug**/
        //pswd1[2] = '\0';
        clearList(pswd1,11);
        printf("                    ");
        while(1){
            if(i == 10){
                if((strcmp(pswd2,"") != 0) && (strcmp(pswd1,pswd2) != 0)){
                    cursorGoto(52,3);
                    printCorlor(0x04);
                    printf("！两次输入不一致");
                    printCorlor(0x02);
                }
                break;
            }
            cursorGoto(j,3);
            str = getch();
            if(str == ENTER){
                if((strcmp(pswd2,"") != 0) && (strcmp(pswd1,pswd2) != 0)){
                    cursorGoto(52,3);
                    printCorlor(0x04);
                    printf("！两次输入不一致");
                    printCorlor(0x02);
                }
                break;
            }
            if((str>='0' && str<='9') || ((str>='A' && str<='Z') || (str>='a' && str<='z'))){
                *(pswd1 + i) = str;
                printf("%c",*(pswd1 + i));
                i ++;
                j ++;
            }
            else{
                cursorGoto(52,3);
                printCorlor(0x04);
                printf("！请输入有效数字");
                printCorlor(0x02);
            }
        }
    }
    if(number == 2){
        cursorGoto(31,6);
        clearList(pswd2,11);
        printf("                    ");
        while(1){
            if(i == 10){
                if(strcmp(pswd1,"") == 0){
                    cursorGoto(52,3);
                    printCorlor(0x04);
                    printf("!输入框为空");
                    printCorlor(0x02);
                }else if(strcmp(pswd2,pswd1) != 0){
                    cursorGoto(52,6);
                    printCorlor(0x04);
                    printf("！两次输入不一致");
                    printCorlor(0x02);
                }
                break;
            }
            cursorGoto(j,6);
            str = getch();
            if(str == ENTER){
                if(strcmp(pswd1,"") == 0){
                    cursorGoto(52,3);
                    printf("!输入框为空");
                }else if(strcmp(pswd2,pswd1) != 0){
                    cursorGoto(52,6);
                    printCorlor(0x04);
                    printf("！两次输入不一致");
                    printCorlor(0x02);
                }
                break;
            }
            if((str>='0' && str<='9') || ((str>='A' && str<='Z') || (str>='a' && str<='z'))){
                *(pswd2 + i) = str;
                printf("%c",*(pswd2 + i));
                i ++;
                j ++;
            }
            else{
                cursorGoto(52,6);
                printCorlor(0x04);
                printf("！请输入有效数字");
                printCorlor(0x02);
            }
        }
    }
    if(number == 3){
        int isTrue = 1;
        int times = 0;
        char temp_account[11];//随机抽取0~9数字十个
        char file_account[11];//从文件中读出的临时账号
        char file_pswd[11];//从文件中读取的临时密码
        char file_question[21];
        char file_answer[11];
        if(strcmp(pswd1,"")==0){
            isTrue = 0;
            cursorGoto(52,3);
            printCorlor(0X04);
            printf("!输入为空");
            printCorlor(0X02);
        }
        if(strcmp(pswd2,"")==0){
            isTrue = 0;
            cursorGoto(52,6);
            printCorlor(0X04);
            printf("!输入为空");
            printCorlor(0X02);
        }
        if((strcmp(question,"")==0) != (strcmp(answer,"")==0)){
            isTrue = 0;
            cursorGoto(64,9);
            printCorlor(0X04);
            printf("!问题答案不匹配");
            cursorGoto(52,12);
            printf("!问题答案不匹配");
            printCorlor(0X02);
        }
        if(isTrue){
            teacher_file = fopen("Teacher.txt","r+");
            if(teacher_file == NULL){
                warningDialog("注册失败，文件操作失误。","注册失败","");
                clearList(pswd1,11);
                clearList(pswd2,11);
                clearList(question,41);
                clearList(answer,21);
            }else{
                int temp_mark = 1;
                while(temp_mark){
                    for(; times < 10; times ++){
                        temp_account[times] = rand()%9 + 49;
                    }
                    temp_account[10] = '\0';
                    temp_mark = 0;
                    while(fscanf(teacher_file,"%s %s %s %s\n",file_account,file_pswd,file_question,file_answer) != EOF){
                        if(strcmp(file_account,temp_account)==0){
                            temp_mark = 1;
                            break;
                        }
                    }
                }
                rewind(teacher_file);
                fseek(teacher_file,0,SEEK_END);
                fprintf(teacher_file,"%s %s %s %s\n",temp_account,pswd1,question,answer);
                clearList(pswd1,11);
                clearList(pswd2,11);
                clearList(question,41);
                clearList(answer,21);
                char temp_list[35] = "Account:";
                int de = 0;
                int now = 8;
                for(;de < 10,now < 19; de ++,now ++){
                    temp_list[now] = temp_account[de];
                }
                warningDialog(temp_list,"注册成功！请记牢账号","");
            }
            fclose(teacher_file);
        }
    }
    if(number == 4){
        clearList(question,21);
        cursorGoto(31,9);
        printf("                ");
        cursorGoto(31,9);
        gets(question);
    }
    if(number == 5){
        clearList(answer,11);
        cursorGoto(31,12);
        printf("          ");
        cursorGoto(31,12);
        gets(answer);
        if(strcmp(question,"") == 0){
            cursorGoto(52,9);
            printCorlor(0X04);
            printf("!输入为空");
            printCorlor(0X02);
        }
    }
}

void repeatPrintPswd(){//    repeatPrintPswd()    在用户选择时重复打印密码
    cursorGoto(31,3);
    printf("%s",pswd1);
    cursorGoto(31,6);
    printf("%s",pswd2);
    cursorGoto(31,9);
    printf("%s",question);
    cursorGoto(31,12);
    printf("%s",answer);
}

void clearList(char *list,int index){//    deleteList(char *,int)    将数组赋值为空串
    int k = 0;
    for(;k < index; k ++){
        *(list + k) = '\0';
    }
}

/////////////////////////////登录后相关操作函数

void teacherOpUI(){//    teacherOpUI()    教师端登录后操作界面框架
    isCursorActive(0);
    gameUI(12);
    printCorlor(9);
    cursorGoto(14,1);
    printf("                ╔══════════════╗ ");
    cursorGoto(14,2);
    printf("################║教师端操作页面║ ###############");
    cursorGoto(14,3);
    printf("                ╚══════════════╝ ");
    cursorGoto(35,7);
    printf("查看成绩");
    cursorGoto(35,9);
    printf("增加成绩");
    cursorGoto(35,11);
    printf("修改成绩");
    cursorGoto(35,13);
    printf("删除成绩");
    cursorGoto(35,15);
    printf("修改密码");
    cursorGoto(35,17);
    printf("修改学生密码");
    cursorGoto(35,19);
    printf("退出");
    moveNotice(10,23,"Tips:请用键盘上下键来控制箭头上下移动，按回车进行选择。");
    cursorGoto(10,22);
    //system("pause");
}

void teacherOPImplement(char *class_id){//    teacherOpImplement()    教师操作具体实现函数
    char teacher_account[11];
    strcpy(teacher_account,class_id);
    char creat_class[15];
    Node *temp_head = NULL;
    int times = 0;
    for(; times < 10; times ++){
        creat_class[times] = class_id[times];
    }
    creat_class[10] = '.';
    creat_class[11] = 't';
    creat_class[12] = 'x';
    creat_class[13] = 't';
    creat_class[14] = '\0';
    FILE *class_vertify = NULL;
    //class_vertify = fopen(creat_class,"r");
    /*cursorGoto(2,0);
    printf("%s",creat_class);*/
    /*if(class_vertify == NULL){
        class_vertify = fopen(creat_class,"w");
    }
    fclose(class_vertify);*/
    temp_head = readAndWrite(temp_head,creat_class);
    temp_head = listSort(temp_head,creat_class);
    temp_head = writeAndRead(temp_head,creat_class);

    while(1){
        int i;
        teacherOpUI();
        i = choiceReact(32,7,2,VIEW,LEAVE_TEACH_SIDE,teacherOpUI);//注意函数指针后边没有()
        switch(i){
          case 7 :      system("cls");
                        printCorlor(7);
                        system("pause");
                        printList(temp_head);
                        //deleteList(temp_head);
                        //cursorGoto(45,7);
                        //printf("7查看成绩");
                        system("pause");
                        system("cls");
                        break;

        case 9 :        //cursorGoto(45,9);
                        //printf("9增加成绩");
                        system("cls");
                        insertNode(temp_head,creat_class);
 /**free在这里**/       //deleteList(temp_head);
                        system("pause");
                        system("cls");
                        break;

     case 11 :          modifyStudentInfo(temp_head,creat_class);
                        //deleteList(temp_head);
                        system("pause");
                        system("cls");
                        break;

          case 13 :    //cursorGoto(45,13);
                        //printf("13删除成绩");
                        temp_head = deleteNode(temp_head,creat_class);
                        deleteList(temp_head);
                        system("pause");
                        system("cls");
                        break;
            case 15 :   cursorGoto(45,15);
                        printf("15修改密码");
                        system("pause");
                        break;
            case 17 :cursorGoto(45,17);
                     printf("17修改学生密码");
                     system("pause");
                     break;
            case 19 :    if(warningDialog("您确定要退出教师端吗？","退出提醒","您已退出系统")){
                                exit(1);
                            }
                        break;
        }
    }
    deleteList(temp_head);
}

/////////////////////////////////////////////////链表相关函数

Node* creatList(const char* file){//    creatList()     创建链表
    Node *head = NULL;                        //头节点
    Node *end = NULL;                  //用于指向最后一个（当前操作的）节点
    Node *current = NULL;              //指向每一个新创建的节点
    head = (Node*)malloc(sizeof(Node));
    int temp_id;
    char temp_pswd[11];
    char temp_name[21];
    int temp_C;
    int temp_M;
    int temp_E;

    if(head == NULL){
        printf("can't open up space\n");
    }else{
        end = head;                      //先让尾节点指向头节点
        if((student_file = fopen(file,"r")) != NULL){
            while((fscanf(student_file,"%d %s %s %d %d %d\n",&temp_id,temp_pswd,temp_name,&temp_C,&temp_M,&temp_E)) != EOF){
                current = (Node*)malloc(sizeof(Node));
                //gets(current->stu.name);使用gets会在最后输入回车
                /*scanf("%s",current->stu.name);
                scanf("%d",&current->stu.id);
                scanf("%d",&current->stu.c_grade);
                scanf("%d",&current->stu.math_grade);
                scanf("%d",&current->stu.english_grade);*/
                current->stu.id = temp_id;
                strcpy(current->stu.pswd,temp_pswd);
                strcpy(current->stu.name,temp_name);
                current->stu.c_grade = temp_C;
                current->stu.math_grade = temp_M;
                current->stu.english_grade = temp_E;
                end->next = current;               //现在正在操作的节点next指向新创建的节点
                current->next = NULL;              //新创建的next指针赋值为空
                end = current;                     //尾节点被赋值为新创建的，新节点创建完毕
            }

            fclose(student_file);
        }else{
                printf("error");
                exit(-1);
            }

    }
    return head;
}

void printList(Node *head){//    printList()     打印链表
    Node *this_node = NULL;
    Node *this_head = head;          //用来接收头节点的指针
    this_node = this_head;
    this_node = this_node->next;             //直接赋值为next方便打印
    //printf("\n\n");
    //printf("jinru");
    if(this_head != NULL){
            printf("  ID         姓名   C语言  数学  英语  总成绩\n");
        while(this_node != NULL){
            printCorlor(0X02);
            printf("%d  ",this_node->stu.id);
            printCorlor(7);
            //printf("%s  ",this_node->stu.pswd);
            printf("%s   ",this_node->stu.name);
            printf("%d     ",this_node->stu.c_grade);
            printf("%d    ",this_node->stu.math_grade);
            printf("%d    ",this_node->stu.english_grade);
            int score = this_node->stu.c_grade + this_node->stu.math_grade + this_node->stu.english_grade;
            printf("%d\n",score);
            this_node = this_node->next;
        }
    }else{
        printf("head == NULL");
    }
}

void deleteList(Node *head){//    deleteList()     释放整个链表内存，指针格式化为NULL
    Node *deleteP = NULL;                     //原理和创建链表的一样
    Node *currentP = NULL;
    currentP = head;

    while(currentP != NULL){
        deleteP = currentP;
        currentP = currentP->next;
        free(deleteP);
        deleteP = NULL;           /**千万注意赋为NULL，防止系统再次调用野指针造成的不可弥补的错误**/
    }
}

/**下面是遍历成绩的函数**/
Node* searchStudentNode(Node* head , int id){//    searchStudentNode()    返回一个指定的id对应节点
    Node *now = head;
    now = now->next;
    Node *the_node = NULL;
    while(now!=NULL){
        if(now->stu.id == id){
           the_node = now;
           break;
        }
        now = now->next;
    }
    return the_node;
}

Node* modifyStudentInfo(Node* head ,const char *file_name){//    nodifyStudentInfo()    三个参数分别是头指针，学生id，学生数学成绩
    Node *this_node = head;
    Node *now = this_node;
    Node *receive = NULL;
    int mark = 1;
    int temp_id = 0;
    int temp_c_grade = 0;
    int temp_m_grade = 0;
    int temp_e_grade = 0;
    char temp_name[21];
    char temp_pswd[11];
    printf("请输入你需要修改的学生的id：\n");
    isCursorActive(1);
    scanf("%d",&temp_id);
    receive = searchStudentNode(this_node,temp_id);
    if(receive != NULL){
        printf("请依次输入你所需要修改的学生密码，名字，C语言、数学和英语成绩：\n");
        scanf("%s",temp_pswd);
        scanf("%s",temp_name);
        scanf("%d",&temp_c_grade);
        scanf("%d",&temp_m_grade);
        scanf("%d",&temp_e_grade);
        isCursorActive(0);
        receive->stu.c_grade = temp_c_grade;
        receive->stu.math_grade = temp_m_grade;
        receive->stu.english_grade = temp_e_grade;
        strcpy(receive->stu.pswd,temp_pswd);
        strcpy(receive->stu.name,temp_name);
    }else{
        mark = 0;
        isCursorActive(0);
        printf("此id还未添加，检查输入是否正确\n");
    }
    if(mark){
        writeAndRead(this_node,file_name);
        this_node = listSort(this_node,file_name);
        readAndWrite(this_node,file_name);
        now = now->next;
        printCorlor(7);
        while(now != NULL){
            if(now->stu.id == temp_id){
                printCorlor(0X04);
            }
            printf("%d %s %s %d %d %d\n",now->stu.id,now->stu.pswd,now->stu.name,now->stu.c_grade,now->stu.math_grade,now->stu.english_grade);
            now = now->next;
        }
    }
    return this_node;
}
/***未完成***/
Node* modifyTeacherPswd( char *account){//三个参数分别是头指针，学生id，学生C语言成绩
    char temp_pswd[11];
    char temp_account[11];
    char vertify_pswd[11];
    char useless_ques[41];
    char useless_answ[21];
    tNode temp_head = NULL;
    temp_head = (tNode*)malloc(sizeof(tNode));/**循环申请动态内存，读到教师链表，进行改写**/
    tNode now = temp_head;
    isCursorActive(1);
    printf("请输入您的旧密码：\n");
    scanf("%s",temp_pswd);
    FILE *temp_file = NULL;
    temp_file = fopen("Teacher.txt","r+");
    if(temp_file == NULL){
        printf("Modify_Pswd_File_Error\n");
    }else{
        while(fscanf(temp_file,"%s %s %s %s\n",temp_account,vertify_pswd,useless_ques,useless_answ) != EOF){

        }
    }
}

Node* deleteNode(Node* head, const char* file_name){//    deleteNode()    删除指定id的学生节点
    Node *now = head;
    Node *this_head = head;
    Node *temp = NULL;
    int mark = 0;
    int temp_id = 0;
    isCursorActive(1);
    printf("请（谨慎）输入要删除学生的id：\n");
    scanf("%d",&temp_id);

    while(now->next != NULL){
        if(now->next->stu.id == temp_id){
            now->next = now->next->next;
            free(now->next);
            now->next == NULL;
            mark = 1;
        }
        now = now->next;
    }
    if(mark){
        writeAndRead(this_head,file_name);
        printf("删除完毕\n");
    }else{
        printf("未找到此学生\n");
    }

    return this_head;
}

void insertNode(Node* head , const char *file_name ){//    参数是头节点和要插入新节点在哪个节点后边(头节点还未分配内存)
    Node* current = NULL;                             //插入到头节点之后，再调用链表排序函数
    Node* foreNode = NULL;
    Node* newNode = NULL;
    Node *insert_node = NULL;
    Node *temp_head = head;
    temp_head = temp_head->next;
    insert_node = (Node*)malloc(sizeof(Node));
    int mark = 1;
    isCursorActive(1);
    printCorlor(7);
    printf("请输入您要插入的学生信息，按照ID 初始密码 姓名 C语言 数学 英语成绩来输入：\n");
    printCorlor(0X02);
    scanf("%d",&insert_node->stu.id);
    scanf("%s",insert_node->stu.pswd);
    scanf("%s",insert_node->stu.name);
    scanf("%d",&insert_node->stu.c_grade);
    scanf("%d",&insert_node->stu.math_grade);
    scanf("%d",&insert_node->stu.english_grade);
    isCursorActive(0);
    //int insert_score = insert_node->stu.c_grade + insert_node->stu.english_grade + insert_node->stu.math_grade;
    //int score = 0;
    while(temp_head != NULL){
        if(insert_node->stu.id == head->stu.id){
            mark = 0;
            //printCorlor(12);
        }
        //printf("%d %s\n",temp_head->stu.id,temp_head->stu.name);
        temp_head = temp_head->next;
        //printCorlor(7);
    }
    if(mark){                         //判断是否输入的学号已经存在
        Node *temp_node = NULL;
        temp_node = head->next;
        head->next = insert_node;
        insert_node->next = temp_node;
        head = writeAndRead(head,file_name);
    }else{
        printf("输入的学号已存在");
    }
    listSort(head,file_name);
    head = readAndWrite(head,file_name);
    Node *now = head;
    now = now->next;
    printCorlor(12);
    printf("------------打印------------\n");
    printCorlor(7);
    while(now != NULL){
        if(now->stu.id == insert_node->stu.id){
            printCorlor(0X04);
        }
        printf("%d %s %d %d %d\n",now->stu.id,now->stu.name,now->stu.c_grade,now->stu.math_grade,now->stu.english_grade);
        printCorlor(7);
        now = now->next;
    }
}

////////////////////////////////////////////////////文件读写和排序函数

void myExchange(Node *exchanged_node,Node *swapped_node){//    myExchange()    将两个节点的数据域交换
    int num = 0;
    char pswd[11];
    char name[20];
    /////////////////////
    if((exchanged_node == NULL) && (swapped_node == NULL)){//如果两个节点都为空则报错
        printf("Exchange_NullPointer_Error\n");
        exit(-1);
    }else{
        num = exchanged_node->stu.english_grade;
        exchanged_node->stu.english_grade = swapped_node->stu.english_grade;
        swapped_node->stu.english_grade = num;
        num = exchanged_node->stu.math_grade;
        exchanged_node->stu.math_grade = swapped_node->stu.math_grade;
        swapped_node->stu.math_grade = num;
        num = exchanged_node->stu.c_grade;
        exchanged_node->stu.c_grade = swapped_node->stu.c_grade;
        swapped_node->stu.c_grade = num;
        num = exchanged_node->stu.id;
        exchanged_node->stu.id = swapped_node->stu.id;
        swapped_node->stu.id = num;
        strcpy(name,exchanged_node->stu.name);
        strcpy(exchanged_node->stu.name,swapped_node->stu.name);
        strcpy(swapped_node->stu.name,name);
        strcpy(pswd,exchanged_node->stu.pswd);
        strcpy(exchanged_node->stu.pswd,swapped_node->stu.pswd);
        strcpy(swapped_node->stu.pswd,pswd);
    }

}

Node* listSort(Node *head,const char *grade_file_name){//    listSort()    以链表为载体将文件中的信息按照数据大小排序
    FILE *file = NULL;
    Node *this_head = head;
    Node *temp_min = NULL;
    this_head = readAndWrite(this_head,grade_file_name);
    Node *now = this_head->next;
    //printList(this_head);
    //printf("------------分界线----------\n");
    int score = 0;
    int next_score = 0;
    while(now->next != NULL){                      //用选择排序算法（第二层遍历用的是getMinNode函数）
        temp_min = getMinNode(now);
        score = temp_min->stu.c_grade + temp_min->stu.math_grade + temp_min->stu.english_grade;
        next_score = now->stu.c_grade + now->stu.math_grade + now->stu.english_grade;
        if(score != next_score){
            myExchange(temp_min,now);
        }
        now = now->next;
    }
    //printList(this_head);
    this_head = writeAndRead(this_head,grade_file_name);
    fclose(file);
    return this_head;
}

Node* getMinNode(Node* head){//    getMinNode()    搜索并返回指定头节点链表中最小数据的节点
    Node *minp = head;
    Node *p = head->next;
    int score = 0;
    int next_score = 0;
    while(p != NULL){
        score = minp->stu.c_grade + minp->stu.english_grade + minp->stu.math_grade;
        next_score = p->stu.c_grade + p->stu.english_grade + p->stu.math_grade;
        if(score < next_score){
            minp = p;
        }
        p = p->next;
    }
    return minp;
}

Node* readAndWrite(Node *head,const char *file_name){//    readAndWrite()    将链表读进指定文件中
    FILE *file = NULL;
    Node *this_head = head;
    Node *temp = NULL;
    this_head = (Node*)malloc(sizeof(Node));
    Node *now = this_head;
    file = fopen(file_name,"r");
    if(this_head == NULL){
        printf("Read_Write_NullPointer_Error\n");
        exit(-1);
    }else{
        int id = 0;
        int c_gra = 0;
        int m_gra = 0;
        int e_gra = 0;
        char name[20];
        char pswd[11];
        while((fscanf(file,"%d %s %s %d %d %d\n",&id,pswd,name,&c_gra,&m_gra,&e_gra)) != EOF){
            temp = (Node*)malloc(sizeof(Node));
            temp->next = NULL;
            now->next = temp;
            now = temp;
            now->stu.id = id;
            strcpy(now->stu.pswd,pswd);
            strcpy(now->stu.name,name);
            now->stu.c_grade = c_gra;
            now->stu.math_grade = m_gra;
            now->stu.english_grade = e_gra;
        }
    }
    fclose(file);
    return this_head;
}

Node* writeAndRead(Node *head,const char *file_name){// writeAndRead()    将链表存储到指定的文件中
    Node *this_head = head;
    FILE *file = NULL;
    Node *now = this_head->next;
    file = fopen(file_name,"w");
    int id = 0;
    int c_gra = 0;
    int m_gra = 0;
    int e_gra = 0;
    char name[20];
    char pswd[11];
    if(this_head->next == NULL){
        printf("Write_Read_NullPointer_Error\n");
        exit(-1);
    }else{
        while(now != NULL){
            id = now->stu.id;
            strcpy(pswd,now->stu.pswd);
            strcpy(name,now->stu.name);
            c_gra = now->stu.c_grade;
            m_gra = now->stu.math_grade;
            e_gra = now->stu.english_grade;
            fprintf(file,"%d %s %s %d %d %d\n",id,pswd,name,c_gra,m_gra,e_gra);
            now = now->next;
       }
    }
    fclose(file);
    return this_head;
}
