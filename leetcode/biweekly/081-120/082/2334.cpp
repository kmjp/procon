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
    int validSubarraySize(vector<int>& nums, int threshold) {
		vector<pair<int,int>> S={{0,0}};
		int i;
		int N=nums.size();
		for(i=1;i<=nums.size();i++) {
			int x=nums[i-1];
			int pre=i;
			while(S.back().first>=x) {
				if(1LL*S.back().first*(i-S.back().second)>threshold) {
					cout<<"!"<<S.back().second<<" "<<i<<endl;
					return (i-S.back().second);
				}
				pre=S.back().second;
				S.pop_back();
			}
			S.push_back({x,pre});
			
		}
		while(S.size()) {
			if(1LL*S.back().first*(N+1-S.back().second)>threshold) {
					cout<<"!"<<S.back().second<<" "<<N+1<<endl;
				return (N+1-S.back().second);
			}
			S.pop_back();
		}
		return -1;
        
    }
};

