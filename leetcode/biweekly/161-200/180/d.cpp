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

const ll mo=1000000007;

class Solution {
public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
		ll p=0;
		int i,j;
		vector<pair<int,int>> V;
		
		FOR(i,nums1.size()) {
			if(nums0[i]==0) {
				FOR(j,nums1[i]) p=(p*2+1)%mo;
			}
			else {
				V.push_back({-nums1[i],nums0[i]});
			}
		}
		sort(ALL(V));
		FORR2(a,b,V) {
			FOR(j,-a) p=(p*2+1)%mo;
			FOR(j,b) p=(p*2)%mo;
		}
		return p;
        
    }
};
