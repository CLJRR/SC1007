#include <stdio.h>
#include <stdlib.h>

#define TABLESIZE 37
#define PRIME 13

enum Marker
{
    EMPTY,
    USED
};

typedef struct _slot
{
    int key;
    enum Marker indicator;
    int next;
} HashSlot;

int HashInsert(int key, HashSlot hashTable[]);
int HashFind(int key, HashSlot hashTable[]);

int hash(int key)
{
    return (key % TABLESIZE);
}

int main()
{
    int opt;
    int i;
    int key;
    int index;
    HashSlot hashTable[TABLESIZE];

    for (i = 0; i < TABLESIZE; i++)
    {
        hashTable[i].next = -1;
        hashTable[i].key = 0;
        hashTable[i].indicator = EMPTY;
    }

    printf("============= Hash Table ============\n");
    printf("|1. Insert a key to the hash table  |\n");
    printf("|2. Search a key in the hash table  |\n");
    printf("|3. Print the hash table            |\n");
    printf("|4. Quit                            |\n");
    printf("=====================================\n");

    printf("Enter selection: ");
    scanf("%d", &opt);
    while (opt >= 1 && opt <= 3)
    {
        switch (opt)
        {
        case 1:
            printf("Enter a key to be inserted:\n");
            scanf("%d", &key);
            index = HashInsert(key, hashTable);
            if (index < 0)
                printf("Duplicate key\n");
            else if (index < TABLESIZE)
                printf("Insert %d at index %d\n", key, index);
            else
                printf("Table is full.\n");
            break;
        case 2:
            printf("Enter a key for searching in the HashTable:\n");
            scanf("%d", &key);
            index = HashFind(key, hashTable);

            if (index != -1)
                printf("%d is found at index %d.\n", key, index);
            else
                printf("%d is not found.\n", key);
            break;

        case 3:
            printf("index:\t key \t next\n");
            for (i = 0; i < TABLESIZE; i++)
                printf("%d\t%d\t%d\n", i, hashTable[i].key, hashTable[i].next);
            break;
        }
        printf("Enter selection: ");
        scanf("%d", &opt);
    }
    return 0;
}

int HashInsert(int key, HashSlot hashTable[])
{
    int bin = hash(key), count = 0;

    if (hashTable[bin].indicator == EMPTY) // if first indicator is empty, slot in
    {
        hashTable[bin].indicator = USED;
        hashTable[bin].key = key;
        return bin;
    }
    while (hashTable[bin].next != -1) // find last in next
    {
        if (hashTable[bin].key == key)
            return -1;
        bin = hashTable[bin].next;
    }
    // check last element for dupes
    if (hashTable[bin].key == key)
        return -1;
    int newbin = bin; // make new bin for new position
    for (count, count < TABLESIZE, ++count)
    {
        newbin++;
        if (hashTable[newbin].indicator == EMPTY)
            break; // Found an empty slot.
    }

    if (count > TABLESIZE)
        return count;
    else
    {

        // update needed places
        hashTable[bin].indicator = USED;
        hashTable[bin].key = key;
        hashTable[temp].next = bin;
        return bin;
    }
}

int HashFind(int key, HashSlot hashTable[])
{
    int bin = hash(key);

    if (hashTable[bin].indicator == EMPTY) // if first indicator is empty, return not found
    {
        return -1;
    }
    while (hashTable[bin].next != -1) // compare until last
    {
        if (hashTable[bin].key == key)
            return bin;
        bin = hashTable[bin].next;
    }
    if (hashTable[bin].key == key)
        return bin;
    else
        return -1;
}