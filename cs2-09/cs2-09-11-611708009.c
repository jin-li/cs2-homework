/**
 * This code was copied from the book "C Programming, A Modern Approach 2nd ed."
 * (written by K. N. King), for the lecture "Computer Software II" in Nagoya University.
 */
#include <stdio.h>
#include <stdlib.h>


struct node {
    int value;          /* data stored in the node */
    struct node *next;  /* pointer to the next node */
};

/*
 * a function to count how many times a member occurs
 */
int count_occurrences(struct node *list, int n)
{
    struct node *p;
    int cnt = 0;
    for(p = list; p!=NULL; p = p->next)
    {
        if(p->value == n)
            cnt++;
    }
    return cnt;
}

/*
 * a funtion to insert a node
 */
struct node *add_to_list(struct node *list, int n)
{
    struct node *new_node;

    new_node = malloc(sizeof(struct node));
    if(new_node == NULL){
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = list;
    return new_node;
}


/*
 * a funtion to read numbers from input stream
 */
struct node *read_numbers(void)
{
    struct node *first = NULL;
    int n;

    printf("Enter a series of integers (0 to terminate): ");
    for(;;){
        scanf("%d", &n);
        if(n == 0)
            return first;
        first = add_to_list(first, n);
    }
}

/*
 * a function to search a node from a list
 */
struct node *search_list(struct node *list, int n)
{
    struct node *p;

    for(p = list; p != NULL; p = p->next){
        if(p->value == n)
            return p;
    }
    return NULL;
}


/*
 * a function to delete a node from a list
 */
struct node  *delete_from_list (struct node *list,  int n)
{
    struct node  *cur, *prev;

    for(cur = list, prev = NULL;
        cur != NULL && cur->value !=n;
        prev = cur,   cur = cur->next)
        ;
    if(cur == NULL)               /* n was not found */
        return list;
    if(prev == NULL)              /* n is in the first node */
        list = list->next;
    else                          /* n is in some other node */
        prev->next = cur->next;
    free(cur);
    return list;
}


/*
 * a function to print a list
 */
void print_list (struct node *list)
{
    struct node *p;

    for(p = list; p != NULL; p = p->next){
        printf("[%d]->", p->value);
    }
    printf("\n");
}


/*
 * the main function
 */
int main(void)
{
    struct node *list;
    int n;

    list = read_numbers();
    print_list(list);
/*
    printf("Enter a number for searching: ");
    scanf("%d", &n);
    if(search_list(list, n) != NULL)
        printf("%d is found.\n", n);
    else
        printf("%d is not found.\n", n);

    printf("Enter a number for deleting: ");
    scanf("%d", &n);
    list = delete_from_list(list, n);
    print_list(list);
*/
    int occurrences;
    printf("Enter a member for counting: ");
    scanf("%d", &n);
    occurrences = count_occurrences(list, n);
    printf("%d appears %d time(s).", n, occurrences);
    return 0;
}
