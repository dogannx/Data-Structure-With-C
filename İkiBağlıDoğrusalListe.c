#include <stdio.h>
#include <stdlib.h>

/*void SondanSil2(struct Node *head) {//free yapınca  sonu Null yapmamamızdan kaynaklı oluşan durumu önlemek için
    struct Node *tmp =head;
    struct Node *tmp2;
    while (tmp->next!=NULL)
        tmp=tmp->next;
    tmp2=tmp->prev->next;
    free(tmp);
}// TODO burayıda bir sor. Çalışıyor ama boşver.*/

/*void Donustur(struct Node * head, int x) {
    struct Node *tmp;
    int uzunluk=say(head);
    if (say % 2==1){
        tmp=head;
        while (tmp!=NULL){
           tmp->prev=NULL;
           tmp=tmp->next;
        }
    } else{
        tmp=head;
        while (tmp->next!=NULL)
            tmp=tmp->next;
        tmp->next=head;
        head->prev=tmp;
    }
}*/ //TODO chatgpt'ye sor bunuda...

/*void AradaykenOncekiAdresiSil(struct Node * head, int x) {
    struct Node *tmp =head;
    struct Node *silinecek;

    // Değeri x olan düğümü bul
    while (tmp != NULL && tmp->data != x) {
        tmp = tmp->next;
    }
    silinecek=tmp->prev;
    // Bağlantıları güncelle
    if (silinecek->prev != NULL) {
        silinecek->prev->next = tmp;
        tmp->prev = silinecek->prev;
    } else {
        // Eğer silinecek düğüm listenin başındaysa
        tmp->prev = NULL;
        head = tmp;
    }

    free(silinecek);
} //TODO burada hata var bir bak. Çalışmıyor.*/



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

void printList(struct Node*head) {
    if (head == NULL) {
        printf("Liste bos.\n");
        return;
    }

    struct Node* tmp = head;
    do {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    } while (tmp != NULL);

    printf("\n");
}

// Listeye baştan ekleme fonksiyonu
void BasaEkle(struct Node ** head, int x) {
    struct Node *yeni = yeniNode(x);
    yeni->next = *head;
    (*head)->prev=yeni;
    (*head) =yeni;
}

void ArayaEkle(struct Node * head, int EklenecekSayi, int ListedeOlanSayi) {
    struct Node *yeni = yeniNode(EklenecekSayi);
    struct Node *tmp =head;
    while (tmp->data!= ListedeOlanSayi)
        tmp=tmp->next;
    yeni->prev=tmp;
    yeni->next=tmp->next;
    tmp->next=yeni;
    tmp->next->prev=yeni;
}

void SonaEkle(struct Node * head, int x) {
    struct Node *yeni = yeniNode(x);
    struct Node *tmp =head;
    while (tmp->next!=NULL)
        tmp=tmp->next;
    tmp->next=yeni;
    yeni->prev=tmp;
}



void BastanSil(struct Node **head) {
    struct Node *tmp = *head;
    *head =tmp->next;
    tmp->next->prev=NULL;
    free(tmp);
}

void AradanSil(struct Node * head, int Silinecek) {
    struct Node *tmp =head;
    while (tmp->data!=Silinecek)
        tmp=tmp->next;
    tmp->prev->next=tmp->next;
    tmp->next->prev=tmp->prev;
    free(tmp);
}

void SondanSil(struct Node *head) {
    struct Node *tmp =head;
    while (tmp->next!=NULL)
        tmp=tmp->next;
    tmp->prev->next=NULL;
    free(tmp);
}

struct Node* Klonla(struct Node *head1) {
    // İlk düğümü oluştur
    struct Node *yeniHead = yeniNode(head1->data);
    struct Node *tmp = head1->next;
    struct Node *yeniTmp = yeniHead;

    // Geri kalan düğümleri oluştur
    while (tmp != NULL) {
        // Yeni düğüm oluştur
        struct Node *yeniDugum = yeniNode(tmp->data);

        // Çift yönlü bağlantıları kur
        yeniTmp->next = yeniDugum;
        yeniDugum->prev = yeniTmp;

        // İlerle
        tmp = tmp->next;
        yeniTmp = yeniTmp->next;
    }

    return yeniHead;
}//Üzerine düşünmedim...



int main() {
    struct Node*birinci= yeniNode(5);
    struct Node*ikinci= yeniNode(10);
    birinci->next=ikinci;
    ikinci->prev=birinci;
    struct Node*ucuncu= yeniNode(15);
    ikinci->next=ucuncu;
    ucuncu->prev=ikinci;

    printList(birinci);

    BasaEkle(&birinci,3);
    printList(birinci);

    ArayaEkle(birinci,13,10);
    printList(birinci);

    SonaEkle(birinci,20);
    printList(birinci);

/*    BastanSil(&birinci);
    printList(birinci);

    AradanSil(birinci,10);
    printList(birinci);

    SondanSil(birinci);
    printList(birinci);

    SondanSil2(birinci);
    printList(birinci);*/

    struct Node *liste2 = Klonla(birinci);
    printList(liste2);

    return 0;
}
