#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "Class.h"

void main(void)
{
	u8 Choice=0 ;
	
	ST_Class* FirstStudent= NULL;
	
	printf("**************************************************************************************\n");
	printf("**************************************************************************************\n");
	printf("********************************                      ********************************\n");
	printf("********************************   WELCOME TO CLASS   ********************************\n");
	printf("********************************                      ********************************\n");
	printf("**************************************************************************************\n");
	printf("**************************************************************************************\n");
						
	while (Choice!='x')
	{	
		printf("\n");
		printf("->  Please Enter 'a' To Add A New Student  			     					\n");
		printf("->  Please Enter 'p' To Print The Students List 							\n");
		printf("->  Please Enter 'd' To Delete A Student From The List						\n");
		printf("->  Please Enter 'e' To edit A Student Data 								\n");
		printf("->  Please Enter 's' To Sort The Student List According To The GPA 			\n");
		printf("->  Please Enter 'x' To Exit 									 			\n");

		printf("Enter Your Choice: ");
		scanf(" %c",&Choice);
		
		switch (Choice)
		{
			case 'a': 	Add_NewStudent (&FirstStudent); 				break;
			
			case 'p': 	Print_StudentDataBase (&FirstStudent); 			break;
			
			case 'd': 	Delete_StudentData (&FirstStudent); 			break;
			
			case 's': 	Sort_StudentData (&FirstStudent) ;				break;
			
			case 'e': 	Edit_StudentData (&FirstStudent); 				break;
			
			case 'x': 									 				break;
			
			default: 	printf("Wrong Choice, Please Try Again\n");		break;
		}
	}
	
	
	
}