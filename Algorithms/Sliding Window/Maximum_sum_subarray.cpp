#include <iostream>
#include <vector>
using namespace std;
// Find the maximum sum of a subarray of size k using Brute Force.
class Deque1
{
    vector<int> arr;
    int k;

public:
    Deque1(vector<int> nums, int window)
    {
        arr = nums;
        k = window;
    }
    int findmax(int arr[], int k)
    {
        int maxsum = 0;
        int n = this->arr.size();
        for (int i = 0; i <= n - k; i++)
        {
            int sum = 0;
            for (int j = i; j < i + k; j++)
            {
                sum += arr[j];
            }
            maxsum = max(maxsum, sum);
        }
        return maxsum;
    }
};

int main()
{
    vector<int> nums = {2, 1, 5, 1, 3, 2};
    int k = 3;
    Deque1 d(nums, k);
    cout << "Maximum sum of a subarray of size k is => " << d.findmax(nums.data(), k) << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Find the maximum sum of a subarray of size k using Optimal Approach sliding Window time complexity o(n) and space complexity o(k).

int maxSubarraySum(vector<int>& arr, int k) {
    int n = arr.size();
    queue<int> q;
    int sum = 0, maxSum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        q.push(arr[i]);

        // maintain window of size k
        if (q.size() > k) {
            sum -= q.front();
            q.pop();
        }

        // update maximum when window size becomes k
        if (q.size() == k) { 
            maxSum = max(maxSum, sum);
        }
    }

    return maxSum;

        

    
};

int main() {
    vector<int> nums = {2,1,5,1,3,2};
    int k = 3;
    cout<< maxSubarraySum(nums, k)<<endl;

    return 0;
}