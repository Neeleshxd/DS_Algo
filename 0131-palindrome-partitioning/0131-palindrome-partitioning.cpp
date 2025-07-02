class Solution
{
    public:
        vector<string> temp;
    vector<vector < string>> result;
    bool isPalindrome(int i, int j,string &s)
    {
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(string &s, int idx)
    {
        int n = s.size();
        if (idx == n)
        {
            result.push_back(temp);
            return;
        }
        for (int i = idx; i < n; i++)
        {
            if (isPalindrome(idx, i,s))
            {
                temp.push_back(s.substr(idx, i - idx + 1));
                solve(s, i + 1);
                temp.pop_back();
            }
        }
    }
    vector<vector < string>> partition(string s)
    {
        solve(s, 0);
        return result;
    }
};