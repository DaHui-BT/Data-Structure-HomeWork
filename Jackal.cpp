//
// Created by dahui on 2020/12/11.
//


# include "iostream"
# include <cstring>
# include "windows.h"
using namespace std;

# define Size 20
# define JudgeSize 4
# define MaxSize 100

/**
 * Jackal的属性列表
 */
typedef struct Jackal{
    char id[Size];                  // 编号
    char name[Size];                // 名称
    int age;                      // 年龄
    float length;                 // 体长
    float weight;                 // 体重
    char color[Size];                 // color设置为枚举类型
    char isCarnivorous[JudgeSize];           // 是否是肉
    char naturalEnemyName[Size];    // 天敌名称
    char favoriteFoodName[Size];    // 最喜爱食物的名称
}Jackal;

typedef struct JackalNode{
    Jackal data;
    struct JackalNode *next;
}JackalNode, *LinkList;

/**
 * 带头结点的链表
 * @param L 链表
 */
void Init(LinkList &L){
    L = new JackalNode;
    L->next = nullptr;
}

/**
 * 判断L是否为空
 * @param L
 * @return 1为非空、0为空
 */
int EmptyLinkList(LinkList L){
    // 如果L为空则退出删除操作
    if (L->next == nullptr){
        cout<<"该Jackal链表为空！不能进行操作！\n";
        return 0;
    }
    return 1;
}

/**
 * 判断字符长度是否合格
 * @param correct
 */
void Correct(char *correct){
    cin>>correct;
    while (strlen(correct) > Size || strlen(correct) < 0){
        cout<<"您输入的格式不正确，请输入规定的格式字符（0~20个字符长度）\n";
        cin>>correct;
    }
}

/**
 * 检验数字是否合乎规范
 * @param correct
 * @param begin 最小值
 * @param end 最大值
 */
void Correct(int &correct, int begin, int end){
    cin>>correct;
    while (correct > end || correct < begin){
        printf("您输入的格式不正确，请输入规定的格式字符（%d~%d范围内）\n", begin, end);
        cin>>correct;
    }
}

/**
 * 检验数字是否合乎规范
 * @param correct
 * @param begin 最小值
 * @param end 最大值
 */
void Correct(float &correct, float begin, float end){
    cin>>correct;
    while (correct > end || correct < begin){
        printf("您输入的格式不正确，请输入规定的格式字符（%.2f~%.2f范围内）\n", begin, end);
        cin>>correct;
    }
}

/**
 * 程序的等待执行
 */
void Wait(){
    char wait[MaxSize];
    cout<<"请输入任意字符并按回车键，以继续进行操作！";
    cin>>wait;
}

/**
 * 进行jackal的信息填写
 * @param J
 */
void JackalFill(Jackal &jackal){
    // 定义变量进行存储输入的数据，并进行判断是否符合格式规范，不符合则进行重新输入
    char id[Size], name[Size], color[Size], isCarnivorous[JudgeSize], naturalEnemyName[Size], favoriteFoodName[Size];
    int age;
    float length, weight;
    // 提示用户输入的项目
    cout<<"《Jackal的属性包括：编号、名称、年龄、体长、体重、体色、是否食肉、天敌名称、最喜爱食物的名称，请按值填写。》\n";
    // 进行数据的处理
    cout<<"请输入Jackal的编号（0~20个字符长度）：";
    Correct(id);            // 规范化操作
    strcpy(jackal.id,id);
    cout<<"\n请输入Jackal的名称（0~20个字符长度）：";
    Correct(name);
    strcpy(jackal.name, name);
    cout<<"\n请输入Jackal的年龄（0~100范围内）：";
    Correct(age, 0, 100);
    jackal.age = age;
    cout<<"\n请输入Jackal的体长（10~200范围内）：";
    Correct(length, 10, 200);
    jackal.length = length;
    cout<<"\n请输入Jackal的体重（千克：5~100）：";
    Correct(weight, 5, 100);
    jackal.weight = weight;
    cout<<"\n请输入Jackal的体色（体色正确格式填写为[其中一个]：RED、ORANGE、YELLOW、GREEN、INDIGO、VIOLET、BLACK）：";
    cin>>color;
    cout<<color;
    strcpy(jackal.color, color);
    cout<<jackal.color;
    cout<<"\n请输入Jackal是否食肉（请输入“yes”或”no“）：";
    cin>>isCarnivorous;
    while (true){     // 判断用户输入是否为符合的字段
        if (strcmp(isCarnivorous, "yes") == 0 || strcmp(isCarnivorous, "no") == 0 && strlen(isCarnivorous) < 4){
            break;
        } else {
            cout<<"\n输入不符合格式，请按格式进行输入！（”yes“或“no”）\n";
            cin>>isCarnivorous;
        }
    }
    strcpy(jackal.isCarnivorous, isCarnivorous);
    cout<<"\n请输入Jackal天敌名称（0~20个字符长度）：";
    Correct(naturalEnemyName);
    strcpy(jackal.naturalEnemyName, naturalEnemyName);
    cout<<"\n请输入Jackal最喜爱的食物（0~20个字符长度）：";
    Correct(favoriteFoodName);
    strcpy(jackal.favoriteFoodName, favoriteFoodName);
}

