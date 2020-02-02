// HeapSort.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>

#define PARENT(i) i>>1
#define LEFT(i) i<<1 
#define RIGHT(i) (i<<1) + 1 

#define HEAPSIZE(A) (sizeof(A)/sizeof(int))-1

void MAX_HEAPFY(int A[], int index,int heapsize) {

    int l, r, largest;
    int tmp;

 //   int heapsize = HEAPSIZE(A);

    l = LEFT(index);
    r = RIGHT(index);

    if (l <= heapsize && A[l] > A[index])
        largest = l;
    else largest = index;

    if (r <= heapsize && A[r] > A[largest])
        largest = r;

    if (largest != index) {
        tmp = A[index];
        A[index] = A[largest];
        A[largest] = tmp;
        MAX_HEAPFY(A, largest, heapsize);
    }

    
}


void BUILD_MAX_HEAPFY(int* A, int heapsize) {

   // int heapsize = HEAPSIZE(A);
    int i = 0;

    for (i = heapsize / 2; i > 0; i-- ) {

        MAX_HEAPFY(A,i,heapsize);
    }

}

void HEAPSORT(int* A,int heapsize) {

    int i,tmp;
  //  int heapsize = HEAPSIZE(A);
    int heapsize_ = heapsize;
    BUILD_MAX_HEAPFY(A,heapsize);

    for (i = heapsize; i > 1;i--) {
        tmp = A[1];
        A[1] = A[i];
        A[heapsize_] = tmp;
        heapsize_--;
        MAX_HEAPFY(A, 1, heapsize_);

        
    }
}

int main()
{
    int A[11] = { -1,2,4,1,10,9,3,17,8,16,27 };
    std::cout << "HEAP SORT!\n";
    std::cout << "BEFORE HEAPSORT:\n";
    
    for (int i = 1; i <= HEAPSIZE(A); i++) {

        printf("%d ",A[i]);
    }

    HEAPSORT(A,HEAPSIZE(A));

    std::cout << "\nAFTER HEAPSORT:\n";

    for (int i = 1; i <= HEAPSIZE(A); i++) {

        printf("%d ", A[i]);
    }

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
