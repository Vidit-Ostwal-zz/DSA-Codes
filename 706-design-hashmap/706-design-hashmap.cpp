class MyHashMap {
  vector<int> temp;
public:
    MyHashMap() {
        temp = vector<int>(1000001,-1);
    }
    
    void put(int key, int value) {
        temp[key] = value;
    }
    
    int get(int key) {
        return temp[key] ;
    }
    
    void remove(int key) {
      temp[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */