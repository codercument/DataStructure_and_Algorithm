// BinarySearch.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

//ALGORITHM BinarySearch(A[0..n − 1], K)
//Implements nonrecursive binary search
//Input: An array A[0..n − 1] sorted in ascending order and
// a search key K
//Output: An index of the array’s element that is equal to K
// or −1 if there is no such element
//l←0; r ←n − 1
//while l ≤ r do
//m←(l + r) / 2
//if K = A[m] return m
//else ifK < A[m] r ←m − 1
//else l← m + l
//return −1

// C(n) = logn

#include <iostream>;
using namespace std;

int main()
{
	int K1 = 31, K2 = 40;
	int a[] = {1,3,5,17,21,31,33,44,65,80};
    cout << "Binary Search is Beginnig!" << endl;

	int l = 0;
	int r = (sizeof(a) / sizeof(a[0])) - 1;
	int m = 0;
	while (l <= r) {
	
		m = (l + r) / 2;
		if (K2 == a[m]) {
			cout << "Search is successful and index: " << m << endl;
			return m;
		}
		else if (K1 < a[m])
			r = m - 1;
		else l = m + 1;
	}
	std::cout << "Search is unsuccessful !" << endl;
	return -1;



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
