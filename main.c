#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct _student)


int num;

struct _student *head,*tail;

typedef struct _student
{
	int ID;
	char name[20];
	int gender;
	double score;
	struct _student *next;
}Student;

void input();             //输入一个学生信息
void output();            //输出所有学生信息
void find();              //查找对应姓名的学生信息
void del();               //删除一个学生信息
void order();             //对学号进行排序
void read();              //从文件中读取信息
void write();              //将所有信息输出到文件中
int confirm(const char *words);  //敏感操作确认




int main()
{
    char choice[10];


    while(1)
    {
    	printf( "\n-菜单:\n"
            "1.查找\t"
            "2.追加\t"
            "3.删除\t"
            "4.显示\t"
            "5.排序\t"
            "6.读取文件\t"
            "7.保存文件\t"
            "0.退出\n"
            "输入序号:");

        //choice=getchar();
        //getchar();     //将回车读入
        scanf("%s",choice);
        switch(choice[0])
        {
        case '1':      //查找
            find();
            break;
        case '2':      //追加
            input();
            break;
        case '3':      //删除
            del();
            break;
        case '4':      //显示
            output();
            break;
        case '5':      //排序
            order();
            break;
        case '6':      //读取文件
            read();
            break;
        case '7':      //保存文件
            write();
            break;
        case '0':
            if (confirm("退出前保存？（Y/N）"))
            {
               write();
            }
            exit(0);
            break;
        default:
            printf("没有该序号！请重新输入\n");
            break;
        }
    }

}

