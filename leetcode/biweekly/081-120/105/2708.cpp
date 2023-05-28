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
    long long maxStrength(vector<int>& nums) {
		ll P=1;
		int Z=0;
		vector<int> M;
		int np=0;
		FORR(n,nums) {
			if(n>0) {
				P=P*n;
				np++;
			}
			else if(n==0) {
				Z++;
			}
			else {
				M.push_back(n);
			}
		}
        
        if(np||M.size()>=2) {
			sort(ALL(M));
			if(M.size()%2==1) M.pop_back();
			FORR(m,M) P*=m;
			return P;
		}
		else {
			if(Z) return 0;
			else return M[0];
		}
        
        
    }
};
