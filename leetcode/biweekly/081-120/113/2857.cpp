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
    int countPairs(vector<vector<int>>& coordinates, int k) {
		map<pair<int,int>,int> M;
		ll ret=0;
		FORR(v,coordinates) {
			for(int dx=0;dx<=k;dx++) {
				int dy=k-dx;
				if(M.count({v[0]^dx,v[1]^dy})) ret+=M[{v[0]^dx,v[1]^dy}];
			}
			
			
			M[{v[0],v[1]}]++;
		}
        
        return ret;
    }
};

