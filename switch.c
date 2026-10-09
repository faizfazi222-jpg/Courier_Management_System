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