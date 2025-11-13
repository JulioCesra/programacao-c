#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int cont;
    struct Node *next;
}List;

List *startList(){
    return NULL;
}

List *addNode(List *list, int cont){
    List *newNode = (List *)malloc(sizeof(List));
    if(newNode == NULL){
        printf("Allocation Memory Error!\n");
        return list;
    }
    newNode->cont = cont;
    newNode->next = NULL;
    if(list == NULL){
        return newNode;
    }
    List *aux = list;
    while(aux->next != NULL){
        aux = aux->next;
    }
    aux->next = newNode;
    return list;
}

int countNodes(List *list){
    if(list == NULL){
        return 0;
    }
    return 1 + countNodes(list->next);
}

int isEmpty(List *list){
    return (list == NULL) ? 1 : 0;
}

List *searchNode(List *list, int valueSought){
    if(list == NULL){
        return NULL;
    }
    if(list->cont == valueSought){
        return list;
    }
    return searchNode(list->next,valueSought);
}

List *removeNode(List *list, int valueSought){
    if(isEmpty(list)){
        printf("List empty!\n");
        return NULL;
    }
    List *current = list;
    List *previous = NULL;
    while(current != NULL && current->cont != valueSought){
        previous = current;
        current = current->next;
    }
    if(current == NULL){
        printf("Node not found!\n");
        return list;
    }
    if(previous == NULL){
        list = current->next;
        free(current);
        return list;
    }else{
        previous->next = current->next;
        free(current);
        return list;
    }
}

List *removeDuplicatedNodes(List *list){
    if(isEmpty(list)){
        return NULL;
    }
    List *current = list;
    while(current != NULL){
        List *runner = current;
        while(runner->next != NULL){
            if(runner->next->cont == current->cont){
                List *noRemove = runner->next;
                runner->next = noRemove->next;
                free(noRemove);
            }else{
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

void quickSort(int arr[], int start, int size){
    if(start < size){
        int i = start;
        int j = size - 1;
        int pivo = arr[(i + j) / 2];
        while(i <= j){
            while(arr[i] < pivo){
                i ++;
            }
            while(arr[j] > pivo){
                j --;
            }
            if(i <= j){
                int x = arr[i];
                arr[i] = arr[j];
                arr[j] = x;
                i ++;
                j --;
            }
        }
        if(start < j + 1){
            quickSort(arr, start, j + 1);
        }
        if(i < size){
            quickSort(arr, i, size);
        }
    }
}

void viewList(List *list){
    if(list == NULL){
        printf("NULL\n");
        return;
    }
    printf("[Cont: %d | Memory Address: %p] -> ",list->cont,list);
    viewList(list->next);
}

void viewNormalList(int arr[], int size){
    for(int i = 0; i < size; i ++){
        printf("|%d| -> ",arr[i]);
    }
}

int main(){
    List *list;
    list = startList();
    list = addNode(list,20);
    list = addNode(list,5);
    list = addNode(list,59);
    viewList(list);
    printf("Quantity of nodes: %d\n",countNodes(list));
    List *node;
    node = searchNode(list,5);
    if(node == NULL){
        printf("Node not found!\n");
    }else{
        printf("Note found\n");
        printf("Content of node found: %d\n",node->cont);
    }
    list = removeNode(list,59);
    viewList(list);
    list = removeDuplicatedNodes(list);
    viewList(list);
    int arr[] = {10, 30, 50, 1, 2,7};
    int size = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr,0,size);
    viewNormalList(arr,size);
    return 0;
}