#ifndef BANK_DATABASE_H
#define BANK_DATABASE_H
typedef struct clients
{
    char name[40];
    double cash;
    char type[7]; //Debit or Credit
    int id;

}Client;
void Create_New_Customer(void);
void Edit_Customer_Data(void);
void Print_Customer_Data(void);
void Delete_Customer_Data(void);
void transfer_cash(void);
void Exit_Program(void);
#endif // BANK_DATABASE_H
