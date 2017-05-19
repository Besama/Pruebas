/* Write a C program to implement stack. Stack is a LIFO data strcuture *
 * LIFO - Last in First Out *
 * Perform PUSH(insert operation), POP(Delete operation) and Display stack */
#include <stdio.h>
#include <conio.h>
#define MAXSIZE 5
struct stack /* Structure definition for stack */
{
	int stk[MAXSIZE];
	int top;
};
typedef struct stack STACK;
STACK s;
/* Function declaration/Prototype*/
void push (void);
int pop(void);
void display (void);
void main ()
{
	int choice;
	int option = 1;
	clrscr ();
	s.top = -1;
	printf ("STACK OPERATION\n");
	while (option)
	{
		printf ("------------------------------------------\n");
		printf (" 1 --> PUSH \n");
		printf (" 2 --> POP \n");
		printf (" 3 --> DISPLAY \n");
		printf (" 4 --> EXIT \n");
		printf ("------------------------------------------\n");
		printf ("Enter your choice\n");
		scanf ("%d", &choice);

		switch (choice)
		{
		case 1: push();
		break;
		case 2: pop();
		break;
		case 3: display();
		break;
		case 4: return;
		}
		fflush (stdin);
		printf ("Do you want to continue(Type 0 or 1)?\n");
		scanf ("%d", &option);
	}
}
/*Function to add an element to the stack*/
void push ()
{
	int num;
	if (s.top == (MAXSIZE - 1))
	{
		printf ("Stack is Full\n");
		return;
	}
	else
	{
		printf ("Enter the element to be pushed\n");
		scanf ("%d", &num);
		s.top = s.top + 1;
		s.stk[s.top] = num;
	}
	return;
}

/*Function to delete an element from the stack*/
int pop ()
{
	int num;
	if (s.top == - 1)
	{
		printf ("Stack is Empty\n");
		return (s.top);
	}
	else
	{
		num = s.stk[s.top];
		printf ("poped element is = %d\n", s.stk[s.top]);
		s.top = s.top - 1;
	}
	return(num);
}
/*Function to display the status of the stack*/
void display ()
{
	int i;
	if (s.top == -1)
	{
		printf ("Stack is empty\n");
		return;
	}
	else
	{
		printf ("\nThe status of the stack is\n");
		for (i = s.top; i >= 0; i--)
		{
			printf ("%d\n", s.stk[i]);
		}
	}
	printf ("\n");
}
/*---------------------------------------------------------------------------
Output
STACK OPERATION
------------------------------------------
1 --> PUSH
2 --> POP
3 --> DISPLAY
4 --> EXIT
------------------------------------------
Enter your choice
1
Enter the element to be pushed
23
Do you want to continue(Type 0 or 1)?
1
------------------------------------------
1 --> PUSH
2 --> POP
3 --> DISPLAY
4 --> EXIT
------------------------------------------
Enter your choice
1
Enter the element to be pushed
45
Do you want to continue(Type 0 or 1)?
1
------------------------------------------
1 --> PUSH
2 --> POP
3 --> DISPLAY
4 --> EXIT
------------------------------------------
Enter your choice
1
Enter the element to be pushed
78
Do you want to continue(Type 0 or 1)?
1
------------------------------------------
1 --> PUSH
2 --> POP
3 --> DISPLAY
4 --> EXIT
------------------------------------------
Enter your choice
3
The status of the stack is
78
45
23
Do you want to continue(Type 0 or 1)?
1
------------------------------------------
1 --> PUSH
2 --> POP
3 --> DISPLAY
4 --> EXIT
------------------------------------------
Enter your choice
2
poped element is = 78
Do you want to continue(Type 0 or 1)?
1
------------------------------------------
1 --> PUSH
2 --> POP
3 --> DISPLAY
4 --> EXIT
------------------------------------------
Enter your choice
3
The status of the stack is
45
23
Do you want to continue(Type 0 or 1)?
0
--------------------------------------------------------------------------------------------------------------------------------------------*/
/* Write a C program to illustrate the operations of singly linked list */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX 30
struct EMP
{
	int empno;
	char empName[MAX];
	char designation[MAX];
	struct EMP *next;
};
/*********************************************************************/
/* Function to insert a node at the front of the linked list. */
/* front: front pointer, id: employee ID, name: employee name */
/* desg: Employee designation */
/* Returns the new front pointer. */
/*********************************************************************/
struct EMP* insert(struct EMP *front, int id, char name[], char desg[])
{
	struct EMP *newnode;
	newnode = (struct EMP*) malloc(sizeof(struct EMP));
	if (newnode == NULL)
	{
		printf("\nAllocation failed\n");
		exit(2);
	}
	newnode->empno = id;
	strcpy(newnode->empName, name);
	strcpy(newnode->designation, desg);
	newnode->next = front;
	front = newnode;
	return(front);
} /*End of insert() */
/* Function to display a node in a linked list */
void printNode(struct EMP *p)
{
	printf("\nEmployee Details...\n");
	printf("\nEmp No : %d", p->empno);
	printf("\nName : %s", p->empName);
	printf("\nDesignation : %s\n", p->designation);
	printf("-------------------------------------\n");
} /*End of printNode() */
/* ********************************************************/
/* Function to deleteNode a node based on employee number */
/* front: front pointer, id: Key value */
/* Returns: the modified list. */
/* ********************************************************/
struct EMP* deleteNode(struct EMP *front, int id)
{
	struct EMP *ptr;
	struct EMP *bptr; /* bptr is pointing to the node behind ptr */

