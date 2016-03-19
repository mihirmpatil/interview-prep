class Solution {
public:
    int compareVersion(string version1, string version2) {
        std::string::size_type sz1(0), sz2(0);
        std::string::size_type accum1(0), accum2(0);
        int v1 = stoi(version1, &sz1, 10);
        int v2 = stoi(version2, &sz2, 10);
        if (v1>v2)
            return 1;
        else if(v1<v2)
            return -1;
        
        accum1 = accum1 + sz1 + 1;
        accum2 = accum2 + sz2 + 1;
    
        while(accum1 < version1.length() && accum2 < version2.length()) {
            
            v1 = stoi(version1.substr(accum1), &sz1, 10);
            v2 = stoi(version2.substr(accum2), &sz2, 10);
            //cout << "while " << v1 << " " << v2 << endl;
            if (v1>v2)
                return 1;
            else if(v1<v2)
                return -1;
            
            accum1 = accum1 + sz1 + 1;
            accum2 = accum2 + sz2 + 1;
        }
        //cout << "here" << endl;
        while (accum1 < version1.length()) {
            //cout << "while1" << endl;
            v1 = stoi(version1.substr(accum1), &sz1, 10);
            if(v1>0)
                return 1;
            accum1 = accum1 + sz1 + 1;
        }
        while (accum2 < version2.length()) {
            //cout << "while2" << endl;
            v2 = stoi(version2.substr(accum2), &sz2, 10);
            if(v2>0)
                return -1;
            accum2 = accum2 + sz2 + 1;
        }
        return 0;
    }
};