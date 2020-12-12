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
 * Jackal�������б�
 */
typedef struct Jackal{
    char id[Size];                  // ���
    char name[Size];                // ����
    int age;                      // ����
    float length;                 // �峤
    float weight;                 // ����
    char color[Size];                 // color����Ϊö������
    char isCarnivorous[JudgeSize];           // �Ƿ�����
    char naturalEnemyName[Size];    // �������
    char favoriteFoodName[Size];    // ��ϲ��ʳ�������
}Jackal;

typedef struct JackalNode{
    Jackal data;
    struct JackalNode *next;
}JackalNode, *LinkList;

/**
 * ��ͷ��������
 * @param L ����
 */
void Init(LinkList &L){
    L = new JackalNode;
    L->next = nullptr;
}

/**
 * �ж�L�Ƿ�Ϊ��
 * @param L
 * @return 1Ϊ�ǿա�0Ϊ��
 */
int EmptyLinkList(LinkList L){
    // ���LΪ�����˳�ɾ������
    if (L->next == nullptr){
        cout<<"��Jackal����Ϊ�գ����ܽ��в�����\n";
        return 0;
    }
    return 1;
}

/**
 * �ж��ַ������Ƿ�ϸ�
 * @param correct
 */
void Correct(char *correct){
    cin>>correct;
    while (strlen(correct) > Size || strlen(correct) < 0){
        cout<<"������ĸ�ʽ����ȷ��������涨�ĸ�ʽ�ַ���0~20���ַ����ȣ�\n";
        cin>>correct;
    }
}

/**
 * ���������Ƿ�Ϻ��淶
 * @param correct
 * @param begin ��Сֵ
 * @param end ���ֵ
 */
void Correct(int &correct, int begin, int end){
    cin>>correct;
    while (correct > end || correct < begin){
        printf("������ĸ�ʽ����ȷ��������涨�ĸ�ʽ�ַ���%d~%d��Χ�ڣ�\n", begin, end);
        cin>>correct;
    }
}

/**
 * ���������Ƿ�Ϻ��淶
 * @param correct
 * @param begin ��Сֵ
 * @param end ���ֵ
 */
void Correct(float &correct, float begin, float end){
    cin>>correct;
    while (correct > end || correct < begin){
        printf("������ĸ�ʽ����ȷ��������涨�ĸ�ʽ�ַ���%.2f~%.2f��Χ�ڣ�\n", begin, end);
        cin>>correct;
    }
}

/**
 * ����ĵȴ�ִ��
 */
void Wait(){
    char wait[MaxSize];
    cout<<"�����������ַ������س������Լ������в�����";
    cin>>wait;
}

/**
 * ����jackal����Ϣ��д
 * @param J
 */
void JackalFill(Jackal &jackal){
    // ����������д洢��������ݣ��������ж��Ƿ���ϸ�ʽ�淶���������������������
    char id[Size], name[Size], color[Size], isCarnivorous[JudgeSize], naturalEnemyName[Size], favoriteFoodName[Size];
    int age;
    float length, weight;
    // ��ʾ�û��������Ŀ
    cout<<"��Jackal�����԰�������š����ơ����䡢�峤�����ء���ɫ���Ƿ�ʳ�⡢������ơ���ϲ��ʳ������ƣ��밴ֵ��д����\n";
    // �������ݵĴ���
    cout<<"������Jackal�ı�ţ�0~20���ַ����ȣ���";
    Correct(id);            // �淶������
    strcpy(jackal.id,id);
    cout<<"\n������Jackal�����ƣ�0~20���ַ����ȣ���";
    Correct(name);
    strcpy(jackal.name, name);
    cout<<"\n������Jackal�����䣨0~100��Χ�ڣ���";
    Correct(age, 0, 100);
    jackal.age = age;
    cout<<"\n������Jackal���峤��10~200��Χ�ڣ���";
    Correct(length, 10, 200);
    jackal.length = length;
    cout<<"\n������Jackal�����أ�ǧ�ˣ�5~100����";
    Correct(weight, 5, 100);
    jackal.weight = weight;
    cout<<"\n������Jackal����ɫ����ɫ��ȷ��ʽ��дΪ[����һ��]��RED��ORANGE��YELLOW��GREEN��INDIGO��VIOLET��BLACK����";
    cin>>color;
    cout<<color;
    strcpy(jackal.color, color);
    cout<<jackal.color;
    cout<<"\n������Jackal�Ƿ�ʳ�⣨�����롰yes����no������";
    cin>>isCarnivorous;
    while (true){     // �ж��û������Ƿ�Ϊ���ϵ��ֶ�
        if (strcmp(isCarnivorous, "yes") == 0 || strcmp(isCarnivorous, "no") == 0 && strlen(isCarnivorous) < 4){
            break;
        } else {
            cout<<"\n���벻���ϸ�ʽ���밴��ʽ�������룡����yes����no����\n";
            cin>>isCarnivorous;
        }
    }
    strcpy(jackal.isCarnivorous, isCarnivorous);
    cout<<"\n������Jackal������ƣ�0~20���ַ����ȣ���";
    Correct(naturalEnemyName);
    strcpy(jackal.naturalEnemyName, naturalEnemyName);
    cout<<"\n������Jackal��ϲ����ʳ�0~20���ַ����ȣ���";
    Correct(favoriteFoodName);
    strcpy(jackal.favoriteFoodName, favoriteFoodName);
}

