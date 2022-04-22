class MyHashSet {
  vector<int> shared;
public:
    MyHashSet() {
        shared = vector<int> (1000001);
    }
    
    void add(int key) {
        shared[key] = 1;
    }
    
    void remove(int key) {
        shared[key] = -1;
    }
    
    bool contains(int key) {
        return (shared[key] == 1);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */