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

void input();             //����һ��ѧ����Ϣ
void output();            //�������ѧ����Ϣ
void find();              //���Ҷ�Ӧ������ѧ����Ϣ
void del();               //ɾ��һ��ѧ����Ϣ
void order();             //��ѧ�Ž�������
void read();              //���ļ��ж�ȡ��Ϣ
void write();              //��������Ϣ������ļ���
int confirm(const char *words);  //���в���ȷ��




int main()
{
    char choice[10];


    while(1)
    {
    	printf( "\n-�˵�:\n"
            "1.����\t"
            "2.׷��\t"
            "3.ɾ��\t"
            "4.��ʾ\t"
            "5.����\t"
            "6.��ȡ�ļ�\t"
            "7.�����ļ�\t"
            "0.�˳�\n"
            "�������:");

        //choice=getchar();
        //getchar();     //���س�����
        scanf("%s",choice);
        switch(choice[0])
        {
        case '1':      //����
            find();
            break;
        case '2':      //׷��
            input();
            break;
        case '3':      //ɾ��
            del();
            break;
        case '4':      //��ʾ
            output();
            break;
        case '5':      //����
            order();
            break;
        case '6':      //��ȡ�ļ�
            read();
            break;
        case '7':      //�����ļ�
            write();
            break;
        case '0':
            if (confirm("�˳�ǰ���棿��Y/N��"))
            {
               write();
            }
            exit(0);
            break;
        default:
            printf("û�и���ţ�����������\n");
            break;
        }
    }

}

