#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "Class.h"
/*************************************************************************************************************************		
**************************************************************************************************************************
**************************************************************************************************************************
** Function Name  : Add_NewStudent   																					**
** Input Argument : pointer to pointer																					**
** Return Type    : void 																								**
** Description    : This function add a new student to the list 														**
**					and it takes a pointer to pointer as an input 														**
**					argument which is the head of the linked list. 														**
**************************************************************************************************************************
**************************************************************************************************************************
*************************************************************************************************************************/				
void Add_NewStudent (ST_Class** Head)
{
	EN_Error Class_Error ;  //Creating a variable with an enum type to save the error if it is occured
	
	ST_Class* NewStudent = (ST_Class*) malloc(sizeof(ST_Class)); //Creating new node which is new student
	
	do{
		Class_Error= Add_StudentName (NewStudent); //Asking the user to enter the student name
		}while(Class_Error!=OK);

	do{
		Class_Error= Add_StudentID (NewStudent); //Asking the user to enter the ID
		}while(Class_Error!=OK);
		
	do{
		Class_Error= Add_StudentGPA (NewStudent); //Asking the user to enter the GPA
		}while(Class_Error!=OK);
	
	do{
		Class_Error= Add_StudentPhoneNumber (NewStudent); //Asking the user to enter the Phone Number
		}while(Class_Error!=OK);
	
	NewStudent -> Next = *Head ;   
	
	*Head=NewStudent;
	
	printf("\n** The Student Data Added Successfully **\n");
	printf("-------------------------------------------------------------\n");
	printf("-------------------------------------------------------------\n");
	
	}	
