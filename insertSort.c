#include "SORT.h"
void display(int arr[], int len){
	for (int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
/*
	ʱ�临�Ӷȣ��ʱ�临�Ӷ�,����������ʱO(n^2)��ƽ�� O(n^2)�����O(n)
	�ռ临�Ӷȣ�ֻ�м�����ʱ����O(1)
	�ȶ��ԣ��ȶ�
	�������жȣ�����
*/
void insertSort(int arr[], int len){
	// i �� ��ʾ�������ݵ����һ��λ��
	for (int i = 0; i < len - 1; i++){
		// end ��ʾ�������е����һ��λ��
		int end = i;
		// ���������ݣ��������ݵ����λ�õĺ�һ��λ��
		int key = arr[end + 1];
		// �ҵ���һ�� С�ڵ���key ��λ��
		while (end >= 0 && arr[end] > key){
			// ��ǰ��������ƶ�һ��λ��
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