// main.c
#include <stdio.h>
#include "memory.h"

int main() {
    int choice, pid, size;

    init_memory();

    while (1) {
        printf("\n1. Allocate Memory\n2. Free Memory\n3. Show Map\n4. Exit\nSelect: ");
        scanf("%d", &choice);

        switch (choice) {
            // در قسمت case 1 فایل main.c این تغییرات را بده:

            case 1:
                printf("Enter Process ID and Size: ");
                scanf("%d %d", &pid, &size);
                
                printf("Choose Algorithm: 1.First-Fit  2.Best-Fit: ");
                int alg;
                scanf("%d", &alg);

                bool result = false;
                if (alg == 1) 
                    result = allocate_memory(pid, size); // همان تابع قبلی
                else 
                    result = allocate_best_fit(pid, size); // تابع جدید

                if (result) printf(">> Success!\n");
                else printf(">> Error: Not enough memory.\n");
                break;
            case 2:
                printf("Enter Process ID to free: ");
                scanf("%d", &pid);
                free_memory(pid);
                break;
            case 3:
                show_memory_map();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}