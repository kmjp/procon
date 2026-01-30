#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

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

int T;
ll X[4],Y[4],Z[4];
__int128 PX[4],PY[4],Q[4];
__int128 PX2[4],PY2[4],Q2[4];
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		FOR(i,4) {
			cin>>X[i]>>Y[i]>>Z[i];
		}
		//éÀâe
		FOR(i,3) {
			PX[i]=X[3]*(Z[3]-Z[i])+(X[i]-X[3])*Z[3];
			PY[i]=Y[3]*(Z[3]-Z[i])+(Y[i]-Y[3])*Z[3];
			Q[i]=(Z[3]-Z[i]);
		}
		//ïΩçsà⁄ìÆ
		FOR(i,2) {
			//PX[i]/Q[i]-PX[2]/Q[2]
			PX2[i]=PX[i]*Q[2]-PX[2]*Q[i];
			PY2[i]=PY[i]*Q[2]-PY[2]*Q[i];
			Q2[i]=Q[i]*Q[2];
		}
		//äOêœ
		__int128 V=PX2[0]*PY2[1]-PX2[1]*PY2[0];
		__int128 W=Q2[0]*Q2[1]*2;
		if(V<0) V=-V;
		if(W<0) W=-W;
		V%=mo;
		W%=mo;
		cout<<(ll)V*modpow(W)%mo<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
