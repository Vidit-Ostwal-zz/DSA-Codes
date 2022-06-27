struct Node {
  Node* arr[26];
  bool flag = false;
  
  bool checkchar(char ch)
  {
    return arr[ch - 'a'] != NULL;
  }
  
  void makenewnode(char ch)
  {
    arr[ch - 'a'] = new Node();
  }
  
  Node* charnode (char ch)
  {
    return arr[ch - 'a'];
  }
  
  void setFlag()
  {
    flag = true;
  }
  
  bool getflag()
  {
    return flag;
  }
};


class Trie {
  Node* root;
public:
    Trie() {
        root = new  Node();
    }
    
    void insert(string word) {
        Node* temp = root;
      
      for (int i = 0; i < word.length(); i++)
      {
        char ch = word[i];
        if (!(temp -> checkchar(ch)))
          temp -> makenewnode(ch);
        temp = temp -> charnode(ch);
      }
      temp -> setFlag();
    }
    
    bool search(string word) {
        Node* temp = root;
      
      for (int i = 0; i < word.length(); i++)
      {
        char ch = word[i];
        
        if (temp -> checkchar(ch))
          temp = temp -> charnode(ch);
        else
          return false;
      }
      return temp -> getflag();
    }
    
    bool startsWith(string word) {
        Node* temp = root;
      
      for (int i = 0; i < word.length(); i++)
      {
        char ch = word[i];
         
        if (temp -> checkchar(ch))
          temp = temp -> charnode(ch);
        else
          return false;
      }
      return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */