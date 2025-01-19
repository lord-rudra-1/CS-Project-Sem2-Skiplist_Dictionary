#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define P 0.5

typedef struct Node
{
    char *key;
    int value;
    struct Node **forward;
} Node;

typedef struct SkipList
{
    int level;
    Node *header;
    int size;
} SkipList;

Node *createNode(const char *key, int value, int level);
SkipList *createSkipList();
int randomLevel();
void insert(SkipList *list, const char *key, int value);
int size(SkipList *list);
int isEmpty(SkipList *list);
void displayList(SkipList *list);
int search(SkipList *list, const char *key);
void removeElement(SkipList *list, const char *key);
void clear(SkipList *list);
SkipList *subMap(SkipList *list, const char *fromKey, const char *toKey);
SkipList *headMap(SkipList *list, const char *toKey);
SkipList *tailMap(SkipList *list, const char *fromKey);
char *floorKey(SkipList *list, const char *key);
char *ceilingKey(SkipList *list, const char *key);
char *lowerKey(SkipList *list, const char *key);
char *higherKey(SkipList *list, const char *key);

int main()
{
    SkipList *list = createSkipList();
    char input[100];
    while (1)
    {
        printf("\n\nChoose an option:\n");
        printf("1. Insert\n");
        printf("2. Remove\n");
        printf("3. Search\n");
        printf("4. Size\n");
        printf("5. IsEmpty\n");
        printf("6. Clear\n");
        printf("7. FloorKey\n");
        printf("8. CeilingKey\n");
        printf("9. LowerKey\n");
        printf("10. HigherKey\n");
        printf("11. SubMap\n");
        printf("12. HeadMap\n");
        printf("13. TailMap\n");
        printf("14. Display\n");
        printf("15. Exit\n");

        int choice;
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            printf("Enter key and value to insert: ");
            char key[100];
            int value;
            if (scanf("%s%d", key, &value) != 2)
            {
                printf("Invalid input. Please enter key and value.\n");
                while (getchar() != '\n');
                continue;
            }
            insert(list, key, value);
            break;
        }
        case 2:
        {
            printf("Enter key to remove: ");
            char removeKey[100];
            if (scanf("%s", removeKey) != 1)
            {
                printf("Invalid input. Please enter a key.\n");
                while (getchar() != '\n');
                continue;
            }
            removeElement(list, removeKey);
            break;
        }
        case 3:
        {
            printf("Enter key to search: ");
            char searchKey[100];
            if (scanf("%s", searchKey) != 1)
            {
                printf("Invalid input. Please enter a key.\n");
                while (getchar() != '\n');
                continue;
            }
            int result = search(list, searchKey);
            if (result != -1)
                printf("Value associated with key '%s': %d\n", searchKey, result);
            else
                printf("Key '%s' not found\n", searchKey);
            break;
        }
        case 4:
            printf("Size of Skip List: %d\n", size(list));
            break;
        case 5:
            printf("Skip List is %s\n", isEmpty(list) ? "empty" : "not empty");
            break;
        case 6:
            clear(list);
            break;
        case 7:
        {
            printf("Enter key for FloorKey: ");
            char key[100];
            if (scanf("%s", key) != 1)
            {
                printf("Invalid input. Please enter a key.\n");
                while (getchar() != '\n');
                continue;
            }
            char *result = floorKey(list, key);
            if (result != NULL)
                printf("Floor Key of %s: %s\n", key, result);
            else
                printf("No floor key found for %s\n", key);
            break;
        }
        case 8:
        {
            printf("Enter key for CeilingKey: ");
            char key[100];
            if (scanf("%s", key) != 1)
            {
                printf("Invalid input. Please enter a key.\n");
                while (getchar() != '\n');
                continue;
            }
            char *result = ceilingKey(list, key);
            if (result != NULL)
                printf("Ceiling Key of %s: %s\n", key, result);
            else
                printf("No ceiling key found for %s\n", key);
            break;
        }
        case 9:
        {
            printf("Enter key for LowerKey: ");
            char key[100];
            if (scanf("%s", key) != 1)
            {
                printf("Invalid input. Please enter a key.\n");
                while (getchar() != '\n');
                continue;
            }
            char *result = lowerKey(list, key);
            if (result != NULL)
                printf("Lower Key of %s: %s\n", key, result);
            else
                printf("No lower key found for %s\n", key);
            break;
        }
        case 10:
        {
            printf("Enter key for HigherKey: ");
            char key[100];
            if (scanf("%s", key) != 1)
            {
                printf("Invalid input. Please enter a key.\n");
                while (getchar() != '\n');
                continue;
            }
            char *result = higherKey(list, key);
            if (result != NULL)
                printf("Higher Key of %s: %s\n", key, result);
            else
                printf("No higher key found for %s\n", key);
            break;
        }
        case 11:
        {
            printf("Enter fromKey and toKey for SubMap: ");
            char fromKey[100], toKey[100];
            if (scanf("%s%s", fromKey, toKey) != 2)
            {
                printf("Invalid input. Please enter fromKey and toKey.\n");
                while (getchar() != '\n');
                continue;
            }
            SkipList *subMapList = subMap(list, fromKey, toKey);
            printf("SubMap:\n");
            displayList(subMapList);
            clear(subMapList);
            break;
        }
        case 12:
        {
            printf("Enter upper bound for HeadMap: ");
            char upperBound[100];
            if (scanf("%s", upperBound) != 1)
            {
                printf("Invalid input. Please enter a key.\n");
                while (getchar() != '\n');
                continue;
            }
            SkipList *headMapList = headMap(list, upperBound);
            printf("HeadMap:\n");
            displayList(headMapList);
            clear(headMapList);
            break;
        }
        case 13:
        {
            printf("Enter lower bound for TailMap: ");
            char lowerBound[100];
            if (scanf("%s", lowerBound) != 1)
            {
                printf("Invalid input. Please enter a key.\n");
                while (getchar() != '\n');
                continue;
            }
            SkipList *tailMapList = tailMap(list, lowerBound);
            printf("TailMap:\n");
            displayList(tailMapList);
            clear(tailMapList);
            break;
        }
        case 14:
            displayList(list);
            break;
        case 15:
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid choice. Please enter a number between 1 and 15.\n");
        }
    }
    return 0;
}

