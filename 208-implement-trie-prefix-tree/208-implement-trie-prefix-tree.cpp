struct Node {
  Node* links[26];
  bool  flag  = false;
  
  bool containskey(char ch)
  {
    return links[ch - 'a'] != NULL;
  }
  
  Node* getkey(char ch)
  {
    return links[ch - 'a'];
  }
  
  void put (char ch, Node* temp)
  {
    links[ch - 'a'] = temp;
  }
  
  
  void setEnd()
  {
    flag = true;
  }
  
  bool isEnd()
  {
    return flag == true;
  }
};



class Trie {
  Node* root;
  
public:
  
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
      Node* temp = root;
      for (int i = 0; i < word.length(); i++)
      {
        if (! temp -> containskey(word[i]))
          temp -> put(word[i],new Node());
        
        temp = temp -> getkey(word[i]);
      }
      temp ->setEnd();
    }
    
    bool search(string word) {
        Node* temp = root;
      for (int i = 0; i < word.length(); i++)
      {
        if (!temp -> containskey(word[i]))
          return false;
        
        temp = temp -> getkey(word[i]);
      }
      if (temp -> isEnd())
        return true;
      
      return false;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
      for (int i = 0 ;i < prefix.length(); i++)
      {
        if (!temp -> containskey(prefix[i]))
            return false;
        
        temp = temp -> getkey(prefix[i]);
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