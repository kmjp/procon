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
string S;
ll mo=1000000007;
vector<ll> C,R;
const int PAT=5;
vector<ll> A[PAT];
vector<ll> B[PAT];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	srand(time(NULL));
	FOR(i,PAT) {
		C.push_back(rand()%10000000+10000000);
		R.push_back(modpow(C.back()));
		A[i].push_back(1);
		B[i].push_back(0);
	}
	reverse(ALL(S));
	FORR(c,S) {
		FOR(i,PAT) {
			if(c=='+') {
				A[i].push_back(A[i].back());
				B[i].push_back((B[i].back()+1)%mo);
			}
			if(c=='-') {
				A[i].push_back(A[i].back());
				B[i].push_back((B[i].back()+mo-1)%mo);
			}
			if(c=='>') {
				A[i].push_back(A[i].back()*C[i]%mo);
				B[i].push_back(B[i].back()*R[i]%mo);
			}
			if(c=='<') {
				A[i].push_back(A[i].back()*R[i]%mo);
				B[i].push_back(B[i].back()*C[i]%mo);
			}
		}
	}
	ll ret=0;
	map<vector<ll>,int> memo;
	memo[vector<ll>(PAT,0)]++;
	FOR(j,N) {
		vector<ll> BA(PAT),BAS(PAT);
		FOR(i,PAT) {
			BA[i]=B[i][j+1]*A[i][j+1]%mo;
			BAS[i]=(B[i][j+1]+mo-B[i].back())*A[i][j+1]%mo;
		}
		ret+=memo[BAS];
		memo[BA]++;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
