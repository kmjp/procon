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

int D[1010101];

class Solution {
public:
    int minOperations(vector<int>& nums) {
		int i;
		int N=nums.size();
		int mi=1<<20;
		for(int L=0;L<N;L++) {
			int g=0;
			for(int R=L;R<N;R++) {
				g=__gcd(g,nums[R]);
				if(g==1) {
					
					for(int C=L;C<=R;C++) {
						int step=R-L;
						FOR(i,C) if(nums[i]>1) step++;
						for(i=C+1;i<N;i++) if(nums[i]>1) step++;
						mi=min(mi,step);
					}
					
				}
				
			}
		}
		
		if(mi==1<<20) mi=-1;
		return mi;
        
    }
};
