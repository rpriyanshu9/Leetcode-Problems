class Solution
{
public:
    vector<string> res;

    void helper(string s, unordered_set<string> &dict, string curr)
    {
        if (s.length() <= 0)
        {
            res.push_back(curr);
        }
        for (int i = 1; i <= s.length(); i++)
        {
            if (dict.find(s.substr(0, i)) != dict.end())
            {
                string temp = curr;
                if (temp != "")
                    temp += " ";
                temp += s.substr(0, i);
                helper(s.substr(i), dict, temp);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict;
        for (auto word : wordDict)
        {
            dict.insert(word);
        }
        string curr = "";
        helper(s, dict, curr);
        return res;
    }
};