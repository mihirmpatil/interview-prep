class Solution {
public:
    string convert(string s, int numRows) {
        int i, s1, s2, pos;
        string result;
        
        if(s.empty())
            return result;
        if(numRows==1 || numRows > s.length())
            return s;
        
        for (i=0; i<numRows; i++) {
            pos = i;
            result += s[pos];
            s1 = 2*(numRows - 1 - i);
            s2 = 2*i;
            //cout << pos << " " << s1 << " " << s2 << endl;
            while(pos < s.length()){
                pos = pos + s1;
                
                if(s1 != 0 && pos < s.length()) {
                    result += s[pos];
                    //cout << "here " << result << " " << pos << " " << s1 << " " << s2 << endl;
                }
                pos = pos + s2;
                if(s2 != 0 && pos < s.length())
                    result += s[pos];
            }
        }
        return result;
    }
};