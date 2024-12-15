#include <vector>
#include <iostream>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Step 1: Initialize two pointers: actual_Index to track where we will place the modified elements
        // and index to iterate through the original array.
        int actual_Index = 0, index = 0, n = nums.size();

        // Step 2: Iterate through the array while the index is less than the length of the array
        while (index < n) {
            // Step 3: Place the current element at actual_Index and move actual_Index forward
            nums[actual_Index] = nums[index];
            ++actual_Index;  // Increment actual_Index to point to the next available position

            // Step 4: If the next element is the same as the current element, place it again at actual_Index
            if (index + 1 < n && nums[index] == nums[index + 1]) {
                nums[actual_Index] = nums[index];  // Place the duplicate element
                ++actual_Index;  // Move actual_Index forward
            }

            // Step 5: Skip all the duplicate elements by finding the next unique element
            int tempIndex = index + 1;
            while (tempIndex < n && nums[tempIndex] == nums[index]) 
                ++tempIndex;  // Move tempIndex forward until a different number is found
            
            // Step 6: Move the main index to the next unique element
            index = tempIndex;
        }

        // Step 7: Return the length of the modified array
        return actual_Index;
    }
};


int main() {
    vector<vector<int>> nums = {{1,1,1,2,2,3}, {0,0,1,1,1,1,2,3,3}};
    vector<pair<int,vector<int>>> outputs = {{5, {1,1,2,2,3}}, {7, {0,0,1,1,2,3,3}}};
    Solution sol;

    for(int index = 0; index < nums.size(); ++index) {
        int result = sol.removeDuplicates(nums[index]);
        int n = outputs[index].first;
        vector<int> output = outputs[index].second;
        bool match = true;

        for(int i = 0; i < n; ++i) if(nums[index][i] != output[i]) { match = false; break; }
        
        cout << ((match && result == n) ? "true": "false") << endl;
    }
}