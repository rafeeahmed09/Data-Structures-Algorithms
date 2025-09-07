#include<iostream>
#include<deque>
#include<vector>
using namespace std;
class Deque1{
    vector<int> arr;
    int k;
public:
    Deque1(vector<int> nums, int window){
        arr = nums;
        k = window;
    }
    vector<int> maxsliding(vector<int> nums, int k){
        deque<int> dq;
        vector<int> res;

        for (int i = 0; i < k; i++)
        {
            while (dq.size() > 0 && nums[dq.back()] <= nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            
        }

        for (int i = k; i < nums.size(); i++)
        {
            res.push_back(nums[dq.front()]);

            // remove elements out of the current window
            while (dq.size() > 0 && dq.front() <= i-k)
            {
                dq.pop_front();
            }
             while (dq.size() > 0 && nums[dq.back()] <= nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            
        }
        
        res.push_back(nums[dq.front()]);
        return res;
    }

};

int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    Deque1 d(nums, k);
    vector<int> ans = d.maxsliding(nums, k);
    for (int x : ans)
    {
        cout<<x<<" ";

    }
    cout<<endl;

    return 0;
    
}