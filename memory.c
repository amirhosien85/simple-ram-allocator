// memory.c
#include "memory.h"

// تعریف آرایه اصلی حافظه
int ram[MEMORY_SIZE];

// تابع ۱: پاکسازی اولیه حافظهgit 
void init_memory() {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        ram[i] = 0; // 0 یعنی خالی
    }
    printf(">> Memory Initialized.\n");
}

// تابع ۲: اختصاص حافظه (شبیه‌سازی First-Fit)
bool allocate_memory(int process_id, int size) {
    int free_count = 0;
    int start_index = -1;

    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (ram[i] == 0) {
            if (free_count == 0) start_index = i;
            free_count++;
            
            // اگر فضای کافی پیدا شد
            if (free_count == size) {
                for (int j = start_index; j < start_index + size; j++) {
                    ram[j] = process_id;
                }
                return true; // موفقیت
            }
        } else {
            // زنجیره فضای خالی قطع شد
            free_count = 0;
            start_index = -1;
        }
    }
    return false; // فضای کافی پیدا نشد
}

// تابع ۳: آزادسازی حافظه یک پردازه
void free_memory(int process_id) {
    int freed_count = 0;
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (ram[i] == process_id) {
            ram[i] = 0;
            freed_count++;
        }
    }
    if (freed_count > 0)
        printf(">> Process %d freed (%d blocks).\n", process_id, freed_count);
    else
        printf(">> Process %d not found.\n", process_id);
}

// تابع ۴: نمایش گرافیکی وضعیت حافظه
void show_memory_map() {
    printf("\n--- Memory Map ---\n");
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (ram[i] == 0) printf(". "); // نقطه یعنی خالی
        else printf("%d ", ram[i]);    // عدد یعنی اشغال توسط آن پردازه
        
        // هر ۲۰ بلوک یک خط جدید برود
        if ((i + 1) % 20 == 0) printf("\n");
    }
    printf("------------------\n");
}