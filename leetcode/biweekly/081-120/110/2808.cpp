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
    int minimumSeconds(vector<int>& nums) {
		int mi=1<<20;
		map<int,vector<int>> V;
		int i;
		FOR(i,nums.size()) V[nums[i]].push_back(i);
		FORR(v,V) {
			vector<int> A=v.second;
			A.push_back(A[0]+nums.size());
			int ma=0;
			FOR(i,A.size()-1) {
				ma=max(ma,(A[i+1]-A[i])/2);
			}
			mi=min(mi,ma);
		}
		return mi;
		
        
    }
};
