
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/lsm.h"

// Initialize the LSM Tree
void initLSMTree(LSMTree *tree) {
    tree->memtable.size = 0;
    tree->levelCount = 0;

    for (int i = 0; i < MAX_LEVELS; i++) {
        tree->levels[i].filename[0] = '\0';
        tree->levels[i].level = i;
        tree->levels[i].recordCount = 0;
    }

    printf("LSM Tree initialized successfully!\n");
}

