class SmallestInfiniteSet {
public:

    set<int>st;
    int currsmallest;
    SmallestInfiniteSet() {
       currsmallest = 1;

    }
    
    int popSmallest() {
        int result;
        if(!st.empty()){
            result  = *st.begin();
            st.erase(st.begin());
        }
        else{
            result = currsmallest;
            currsmallest += 1;
        }

       
        return result;
    }
    
    void addBack(int num) {
      if( num >= currsmallest || st.find(num) != st.end())
      return;
      st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */