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

ll p[101010];
int m2[101010];
int m5[101010];

ll modpow(ll a, ll n, ll mo) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

class Solution {
public:
    bool hasSameDigits(string s) {
		int N=s.size();
		
		int rev[10]={1,1,1,7,1,1,1,3,1,9};
		
		int i;
		p[0]=p[N-1]=1;
		m2[0]=m2[N-1]=m5[0]=m5[N-1]=0;
		for(i=1;i<=N-2;i++) {
			p[i]=p[i-1];
			m2[i]=m2[i-1];
			m5[i]=m5[i-1];
			int x=i;
			int y=N-1-i;
			while(y%2==0) m2[i]++, y/=2;
			while(y%5==0) m5[i]++, y/=5;
			while(x%2==0) m2[i]--, x/=2;
			while(x%5==0) m5[i]--, x/=5;
			p[i]=p[i]*(y%10)*rev[x%10]%10;
		}
		
		int a=0,b=0;
		FOR(i,N-1) {
			ll v=p[i]*modpow(2,m2[i],10)*modpow(5,m5[i],10)%10;
			a+=(s[i]-'0')*v;
			b+=(s[i+1]-'0')*v;
		}
        return a%10==b%10;
    }
};
