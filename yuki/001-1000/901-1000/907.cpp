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

int N,M;
int A[202],B[202],X[202],Y[202];
vector<int> V;

ll mo=1000000007;
ll S[202][202],T[202];

ll P[202][402][205];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	S[1][0]=T[1]=1;
	for(i=2;i<=200;i++) {
		FOR(j,i) {
			if(i%2==0) {
				FOR(x,j) S[i][j]+=S[i-1][x];
			}
			else {
				for(x=j;x<i;x++) S[i][j]+=S[i-1][x];
			}
			
			(S[i][j]=S[i][j]%mo*modpow(i))%=mo;
			T[i]+=S[i][j];
		}
		T[i]%=mo;
	}
	for(i=200;i>=2;i--) T[i]=T[i]*modpow(T[i-1])%mo;
	
	
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		V.push_back(A[i]);
		V.push_back(B[i]);
	}
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	M=V.size()-1;
	FOR(x,M) FOR(y,M) if(V[x]>=A[0]&&V[x]<B[0] && V[y]>=A[1]&&V[y]<B[1]) {
		ll a=(V[x+1]-V[x])*modpow(B[0]-A[0])%mo;
		ll b=(V[y+1]-V[y])*modpow(B[1]-A[1])%mo;
		ll c=a*b%mo;
		if(x<y) {
			(P[1][y][1]+=c)%=mo;
			(P[1][y][0]+=c)%=mo;
		}
		if(x==y) {
			(P[1][y][2]+=c*modpow(2))%=mo;
			(P[1][y][0]+=c*modpow(2))%=mo;
		}
	}
	
	
	for(i=2;i<N;i++) {
		FOR(j,M) if(V[j]>=A[i]&&V[j]<B[i]) {
			ll p=(V[j+1]-V[j])*modpow(B[i]-A[i])%mo;
			if(i%2) {
				FOR(x,j) {
					(P[i][j][1]+=P[i-1][x][0]*p)%=mo;
					(P[i][j][0]+=P[i-1][x][0]*p)%=mo;
				}
			}
			else {
				for(x=j+1;x<M;x++) {
					(P[i][j][1]+=P[i-1][x][0]*p)%=mo;
					(P[i][j][0]+=P[i-1][x][0]*p)%=mo;
				}
			}
			for(x=1;x<=i;x++) {
				(P[i][j][x+1]+=P[i-1][j][x]*p%mo*T[x+1])%=mo;
				(P[i][j][0]+=P[i-1][j][x]*p%mo*T[x+1])%=mo;
			}
		}
	}
	
	ll ret=0;
	FOR(j,M) ret+=P[N-1][j][0];
	cout<<ret%mo<<endl;
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