Node *createNode(const char *key, int value, int level)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->key = strdup(key);
    n->value = value;
    n->forward = (Node **)malloc((level + 1) * sizeof(Node *));

    for (int i = 0; i <= level; i++)
    {
        n->forward[i] = NULL;
    }
    return n;
}

SkipList *createSkipList()
{
    SkipList *list = (SkipList *)malloc(sizeof(SkipList));
    list->level = 0;
    list->header = createNode("", -1, 0);
    list->size = 0;
    return list;
}

int randomLevel()
{
    int level = 0;
    while (((double)rand() / RAND_MAX) < P)
    {
        level++;
    }
    return level;
}

void insert(SkipList *list, const char *key, int value)
{
    Node *current = list->header;
    Node *update[list->level + 1];
    for (int i = 0; i <= list->level; i++)
        update[i] = NULL;
    for (int i = list->level; i >= 0; i--)
    {
        while (current->forward[i] != NULL && strcmp(current->forward[i]->key, key) < 0)
            current = current->forward[i];
        update[i] = current;
    }
    current = current->forward[0];
    if (current == NULL || strcmp(current->key, key) != 0)
    {
        int rlevel = randomLevel();
        if (rlevel > list->level)
        {
            for (int i = list->level + 1; i <= rlevel; i++)
                update[i] = list->header;
            list->level = rlevel;
        }
        Node *n = createNode(key, value, rlevel);
        for (int i = 0; i <= rlevel; i++)
        {
            n->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = n;
        }
        list->size++;
        printf("Successfully Inserted key '%s'\n", key);
    }
    else
        current->value = value;
}

int size(SkipList *list)
{
    return list != NULL ? list->size : 0;
}

int isEmpty(SkipList *list)
{
    return list == NULL || list->size == 0;
}

void displayList(SkipList *list)
{
    if (list == NULL || list->header == NULL || list->header->forward == NULL)
    {
        printf("Empty Skip List\n");
        return;
    }

    printf("\n**Skip List\n");
    for (int i = 0; i <= list->level; i++)
    {
        printf("Level %d: ", i);
        Node *node = list->header->forward[i];
        while (node != NULL)
        {
            if (node->key != NULL)
                printf("(%s, %d) ", node->key, node->value);
            node = node->forward[i];
        }
        printf("\n");
    }
}

