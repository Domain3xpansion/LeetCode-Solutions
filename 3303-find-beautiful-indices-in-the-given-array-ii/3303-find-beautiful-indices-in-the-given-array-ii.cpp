class Solution {
public:
    void computeLPS(string pattern, vector<int>& lps){
        int M = pattern.length();
        int len = 0;                         
        lps[0] = 0;                           
        int i = 1;                             
        while(i<M){
            if(pattern[i] == pattern[len]){           
                len++;
                lps[i] = len;
                i++;
            }else{                                   
                if(len != 0)
                    len = lps[len - 1];                     
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    vector<int> KMP(string pat, string txt){
        int N = txt.length(), M = pat.length();
        vector<int> res, lps(M, 0);    
        computeLPS(pat, lps);
        int i = 0; 
        int j = 0; 
        while(i < N){
            if(pat[j] == txt[i]){ 
                i++;                      
                j++;
            }
            if(j == M){                               
                res.push_back(i-j);                          
                j = lps[j - 1];                                 
            }else if(i < N && txt[i] != pat[j]){
                if(j != 0)
                    j = lps[j - 1];                  
                else 
                    i++;
            }                
        }
        return res; 
    }
    
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.length(), j=0;
        vector<int> i_indices = KMP(a, s);
        vector<int> j_indices = KMP(b, s);
        vector<int> result;
        for(auto &i : i_indices){
            while(j<j_indices.size() && j_indices[j]<i-k){
                j++;
            }
            if(j<j_indices.size() && j_indices[j]<=i+k){
                result.push_back(i);
            }
        }
        return result;
    }
};