#ifndef STUDENTS_H_INCLUDED
#define STUDENTS_H_INCLUDED
#include "Objects.h"
#include "windows.h"
#include <string.h>

/***********VOID FUNKCIJE***********/
void adminMenu();
void sMenu();
void sKviz();
void showList();
void deleteStudent();
void editStudent();
void newStudent();
void Login(char *mail,char *pass);
int pBroj;
int pBroj2;
void sPredmet();
void sProfil();
/***********STRUKTURE***********/
struct Student
{
    int  StudentId;
    char StudentIme[30];
    char StudentPrezime[30];
    int godine;
    char email[50];
    char password[50];
};
    struct Student student;
    struct Student students[50];
    char adminMail[30]="admin@gmail.com";
    char adminPass[20]="admin123";

struct Predmet
{
    char ime[50];
    char pit1[60];
    char odg1[60];

    char pit2[60];
    char odg2[60];

    char pit3[60];
    char odg3[60];

    char pit4[60];
    char odg4[30];

    char pit5[60];
    char odg5[60];

    int bodovi1,bodovi2,bodovi3,bodovi4,bodovi5;
    int ukbod;
};
    struct Predmet predmeti;
/***********KREIRANJE PITANJA***********/
void sPredmet()
{
    FILE *p;
    p=fopen("Predmeti.dat","ab+");
    if(p==NULL)
        {
        printf("Fajl nije otvoren!");
        return;
    }
    unosString("Unesite naziv predmeta: ", predmeti.ime);
    fflush(stdin);
    unosString("Unesite prvo pitanje: ", predmeti.pit1);
    fflush(stdin);
    unosString("Unesite odgovor na prvo pitanje: ", predmeti.odg1);
    fflush(stdin);
    unosString("Unesite drugo pitanje: ", predmeti.pit2);
    fflush(stdin);
    unosString("Unesite odgovor na drugo pitanje: ", predmeti.odg2);
    fflush(stdin);
    unosString("Unesite trece pitanje: ", predmeti.pit3);
    fflush(stdin);
    unosString("Unesite odgovor na trece pitanje: ", predmeti.odg3);
    fflush(stdin);
    unosString("Unesite cetvrto pitanje: ", predmeti.pit4);
    fflush(stdin);
    unosString("Unesite odgovor na cetvrto pitanje: ", predmeti.odg4);
    fflush(stdin);
    unosString("Unesite peto pitanje: ", predmeti.pit5);
    fflush(stdin);
    unosString("Unesite odgovor na peto pitanje: ", predmeti.odg5);
    fflush(stdin);
    fwrite(&predmeti,sizeof(struct Predmet),1,p);
    fclose(p);
    printf("\nKviz uspjesno kreiran!\n");

}
/***********KVIZ***********/
void sKviz()
{
    FILE *p;
    p=fopen("Predmeti.dat","r+");
    printf("\n*************************");
    while(fread(&predmeti,sizeof(struct Predmet),1,p))
    {
        char odgg1[60];
        char odgg2[60];
        char odgg3[60];
        char odgg4[60];
        char odgg5[60];
        printf("\nPredmet: %s",predmeti.ime);
        printf("\nPitanje 1: %s",predmeti.pit1);
        unosString("Unesite odgovor na prvo pitanje: ", odgg1);
        fflush(stdin);
        if(!strcmp(odgg1,predmeti.odg1))
        {
            printf("Vas odgovor je tacan vi ste dobili 10 bodova!");
            predmeti.bodovi1 += 10;
        }
        else
        {
            printf("Vas odgovor nije tacan!");
            predmeti.bodovi1 = 0;
        }
        printf("\nPitanje 2: %s",predmeti.pit2);
        unosString("Unesite odgovor na drugo pitanje: ", odgg2);
        fflush(stdin);
        if(!strcmp(odgg2,predmeti.odg2))
        {
            printf("Vas odgovor je tacan vi ste dobili 10 bodova!");
            predmeti.bodovi2 += 10;
        }
        else
        {
            printf("Vas odgovor nije tacan!");
            predmeti.bodovi2 = 0;
        }
        printf("\nPitanje 3: %s",predmeti.pit3);
        unosString("Unesite odgovor na trece pitanje: ", odgg3);
        fflush(stdin);
        if(!strcmp(odgg3,predmeti.odg3))
        {
            printf("Vas odgovor je tacan vi ste dobili 10 bodova!");
            predmeti.bodovi3 += 10;
        }
        else
        {
            printf("Vas odgovor nije tacan!");
            predmeti.bodovi3 = 0;
        }
        printf("\nPitanje 4: %s",predmeti.pit4);
        unosString("Unesite odgovor na cetvrto pitanje: ", odgg4);
        fflush(stdin);
        if(!strcmp(odgg4,predmeti.odg4))
        {
            printf("Vas odgovor je tacan vi ste dobili 10 bodova!");
            predmeti.bodovi4 += 10;
        }
        else
        {
            printf("Vas odgovor nije tacan!");
            predmeti.bodovi4 = 0;
        }
        printf("\nPitanje 5: %s",predmeti.pit5);
        unosString("Unesite odgovor na peto pitanje: ", odgg5);
        fflush(stdin);
        if(!strcmp(odgg5,predmeti.odg5))
        {
            printf("Vas odgovor je tacan vi ste dobili 10 bodova!");
            predmeti.bodovi5 += 10;
        }
        else
        {
            printf("Vas odgovor nije tacan!");
            predmeti.bodovi5 = 0;
        }
        predmeti.ukbod = predmeti.bodovi1 + predmeti.bodovi2 + predmeti.bodovi3 + predmeti.bodovi4 + predmeti.bodovi5;
        printf("\nOsvojeni broj bodova: %d", predmeti.ukbod);
        printf("\n*************************");
    }
    fclose(p);
}
/***********BRISANJE PROFILA***********/
void deleteStudent()
{
    FILE *p;
    p=fopen("Studenti.dat","r+");
    int i=0;
    while(fread(&student,sizeof(struct Student),1,p))
    {
    students[i]=student;
    i++;
    }
    fclose(p);
    char StudentEmail[30];
    unosString("Unesite e-mail: ",StudentEmail);
    char StudentPassword[20];
    unosString("Unesite lozinku: ",StudentPassword);
    for(int j=0;j<i;j++)
    {
        if(!strcmp(StudentEmail,students[j].email) && !strcmp(StudentPassword,students[j].password))
        {
            for(int k=j;k<i-1;k++)
            {
                students[k]=students[k+1];

            }
            printf("\nProfil uspjesno izbrisan iz baze podataka!\n");
        }
    }
    p=fopen("Studenti.dat","wb+");
    for(int j=0;j<i-1;j++)
        {
        fwrite(&students[j],sizeof(struct Student),1,p);
    }
    fclose(p);
}
/***********EDITOVANJE PROFILA***********/
void editStudent()
{
    FILE *p;
    p=fopen("Studenti.dat","r+");
    int i=0;
    while(fread(&student,sizeof(struct Student),1,p))
    {
    students[i]=student;
    i++;
    }
    fclose(p);
    int ID;
    int unos;
    unosInt("Unesite ID studenta za edit: ",&ID);
    for(int j=0;j<=i;j++)
    {
        if(ID==students[j].StudentId)
        {
            do
            {
            printf("\nEdit\n1.)First name\n2.)Last name\n3.)Email\n4.)ID\n5.)Age\n6.)Password\n7.)Exit");
            unos = 0;
            unosInt("Unesite Vas izbor: ",&unos);
            if(unos == 1)
            {
                unosString("Novo ime: ",students[j].StudentIme);
                printf("Nove promjene izvrsene!");
            }
            if(unos == 2)
            {
                unosString("Novo prezime: ",students[j].StudentPrezime);
                printf("Nove promjene izvrsene!");
            }
            if(unos == 3)
            {
                unosString("Novi e-mail: ",students[j].email);
                printf("Nove promjene izvrsene!");
            }
            if(unos == 4)
            {
                unosInt("Novi ID: ",&students[j].StudentId);
                printf("Nove promjene izvrsene!");
            }
            if(unos == 5)
            {
                unosInt("Novi broj godina:",&students[j].godine);
                printf("Nove promjene izvrsene!");
            }
            if(unos == 6)
            {
                unosString("Novi password:",students[j].password);
                printf("Nove promjene izvrsene!");
            }

        }
        while(unos!=7);
    }
    }
    p=fopen("Studenti.dat","wb+");
    for(int j=0;j<i;j++)
        {
        fwrite(&students[j],sizeof(struct Student),1,p);
    }
    fclose(p);
}
/***********PRIKAZ LISTE STUDENATA***********/
void showList()
{
    FILE *p;
    p=fopen("Studenti.dat","r+");
    printf("\n*************************");
    while(fread(&student,sizeof(struct Student),1,p))
    {
        printf("\nIme: %s",student.StudentIme);
        printf("\nPrezime: %s",student.StudentPrezime);
        printf("\nGodine: %d",student.godine);
        printf("\nStudent ID: %d",student.StudentId);
        printf("\nEmail: %s",student.email);
        printf("\nPassword: %s",student.password);
        printf("\n*************************");
    }
    fclose(p);
}
/***********PRIKAZ LICNOG PROFILA***********/
void sProfil()
{
        printf("\n***********PROFIL**************");
        printf("\nID: %d",students[pBroj].StudentId);
        printf("\nIme: %s",students[pBroj].StudentIme);
        printf("\nPrezime: %s",students[pBroj].StudentPrezime);
        printf("\nGodine: %d",students[pBroj].godine);
        printf("\nEmail: %s",students[pBroj].email);
        printf("\nPassword: %s",students[pBroj].password);
        printf("\nPredmet: %s", predmeti.ime);
        printf("\nBodovi: %d", predmeti.ukbod);
        printf("\n*******************************");
}
/***********KREIRANJE NOVOG STUDENTA***********/
void newStudent()
{
    FILE *p;
    p=fopen("Studenti.dat","ab+");
    if(p==NULL)
        {
        printf("Fajl nije otvoren!");
        return;
    }
    unosString("Unesite ime: ", student.StudentIme);
    unosString("Unesite prezime: ", student.StudentPrezime);
    unosInt("Unesite godine: ", &student.godine);
    unosString("Unesite email: ", student.email);
    unosString("Unesite password: ", student.password);
    unosInt("Unesite ID: ", &student.StudentId);
    fwrite(&student,sizeof(struct Student),1,p);
    fclose(p);
    printf("\nNalog uspjesno kreiran!\n");
}
/***********LOGIN FORMA***********/
void Login(char *mail,char *pass){

    FILE *p;
    p=fopen("Studenti.dat","r+");
    int i=0;
    while(fread(&student,sizeof(struct Student),1,p))
    {
    students[i]=student;
    i++;
    }

    fclose(p);
    pBroj2=i;
    for(int j=0;j<=i;j++)
        {
        if(!strcmp(mail,adminMail) && !strcmp(pass,adminPass))
        {
            printf("\n*****Welcome Admin*****\n");
            adminMenu();
            break;
        }
        else if(!strcmp(mail,students[j].email)&&!strcmp(pass,students[j].password))
        {
            printf("\n*****Welcome Student*****\n");
            pBroj=j;
            sMenu();
        }
    }
}

#endif // STUDENTS_H_INCLUDED
