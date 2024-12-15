#include <vector>
#include <iostream>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Step 1: Create a map to count the frequency of each number in nums
        map<int, int> num_Count;  // Key: number, Value: frequency of the number
        
        // Step 2: Count the occurrences of each number in the nums vector
        for(const int& num: nums) ++num_Count[num];  // Iterate through nums and update frequency
        
        // Step 3: Create a vector to store the result, which will hold the modified nums
        vector<int> extra_memory;

        // Step 4: Iterate over the map (num_Count) to build the updated array
        for(auto p = num_Count.begin(); p != num_Count.end(); ++p) {
            int num = p->first;  // The number
            int freq = p->second;  // The frequency of the number
            
            // Always push the number once to the extra_memory vector
            extra_memory.push_back(num);
            
            // If the number appears more than once, push it again (it should appear twice)
            if(freq > 1)  extra_memory.push_back(num);
        }

        // Step 5: Copy the elements from extra_memory back to the nums vector
        for(int index = 0; index < extra_memory.size(); ++index)
            nums[index] = extra_memory[index];  // Update the nums vector with elements from extra_memory

        // Step 6: Return the size of the modified nums array (the number of elements in extra_memory)
        return extra_memory.size();
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