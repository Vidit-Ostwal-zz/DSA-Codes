struct Node{
  Node* links[26];
  bool flag = false;
  
  bool Containskey(char ch)
  {
    return (links[ch - 'a'] != NULL);
  }
  
  void putchar(char ch, Node* temp)
  {
    links[ch -'a'] = temp;
  }
  
  Node* getchar(char ch)
  {
    return links[ch- 'a'];
  }
  
  void setflag()
  {
    flag = true;
  } 
};



class Trie {
  Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
      
      for (int i = 0; i < word.length(); i++)
      {
        if (!node -> Containskey(word[i]))
          node -> putchar(word[i],new Node());
        
        node = node -> getchar(word[i]);
      }
      node -> setflag();
    }
    
    bool search(string word) {
        Node* node = root;
      
      for (int i = 0; i < word.length(); i++)
      {
        if (!node -> Containskey(word[i]))
          return false;
        
        node = node -> getchar(word[i]);
      }
      return node -> flag;
    }
    
    bool startsWith(string word) {
        Node* node = root;
      
      for (int i = 0; i < word.length(); i++)
      {
        if (!node -> Containskey(word[i]))
          return false;
        
        node = node -> getchar(word[i]);
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