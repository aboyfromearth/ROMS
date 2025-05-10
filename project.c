#include <stdio.h>
int main() {
    int choice ;
        
    Welcome_Message();
    menu();
        
    }
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
    getchar(); getchar();
}

int menu() {
 
        int choice, orders, totalOrders;
 
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
 
        switch (choice) {
            case 1: Register_New_Order(orders, &totalOrders); break;
            case 2: Remove_Order(orders, &totalOrders); break;
            case 3: Display_All_Orders(orders, totalOrders); break;
            case 4: {
                int orderNum;
                printf("Enter Order Number to search: ");
                scanf("%d", &orderNum);
            }
        }
    }
int Register_New_Order(int orders, int *totalOrders) {
    int quantity, hour, minute, am_pm, serveHour, serveMinute, serve_am_pm;

    printf("===================================\n");
    printf("\n--- Register New Order ---\n");
    printf("===================================\n");

    printf("Enter Order Number: ");
    scanf("%d", &orders);

    printf("Enter Quantity of Food Items: ");
    scanf("%d", &quantity);

    printf("Enter Hour: ");
    scanf("%d", &hour);

    printf("Enter Minute: ");
    scanf("%d", &minute);

    printf("Enter AM or PM (0 for AM, 1 for PM): ");
    scanf("%d", &am_pm);// 0 for AM, 1 for PM

    printf("Enter Serve Hour: ");
    scanf("%d", &serveHour);

    printf("Enter Serve Minute: ");
    scanf("%d", &serveMinute);

    printf("Enter AM or PM (0 for AM, 1 for PM): ");
    scanf("%d", &serve_am_pm);

    printf("Order Registered Successfully!\n");

    // Increment total orders
    (*totalOrders)++;

    return 0;
}
int Remove_Order(int orders, int *totalOrders) {
    // Function to remove an order
    // Implementation 
    return 0;
}
int Display_All_Orders(int orders, int totalOrders) {
    // Function to display all orders
    // Implementation 
    return 0;
}
int Search_Order(int orders, int totalOrders) {
    // Function to search for an order
    // Implementation 
    return 0;
}
int Update_Serve_Time(int orders, int totalOrders) {
    // Function to update serve time
    // Implementation 
    return 0;
}
int Calculate_Time_Taken(int orders, int totalOrders) {
    // Function to calculate time taken to serve each order
    // Implementation 
    return 0;
}
int Exit_System() {
    // Function to exit the system
    printf("Exiting the system...\n");
    return 0;
}
