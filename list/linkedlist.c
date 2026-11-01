#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct t_list {
    void *content;
    struct t_list *next;
} t_list;

void show(t_list* list) {
    t_list *current = list;
    while (current) {
        if (current->content) {
            printf("%s\n", (char *)current->content);
        }
        current = current->next;
    }
}

void insert(t_list* list, void *content) {
    t_list* current = list;
    
    while (current->next != NULL) {
        current = current->next;
    }
    
    t_list* new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node) return;

    new_node->content = malloc(strlen((char *)content) + 1);
    if (new_node->content) {
        strcpy((char *)new_node->content, (char *)content);
    }
    new_node->next = NULL;
    
    current->next = new_node;
}

int main() {
    t_list list;
    list.content = "Initial"; 
    list.next = NULL;

    insert(&list, "Bruh");
    insert(&list, "C est mieux");
    
    show(&list);
    
    return (0);
}