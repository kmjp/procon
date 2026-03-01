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
    vector<int> makeParityAlternating(vector<int>& nums) {
        vector<int> C;
        int V[2]={};
        int N=nums.size();
        int i;
        FOR(i,N) {
			int a=nums[i];
			C.push_back(a-1);
			C.push_back(a);
			C.push_back(a+1);
			if(abs(a)%2==i%2) {
				V[1]++;
			}
			else {
				V[0]++;
			}
		}
		int mask=0;
		if(V[0]<=V[1]) mask|=1;
		if(V[1]<=V[0]) mask|=2;
		int ret=0;
		sort(ALL(C));
		C.erase(unique(ALL(C)),C.end());
		int x,y,j;
		ll cand=1LL<<31;
		FOR(x,3) FOR(y,3) {
			ll mi=C[x],ma=C[C.size()-1-y];
			FOR(j,2) if(mask&(1<<j)) {
				int ok=1;
				FOR(i,N) {
					ll a=nums[i];
					
					if(abs(a)%2==i%2) {
						if(j==0) {
							if(a<mi||a>ma) ok=0;
						}
						else {
							if((a-1<mi||a-1>ma)&&(a+1<mi||a+1>ma)) ok=0;
						}
					}
					else {
						if(j==1) {
							if(a<mi||a>ma) ok=0;
						}
						else {
							if((a-1<mi||a-1>ma)&&(a+1<mi||a+1>ma)) ok=0;
						}
					}
				}
				if(ok) cand=min(cand,ma-mi);
			}
		}
		return {min(V[0],V[1]),(int)cand};
			
		
		
        
    }
};
