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
	ll ret;
	void dfs(vector<int> V,int L,int R) {
		if(R-L<=1||V.size()<2) return;
		int M=(L+R)/2;
		vector<int> A,B,X,Y;
		int i;
		FOR(i,V.size()) {
			int v=V[i];
			
			if(v<M) {
				
				while(A.size()&&V[A.back()]<v) A.pop_back();
				A.push_back(i);
				X.push_back(v);
			}
			else {
				while(B.size()&&V[B.back()]>=v) B.pop_back();
				int p=-1;
				if(B.size()) p=B.back();
				ret+=A.end()-lower_bound(ALL(A),p);
				B.push_back(i);
				Y.push_back(v);
			}
			
		}
		
		dfs(X,L,M);
		dfs(Y,M,R);
		
	}
    int shadowPairs(vector<int>& nums) {
		vector<int> V;
		FORR(a,nums) V.push_back(a);
		sort(ALL(V));
		V.erase(unique(ALL(V)),V.end());
		FORR(a,nums) a=lower_bound(ALL(V),a)-V.begin();
		
		ret=0;
		
		dfs(nums,0,V.size());
        return ret;
    }
};

