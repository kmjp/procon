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

int dp[555][555],X;
vector<int> V;
class Solution {
public:
	int hoge(int L,int R) {
		if(L==R) return 0;
		if(dp[L][R]>=0) return dp[L][R];
		int ret=1<<30;
		for(int i=L+1;i<R;i+=2) ret=min(ret,min(X,V[i]-V[L])+hoge(L+1,i)+hoge(i+1,R));
		return dp[L][R]=ret;
	}

    int minOperations(string s1, string s2, int x) {
		int i,j,N=s1.size();
		int ret=0;
		int pre=-1;
		X=x;
		
		MINUS(dp);
		V.clear();
		FOR(i,N) if(s1[i]!=s2[i]) V.push_back(i);
		if(V.size()%2) return -1;
		return hoge(0,V.size());
		
        
    }
};
