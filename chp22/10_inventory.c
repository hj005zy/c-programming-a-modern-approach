/* Maintains a parts database (linked list version) */

#include <stdio.h>
#include <stdlib.h>
#include "10_readline.h"

#define NAME_LEN 25
#define FILENAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    struct part *next;
};

struct part *inventory = NULL;

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void dump(void);
void read(void);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
    char code;

    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')
            ;
        switch (code) {
            case 'i':
                insert();
                break;
            case 's':
                search();
                break;
            case 'u':
                update();
                break;
            case 'p':
                print();
                break;
            case 'd':
                dump();
                break;
            case 'r':
                read();
                break;
            case 'q':
                return 0;
            default:
                printf("Illegal code\n");
        }
        printf("\n");
    }
}

/**********************************************************
 * find_part: Looks up a part number in the inventory     *
 *            list. Returns a pointer to the node         *
 *            containing the part number; if the part     *
 *            number is not found, returns NULL.          *
 **********************************************************/
struct part *find_part(int number)
{
    struct part *p;

    for (p = inventory; p != NULL && number > p->number; p = p->next)
        ;
    if (p != NULL && number == p->number) {
        return p;
    }
    return NULL;
}

/**********************************************************
 * insert: Prompts the user for information about a new   *
 *         part and then inserts the part into the        *
 *         inventory list; the list remains sorted by     *
 *         part number. Prints an error message and       *
 *         returns prematurely if the part already exists *
 *         or space could not be allocated for the part.  *
 **********************************************************/
void insert(void)
{
    struct part *cur, *prev, *new_node;

    new_node = malloc(sizeof(struct part));
    if (new_node == NULL) {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &new_node->number);

    for (cur = inventory, prev = NULL;
         cur != NULL && new_node->number > cur->number;
         prev = cur, cur = cur->next)
        ;
    if (cur != NULL && new_node->number == cur->number) {
        printf("Part already exists.\n");
        free(new_node);
        return;
    }

    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &new_node->on_hand);

    new_node->next = cur;
    if (prev == NULL) {
        inventory = new_node;
    } else {
        prev->next = new_node;
    }
}

/**********************************************************
 * search: Prompts the user to enter a part number, then  *
 *         looks up the part in the database. If the part *
 *         exists, prints the name and quantity on hand;  *
 *         if not, prints an error message.               *
 **********************************************************/
void search(void)
{
    int number;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL) {
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d\n", p->on_hand);
    } else {
        printf("Part not found.\n");
    }
}

/**********************************************************
 * update: Prompts the user to enter a part number.       *
 *         Prints an error message if the part doesn't    *
 *         exist; otherwise, prompts the user to enter    *
 *         change in quantity on hand and updates the     *
 *         database.                                      *
 **********************************************************/
void update(void)
{
    int number, change;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        p->on_hand += change;
    } else {
        printf("Part not found.\n");
    }
}

/**********************************************************
 * print: Prints a listing of all parts in the database,  *
 *        showing the part number, part name, and         *
 *        quantity on hand. Parts are printed in the      *
 *        order in which they were entered into the       *
 *        database.                                       *
 **********************************************************/
void print(void)
{
    struct part *p;

    printf("Part Number   Part Name                  "
           "Quantity on Hand\n");
    for (p = inventory; p != NULL; p = p->next) {
        printf("%7d       %-25s%11d\n", p->number,
               p->name, p->on_hand);
    }
}

/**********************************************************
 * dump: Prompts the user to enter output file name, then *
 *       dumps all parts to the file.                     *
 **********************************************************/
void dump(void)
{
    struct part *p;
    char file_name[FILENAME_LEN + 1];
    FILE *fp;

    printf("Enter name of output file: ");
    read_line(file_name, FILENAME_LEN);

    fp = fopen(file_name, "wb");
    for (p = inventory; p != NULL; p = p->next) {
        fwrite(&p->number, sizeof(p->number), 1, fp);
        fwrite(p->name, sizeof(char), NAME_LEN, fp);
        fwrite(&p->on_hand, sizeof(p->on_hand), 1, fp);
    }
    fclose(fp);
}

/**********************************************************
 * read: Prompts the user to enter input file name, then  *
 *       reads the parts data into the database.          *
 **********************************************************/
void read(void)
{
    struct part *cur, *prev, *new_node;
    char file_name[FILENAME_LEN + 1];
    FILE *fp;
    int number, num_read, i;

    printf("Enter name of input file: ");
    read_line(file_name, FILENAME_LEN);

    if ((fp = fopen(file_name, "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", file_name);
        exit(EXIT_FAILURE);
    }

    num_read = fread(&number, sizeof(number), 1, fp);
    while (num_read == 1) {
        new_node = malloc(sizeof(struct part));
        if (new_node == NULL) {
            printf("Database is full; can't add more parts.\n");
            return;
        }
        new_node->number = number;
        fread(new_node->name, sizeof(char), NAME_LEN, fp);
        new_node->name[NAME_LEN] = '\0';
        fread(&new_node->on_hand, sizeof(new_node->on_hand), 1, fp);
 
        for (cur = inventory, prev = NULL;
             cur != NULL && new_node->number > cur->number;
             prev = cur, cur = cur->next)
            ;

        new_node->next = cur;
        if (prev == NULL) {
            inventory = new_node;
        } else {
            prev->next = new_node;
        }

        num_read = fread(&number, sizeof(number), 1, fp);
    }
    fclose(fp);
}
