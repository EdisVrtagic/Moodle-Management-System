#include <stdio.h>
#include <string.h>
#include "Students.h"
#include "Objects.h"

/***********VOID FUNKCIJE***********/
void unosInt();
void adminMenu();
void sMenu();
void sKviz();
void sProfil();
void showList();
void deleteStudent();
void editStudent();
void newStudent();
void Login(char *mail,char *pass);
/***********LOGIN***********/
int main()
{
    int unos=0;
    do
    {
    printf("\n**********MOODLE***************\n");
    printf("1.) Login\n2.) Exit\n");
    unosInt("Unesite Vas izbor: ",&unos);
    if(unos == 1)
    {
        char email[50];
        char pass[50];
        unosString("Unesite email: ",email);
        unosString("Unesite password: ",pass);
        Login(email,pass);
    }
    unos=0;
    }
    while(unos!=2);
    printf("\nOdjavili ste se!");
}
