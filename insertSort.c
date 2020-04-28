#include "SORT.h"
void display(int arr[], int len){
	for (int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
/*
	时间复杂度：最坏时间复杂度,当数据逆序时O(n^2)；平均 O(n^2)；最好O(n)
	空间复杂度：只有几个临时变量O(1)
	稳定性：稳定
	数据敏感度：敏感
*/
void insertSort(int arr[], int len){
	// i ： 表示有序数据的最后一个位置
	for (int i = 0; i < len - 1; i++){
		// end 表示有序序列的最后一个位置
		int end = i;
		// 待插入数据，有序数据的最后位置的后一个位置
		int key = arr[end + 1];
		// 找到第一个 小于等于key 的位置
		while (end >= 0 && arr[end] > key){
			// 当前数据向后移动一个位置
			arr[end + 1] = arr[end];
			--end;
		}
		arr[end + 1] = key;
	}
}
void insert(int arr[], int len){
	for (int i = 1; i < len; i++){
		if (arr[i] < arr[i - 1]){
			int j = 0;
			int cur = arr[i];
			for (j = i - 1; j >= 0 && cur < arr[j]; j--){
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = cur;
		}
	}
}
void test(){
		int arr[] = { 34,0,43,5,79,19,57,164,87,9,16 };
		int len = sizeof(arr) / sizeof(arr[0]);
		insert(arr, len);
		display(arr, len);
}
void testTime(){
	srand(time(NULL));
	int n;
	scanf("%d", &n);
	int* array = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++){
		array[i] = rand();
	}
	size_t begin = clock();
	insertSort(array, n);
	size_t end = clock();
	printf("insertSort:>%d\n", end - begin);

	begin = clock();
	insertSort(array, n);
	end = clock();
	printf("after insertSort:>%d\n", end - begin);
}
int main(){
	testTime();
	//test();
	system("pause");
	return 0;
}