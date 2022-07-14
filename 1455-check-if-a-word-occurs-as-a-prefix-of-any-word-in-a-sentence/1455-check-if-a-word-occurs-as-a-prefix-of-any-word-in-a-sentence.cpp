class Solution
{
    vector<string> SeperateString(string s)
    {
        vector<string> words;
        istringstream ss(s);

        string word;

        while (ss >> word)
        {
            words.push_back(word);
        }
        return words;
    }

    void show_vector(vector<int> vect)
    {
        for (auto &it: vect)
        {
            cout << it << endl;
           	// cout << it.first << "  " << it.second << endl;
        }
      cout << endl;
    }

    bool KMP(string s, int length)
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
        // show_vector(KMPvector);
      
        if (2*length < KMPvector.size() && KMPvector[2 *length] == length)
            return true;
        return false;
    }

    public:
        int isPrefixOfWord(string sentence, string searchWord)
        {

            vector<string> stringvector = SeperateString(sentence);

            for (int i = 0; i < stringvector.size(); i++)
            {
                if (stringvector[i].size() >= searchWord.length() && KMP(searchWord + " " + stringvector[i], searchWord.length()))
                    return i + 1;
            }
            return -1;
        }
};