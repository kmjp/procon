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



vector<int> Z;

class Solution {
public:
    int numberOfSubstrings(string s) {
		int N=s.size();
		int i,j;
		Z.clear();
		FOR(i,N) if(s[i]=='0') Z.push_back(i);
		Z.push_back(N);
		
		ll ret=0;
		FOR(i,N) {
			int x=lower_bound(ALL(Z),i)-Z.begin();
			for(j=0;j+x<Z.size()&&j<=201;j++) {
				int L,R;
				
				if(j==0) {
					L=i+1;
				}
				else {
					L=Z[j+x-1]+1;
				}
				R=Z[j+x];
				int dif=L-i-j-j*j;
				if(dif>=0) {
					ret+=R-L+1;
				}
				else if(R-L+dif>=0) {
					ret+=R-L+dif+1;
				}
				
			}
			
		}
		
		return ret;
    }
};
