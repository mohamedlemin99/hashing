#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define max 7
clock_t start,end;

struct student{int day,month,year;
int ID;
 char name[100];
 int score_last_year;
};
struct node{
struct student data;
struct student *next;
};
struct openhashing{
struct node *usename;


};
struct openhashing *narray;
void init()
{
    int i;
    for(i = 0; i < max; i++)
        narray[i].usename = NULL;
}
void insertop()
{
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    if(newNode==NULL)printf("Unable to allocate memory.");
    else{   printf("\n Name: ");
    fflush(stdin);
    fgets(newNode->data.name, sizeof(newNode->data.name), stdin);
   printf("\n enter the student ID ");
    scanf("%d",&newNode->data.ID);
    printf("\n enter the student score of last year ");
    scanf("%d",&newNode->data.score_last_year);
    printf("\n enter the birth date\n");
    printf(" year :\t");
    scanf("%d",&newNode->data.year);
    printf("\n day :\t");
    scanf("%d",&newNode->data.day);
    printf("\n month :\t");
    scanf("%d",&newNode->data.month);
    newNode->next=NULL;
    int tot=getasci(newNode->data.name);
    int key=(tot%max);
    start=clock();

    if(narray[key].usename==NULL)
    {
     narray[key].usename=newNode;
     printf("not used\n");
    }
     else
    {
        //add the node at the end of chain[key].
        struct node *temp = narray[key].usename;
        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
    }
}
int getasci(char name[100])
{
    int test[100]={},i=0,j,tot=0;
while(name[i]!='\0') {test[i]=name[i]; i++;}
for(j=0;j<i-1;j++)
{
tot=tot+(int)(test[j]);
}
return tot;
}
void displayy()
{
for(int i=0;i<max; i++)
    {
         if(narray[i].usename!=NULL){
                struct node *temp = narray[i].usename;
        while(temp)
        {
            printf("index: %d",i);
            printf(" name: %s\t score_last_year: %d \t ID: %d  birthday %d/%d/%d",temp->data.name,temp->data.score_last_year,temp->data.ID,temp->data.day,temp->data.month,temp->data.year);
            temp = temp->next;
            printf("\t-->\t");
        }
        printf("\n");

        }
        else printf("index %d empty place\n",i);

    }
}
deleet()
{
   char nname[100];int id;
    printf("\n Name: to delete \n ");
    fflush(stdin);
    fgets(nname, sizeof(nname), stdin);
    printf("\n enter the student ID ");
    scanf("%d",&id);
    int tot=getasci(nname);
    int key=(tot%max);
    struct node *head = narray[key].usename;
    struct node *temp=head->next;
    struct node *deleted;
    if((strcmp(head->data.name,nname)==0)&&(id==head->data.ID))
    {
      narray[key].usename=head->next;
      free(head);
      return;
    }
    while(temp){
    if((strcmp(temp->data.name,nname)==0)&&(id==head->data.ID))
    {
        deleted=temp;
        temp=temp->next;
        free(deleted);
       return;
    }
    temp=temp->next;

    }
    printf("%s    not found\n",nname);
}
void searchh()
{
    char nname[100];int id;
    printf("\n Name: to seach for\n ");
    fflush(stdin);
    fgets(nname, sizeof(nname), stdin);
     printf("\n enter the student ID ");
    scanf("%d",&id);
    int tot=getasci(nname);
    int key=(tot%max);
    struct node *temp = narray[key].usename;
    while(temp){
    if((strcmp(temp->data.name,nname)==0)&&(temp->data.ID==id))
    {
        printf("index: %d",key);
            printf(" name: %s\t score_last_year: %d \t ID: %d  birthday %d/%d/%d",temp->data.name,temp->data.score_last_year,temp->data.ID,temp->data.day,temp->data.month,temp->data.year);
return;
    }
    temp=temp->next;

    }
    printf("%s    not found\n",nname);


}
void open_adressing()
{
    narray = (struct openhashing*) malloc(max*sizeof(struct openhashing*));
    init();
    int num;
    printf("the memory requried to store the data for open addressing is %d\n",sizeof(struct openhashing));
    printf("the memory requried to store the data for student %d\n",sizeof(struct student));
    b:

    printf("enter\n 1 to insert\n 2 to display \n 3 to search \n 4 to delete !\n");
    scanf("%d",&num);
    switch(num)
    {
        case(1):
            insertop();
            end=clock();
            break;
        case(2):displayy();break;
        case(3):searchh();break;
        case(4):deleet();break;
        default:printf("out of range\n");break;
    }
    double cpu_time_used=((double)(end-start))/ CLOCKS_PER_SEC ;
printf(" time taken by function is %lf\n",cpu_time_used);
    goto b;
}
int main()
{
    printf("welcome doctor omar\n");
    open_adressing();
    return 0;
}
