#include <stdio.h>
#include <stdlib.h>

// Node yapısı tanımlanıyor
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Yeni bir düğüm (node) oluşturma fonksiyonu
struct Node* yeniNode(int x) {
    struct Node* yeni = (struct Node*)malloc(sizeof(struct Node));
    yeni->data = x;
    yeni->prev = yeni->next = NULL;
    return yeni;
}



void PrintList(struct Node *head){
    struct Node*tmp=head;
    do {
        printf("%d\t", tmp->data);
        tmp=tmp->next;
    } while (tmp!=head);
    printf("NULL\n");//Bir Satır Aşağı İnmek için
}

void BastanSil(struct Node**head){
    struct Node* tmp= *head;
    struct Node* st=NULL;
    while (tmp->next !=*head){
        tmp=tmp->next;
    }
    st=tmp->next;
    tmp->next=st->next;
    st->next->prev=tmp;
    *head=st->next;
    free(st);
}

void SondanSil(struct Node*head){
    struct Node* tmp= head;
    struct Node*st;
    while(tmp->next->next!=head){
        tmp=tmp->next;
    }
    st=tmp->next;
    tmp->next=head;
    head->prev=tmp;
    free(st);
}

int main(){
    struct Node*birinci= yeniNode(5);
    struct Node*ikinci= yeniNode(15);
    birinci->next=ikinci;
    struct Node*ucuncu= yeniNode(25);
    ikinci->prev=birinci;
    ikinci->next=ucuncu;
    ucuncu->prev=ikinci;
    ucuncu->next=birinci;

    birinci->prev=ucuncu;

    PrintList(birinci);

    BastanSil(&birinci);
    PrintList(birinci);

    SondanSil(birinci);
    PrintList(birinci);

}

//TODO tamamı doğru...