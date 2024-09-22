#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
		int i,j;
        int C[26]={},D[26]={};
		FORR(c,word2) D[c-'a']++;
        
        ll ret=0;
        for(int L=0,R=0;L<word1.size();L++) {
			while(1) {
				int ok=1;
				FOR(i,26) if(C[i]<D[i]) ok=0;
				if(ok==1) break;
				if(R==word1.size()) {
					R++;
					break;
				}
				C[word1[R]-'a']++;
				R++;
			}
			if(R>word1.size()) break;
			ret+=word1.size()-R+1;
			C[word1[L]-'a']--;
			
		}
        return ret;
    }
};
