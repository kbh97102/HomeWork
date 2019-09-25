#include <stdio.h>
#define MAX_ELEMENT 100

typedef struct {
	int key;
}element;

typedef struct {
	element heap[MAX_ELEMENT+1];
	int heap_size;
}HeapType;

void init(HeapType* h)
{
	for (int i = 0; i <= MAX_ELEMENT; i++) {
		h->heap[i].key = 0;
	}
	h->heap_size = 0;
}
void insert_max_heap(HeapType* h, element item)
{
	int childIndex;
	
	childIndex = ++(h->heap_size);
	
	while ((childIndex != 1) && (item.key > h->heap[childIndex / 2].key)) {
		h->heap[childIndex] = h->heap[childIndex / 2];
		childIndex /= 2;
	}
	h->heap[childIndex] = item;
}

element delete_max_heap(HeapType* h)
{
	//최대값 제거 == 첫번째 인덱스의값
	element deletedData;
	deletedData = h->heap[1];
	//힙 구조를 지키기위해 맨마지막값을 가져오고 힙 구조를 다시 생성한다.
	h->heap[1] = h->heap[h->heap_size];
	h->heap[h->heap_size].key = NULL;
	h->heap_size--;
	int childIndex = 0;
	int parentIndex;
	for (int i = 2; i <= h->heap_size; i++) {
		childIndex = i;
		do {
			
			parentIndex = childIndex / 2;
			
			if (h->heap[childIndex].key > h->heap[parentIndex].key) {
				element temp;
				temp = h->heap[childIndex];
				h->heap[childIndex] = h->heap[parentIndex];
				h->heap[parentIndex] = temp;
			}
			childIndex = parentIndex;
		} while (childIndex != 1);
	}
	return deletedData;
}

void print_heap(HeapType* h)
{
	for (int i = 1; i <= h->heap_size; i++)
		printf("<%d >", h->heap[i].key);
	printf("\n");
}


void delete_element(HeapType * h, int number)
{ // number를 key로 갖는 element를 삭제한다. 삭제 후에 max heap이 유지되어야 한다
	//위에서 했던 max값을 지우는 방법에서 max대신 알맞는 값의 위치를 찾으면된다
	int deleteIndex;
	for (int i = 1; i <= h->heap_size; i++) {
		if (h->heap[i].key == number) {
			deleteIndex = i;
			break;
		}
	}
	h->heap[deleteIndex] = h->heap[h->heap_size];
	h->heap[h->heap_size].key = NULL;
	h->heap_size--;
	int childIndex = 0;
	int parentIndex;
	for (int i = 2; i <= h->heap_size; i++) {
		childIndex = i;
		do {

			parentIndex = childIndex / 2;

			if (h->heap[childIndex].key > h->heap[parentIndex].key) {
				element temp;
				temp = h->heap[childIndex];
				h->heap[childIndex] = h->heap[parentIndex];
				h->heap[parentIndex] = temp;
			}
			childIndex = parentIndex;
		} while (childIndex != 1);
	}
}

void main()
{
	element e[9] = { {10},{40},{30},{5},{12},{6},{15},{9},{60} };
	HeapType heap1;
	int i;
	element a;
	init(&heap1);
	for (i = 0; i < 9; i++)
		insert_max_heap(&heap1, e[i]);
	print_heap(&heap1);
	int num = 40;

	
	delete_element(&heap1, num);
	print_heap(&heap1);
	//max heap인지 체크하는 과정   값이 큰 순서대로 출력되어야 한다
	for (i = 0; i < 8; i++) {
		a = delete_max_heap(&heap1);
		printf("%d ", a.key);
	}
}