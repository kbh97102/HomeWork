#include <stdio.h>
#include <string.h>

#define MAXDATA	20
#define MAXKEY 20
typedef struct {
	int id;
	char key[MAXKEY];
}element;

typedef struct {
	element data[MAXDATA];
	int heapSize;
}Heap;

void HeapDisplay(Heap* heap) {
	for (int i = 0; i < heap->heapSize; i++) {
		printf("index = %d, data = %s, id = %d\n", i, heap->data[i].key, heap->data[i].id);
	}
	printf("\n");

}

void HeapInit(Heap* heap) {
	heap->heapSize = 0;
	for (int i = 0; i < MAXDATA; i++) {
		memset(heap->data[i].key, NULL, sizeof(char));
		heap->data[i].id = 0;
	}
}

void swap(Heap* heap, int index1, int index2) {
	char *temp = (char*)malloc(sizeof(char)* MAXKEY);
	int idTemp;
	strcpy(temp, heap->data[index1].key);
	strcpy(heap->data[index1].key, heap->data[index2].key);
	strcpy(heap->data[index2].key, temp);
	idTemp = heap->data[index1].id;
	heap->data[index1].id = heap->data[index2].id;
	heap->data[index2].id = idTemp;
}
void HeapInsert(char *value, int id, Heap* heap) {

	int parentIndex = 0;
	int childIndex = 0;

	
	while (childIndex < MAXDATA) {

		if (heap->data[0].id == NULL) {
			strcpy(heap->data[0].key, value);
			heap->data[0].id = id;
			printf("index = %d, key = %s, id = %d\n", heap->heapSize, heap->data[0].key, heap->data[0].id);
			heap->heapSize++;
			break;
		}
		if (parentIndex == 0) {
			childIndex = 1;
		}
		if (heap->data[childIndex].id == NULL) {
			strcpy(heap->data[childIndex].key, value);
			heap->data[childIndex].id = id;
			printf("index = %d, key = %s, id = %d\n", heap->heapSize, heap->data[heap->heapSize].key, heap->data[heap->heapSize].id);
			heap->heapSize++;
			break;
		}
		else if (heap->data[childIndex+1].id == NULL) {
			strcpy(heap->data[childIndex + 1].key, value);
			heap->data[childIndex + 1].id = id;
			printf("index = %d, key = %s, id = %d\n", heap->heapSize, heap->data[heap->heapSize].key, heap->data[heap->heapSize].id);
			heap->heapSize++;
			break;
		}
		else {
			parentIndex++;
			childIndex = parentIndex * 2 + 1;
		}
	}
}

void HeapBuild(Heap* heap) {
	int childIndex = 0;
	int parentIndex;
	int judge;// -1 �ι�° ���� ��ũ�� 0 �Ѵ� ���� 1 ù��°�� ũ��
	for (int i = 0; i < heap->heapSize; i++) {
		childIndex = i;
		do {
			if (childIndex <= 2) {
				parentIndex = 0;
			}
			else {
				parentIndex = childIndex / 2;
			}
			judge = strcmp(heap->data[childIndex].key, heap->data[parentIndex].key);
			if (judge == 1) {
				printf("�θ�(%s)�� �ڽ�(%s)�� ��ġ�� �ٲ۴�.\n", heap->data[parentIndex].key, heap->data[childIndex].key);
				swap(heap, childIndex, parentIndex);
				HeapDisplay(heap);
			}
			childIndex = parentIndex;
		} while (childIndex != 0);
	}
}

void HeapDeleteById(Heap* heap, int deleteId) {
	
	int deleteIndex=0;
	int deleteChildIndex;

	int lastDataIndex;
	for (int i = 0; i < heap->heapSize; i++) {
		if (heap->data[i].id == deleteId) {
			deleteIndex = i;
			break;
		}
	}
	//���� �� ���� Ʈ���� �� �Ʒ��� �ִ� ��� == �ڽ��� ����. == �� ������ �������� �ʴ´�
	deleteChildIndex = deleteIndex * 2 + 1;
	if (heap->data[deleteChildIndex].id == NULL && heap->data[deleteChildIndex + 1].id == NULL) {
		heap->data[deleteIndex].id = NULL;
		memset(heap->data[deleteIndex].key, NULL, sizeof(char));
		heap->heapSize--;
	}
	//�� ������ ��Ű�����ؼ� �� ��������带 �����;� �Ѵ�.
	else {
		lastDataIndex = heap->heapSize - 1;
		heap->data[deleteIndex].id = heap->data[lastDataIndex].id;
		strcpy(heap->data[deleteIndex].key, heap->data[lastDataIndex].key);
		heap->data[lastDataIndex].id = NULL;
		memset(heap->data[lastDataIndex].key, NULL, sizeof(char));
		heap->heapSize--;
		//������ �� ������ �ٽ� ����
		HeapBuild(heap);
	}
}
int main() {
	Heap* heap = (Heap*)malloc(sizeof(Heap));

	HeapInit(heap);
	HeapInsert("a", 1234, heap);
	HeapInsert("b", 3214, heap);
	HeapInsert("c", 5123, heap);
	HeapInsert("d", 9999, heap);
	
	HeapBuild(heap);
	printf("Heap Complete\n");
	HeapDisplay(heap);
	printf("9999���� id�� ���� ������ ����\n");
	HeapDeleteById(heap, 9999);
	printf("Heap Complete\n");
	HeapDisplay(heap);

	return 0;
}