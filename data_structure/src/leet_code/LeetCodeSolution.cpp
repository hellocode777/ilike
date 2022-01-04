#include "LeetCodeSolution.h"
#include <map>

vector<int> LeetCodeSolution::twoSum_1(vector<int> &nums, int target)
{
    map<int, int> tempMap;
    map<int, int>::iterator iter;
    for (int i = 0; i < static_cast<int>(nums.size()); i++)
    {
        iter = tempMap.find(target - nums[i]);
        if (iter != tempMap.end())
        {
            return {iter->second, i};
        }

        tempMap.emplace(nums[i], i);
    }
    return {};
  
}

void LeetCodeSolution::test_twoSum() {
    vector<int> ve{1, 41, 6, 52};
    ve = twoSum_1(ve, 93);
    vector<int> temp{1, 3};
    cout << __FUNCTION__ << (temp == ve ? ":pass" : ":fail") << endl;
}
