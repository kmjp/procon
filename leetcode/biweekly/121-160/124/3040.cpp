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
	unordered_map<int,int> M[2020];
	vector<int> V;
	int dfs(int L,int R,int c) {
		if(R<=L) return 0;
		if(M[L].count(R)) return M[L][R];
		
		int ma=0;
		if(V[L]+V[L+1]==c) ma=max(ma,1+dfs(L+2,R,c));
		if(V[R]+V[R-1]==c) ma=max(ma,1+dfs(L,R-2,c));
		if(V[L]+V[R]==c) ma=max(ma,1+dfs(L+1,R-1,c));
		return M[L][R]=ma;
	}
    int maxOperations(vector<int>& nums) {
        V=nums;
        vector<int> C={V[0]+V[1],V.back()+V[V.size()-2],V[0]+V.back()};
        int ma=0;
        int i;
        
        FORR(c,C) {
			FOR(i,2020) M[i].clear();
			ma=max(ma,dfs(0,V.size()-1,c));
		}
		return ma;
        
    }
};

