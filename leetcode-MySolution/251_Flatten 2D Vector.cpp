class Vector2D {
public:
    Vector2D(vector<vector<int>>& v) {
        iStart = v.begin();
        iEnd = v.end();
        th = 0;
        
    }
    
    int next() {
        hasNext();  //代码复用，学到了
        return (*iStart)[th++];
        
        
    }
    
    bool hasNext() {
        // 找到一个非空的vector。这种检查方式很巧，
        while(iStart!=iEnd && th==(*iStart).size()){
            ++iStart;
            th=0;
        }
        
        return iStart!=iEnd;
    }
    
private:
    vector<vector<int>>::iterator iStart, iEnd;
    int th; //当前所要输出的元素的下标
    
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */