// LinkedList_In_C.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>

typedef struct Node_  {

    int veri;
    struct Node_* next;
}Node;

Node *head = NULL;
Node* last = NULL;

int count = 0;

void insert_at_begin(int);
void insert_at_end(int);
void traverse();
void delete_from_begin();
void delete_from_end();

int main()
{
    int i, data;

    for (;;) {
        printf("1. Insert an element at the beginning of linked list.\n");
        printf("2. Insert an element at the end of linked list.\n");
        printf("3. Traverse linked list.\n");
        printf("4. Delete an element from beginning.\n");
        printf("5. Delete an element from end.\n");
        printf("6. Exit\n");

        scanf("%d", &i);    
        
        if (i == 1) {
            printf("Enter value of element\n");
            scanf("%d", &data);
            insert_at_begin(data);
        }
        else if (i == 2) {
            printf("Enter value of element\n");
            scanf("%d", &data);
            insert_at_end(data);
        }
        else if (i == 3)
            traverse();
        else if (i == 4)
            delete_from_begin();
        else if (i == 5)
            delete_from_end();
        else if (i == 6)
            break;
        else
            printf("Please enter valid input.\n");


    }
}

void insert_at_begin(int x) {

    Node* node = (Node*)malloc(sizeof(Node));
   
    if (node == NULL)
        return;
   
    node->veri = x;
    count++;

    if (head == NULL) {

        head = node;
        head->next = NULL;
        last = head;
        last->next = NULL;
        return;
    }

    node->next = head;
    head = node;

    return;

}

void insert_at_end(int x) {

    Node* node;

    node = (Node*)malloc(sizeof(Node));
    if (node == NULL)
        return;

    node->veri = x;

    count++;

    if (head == NULL) {
        head = node;
        head->next = NULL;
        last = head;
        last->next = NULL;
        return;
    }

    last->next = node;
    last = node;
    last->next = NULL;
    return;

}

void traverse() {

    Node* t = head;

    if (t == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    printf("There are %d elements in linked list.\n", count);

    while (t->next != NULL) {
        printf("%d\n", t->veri);
        t = t->next;
    }
    printf("%d\n", t->veri); // Print last node
}

void delete_from_begin() {

    Node* t;
    int n;

    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    n = head->veri;
    t = head->next;
    free(head);
    head = t;
    count--;

    printf("%d deleted from the beginning successfully.\n", n);
}
void delete_from_end() {

    Node* t, * u;
    int n;

    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    count--;

    if (head->next == NULL) {
        n = head->veri;
        free(head);
        head = NULL;
        printf("%d deleted from end successfully.\n", n);
        return;
    }

    Node* second_last = head;

    while (second_last->next->next != NULL)
        second_last = second_last->next;

    n = second_last->veri;

    free(second_last->next);
    second_last->next = NULL;
    last = second_last;

    printf("%d deleted from end successfully.\n", n);
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
