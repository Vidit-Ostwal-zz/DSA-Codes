class ProductOfNumbers 
{
  vector<int> temp;
   vector<int> K;
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
      cout << "add" << endl;
      if (num == 0)
      {
        temp = K;
      }
      else if (temp.size() == 0)
      {
        temp.push_back(num);
      }
      else
      {
        temp.push_back(temp[temp.size()-1]*num);
      }
    }
    
    int getProduct(int k) {
      cout << "Product" << endl;
        if (k > temp.size())
        {
          return 0;
        }
      if (k == temp.size())
      {
        return temp[temp.size()-1];
      }
      return temp[temp.size()-1]/temp[temp.size()-1-k];
      
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */