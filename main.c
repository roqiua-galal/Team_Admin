#include <stdio.h>
#include <stdlib.h>
#include"Bank_Database.h"
Client arr[3];
char choice;
int counter;
int i;
int main()
{
    while(1)
    {
        printf(".......................................\n");
        printf("please select one of the following options :\n\n1-create anew customer (press 1 to select this option)\n2-edit customer (press 2 to select this option )\n3-delete customer (press 3 to select this option)\n4-print customer data (press 4 to select this option)\n5-cash transfer from customer to another (press 5 t select this option)\n6-exit (press 6 to select this option)\n\nplease enter your choice:");

        fflush(stdin);
        scanf("%c",&choice);
        printf(".......................................\n");
        switch(choice)
        {
        case '1':
            if(counter>=3)
            {
                printf("\n\nthe maximum number of customers is 3 so you can't add anymore\n");
                break;
            }
            Create_New_Customer();
            break;
        case '2':

            Edit_Customer_Data();
            break;
        case '3':
            Delete_Customer_Data();
            break;
        case '4':

            Print_Customer_Data();
            break;
        case '5':

            transfer_cash();
            break;
        case '6':

            exit(0);

        default:
            printf("wrong choice\n\n");

        }




    }

    return 0;
}
