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


using VT = string;

vector<int> Zalgo(VT s) {
	vector<int> v(1,s.size());
	for(int i=1,l=-1,r=-1;i<s.size();i++) {
		if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
		else {
			l=i; r=(i>r)?i:(r+1);
			while(r<s.size() && s[r-i]==s[r]) r++;
			v.push_back((r--)-l);
		}
	}
	v.push_back(0);
	return v;
}

const ll mo=1000000007;

const int MAT=2;
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);};};

Mat mulmat(Mat& a,Mat& b,int n=MAT) {
	ll mo2=4*mo*mo;
	int x,y,z; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(x,n) FOR(z,n) FOR(y,n) {
		r.v[x][y] += a.v[x][z]*b.v[z][y];
		if(r.v[x][y]>mo2) r.v[x][y] -= mo2;
	}
	FOR(x,n) FOR(y,n) r.v[x][y]%=mo;
	return r;
}

Mat powmat(ll p,Mat a,int n=MAT) {
	int i,x,y; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(i,n) r.v[i][i]=1;
	while(p) {
		if(p%2) r=mulmat(r,a,n);
		a=mulmat(a,a,n);
		p>>=1;
	}
	return r;
}

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


class Solution {
public:
    int numberOfWays(string s, string t, long long k) {
		int N=t.size();
		t=t+"*"+s+s;
		vector<int> V=Zalgo(t);
		vector<int> T(N);
		int i;
		
		Mat A;
		
		A.v[0][0]=0;
		A.v[0][1]=N-1;
		A.v[1][0]=1;
		A.v[1][1]=N-2;
		A=powmat(k,A);
		ll ret=0;
		FOR(i,N) if(V[N+1+i]>=N) {
			if(i==0) ret+=A.v[0][0];
			else ret+=A.v[1][0];
		}
		return ret%mo;
		
		
        
    }
};
