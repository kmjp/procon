#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W,Q,Y,X;;
vector<vector<ll>> A;

int ZR[101010],ZC[101010];
ll PR[101010],PC[101010];
ll P,Z;
const ll mo=1000000007;

ll modpow(ll a, ll n=mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(i,101010) PR[i]=PC[i]=1;
	P=1;
	A.resize(H);
	FOR(y,H) {
		A[y].resize(W);
		FOR(x,W) {
			cin>>A[y][x];
			
			if(A[y][x]==0) {
				ZR[y]++;
				ZC[x]++;
				Z++;
			}
			else {
				(PR[y]*=A[y][x])%=mo;
				(PC[x]*=A[y][x])%=mo;
				(P*=A[y][x])%=mo;
			}
		}
	}
	
	cin>>Q;
	while(Q--) {
		cin>>Y>>X;
		Y--,X--;
		int tz=Z-ZR[Y]-ZC[X];
		if(A[Y][X]==0) tz++;
		
		if(tz>0) {
			cout<<0<<endl;
		}
		else {
			ll ret=P*modpow(PR[Y])%mo*modpow(PC[X])%mo;
			if(A[Y][X]) (ret*=A[Y][X])%=mo;
			cout<<ret<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
