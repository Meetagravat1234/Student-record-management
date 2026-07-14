#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

typedef struct student
{
    int num;
    char s[20];
    float m;
    struct student *next;
} std;

std *head = 0;

void stud_add();
int lpn();
void stud_show();
void stud_deln();
void stud_delr();
void search_r();
void search_n();
void search_p();
void save_data();
void sort_p();
void sort_n();
void rev_link();
void delete_all();
void add_m();
void add_e();

void main()
{
    char ch,ch1;

    while(1)
    {
        printf("\n   *** STUDENT RECORD MENU ***  \n\n");
        printf("a/A :add new record\nd/D :dlete a record\ns/S :show the list\nm/M :modify a record\nv/V :save\ne/E :exit\nt/T :sort the list\nl/L :delete all the records\nr/R :reverse the list\n\nEnter your choice:");
        scanf(" %c",&ch);

        if(ch>='A' && ch<='Z')
        {
            ch = ch + 32;
        }

        switch(ch)
        {
            case 'a':
                printf("\nA/a :add at begin\nM/m :add at middle\nE/e : add at end\n");
                printf("enter your choice: ");
                char choice;
                scanf(" %c",&choice);
                 if(choice>='A' && choice<='Z')
          {
              choice= choice + 32;
          }
                switch(choice)
{
                case 'a':
                stud_add();
                break;
                case 'm':
                add_m();
                break;
                case 'e':
                add_e();
                break;
                
                default:printf("\nenter the valid choice\n");break;

}
break;

            case 's':
                stud_show();
                break;

            case 'd':
                printf("\nR/r :enter the roll no to delete\nN/n :enter name to delete\nenter the choice :");
                scanf(" %c",&ch1);

                if(ch1>='A' && ch1<='Z')
                {
                    ch1 = ch1+ 32;
                }

                switch(ch1)
                {
                    case 'r':
                        stud_delr();
                        break;

                    case 'n':
                        stud_deln();
                        break;

                    default:
                        printf("enter the valid option\n");
                        break;
                }
                break;
                
                case 'm' :printf("\nenter which record search for modification\n");
                        printf("\nR/r :to search a roll num\nN/n :to search a name\nP/p : percentage based\n\nenter the choice :");
                        char ch2;
                        scanf(" %c",&ch2);
                        if(ch2>='A' && ch2<='Z')
                {
                    ch2 = ch2+ 32;
                }
                        switch(ch2)
                        {
                           case 'r':search_r();break;
                           case 'n':search_n();break;
                           case 'p':search_p();break;
                           default:printf("enter the valid options\n");break;
                        }
                        break;
               // case 'e':exit(0);break;
                case 'e':printf("\nS/s :save and exit\nE/e :exit without saving\nenter your choice :");
                     char ch3;
                     scanf(" %c",&ch3);
                     if(ch3>='A' && ch3<='Z')
                     {
                    ch3 = ch3+ 32;
                     }
                     switch(ch3)
                     {
                         case 's':save_data();break;
                         case 'e':exit(0);break;
                         default:printf("/n enter the valid options\n");break;
                     }
                     break;
                case 't':printf("\nN/n :sort with name\nP/p :sort with percentage\n\nEnter the choice :");
                    char ch4;
                    scanf(" %c",&ch4);
                    if(ch4>='A' && ch4<='Z')
                     {
                    ch4 = ch4+ 32;
                     }
                     switch(ch4)
                     {
                         case 'n':sort_n();break;
                         case 'p':sort_p();break;
                         default:printf("enter the valid choice\n");break;
                     }
                     break;
                    
                case 'l':delete_all();break;
                case 'r':rev_link();break;
                
                case 'v':save_data();break;                    
                

            default:
                printf("enter the valid options\n");
                break;
        }
    }
}

void stud_add()
{
    std *new;
    new = malloc(sizeof(std));

    new->num = lpn();

    printf("enter the name and marks\n");
    scanf("%s",new->s);
    scanf("%f",&(new->m));

    if(head==0)
    {
        new->next = 0;
        head = new;
    }
    else
    {
        new->next = head;
        head = new;
    }
}

