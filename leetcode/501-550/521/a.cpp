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
    vector<int> rearrangeArray(vector<int>& nums) {
		map<int,int> M;
		vector<int> V;
		FORR(a,nums) M[a]++;
		while(M.size()) {
			vector<int> D;
			FORR2(a,b,M) {
				V.push_back(a);
				D.push_back(a);
			}
			FORR(v,D) {
				if(--M[v]==0) M.erase(v);
			}
		}
		return V;
        
    }
};
