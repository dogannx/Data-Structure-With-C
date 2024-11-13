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

//PrintList
void PrintList(struct Node *head){
    struct Node*tmp=head;
    do {
        printf("%d\t", tmp->data);
        tmp=tmp->next;
    } while (tmp!=head);
    printf("NULL\n");//Bir Satır Aşağı İnmek için
}

//Başa ekle
// Başa ekleme fonksiyonu düzeltildi
void BasaEkle(struct Node **head, int x) {
    struct Node *yeni = yeniNode(x);
/*
    if (*head == NULL) {
        yeni->next = yeni;  // Tek elemanlı dairesel liste
        *head = yeni;
        return;
    }
*/
    struct Node *tmp = *head;
    while (tmp->next != *head) {
        tmp = tmp->next;
    }

    yeni->next = *head;
    tmp->next = yeni;
    *head = yeni;  // Yeni düğümü baş olarak ayarla
}

//Araya Ekle
void ArayaEkle(struct Node *head,int eklenecekdeger, int listedeolandeger){
    struct Node * yeni= yeniNode(eklenecekdeger);
    struct Node *tmp=head;
    while(tmp->data != listedeolandeger)
        tmp=tmp->next;
    yeni->next=tmp->next;
    tmp->next=yeni;
}

//Sona Ekle
void SonaEkle(struct Node *head,int x){
    struct Node * yeni= yeniNode(x);
    struct Node *tmp=head;
    while(tmp->next != head){
        tmp=tmp->next;
    }
    yeni->next=tmp->next;
    tmp->next=yeni;
}

//BastanSil
void BastanSil(struct Node **head){
    struct Node*tmp=*head;
    struct Node* silinecek;
    while(tmp->next != *head)
        tmp=tmp->next;
    silinecek=tmp->next;
    tmp->next=tmp->next->next;
    *head =tmp->next;
    free(silinecek);
}

//AradanSil
void AradanSil(struct Node *head, int x){
    struct Node*tmp=head;
    while(tmp->next->data!=x)
        tmp=tmp->next;
    struct Node* silinecek= tmp->next;
    tmp->next=tmp->next->next;
    free(silinecek);
}

//SondanSil
void SondanSil(struct Node *head){
    struct Node*tmp=head;
    while(tmp->next->next!=head)
        tmp=tmp->next;
    struct Node* silinecek= tmp->next;
    tmp->next=tmp->next->next;
    free(silinecek);
    tmp->next=head;
}

int uzunluk(struct Node*head){
    struct Node *tmp= head;
    int sonuc=0;
    do{
        sonuc++;
        tmp=tmp->next;
    } while (tmp!=head);
    return sonuc;
}

//Bağla
void bagla(struct Node **head1, struct Node *head2) {
    if (*head1 == NULL || head2 == NULL) return;  // Boş liste kontrolü

    int uzunluk1 = uzunluk(*head1);
    int uzunluk2 = uzunluk(head2);

    if (uzunluk2 < uzunluk1) {
        // Birinci listenin sonunu bul
        struct Node *tmp1 = *head1;
        while (tmp1->next != *head1) {
            tmp1 = tmp1->next;
        }

        // İkinci listenin sonunu bul
        struct Node *tmp2 = head2;
        while (tmp2->next != head2) {
            tmp2 = tmp2->next;
        }

        // İkinci listenin sonunu birinci listenin başına bağla
        tmp2->next = *head1;
        // Birinci listenin sonunu ikinci listenin başına bağla
        tmp1->next = head2;
    }
}

int main(){
    struct Node*birinci= yeniNode(5);
    struct Node*ikinci= yeniNode(15);
    birinci->next=ikinci;
    struct Node*ucuncu= yeniNode(25);
    ikinci->next=ucuncu;
    ucuncu->next=birinci;

    PrintList(birinci);

    BasaEkle(&birinci,4);
    PrintList(birinci);

    ArayaEkle(birinci,10,5);
    PrintList(birinci);

    SonaEkle(birinci,30);
    PrintList(birinci);

    BastanSil(&birinci);
    PrintList(birinci);

    AradanSil(birinci,10);
    PrintList(birinci);

    SondanSil(birinci);
    PrintList(birinci);

    printf("Liste uzunluk: %d\n", uzunluk(birinci));


    struct Node*bg1= yeniNode(50);
    struct Node*bg2= yeniNode(60);
    bg1->next=bg2;
    bg2->next=bg1;
    printf("Liste uzunluk: %d\n", uzunluk(bg1));

    bagla(&birinci,bg1);
    PrintList(birinci);
}

//TODO Tamamı doğru bu kısmın...