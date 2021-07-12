#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define max 7
clock_t start,end;
struct student{int day,month,year;
int ID;
 char name[100];
 int score_last_year;
};
struct hashing{
struct student *birthday;
};
struct hashing *sarray;
int linear_probing(int tot)
{
    for(int i=0; i<max; i++)
 {int key= ((tot+i)%max);

    if(sarray[key].birthday==NULL)
    return key;
 }
 printf("Collision element already exist!\n");
        printf("Unable to insert \n");
        return -1;
}

int quadratic_probing(int tot)
{
   for(int i=0; i<max; i++)
 {int key= ((tot+i*i)%max);

    if(sarray[key].birthday==NULL)
    return key;
 }
printf("Collision element already exist!\n");
        printf("Unable to insert \n");
        return -1;
}
void init_array()
{
    int i;
    for (i = 0; i < max; i++)
    {
	sarray[i].birthday = NULL;
	//sarray[i].birthday->day=0,sarray[i].birthday->month=0,sarray[i].birthday->year=0;

    }
}
void insert_student()
{
    int key,num;
        struct student *new_item = (struct student*) malloc(sizeof(struct student));

    printf("\tName:\n");
     fflush(stdin);
     fgets(new_item->name, sizeof(new_item->name), stdin);  // read name
     printf("\tEnter the student ID\n");
     scanf("%d",&new_item->ID);
     printf("\tEnter the student score_last_year\n");
     scanf("%d",&new_item->score_last_year);
     printf("\n enter the birth date\n");
    printf(" year :\t");
    scanf("%d",&new_item->year);
    printf("\n month :\t");
    scanf("%d",&new_item->month);
    printf("\n day :\t");
    scanf("%d",&new_item->day);


    int tot=new_item->year*360+new_item->month*30+new_item->day;
    printf("enter 1 to do linear probing \n enter 2 to do quadratic probing \t");
    scanf("%d",&num);
    start=clock();
    switch(num){
   case(2):key=quadratic_probing(tot);
   break;
   case(1):key=linear_probing(tot);
   break;
    }
    if(key!=-1)
         sarray[key].birthday=new_item;
}
int search(int nday, int nmonth,int nyear,char Name[100])
{
    int tot=nyear*360+nmonth*30+nday;

    for(int i=0; i<max; i++){
        int key = (tot+i) % max;
    if(sarray[key].birthday!=NULL)
    {
        if((sarray[key].birthday->day==nday)&&(sarray[key].birthday->month==nmonth)&&(sarray[key].birthday->year==nyear)/*&&(strcmp(sarray[key].birthday->name,Name)==0)*/)
        {
        return key;}

    }}
    return -1;

}
void del(int nday, int nmonth,int nyear,char Name[100])
{
    int key=search(nday,nmonth,nyear,Name);
    if(key != -1){sarray[key].birthday=NULL;
    printf("deleted successfully");}
    else
        printf("not present in the hash table\n");
}
void display(){
for(int i=0;i<max; i++)
    {
         if(sarray[i].birthday!=NULL)
        printf("index %d name: %s\t score_last_year: %d \t ID: %d  birthday %d/%d/%d\n",i ,sarray[i].birthday->name,sarray[i].birthday->score_last_year,sarray[i].birthday->ID,sarray[i].birthday->day,sarray[i].birthday->month,sarray[i].birthday->year);
        else printf("index %d empty place\n",i);

    }}
    void closed_addressing()
    {
        int x;

    sarray = (struct hashing*) malloc(max*sizeof(struct hashing*));
    printf("1Hello world!\n");
    init_array();
    printf("the memory requried to store the data for closed addressing is %d\n",sizeof(struct hashing));
    printf("the memory requried to store the data for student %d\n",sizeof(struct student));
    b:
    printf("enter\n 1 to insert\n 2 to delete student\n 3 to search\n 4 to display\n");
    scanf("%d",&x);
switch(x)
    {
    case(1):
        insert_student();
        end=clock();
    break;
    case(3):{int key=search(14, 12,1999,"ahmed");
    if(key!=-1)
    printf("Search Found found at index: %d\n",key);
    else printf("Search Not Found\n");
    break;}
    case(2):del(14, 12,1999,"ahmed");break;

   case(4):{
    display();break;}
   default:printf("out of range\n");break;}

   double cpu_time_used=((double)(end-start))/ CLOCKS_PER_SEC ;
printf(" time taken by function is %lf\n",cpu_time_used);
    goto b;

    }
int main()
{
    printf("welcome doctor omar\n");
    closed_addressing();

    return 0;
}