	if (front->empno == id)
	{
		ptr = front;
		printf("\nNode deleted:");
		printNode(front);
		front = front->next;
		free(ptr);
		return(front);
	}
	for(ptr=front->next, bptr=front; ptr!=NULL; ptr=ptr->next, bptr=bptr->next)
	{
		if (ptr->empno == id)
		{
			printf("\nNode deleted:");
			printNode(ptr);
			bptr->next = ptr->next;
			free(ptr);
			return(front);
		}
	}
	printf("\nEmployee Number %d not found ", id);
	return(front);
} /*End of deleteNode() */
/*****************************************************************/
/* Function to search the nodes in a linear fashion based emp ID */
/* front: front pointer, key: key ID. */
/*****************************************************************/
void search(struct EMP *front, int key)
{
	struct EMP *ptr;
	for (ptr = front; ptr != NULL; ptr = ptr -> next)
	{
		if (ptr->empno == key)
		{
			printf("\nKey found:");
			printNode(ptr);
			return;
		}
	}
	printf("\nEmployee Number %d not found ", key);
} /*End of search() */
/* Function to display the linked list */
void display(struct EMP *front)
{
	struct EMP *ptr;
	for (ptr = front; ptr != NULL; ptr = ptr->next)
	{
		printNode(ptr);
	}
} /*End of display() */
/* Function to display the menu of operations on a linked list */
void menu()
{
	printf("---------------------------------------------\n");
	printf("Press 1 to INSERT a node into the list \n");
	printf("Press 2 to DELETE a node from the list \n");
	printf("Press 3 to DISPLAY the list \n");
	printf("Press 4 to SEARCH the list \n");
	printf("Press 5 to EXIT \n");
	printf("---------------------------------------------\n");
} /*End of menu() */
/* Function to select the option */
char option()
{
	char choice;
	printf("\n\n>> Enter your choice: ");
	switch(choice=getche())
	{
	case '1':
	case '2':
	case '3':
	case '4':
	case '5': return(choice);
	default : printf("\nInvalid choice.");
	}
	return choice;
} /*End of option() */
/* The main() program begins */
void main()
{
	struct EMP *linkList;
	char name[21], desig[51];
	char choice;
	int eno;
	linkList = NULL;
	printf("\nWelcome to demonstration of singly linked list\n");
	menu(); /*Function call */
	do {
		choice = option(); /*to choose oeration to be performed */
		switch(choice)
		{
		case '1': printf("\nEnter the Employee Number : ");
		scanf("%d", &eno);
		printf("Enter the Employee name : ");
		fflush(stdin);
		gets(name);
		printf("Enter the Employee Designation : ");
		gets(desig);
		linkList = insert(linkList, eno, name, desig);
		break;
		case '2': printf("\n\nEnter the employee number to be deleted: ");
		scanf("%d", &eno);
		linkList = deleteNode(linkList, eno);
		break;
		case '3': if (linkList == NULL)
		{
			printf("\nList empty.");
			break;
		}
		display(linkList);
		break;
		case '4': printf("\n\nEnter the employee number to be searched: ");
		scanf("%d", &eno);
		search(linkList, eno);
		break;
		case '5': break;
		}
	} while (choice != '5');
} /*End fo main()*/
/*------------------------------------------------------------------------------
Output
Welcome to demonstration of singly linked list
---------------------------------------------
Press 1 to INSERT a node into the list
Press 2 to DELETE a node from the list
Press 3 to DISPLAY the list
Press 4 to SEARCH the list
Press 5 to EXIT
---------------------------------------------

>> Enter your choice: 1
Enter the Employee Number : 1234
Enter the Employee name : Keerthi
Enter the Employee Designation : Engineer

>> Enter your choice: 1
Enter the Employee Number : 2345
Enter the Employee name : Srinivasan
Enter the Employee Designation : Specilist

>> Enter your choice: 1
Enter the Employee Number : 4567
Enter the Employee name : Annapoorna
Enter the Employee Designation : Project Manager

>> Enter your choice: 3
Employee Details...
Emp No : 4567
Name : Annapoorna
Designation : Project Manager
-------------------------------------
Employee Details...
Emp No : 2345
Name : Srinivasan
Designation : Specilist
-------------------------------------
Employee Details...
Emp No : 1234
Name : Keerthi
Designation : Engineer
-------------------------------------

>> Enter your choice: 2
Enter the employee number to be deleted: 2345
Node deleted:
Employee Details...
Emp No : 2345
Name : Srinivasan
Designation : Specilist
-------------------------------------

>> Enter your choice: 3
Employee Details...
Emp No : 4567
Name : Annapoorna
Designation : Project Manager
-------------------------------------
Employee Details...
Emp No : 1234
Name : Keerthi
Designation : Engineer
-------------------------------------

>> Enter your choice: 4
Enter the employee number to be searched: 2345
Employee Number 2345 not found
>> Enter your choice: 5
--------------------------------------------------------------------------------------------------------------------------------------------------*/
/* This program accepts an array of N elements and a key. *
 * Then it searches for the desired element. If the search *
 * is successful, it displays "SUCCESSFUL SEARCH". *
 * Otherwise, a message "UNSUCCESSFUL SEARCH" is displayed. */
