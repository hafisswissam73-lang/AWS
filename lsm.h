#ifndef LSM_H
#define LSM_H

#define MEMTABLE_CAPACITY 100
#define MAX_LEVELS 4

typedef struct {
    int key;
    int value;
} Record;

typedef struct {
    Record records[MEMTABLE_CAPACITY];
    int size;
} MemTable;

typedef struct {
    char filename[100];
    int level;
    int recordCount;
} SSTable;

typedef struct {
    MemTable memtable;
    SSTable levels[MAX_LEVELS];
    int levelCount;
} LSMTree;

#endif
