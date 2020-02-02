// BinaryTree.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
using namespace std;

typedef struct node_t {

    int data;
    struct node_t *sol;
    struct node_t* sag;

}Node;

Node *root = NULL;

Node* New_Node() {

    Node* new_node =(Node*) malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("Node hatasi\n");
        return NULL;
    }

    printf("Veri Girin:");
    scanf("%d",&(new_node->data));
    new_node->sag = NULL;
    new_node->sol = NULL;

    return new_node;
}

Node* New_Node_withvalue(int value) {

    Node* new_node = (Node*)malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("Node hatasi\n");
        return NULL;
    }

    new_node->data = value;
    new_node->sag = NULL;
    new_node->sol = NULL;

    return new_node;
}

void Insert_Node(Node * head,Node * node) {

    if (root == NULL) {

        root = node;
    }
    else {
        if (head->data > node->data) {
            if (head->sol == NULL)
                head->sol = node;
            else
                Insert_Node(head->sol,node);
        }
        else if (head->data < node->data) {
            if (head->sag == NULL)
                head->sag = node;
            else
                Insert_Node(head->sag, node);
        }
    }
}

void pre_Order(Node *node) {
    
    if (node != NULL) {
        printf("%d\n",node->data);
        pre_Order(node->sol);
        pre_Order(node->sag);

    }
    
}

void post_Order(Node* node) {

    if (node != NULL) {
        post_Order(node->sol);
        post_Order(node->sag);
        printf("%d\n", node->data);

    }

}

void in_Order(Node* node) {

    if (node != NULL) {
        in_Order(node->sol);
        printf("%d\n", node->data);
        in_Order(node->sag);
        
    }

}

Node* Search(int value) {

    Node* pnode = root;

    while (pnode != NULL && pnode->data != value )
    {
        if (pnode->data > value)
            pnode = pnode->sol;
        else  pnode = pnode->sag;
    }


    return pnode;

}

int main()
{
    std::cout << "Binary Searh Tree!\n";
    char secim;
    Node *new_node, *pn;
    int veri;

    int test[] = {9,5,2,7,23,15,12,29,25,33};

    while (1) {

        puts("\nEkleme:E|e\nListeleme:L|l\nArama:A|a\nSilme:S|s\nMiktar:M|m\nTest:T|t\nCikis:X|x");
        cin >> secim;
        
        switch (secim)
        {
        case 'E': case 'e' :
            new_node = New_Node();
            if (new_node)
                Insert_Node(root, new_node);

            break;
        case 'L': case 'l':
            if (root != NULL) {
                printf("InOrder: i, PostOrder: p, PreOrder: r\n");
                char l;
                cin >> l;
                
                switch (l)
                {
                case 'i':
                    in_Order(root);
                    break;
                case 'p':
                    post_Order(root);
                    break;
                case 'r':
                    pre_Order(root);
                    break;
                default:

                    pre_Order(root);
                    break;
                }
            }                  
            else printf("Bos Agac!\n");
            break;
        case 'T' : case 't':
            for (int i = 0; i < sizeof(test) / sizeof(int); i++) {
                new_node = New_Node_withvalue(test[i]);
                if (new_node)
                    Insert_Node(root, new_node);
            }
            break;
        case 'A': case 'a':

            printf("Aranacak veriyi girin:\n");
            scanf("%d",&veri);
            pn = Search(veri);
            if (pn) {

                printf("Deger : %d bulundu\n",pn->data);
            }

            break;
        case 'X' : case 'x':

            return 0;
        default:
            printf("...\n");
            break;
        }
    }
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