int lpn()
{
    int c = 1, temp = 0;

    while(1)
    {
        std *ptr = head;
        temp = 0;

        while(ptr)

        {
            if(ptr->num == c)
            {
                temp = 1;
                break;
            }
            ptr = ptr->next;
        }

        if(temp == 0)
            return c;

        c++;
    }
}

void stud_show()
{
    std *ptr = head;

    if(ptr == 0)
    {
        printf("no data is avaiable\n");
        return;
    }

    printf("\n   *** student data ***\n");
    printf("\nno name  marks\n");

    while(ptr)
    {
     printf("%d %s %.2f \n",ptr->num,ptr->s,ptr->m);
        ptr = ptr->next;
    }
}

void stud_delr()
{
    int n;

    printf("\nenter the roll number of student that you want to delete\n");
    scanf("%d",&n);

    std *ptr = head;

    if(ptr == 0)
    {
        printf("no data is avaiable to delete\n");
        return;
    }
    if(ptr->num==n)
    {
       head=ptr->next;
       free(ptr);
    }
    std *pre=0;
    while(ptr)
    {
        if(ptr->num==n)
        {
            pre->next=ptr->next;
            free(ptr);
            printf("\n data deletes successfully\n");
            return;
        }
        pre=ptr;
        ptr=ptr->next;
    }
    printf("\n no number found enter valid data\n");
    return;
}
void stud_deln()
{
  printf("enter the name of studnet that you want to deete\n");
  char s[20];
  scanf("%s",s);
  std *ptr=head;
  if(ptr==0)
  {
      printf("no record found\n");
      return;
  }
  int c=0;
  while(ptr)
  {
      if(strcmp(ptr->s,s)==0)
      {
          printf("%d %s %f\n",ptr->num,ptr->s,ptr->m);
          c++;
      }
   ptr=ptr->next;
  }
  if(c>0)
  {
    stud_delr();
    return;
  }
 printf("\n enter the valid name\n");
}

