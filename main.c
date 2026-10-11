#include <stdio.h>
int main()
{
  int choice;

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


  return 0 ;
}