/*************************************************************************************************************************		
**************************************************************************************************************************
**************************************************************************************************************************
** Function Name  : Print_StudentDataBase   																			**
** Input Argument : pointer to pointer																					**
** Return Type    : void 																								**
** Description    : This function print the data base of the list  														**
**					and it takes a pointer to pointer as an input 														**
**					argument which is the head of the linked list. 														**
**************************************************************************************************************************
**************************************************************************************************************************
*************************************************************************************************************************/
void Print_StudentDataBase (ST_Class** Head)
{
	ST_Class* TempPtr=*Head; //Creating temp pointer intially points to the head node
	u8 Counter=0 ;
	while (TempPtr!=NULL)
	{
		printf("Student Name: ");
		for (Counter=0 ;Counter<MaxNameSize;Counter++)
		{
			printf("%c",TempPtr->Name[Counter]);
		}
		
		printf("\nStudent ID: %d\n",TempPtr->ID);
		printf("Student GPA: %0.2f\n",TempPtr->GPA);
		printf("Student Phone Number: %d\n",TempPtr->PhoneNumber);
		printf("-----------------------------------------\n");
		
		TempPtr=TempPtr->Next ;
	}
}
/*************************************************************************************************************************		
**************************************************************************************************************************
**************************************************************************************************************************
** Function Name  : Delete_StudentData   																				**
** Input Argument : pointer to pointer																					**
** Return Type    : void 																								**
** Description    : This function asks the user to enter a student 														**
**					ID delete to this student from the data base     													**
**					and it takes a pointer to pointer as an input 														**
**					argument which is the head of the linked list. 														**
**************************************************************************************************************************
**************************************************************************************************************************
*************************************************************************************************************************/
void Delete_StudentData (ST_Class** Head)
{
	u8 StuedentID;
	ST_Class *TempPtr = *Head; //Creating a temporary pointer intialy points to the head
	ST_Class *Prev ; 
	
	printf("Please Enter The Student ID you want to Delete\n");
	
	scanf(" %d",&StuedentID); //Asking the user the student id to delete it 
	
	if (TempPtr != NULL && TempPtr->ID == StuedentID) //In case of the head has the ID that will be deleted
	{
		*Head = TempPtr->Next ; //The head will points to the next node
		free(TempPtr); // delete the head node
		printf("The Student With ID %d Deleted Successfully\n",TempPtr->ID);
	}
	else
	{
		while (TempPtr != NULL && TempPtr->ID != StuedentID) //Searching for the student ID through the list
		{
			Prev=TempPtr ; 
			TempPtr=TempPtr->Next;
		}
		if (TempPtr == NULL) //In case of the Id is not exist it will print "THIS ID IS NOT EXIST"
		{
			printf("THIS ID IS NOT EXIST\n");
		}
		else  //If the Id exist
		{
			Prev->Next = TempPtr->Next ; //The prev will points to the next node
			free(TempPtr); // the node which has the ID will be deleted
			printf("The Student With ID %d Deleted Successfully\n",TempPtr->ID);
		}
	}
}
/*************************************************************************************************************************		
**************************************************************************************************************************
**************************************************************************************************************************
** Function Name  : Edit_StudentData   				    																**
** Input Argument : pointer to pointer																					**
** Return Type    : void 																								**
** Description    : This function asks the user to enter a student 														**
**					ID to edit GPA, Phone Number or ID of this student   												**
**					and it takes a pointer to pointer as an input 														**
**					argument which is the head of the linked list. 														**
**************************************************************************************************************************
**************************************************************************************************************************
*************************************************************************************************************************/
void Edit_StudentData (ST_Class** Head)
{
	u8 StuedentID;
	u8 EditInput;
	ST_Class *TempPtr = *Head; //Creating a temporary pointer intialy points to the head
	ST_Class *Prev ;
	
	printf("Please Enter The Student ID you want to Edit\n"); //Asking the user the student id to edit it 
	scanf("%d",&StuedentID);
	
	printf("To Edit Student ID Press 1\n");
	printf("To Edit Student GPA Press 2\n");
	printf("To Edit Student Phone Number Press 3\n");
	printf("Enter Your Choice: ");
	

	
	if (TempPtr != NULL && TempPtr->ID == StuedentID) //In case of the head has the ID that will be edited
	{
		scanf(" %d",&EditInput);
		switch (EditInput)
		{
			case 1: Add_StudentID(TempPtr); 
					printf("The Student ID Changed Successfully\n");
					break;
			
			case 2: Add_StudentGPA(TempPtr);
					printf("The Student GPA Changed Successfully\n");
					break;
			
			case 3: Add_StudentPhoneNumber (TempPtr);
					printf("The Student Phone Number Changed To Successfully\n");
					break;
			
			default: printf("Wrong Choice\n"); break ;
		}
		
		
	}
	
	else 
	{
		while (TempPtr != NULL && TempPtr->ID != StuedentID) //Searching for the student ID through the list
		{
			Prev=TempPtr ;
			TempPtr=TempPtr->Next;
		}
		if (TempPtr== NULL) //In case of the Id is not exist it will print "THIS ID IS NOT EXIST"
		{
			printf("NOT EXIST\n");
		}
		else //If the Id exist the user will be asked to choose the data that needed to be edit
		{
			scanf(" %d",&EditInput);
			switch (EditInput)
			{
				case 1: Add_StudentID(TempPtr); 
					printf("The Student ID Changed Successfully\n");
					break;
			
				case 2: Add_StudentGPA(TempPtr);
						printf("The Student GPA Changed Successfully\n");
						break;
				
				case 3: Add_StudentPhoneNumber (TempPtr);
						printf("The Student Phone Number Changed Successfully\n");
						break;
			
				default: printf("Wrong Choice\n"); break ;
			
			}
			
		}
	}
}
/*************************************************************************************************************************		
**************************************************************************************************************************
**************************************************************************************************************************
** Function Name  : Sort_StudentData   				    																**
** Input Argument : pointer to pointer																					**
** Return Type    : void 																								**
** Description    : This function sorts the  student list according to													**
**					the highest GPA value by  the bubble sort algorthim   									        	**
**					and it takes a pointer to pointer as an input 														**
**					argument which is the head of the linked list. 														**
**************************************************************************************************************************
**************************************************************************************************************************
*************************************************************************************************************************/	
void Sort_StudentData (ST_Class** Head)
{
	ST_Class * Current = *Head;

	ST_Class* ptrNext = Current->Next ;
	
	ST_Class* TempNode = (ST_Class*) malloc(sizeof(ST_Class));
	
	for(Current=*Head ; Current !=NULL ; Current=Current->Next)
	{
		for(ptrNext=Current->Next; ptrNext!=NULL; ptrNext=ptrNext->Next)
		{
			if(Current->GPA < ptrNext->GPA)
			{
				strcpy(TempNode ->Name , Current-> Name );
				TempNode ->ID = Current-> ID ;
				TempNode ->GPA = Current-> GPA ;
				TempNode ->PhoneNumber = Current-> PhoneNumber ;
				
				strcpy(Current->Name, ptrNext->Name );
				Current->ID   = ptrNext->ID ;
				Current->GPA  = ptrNext->GPA ;
				Current->PhoneNumber  = ptrNext->PhoneNumber;
				
				strcpy(ptrNext->Name , TempNode->Name);
				ptrNext->ID = TempNode->ID ;
				ptrNext->GPA = TempNode->GPA ;
				ptrNext->PhoneNumber = TempNode->PhoneNumber ;
			}
		}
	}
	printf("** The Students Data Sorted Successfully **\n");
}

