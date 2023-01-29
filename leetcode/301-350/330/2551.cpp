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
	ll hoge(vector<int>& W, int k,int r=0) {
		int N=W.size();
		vector<int> V;
		int i;
		FOR(i,N-1) V.push_back(W[i]+W[i+1]);
		ll a=W[0]+W[N-1];
		sort(ALL(V));
		if(r==0) {
			reverse(ALL(V));
		}
		FOR(i,k-1) a+=V[i];
		return a;
		
	}
    long long putMarbles(vector<int>& weights, int k) {
		return hoge(weights,k)-hoge(weights,k,1);
        
    }
};
