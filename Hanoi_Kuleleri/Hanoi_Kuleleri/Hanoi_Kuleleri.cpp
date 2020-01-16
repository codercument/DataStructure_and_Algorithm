// Hanoi_Kuleleri.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

// M(n) = M(n − 1) + 1+ M(n − 1) for n > 1.
//M(n) = 2M(n − 1) + 1 for n > 1, 
//M(1) = 1


//C(n) =2^n − 1.

#include <iostream>
using namespace std;
void hanoi(int n, char src, char dest, char aux);

int main()
{
	int numDisks = 1;
	while (true) {
		cout << "Hanoi Kuleleri! Disk Sayisini Girin:" << endl;
		cin >> numDisks;
		if (numDisks < 1) return 0;
		hanoi(numDisks, 'S', 'D', 'A');
	} 
	return 0;
}

void hanoi(int n, char src, char dest, char aux) {

	if (n > 1) {
		hanoi(n - 1, src, aux, dest);
		hanoi(1, src, dest,aux);
		hanoi(n - 1, aux, dest, src);
	}
	else {
		cout << src << " -> " << dest << endl;
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
