#include <stdio.h>
int main() {
    int choice ;
        
    Welcome_Message();
    menu();
        
    }
int Welcome_Message() {
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
            //case 1: Register_New_Order(orders, &totalOrders); break;
            //case 2: Remove_Order(orders, &totalOrders); break;
            //case 3: Display_All_Orders(orders, totalOrders); break;
            case 4: {
                int orderNum;
                printf("Enter Order Number to search: ");
                scanf("%d", &orderNum);
            }
        }
    }