/**
 * 插入操作
 * @param L
 */
void Insert(LinkList &L, Jackal jackal){
    JackalNode *P, *Q;
    // P为指向L的指针
    P = L;
    while (P->next != nullptr){  // 进行找到插入点（后插法）
        P = P->next;
    }
    // Q为待插入节点
    Q = new JackalNode;
    Q->data = jackal;
    Q->next = nullptr;
    P->next = Q;
}

void DisplayList(LinkList OL);

/**
 * 进行删除操作
 * @param L 链表
 */
void Delete(LinkList &L){
    // 如果L为空则退出删除操作
    if (EmptyLinkList(L) == 0){
        cout<<"3秒后将程序将继续进行...\n";
        Sleep(3 * 1000);
        return ;
    }
    char no[Size], isBreak[JudgeSize];
    int i = -1;
    LinkList OL;     // 存放将要删除节点的信息
    Init(OL);    //对OL初始化
    JackalNode *P;
    while (true){
        OnePlace:
        // 如果L为空则退出删除操作
        if (EmptyLinkList(L) == 0){
            cout<<"3秒后将继续进行...\n";
            Sleep(3 * 1000);
            return ;
        }
        cout<<"请输入要删除的编号";
        cin>>no;
        P = L;
        while (P->next){
            if (strcmp(P->next->data.id, no) == 0){
                i ++;
                break;
            }
            P = P->next;
        }
        if (P->next == nullptr){
            cout<<"该编号信息不存在！\n";
            continue;
        }
        Insert(OL, P->next->data);
        JackalNode *Q = P->next;
        P->next = Q->next;
        delete Q;
        cout<<"删除成功，您所删除的信息为：";
        DisplayList(OL);
        cout<<"删除成功！是否还要进行删除操作？（yes或者no）：";
        cin>>isBreak;
        while (true){     // 判断用户输入是否为符合的字段
            if (strcmp(isBreak, "yes") == 0 && strlen(isBreak) < 4){
                goto OnePlace;
            } else if(strcmp(isBreak, "no") == 0 && strlen(isBreak) < 4){
                return ;
            } else {
                cout<<"\n输入不符合格式，请按格式进行输入！（”yes“或“no”）";
                cin>>isBreak;
            }
        }
    }
}

/**
 * 进行改操作
 * @param L
 */
void Update(LinkList &L){
    if (EmptyLinkList(L) == 0){
        cout<<"3秒后将程序将继续进行...\n";
        Sleep(3 * 1000);
        return ;
    }
    char no[Size], isBreak[JudgeSize];
    Jackal jackal;
    TwoPlace:
    cout<<"请输入要更新jackal的编号：";
    cin>>no;
    JackalNode *P = L;
    while (P->next){
        if (strcmp(P->next->data.id, no) == 0){
            break;
        }
        P = P->next;
    }
    if (P->next == nullptr){
        cout<<"改编号信息不存在！是否要跳转到主选择页面？（yes或者no）\n";
        cin>>isBreak;
        while (true){     // 判断用户输入是否为符合的字段
            if (strcmp(isBreak, "yes") == 0 && strlen(isBreak) < 4){
                return ;
            } else if(strcmp(isBreak, "no") == 0 && strlen(isBreak) < 4){
                goto TwoPlace;      // 进行跳转到重新输入编号的地方
            } else {
                cout<<"\n输入不符合格式，请按格式进行输入！（”yes“或“no”）";
                cin>>isBreak;
            }
        }
    }
    JackalFill(jackal);
    JackalNode *Q = P->next;
    Q->data = jackal;
    cout<<"修改成功！";
    Wait();
}

/**
 * 按编号进行查找
 * @param L 链表
 * @param no 编号
 * @return -1为链表为空、0表示未找到符合条件的
 */