#include <stdio.h>
void main()
{
	int table[20];
	int i, low, mid, high, key, size;
	printf("Enter the size of an array\n");
	scanf("%d", &size);
	printf("Enter the array elements\n");
	for(i = 0; i < size; i++)
	{
		scanf("%d", &table[i]);
	}
	printf("Enter the key\n");
	scanf("%d", &key);
	/* search begins */
	low = 0;
	high = (size - 1);
	while(low <= high)
	{
		mid = (low + high)/2;
		if(key == table[mid])
		{
			printf("SUCCESSFUL SEARCH\n");
			return;
		}
		if(key < table[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	printf("UNSUCCESSFUL SEARCH\n");
} /* End of main() */
/*----------------------------------
Output
Output
Enter the size of an array
5
Enter the array elements
12
36
45
78
99
Enter the key
45
SUCCESSFUL SEARCH
------------------------------------------------------------------------------------------------------------------------------------------------*/
/*Write a C program to illustrate as to how the data stored on the disk is read */
#include <stdio.h>
#include <stdlib.h>
void main()
{
	FILE *fptr;
	char filename[15];
	char ch;
	printf("Enter the filename to be opened\n");
	gets(filename);
	fptr = fopen (filename, "r"); /*open for reading*/
	if (fptr == NULL)
	{
		printf("Cannot open file\n");
		exit(0);
	}
	ch = fgetc(fptr);
	while (ch != EOF)
	{
		printf ("%c", ch);
		ch = fgetc(fptr);
	}
	fclose(fptr);
} /* End of main () */
/*----------------------------------------------
Output
Enter the filename to be opened
emp.rec
Name = Prabhu
Age = 25
Salary = 25000.00
--------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Write a C program to create a file called emp.rec and store information *
 * about a person, in terms of his name, age and salary. */
#include <stdio.h>
void main()
{
	FILE *fptr;
	char name[20];
	int age;
	float salary;
	fptr = fopen ("emp.rec", "w"); /*open for writing*/
	if (fptr == NULL)
	{
		printf("File does not exists\n");
		return;
	}
	printf("Enter the name\n");
	scanf("%s", name);
	fprintf(fptr, "Name = %s\n", name);
	printf("Enter the age\n");
	scanf("%d", &age);
	fprintf(fptr, "Age = %d\n", age);
	printf("Enter the salary\n");
	scanf("%f", &salary);
	fprintf(fptr, "Salary = %.2f\n", salary);
	fclose(fptr);
}
/*---------------------------------------------------------------------------
Output
Enter the name
Prabhu
Enter the age
25
Enter the salary
25000
-------------------------------------
Please note that you have to open the file called emp.rec in the directory
Name = Prabhu
Age = 25
Salary = 25000.00
--------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Write a C program to find the size of a union*/
#include <stdio.h>
void main()
{
	union sample
	{
		int m;
		float n;
		char ch;
	};
	union sample u;
	printf("The size of union =%d\n", sizeof(u));
	/*initialization */
	u.m = 25;
	printf("%d %f %c\n", u.m, u.n,u.ch);
	u.n = 0.2;
	printf("%d %f %c\n", u.m, u.n,u.ch);
	u.ch = 'p';
	printf("%d %f %c\n", u.m, u.n,u.ch);
} /*End of main() */
/*-----------------------------------------
Output
The size of union =4
25 12163373596672.000000 
-13107 0.200000 Í
-13200 0.199999 p
---------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Write a C program to illustrate the concept of unions*/
#include <stdio.h>
#include <conio.h>
void main()
{
	union number
	{
		int n1;
		float n2;
	};
	union number x;
	clrscr() ;
	printf("Enter the value of n1: ");
	scanf("%d", &x.n1);
	printf("Value of n1 =%d", x.n1);
	printf("\nEnter the value of n2: ");
	scanf("%d", &x.n2);
	printf("Value of n2 = %d\n",x.n2);
} /* End of main() */
/*------------------------------------
Output
Enter the value of n1: 2
Value of n1 =2
Enter the value of n2: 3
Value of n2 = 0
-------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Write a C program to accept an array of 10 elements and swap 3rd *
 * element with 4th element using pointers. And display the results */
#include <stdio.h>
void main()
{
	float x[10];
	int i,n;
	void swap34(float *ptr1, float *ptr2 ); /* Function Declaration */
	printf("How many Elements...\n");
	scanf("%d", &n);
	printf("Enter Elements one by one\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",x+i);
	}
	swap34(x+2, x+3); /* Function call:Interchanging 3rd element by 4th */
	printf("\nResultant Array...\n");
	for(i=0;i<n;i++)
	{
		printf("X[%d] = %f\n",i,x[i]);
	}
} /* End of main() */
/* Function to swap the 3rd element with the 4th element in the array */
void swap34(float *ptr1, float *ptr2 ) /* Function Definition */
{
	float temp;
	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
} /* End of Function */
/*-------------------------------------------
Output
How many Elements...
10
Enter Elements one by one
10
20
30
40
50
60
70
80
90
100
Resultant Array...
X[0] = 10.000000
X[1] = 20.000000
X[2] = 40.000000
X[3] = 30.000000
X[4] = 50.000000
X[5] = 60.000000
X[6] = 70.000000
X[7] = 80.000000
X[8] = 90.000000
X[9] = 100.000000
-------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Write a C program to find the sum of all elements of *
 * an array using pointersas arguments */
#include <stdio.h>
void main()
{
	static int array[5]={ 200,400,600,800,1000 };
	int sum;
	int addnum(int *ptr); /* function prototype */
	sum = addnum(array);
	printf("Sum of all array elements = %5d\n", sum);
} /* End of main() */

int addnum(int *ptr)
{
	int index, total=0;
	for(index = 0; index < 5; index++)
	{
		total += *(ptr+index);
	}
	return(total);
}
/*-----------------------------------
Output
Sum of all array elements = 3000
--------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Write a C program to find the sum of two one-dimensional arrays using *
 * Dynamic Memory Allocation */
#include <stdio.h>
#include <alloc.h>
#include <stdlib.h>
void main()
{
	int i,n;
	int *a,*b,*c;
	printf("How many Elements in each array...\n");
	scanf("%d", &n);
	a = (int *) malloc(n*sizeof(int));
	b = (int *) malloc(n*sizeof(int));
	c =( int *) malloc(n*sizeof(int));
	printf("Enter Elements of First List\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	printf("Enter Elements of Second List\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",b+i);
	}
	for(i=0;i<n;i++)
	{
		*(c+i) = *(a+i) + *(b+i);
	}
	printf("Resultant List is\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",*(c+i));
	}
} /* End of main() */
/*---------------------------------------
Output
How many Elements in each array...
4
Enter Elements of First List
1
2
3
4
Enter Elements of Second List
6
7
8
9
Resultant List is
7
9
11
13
-------------------------------------------------------------------------------------------------------------------------------------------*/
/* Write a C program to accept a set of names and sort them in *
 * an alphabetical order, Use structures to store the names */
#include<stdio.h>
#include<conio.h>
#include<string.h>
struct person
{
	char name[10];
	int rno;
};
typedef struct person NAME;
NAME stud[10], temp[10];
void main()
{
	int no,i;
	void sort(int N); /* Function declaration */
	clrscr();
	fflush(stdin);
	printf("Enter the number of students in the list\n");
	scanf("%d",&no);
	for(i = 0; i < no; i++)
	{
		printf("\nEnter the name of person %d : ", i+1);
		fflush(stdin);
		gets(stud[i].name);
		printf("Enter the roll number of %d : ", i+1);
		scanf("%d",&stud[i].rno);
		temp[i] = stud[i];
	}
	printf("\n*****************************\n");
	printf (" Names before sorting \n");
	/* Print the list of names before sorting */
	for(i=0;i<no;i++)
	{
		printf("%-10s\t%3d\n",temp[i].name,temp[i].rno);
	}
	sort(no); /* Function call */
	printf("\n*****************************\n");
	printf (" Names after sorting \n");
	printf("\n*****************************\n");
	/* Display the sorted names */
	for(i=0;i<no;i++)
	{
		printf("%-10s\t%3d\n",stud[i].name,stud[i].rno);
	}
	printf("\n*****************************\n");
} /* End of main() */
/* Function to sort the given names */
void sort(int N)
{
	int i,j;
	NAME temp;
	for(i = 0; i < N-1;i++)
	{
		for(j = i+1; j < N; j++)
		{
			if(strcmp(stud[i].name,stud[j].name) > 0 )
			{
				temp = stud[i];
				stud[i] = stud[j];
				stud[j] = temp;
			}
		}
	}
} /* end of sort() */
/*--------------------------------------------------------
Enter the number of students in the list
5
Enter the name of person 1 : Rajashree
Enter the roll number of 1 : 123
Enter the name of person 2 : John
Enter the roll number of 2 : 222
Enter the name of person 3 : Priya
Enter the roll number of 3 : 331
Enter the name of person 4 : Anand
Enter the roll number of 4 : 411
Enter the name of person 5 : Nirmala
Enter the roll number of 5 : 311
 *****************************
Names before sorting
Rajashree 123
John 222
Priya 331
Anand 411
Nirmala 311
 *****************************
Names after sorting
 *****************************
Anand 411
John 222
Nirmala 311
Priya 331
Rajashree 123
 *****************************
----------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Write a C program to accept a amtric of order MxN and sort all rows *
 * of the matrix in ascending order and all columns in descendng order */
#include <stdio.h>
void main ()
{
	static int ma[10][10],mb[10][10];
	int i,j,k,a,m,n;
	printf ("Enter the order of the matrix \n");
	scanf ("%d %d", &m,&n);
	printf ("Enter co-efficients of the matrix \n");
	for (i=0;i<m;++i)
	{
		for (j=0;j<n;++j)
		{
			scanf ("%d",&ma[i][j]);
			mb[i][j] = ma[i][j];
		}
	}
	printf ("The given matrix is \n");
	for (i=0;i<m;++i)
	{
		for (j=0;j<n;++j)
		{
			printf (" %d",ma[i][j]);
		}
		printf ("\n");
	}
	printf ("After arranging rows in ascending order\n");
	for (i=0;i<m;++i)
	{
		for (j=0;j<n;++j)
		{
			for (k=(j+1);k<n;++k)
			{
				if (ma[i][j] > ma[i][k])
				{
					a = ma[i][j];
					ma[i][j] = ma[i][k];
					ma[i][k] = a;
				}
			}
		}
	} /* End of outer for loop*/
	for (i=0;i<m;++i)
	{
		for (j=0;j<n;++j)
		{
			printf (" %d",ma[i][j]);
		}
		printf ("\n");
	}
	printf ("After arranging the columns in descending order \n");
	for (j=0;j<n;++j)
	{
		for (i=0;i<m;++i)
		{
			for (k=i+1;k<m;++k)
			{
				if (mb[i][j] < mb[k][j])
				{
					a = mb[i][j];
					mb[i][j] = mb[k][j];
					mb[k][j] = a;
				}
			}
		}
	} /* End of outer for loop*/
	for (i=0;i<m;++i)
	{
		for (j=0;j<n;++j)
		{
			printf (" %d",mb[i][j]);
		}
		printf ("\n");
	}
} /*End of main() */
/*-------------------------------------------------
Enter the order of the matrix
2 2
Enter co-efficients of the matrix
3 1
5 2
The given matrix is
3 1
5 2
After arranging rows in ascending order
1 3
2 5
After arranging the columns in descending order
5 2
3 1
--------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Write a C program to accept a matric and determine whether *
 * it is a sparse matrix. A sparse martix is matrix which *
 * has more zero elements than nonzero elements */
#include <stdio.h>
void main ()
{
	static int m1[10][10];
	int i,j,m,n;
	int counter=0;
	printf ("Enter the order of the matix\n");
	scanf ("%d %d",&m,&n);
	printf ("Enter the co-efficients of the matix\n");
	for (i=0;i<m;++i)
	{
		for (j=0;j<n;++j)
		{
			scanf ("%d",&m1[i][j]);
			if (m1[i][j]==0)
			{
				++counter;
			}
		}
	}
	if (counter>((m*n)/2))
	{
		printf ("The given matrix is sparse matrix \n");
	}
	else
		printf ("The given matrix is not a sparse matrix \n");
	printf ("There are %d number of zeros",counter);
} /* EN dof main() */
/*----------------------------------------------
Output
Enter the order of the matix
2 2
Enter the co-efficients of the matix
1 2
3 4
The given matrix is not a sparse matrix
There are 0 number of zeros
Run 2
Enter the order of the matix
3 3
Enter the co-efficients of the matix
1 0 0
0 0 1
0 1 0
The given matrix is sparse matrix
There are 6 number of zeros
--------------------------------------------------------------------------------------------------------------------------------------*/
/* Write a C program to accept a matricx of order MxN and find the trcae and *
 * normal of a matrix HINT:Trace is defined as the sum of main diagonal *
 * elements and Normal is defined as squre root of the sum of all *
 * the elements */
#include <stdio.h>
#include <math.h>
void main ()
{
	static int ma[10][10];
	int i,j,m,n,sum=0,sum1=0,a=0,normal;
	printf ("Enter the order of the matrix\n");
	scanf ("%d %d", &m,&n);
	printf ("Enter the ncoefficients of the matrix \n");
	for (i=0;i<m;++i)
	{
		for (j=0;j<n;++j)
		{
			scanf ("%d",&ma[i][j]);
			a = ma[i][j]*ma[i][j];
			sum1 = sum1+a;
		}
	}
	normal = sqrt(sum1);
	printf ("The normal of the given matrix is = %d\n",normal);
	for (i=0;i<m;++i)
	{
		sum = sum + ma[i][i];
	}
	printf ("Trace of the matrix is = %d\n",sum);
} /*End of main() */
/*---------------------------------------------------
Output
Enter the order of the matrix
3 3
Enter the ncoefficients of the matrix
1 2 3
4 5 6
7 8 9
The normal of the given matrix is = 16
Trace of the matrix is = 15
Run 2
Enter the order of the matrix
2 2
Enter the ncoefficients of the matrix
2 4
6 8
The normal of the given matrix is = 10
Trace of the matrix is = 10
--------------------------------------------------------------------------------------------------------------------------------------------*/
/* Write a C program to accept a string and find the sum of *
 * all digits present in the string */
#include <stdio.h>
void main()
{
	char string[80];
	int count,nc=0,sum=0;
	printf("Enter the string containing both digits and alphabet\n");
	scanf("%s",string);
	for(count=0;string[count]!='\0'; count++)
	{
		if((string[count]>='0') && (string[count]<='9'))
		{
			nc += 1;
			sum += (string[count] - '0');
		} /* End of if */
	} /* End of For */
	printf("NO. of Digits in the string=%d\n",nc);
	printf("Sum of all digits=%d\n",sum);
} /* End of main() */
/*-----------------------------------------------------
Output
Enter the string containing both digits and alphabet
goodmorning25
NO. of Digits in the string=2
Sum of all digits=7
---------------------------------------------------------------------------------------------------------------------------------------------*/
/* Write a C Program to accept a grade and declare the equivalent descrption *
 * if code is S, then print SUPER *
 * if code is A, then print VERY GOOD *
 * if code is B, then print FAIR *
 * if code is Y, then print ABSENT *
 * if code is F, then print FAILS */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
void main()
{
	char remark[15];
	char grade;
	printf("Enter the grade\n");
	scanf("%c",&grade);
	grade=toupper(grade); /* lower case letter to upper case */
	switch(grade)
	{
	case 'S': strcpy(remark," SUPER");
	break;
	case 'A': strcpy(remark," VERY GOOD");
	break;
	case 'B': strcpy(remark," FAIR");
	break;
	case 'Y': strcpy(remark," ABSENT");
	break;
	case 'F': strcpy(remark," FAILS");
	break;
	default : strcpy(remark, "ERROR IN GRADE\n");
	break;
	} /* End of switch */
	printf("RESULT : %s\n",remark);
} /* End of main() */
/*-------------------------------------------
Output
RUN 1
Enter the grade
s
RESULT : SUPER
RUN 2
Enter the grade
y
RESULT : ABSENT
-----------------------------------------------------------------------------------------------------------------------------------------------*/
/* Write a C program to accept a figure code and find the ares of different *
 * geometrical figures such as circle, square, rectangle etc using switch */
#include <stdio.h>
void main()
{
	int fig_code;
	float side,base,length,bredth,height,area,radius;
	printf("-------------------------\n");
	printf(" 1 --> Circle\n");
	printf(" 2 --> Rectangle\n");
	printf(" 3 --> Triangle\n");
	printf(" 4 --> Square\n");
	printf("-------------------------\n");
	printf("Enter the Figure code\n");
	scanf("%d",&fig_code);
	switch(fig_code)
	{
	case 1: printf("Enter the radius\n");
	scanf("%f",&radius);
	area=3.142*radius*radius;
	printf("Area of a circle=%f\n", area);
	break;
	case 2: printf("Enter the bredth and length\n");
	scanf("%f %f",&bredth, &length);
	area=bredth *length;
	printf("Area of a Reactangle=%f\n", area);
	break;
	case 3: printf("Enter the base and height\n");
	scanf("%f %f",&base,&height);
	area=0.5 *base*height;
	printf("Area of a Triangle=%f\n", area);
	break;
	case 4: printf("Enter the side\n");
	scanf("%f",&side);
	area=side * side;
	printf("Area of a Square=%f\n", area);
	break;
	default: printf("Error in figure code\n");
	break;
	} /* End of switch */
} /* End of main() */
/*----------------------------------------------------
Output
Run 1
-------------------------
1 --> Circle
2 --> Rectangle
3 --> Triangle
4 --> Square
-------------------------
Enter the Figure code
2
Enter the bredth and length
2
6
Area of a Reactangle=12.000000
Run 2
-------------------------
1 --> Circle
2 --> Rectangle
3 --> Triangle
4 --> Square
-------------------------
Enter the Figure code
3
Enter the base and height
5
7
Area of a Triangle=17.500000
---------------------------------------------------------------------------------------------------------------------------------------*/
/* Write a C program to accept a coordinate point in a XY coordinate system *
 * and determine its quadrant */
#include <stdio.h>
void main()
{
	int x,y;
	printf("Enter the values for X and Y\n");
	scanf("%d %d",&x,&y);
	if( x > 0 && y > 0)
		printf("point (%d,%d) lies in the First quandrant\n");
	else if( x < 0 && y > 0)
		printf("point (%d,%d) lies in the Second quandrant\n");
	else if( x < 0 && y < 0)
		printf("point (%d, %d) lies in the Third quandrant\n");
	else if( x > 0 && y < 0)
		printf("point (%d,%d) lies in the Fourth quandrant\n");
	else if( x == 0 && y == 0)
		printf("point (%d,%d) lies at the origin\n");
} /* End of main() */
/*---------------------------------------------
Output
RUN 1
Enter the values for X and Y
3 5
point (5,3) lies in the First quandrant
RUN 2
Enter the values for X and Y
-4
-7
point (-7, -4) lies in the Third quandrant

------------------------------------------------------------------------------------------------------------------------------------*/
//* Write a C program to accept the height of a person in centermeter and *
* categorize the person based on height as taller, dwarf and *
* average height person */
#include <stdio.h>
void main()
{
	float ht;
	printf("Enter the Height (in centimetres)\n");
	scanf("%f",&ht);
	if(ht < 150.0)
		printf("Dwarf\n");
	else if((ht>=150.0) && (ht<=165.0))
		printf(" Average Height\n");
	else if((ht>=165.0) && (ht <= 195.0))
		printf("Taller\n");
	else
		printf("Abnormal height\n");
} /* End of main() */
/*-----------------------------------
Output
Enter the Height (in centimetres)
45
Dwarf
-----------------------------------------------------------------------------------------------------------------------------------------*/
/* Write a C program to accept two integers and check if they are equal */
#include <stdio.h>
void main()
{
	int m,n;
	printf("Enter the values for M and N\n");
	scanf("%d %d", &m,&n);
	if(m == n )
		printf("M and N are equal\n");
	else
		printf("M and N are not equal\n");
} /* End of main() */
/*------------------------------------
output
Enter the values for M and N
34 45
M and N are not equal
---------------------------------------------------------------------------------------------------------------------------------------*/
/* Write a C program to accept a matrix of order M x N and store its elements *
 * and interchange the main diagonal elements of the matrix *
with that of the secondary diagonal elements */
#include <stdio.h>
void main ()
{
	static int ma[10][10];
	int i,j,m,n,a;
	printf ("Enetr the order of the matix \n");
	scanf ("%d %d",&m,&n);
	if (m ==n )
	{
		printf ("Enter the co-efficients of the matrix\n");
		for (i=0;i<m;++i)
		{
			for (j=0;j<n;++j)
			{
				scanf ("%dx%d",&ma[i][j]);
			}
		}
		printf ("The given matrix is \n");
		for (i=0;i<m;++i)
		{
			for (j=0;j<n;++j)
			{
				printf (" %d",ma[i][j]);
			}
			printf ("\n");
		}
		for (i=0;i<m;++i)
		{
			a = ma[i][i];
			ma[i][i] = ma[i][m-i-1];
			ma[i][m-i-1] = a;
		}
		printf ("THe matrix after changing the \n");
		printf ("main diagonal & secondary diagonal\n");
		for (i=0;i<m;++i)
		{
			for (j=0;j<n;++j)
			{
				printf (" %d",ma[i][j]);
			}
			printf ("\n");
		}
	}
	else
		printf ("The givan order is not square matrix\n");
} /* end of main() */
/*----------------------------------------------------
Output
Enetr the order of the matix
3 3
Enter the co-efficients of the matrix
1 2 3
4 5 6
7 8 9
The given matrix is
1 2 3
4 5 6
7 8 9
THe matrix after changing the
main diagonal & secondary diagonal
3 2 1
4 5 6
9 8 7
---------------------------------------------------------------------------------------------------------------------------*/
/* Write a C program to find the frequency of odd numbers *
 * and even numbers in the input of a matrix */
#include <stdio.h>
void main ()
{
	static int ma[10][10];
	int i,j,m,n,even=0,odd=0;
	printf ("Enter the order ofthe matrix \n");
	scanf ("%d %d",&m,&n);
	printf ("Enter the coefficients if matrix \n");
	for (i=0;i<m;++i)
	{
		for (j=0;j<n;++j)
		{
			scanf ("%d", &ma[i][j]);
			if ((ma[i][j]%2) == 0)
			{
				++even;
			}
			else
				++odd;
		}
	}
	printf ("The given matrix is\n");
	for (i=0;i<m;++i)
	{
		for (j=0;j<n;++j)
		{
			printf (" %d",ma[i][j]);
		}
		printf ("\n");
	}
	printf ("\nThe frequency of occurance of odd number = %d\n",odd);
	printf ("The frequency of occurance of even number = %d\n",even);
} /* End of main() */
/*-----------------------------------------------------
Output
Enter the order ofthe matrix
3 3
Enter the coefficients if matrix
1 2 3
4 5 6
7 8 9
The given matrix is
1 2 3
4 5 6
7 8 9
The frequency of occurance of odd number = 5
The frequency of occurance of even number = 4
-------------------------------------------------------------------------------------------------------------------------------------------*/
/* Write a C programme (1-D Array) store some elements in it.Accept key
& split from that point. Add the first half to the end of second half*/
#include <stdio.h>
void main ()
{
	int number[30];
	int i,n,a,j;
	printf ("Enter the value of n\n");
	scanf ("%d",&n);
	printf ("enter the numbers\n");
	for (i=0; i<n; ++i)
		scanf ("%d", &number[i]);
	printf ("Enter the position of the element to split the array \n");
	scanf ("%d",&a);
	for (i=0; i<a; ++i)
	{
		number[n] = number[0];
		for (j=0; j<n; ++j)
		{
			number[j] = number[j+1];
		}
	}
	printf("The resultant array is\n");
	for (i=0; i<n; ++i)
	{
		printf ("%d\n",number[i]);
	}
} /* End of main() */
/*-------------------------------------------------
Output
Enter the value of n
5
enter the numbers
30
10
40
50
60
Enter the position of the element to split the array
2
The resultant array is
40
50
60
30
10
----------------------------------------------------------*/
/* Write a C program to accept a list of data items and find the second *
largest and second smallest elements in it. And also computer the average *
of both. And search for the average value whether it is present in the *
array or not. Display appropriate message on successful search. */
#include <stdio.h>
void main ()
{
	int number[30];
	int i,j,a,n,counter,ave;
	printf ("Enter the value of N\n");
	scanf ("%d", &n);
	printf ("Enter the numbers \n");
	for (i=0; i<n; ++i)
		scanf ("%d",&number[i]);
	for (i=0; i<n; ++i)
	{
		for (j=i+1; j<n; ++j)
		{
			if (number[i] < number[j])
			{
				a = number[i];
				number[i] = number[j];
				number[j] = a;
			}
		}
	}
	printf ("The numbers arranged in descending order are given below\n");
	for (i=0; i<n; ++i)
	{
		printf ("%d\n",number[i]);
	}
	printf ("The 2nd largest number is = %d\n", number[1]);
	printf ("The 2nd smallest number is = %d\n", number[n-2]);
	ave = (number[1] +number[n-2])/2;
	counter = 0;
	for (i=0; i<n; ++i)
	{
		if (ave == number[i])
		{
			++counter;
		}
	}
	if (counter == 0 )
		printf ("The average of %d and %d is = %d is not in the array\n", number[1], number[n-2], ave);
	else
		printf ("The average of %d and %d in array is %d in numbers\n",number[1], number[n-2], counter);
} /* End of main() */
/*-------------------------------------------------------
Output
Enter the value of N
6
Enter the numbers
30
80
10
40
70
90
The numbers arranged in descending order are given below
90
80
70
40
30
10
The 2nd largest number is = 80
The 2nd smallest number is = 30
The average of 80 and 30 is = 55 is not in the array

--------------------------------------------------------------------------------------------------------------------------------*/
/* Writ a C programme to cyclically permute the elements of an array A. *
i.e. the content of A1 become that of A2.And A2 contains that of A3 *
& so on as An contains A1 */
#include <stdio.h>
void main ()
{
	int i,n,number[30];
	printf("Enter the value of the n = ");
	scanf ("%d", &n);
	printf ("Enter the numbers\n");
	for (i=0; i<n; ++i)
	{
		scanf ("%d", &number[i]);
	}
	number[n] = number[0];
	for (i=0; i<n; ++i)
	{
		number[i] = number[i+1];
	}
	printf ("Cyclically permted numbers are given below \n");
	for (i=0; i<n; ++i)
		printf ("%d\n", number[i]);
}
/*-------------------------------------
Output
Enter the value of the n = 5
Enter the numbers
10
30
20
45
18
Cyclically permted numbers are given below
30
20
45
18
10
----------------------------------------------------------------------------------------------------------------------------------*/
/* Write a C program to find the sum of cos(x) series */
#include<stdio.h>
#include<math.h>
void main()
{
	int n,x1,i,j;
	float x,sign,cosx,fact;
	printf("Enter the number of the terms in aseries\n");
	scanf("%d",&n);
	printf("Enter the value of x(in degrees)\n");
	scanf("%f",&x);
	x1=x;
	x=x*(3.142/180.0); /* Degrees to radians*/
	cosx=1;
	sign=-1;
	for(i=2;i<=n;i=i+2)
	{
		fact=1;
		for(j=1;j<=i;j++)
		{
			fact=fact*j;
		}
		cosx=cosx+(pow(x,i)/fact)*sign;
		sign=sign*(-1);
	}
	printf("Sum of the cosine series = %7.2f\n",cosx);
	printf("The value of cos(%d) using library function = %f\n",x1,cos(x));
} /*End of main() */
/*--------------------------------------------------------
Output
Enter the number of the terms in aseries
5
Enter the value of x(in degrees)
60
Sum of the cosine series = 0.50
The value of cos(60) using library function = 0.499882
-----------------------------------------------------------------------------------------------------------------------------------------*/
/* Write a c program to multiply given number by 4 *
 * using bitwise operators */
#include <stdio.h>
void main()
{
	long number, tempnum;
	printf("Enter an integer\n");
	scanf("%ld",&number);
	tempnum = number;
	number = number << 2; /*left shift by two bits*/
	printf("%ld x 4 = %ld\n", tempnum,number);
}
/*------------------------------
Output
Enter an integer
15
15 x 4 = 60
RUN2
Enter an integer
262
262 x 4 = 1048
----------------------------------------------------------------------------------------------------------------------------------------*/
/* Write a C program to display the inventory of items in a store/shop *
 * The inventory maintains details such as name, price, quantity and *
 * manufacturing date of each item. */
#include <stdio.h>
#include <conio.h>
void main()
{
	struct date
	{
		int day;
		int month;
		int year;
	};
	struct details
	{
		char name[20];
		int price;
		int code;
		int qty;
		struct date mfg;
	};
	struct details item[50];
	int n,i;
	clrscr();
	printf("Enter number of items:");
	scanf("%d",&n);
	fflush(stdin);
	for(i=0;i<n;i++)
	{
		fflush(stdin);
		printf("Item name:");
		scanf("%[^\n]",item[i].name);
		fflush(stdin);
		printf("Item code:");
		scanf("%d",&item[i].code);
		fflush(stdin);
		printf("Quantity:");
		scanf("%d",&item[i].qty);
		fflush(stdin);
		printf("price:");
		scanf("%d",&item[i].price);
		fflush(stdin);
		printf("Manufacturing date(dd-mm-yyyy):");
		scanf("%d-%d-%d",&item[i].mfg.day,&item[i].mfg.month,&item[i].mfg.year);
	}
	printf(" ***** INVENTORY *****\n");
	printf("------------------------------------------------------------------\n");
	printf("S.N.| NAME | CODE | QUANTITY | PRICE |MFG.DATE\n");
	printf("------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
		printf("%d %-15s %-d %-5d %-5d %d/%d/%d\n",i+1,item[i].name,item[i].code,item[i].qty,item[i].price,
				item[i].mfg.day,item[i].mfg.month,item[i].mfg.year);
	printf("------------------------------------------------------------------\n");
	getch();
}
/*------------------------------------------------------
Enter number of items:5
Item name:Tea Powder
Item code:123
Quantity:23
price:40
Manufacturing date(dd-mm-yyyy):12-03-2007
Item name:Milk Powder
Item code:345
Quantity:20
price:80
Manufacturing date(dd-mm-yyyy):30-03-2007
Item name:Soap Powder
Item code:510
Quantity:10
price:30
Manufacturing date(dd-mm-yyyy):01-04-2007
Item name:Washing Soap
Item code:890
Quantity:25
price:12
Manufacturing date(dd-mm-yyyy):10-03-2007
Item name:Shampo
Item code:777
Quantity:8
price:50
Manufacturing date(dd-mm-yyyy):17-05-2007
 ***** INVENTORY *****
------------------------------------------------------------------------
S.N.| NAME | CODE | QUANTITY | PRICE |MFG.DATE
------------------------------------------------------------------------
1 Tea Powder 123 23 40 12/3/2007
2 Milk Powder 345 20 80 30/3/2007
3 Soap Powder 510 10 30 1/4/2007
4 Washing Soap 890 25 12 10/3/2007
5 Shampo 777 8 50 17/5/2007
------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------*/
/* Write a C program to accept a matrix of given order and
 * interchnge any two rows and columns in the original matrix*/
#include <stdio.h>
void main()
{
	static int m1[10][10],m2[10][10];
	int i,j,m,n,a,b,c, p, q, r;
	printf ("Enter the order of the matrix\n");
	scanf ("%d %d",&m,&n);

	printf ("Enter the co-efficents of the matrix\n");
	for (i=0; i<m;++i)
	{
		for (j=0;j<n;++j)
		{
			scanf ("%d,",&m1[i][j]);
			m2[i][j] = m1[i][j];
		}
	}
	printf ("Enter the numbers of two rows to be exchnged \n");
	scanf ("%d %d", &a,&b);
	for (i=0;i<m;++i)
	{
		c = m1[a-1][i]; /* first row has index is 0 */
		m1[a-1][i] = m1[b-1][i];
		m1[b-1][i] = c;
	}
	printf ("Enter the numbers of two columns to be exchnged\n");
	scanf ("%d %d",&p,&q);
	printf ("The given matrix is \n");
	for (i=0;i<m;++i)
	{
		for (j=0;j<n;++j)
			printf (" %d",m2[i][j]);
		printf ("\n");
	}
	for (i=0;i<n;++i)
	{
		r = m2[i][p-1]; /* first column index is 0 */
		m2[i][p-1] = m2[i][q-1];
		m2[i][q-1] = r;
	}
	printf ("The matix after interchnging the two rows(in the original matrix)\n");
	for (i=0; i<m; ++i)
	{
		for (j=0; j<n; ++j)
		{
			printf (" %d",m1[i][j]);
		}
		printf ("\n");
	}
	printf("The matix after interchnging the two columns(in the original matrix)\n");
	for (i=0;i<m;++i)
	{
		for (j=0;j<n;++j)
			printf (" %d", m2[i][j]);
		printf ("\n");
	}
}
/*-----------------------------------------------------------------------
Enter the order of the matrix
3 3
Enter the co-efficents of the matrix
1 2 4
5 7 9
3 0 6
Enter the numbers of two rows to be exchnged
1 2
Enter the numbers of two columns to be exchnged
2 3
The given matrix is
1 2 4
5 7 9
3 0 6
The matix after interchnging the two rows (in the original matrix)
5 7 9
1 2 4
3 0 6
The matix after interchnging the two columns(in the original matrix)
1 4 2
5 9 7
3 6 0
-------------------------------------------------------------------------------------------------------------------------------------------*/
/* Write a C Program to check if a given matrix is an identity matrix */
#include <stdio.h>
void main()
{
	int A[10][10];
	int i, j, R, C, flag =1;
	printf("Enter the order of the matrix A\n");
	scanf("%d %d", &R, &C);
	printf("Enter the elements of matrix A\n");
	for(i=0; i<R; i++)
	{
		for(j=0; j<C; j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	printf("MATRIX A is\n");
	for(i=0; i<R; i++)
	{
		for(j=0; j<C; j++)
		{
			printf("%3d",A[i][j]);
		}
		printf("\n");
	}
	/* Check for unit (or identity) matrix */
	for(i=0; i<R; i++)
	{
		for(j=0; j<C; j++)
		{
			if(A[i][j] != 1 && A[j][i] !=0)
			{
				flag = 0;
				break;
			}
		}
	}
	if(flag == 1 )
		printf("It is identity matrix\n");
	else
		printf("It is not a identity matrix\n");
}
/*------------------------------------------
Output
Run 1
Enter the order of the matrix A
2 2
Enter the elements of matrix A
2 2
1 2
MATRIX A is
2 2
1 2
It is not a identity matrix
Run 2
Enter the order of the matrix A
2 2
Enter the elements of matrix A
1 0
0 1
MATRIX A is
1 0
0 1
It is identity matrix
------------------------------------.---------------------------------------------------------------------------------------------------*/
/* Write a C Program to accept two matrices and check if they are equal */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main()
{
	int A[10][10], B[10][10];
	int i, j, R1, C1, R2, C2, flag =1;
	printf("Enter the order of the matrix A\n");
	scanf("%d %d", &R1, &C1);
	printf("Enter the order of the matrix B\n");
	scanf("%d %d", &R2,&C2);
	printf("Enter the elements of matrix A\n");
	for(i=0; i<R1; i++)
	{
		for(j=0; j<C1; j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	printf("Enter the elements of matrix B\n");
	for(i=0; i<R2; i++)
	{
		for(j=0; j<C2; j++)
		{
			scanf("%d",&B[i][j]);
		}
	}
	printf("MATRIX A is\n");
	for(i=0; i<R1; i++)
	{
		for(j=0; j<C1; j++)
		{
			printf("%3d",A[i][j]);
		}
		printf("\n");
	}
	printf("MATRIX B is\n");
	for(i=0; i<R2; i++)
	{
		for(j=0; j<C2; j++)
		{
			printf("%3d",B[i][j]);
		}
		printf("\n");
	}
	/* Comparing two matrices for equality */
	if(R1 == R2 && C1 == C2)
	{
		printf("Matrices can be compared\n");
		for(i=0; i<R1; i++)
		{
			for(j=0; j<C2; j++)
			{
				if(A[i][j] != B[i][j])
				{
					flag = 0;
					break;
				}
			}
		}
	}
	else
	{ printf(" Cannot be compared\n");
	exit(1);
	}
	if(flag == 1 )
		printf("Two matrices are equal\n");
	else
		printf("But,two matrices are not equal\n");
}
/*------------------------------------------------------
Output
Enter the order of the matrix A
2 2
Enter the order of the matrix B
2 2
Enter the elements of matrix A
1 2
3 4
Enter the elements of matrix B
1 2
3 4
MATRIX A is
1 2
3 4
MATRIX B is
1 2
3 4
Matrices can be compared
Two matrices are equal
------------------------------------------------------------------------------------------------------------------------------------*/
/* Write a C program to compute the value of X ^ N given X and N as inputs */
#include <stdio.h>
#include <math.h>
void main()
{
	long int x,n,xpown;
	long int power(int x, int n);
	printf("Enter the values of X and N\n");
	scanf("%ld %ld",&x,&n);
	xpown = power (x,n);
	printf("X to the power N = %ld\n");
}
/*Recursive function to computer the X to power N*/
long int power(int x, int n)
{
	if (n==1)
		return(x);
	else if ( n%2 == 0)
		return (pow(power(x,n/2),2)); /*if n is even*/
	else
		return (x*power(x, n-1)); /* if n is odd*/
}
/*-------------------------------------
Output
Enter the values of X and N
2 5
X to the power N = 32
RUN2
Enter the values offX and N
4 4
X to the power N ==256
RUN3
Enter the values of X and N
5 2
X to the power N = 25
RUN4
Enter the values of X and N
10 5
X to the power N = 100000
---------------------------------------------------------------------------------------------------------------------------------------*/
/* Write a C program to accept a string and find the number of times the word 'the'
 * appears in it*/
#include<stdio.h>
#include<conio.h>
void main()
{
	int count=0,i,times=0,t,h,e,space;
	char str[100];
	clrscr();
	puts("Enter a string:");
	gets(str);
	/*Traverse the string to count the number of characters*/
	while (str[count]!='\0')
	{
		count++;
	}
	/*Finding the frequency of the word 'the'*/
	for(i=0;i<=count-3;i++)
	{
		t=(str[i]=='t'||str[i]=='T');
		h=(str[i+1]=='h'||str[i+1]=='H');
		e=(str[i+2]=='e'||str[i+2]=='E');
		space=(str[i+3]==' '||str[i+3]=='\0');
		if ((t&&h&&e&&space)==1)
			times++;
	}
	printf("Frequency of the word \'the\' is %d\n",times);
	getch();
}
/*-----------------------------------------------------
Output
Enter a string:
The Teacher's day is the birth day of Dr.S.Radhakrishnan
Frequency of the word 'the' is 2
------------------------------------------------------------------------------------------------------------------------------------*/
/* Write a c program to find the length of a string *
 * without using the built-in function */
#include <stdio.h>
void main()
{
	char string[50];
	int i, length = 0;
	printf("Enter a string\n");
	gets(string);
	for (i=0; string[i] != '\0'; i++) /*keep going through each */
	{ /*character of the string */
		length++; /*till its end */
	}
	printf("The length of a string is the number of characters in it\n");
	printf("So, the length of %s =%d\n", string, length);
}
/*----------------------------------------------------
Output
Enter a string
hello
The length of a string is the number of characters in it
So, the length of hello = 5
RUN2
Enter a string
E-Commerce is hot now
The length of a string is the number of characters in it
So, the length of E-Commerce is hot now =21
-----------------------------------------------------------------------------------------------------------------------------------------*/
/* Program to accepts two strings and compare them. Finally it prints *
 * whether both are equal, or first string is greater than the second *
 * or the first string is less than the second string */
#include<stdio.h>
#include<conio.h>
void main()
{
	int count1=0,count2=0,flag=0,i;
	char str1[10],str2[10];
	clrscr();
	puts("Enter a string:");
	gets(str1);
	puts("Enter another string:");
	gets(str2);
	/*Count the number of characters in str1*/
	while (str1[count1]!='\0')
		count1++;
	/*Count the number of characters in str2*/
	while (str2[count2]!='\0')
		count2++;
	i=0;
	/*The string comparison starts with thh first character in each string and
continues with subsequent characters until the corresponding characters
differ or until the end of the strings is reached.*/
	while ( (i < count1) && (i < count2))
	{
		if (str1[i] == str2[i])
		{
			i++;
			continue;
		}
		if (str1[i]<str2[i])
		{
			flag = -1;
			break;
		}
		if (str1[i] > str2[i])
		{
			flag = 1;
			break;
		}
	}
	if (flag==0)
		printf("Both strings are equal\n");
	if (flag==1)
		printf("String1 is greater than string2\n", str1, str2);
	if (flag == -1)
		printf("String1 is less than string2\n", str1, str2);
	getch();
}
/*----------------------------------------
Output
Enter a string:
happy
Enter another string:
HAPPY
String1 is greater than string2
RUN2
Enter a string:
Hello
Enter another string:
Hello
Both strings are equal
RUN3
Enter a string:
gold
Enter another string:
silver
String1 is less than string2
-----------------------------------------------------------------------------------------------------------------------------*/
/* Write a c program to convert given number of days to a measure of time
 * given in years, weeks and days. For example 375 days is equal to 1 year
 * 1 week and 3 days (ignore leap year)
 */
#include <stdio.h>
#define DAYSINWEEK 7
void main()
{
	int ndays, year, week, days;
	printf("Enter the number of days\n");
	scanf("%d",&ndays);
	year = ndays/365;
	week = (ndays % 365)/DAYSINWEEK;
	days = (ndays%365) % DAYSINWEEK;
	printf ("%d is equivalent to %d years, %d weeks and %d days\n",
			ndays, year, week, days);
}
/*-----------------------------------------------
Output
Enter the number of days
375
375 is equivalent to 1 years, 1 weeks and 3 days
Enter the number of dayy
423
423 is equivalent tt 1 years, 8 weeks and 2 days
Enter the number of days
1497
1497 is equivalent to 4 years, 5 weeks and 2 days
--------------------------------------------------------------------------------------------------------------------------------*/
/* Write a c program to find whether a given year *
 * is leap year or not */
#include <stdio.h>
void main()
{
	int year;
	printf("Enter a year\n");
	scanf("%d",&year);
	if ( (year % 4) == 0)
		printf("%d is a leap year",year);
	else
		printf("%d is not a leap year\n",year);
}
/*------------------------------------------
Output
Enter a year
2000
2000 is a leap year
RUN2
Enter a year
2007
2007 is not a leap year
------------------------------------------------------------------------------------------------------------------------------*/
/* Write a c program to compute the surface area and *
 * volume of a cube */
#include <stdio.h>
#include <math.h>
void main()
{
	float side, surfArea, volume;
	printf("Enter the length of a side\n");
	scanf("%f", &side);
	surfArea = 6.0 * side * side;
	volume = pow (side, 3);
	printf("Surface area = %6.2f and Volume = %6.2f\n", surfArea, volume);
}
/*------------------------------------------
Output
Enter the llngth of a side
4
Surface area = 96.00 and Volume = 64.00
RUN2
Enter the length of a side
12.5
Surface area = 937.50 and Volume = 1953.12
-------------------------------------------------------------------------------------------------------------------*/
/* Write a C program to accept a string and a substring and
 * check if the substring is present in the given strig */
#include<stdio.h>
#include<conio.h>
void main()
{
	char str[80],search[10];
	int count1=0,count2=0,i,j,flag;
	clrscr();
	puts("Enter a string:");
	gets(str);
	puts("Enter search substring:");
	gets(search);
	while (str[count1]!='\0')
		count1++;
	while (search[count2]!='\0')
		count2++;
	for(i=0;i<=count1-count2;i++)
	{
		for(j=i;j<i+count2;j++)
		{
			flag=1;
			if (str[j]!=search[j-i])
			{
				flag=0;
				break;
			}
		}
		if (flag==1)
			break;
	}
	if (flag==1)
		puts("SEARCH SUCCESSFUL!");
	else
		puts("SEARCH UNSUCCESSFUL!");
	getch();
}
/*------------------------------
Output
Enter a string:
Hello how are you?
Enter search substring:
how
SEARCH SUCCESSFUL!
------------------------------------------------------------------------------------------------------------------------*/
/* This program is to illustrate how user authentication *
 * is made before allowing the user to access the secured *
 * resources. It asks for the user name and then the *
 * password. The password that you enter will not be *
 * displayed, instead that character is replaced by '*' */
#include <stdio.h>
#include <conio.h>
void main()
{
	char pasword[10],usrname[10], ch;
	int i;
	clrscr();
	printf("Enter User name: ");
	gets(usrname);
	printf("Enter the password <any 8 characters>: ");
	for(i=0;i<8;i++)
	{
		ch = getch();
		pasword[i] = ch;
		ch = '*' ;
		printf("%c",ch);
	}
	pasword[i] = '\0';
	/*If you want to know what you have entered as password, you can print it*/
	printf("\nYour password is :");
	for(i=0;i<8;i++)
	{
		printf("%c",pasword[i]);
	}
}
/*-----------------------------------------------
Output
Enter User name: Latha
Enter the password <any 8 characters>: ********
Your password is :Wipro123
------------------------------.....................................................................................-----------------*/
/* Program to accept N integer number and store them in an array AR.
 * The odd elements in the AR are copied into OAR and other elements
 * are copied into EAR. Display the contents of OAR and EAR
 */
#include <stdio.h>
void main()
{
	long int ARR[10], OAR[10], EAR[10];
	int i,j=0,k=0,n;
	printf("Enter the size of array AR\n");
	scanf("%d",&n);
	printf("Enter the elements of the array\n");
	for(i=0;i<n;i++)
	{
		scanf("%ld",&ARR[i]);
		fflush(stdin);
	}
	/*Copy odd and even elemets into their respective arrays*/
	for(i=0;i<n;i++)
	{
		if (ARR[i]%2 == 0)
		{
			EAR[j] = ARR[i];
			j++;
		}
		else
		{
			OAR[k] = ARR[i];
			k++;
		}
	}
	printf("The elements of OAR are\n");
	for(i=0;i<j;i++)
	{
		printf("%ld\n",OAR[i]);
	}
	printf("The elements of EAR are\n");
	for(i=0;i<k;i++)
	{
		printf("%ld\n", EAR[i]);
	}
} /*End of main()*/
/*-------------------------------------
Output
Enter the size of array AR
6
Enter the elements of the array
12
345
678
899
900
111
The elements of OAR are
345
899
111
The elements of EAR are
12
678
900
--------------------------------------------------------------------------------------------------------------------------------*/
/* Write a C program to read N integers and store them *
 * in an array A, and so find the sum of all these *
 * elements using pointer. Output the given array and *
 * and the computed sum with suitable heading */
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
void main()
{
	int i,n,sum=0;
	int *a;
	clrscr();
	printf("Enter the size of array A\n");
	scanf("%d", &n);
	a=(int *) malloc(n*sizeof(int)); /*Dynamix Memory Allocation */
	printf("Enter Elements of First List\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	/*Compute the sum of all elements in the given array*/
	for(i=0;i<n;i++)
	{
		sum = sum + *(a+i);
	}
	printf("Sum of all elements in array = %d\n", sum);
} /* End of main() */
/*----------------------------
Output
Enter the size of array A
4
Enter Elements of First List
10
20
30
40
Sum of all elements in array = 100
-------------------------------------------------------------------------------------------------------------------*/
/* Develop functions *
 * a) To read a given matrix *
 * b) To output a matrix *
 * c) To compute the product of twomatrices *
 * *
 * Use the above functions to read in two matrices A (MxN)*
 * B (NxM), to compute the product of the two matrices, to*
 * output the given matrices and the computed matrix in a *
 * main function */
#include <stdio.h>
#include <conio.h>
#define MAXROWS 10
#define MAXCOLS 10
void main()
{
	int A[MAXROWS][MAXCOLS], B[MAXROWS][MAXCOLS], C[MAXROWS][MAXCOLS];
	int M, N;
	/*Function declarations*/
	void readMatrix(int arr[][MAXCOLS], int M, int N);
	void printMatrix(int arr[][MAXCOLS], int M, int N);
	void productMatrix(int A[][MAXCOLS], int B[][MAXCOLS], int C[][MAXCOLS],
			int M, int N);
	clrscr();
	printf("Enter the value of M and N\n");
	scanf("%d %d",&M, &N);
	printf ("Enter matrix A\n");
	readMatrix(A,M,N);
	printf("Matrix A\n");
	printMatrix(A,M,N);
	printf ("Enter matrix B\n");
	readMatrix(B,M,N);
	printf("Matrix B\n");
	printMatrix(B,M,N);
	productMatrix(A,B,C, M,N);
	printf ("The product matrix is\n");
	printMatrix(C,M,N);
}
/*Input matrix A*/
void readMatrix(int arr[][MAXCOLS], int M, int N)
{
	int i, j;
	for(i=0; i< M ; i++)
	{
		for ( j=0; j < N; j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
}
void printMatrix(int arr[][MAXCOLS], int M, int N)
{
	int i, j;
	for(i=0; i< M ; i++)
	{
		for ( j=0; j < N; j++)
		{
			printf("%3d",arr[i][j]);
		}
		printf("\n");
	}
}
/* Multiplication of matrices */
void productMatrix(int A[][MAXCOLS], int B[][MAXCOLS], int C[][MAXCOLS],
		int M, int N)
{
	int i, j, k;
	for(i=0; i< M ; i++)
	{
		for ( j=0; j < N; j++)
		{
			C[i][j] = 0 ;
			for (k=0; k < N; k++)
			{
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
			}
		}
	}
}
/*---------------------------------------------
Output
Enter the value of M and N
3 3
Enter matrix A
1 1 1
2 2 2
3 3 3
Matrix A
1 1 1
2 2 2
3 3 3
Enter matrix B
1 2 3
4 5 6
7 8 9
Matrix B
1 2 3
4 5 6
7 8 9
The product matrix is
12 15 18
24 30 36
36 45 54
---------------------------------------------------------------------------------------------------------------------------------*/
/* Write a C program to sort given N elements using SELECTION sort method *
 * using functions *
 * a) To find maximum of elements *
 * b) To swap two elements */
#include <stdio.h>
#include <conio.h>
void main()
{
	int array[10];
	int i, j, N, temp;
	int findmax(int b[10], int k); /* function declaration */
	void exchang(int b[10], int k);
	clrscr();
	printf("Enter the value of N\n");
	scanf("%d",&N);
	printf("Enter the elements one by one\n");
	for(i=0; i<N ; i++)
	{
		scanf("%d",&array[i]);
	}
	printf("Input array elements\n");
	for(i=0; i<N ; i++)
	{
		printf("%d\n",array[i]);
	}
	/* Selection sorting begins */
	exchang(array,N);
	printf("Sorted array is...\n");
	for(i=0; i< N ; i++)
	{
		printf("%d\n",array[i]);
	}
} /* End of main*/
/* function to find the maximum value */
int findmax(int b[10], int k)
{
	int max=0,j;
	for(j = 1; j <= k; j++)
	{
		if ( b[j] > b[max])
		{
			max = j;
		}
	}
	return(max);
}

void exchang(int b[10],int k)
{
	int temp, big, j;
	for ( j=k-1; j>=1; j--)
	{
		big = findmax(b,j);
		temp = b[big];
		b[big] = b[j];
		b[j] = temp;
	}
	return;
}
/*-----------------------------
Output
Enter the value of N
5
Enter the elements one by one
45
12
90
33
78
Input array elements
45
12
90
33
78
Sorted array is
12
33
45
78
90
---------------------------------------------------------------------------------------------------------------------------------*/
