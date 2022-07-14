class Solution
{
    bool KMPMatch(string s, int length)
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
       	// return KMPvector;

        for (int i = length; i < s.length(); i++)
        {
            if (KMPvector[i] == length)
                return true;
        }
        return false;
    }
    public:
        vector<string> stringMatching(vector<string> &words)
        {

            // sort(words.begin(), words.end());
            vector<string> answer;

            for (int i = 0; i < words.size(); i++)
            {
                for (int j = 0; j < words.size(); j++)
                {
                   	// words[i] is the substring to be checked and
                   	// words[j] is the string in which substring needs to be checked 
                    if ( i != j && KMPMatch(words[i] + " " + words[j], words[i].length()))
                    {
                        answer.push_back(words[i]);
                        break;
                    }
                }
            }
            return answer;
        }
};