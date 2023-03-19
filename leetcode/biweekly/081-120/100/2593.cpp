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



int mark[101010];
class Solution {
public:
    long long findScore(vector<int>& nums) {
		int i,N=nums.size();
		vector<pair<int,int>> V;
		FOR(i,N) {
			mark[i]=0;
			V.push_back({nums[i],i});
		}
		sort(ALL(V));
		ll ret=0;
		FORR(v,V) {
			int x=v.second;
			if(mark[x]) continue;
			mark[x]=1;
			if(x) mark[x-1]=1;
			mark[x+1]=1;
			ret+=v.first;
		}
		return ret;
        
    }
};
