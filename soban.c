void trackParcel(struct Parcel parcels[], int parcelcount)
{
    int search_id;
    int found = 0;

    printf("\n------ Track Parcel ------\n");
    printf("Enter Parcel ID: ");
    scanf("%d", &search_id);

    for(int i = 0; i < parcelcount; i++)
    {
        if(parcels[i].parcel_id == search_id)
        {
            found = 1;

            printf("\nParcel Found!\n");
            printf("Parcel ID: %d\n", parcels[i].parcel_id);

            printf("Current Delivery Status: ");

            if(parcels[i].status == 1)
                printf("Booked\n");
            else if(parcels[i].status == 2)
                printf("In Transit\n");
            else if(parcels[i].status == 3)
                printf("At Destination\n");
            else if(parcels[i].status == 4)
                printf("Delivered\n");
            else if(parcels[i].status == 5)
                printf("Cancelled\n");

            break;
        }
    }

    if(found == 0)
    {
        printf("\nParcel Not Found!\n");
    }
}
void cancelParcel(struct Parcel parcels[], int parcelcount)
{
    int search_id;
    int found = 0;
    char confirm;

    printf("\n------ Cancel Parcel ------\n");
    printf("Enter Parcel ID: ");
    scanf("%d", &search_id);

    for(int i = 0; i < parcelcount; i++)
    {
        if(parcels[i].parcel_id == search_id)
        {
            found = 1;

            printf("\nParcel Found!\n");
            printf("Parcel ID: %d\n", parcels[i].parcel_id);

            printf("Current Status: ");

            if(parcels[i].status == 1)
                printf("Booked\n");
            else if(parcels[i].status == 2)
                printf("In Transit\n");
            else if(parcels[i].status == 3)
                printf("At Destination\n");
            else if(parcels[i].status == 4)
                printf("Delivered\n");
            else if(parcels[i].status == 5)
                printf("Cancelled\n");

            if(parcels[i].status == 5)
            {
                printf("\nThis Parcel is Already Cancelled!\n");
                break;
            }

            if(parcels[i].status == 4)
            {
                printf("\nDelivered Parcel Cannot Be Cancelled!\n");
                break;
            }

            printf("\nAre you sure you want to cancel this parcel (Y/N): ");
            scanf(" %c", &confirm);

            if(confirm == 'Y' || confirm == 'y')
            {
                parcels[i].status = 5;
                printf("\nParcel Successfully Cancelled!\n");
            }
            else if(confirm == 'N' || confirm == 'n')
            {
                printf("\nParcel Cancellation Aborted!\n");
            }
            else
            {
                printf("\nInvalid Confirmation!\n");
            }

            break;
        }
    }

    if(found == 0)
    {
        printf("\nParcel Not Found!\n");
    }
}

