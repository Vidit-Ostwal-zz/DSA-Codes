class Solution
{
    void show_vector(vector<int> vect)
    {
        for (auto &it: vect)
        {
            cout << it << " ";
           	// cout << it.first << "  " << it.second << endl;
        }
      cout << endl;
    }

    bool KMP(string s)
    {
        vector<int> KMPvector(s.length(), 0);
        KMPvector[0] = 0;

        int len = 0;
        int i = 1;

        while (i < s.length())
        {
            if (s[i] == s[len])
            {
                len++;
                KMPvector[i] = len;
                i++;
            }
            else
            {
               	// the character does not match, you go to the previous one which matched, which points to the starting same prefix
                if (len != 0)
                    len = KMPvector[len - 1];
                else
                {
                    KMPvector[i] = 0;
                    i++;
                }
            }
        }
       	// show_vector(KMPvector);
      // last integer will represent the length from the starting till which it can be same
      int length = KMPvector.size() - KMPvector[KMPvector.size()-1];
      return KMPvector[KMPvector.size()-1] && KMPvector[KMPvector.size()-1] % length == 0;
    }
    public:
        bool repeatedSubstringPattern(string s)
        {
            return KMP(s);
        }
};