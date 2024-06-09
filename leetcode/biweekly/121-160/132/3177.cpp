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

map<int,int> M[51];
multiset<int> S[51];
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
		int i;
		FOR(i,k+1) {
	        M[i].clear();
	        S[i].clear();
	    }
	    int ma=0;
	    FORR(n,nums) {
			FOR(i,k+1) if(M[i].count(n)) S[i].erase(S[i].find(M[i][n]));
			
			FOR(i,k+1) if(M[i].count(n)) M[i][n]++;
			for(i=k-1;i>=0;i--) if(S[i].size()) M[i+1][n]=max(M[i+1][n],*S[i].rbegin()+1);
			if(M[0][n]==0) M[0][n]=1;
			
			FOR(i,k+1) if(M[i].count(n)) {
				S[i].insert(M[i][n]);
				ma=max(ma,M[i][n]);
			}
		}
		return ma;
        
    }
};