void search_r()
{
    int n;
    printf("\enter the roll number that you want to modify\n");
    scanf(" %d",&n);
    
    std *ptr=head;
    if(ptr==0)
    {
        printf("\nno recod found\n");
        return ;
    }
    int c=0;
    while(ptr)
    {
        if(ptr->num==n)
        {
            printf("%d %s %f\n",ptr->num,ptr->s,ptr->m);
            printf("\nnow enter the name and percentage you want to modify\n");
            char s[20];
            float f;
            scanf("%s %f",ptr->s,&ptr->m);
            printf("\n data modified successfully\n");
           // printf("\n new data is %s %f",ptr->s,ptr->m);
            c++;
            
        }
        ptr=ptr->next;
    }
    if(c>0)
    return;
    printf("\n roll number is not found enter valid roll number\n");
    return;
}
void search_n()
{
  printf("\n enter the name of studnet that you want to modify\n");
  char s[20];
  scanf("%s",s);
  std *ptr=head;
  if(ptr==0)
  {
      printf("no record found\n");
      return;
  }
  int c=0;
  while(ptr)
  {
      if(strcmp(ptr->s,s)==0)
      {
          printf("%d %s %f\n",ptr->num,ptr->s,ptr->m);
          c++;
      }
   ptr=ptr->next;
  }
  if(c>0)
  {
    printf("\n enter the roll no of that student name\n");
    search_r();
    return;
  }
 printf("\n enter the valid name\n");
 return;
    
}
void search_p()
{
  printf("enter the percenatge of studnet that you want to modify\n");
  float f;
  scanf(" %f",&f);
  std *ptr=head;
  if(ptr==0)
  {
      printf("no record found\n");
      return;
  }
  int c=0;
  while(ptr)
  {
      if((ptr->m)==f)
      {
          printf("%d %s %f\n",ptr->num,ptr->s,ptr->m);
          c++;
      }
   ptr=ptr->next;
  }
  if(c>0)
  {
    printf("\n enter the roll no of that percenatage students marks\n");
    search_r();
    return;
  }
 printf("\n enter the valid marks\n");
}
void save_data()
{
    std *ptr=head;
    if(ptr==0)
    {
        printf("\n no data is avaible for the storing in the file\n");
        return ;
    }
    FILE *fp;
    fp=fopen("student_data.txt","w+");
    while(ptr)
    {
      fprintf(fp,"%d %s %f\n",ptr->num,ptr->s,ptr->m);
      ptr=ptr->next;
    }
    printf("\n data saved successfully in student_data.txt\n");
    fclose(fp);
    return ;
}
void sort_n()
{
    std *ptr=head;
    if(ptr==0)
    {
        printf("\n data is not avaiable\n");
        return;
    }
    if(ptr->next==0)

    {
        printf("\n data is already sorted\n");
        return ;
    }
    int i,j,c=0;
    while(ptr)
    {
        c++;
        ptr=ptr->next;
    }
    std *ptr1,*ptr2;
    ptr1=head;
    for(i=0;i<c-1;i++)
    {
        ptr2=ptr1->next;
        for(j=0;j<c-1-i;j++)
        {
            if(strcmp(ptr1->s,ptr2->s)>0)
            {
                int t;
                char s[20];
                float f;
                t=ptr1->num;
                ptr1->num=ptr2->num;
                ptr2->num=t;
                
                strcpy(s,ptr1->s);
                strcpy(ptr1->s,ptr2->s);
                strcpy(ptr2->s,s);
                
                f=ptr1->m;
                ptr1->m=ptr2->m;
                ptr2->m=t;
                
                
            }
        }
        ptr1=ptr1->next;
    }
    return;
}
void sort_p()
{
  std *ptr=head;
    if(ptr==0)
    {
        printf("\n data is not avaiable\n");
        return;
    }
    if(ptr->next==0)
    {
        printf("\n data is already sorted\n");
        return ;
    }
    int i,j,c=0;
    while(ptr)
    {
        c++;
        ptr=ptr->next;
    }
    std *ptr1,*ptr2;
    ptr1=head;
    for(i=0;i<c-1;i++)
    {
        ptr2=ptr1->next;
        for(j=0;j<c-1-i;j++)
        {
            if((ptr1->m)>(ptr2->m))
            {
                int t;
                char s[20];
                float f;
                t=ptr1->num;
                ptr1->num=ptr2->num;
                ptr2->num=t;
                
                strcpy(s,ptr1->s);
                strcpy(ptr1->s,ptr2->s);
                strcpy(ptr2->s,s);
                
                f=ptr1->m;
                ptr1->m=ptr2->m;
                ptr2->m=f;
                
                
            }
        }
        ptr1=ptr1->next;
    }
    return;   
}
void delete_all()
{
    std *del=head;
    if(del==0)
    {
        printf("\n no recod for deleting\n");
        return;
    }
    while(del)
    {
        head=del->next;
        free(del);
        del=head;
    }
    printf("\n all data deleted successfully\n");
    
}
void rev_link()
{
    std *ptr=head;
    std *pre=0;
    std *next=0;
    if(ptr==0)
    {
        printf("\n no record for reverse\n");
        return ;
    }
    if(ptr->next==0)
    {
        printf("\n only one record cant able to reverse\n");
        return;
    }
    while(ptr)
    {
        next=ptr->next;
        ptr->next=pre;
        pre=ptr;
        ptr=next;
    }
    head=pre;
    printf("\n data reversed successfully\n");
}

void add_e()
{

    std *ptr=head;
    std *new;
    new = malloc(sizeof(std));

    new->num = lpn();

    printf("enter the name and marks\n");
    scanf("%s",new->s);
    scanf("%f",&(new->m));
    
   new->next=0;
   if(ptr==0)
   {
     head=new;
     return;
   }
   while(ptr->next!=0)
   {
     ptr=ptr->next;
   }
   ptr->next=new;
}
void add_m()
{

    std *new,*ptr=head;
    new = malloc(sizeof(std));

    new->num = lpn();

    printf("enter the name and marks\n");
    scanf("%s",new->s);
    scanf("%f",&(new->m));

if(ptr==0||(new->num)<ptr->num)
{
  new->next=ptr;
  head=new;

}
else
{
  while(ptr->next!=0&&(new->num)>(ptr->next->num))
  ptr=ptr->next;

  new->next=ptr->next;
  ptr->next=new;
}
}
