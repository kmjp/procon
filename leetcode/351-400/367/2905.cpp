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
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
		set<int> A;
		deque<pair<int,int>> D;
		vector<pair<int,int>> V;
		int i;
		int N=nums.size();
		FOR(i,N) V.push_back({nums[i],i});
		sort(ALL(V));
		int x,y;
		y=0;
		FOR(x,N) {
			while(y<=x&&V[y].first+valueDifference<=V[x].first) {
				A.insert(V[y].second);
				y++;
			}
			auto it=A.lower_bound(V[x].second+indexDifference);
			if(it!=A.end()) return  {V[x].second,*it};
			it=A.lower_bound(V[x].second-indexDifference+1);
			if(it!=A.begin()) return  {V[x].second,*prev(it)};
			
		}
        return {-1,-1};
    }
};
