#ifndef _CLASS_H_
#define _CLASS_H_

#define VALID 		1
#define NOTVALID 	2
#define MaxNameSize 15
#define MinNameSize 7
#define MaxIDNum 500
#define MaxGPA 4


typedef struct Class
{
	u8 Name[MaxNameSize];
	u32 ID;
	f32 GPA;
	u32 PhoneNumber;
	struct Class* Next;
	
}ST_Class ;

typedef enum Error
{
	OK, 
	WRONG_NAME, 
	WRONG_ID, 
	WRONG_PHONE, 
	WRONG_GPA
}EN_Error;


void Add_NewStudent (ST_Class** Head);
EN_Error Add_StudentName (ST_Class* PtrNewStudent);
EN_Error Add_StudentID (ST_Class* PtrNewStudent);
EN_Error Add_StudentGPA (ST_Class* PtrNewStudent);
EN_Error Add_StudentPhoneNumber (ST_Class* PtrNewStudent);


void Print_StudentDataBase (ST_Class** Head);


void Delete_StudentData (ST_Class** Head);


void Edit_StudentData (ST_Class** Head);

void Sort_StudentData (ST_Class** Head) ;




#endif