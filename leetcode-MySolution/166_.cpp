class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0||denominator==0)
            return "0";
        
        // 用异或考虑负值的情况
        string resStr="";
        if(numerator<0 ^ denominator<0)
            resStr +='-';
        // 转成绝对值，防止后面数值溢出
        long num = long(labs(numerator));
        long den = long(labs(denominator));
        resStr += to_string(num/den);
        if(num%den==0)
            return resStr;
        
        // 处理小数部分        
        string float_part = "";
        unordered_map<long,long> hashTable;
        long res = num%den;
        long loc = 0;
        while(res!=0){
            long val = 10*res/den;
            if(hashTable.find(res)!=hashTable.end()){
                // string的insert命令，是在pos所指的位置之前插入的
                float_part.insert(hashTable[res],"(");
                float_part +=")";
                break;
            }
            hashTable.insert(make_pair(res,loc));

            float_part  += (val+'0');
            res = 10*res%den;
            loc++;
        }
        
        resStr += '.';
        resStr += float_part;
        return resStr;
        
    }
};