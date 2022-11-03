#ifndef OBJECTS_H_INCLUDED
#define OBJECTS_H_INCLUDED
#include <string.h>
#include "Students.h"
#include "windows.h"

/***********VOID FUNKCIJE***********/
void unosInt();
void adminMenu();
void sMenu();
void sKviz();
void showList();
void deleteStudent();
void editStudent();
void newStudent();
void sPredmet();
void sProfil();
/***********UNOS STRING***********/
void unosString(char *sUnos,char *unos)
{
printf("\n%s",sUnos);
scanf("%s",unos);
}
/***********UNOS BROJA***********/
void unosInt(char *sUnos,int *a)
{
printf("\n%s",sUnos);
int broj;
scanf("%d",&broj);
*a=broj;
}
/***********ADMIN MENU***********/
void adminMenu()
{
int unos=0;
do
{
    printf("\n*************************");
    printf("\n1.) New student\n2.) Show student list\n3.) Delete student\n4.) Edit student\n5.) Create question\n6.) Log out");
    printf("\n*************************\n");
    unosInt("Unesite Vas izbor: ",&unos);
    if(unos == 1)
    newStudent();
    else if(unos == 2)
    showList();
    else if(unos == 3)
    deleteStudent();
    else if(unos == 4)
    editStudent();
    else if(unos == 5)
    sPredmet();
    else if(unos == 6)
    return;
}
while(unos!=6);
return;
}
/***********STUDENT MENU***********/
void sMenu()
{
int unos;
do
{
    printf("\n*************************");
    printf("\n1.) Kviz \n2.) Profil \n3.) Log out");
    printf("\n*************************\n");
    unosInt("Unesite Vas izbor: ",&unos);
    if(unos == 1)
    sKviz();
    else if(unos == 2)
    sProfil();
    else if(unos == 3)
    continue;
    else printf("Pogresan izbor!");
    unos = 0;
}
while(unos!=3);
return;
}
#endif // OBJECTS_H_INCLUDED
