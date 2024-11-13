#include <stdio.h>
#include <stdlib.h>

struct stack{
    int top;
    unsigned capacity;
    int *array;
};

struct stack *createStack(unsigned capacity){
    struct stack *yeni= (struct stack*) malloc(sizeof (struct stack));
    yeni->capacity=capacity;
    yeni->top=-1;
    yeni->array=(int*)malloc(sizeof(int)*yeni->capacity);
    return yeni;
}

int isFull(struct stack *x){
    return x->top==x->capacity-1;//Capacity ise başta belirlediğimiz kapasitedir örn 14 fln //Top -1 ise yığıt boş //Top aşağıdan yukarı 01234 diye gider.// Array da aynı şekilde
}

int isEmpty(struct stack *x){
    return x->top==-1;
}

void Push(struct stack *x , int y){ //yığıta eleman koyma
    if (isFull(x)==1)
        return;
    x->array[++(x->top)]=y;
}

int Pop(struct stack *x){ //yığıttan eleman çıkarma
    if (isEmpty(x)==1)
        return -1;

    int alinan= x->array[x->top];
    x->top=x->top-1;
    return alinan;
}

void Fun(int n){
    struct stack S;
    while (n>0){
        Push(&S,n%2);
        n=n/2;
    }
    while (!isEmpty(&S)){
        printf("%d", Pop(&S));
    }
}

int main() {
    struct stack *yigit = createStack(5);

    printf("Yığıt Boş mu? : %d\n", isEmpty(yigit));//1 Demek boş demek, 0 demek dolu demek.
    printf("Yığıt Dolu mu? : %d\n", isFull(yigit));//1 Demek dolu demek, 0 demek boş demek.


    Push(yigit, 10);
    Push(yigit, 20);
    Push(yigit, 30);

    printf("Çıkarılan eleman: %d\n", Pop(yigit)); // 30
    printf("Çıkarılan eleman: %d\n", Pop(yigit)); // 20
    printf("Çıkarılan eleman: %d\n", Pop(yigit)); // 10
    printf("Çıkarılan eleman: %d\n", Pop(yigit)); // Yığıt boş, hata mesajı

    printf("Yığıt Dolu mu? : %d\n", isFull(yigit));//1 Demek dolu demek, 0 demek boş demek.


    free(yigit->array);
    free(yigit);
    return 0;
}

//TODO tamamı doğru