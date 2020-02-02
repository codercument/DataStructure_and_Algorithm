// Stack_in_C.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>

struct Stack {

	int top;
	int capacity;
	int* array;

};

int isFull(struct Stack *s) {

	return s->top == s->capacity - 1;
}

int isEmpty(struct Stack *s) {

	return s->top == -1;
}

int peek(struct Stack *s) {

	if (isEmpty(s))
		return INT_MIN;
	else return s->array[s->top];

}

int pop(struct Stack *s) {

	if (isEmpty(s))
		return INT_MIN;
	else return s->array[s->top--];

}

void push(struct Stack* s, int item) {

	if (isFull(s)) {
		printf("Stack is Full\n");
		return;
	}
		
	s->array[++s->top] = item;
	printf("%d pushed to stack\n", item);

}

struct Stack *createStack (int capacity){

	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->top = -1;
	stack->capacity = capacity;
	stack->array = (int*)malloc(sizeof(stack->capacity*sizeof(int)));

	return stack;
}

int main()
{
	struct Stack* stack = createStack(100);

	std::cout << "Stack Examole in C\n";

	push(stack, 10);
	push(stack, 20);
	push(stack, 30);

	std::cout << std::endl;
	std::cout << std::endl;

	printf("%d popped from stack\n", pop(stack));
	printf("%d popped from stack\n", pop(stack));
	printf("%d popped from stack\n", pop(stack));



    
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
