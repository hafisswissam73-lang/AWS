
#ifndef LSM_H
#define LSM_H

#define MEMTABLE_CAPACITY 100
#define MAX_LEVELS 4

// Structure representing one record
typedef struct {
    int key;
    int value;
} Record;

// MemTable structure
typedef struct {
    Record records[MEMTABLE_CAPACITY];
    int size;
} MemTable;

// SSTable structure
typedef struct {
    char filename[100];
    int level;
    int recordCount;
} SSTable;

// Main LSM Tree structure
typedef struct {
    MemTable memtable;
    SSTable levels[MAX_LEVELS];
    int levelCount;
} LSMTree;

// Function declarations
void initLSMTree(LSMTree *tree);
int insertRecord(LSMTree *tree, int key, int value);
int searchRecord(LSMTree *tree, int key, int *value);
void flushMemTable(LSMTree *tree);
void freeLSMTree(LSMTree *tree);

#endif

