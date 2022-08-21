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

ll S[101010];

class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int N=nums.size();
        int i;
        FOR(i,N) S[i+1]=S[i]+nums[i];
        set<pair<int,int>> C={{0,N}};
        multiset<ll> M={S[N],0};
        vector<ll> ret;
        FORR(q,removeQueries) {
			auto it=C.lower_bound({q+1,0});
			it--;
			auto p=*it;
			C.erase(p);
			M.erase(M.find(S[p.second]-S[p.first]));
			
			if(q!=p.first) {
				C.insert({p.first,q});
				M.insert(S[q]-S[p.first]);
			}
			if(q!=p.second-1) {
				C.insert({q+1,p.second});
				M.insert(S[p.second]-S[q+1]);
			}
			ret.push_back(*M.rbegin());
		}
        return ret;
    }
};