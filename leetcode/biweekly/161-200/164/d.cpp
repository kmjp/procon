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

int dp[101010];

class Solution {
public:
    int minOperations(string s, int k) {
		int C=0;
		int N=s.size();
		int i;
		FORR(a,s) C+=a=='1';
		set<int> S[2];
		dp[C]=0;
		
		FOR(i,N+1) S[i%2].insert(i);
		S[C%2].erase(C);
		queue<int> Q;
		Q.push(C);
		while(Q.size()) {
			int C=Q.front();
			Q.pop();
			if(C==N) return dp[C];
			int mi,ma;
			mi=C-k;
			if(mi<0) mi=-mi;
			ma=C+k;
			if(ma>N) ma=N-(ma-N);
			int id=mi%2;
			auto it=S[id].lower_bound(mi);
			while(it!=S[id].end()&&*it<=ma) {
				dp[*it]=dp[C]+1;
				Q.push(*it);
				it=S[id].erase(it);
			}
		}
		
        return -1;
    }
};

