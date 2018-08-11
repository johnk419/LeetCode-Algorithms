// Question : https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        vector<int> s1map(26);
        vector<int> s2map(26);
        
        for (int i = 0; i < s1.size(); ++i) {
            s1map[s1[i] - 'a']++;
            s2map[s2[i] - 'a']++;
        }
        
        int matching = 0;
        for (int i = 0; i < 26; ++i) {
            if (s1map[i] == s2map[i]) {
                matching++;
            }
        }
        
        if (matching == 26) {
            return true;
        }
        
        for (int i = 0; i < s2.size() - s1.size(); ++i) {
            if (matching == 26) {
                return true;
            }
            
            int beginChar = s2[i] - 'a';
            int endChar = s2[i + s1.size()] - 'a';
            
            s2map[endChar]++;
            if (s2map[endChar] == s1map[endChar]) {
                matching++;
            } else if (s2map[endChar] == s1map[endChar] + 1) {
                matching--;
            }
            s2map[beginChar]--;
            if (s2map[beginChar] == s1map[beginChar]) {
                matching++;
            }
            else if (s2map[beginChar] == s1map[beginChar] - 1) {
                matching--;
            }
            
        }
        return matching == 26;
    }
    
 
};