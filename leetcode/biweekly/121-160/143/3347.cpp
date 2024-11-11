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
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
		map<int,int> C;
		FORR(a,nums) C[a]++;
		sort(ALL(nums));
		int ma=0;
		
		//’†S‚ª‚È‚¢
		int N=nums.size();
		for(int L=0,R=0;L<N;L++) {
			while(R<N&&R-L<numOperations&&nums[R]-nums[L]<=2*k) R++;
			ma=max(ma,R-L);
		}
		//’†S‚ª‚ ‚é
		for(int L=0,M=0,R=0;M<N;M++) {
			while(R<N&&nums[R]-nums[M]<=k) R++;
			while(nums[M]-nums[L]>k) L++;
			int c=C[nums[M]];
			int t=min(R-L-c,numOperations);
			ma=max(ma,c+t);
		}
		return ma;
        
    }
};

