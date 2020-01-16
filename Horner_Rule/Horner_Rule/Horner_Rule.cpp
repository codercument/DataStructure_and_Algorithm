// Horner_Rule.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//
//ALGORITHM Horner(P[0..n], x)
//Evaluates a polynomial at a given point by Horner’s rule
//Input: An array P[0..n] of coefficients of a polynomial of degree n,
// stored from the lowest to the highest and a number x
//Output: The value of the polynomial at x
//p←P[n]
//for i ←n − 1 downto 0 do
//p←x ∗ p + P[i]
//return p
// O(n)
#include <iostream>
using namespace std;

int main()
{
    std::cout << "Horner Rule!" << endl;

	int P[] = { -5, 1, 3, -1, 2 };
	int x = 3;
	int i = 0;
	int N = sizeof(P) / sizeof(int);
	int p = P[N - 1];

	for (i = N - 2; i >= 0; i--) {

		p = p * x + P[i];
	}

	cout << "Sonuc: " << p << endl;
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