int Find_By_No(LinkList L, char *no){
    LinkList OL;
    Init(OL);
    int i = -1;
    JackalNode *P;
    // 如果L为空则退出删除操作
    if (EmptyLinkList(L) == 0){
        cout<<"3秒后将继续进行...\n";
        Sleep(3 * 1000);
        return -1;
    }
    P = L;
    while (P->next){
        if (strcmp(P->next->data.id, no) == 0){
            i ++;
            break;
        }
        P = P->next;
    }
    if (P->next == nullptr){
        cout<<"该编号信息不存在！3秒后将继续进行...\n";
        Sleep(3 * 1000);
        return 0;
    }
    Insert(OL, P->next->data);
    cout<<"查找成功！您所查找的信息为：";
    DisplayList(OL);
}

/**
 * 按姓名尽心查找
 * @param L 链表
 * @param name Jackal的名字
 * @return -1为链表为空、0表示未找到符合条件的
 */
int Find_By_Name(LinkList L, char name[Size]){
    LinkList OL;
    Init(OL);
    int i = -1;
    JackalNode *P;
    // 如果L为空则退出删除操作
    if (EmptyLinkList(L) == 0){
        cout<<"3秒后将继续进行...\n";
        Sleep(3 * 1000);
        return -1;
    }
    P = L;
    while (P->next){
        if (strcmp(P->next->data.name, name) == 0){
            i ++;
            break;
        }
        P = P->next;
    }
    if (P->next == nullptr){
        cout<<"该名字信息不存在！3秒后将继续进行...\n";
        Sleep(3 * 1000);
        return 0;
    }
    Insert(OL, P->next->data);
    cout<<"查找成功！您所查找的信息为：";
    DisplayList(OL);
}

/**
 * 按年龄范围进行查找
 * @param L 链表
 * @param ageMin 年龄的最小值
 * @param ageMax 年龄的最大值
 * @return -1为链表为空、0表示未找到符合条件的
 */
int Find_By_Age_Range(LinkList L, int ageMin, int ageMax){
    LinkList OL;
    Init(OL);
    int i = -1;
    JackalNode *P, *Q;
    // 如果L为空则退出删除操作
    if (EmptyLinkList(L) == 0){
        cout<<"3秒后将继续进行...\n";
        Sleep(3 * 1000);
        return -1;
    }
    P = L;
    Q = OL;
    while (P->next){
        if (P->next->data.age >= ageMin && P->next->data.age <= ageMax){
            ++ i;
            Insert(OL, P->next->data);
        }
        P = P->next;
    }
    if (EmptyLinkList(OL) == 0){
        cout<<"该年龄范围信息不存在！3秒后将继续进行...\n";
        Sleep(3 * 1000);
        return 0;
    }
    cout<<"查找成功！您所查找的信息为：";
    DisplayList(OL);
}

/**
 * 按体重范围进行查找
 * @param L 链表
 * @param weightMin 最小体重
 * @param weightMax 最大体重
 * @return -1为链表为空、0表示未找到符合条件的
 */
int Find_By_Weight_Range(LinkList L, int weightMin, int weightMax){
    LinkList OL;
    Init(OL);
    int i = -1;
    JackalNode *P, *Q;
    // 如果L为空则退出删除操作
    if (EmptyLinkList(L) == 0){
        cout<<"3秒后将继续进行...\n";
        Sleep(3 * 1000);
        return -1;
    }
    P = L;
    Q = OL;
    while (P->next){
        if (P->next->data.age >= weightMin && P->next->data.age <= weightMax){
            i ++;
            Insert(OL, P->next->data);
        }
        P = P->next;
    }
    if (EmptyLinkList(OL) == 0){
        cout<<"该体重范围信息不存在！3秒后将继续进行...\n";
        Sleep(3 * 1000);
        return 0;
    }
    cout<<"查找成功！您所查找的信息为：";
    DisplayList(OL);
}

/**
 * 进行查找前判断，要查找的依据
 * @param L 链表
 * @return 用户的选项
 */