/**
 * �������
 * @param L
 */
void Insert(LinkList &L, Jackal jackal){
    JackalNode *P, *Q;
    // PΪָ��L��ָ��
    P = L;
    while (P->next != nullptr){  // �����ҵ�����㣨��巨��
        P = P->next;
    }
    // QΪ������ڵ�
    Q = new JackalNode;
    Q->data = jackal;
    Q->next = nullptr;
    P->next = Q;
}

void DisplayList(LinkList OL);

/**
 * ����ɾ������
 * @param L ����
 */
void Delete(LinkList &L){
    // ���LΪ�����˳�ɾ������
    if (EmptyLinkList(L) == 0){
        cout<<"3��󽫳��򽫼�������...\n";
        Sleep(3 * 1000);
        return ;
    }
    char no[Size], isBreak[JudgeSize];
    int i = -1;
    LinkList OL;     // ��Ž�Ҫɾ���ڵ����Ϣ
    Init(OL);    //��OL��ʼ��
    JackalNode *P;
    while (true){
        OnePlace:
        // ���LΪ�����˳�ɾ������
        if (EmptyLinkList(L) == 0){
            cout<<"3��󽫼�������...\n";
            Sleep(3 * 1000);
            return ;
        }
        cout<<"������Ҫɾ���ı��";
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
            cout<<"�ñ����Ϣ�����ڣ�\n";
            continue;
        }
        Insert(OL, P->next->data);
        JackalNode *Q = P->next;
        P->next = Q->next;
        delete Q;
        cout<<"ɾ���ɹ�������ɾ������ϢΪ��";
        DisplayList(OL);
        cout<<"ɾ���ɹ����Ƿ�Ҫ����ɾ����������yes����no����";
        cin>>isBreak;
        while (true){     // �ж��û������Ƿ�Ϊ���ϵ��ֶ�
            if (strcmp(isBreak, "yes") == 0 && strlen(isBreak) < 4){
                goto OnePlace;
            } else if(strcmp(isBreak, "no") == 0 && strlen(isBreak) < 4){
                return ;
            } else {
                cout<<"\n���벻���ϸ�ʽ���밴��ʽ�������룡����yes����no����";
                cin>>isBreak;
            }
        }
    }
}

/**
 * ���иĲ���
 * @param L
 */
void Update(LinkList &L){
    if (EmptyLinkList(L) == 0){
        cout<<"3��󽫳��򽫼�������...\n";
        Sleep(3 * 1000);
        return ;
    }
    char no[Size], isBreak[JudgeSize];
    Jackal jackal;
    TwoPlace:
    cout<<"������Ҫ����jackal�ı�ţ�";
    cin>>no;
    JackalNode *P = L;
    while (P->next){
        if (strcmp(P->next->data.id, no) == 0){
            break;
        }
        P = P->next;
    }
    if (P->next == nullptr){
        cout<<"�ı����Ϣ�����ڣ��Ƿ�Ҫ��ת����ѡ��ҳ�棿��yes����no��\n";
        cin>>isBreak;
        while (true){     // �ж��û������Ƿ�Ϊ���ϵ��ֶ�
            if (strcmp(isBreak, "yes") == 0 && strlen(isBreak) < 4){
                return ;
            } else if(strcmp(isBreak, "no") == 0 && strlen(isBreak) < 4){
                goto TwoPlace;      // ������ת�����������ŵĵط�
            } else {
                cout<<"\n���벻���ϸ�ʽ���밴��ʽ�������룡����yes����no����";
                cin>>isBreak;
            }
        }
    }
    JackalFill(jackal);
    JackalNode *Q = P->next;
    Q->data = jackal;
    cout<<"�޸ĳɹ���";
    Wait();
}

