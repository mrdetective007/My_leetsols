class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        unordered_map<int, int> mp;
        mp[0]++;
        int prev = 0;
        for(int i = 1;i<=pow(2, n) - 1;i++)
        {
            int num = 1;
            int temp = prev;
            while(mp.find(temp^num) != mp.end())
            {
                num = num<<1;
            }
            mp[temp^num]++;
            ans.push_back(temp^num);
            prev = (temp^num);
        }
        return ans;
    }
};