#include <stdio.h>
struct Parcel
{
  int parcel_id;
  char sendername[50];
  char receivername[50];
  char phone[20];
  char destination[50];
  float weight;
  int deliverytype;
  int status;
};
void addparcel(struct Parcel parcels[],int *parcelcount)
{
  if(*parcelcount >= 100)
  {
    printf("Finally Parcel Storage is Full");
    return;
  }
  int new_id;

  printf("\n------- Add New Parcel -------\n");
  printf("Enter Parcel ID:");
  scanf("%d",&new_id);

  for(int i = 0 ; i < *parcelcount ; i++)
  {
    if(parcels[i].parcel_id == new_id)
    {
      printf("This Parcel ID Already Exist");
      return;
    }
  }
  parcels[*parcelcount].parcel_id = new_id;

  printf("Enter Sender Name:");
  scanf("%49[^\n]",parcels[*parcelcount].sendername);

  printf("Enter Receiver Name:");
  scanf("%49[^\n]",parcels[*parcelcount].receivername);

  printf("Enter Phone Number:");
  scanf("%19s",parcels[*parcelcount].phone);

  printf("Enter Destination:");
  scanf("%49[^\n]",parcels[*parcelcount].destination);

  printf("Enter Weight in kg:");
  scanf("%f",&parcels[*parcelcount].weight);

  if(parcels[*parcelcount].deliverytype != 1 && parcels[*parcelcount].deliverytype !=2){
    printf("Invalid Delivery Type");
    return;
  }

  parcels[*parcelcount].status = 1;
  (*parcelcount)++;
  printf("Parcel Successfully Added !");
}
void displayAllParcels(struct Parcel parcels[], int parcelcount)
{
    int i;

    printf("\n========== ALL PARCELS ==========\n");

    if (parcelcount == 0)
    {
        printf("No parcels available.\n");
    }
    else
    {
        for (i = 0; i < parcelcount; i++)
        {
            printf("\nParcel Number: %d\n", i + 1);
            printf("Parcel ID: %d\n", parcels[i].parcel_id);
            printf("Sender Name: %s\n", parcels[i].sendername);
            printf("Receiver Name: %s\n", parcels[i].receivername);
            printf("Phone Number: %s\n", parcels[i].phone);
            printf("Destination: %s\n", parcels[i].destination);
            printf("Weight: %.2f kg\n", parcels[i].weight);

            if (parcels[i].deliverytype == 1)
                printf("Delivery Type is Normal\n");
            else if (parcels[i].deliverytype == 2)
                printf("Delivery Type is Express\n");

            if (parcels[i].status == 1)
                printf("Status: Booked\n");

            printf("-------------------------------\n");
        }
    }
}
int main()
{
  int choice;

  struct Parcel parcels[100];
  int parcelcount = 0;

  do
  {
    
  printf("====================================\n");
  printf(" COURIER MANAGEMENT SYSTEM\n");
  printf("====================================\n");

  printf("\n1) Add New Parcel\n");
  printf("\n2) Track Parcel\n");
  printf("\n3) Search Parcel\n");
  printf("\n4) Update Parcel Status\n");
  printf("\n5) Cancel Parcel\n");
  printf("\n6) Display All Parcels\n");
  printf("\n7) Calculate Delivery Charges\n");
  printf("\n8) Generate Bill\n");
  printf("\n9) Exit\n");

  printf("\nEnter your choice:");
  scanf("%d",&choice);

  switch(choice)
  {
    case 1 : printf("Add new parcel selected\n");
    break;

    case 2 : printf("Track parcel selected\n");
    break;

    case 3 : printf("Search parcel selected\n");
    break;

    case 4 : printf("Update parcel selected\n");
    break;

    case 5 : printf("Cancel parcel selected\n");
    break;

    case 6 : printf("Display all parcels selected\n");
    break;

    case 7 : printf("Calculate delivery charges selected\n");
    break;

    case 8 : printf("Generate bill selected\n");
    break;

    case 9 : printf("Thank you for using system !\n");
    break;

    default : printf("Invalid choice.");

  }

  } while (choice != 9);


  return 0 ;
}