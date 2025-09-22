///////////////////////////////////////////////////////////////////////
//
//Header file Inclusion
//
///////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////
//
// User defined Macros
//
///////////////////////////////////////////////////////////////////////

# define MAXFILESIZE 100

# define MAXINODE 5

# define READ 1
# define WRITE 2
# define EXECUTE 4

# define REGULARFILE 1
# define SPEACIALFILE 2

# define START 0
# define CURRENT 1
# define END 2

///////////////////////////////////////////////////////////////////////
//
// Structure name : BootBlock
// Description :    Holds information to boot the operating system
//
///////////////////////////////////////////////////////////////////////


struct BootBlock
{
    char Information[100];
};

///////////////////////////////////////////////////////////////////////
//
// Structure name : SuperBlock
// Description :    Holds information about the file system
//
///////////////////////////////////////////////////////////////////////

struct SuperBlock
{
    int TotalInodes;
    int FreeInods;
};

///////////////////////////////////////////////////////////////////////
//
// Structure name : Inode
// Description :    Holds information about the file 
//
///////////////////////////////////////////////////////////////////////

typedef struct Inode
{
    char FileName[50];
    int InodeNumber;
    int FileSize;
    int ActualFileSize;
    int FileType;
    int ReferenceCount;
    int LinkCount;
    int Permission;
    char *Buffer;
    struct Inode *next;
}INODE, *PINODE, **PPINODE;

///////////////////////////////////////////////////////////////////////
//
// Structure name : FileTable
// Description :    Holds information about opened file
//
///////////////////////////////////////////////////////////////////////

typedef struct FileTable
{
    int Readoffset;
    int WriteOffset;
    int Count;
    int Mode;
    PINODE ptrinode;
}FILETABLE, *PFILETABLE;

///////////////////////////////////////////////////////////////////////
//
// Structure name : UAREA
// Description :    Holds information about the process
//
///////////////////////////////////////////////////////////////////////

struct UAREA
{
    char ProcessName[50];
    PFILETABLE UFDT[MAXINODE];
};

///////////////////////////////////////////////////////////////////////
//
// 
// Global variables or objects used in projects
//
///////////////////////////////////////////////////////////////////////

BootBlock bootobj;
SuperBlock superobj;
PINODE head = NULL;
UAREA uareaobj;

///////////////////////////////////////////////////////////////////////
//
// Function name :  InitialiseUAREA
//  Description  :  it is used to initialize the contents of UAREA
//  Author       :   Yash sunil Pagar
//  Date         :   10/08/2025
// 
///////////////////////////////////////////////////////////////////////

void InitialiseUAREA()
{
    strcpy(uareaobj.ProcessName,"Myexe");

    int i = 1;

    while(i < MAXINODE)
    {
        uareaobj.UFDT[i] = NULL;
        i++;
    }
    cout<<"Marvellous CVFS : UAREA initialized Sucessfully\n";
}


///////////////////////////////////////////////////////////////////////
//
// Function name :  InitialsuperBlock
//  Description  :  it is used to initialize the contents of super block
//  Author       :   Yash sunil Pagar
//  Date         :   10/08/2025
// 
///////////////////////////////////////////////////////////////////////

void InitialiseSuperBlock()
{
    superobj.TotalInodes = MAXINODE;
    superobj.FreeInods   = MAXINODE;

    cout<<"Marvellous CVFS : SuperBlock initialized Sucessfully\n";

}

///////////////////////////////////////////////////////////////////////
//
// Function name :  CreateDILB
//  Description  :  it is used to create Linked List of Inodes
//  Author       :   Yash sunil Pagar
//  Date         :   10/08/2025
// 
///////////////////////////////////////////////////////////////////////

void CreateDILB()
{
    int i = 1;
    PINODE newn = NULL;
    PINODE temp = head;

    while(i <= MAXINODE)
    {
        newn = new INODE;
        newn->InodeNumber = i;
        newn->FileSize = 0;
        newn->ActualFileSize = 0;
        newn->LinkCount = 0;
        newn->Permission = 0;
        newn->Buffer = NULL;
        newn->next = NULL;

        if(temp == NULL)
        {
            head = newn;
            temp = head;
        }
        else
        {
            temp->next = newn;
            temp = temp->next;
        }

        i++;
    }
    
    cout<<"Marvellous CVFS : DILB Created Sucessfully\n";
}


///////////////////////////////////////////////////////////////////////
//
// Function name :  StartOxillaryDataInitialisation
//  Description  :  it is used to initialize the auxillary data
//  Author       :   Yash sunil Pagar
//  Date         :   10/08/2025
// 
///////////////////////////////////////////////////////////////////////




void StartOxillaryDataInitialisation()
{

   strcpy(bootobj.Information,"Boot Process of Operating System done");

    cout<<bootobj.Information<<"\n";

    InitialiseSuperBlock();

    CreateDILB();

    InitialiseUAREA();

    cout<<"Marvellous CVFS : Oxillary Data initialized Sucessfully\n";

}


///////////////////////////////////////////////////////////////////////
//
// Entry point function of project (main)
//
///////////////////////////////////////////////////////////////////////

int main()
{
    StartOxillaryDataInitialisation();



    return 0;
}