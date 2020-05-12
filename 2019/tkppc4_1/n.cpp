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

int N,D;
int A[101010];
int B[101010][20];
int NP,P[20],Q[20];
ll S[101010];

map<ll,int> enumpr(ll n) {
	map<ll,int> V;
	for(ll i=2;i*i<=n;i++) while(n%i==0) V[i]++,n/=i;
	if(n>1) V[n]++;
	return V;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D;
	auto M=enumpr(D);
	FORR(m,M) {
		P[NP]=m.first;
		Q[NP]=m.second;
		NP++;
	}
	
	ll ret=0;
	map<int,int> hist;
	int L=-1;
	FOR(i,N) {
		cin>>A[i];
		S[i+1]=(S[i]+A[i])%D;
		FOR(x,NP) {
			B[i+1][x]=B[i][x];
			y=A[i];
			while(y%P[x]==0) B[i+1][x]++, y/=P[x];
		}
		while(L<i) {
			int ok=1;
			FOR(x,NP) if(B[i+1][x]-B[L+1][x]<Q[x]) ok=0;
			if(ok==0) break;
			L++;
			hist[S[L]]++;
		}
		ret+=hist[S[i+1]];
		
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
