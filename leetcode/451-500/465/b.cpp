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
	int N,K;
	vector<int> ret;
	vector<int> cand;
	
	void dfs(vector<int> V) {
		ll a=1;
		FORR(v,V) {
			a*=cand[v];
			if(a>N) return;
		}
		if(V.size()==K-1) {
			if(N%a==0) {
				vector<int> W;
				FORR(a,V) W.push_back(cand[a]);
				W.push_back(N/a);
				sort(ALL(W));
				
				if(ret.empty()) ret=W;
				if(ret.back()-ret[0]>W.back()-W[0]) ret=W;
				
			}
			return;
		}
		int i;
		for(i=(V.empty()?0:V.back());i<cand.size();i++) {
			V.push_back(i);
			dfs(V);
			V.pop_back();
		}
		
	}
	
    vector<int> minDifference(int n, int k) {
		N=n;
		K=k;
		ret.clear();
		cand.clear();
		vector<int> V;
		int i;
		for(i=1;i<=N;i++) if(N%i==0) cand.push_back(i);
		dfs(V);
		return ret;
		
		
        
    }
};