int search(SkipList *list, const char *key)
{
    if (list == NULL || list->header == NULL)
        return -1;
    Node *current = list->header;
    for (int i = list->level; i >= 0; i--)
    {
        while (current->forward[i] != NULL && strcmp(current->forward[i]->key, key) < 0)
            current = current->forward[i];
    }
    current = current->forward[0];
    if (current && strcmp(current->key, key) == 0)
        return current->value;
    else
        return -1;
}

void removeElement(SkipList *list, const char *key)
{
    if (list == NULL || list->header == NULL)
        return;
    Node *current = list->header;
    Node *update[list->level + 1];
    for (int i = 0; i <= list->level; i++)
        update[i] = NULL;
    for (int i = list->level; i >= 0; i--)
    {
        while (current->forward[i] != NULL && strcmp(current->forward[i]->key, key) < 0)
            current = current->forward[i];
        update[i] = current;
    }
    current = current->forward[0];
    if (current && strcmp(current->key, key) == 0)
    {
        for (int i = 0; i <= list->level; i++)
        {
            if (update[i]->forward[i] != current)
                break;
            update[i]->forward[i] = current->forward[i];
        }
        free(current->key);
        free(current->forward);
        free(current);
        while (list->level > 0 && list->header->forward[list->level] == NULL)
            list->level--;
        list->size--;
        printf("Successfully deleted key '%s'\n", key);
    }
    else
        printf("Key '%s' not found\n", key);
}

void clear(SkipList *list)
{
    if (list == NULL)
        return;
    Node *current = list->header->forward[0];
    while (current != NULL)
    {
        Node *temp = current;
        current = current->forward[0];
        free(temp->key);
        free(temp->forward);
        free(temp);
    }
    free(list->header->key);
    free(list->header->forward);
    free(list->header);
    free(list);
    printf("Skip List cleared\n");
}

SkipList *subMap(SkipList *list, const char *fromKey, const char *toKey)
{
    if (list == NULL)
        return NULL;
    SkipList *sublist = createSkipList();
    Node *current = list->header;
    for (int i = list->level; i >= 0; i--)
    {
        while (current->forward[i] != NULL && strcmp(current->forward[i]->key, fromKey) < 0)
        {
            current = current->forward[i];
        }
    }
    current = current->forward[0];
    while (current != NULL && strcmp(current->key, toKey) <= 0)
    {
        insert(sublist, current->key, current->value);
        current = current->forward[0];
    }
    return sublist;
}

SkipList *headMap(SkipList *list, const char *toKey)
{
    return subMap(list, "", toKey);
}

SkipList *tailMap(SkipList *list, const char *fromKey)
{
    return subMap(list, fromKey, "}");
}

char *floorKey(SkipList *list, const char *key)
{
    if (list == NULL || list->header == NULL)
        return NULL;
    Node *current = list->header;
    for (int i = list->level; i >= 0; i--)
    {
        while (current->forward[i] != NULL && strcmp(current->forward[i]->key, key) <= 0)
            current = current->forward[i];
    }
    return current->key;
}

char *ceilingKey(SkipList *list, const char *key)
{
    if (list == NULL || list->header == NULL)
        return NULL;
    Node *current = list->header;
    for (int i = list->level; i >= 0; i--)
    {
        while (current->forward[i] != NULL && strcmp(current->forward[i]->key, key) < 0)
            current = current->forward[i];
    }
    if (current->forward[0] != NULL)
        return current->forward[0]->key;
    else
        return NULL;
}

char *lowerKey(SkipList *list, const char *key)
{
    if (list == NULL || list->header == NULL)
        return NULL;
    Node *current = list->header;
    for (int i = list->level; i >= 0; i--)
    {
        while (current->forward[i] != NULL && strcmp(current->forward[i]->key, key) < 0)
            current = current->forward[i];
    }
    return current->key;
}

char *higherKey(SkipList *list, const char *key)
{
    if (list == NULL || list->header == NULL)
        return NULL;
    Node *current = list->header;
    for (int i = list->level; i >= 0; i--)
    {
        while (current->forward[i] != NULL && strcmp(current->forward[i]->key, key) <= 0)
            current = current->forward[i];
    }
    if (current->forward[0] != NULL)
        return current->forward[0]->key;
    else
        return NULL;
}