/*************************************************************************************************************************		
**************************************************************************************************************************
**************************************************************************************************************************
** Function Name  : Add_StudentName   				    																**
** Input Argument : Pointer to struct																					**
** Return Type    : Enum Variable																						**
** Description    : This function asks the user to enter the student name												**
**					and validate it by checking if the name has letters only     							     	  	**
**					and it takes a pointer to struct as an input 														**
**					argument. 																							**
**************************************************************************************************************************
**************************************************************************************************************************
*************************************************************************************************************************/		
EN_Error Add_StudentName (ST_Class* PtrNewStudent)
{
	u8 TempStudentName[MaxNameSize]; //Temp array to save the student name 
	u8 NameSize=0;
	u8 NameValdiation=0;
	u8 Counter=0;
	
	printf("\nPlease Enter Student Name: "); //asking the user to enter the student name
	 scanf(" %[^\n]s", TempStudentName);
	
	NameSize=strlen(TempStudentName); //Calculating array size to validate the name size 

	
	if (NameSize>=MinNameSize && NameSize<=MaxNameSize)
	{
			for (Counter=0; Counter<NameSize ;Counter++)
		{
			/*Checking for the name format that has only letters */
			if ((TempStudentName[Counter]>='a' && TempStudentName[Counter] <= 'z') ||
				(TempStudentName[Counter]>='A' && TempStudentName[Counter] <= 'Z') ||	
				(TempStudentName[Counter] == ' '))    
			{
						
			}
			else 
			{
				NameValdiation=NOTVALID;
			}
		
		}
	}
	else 
	{
		printf("\nWrong name size, Please enter from 10 to 15 letters and try again\n");
		return WRONG_NAME;
	}
	
	if (NameValdiation==NOTVALID)
	{
		printf("\nWrong name format, Please try again\n");
		return WRONG_NAME;
	}
	
	else 
	{
		for (Counter=0 ; Counter<MaxNameSize ; Counter++)
		{
			PtrNewStudent->Name[Counter]=TempStudentName[Counter]; //Saving the name after the vallidation proccess into the main array
		}
		return OK;
	}
}
/*************************************************************************************************************************		
**************************************************************************************************************************
**************************************************************************************************************************
** Function Name  : Add_StudentID   				    																**
** Input Argument : Pointer to struct																					**
** Return Type    : Enum Variable																						**
** Description    : This function asks the user to enter the student 													**
**					ID and validate it by checking if the ID is bigger 													**
**					than the max ID setted or not.    							     	  								**
**					and it takes a pointer to struct as an input 														**
**					argument. 																							**
**************************************************************************************************************************
**************************************************************************************************************************
*************************************************************************************************************************/	
EN_Error Add_StudentID (ST_Class* PtrNewStudent)
{
	u32 Input_ID= 0;
	printf("Please Enter Student ID: ");
	scanf("%d",&Input_ID);

	
	if (Input_ID < MaxIDNum)
	{
		PtrNewStudent -> ID = Input_ID;
		return OK;
		
	}
	else 
	{
		printf("Wrong ID\n");
		return WRONG_ID;
	}
	
}
/*************************************************************************************************************************		
**************************************************************************************************************************
**************************************************************************************************************************
** Function Name  : Add_StudentGPA   				    																**
** Input Argument : Pointer to struct																					**
** Return Type    : Enum Variable																						**
** Description    : This function asks the user to enter the student 													**
**					GPA and validate it by checking if the GPA is bigger 												**
**					than the max GPA which is 4 or not.    							     	  							**
**					and it takes a pointer to struct as an input 														**
**					argument. 									 														**
**************************************************************************************************************************
**************************************************************************************************************************
*************************************************************************************************************************/
EN_Error Add_StudentGPA (ST_Class* PtrNewStudent)
{
	f32 Input_GPA= 0;
	printf("Please Enter Student GPA: ");
	scanf("%f",&Input_GPA);

	if (Input_GPA <= MaxGPA)
	{
		PtrNewStudent -> GPA = Input_GPA;
		return OK;
		
	}
	else 
	{
		printf("Wrong GPA\n");
		return WRONG_GPA;
	}
}
/*************************************************************************************************************************		
**************************************************************************************************************************
**************************************************************************************************************************
** Function Name  : Add_StudentPhoneNumber   				    														**
** Input Argument : Pointer to struct																					**
** Return Type    : Enum Variable																						**
** Description    : This function asks the user to enter the student 													**
**					Phone Number 																						**
**					and it takes a pointer to struct as an input 														**
**					argument              						 														**
**************************************************************************************************************************
**************************************************************************************************************************
*************************************************************************************************************************/
EN_Error Add_StudentPhoneNumber(ST_Class* PtrNewStudent)
{
	u32 Input_PhoneNumber= 0;
	printf("Please Enter Student Phone Number: ");
	scanf(" %d",&Input_PhoneNumber);
	
	
	PtrNewStudent -> PhoneNumber = Input_PhoneNumber;
	return OK;	
}