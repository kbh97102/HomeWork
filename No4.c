//(4) 정렬이 안된 수들 중 k번째로 작은 수를 반환하는 함수를 만드시오.전체 데이터를 정렬하지  말고 하시오. (수업시간 중 알고리즘 설명)

#include <stdio.h>

#define MAXARR 9
#define ORDER_K 3

//quick selection


int select(int *arr, int left, int right,int k) {
	if (left == right) {
		return arr[left];
	}
	int split;
	split = partition(arr, left, right);
	int length;
	length = split - left + 1;
	if (length == k) {
		return arr[split];
	}
	else if (k < length) {
		return select(arr, left, split - 1, k);
	}
	else {
		return select(arr, split + 1, k - length, k);
	}
}
int partition(int* arr, int left, int right) {
	int pivot = arr[left];
	int leftMark = left + 1;
	int rightMark = right;
	int temp;
	while (1) {
		while (leftMark < right && arr[leftMark] < pivot) {
			leftMark++;
		}
		while (rightMark > left && arr[rightMark] > pivot) {
			rightMark--;
		}
		if (leftMark >= rightMark) {
			break;
		}
		else {
			temp = arr[leftMark];
			arr[leftMark] = arr[rightMark];
			arr[rightMark] = temp;
		}
	}
	temp = arr[left];
	arr[left] = arr[rightMark];
	arr[rightMark] = temp;
	return rightMark;
}
int main() {
	
	int notSortedArr[MAXARR] = {7,2,4,1,6,5,3,9,8};
	int test;
	test = select(&notSortedArr, 0, 8, 3);
	printf("%d", test);

	return 0;
}