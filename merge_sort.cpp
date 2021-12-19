#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void merge_sort(vector<int>& nums) {
        vector<int> temp(nums.size()); // 使用temp避免多次创建
        _merge_sort(0, nums.size()-1, nums, temp);
    }

private:
    void _merge_sort(int left, int right, vector<int>& nums, vector<int>& temp) {
        if (left >= right){
            return;
        }
        int mid = left + (right - left) / 2;
        _merge_sort(left, mid, nums, temp);
        _merge_sort(mid+1, right, nums, temp);
        _merge(left, mid, right, nums, temp);
    }

    void _merge(int left, int mid, int right, vector<int>& nums, vector<int>& temp){
        int i = left;
        int j = mid+1;
        int pos = left;
        while (i <= mid && j <= right){
            if (nums[i] <= nums[j]){
                temp[pos++] = nums[i++];
            } else{
                temp[pos++] = nums[j++];
            }
        }
        while (i <= mid){
            temp[pos++] = nums[i++];
        }
        while (j <= right){
            temp[pos++] = nums[j++];
        }
        for (int index = left; index <= right; ++index){
            nums[index] = temp[index];
        }
    }
};

int main(){
    Solution s;
    vector<int> vec = {7, 5, 10, 1, 4, 6, 20, 18, 6, 4};
    s.merge_sort(vec);
    for (auto it = vec.cbegin(); it != vec.cend(); ++it){
        cout << *it << " ";
    }
}