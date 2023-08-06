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

ll from[1010];
ll to[1010];

class Solution {
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int X) {
		int N=nums1.size();
		vector<pair<int,int>> V;
		int x,y,i;
		FOR(x,N+1) from[x]=1LL<<60;
		from[0]=0;
		ll aa=0;
		FOR(i,N) {
			V.push_back({nums2[i],nums1[i]});
			aa+=nums2[i];
			from[0]+=nums1[i];
		}
		sort(ALL(V));
		ll sum=0;
		FOR(i,N) {
			FOR(x,N+1) to[x]=1LL<<60;
			FOR(x,N) {
				to[x]=min(to[x],from[x]);
				to[x+1]=min(to[x+1],from[x]-V[i].second-(x+1)*V[i].first);
			}
			/*
			FOR(x,N+1) cout<<from[x]<<" ";
			cout<<endl;
			*/
			swap(from,to);
		}
		
		FOR(i,N+1) {
			//cout<<i<<" "<<from[i]<<" "<<aa*i<<" "<<from[i]+aa*i<<endl;
			if(from[i]+aa*i<=X) return i;
		}
        return -1;
    }
};