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
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
		map<int,int> M;
		multiset<pair<int,int>> L,R;
		int N=nums.size();
		int i;
		FOR(i,N) L.insert({0,0});
		vector<ll> ret;
		FORR(n,nums) M[n]=0;
		FOR(i,k) {
			M[nums[i]]++;
		}
		ll sum=0;
		FORR(e,M) R.insert({e.second,e.first});
		while(R.size()>x) L.insert(*R.begin()),R.erase(R.begin());
		while(R.size()<x) R.insert({0,0});
		FORR(e,R) {
			sum+=1LL*e.first*e.second;
		}
		ret.push_back(sum);
		for(i=k;i<N;i++) {
			int y=nums[i-k];
			if(R.count({M[y],y})) {
				R.erase({M[y],y});
				sum-=y;
				M[y]--;
				R.insert({M[y],y});
			}
			else {
				L.erase({M[y],y});
				M[y]--;
				L.insert({M[y],y});
			}
			y=nums[i];
			if(R.count({M[y],y})) {
				R.erase({M[y],y});
				sum+=y;
				M[y]++;
				R.insert({M[y],y});
			}
			else {
				L.erase({M[y],y});
				M[y]++;
				L.insert({M[y],y});
			}
			while(*L.rbegin()>*R.begin()) {
				auto l=*L.rbegin();
				auto r=*R.begin();
				sum-=1LL*r.first*r.second;
				sum+=1LL*l.first*l.second;
				L.erase(L.find(l));
				R.erase(R.find(r));
				L.insert(r);
				R.insert(l);
			}
			ret.push_back(sum);
		}
		
		
		
		return ret;
		
        
    }
};
