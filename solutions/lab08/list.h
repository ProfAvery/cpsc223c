#ifndef LIST_H
#define LIST_H

struct node {
    int line;
    bstring command;
    unsigned int argument;

    struct node *next;
};

struct node *create_node(int, bstring, unsigned int);
struct node *append_node(struct node *, struct node *);
void print_node(struct node *);
void print_list(struct node *);
void free_list(struct node *);

#endif

