class Solution {
public:
void Swap(int *a,int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void quick_sort(vector<int>&nums, int left, int right, int n)
{
	if (left >= right)
	{
		return;
	}
	int l = left - 1;
	int r = right + 1;
	int i = left;
	int x = nums[rand() % (right - left + 1) + left];
	while (i < r)
	{
		if (nums[i] < x)
		{
			Swap(&nums[i++], &nums[++l]);
		}
		else if (nums[i] > x)
		{
			Swap(&nums[i],&nums[--r]);
		}
		else
		{
			i++;
		}
	}
	if (n - 1 <= l)
	{
		quick_sort(nums,left,l,n);
	}
	else if (n - 1 > l && n - 1 < i)
	{
		return ;
	}
	else
	{
		quick_sort(nums, r, right, n);
	}
}
    vector<int> inventoryManagement(vector<int>& stock, int cnt) {
	srand(time(NULL));
	vector<int>ret;
	quick_sort(stock, 0, stock.size()-1, cnt);
	for (int i=0;i<cnt;i++)
	{
		ret.push_back(stock[i]);
	}
	return ret;
    }
};
