#include <stdio.h>
#include <stdlib.h>

// Node bağlı liste düğümünü temsil eder
struct Node {
    int data;
    struct Node* next;
};

struct Node* yeniNode(int data) {
    struct Node* yeni = (struct Node*)malloc(sizeof(struct Node));
    yeni->data = data;
    yeni->next = NULL;
    return yeni;
}

// Bağlı listeyi yazdırma fonksiyonu
void printList(struct Node* head) {
    while (head != NULL) {
/*
        printf("%d -> ", head);
*/
/*
        printf("%d -> ", *head);
*/
        printf("%d -> ", head->data);
        head = head->next;
        /*int *ptr = (int*)&head;  // Bellekteki 28033040 adresini int işaretçi olarak tanımlıyoruz.
        printf("Adresteki değer budur: %d\n", *ptr);  // Adresteki değeri okuyoruz.*/
    }
    printf("NULL\n");
}

int main() {
    struct Node *birinci = yeniNode(6);
    struct Node *ikinci = yeniNode(7);
    struct Node *ucuncu = yeniNode(8);
    birinci->next = ikinci;
    ikinci->next = ucuncu;

    struct Node **head;

    printList(birinci);


}