/**
 * ����Ž��в���
 * @param L ����
 * @param no ���
 * @return -1Ϊ����Ϊ�ա�0��ʾδ�ҵ�����������
 */
int Find_By_No(LinkList L, char *no){
    LinkList OL;
    Init(OL);
    int i = -1;
    JackalNode *P;
    // ���LΪ�����˳�ɾ������
    if (EmptyLinkList(L) == 0){
        cout<<"3��󽫼�������...\n";
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
        cout<<"�ñ����Ϣ�����ڣ�3��󽫼�������...\n";
        Sleep(3 * 1000);
        return 0;
    }
    Insert(OL, P->next->data);
    cout<<"���ҳɹ����������ҵ���ϢΪ��";
    DisplayList(OL);
}

/**
 * ���������Ĳ���
 * @param L ����
 * @param name Jackal������
 * @return -1Ϊ����Ϊ�ա�0��ʾδ�ҵ�����������
 */
int Find_By_Name(LinkList L, char name[Size]){
    LinkList OL;
    Init(OL);
    int i = -1;
    JackalNode *P;
    // ���LΪ�����˳�ɾ������
    if (EmptyLinkList(L) == 0){
        cout<<"3��󽫼�������...\n";
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
        cout<<"��������Ϣ�����ڣ�3��󽫼�������...\n";
        Sleep(3 * 1000);
        return 0;
    }
    Insert(OL, P->next->data);
    cout<<"���ҳɹ����������ҵ���ϢΪ��";
    DisplayList(OL);
}

/**
 * �����䷶Χ���в���
 * @param L ����
 * @param ageMin �������Сֵ
 * @param ageMax ��������ֵ
 * @return -1Ϊ����Ϊ�ա�0��ʾδ�ҵ�����������
 */
int Find_By_Age_Range(LinkList L, int ageMin, int ageMax){
    LinkList OL;
    Init(OL);
    int i = -1;
    JackalNode *P, *Q;
    // ���LΪ�����˳�ɾ������
    if (EmptyLinkList(L) == 0){
        cout<<"3��󽫼�������...\n";
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
        cout<<"�����䷶Χ��Ϣ�����ڣ�3��󽫼�������...\n";
        Sleep(3 * 1000);
        return 0;
    }
    cout<<"���ҳɹ����������ҵ���ϢΪ��";
    DisplayList(OL);
}

/**
 * �����ط�Χ���в���
 * @param L ����
 * @param weightMin ��С����
 * @param weightMax �������
 * @return -1Ϊ����Ϊ�ա�0��ʾδ�ҵ�����������
 */
int Find_By_Weight_Range(LinkList L, int weightMin, int weightMax){
    LinkList OL;
    Init(OL);
    int i = -1;
    JackalNode *P, *Q;
    // ���LΪ�����˳�ɾ������
    if (EmptyLinkList(L) == 0){
        cout<<"3��󽫼�������...\n";
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
        cout<<"�����ط�Χ��Ϣ�����ڣ�3��󽫼�������...\n";
        Sleep(3 * 1000);
        return 0;
    }
    cout<<"���ҳɹ����������ҵ���ϢΪ��";
    DisplayList(OL);
}

/**
 * ���в���ǰ�жϣ�Ҫ���ҵ�����
 * @param L ����
 * @return �û���ѡ��
 */