void input()
{
    struct _student *temp;
    if(tail!=NULL)   //������ʱ������β�����ӽڵ�
    {
        tail->next=(struct _student*)malloc(LEN);
        tail=tail->next;
        temp=tail;
    }
    else             //������ʱ��������
    {
        head=(struct _student*)malloc(LEN);
        tail=head;
        temp=tail;
    }

        printf("������һ��ѧ����Ϣ:\n\tѧ��(��ʽ��10041461**)��");
        scanf("%d",&temp->ID);
        printf("\t������");
        scanf("%19s",temp->name);
        printf("\t�Ա�\t(0-Ů��1-��)��");
        scanf("%d",&temp->gender);
        printf("\t������");
        scanf("%lf",&temp->score);
        temp->next=NULL;
        num++;
        printf("\t������������ڲ˵��в鿴\n");
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
       printf("��0�����ݣ�");
       return;
   }
   printf("\nѧ����Ϣ:");
   while(temp->next!=NULL)
   {
        printf("\n\tѧ�ţ�%d",temp->ID);
        printf("\t������%19s",temp->name);
        printf("\t�Ա�\t(0-Ů��1-��)��%d",temp->gender);
        printf("\t������%f",temp->score);

        temp=temp->next;
   }

        printf("\n\tѧ�ţ�%d",temp->ID);
        printf("\t������%19s",temp->name);
        printf("\t�Ա�\t(0-Ů��1-��)��%d",temp->gender);
        printf("\t������%f",temp->score); //������һ���ڵ�����
   printf("\n������Ϣ���������");
   return ;
}
void find()
{
    char name[20];
    struct _student *temp;
    printf("������������");
    scanf("%19s",name);
    if(head!=NULL)
    {
       temp=head;
       while(strcmp(temp->name,name)) //�ַ����Ƚϲ�����==�����Ƚϵ�ַ,Ҫ�����ַ����ȽϺ���
       {
           if(temp->next==NULL)  //����ѯ�����һ���Բ���ȣ��˳�����nextΪ�գ�����ִ�л����
           {
               printf("�����������ݲ�����!");
               return;
           }
           temp=temp->next;
       }
        printf("\n\tѧ�ţ�%d",temp->ID);
        printf("\t������%19s",temp->name);
        printf("\t�Ա�\t(0-Ů��1-��)��%d",temp->gender);
        printf("\t������%f",temp->score);
    }
    else
    {
        printf("������˼����0������");
    }
  return ;
}
void del()
{
    char name[20];
    struct _student *temp,*pre;
    pre=NULL;
    printf("������������");
    scanf("%19s",name);
    if(head!=NULL)
    {
       temp=head;
       while(strcmp(temp->name,name)) //�ַ����Ƚϲ�����==�����Ƚϵ�ַ,Ҫ�����ַ�������
       {
           if(temp->next==NULL)  //����ѯ�����һ���Բ���ȣ��˳�����nextΪ�գ�����ִ�л����
           {
               printf("�����������ݲ�����!");
               return;
           }
           pre=temp;
           temp=temp->next;
       }
        printf("\n\tѧ�ţ�%d",temp->ID);
        printf("\t������%19s",temp->name);
        printf("\t�Ա�\t(0-Ů��1-��)��%d",temp->gender);
        printf("\t������%f",temp->score);
    }
    else
    {
        printf("������˼����0������");
        return;
    }

       if(confirm("\nȷ��ɾ������Y/N��"))   //���в���֮ǰȷ��
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
            num--;  //ѧ���������٣���Ҫ�����ﲻ�Ӻ�����п�ָ��
            printf("ɾ���ɹ���");
           }
           else     //������ͷ�ڵ�
           {
                 if(head->next!=NULL)   //������ͷ�ڵ��Ҳ�ֹһ���ڵ�
                {
                 head=head->next;
                 num--;
                 printf("ɾ���ɹ���");
                }
                else                    //������ͷ�ڵ���ֻ��һ���ڵ�
                {
                 head=NULL;
                 tail=NULL;
                 num--;
                 printf("ɾ���ɹ���");
                 printf("��0������");
                }
           }

       }
       else
       {
           printf("ɾ��ʧ�ܣ�");
       }
  return ;
}
void order()
{
    if(head!=NULL)          //�ж������Ƿ����
    {
        if(head->next == NULL)
        {
            return;
        }
        int i,j;
        int isChange = 1;   //ð��������һ������û�н������˳�ѭ��
        struct _student *temp,*pre,*first,*second;

        for(i=0;i<num-1&&isChange;i++)
        {
            temp=head;
            isChange=0;
            for(j=0;j<num-1-i;j++)
            {
                if(temp->ID>temp->next->ID)  //��ǰһ�ڵ����ݱȺ�һ�ڵ���򽻻�
                {
                    first=temp;      //��Ҫ���ṹ��ĸ�ֵ�Ǹ�ֵ�����Ǹ���ַ���������ͬ!
                    second=temp->next;
                    if(temp->next==tail)
                    {
                        tail=first;    //��Ҫ������β�ڵ㽻����Ҫ�ı�βָ��
                    }

                    first->next=second->next;
                    second->next=first;

                    if(pre==NULL)
                    {
                        head=second; //��Ҫ������ͷ�ڵ㽻����Ҫ�ı�ͷָ��
                    }
                    else
                    {
                       pre->next=second;
                    }
                    isChange=1;
                    temp=second;  //��Ҫ������֮��һ��Ҫ�ı䵱ǰָ��
                }
                pre=temp;
                temp=temp->next;
            }
        }
        printf("����ɹ���");

    }
    else
    {
        printf("0�����ݣ�");
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
                printf("��ȡʧ��");
                return ;
            }

            temp->next=stu;
            temp=temp->next; //tempΪ��ǰ����stu��ǰһ���ڵ�
          }
          else
          {
            head=(struct _student*)malloc(LEN);
            if(fread(head,LEN,1,fp)!=1)
            {
                printf("��ȡʧ��");
                return ;
            }
            temp=head;
          }
        }
        tail=temp;
        printf("��ȡ�ɹ���");
      fclose(fp);
    }
    else
    {
        printf("���ļ�ʧ�ܣ�");
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
               printf("д��ʧ��");
               return ;
           }
           temp=temp->next;      //tempΪ��ǰд��ڵ�
       }

       if(fwrite(temp,LEN,1,fp)!=1)
           {
               printf("д��ʧ��");
               return ;
           }                      //temp����β����nextΪ�գ������г�

        printf("д��ɹ���");
        fclose(fp);
    }
    else
    {
        printf("���ļ�ʧ�ܣ�");
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
            printf("����Ƿ����������룡");
            continue;
        case 'Y':
        case 'y':
            printf("��ȷ�ϣ�");
            return 1;
        case 'N':
        case 'n':
            printf("��ȡ����");
            return 0;
        }
    }
}
