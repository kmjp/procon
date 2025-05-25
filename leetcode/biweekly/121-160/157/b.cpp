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


int dp[202020];

class Solution {
public:
    int maxSubstrings(string word) {
		vector<int> C[26];
		int N=word.size();
		int i;
		FOR(i,26) {
			C[i].push_back(-100);
			C[i].push_back(-100);
			C[i].push_back(-100);
		}
			
		FOR(i,N) {
			int c=word[i]-'a';
			int x=C[c].size()-1;
			while(i-C[c][x]<=2) x--;
			if(C[c][x]<0) dp[i+1]=dp[i];
			else dp[i+1]=max(dp[i],dp[C[c][x]]+1);
			C[c].push_back(i);
		}
		return dp[N];
        
    }
};