int FindChoice(LinkList L){
    // 如果L为空则退查找除操作
    if (EmptyLinkList(L) == 0){
        cout<<"改链表为空，不能进行查找操作。3秒后将程序将继续进行...\n";
        Sleep(3 * 1000);
        return -1;
    }
    cout<<"请输入查找选项\n";
    cout<<"+--------+---------------------+\n";
    cout<<"|   1    |      按编号查找       |\n";
    cout<<"|   2    |      按名字查找       |\n";
    cout<<"|   3    |      按年龄段查找     |\n";
    cout<<"|   4    |      按体重范围查找    |\n";
    cout<<"+--------+---------------------+\n";

    char no[Size], name[Size];
    int choice, ageMax, ageMin;
    float weightMin, weightMax;
    OnePlace:
    cin>>choice;
    if (choice == 1){
        cout<<"请输入要查询的编号：";
        cin>>no;
        Find_By_No(L, no);
        return 1;
    } else if(choice == 2){
        cout<<"请输入要查询的姓名：";
        cin>>name;
        Find_By_Name(L, name);
        return 2;
    } else if(choice == 3){
        cout<<"请输入要查找的年龄范围最小值：";
        cin>>ageMin;
        cout<<"请输入要查找的年龄范围最大值：";
        cin>>ageMax;
        Find_By_Age_Range(L, ageMin, ageMax);
        return 3;
    }else if (choice == 4){
        cout<<"请输入要查找的体重范围最小值：";
        cin>>weightMin;
        cout<<"请输入要查找的体重范围最大值：";
        cin>>weightMax;
        Find_By_Weight_Range(L, weightMin, weightMax);
    } else {
        cout<<"输入有误，请重新输入";
        goto OnePlace;
    }
}

/**
 * 统计查询jackal的个数
 * @param L
 * @return 返回Jackal的个数
 */
int Count(LinkList L){
    int i = 0;
    JackalNode *P = L->next;
    while (P){
        P = P->next;
        ++ i;
    }
    cout<<"Jackal的个数--------->  "<<i<<"\n";
    Wait();
    return i;
}

/**
 * 输出格式
 * @param L 链表
 */
void DisplayList(LinkList L){
    JackalNode *P;
    P = L->next;
    // 如果为空，进行退出操作
    if (L->next == nullptr){
        cout<<"Jackal为空，不能进行输出操作！3秒后将程序将继续进行...";
        Sleep(3 * 1000);
        return ;
    }
    cout<<"\n-----------------------------------------------------------------------------------------------------------\n";
    while (P != nullptr){
        printf("| 编号：%s  |  名称：%s  |  年龄%d  |  体长%.2f  |  体重%5.2f"
               "  |  体色%s |  是否是肉%s  |  天敌名称%s  |  最喜爱食物的名称%s  |\n",
               P->data.id, P->data.name, P->data.age, P->data.length, P->data.weight,
                 P->data.color, P->data.isCarnivorous, P->data.naturalEnemyName, P->data.favoriteFoodName);
        P = P->next;
    }
    cout<<"-----------------------------------------------------------------------------------------------------------\n";
    Wait();     // 进行程序等待
}

/**
 * 输出选项
 */
void Display(){
    cout<<"\n============================================================================\n";
    cout<<"||                              请输入要执行的操作                         ||\n";
    cout<<"----------------------------------------------------------------------------\n";
    cout<<"||              选项       ||                 操作内容                    ||\n";
    cout<<"============================================================================\n";
    cout<<"||               1         ||                  增加Jackal                  ||\n";
    cout<<"||               2         ||                  删除Jackal                  ||\n";
    cout<<"||               3         ||                  修改Jackal                  ||\n";
    cout<<"||               4         ||                  查询Jackal信息              ||\n";
    cout<<"||               5         ||                  统计查询Jackal个数          ||\n";
    cout<<"||               6         ||                  输出查询Jackal列表          ||\n";
    cout<<"||               7         ||                  退出                        ||\n";
    cout<<"=============================================================================\n";
}

void Choose(LinkList &L){
    int choice = 0;
    Jackal jackal;
    while (true){
        Display();
        cout<<"请输入选项：";
        cin>>choice;
        switch (choice) {
            case 1:
                JackalFill(jackal);
                Insert(L, jackal);
                cout<<"添加成功！3秒后程序将继续执行...";
                Sleep(3 * 1000);
                break;
            case 2:
                Delete(L);
                break;
            case 3:
                Update(L);
                break;
            case 4:
                FindChoice(L);
                break;
            case 5:
                Count(L);
                break;
            case 6:
                DisplayList(L);
                break;
            case 7:
                return;
            default:
                cout<<"输入错误，请重新输入！（输入内容为1~7之间的数字）";
                cout<<"3秒后将程序将继续进行...\n";
                Sleep(3 * 1000);    // 进行3秒的休眠
        }
    }
}

int main(){

    LinkList L;
    Init(L);
    Choose(L);

    return 0;
}