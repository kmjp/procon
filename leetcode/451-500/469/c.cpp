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


ll from[2020],to[2020];
const ll mo=1000000007;
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
		int m=r-l+1;
		
		ZERO(from);
		//èââÒup
		int i,j;
		FOR(i,m) from[i]=i;
		for(i=2;i<n;i++) {
			ZERO(to);
			ll sum=0;
			if(i%2==0) {
				for(j=m-1;j>=0;j--) {
					to[j]=sum;
					(sum+=from[j])%=mo;
				}
			}
			else {
				FOR(j,m) {
					to[j]=sum;
					(sum+=from[j])%=mo;
				}
			}
			
			swap(from,to);
		}
		ll ret=0;
		FOR(i,m) ret+=from[i];
		return ret*2%mo;
        
    }
};


