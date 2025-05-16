#include <stdio.h>

#define OrderSize 100


int quantity[OrderSize];
int hour[OrderSize];
int minute[OrderSize];
int am_pm[OrderSize];
int serveHour[OrderSize];
int serveMinute[OrderSize];
int serve_am_pm[OrderSize];


int totalOrders = 0;

void Welcome_Message() {
    printf("==============================================\n");
    printf("|      RESTAURANT ORDER MANAGEMENT SYSTEM     |\n");
    printf("==============================================\n");
    printf("| Welcome to the Restaurant Order Management System!\n");
    printf("| -> Developed by: Department of CSE\n");
    printf("| -> Semester: Spring 2025\n");
    printf("|\n");
    printf("| This system allows you to:\n");
    printf("| - Register new orders\n");
    printf("| - Remove existing orders\n");
    printf("| - Display all orders\n");
    printf("| - Search and update times\n");
    printf("| - Calculate time taken to serve each order\n");
    printf("==============================================\n");
    printf("\nPress Enter to start the system...");
    getchar();
}


int menu() {
    int choice;

    printf("===================================\n");
    printf("\n--- Restaurant Management System ---\n");
    printf("===================================\n");
    printf("1. Register New Order\n");
    printf("2. Remove Order\n");
    printf("3. Display All Orders\n");
    printf("4. Search by Order Number\n");
    printf("5. Update Serve or Order Time\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}


int Register_New_Order() {
    if (totalOrders < OrderSize) {
        printf("===================================\n");
        printf("\n--- Register New Order ---\n");
        printf("===================================\n");

        printf("Enter Quantity of Food Items: ");
        scanf("%d", &quantity[totalOrders]);

        printf("Enter Hour: ");
        scanf("%d", &hour[totalOrders]);

        printf("Enter Minute: ");
        scanf("%d", &minute[totalOrders]);

        printf("Enter AM or PM (0 for AM, 1 for PM): ");
        scanf("%d", &am_pm[totalOrders]); 

        printf("Enter Serve Hour: ");
        scanf("%d", &serveHour[totalOrders]);

        printf("Enter Serve Minute: ");
        scanf("%d", &serveMinute[totalOrders]);

        printf("Enter AM or PM for Serve (0 for AM, 1 for PM): ");
        scanf("%d", &serve_am_pm[totalOrders]);

        printf("Order Registered Successfully!\n\n");

      
        totalOrders++;
    } else {
        printf("Order limit reached! Cannot register more orders.\n");
    }

    return 0;
}

int Remove_Order() {

    int orderNum;

    if (totalOrders == 0) {
        printf("No orders to remove.\n");
    }

    printf("Enter the order number to remove (1 to %d): ", totalOrders);
    scanf("%d", &orderNum);

    if (orderNum < 1 || orderNum > totalOrders) {
        printf("not a valid number(has to be between 1 and %d)\n", totalOrders);
    }


for (int i = 0; i < totalOrders ; i++) {
    quantity[i] = quantity[i + 1];
    hour[i] = hour[i + 1];
    minute[i] = minute[i + 1];
    am_pm[i] = am_pm[i + 1];
    serveHour[i] = serveHour[i + 1];
    serveMinute[i] = serveMinute[i + 1];
    serve_am_pm[i] = serve_am_pm[i + 1];
}
       printf("Order %d hsa been removed.",orderNum);
totalOrders--;

    return 0;
}

int Calculate_Time_Taken(int index) {
        int orderTimeInMinutes = (hour[index] % 12) * 60 + minute[index];
    if (am_pm[index] == 1) {
        orderTimeInMinutes += 12 * 60;
    }

    int serveTimeInMinutes = (serveHour[index] % 12) * 60 + serveMinute[index];
    if (serve_am_pm[index] == 1) {
        serveTimeInMinutes += 12 * 60;
    }

    int diff= serveTimeInMinutes - orderTimeInMinutes;
    if (diff < 0) {
        diff += 24 * 60; //adding 24 hours so the order is placed for the next day and not today
    }
    return diff;
}

int Display_All_Orders() {
    if (totalOrders == 0) {
        printf("No orders to display.\n");
        return 0;
    }

    printf("===================================\n");
    printf("\n--- All Orders ---\n");
    printf("===================================\n");

    printf("-------------------------------------------------------------------------------\n");
    printf("| Slot | Order No | Quantity | Order Time | Serve Time | Time to Serve (min) |\n");
    printf("-------------------------------------------------------------------------------\n");

    for (int i = 0; i < totalOrders; i++) {
        int diffMin = Calculate_Time_Taken(i);
        printf("| %4d | %8d | %8d |  %02d:%02d %s  |  %02d:%02d %s  | %18d |\n",i + 1,i + 1,quantity[i],hour[i], minute[i], am_pm[i] == 0 ? "AM" : "PM",
        serveHour[i], serveMinute[i], serve_am_pm[i] == 0 ? "AM" : "PM",diffMin);
    }
    printf("-------------------------------------------------------------------------------\n");

    return 0;
}

int Search_Order() {
    int orderNum;
    printf("===================================\n");
    printf("\n--- Search Order ---\n");
    printf("===================================\n");

    if (totalOrders == 0) {
        printf("No orders to search.\n");
        return 0;
    }

    printf("Enter Order Number: ");
    scanf("%d", &orderNum);

    if (orderNum < 1 || orderNum > totalOrders) {
        printf("Order not found.\n");
        return 0;
    }

    int index = orderNum - 1;
    printf("Order No: %d\n", orderNum);
    printf("Quantity: %d\n", quantity[index]);
    printf("Order Time: %02d:%02d %s\n", hour[index], minute[index], am_pm[index] == 0 ? "AM" : "PM");
    printf("Serve Time: %02d:%02d %s\n", serveHour[index], serveMinute[index], serve_am_pm[index] == 0 ? "AM" : "PM");

    int diffMin = Calculate_Time_Taken(index);
    printf("Time taken to serve: %d minute(s)\n", diffMin);

    return 0;
}

int Update_Time() {
    int orderNum, updateChoice;

    printf("===================================\n");
    printf("\n--- Update Time ---\n");
    printf("===================================\n");

    if (totalOrders == 0) {
        printf("No orders to update.\n");
        return 0;
    }

    printf("Enter Order Number to update: ");
    scanf("%d", &orderNum);

    if (orderNum < 1 || orderNum > totalOrders) {
        printf("Order not found.\n");
        return 0;
    }

    int index = orderNum - 1;

    printf("Enter 1 (Order Time Update) or 2 (Serve Time Update) or 3 (Order and Serve Time Update): ");
    scanf("%d", &updateChoice);

    if (updateChoice == 1 || updateChoice == 3) {
        printf("Enter New Order Hour: ");
        scanf("%d", &hour[index]);
        printf("Enter New Order Minute: ");
        scanf("%d", &minute[index]);
        printf("Enter AM or PM (0 for AM, 1 for PM): ");
        scanf("%d", &am_pm[index]);
        printf("Order time updated.\n");
    }

    if (updateChoice == 2 || updateChoice == 3) {
        printf("Enter New Serve Hour: ");
        scanf("%d", &serveHour[index]);
        printf("Enter New Serve Minute: ");
        scanf("%d", &serveMinute[index]);
        printf("Enter AM or PM (0 for AM, 1 for PM): ");
        scanf("%d", &serve_am_pm[index]);
        printf("Serve time updated.\n");
    }

    printf("\nPress Enter to continue...");
    getchar(); // To consume leftover newline
    getchar(); // To wait for user input

    return 0;
}

int Exit_System() {

    printf("Exiting the system...\n");
    return 0;
}

int main() {
    int choice;

    Welcome_Message();

    while (1) {

        choice = menu();

        switch (choice) {
            case 1:
                Register_New_Order();
                break;
            case 2:
                Remove_Order();
                break;
            case 3:
                Display_All_Orders();
                break;
            case 4:
                Search_Order();
                break;
            case 5:
                Update_Time();
                break;
            case 6:
                Exit_System();
                return 0;

            default:
               
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
