
#include <stdio.h>
int main() {
    int choice ;
        
    Welcome_Message();
    menu();
        
    }
int Welcome_Message() {
    printf("===================================\n");
    printf(" Welcome to Restaurant Management System! (ROMS) \n");
    printf("===================================\n");
    printf("Press any key to continue...");
    getchar(); getchar();
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
        }
 
 switch (choice) {
            //case 1: Register_New_Order(orders, &totalOrders); break;
            //case 2: Remove_Order(orders, &totalOrders); break;
            //case 3: Display_All_Orders(orders, totalOrders); break;
            //case 4: {
                int orderNum;
                printf("Enter Order Number to search: ");
                scanf("%d", &orderNum);
