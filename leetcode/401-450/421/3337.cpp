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

const ll mo=1000000007;

const int MAT=26;
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

class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
		Mat A;
		int x,y;
		FOR(x,26) {
			FOR(y,nums[x]) A.v[(x+1+y)%26][x]=1;
		}
		A=powmat(t,A);
		int C[26]={};
		FORR(c,s) C[c-'a']++;
		
		ll ret=0;
		FOR(y,26) FOR(x,26) ret+=C[y]*A.v[x][y];
		return ret%mo;
        
    }
};
