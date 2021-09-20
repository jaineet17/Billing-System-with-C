#include<stdio.h>
#include<stdlib.h>
float sum=0;

// Structure that represents node
struct node{
    int index;
    float price;
    struct node *spNext;
};

struct node1{
    int CustomerNo;
    float Amount;
    struct node1 *spNext1;
};


struct node *spStart=NULL,*spEnd=NULL,*spTemp=NULL,*spNew=NULL,*spPrev=NULL;
struct node1 *spStart1=NULL,*spEnd1=NULL,*spTemp1=NULL,*spNew1=NULL,*spPrev1=NULL;
int iNodeCount=0;
int iNodeCount1=0;
int p=1,j=1,r=1;

/*void getIndex()
{
    int q=1;
    spTemp=spStart;
    while(spTemp->spNext!= NULL)
    {
        spTemp->index=q;
        q++;
    }
}*/

// Function to create a new node
void createNode()
{
    float iItem;
    spNew=(struct node*)malloc(sizeof(struct node));
    if(spNew==NULL)
        printf("\nMemory allocation failed !");
    else
    {
        printf("\nEnter Price For Items: ");
        scanf("%f",&iItem);
        sum=sum+iItem;
        //getIndex();
        spNew->index=j++;
        spNew->price=iItem;
        spNew->spNext=NULL;
        //getIndex();
    }
}

void createNode1(float a)
{

    spNew1=(struct node1*)malloc(sizeof(struct node1));
    if(spNew1==NULL)
        printf("\nMemory allocation failed !");
    else
    {
        spNew1->Amount=a;
        spNew1->CustomerNo=p++;
        spNew1->spNext1=NULL;
    }
}



// Function to insert node at End
void listInsert()
{

    createNode();
    if(spStart==NULL){
        spStart=spNew;
        //spEnd=spNew;
        iNodeCount=1;
    }
    else{

        spTemp=spStart;
        while(spTemp->spNext != NULL)
            {
                spTemp=spTemp->spNext;
            }

        spTemp->spNext=spNew;
        //spEnd=spNew;
        iNodeCount=iNodeCount+1;
    }
}

void listInsert1(float b)
{

    createNode1(b);
    if(spStart1==NULL){
        spStart1=spNew1;
        //spEnd=spNew;
        iNodeCount1=1;
    }
    else{

        spTemp1=spStart1;
        while(spTemp1->spNext1 != NULL)
            {
                spTemp1=spTemp1->spNext1;
            }

        spTemp1->spNext1=spNew1;
        //spEnd=spNew;
        iNodeCount1=iNodeCount1+1;
    }
}

// Function to call delete function as per choice of user
void listDelete(){
    int iChoice;
    traversal();
    printf("\nEnter Your Choice...\n1. DELETE ITEAM AT START\n2. DELETE ITEM AT END\n3. DELETE ITEM IN BETWEEN\n");
    scanf("%d",&iChoice);
    switch(iChoice){
        case 1: listDeleteStart();
                break;
        case 2: listDeleteEnd();
                break;
        case 3: listDeleteBetween();
                break;
        default: printf("\nInvalid Choice");
    }
}

// Function to delete node at Start
void listDeleteStart(){

    if(spStart==NULL){
        printf("\nList does not exist !\n");
        iNodeCount=0;
    }
    else{


        sum=sum-spStart->price;
        spTemp = spStart->spNext;
        free(spStart);
        //getIndex();
        spStart=spTemp;
        iNodeCount=iNodeCount-1;
    }
    //getIndex();
}

// Function to delete node in between
void listDeleteBetween(){
    int iPosition,iCount=1;
    printf("\nEnter Index for Delete : ");
    scanf("%d",&iPosition);
    if(iPosition>iNodeCount||iPosition<0){
        printf("\nInvalid Position !\n");
    }
    else{
        spTemp=spStart;
        if(iPosition==1){
            listDeleteStart();
        }
        else{
            while(iCount!=iPosition){
                spPrev=spTemp;
                spTemp=spTemp->spNext;
                iCount++;
            }

            sum=sum-spTemp->price;


            //printf("\current node : %d",spTemp->iData);
            //printf("\previous node : %d",spPrev->iData);
            //check form here
            spPrev->spNext=spTemp->spNext;
            spTemp->index=iPosition;

            //spTemp->spNext->spNext=spPrev->spNext;
            //free(spTemp);
            //spStart=spTemp;
            //iNodeCount=iNodeCount-1;

        }

    }
    //getIndex();
}

// Function to delete node at End
void listDeleteEnd(){
    if(spStart==NULL){
        printf("\nList does not exist !\n");
        iNodeCount=0;
    }
    else{

        spTemp=spStart;

        while(spTemp->spNext!=NULL){
            spPrev=spTemp;

            spTemp=spTemp->spNext;
        }

        spPrev->spNext=NULL;
        spTemp->index=j--;
        sum=sum-spTemp->price;
        //printf("\last node : %d",spTemp->iData);
        //printf("\second last node : %d",spPrev->iData);
        if(spTemp==spStart){
            spStart=NULL;
        }
        free(spTemp);
        iNodeCount=iNodeCount-1;

    }
    //getIndex();
}

void record()
{
     if(spStart1==NULL){
        printf("\nList does not exist !\n");
    }
    else{

        spTemp1=spStart1;
        printf("\n---------CUSTOMER RECORD: %d---------\n",iNodeCount1);
        printf("CUSTOMER NO. \t AMOUNT\n");

        while(spTemp1!= NULL){
            printf(" %d \t%f\n",spTemp1->CustomerNo,spTemp1->Amount);
            spTemp1=spTemp1->spNext1;
        }


    }

}

void traversal()
{
    if(spStart==NULL){
        printf("\nList does not exist !\n");
    }
    else{
                spTemp=spStart;
    printf("Index \t Price\n");

             while(spTemp!= NULL){
            printf("\n %d \t%f\n",spTemp->index,spTemp->price);
            spTemp=spTemp->spNext;
            }
    }

}
void finalbill(){

    if(spStart==NULL){
        printf("\nList does not exist !\n");
    }
    else{

        spTemp=spStart;
        printf("\n Customer No. is: %d\n",r);
        r++;
        //printf("%d",r);
        printf("\n---------TOTAL ITEMS: %d---------\n",iNodeCount);
        printf("Index \t Price\n");

        while(spTemp!= NULL){
            printf(" %d \t%f\n",spTemp->index,spTemp->price);
            spTemp=spTemp->spNext;
            }
            spStart=spTemp;


        printf("\nTotal Amount= %f\n",sum);
        printf("------------BILL PAID-----------\n");
        listInsert1(sum);
        sum=0;
        j=1;
        main();

    }
}


void main(){
int iChoice,iTemp,iTemp2;
printf("\n--------- Wel Come to Billing System: ---------\n");
printf("Customer No. is: %d\n",r);

    while(1){


        printf("\nEnter your choice from below...\n0. EXIT\n1. FOR INSERT ITEMS\n2. FOR DELETE ITEMS\n3. FOR FINAL BILL\n4. FOR RECORD");
        scanf("%d",&iChoice);
        switch(iChoice){
            case 0: exit(0);
                    break;
            case 1: listInsert();
                    break;
            case 2: listDelete();
                    break;
            case 3: finalbill();
                    break;
            case 4: record();
                    break;
            default: printf("\ninvalid choice!");
        }
    }
}
