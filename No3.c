#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
#define MAX_ARR 15
#define DEGREE 3
typedef struct {
	int key;
}element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void init(HeapType* h)
{
	for (int i = 0; i < MAX_ELEMENT; i++) {
		h->heap[i].key = NULL;
	}
	h->heap_size = 0;
}

//left_child of i=i*k-(k-2)
//parent index of l=(l+k-2)/k

void insert_max_heap(HeapType* h, element item, int k)
{
	//k-max-heap(�ڽ��� k���� ���� k-nary tree�� �̿��� heap))�� �ǵ��� �ڷḦ          //�Է�
	int childIndex = ++(h->heap_size);
	if (h->heap[1].key == NULL) {
		h->heap[1] = item;
		return;
	}
	while (childIndex != 1 && item.key > h->heap[(childIndex+k-2)/k].key) {
		h->heap[childIndex] = h->heap[(childIndex + k - 2) / k];
		childIndex = ((childIndex + k - 2) / k);
	}
	h->heap[childIndex] = item;
}
int max_num(element heap[], int start, int number)
{
	//heap�� start���� number �� ��ŭ�� ���� �� ���� key�� ū ������ index�� ��ȯ�ϴ�.
	int maxNumIndex = start;
	
	for (int i = start; i < number-1; i++) {
		for (int j = i; j < number-1; j++) {
			if (heap[j].key > heap[j + 1].key) {
				maxNumIndex = j;
			}
		}
	}
	
	return maxNumIndex;
}
element delete_max_heap(HeapType* h, int k)
{
	//k-max-heap���� ���� key�� ū ���Ҹ� ��ȯ�Ѵ�. ��ȯ �� k-max-heap�� �����Ѵ�. ���� max_num�Լ��� �̿�
	int maxNumIndex = max_num(h->heap,1,MAX_ELEMENT);
	int childIndex = 0;
	int parentIndex;
	element maxElement;
	maxElement = h->heap[maxNumIndex];
	h->heap[maxNumIndex] = h->heap[h->heap_size];
	h->heap[h->heap_size].key = NULL;
	h->heap_size--;
	
	for (int i = 2; i <= h->heap_size; i++) {
		childIndex = i;
		do {

			parentIndex = (childIndex+DEGREE-2)/DEGREE;

			if (h->heap[childIndex].key > h->heap[parentIndex].key) {
				element temp;
				temp = h->heap[childIndex];
				h->heap[childIndex] = h->heap[parentIndex];
				h->heap[parentIndex] = temp;
			}
			childIndex = parentIndex;
		} while (childIndex != 1);
	}
	return maxElement;
}
void print_heap(HeapType* h)
{
	for (int i = 1; i <= h->heap_size; i++)
		printf("<%d >", h->heap[i].key);
	printf("\n");
}
void heap_sort(element a[], int n, int k)
{ //k-max-heap�� �̿��Ͽ� �����Ѵ�.
	int i;
	HeapType h;
	init(&h);
	for (i = 0; i < n; i++) {
		insert_max_heap(&h, a[i], k);
	}
	print_heap(&h);
	for (i = n - 1; i >= 0; i--) {
		a[i] = delete_max_heap(&h, k);
		print_heap(&h);
	}
}


void main()
{
	element intArr[MAX_ARR] = {2,3,1,5,6,4,8,9,7,10,15,16,13,87,49 };
	heap_sort(intArr, MAX_ARR, DEGREE);
	//������ 10�̻��� ���� ���� ���� ������ �迭�� ���� heap_sort�� �̿��Ͽ� 
 //�����Ͻÿ�. k���� ���� ���� ���� �ؼ� test�� ���ÿ�.

}
