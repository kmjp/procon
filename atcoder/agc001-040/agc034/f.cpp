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

int N;
int A[1<<18],S;
const ll mo=998244353;
vector<ll> V,W;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

vector<ll> hoge(vector<ll>& A,vector<ll>& B) {
	int n=A.size();
	vector<ll> R(n);
	
	if(n==1) {
		if(A[0]==0) {
			R[0]=0;
		}
		else {
			R[0]=B[0]*modpow(A[0])%mo;
		}
	}
	else {
		vector<ll> C[2],D[2],E[2];
		int i;
		FOR(i,2) C[i].resize(n/2),D[i].resize(n/2);
		FOR(i,n) {
			if(i%2==0) {
				C[0][i/2]+=A[i];
				D[0][i/2]+=B[i];
				C[1][i/2]+=A[i];
				D[1][i/2]+=B[i];
			}
			else {
				C[0][i/2]+=A[i];
				D[0][i/2]+=B[i];
				C[1][i/2]+=mo-A[i];
				D[1][i/2]+=mo-B[i];
				C[0][i/2]%=mo;
				D[0][i/2]%=mo;
				C[1][i/2]%=mo;
				D[1][i/2]%=mo;
			}
		}
		E[0]=hoge(C[0],D[0]);
		E[1]=hoge(C[1],D[1]);
		FOR(i,n) {
			if(i%2==0) {
				R[i]=(E[0][i/2]+E[1][i/2])*(mo+1)/2%mo;
			}
			else {
				R[i]=(E[0][i/2]+mo-E[1][i/2])*(mo+1)/2%mo;
			}
		}
		
	}
	
	return R;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,1<<N) {
		cin>>x;
		V.push_back(x);
		S+=x;
		if(i==0) {
			W.push_back((1<<N)-1);
		}
		else {
			W.push_back(mo-1);
		}
	}
	FOR(i,1<<N) {
		V[i]=V[i]*modpow(S)%mo;
		if(i==0) V[i]=(V[i]+mo-1)%mo;
	}
	
	auto R=hoge(V,W);
	FOR(i,1<<N) if(i) R[i]=(R[i]+mo-R[0])%mo;
	R[0]=0;
	
	FOR(i,1<<N) cout<<R[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
