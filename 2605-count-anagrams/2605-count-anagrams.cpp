class Solution {
public:
    long long mod = 1e9 + 7;
    long long power(long long b, long long e){     // helper for fast exponentiation
        long long r = 1;
        b %= mod;
        while(e > 0){
            if(e & 1) r = r * b % mod;
            b = b * b % mod;
            e >>= 1;
        }
        return r;
    }

    long long modInverse(long long x){             // FIX 2: Fermat's little theorem
        return power(x, mod - 2);
    }
    int countpermutations(int freq[], vector<long long>& fact){
        int noofchars = 0;
        long long ans=0;
        for(int i=0; i<26; i++){
            noofchars += freq[i];
        }
        ans = fact[noofchars];
        for(int i=0; i<26; i++){
            ans = ans * modInverse(fact[freq[i]]) % mod;
        }
        return ans;
    }

    int countAnagrams(string s){
        int i=0, n=s.size();
        long long ans = 1;
        int freq[26];
        fill(freq, freq+26, 0);
        vector<long long> fact(n + 1); 
        fact[0] = 1;
        for(int j = 1; j<=n; j++){
            fact[j] = (fact[j - 1] * j) % mod;
        }
        while(i<=n){
            if(i < n && s[i] != ' ')
                freq[s[i]-97]++;
            else{
                ans = ans * countpermutations(freq, fact) % mod;
                fill(freq, freq+26, 0);
            }
            i++;
        }
        return (int)ans;
    }
};