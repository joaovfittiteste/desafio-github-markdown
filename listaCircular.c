#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int valor;
    struct Node *prox;
}Node;

//inserir começo
void inserirComeco(Node **head, Node **tail, int n){
    Node *novo = (Node *) malloc(sizeof(Node));

    if(novo != NULL){
        novo->valor = n;

        if(*head == NULL){
            *head = *tail = novo;

        }else{
            novo->prox = *head;
            *head = novo;
        }
        (*tail)->prox = *head;
    }
}


//printar lista
void printarLista(Node *head, Node *tail){
    if(head != NULL){
        do{
            printf("%d ", head->valor);
            head = head->prox;
        }while(head != tail->prox);
    }
}


//remover comeco
void removerComeco(Node **head, Node **tail){
    if(*head != NULL){
        Node *aux = *head;

        if(*head == *tail){
            *head = *tail = NULL;
        }
        else{
            *head = (*head)->prox;
            (*tail)->prox = *head;
        }

        free(aux);
    }
}


//inserir final
void inserirFinal(Node **head, Node **tail, int n){
    Node *novo = (Node *)malloc(sizeof(Node));

    if(novo != NULL){
        novo->valor = n;

        if(*head == NULL){
            *head = *tail = novo;
        }
        else{
            (*tail)->prox = novo;
            *tail = novo;
        }
        (*tail)->prox = *head;
    }

}


//remover final
void removerFinal(Node **head, Node **tail){
    if(*head != NULL){
        Node *temp = *head;

        if(*head == *tail){
            *head = *tail = NULL;
            free(temp);
        }
        else{
            while(temp->prox != *tail){
                temp = temp->prox;
            }
            temp->prox = *head;
            free(*tail);
            *tail = temp;
            
        }
        
    }
    
}