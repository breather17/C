#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char id[10];
    char name[10];
    char time[20];
    int score;
}Student;
int stu_count=0;
int main()
{
    int min_socre=100;
    int max_score=0;
    float total=0;
    Student student[100];
    FILE *fp=fopen("stuList.txt","r");
	if (NULL == fp)
	{
		perror("fopen");
		return 1;
	}
    while(!feof(fp)){
        int ret=fscanf(fp,"%s %s %s %d",student[stu_count].id,
                       student[stu_count].name,student[stu_count].time,
                       &student[stu_count].score);
        if(ret!=4){
            break;
        }
        total=total+student[stu_count].score;
        if(max_score<student[stu_count].score){
            max_score=student[stu_count].score;
        }
        if(min_socre>student[stu_count].score){
            min_socre=student[stu_count].score;
        }
        stu_count++;
    }
    printf("学号\t\t姓名\t\t出生日期\t成绩\n");
    for(int i=0;i<stu_count;i++){
        printf("%s\t",student[i].id);
        printf("%s\t\t",student[i].name);
        printf("%s\t\t",student[i].time);
        printf("%d\n",student[i].score);
    }
    printf("最高分为：%d  最低分为：%d  平均分为：%.2f",max_score,min_socre,total/stu_count);
}
