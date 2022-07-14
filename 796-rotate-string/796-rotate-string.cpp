class Solution
{
    int KMPSearch(string s, int length)
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
        return KMPvector[KMPvector.size() - 1];
    }
    public:
        bool rotateString(string s, string goal)
        {
          
          if (s.length() != goal.length())
            return false;
          
            int index = KMPSearch(goal + " " + s, goal.length());
           	// index is in goal

            int j = 0;
            while (index < goal.length())
            {
                if (goal[index] == s[j])
                {
                    index++;
                    j++;
                }
                else
                    break;
            }

            if (index == goal.length())
                return true;
            return false;
        }
};