int FindChoice(LinkList L){
    // ���LΪ�����˲��ҳ�����
    if (EmptyLinkList(L) == 0){
        cout<<"������Ϊ�գ����ܽ��в��Ҳ�����3��󽫳��򽫼�������...\n";
        Sleep(3 * 1000);
        return -1;
    }
    cout<<"���������ѡ��\n";
    cout<<"+--------+---------------------+\n";
    cout<<"|   1    |      ����Ų���       |\n";
    cout<<"|   2    |      �����ֲ���       |\n";
    cout<<"|   3    |      ������β���     |\n";
    cout<<"|   4    |      �����ط�Χ����    |\n";
    cout<<"+--------+---------------------+\n";

    char no[Size], name[Size];
    int choice, ageMax, ageMin;
    float weightMin, weightMax;
    OnePlace:
    cin>>choice;
    if (choice == 1){
        cout<<"������Ҫ��ѯ�ı�ţ�";
        cin>>no;
        Find_By_No(L, no);
        return 1;
    } else if(choice == 2){
        cout<<"������Ҫ��ѯ��������";
        cin>>name;
        Find_By_Name(L, name);
        return 2;
    } else if(choice == 3){
        cout<<"������Ҫ���ҵ����䷶Χ��Сֵ��";
        cin>>ageMin;
        cout<<"������Ҫ���ҵ����䷶Χ���ֵ��";
        cin>>ageMax;
        Find_By_Age_Range(L, ageMin, ageMax);
        return 3;
    }else if (choice == 4){
        cout<<"������Ҫ���ҵ����ط�Χ��Сֵ��";
        cin>>weightMin;
        cout<<"������Ҫ���ҵ����ط�Χ���ֵ��";
        cin>>weightMax;
        Find_By_Weight_Range(L, weightMin, weightMax);
    } else {
        cout<<"������������������";
        goto OnePlace;
    }
}

/**
 * ͳ�Ʋ�ѯjackal�ĸ���
 * @param L
 * @return ����Jackal�ĸ���
 */
int Count(LinkList L){
    int i = 0;
    JackalNode *P = L->next;
    while (P){
        P = P->next;
        ++ i;
    }
    cout<<"Jackal�ĸ���--------->  "<<i<<"\n";
    Wait();
    return i;
}

/**
 * �����ʽ
 * @param L ����
 */
void DisplayList(LinkList L){
    JackalNode *P;
    P = L->next;
    // ���Ϊ�գ������˳�����
    if (L->next == nullptr){
        cout<<"JackalΪ�գ����ܽ������������3��󽫳��򽫼�������...";
        Sleep(3 * 1000);
        return ;
    }
    cout<<"\n-----------------------------------------------------------------------------------------------------------\n";
    while (P != nullptr){
        printf("| ��ţ�%s  |  ���ƣ�%s  |  ����%d  |  �峤%.2f  |  ����%5.2f"
               "  |  ��ɫ%s |  �Ƿ�����%s  |  �������%s  |  ��ϲ��ʳ�������%s  |\n",
               P->data.id, P->data.name, P->data.age, P->data.length, P->data.weight,
                 P->data.color, P->data.isCarnivorous, P->data.naturalEnemyName, P->data.favoriteFoodName);
        P = P->next;
    }
    cout<<"-----------------------------------------------------------------------------------------------------------\n";
    Wait();     // ���г���ȴ�
}

/**
 * ���ѡ��
 */
void Display(){
    cout<<"\n============================================================================\n";
    cout<<"||                              ������Ҫִ�еĲ���                         ||\n";
    cout<<"----------------------------------------------------------------------------\n";
    cout<<"||              ѡ��       ||                 ��������                    ||\n";
    cout<<"============================================================================\n";
    cout<<"||               1         ||                  ����Jackal                  ||\n";
    cout<<"||               2         ||                  ɾ��Jackal                  ||\n";
    cout<<"||               3         ||                  �޸�Jackal                  ||\n";
    cout<<"||               4         ||                  ��ѯJackal��Ϣ              ||\n";
    cout<<"||               5         ||                  ͳ�Ʋ�ѯJackal����          ||\n";
    cout<<"||               6         ||                  �����ѯJackal�б�          ||\n";
    cout<<"||               7         ||                  �˳�                        ||\n";
    cout<<"=============================================================================\n";
}

void Choose(LinkList &L){
    int choice = 0;
    Jackal jackal;
    while (true){
        Display();
        cout<<"������ѡ�";
        cin>>choice;
        switch (choice) {
            case 1:
                JackalFill(jackal);
                Insert(L, jackal);
                cout<<"��ӳɹ���3�����򽫼���ִ��...";
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
                cout<<"����������������룡����������Ϊ1~7֮������֣�";
                cout<<"3��󽫳��򽫼�������...\n";
                Sleep(3 * 1000);    // ����3�������
        }
    }
}

int main(){

    LinkList L;
    Init(L);
    Choose(L);

    return 0;
}