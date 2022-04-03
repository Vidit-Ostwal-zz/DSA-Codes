class Encrypter {
  unordered_map<char,string> kv;
   unordered_map<string,int> dic;
   unordered_map<string,vector<char>> vk;
  
  
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dict) {
        for (int i = 0; i < keys.size(); i++)
        {
          kv[keys[i]] += values[i];
          vk[values[i]].push_back(keys[i]);
        }
      
      for (int i = 0; i < dict.size(); i++)
        dic[encrypt(dict[i])]++;
      
    }
    
    string encrypt(string word1) {
        string temp ="";
      for (int i=  0; i < word1.length(); i++)
        temp += kv[word1[i]];
      
      
      return temp;
    }
    
    int decrypt(string word2) {
        return dic[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */