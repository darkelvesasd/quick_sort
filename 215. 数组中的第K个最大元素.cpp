class Solution {
public:void Swap(int *a,int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int quick_sort(vector<int>&arr,int left,int right,int k)
{
	if (left == right)
	{
		return arr[left];
	}
	srand(time(NULL));
	int x = arr[rand() % (right - left + 1) + left];
	int l = left-1;
	int r = right+1;
	int i = left;
	while (i<r)
	{
		if (arr[i] < x)
		{
			Swap(&arr[++l], &arr[i++]);
		}
		else if (arr[i] > x)
		{
			Swap(&arr[--r],&arr[i]);
		}
		else
		{
			i++;
		}
	}
	 if (k > l && k < i)
	{
		return arr[i - 1];
	}
	 else if (k >= i)
	 {
		 return quick_sort(arr, r, right,k);
	 }
	else
	{
		return quick_sort(arr, left, l,k);
	}
}
    int findKthLargest(vector<int>& nums, int k) {
        return quick_sort(nums, 0, nums.size() - 1,nums.size()- k);
    }
};
