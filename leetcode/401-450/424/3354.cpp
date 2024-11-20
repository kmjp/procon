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
    int countValidSelections(vector<int>& nums) {
		int ret=0;
		int i,j;
		int N=nums.size();
		FOR(i,N) if(nums[i]==0) {
			FOR(j,2) {
				vector<int> V=nums;
				int cur=i;
				int dir=j;
				while(1) {
					if(cur<0||cur>=N) break;
					if(V[cur]==0) {
						if(dir==0) cur++;
						else cur--;
					}
					else {
						V[cur]--;
						dir^=1;
						if(dir==0) cur++;
						else cur--;
					}
				}
				FOR(cur,N) if(V[cur]) break;
				if(cur==N) ret++;
			}
		}
		return ret;
        
    }
};

