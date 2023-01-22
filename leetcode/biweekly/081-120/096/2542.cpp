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
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<pair<int,int>> V;
		int i;
		FOR(i,nums1.size()) V.push_back({nums2[i],nums1[i]});
		ll ma=0;
		sort(ALL(V));
		reverse(ALL(V));
		
		multiset<ll> S;
		ll sum=0;
		FORR(v,V) {
			S.insert(v.second);
			sum+=v.second;
			if(S.size()>k) {
				sum-=*S.begin();
				S.erase(S.begin());
			}
			if(S.size()==k) ma=max(ma,v.first*sum);
		}
		return ma;
        
    }
};
