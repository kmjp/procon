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


const ll mo=12345;


ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
		int A3=0;
		int A5=0;
		int A823=0;
		ll L=1;
		FORR(g,grid) {
			FORR(v,g) {
				ll x=v;
				while(x%3==0) x/=3, A3++;
				while(x%5==0) x/=5, A5++;
				while(x%823==0) x/=823, A823++;
				L=L*x%mo;
			}
		}
		FORR(g,grid) {
			FORR(v,g) {
				{
					ll x=v;
					while(x%3==0) x/=3, A3--;
					while(x%5==0) x/=5, A5--;
					while(x%823==0) x/=823, A823--;
					L=L*modpow(x,2*4*822-1)%mo;
				}
				ll a=L*modpow(3,A3)%mo*modpow(5,A5)%mo*modpow(823,A823)%mo;
				{
					ll x=v;
					while(x%3==0) x/=3, A3++;
					while(x%5==0) x/=5, A5++;
					while(x%823==0) x/=823, A823++;
					L=L*x%mo;
				}
				v=a;
				
			}
		}
		return grid;
        
    }
};
