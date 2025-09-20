#include <iostream>
using namespace std;
#define N 1000010
int sort[N];
int n;
int tem[N];
void merge_sort(int sort[], int left, int right)
{
	if (left >= right)return;
	int mid = (left + right) >> 1;
	merge_sort(sort,left,mid);
	merge_sort(sort, mid + 1, right);
	int k = 0, i = left, j = mid + 1;
	while (i <= mid && j <= right)
	{
		if (sort[i] <= sort[j])
		{
			tem[k++] = sort[i++];
		}
		else
		{
			tem[k++] = sort[j++];
		}
	}
	//左半部分还剩
	while (i <= mid)tem[k++] = sort[i++];
	//右半部分还剩
	while (j <= right)tem[k++] = sort[j++];
	
	//临时数组元素返回去
	for (int i = 0; i < n; i++)
	{
		sort[i] = tem[i];
	}

}
int main()
{

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> sort[i];
	}
	merge_sort(sort,0,n-1);
	for (int i = 0; i < n; ++i)
	{
		cout << sort[i];
	}
	cout << endl;
	return 0;
}