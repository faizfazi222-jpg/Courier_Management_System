scanF("%d", &choice);
switch (choice) {
    case 1:
        printf("\n1) Add New Parcel\n");
        printf("Enter ParcelID\n");
        scanF("%d", &id);
        printf("Enter Sender Name\n");
        scanF("%s", sendername);
        printf("Enter Receiver Name\n");
        scanF("%s", receivername);
        printf("Enter Phone Number\n");
        scanF("%d", &number);
        printf("Enter Destination\n");
        scanF("%s", destination);
        printf("Enter Weight\n");
        scanF("%d", &weight);
        printf("Enter Delivery type\n");
        printf("1-Normal\n2-Express\n");
        scanF("%d", &deliverytype);
        printf("----PARCEL ADDED SUCCESSFULLY----\n");
        printf("PARCEL ID: %d\n", id);
        printf("SENDER NAME: %s\n", sendername);
        printf("RECEIVER NAME: %s\n", receivername);
        printf("PHONE NUMBER: %d\n", number);
        printf("DESTINATION: %s\n", destination);
        printf("WEIGHT: %d\n", weight);
        if (deliverytype == 1) {
            printf("DELIVERY TYPE: Normal\n");
        } else if (deliverytype == 2) {
            printf("DELIVERY TYPE: Express\n");
        } else {
            printf("Invalid delivery type\n");
        }

        break;
    case 2:
        // Handle choice 2
        break;
    default:
        printf("Invalid choice\n");
}


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
            printf("\nParcel ID %d Status: ", parcels[i].parcel_id);
            switch(parcels[i].status) {
                case 1: printf("Booked\n"); break;
                case 2: printf("In Transit\n"); break;
                case 3: printf("At Destination\n"); break;
                case 4: printf("Delivered\n"); break;
                case 5: printf("Cancelled\n"); break;
            }
            found = 1;
            break;
        }
    }
    if(found == 0) printf("\nParcel Not Found!\n");
}



void cancelParcel(struct Parcel parcels[], int parcelcount)
{
    int search_id;
    int found = 0;

    printf("\n------ Cancel Parcel ------\n");
    printf("Enter Parcel ID to cancel: ");
    scanf("%d", &search_id);

    for(int i = 0; i < parcelcount; i++)
    {
        if(parcels[i].parcel_id == search_id)
        {
            if(parcels[i].status == 4) {
                printf("\nCannot cancel a delivered parcel.\n");
            } else if(parcels[i].status == 5) {
                printf("\nParcel is already cancelled.\n");
            } else {
                parcels[i].status = 5;
                printf("\nParcel successfully cancelled.\n");
            }
            found = 1;
            break;
        }
    }
    if(found == 0) printf("\nParcel Not Found!\n");
}



float getDeliveryCost(struct Parcel p)
{
    // Base formula: 50 flat rate + 10 per kg. Express doubles the cost.
    float base_cost = 50.0 + (10.0 * p.weight);
    if(p.deliverytype == 2) {
        return base_cost * 2.0; // Express multiplier
    }
    return base_cost;
}

void calculateDeliveryCharges(struct Parcel parcels[], int parcelcount)
{
    int search_id, found = 0;
    
    printf("\n------ Calculate Charges ------\n");
    printf("Enter Parcel ID: ");
    scanf("%d", &search_id);

    for(int i = 0; i < parcelcount; i++)
    {
        if(parcels[i].parcel_id == search_id)
        {
            float cost = getDeliveryCost(parcels[i]);
            printf("\nDelivery charges for Parcel ID %d: $%.2f\n", parcels[i].parcel_id, cost);
            found = 1;
            break;
        }
    }
    if(found == 0) printf("\nParcel Not Found!\n");
}

void generateBill(struct Parcel parcels[], int parcelcount)
{
    int search_id, found = 0;
    
    printf("\n------ Generate Bill ------\n");
    printf("Enter Parcel ID: ");
    scanf("%d", &search_id);

    for(int i = 0; i < parcelcount; i++)
    {
        if(parcels[i].parcel_id == search_id)
        {
            printf("\n====================================");
            printf("\n            COURIER BILL            ");
            printf("\n====================================\n");
            printf("Parcel ID   : %d\n", parcels[i].parcel_id);
            printf("Sender      : %s\n", parcels[i].sendername);
            printf("Receiver    : %s\n", parcels[i].receivername);
            printf("Destination : %s\n", parcels[i].destination);
            printf("Weight      : %.2f kg\n", parcels[i].weight);
            printf("Type        : %s\n", parcels[i].deliverytype == 1 ? "Normal" : "Express");
            printf("------------------------------------\n");
            printf("TOTAL AMOUNT: $%.2f\n", getDeliveryCost(parcels[i]));
            printf("====================================\n");
            found = 1;
            break;
        }
    }
    if(found == 0) printf("\nParcel Not Found!\n");
}


int main()
{
    int choice;
    struct Parcel parcels[100];
    int parcelcount = 0;

    do
    {
        printf("\n====================================\n");
        printf("        COURIER MANAGEMENT SYSTEM\n");
        printf("====================================\n");

        printf("1) Add New Parcel\n");
        printf("2) Track Parcel\n");
        printf("3) Search Parcel\n");
        printf("4) Update Parcel Status\n");
        printf("5) Cancel Parcel\n");
        printf("6) Display All Parcels\n");
        printf("7) Calculate Delivery Charges\n");
        printf("8) Generate Bill\n");
        printf("9) Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addparcel(parcels, &parcelcount);
                break;
            case 2:
                trackParcel(parcels, parcelcount);
                break;
            case 3:
                searchparcel(parcels, parcelcount);
                break;
            case 4:
                updateParcelStatus(parcels, parcelcount);
                break;
            case 5:
                cancelParcel(parcels, parcelcount);
                break;
            case 6:
                displayAllParcels(parcels, parcelcount);
                break;
            case 7:
                calculateDeliveryCharges(parcels, parcelcount);
                break;
            case 8:
                generateBill(parcels, parcelcount);
                break;
            case 9:
                printf("Thank you for using the system!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice != 9);

    return 0;
}

