// Kuyruk.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 

typedef struct  {

    int rear, front, size;
    unsigned capacity;
    int* array;

}Queue;

int isFull(Queue *q) {

    return (q->size == q->capacity);
}

int isEmpty(Queue* q) {

    return (q->size == 0);
}

void enqueue(Queue* q, int item) {

    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->array[q->rear] = item;
    q->size++;
    printf("%d kuyruga eklendi\n",item);

}

int dequeue(Queue* q) {

    if (isEmpty(q)) {
        printf("Queue is empyt!\n");
        return INT_MIN;
    }
    int item= q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
  //  printf("%d kuyruktan çekildi\n", item);
    return item;

}

// Function to get front of queue 
int front(Queue* q)
{
    if (isEmpty(q))
        return INT_MIN;
    return q->array[q->front];
}

// Function to get rear of queue 
int rear(Queue* q)
{
    if (isEmpty(q))
        return INT_MIN;
    return q->array[q->rear];
}

Queue* createQueue(int capacity) {

    Queue* q = (Queue*)malloc(sizeof(Queue));
   
    q->size = 0;
    q->front = 0;
    q->capacity = capacity;
    q->array = (int*)malloc(q->capacity * sizeof(int));
    q->rear = q->capacity - 1;

    return q;
}

int main()
{
    Queue* queue = createQueue(1000);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("%d dequeued from queue\n\n", dequeue(queue));

    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));

    return 0;
}
// Programı çalıştır: Ctrl + F5 veya Hata Ayıkla > Hata Ayıklamadan Başlat menüsü
// Programda hata ayıkla: F5 veya Hata Ayıkla > Hata Ayıklamayı Başlat menüsü

// Kullanmaya Başlama İpuçları: 
//   1. Dosyaları eklemek/yönetmek için Çözüm Gezgini penceresini kullanın
//   2. Kaynak denetimine bağlanmak için Takım Gezgini penceresini kullanın
//   3. Derleme çıktısını ve diğer iletileri görmek için Çıktı penceresini kullanın
//   4. Hataları görüntülemek için Hata Listesi penceresini kullanın
//   5. Yeni kod dosyaları oluşturmak için Projeye Git > Yeni Öğe ekle veya varolan kod dosyalarını projeye eklemek için Proje > Var Olan Öğeyi Ekle adımlarını izleyin
//   6. Bu projeyi daha sonra yeniden açmak için Dosya > Aç > Proje'ye gidip .sln uzantılı dosyayı seçin
