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


int L[1<<12];
int M[1<<12];
ll C[1<<12];
class Solution {
public:
    long long minMergeCost(vector<vector<int>>& lists) {
		int N=lists.size();
		int i,mask;
		FOR(mask,1<<N) if(mask) {
			vector<int> V;
			FOR(i,N) if(mask&(1<<i)) FORR(a,lists[i]) V.push_back(a);
			sort(ALL(V));
			L[mask]=V.size();
			M[mask]=V[(L[mask]-1)/2];
			
			if(__builtin_popcount(mask)<=1) {
				C[mask]=0;
			}
			else {
				C[mask]=1LL<<60;
				for(int sm=(mask-1)&mask;sm;sm=(sm-1)&mask) {
					int oth=mask^sm;
					if(sm<oth) break;
					C[mask]=min(C[mask],C[sm]+C[oth]+L[mask]+abs(M[sm]-M[oth]));
				}
			}
		}
		return C[(1<<N)-1];
		
        
    }
};

