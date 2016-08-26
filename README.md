# StudentInfo
A program in C which reads student-related data from file and provides function of sort,deletion,add,etc.
##【需求分析】
###功能需求分析：  
用C语言实现从已知文档中读取学生信息，可以实现增加、删除、查找等功能的程序。  
 
##【系统设计】
###数据存储结构：   
将每个学生信息存入一个结构体中，并将结构体组成链表  
###实例：  
typedef struct _student  
{  
	int ID;            //存储学号  
	char name[20];     //存储姓名  
	int gender;         //存储性别  
	double score;       //存储得分  
	struct _student *next; //指向下一个结构体节点  
}Student;  

##【重要逻辑注释】
###重要函数：  
void input();             //输入一个学生信息  
void output();            //输出所有学生信息  
void find();              //查找对应姓名的学生信息  
void del();               //删除一个学生信息  
void order();             //对学号进行排序  
void read();              //从文件中读取信息  
void write();              //将所有信息输出到文件中  
int confirm(const char *words);  //敏感操作确认  
 
