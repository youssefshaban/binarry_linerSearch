#include<stdio.h>
#include<string.h>
#include<conio.h>


struct employee {
  int id;
  int salary ;
  char name[20];
};
struct employee ar [5];
void fill();
void B_Sort();
 int liner_search (char data[]);
int binary_search(int LB,int UB , char data[]);
void B_Sort_name();
void print();
void add_employee (struct employee emp);
int index=0;
int main (){
    int opration;
    int flag = 0,loc;
    char name [20];
    do{    if(index<5){
	printf(" to add new employee enter 1 \n and 2 for end program and print \n 3 to search by name(binary) \n 4 linerSrarch \n");
	}else{
	printf("there is no storage for adding new employee \n enter 2 to print \n 3 to search by name(binary) \n 4 linerSearch \n");
	}
	scanf("%d",&opration);
	if(opration==1){
	   if(index<5){ fill();    }
	}else if (opration==2){
	    B_Sort_name();
	    print();
	    flag=1;
	}else if (opration==3){
	printf("\n enter the name: ") ;
	scanf("%s",name);

	  B_Sort_name();
	  loc=binary_search(0,index-1,name);
	   if (loc==-1){
	     printf("Not exist");
	   }else{
	     printf("index %d  name-> %s \n",loc+1,ar[loc].name);
	   }
	}
	else if (opration==4){
	printf("\n enter the name: ") ;
	scanf("%s",name);


	  loc=binary_search(0,index-1,name);
	   if (loc==-1){
	     printf("Not exist");
	   }else{
	     printf("index %d  name-> %s \n",loc+1,ar[loc].name);
	   }
	   }


    }while(flag == 0);

    getch();
    clrscr();
return 0;
}
void B_Sort(){

 int i,j;
 struct employee temp;

 for(j=0 ; j<index-1;j++){

   for(i=0;i<index-1-j;i++){

      if(ar[i].id > ar[i+1].id){
	 temp=ar[i];
	 ar[i]=ar[i+1];
	 ar[i+1]=temp;

      }
   }
 }
}

void add_employee (struct employee emp){
	if (index<=4){

		 ar[index]= emp;
		 index++;
	}

	else {
		printf("sorry there is no position for adding now one ");
	}

}
void fill (){
	struct employee emp ;
	printf("enter the id : ");
	scanf("%d",&emp.id);
	printf("enter the name : ");
	scanf("%s",emp.name);
	printf("enter the salary : ");
	scanf("%d",&emp.salary);
	add_employee(emp);
}
void print(){
	int i;
	for (i=0;i<=index-1;i++){
	printf("id : %d  |  name: %s  |  salary: %d \n",ar[i].id,ar[i].name,ar[i].salary);

	}

}

void B_Sort_name(){

 int i,j;
 struct employee temp;

 for(j=0 ; j<index-1;j++){

   for(i=0;i<index-1-j;i++){

      if(ar[i].name[0] > ar[i+1].name[0]){
	 temp=ar[i];
	 ar[i]=ar[i+1];
	 ar[i+1]=temp;

      }else if(ar[i].name[0]==ar[i+1].name[0]){
				if(ar[i].name[1]>ar[i+1].name[1]){
				temp=ar[i];
				ar[i]=ar[i+1];
				ar[i+1]=temp ;
				}

      }
   }
 }
 }
 int binary_search(int LB,int UB,char data[]){
	   int loc=-1,mid;
	   mid = (LB+UB)/2;
	   if(ar[mid].name[0]==data[0]){
		loc=mid;
	   }else if (ar[mid].name[0]<data[0]){
	       loc   =	binary_search(mid+1,UB,data);
	   }else {
		loc = binary_search(LB,mid-1,data);

	   }


	      return loc;

 }
 int liner_search (char data[]){
	int loc=-1;
	int flag=0;
	int helper = 0;
	while(flag==0&&helper <= index-1){
       if(ar[helper].name[0]==data[0]){
	  if (ar[helper].name[1]==data[1]){
		if (ar[helper].name[2]==data[2]){
			if(ar[helper].name[3]==data[3]){
				loc=helper ;
				flag=1;
			}
		}
	  }
       }

	}
	return loc;
 }
