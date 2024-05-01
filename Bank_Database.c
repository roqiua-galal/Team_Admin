#include"Bank_Database.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int counter;
extern Client arr[3];
void Create_New_Customer(void)
{
    Client New_Customer;
    printf("please enter the name of the customer number %i:",counter+1);
    fflush(stdin);
    gets(New_Customer.name);
label:
    printf("please enter the cash of the customer number %i:",counter+1);
    scanf("%lf",&(New_Customer.cash) );
    if((New_Customer.cash)<0)
    {
        printf("Please Enter Correct Number\n");
        goto label;
    }
    printf("please enter the type of the customer number %i (debit or credit):",counter+1);
    fflush(stdin);
    gets(New_Customer.type);
    printf("please enter the id of the customer number %i:",counter+1);
    scanf("%i",&(New_Customer.id) );
    arr[counter]=(New_Customer);
    counter++;
}
void Edit_Customer_Data(void)
{
    int ID;
    int index = -1;
    printf("Please Enter ID of Customer You want to change his data :");
    scanf("%i",&ID);
    for(int i=0; i<=counter; i++)
    {
        if((arr[i].id)==ID)
        {
            index=i;
            printf("Please Enter New Data\n");
            printf("please enter the name");
            fflush(stdin);
            gets(arr[i].name);
label:
            printf("please enter the cash of the customer:");
            scanf("%lf",&(arr[i].cash) );
            if((arr[i].cash)<0)
            {
                printf("Please Enter Correct Number\n");
                goto label;
            }
            printf("please enter the type of the customer (debit or credit):");
            fflush(stdin);
            gets(arr[i].type);
            printf("please enter the id of the customer");
            scanf("%i",&(arr[i].id) );

        }

    }
    if(index==-1)
    {
        printf("\n please enter valid id\n");

    }
}

void Print_Customer_Data(void)
{
    int ID;
    int index =-1;
    printf("Please Enter ID of Customer You want to print his data :");
    scanf("%i",&ID);
    for(int i=0; i<=counter; i++)
    {
        if((arr[i].id)==ID)
        {
            index==i;
            printf(".................................\n\n");
            printf("Customer name is %s\n",arr[i].name);
            printf("Customer Cach is %lf\n",arr[i].cash);
            printf("Customer Type is %s\n",arr[i].type);
            printf("Customer Id is %i\n",arr[i].id);
            printf(".................................\n\n");
            break;
        }

    }
    if(index==-1)
    {
        printf("\nplease enter valid id\n");

    }
}
void Delete_Customer_Data(void)
{
    int ID;
    int index =-1;
    printf("Please Enter ID of Customer You want to delete his data :");
    scanf("%i",&ID);
    for(int i=0; i<=counter; i++)
    {
        if((arr[i].id)==ID)
        {
            index=i;
            if(index==counter)
            {
                arr[counter].cash=-1;
                arr[counter].id=-1;
                strcpy(arr[counter].name,"-1");
                strcpy(arr[counter].type,"-1");
                counter--;
            }
            else if(index<=counter-1)
            {
                for(int i=index; i<=counter-1; i++)
                {
                    arr[i]=arr[i+1];
                }
                arr[counter].cash=-1;
                arr[counter].id=-1;
                strcpy(arr[counter].name,"-1");
                strcpy(arr[counter].type,"-1");
                counter--;
            }
            else
            {
                break;
            }
        }

    }
    if(index==-1)
    {
        printf("\nplease enter valid id\n");

    }

}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void transfer_cash(void)
{
    int id1,id2,i,j;
    int Index1=-1;
    int Index2 =-1;
    double req_cash;
    printf("Please Enter Id of client Who want to transfer cash: ");
    scanf("%i",&id1);
    printf("Please Enter Id of client Who want to recieve cash: ");
    scanf("%i",&id2);
jumb:
    printf("Please Enter Cash value you want to transfer: ");
    scanf("%lf",&req_cash);
    for(i=0; i<=counter; i++)
    {
        if((arr[i].id)==id1)
        {
            Index1=i;
            if((arr[i].cash)<req_cash)
            {
                printf("You don't have enough cash to complete this operation\n");
                goto jumb;
            }
            else
            {
                for(j=0; j<=counter; j++)
                {

                    if((arr[j].id)==id2)
                    {
                        Index2=j;
                        arr[j].cash += req_cash;
                        arr[i].cash -= req_cash;
                        printf("\nSuccessful operation\n");
                    }
                }

            }
        }
    }
    if((Index1==-1)||(Index2==-1))
    {
        printf("\nplease enter valid id\n");

    }
}
void Exit_Program(void)
{
    printf("\n...........End..............\n");
}
