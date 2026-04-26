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
    vector<int> kthRemainingInteger(vector<int>& nums, vector<vector<int>>& queries) {
		vector<int> P;
		int i,N=nums.size();
		map<int,int> M;
		FOR(i,N) if(nums[i]%2==0) {
			M[i]=P.size();
			P.push_back(nums[i]/2);
		}
		M[N]=P.size();
		vector<int> V;
		FORR(q,queries) {
			int L=M.lower_bound(q[0])->second;
			int R=M.lower_bound(q[1]+1)->second;
			int K=q[2];
			int ret=1<<30;
			for(i=29;i>=0;i--) {
				int tmp=ret-(1<<i);
				int num=lower_bound(P.begin()+L,P.begin()+R,tmp+1)-P.begin()-L;
				if(tmp-num>=K) ret=tmp;
			}
			V.push_back(ret*2);
			
		}
		return V;
        
    }
};

