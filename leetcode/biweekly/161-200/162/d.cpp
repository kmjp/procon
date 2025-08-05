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

const int DI=100;
vector<pair<int,int>> ev[101];

class Solution {
public:
    vector<int> subarrayMajority(vector<int>& nums, vector<vector<int>>& queries) {
		int N=nums.size();
		int i,j;
		vector<int> ret(queries.size());
		FOR(i,DI) ev[i].clear();
		FOR(i,queries.size()) {
			ev[queries[i][0]/DI].push_back({queries[i][1],i});
		}
		
		FOR(j,DI) if(ev[j].size()) {
			map<int,int> M;
			set<pair<int,int>> S;
			int L=j*DI,R=j*DI;
			sort(ALL(ev[j]));
			FORR2(r,i,ev[j]) {
				while(R<=r) {
					S.erase({M[nums[R]],-nums[R]});
					M[nums[R]]++;
					S.insert({M[nums[R]],-nums[R]});
					R++;
				}
				int l=queries[i][0];
				while(l<L) {
					L--;
					S.erase({M[nums[L]],-nums[L]});
					M[nums[L]]++;
					S.insert({M[nums[L]],-nums[L]});
				}
				while(L<l) {
					S.erase({M[nums[L]],-nums[L]});
					M[nums[L]]--;
					S.insert({M[nums[L]],-nums[L]});
					L++;
				}
				auto it=*S.rbegin();
				if(it.first<queries[i][2]) ret[i]=-1;
				else ret[i]=-it.second;
			}
		}
		return ret;
        
    }
};

