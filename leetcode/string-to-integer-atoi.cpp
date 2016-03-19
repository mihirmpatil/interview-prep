class Solution {
public:
    int myAtoi(string str) {
        int multiplier = 1;
        int start = 0, end = str.size(),i;
        
        if(str.size() == 0)
            return 0;
        
        // Beginning part
        i=0;
        while(i < str.size() && str[i]==' ')
            i++;
        if (i==str.size())
            return 0;
        
        if (str[i]=='-') {
            multiplier = -1;
            i++;
        }
        else if (str[i]=='+')
            i++;
        else if (str[i] < '0' && str[i] > '9')
            return 0;
            
        if (i < str.size() && str[i] >= '0' && str[i] <= '9')
            start = i;
        else
            return 0;
            
        // Ending part
        i=start;
        while (i < str.size() && str[i] >= '0' && str[i] <= '9')
            i++;
        end = i-1;
        
        // Now begin conversion
        i=end;
        long double result = 0;
        long double power = 1;
        int cur_val;
        
        while (i>=start) {
            cur_val = str[i] - '0';
            result += (cur_val * power);
            power *= 10;
            i--;
        }
        result = multiplier*result;
        if (result > INT_MAX)
            return INT_MAX;
        else if (result < INT_MIN)
            return INT_MIN;
        else
            return (int)result;
    }
};
