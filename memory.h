// memory.h
#ifndef MEMORY_H
#define MEMORY_H

#include <stdio.h>
#include <stdbool.h>

// تعریف اندازه حافظه شبیه‌سازی شده
#define MEMORY_SIZE 100

// ساختاری برای نمایش وضعیت هر بلوک حافظه
// 0 means free, other numbers represent Process ID
extern int ram[MEMORY_SIZE];

// لیست توابع (Prototypes)
void init_memory();
bool allocate_memory(int process_id, int size);
void free_memory(int process_id);
void show_memory_map();
// memory.h (این خط را اضافه کن)
bool allocate_best_fit(int process_id, int size);
#endif