#include <stdio.h>
#include <stdlib.h>

// Node bağlı liste düğümünü temsil eder
struct Node {
    int data;
    struct Node* next;
};

// Yeni düğüm oluşturma fonksiyonu
struct Node* yeniNode(int data) {
    struct Node* yeni = (struct Node*)malloc(sizeof(struct Node));
    yeni->data = data;
    yeni->next = NULL;
    return yeni;
}

//Baş düğüm değişirse yani ** olursa & eklenir başına
void basaEkle(struct Node **head,int x){
    struct Node *yeni = yeniNode(x) ;
    yeni->next=*head;
    *head=yeni;
}

void arayaEkle(struct Node *head, int listedebulunan,int eklemekistenen){
    struct Node* yeni= yeniNode(eklemekistenen) ;
    struct Node *tmp= head ;
    while (tmp->next != NULL){
        tmp=tmp->next ;
        if(tmp->data==listedebulunan){
            yeni->next=tmp->next;
            tmp->next=yeni ;
        }
    }
}

void sonaEkle(struct Node *head, int y){
    struct Node* yeni= yeniNode(y) ;
    struct Node *tmp= head ;
    while (tmp->next != NULL)
        tmp=tmp->next ;
    tmp->next=yeni ;
}

// Bağlı listeyi yazdırma fonksiyonu
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void bastanSil(struct Node **head){
    struct Node* tmp=*head;
    *head=(*head)->next;
    free(tmp);
}


void aradanSil(struct Node*head,int x){
    struct Node* tmp=head;
    struct Node* silinecek;
    while (tmp->next->data != x)
        tmp=tmp->next;
    silinecek=tmp->next;
    tmp->next=tmp->next->next;
    free(silinecek);
}

void sondanSil(struct Node*head){
    struct Node* tmp=head;
    while (tmp->next->next != NULL)
        tmp=tmp->next;
    free(tmp->next);
    tmp->next=NULL;
}

void reverse(struct Node **head){
    struct Node* prev=NULL;
    struct Node* current=*head;
    struct Node* next;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *head=prev;
}

int main() {
    struct Node* birinci = yeniNode(6);
    struct Node* ikinci = yeniNode(7);
    birinci->next= ikinci;
    struct Node* ucuncu = yeniNode(8);
    ikinci->next= ucuncu;

    printList(birinci);

    arayaEkle(birinci,7,45);
    printList(birinci);
}
//Tamamen Doğru