void input()
{
    struct _student *temp;
    if(tail!=NULL)   //有数据时在链表尾部增加节点
    {
        tail->next=(struct _student*)malloc(LEN);
        tail=tail->next;
        temp=tail;
    }
    else             //无数据时创建链表
    {
        head=(struct _student*)malloc(LEN);
        tail=head;
        temp=tail;
    }

        printf("请输入一条学生信息:\n\t学号(格式：10041461**)：");
        scanf("%d",&temp->ID);
        printf("\t姓名：");
        scanf("%19s",temp->name);
        printf("\t性别\t(0-女，1-男)：");
        scanf("%d",&temp->gender);
        printf("\t分数：");
        scanf("%lf",&temp->score);
        temp->next=NULL;
        num++;
        printf("\t输入结束，请在菜单中查看\n");
}
void output()
{
   struct _student *temp;
   if(head!=NULL)
   {
       temp=head;
   }
   else
   {
       printf("有0条数据！");
       return;
   }
   printf("\n学生信息:");
   while(temp->next!=NULL)
   {
        printf("\n\t学号：%d",temp->ID);
        printf("\t姓名：%19s",temp->name);
        printf("\t性别\t(0-女，1-男)：%d",temp->gender);
        printf("\t分数：%f",temp->score);

        temp=temp->next;
   }

        printf("\n\t学号：%d",temp->ID);
        printf("\t姓名：%19s",temp->name);
        printf("\t性别\t(0-女，1-男)：%d",temp->gender);
        printf("\t分数：%f",temp->score); //输出最后一个节点数据
   printf("\n所有信息输出结束！");
   return ;
}
void find()
{
    char name[20];
    struct _student *temp;
    printf("请输入姓名：");
    scanf("%19s",name);
    if(head!=NULL)
    {
       temp=head;
       while(strcmp(temp->name,name)) //字符串比较不能用==，仅比较地址,要调用字符串比较函数
       {
           if(temp->next==NULL)  //若查询到最后一个仍不相等，退出（其next为空，继续执行会出错）
           {
               printf("您所查找数据不存在!");
               return;
           }
           temp=temp->next;
       }
        printf("\n\t学号：%d",temp->ID);
        printf("\t姓名：%19s",temp->name);
        printf("\t性别\t(0-女，1-男)：%d",temp->gender);
        printf("\t分数：%f",temp->score);
    }
    else
    {
        printf("不好意思，有0条数据");
    }
  return ;
}
void del()
{
    char name[20];
    struct _student *temp,*pre;
    pre=NULL;
    printf("请输入姓名：");
    scanf("%19s",name);
    if(head!=NULL)
    {
       temp=head;
       while(strcmp(temp->name,name)) //字符串比较不能用==，仅比较地址,要调用字符串函数
       {
           if(temp->next==NULL)  //若查询到最后一个仍不相等，退出（其next为空，继续执行会出错）
           {
               printf("您所查找数据不存在!");
               return;
           }
           pre=temp;
           temp=temp->next;
       }
        printf("\n\t学号：%d",temp->ID);
        printf("\t姓名：%19s",temp->name);
        printf("\t性别\t(0-女，1-男)：%d",temp->gender);
        printf("\t分数：%f",temp->score);
    }
    else
    {
        printf("不好意思，有0条数据");
        return;
    }

       if(confirm("\n确认删除？（Y/N）"))   //敏感操作之前确认
       {
           if(pre!=NULL)
           {
               if(pre->next->next!=NULL)
            {
                pre->next=pre->next->next;
            }
            else
            {
                pre->next=NULL;
                tail=pre;
            }
            num--;  //学生数量减少，重要，这里不加后面会有空指针
            printf("删除成功！");
           }
           else     //如若是头节点
           {
                 if(head->next!=NULL)   //如若是头节点且不止一个节点
                {
                 head=head->next;
                 num--;
                 printf("删除成功！");
                }
                else                    //如若是头节点且只有一个节点
                {
                 head=NULL;
                 tail=NULL;
                 num--;
                 printf("删除成功！");
                 printf("有0条数据");
                }
           }

       }
       else
       {
           printf("删除失败！");
       }
  return ;
}
void order()
{
    if(head!=NULL)          //判断链表是否存在
    {
        if(head->next == NULL)
        {
            return;
        }
        int i,j;
        int isChange = 1;   //冒泡排序，若一趟排序没有交换则退出循环
        struct _student *temp,*pre,*first,*second;

        for(i=0;i<num-1&&isChange;i++)
        {
            temp=head;
            isChange=0;
            for(j=0;j<num-1-i;j++)
            {
                if(temp->ID>temp->next->ID)  //若前一节点数据比后一节点大则交换
                {
                    first=temp;      //重要！结构体的赋值是赋值而不是附地址，与类对象不同!
                    second=temp->next;
                    if(temp->next==tail)
                    {
                        tail=first;    //重要，若是尾节点交换，要改变尾指针
                    }

                    first->next=second->next;
                    second->next=first;

                    if(pre==NULL)
                    {
                        head=second; //重要，若是头节点交换，要改变头指针
                    }
                    else
                    {
                       pre->next=second;
                    }
                    isChange=1;
                    temp=second;  //重要，交换之后一定要改变当前指针
                }
                pre=temp;
                temp=temp->next;
            }
        }
        printf("排序成功！");

    }
    else
    {
        printf("0条数据！");
    }
}
void read()
{
    FILE *fp=fopen("StudentInfo.dat","r");
    struct _student *temp;

    if(fp!=NULL)
    {
        fread(&num,sizeof(int),1,fp);
        struct _student* stu;
        int i;
		for(i=0;i<num;i++)
        {
           if(head!=NULL)
          {
            stu=(struct _student*)malloc(LEN);
            if(fread(stu,LEN,1,fp)!=1)
            {
                printf("读取失败");
                return ;
            }

            temp->next=stu;
            temp=temp->next; //temp为当前读入stu的前一个节点
          }
          else
          {
            head=(struct _student*)malloc(LEN);
            if(fread(head,LEN,1,fp)!=1)
            {
                printf("读取失败");
                return ;
            }
            temp=head;
          }
        }
        tail=temp;
        printf("读取成功！");
      fclose(fp);
    }
    else
    {
        printf("打开文件失败！");
    }


}
void write()
{
    FILE *fp=fopen("StudentInfo.dat","w");
    if(fp!=NULL)
    {
       fwrite(&num,sizeof(int),1,fp);
       struct _student *temp=head;
       int i;
       for(i=0;i<num-1;i++)
       {
           if(fwrite(temp,LEN,1,fp)!=1)
           {
               printf("写入失败");
               return ;
           }
           temp=temp->next;      //temp为当前写入节点
       }

       if(fwrite(temp,LEN,1,fp)!=1)
           {
               printf("写入失败");
               return ;
           }                      //temp到了尾部，next为空，单独列出

        printf("写入成功！");
        fclose(fp);
    }
    else
    {
        printf("打开文件失败！");
    }
}

int confirm(const char *words) {
    char choice;
    printf(words);
    for (;;) {
        getchar();
        choice = getchar();
        getchar();

        switch (choice) {
        default:
            printf("输入非法，重新输入！");
            continue;
        case 'Y':
        case 'y':
            printf("已确认！");
            return 1;
        case 'N':
        case 'n':
            printf("已取消！");
            return 0;
        }
    }
}
