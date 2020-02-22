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

ll N;
ll A[505][505];

const int prime_max = 1000000;
int NP,prime[100000],divp[prime_max];
map<int,int> M;

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

ll LCM(ll a,ll b) {
	if(a==0) return b;
	if(b==0) return a;
	return a/__gcd(a,b)*b;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	cprime();
	
	vector<int> P[2];
	FOR(i,500) {
		P[0].push_back(prime[i]);
		P[1].push_back(prime[999-i]);
	}
	
	FOR(y,500) FOR(x,500) if((x+y)%2==0) {
		i=(x+y)/2;
		j=(x-y)/2+249;
		A[y][x]=1LL*P[0][i]*P[1][j];
	}
	FOR(y,500) FOR(x,500) if((x+y)%2==1) {
		if(y) A[y][x]=LCM(A[y-1][x],A[y][x]);
		if(x) A[y][x]=LCM(A[y][x-1],A[y][x]);
		if(y<499) A[y][x]=LCM(A[y+1][x],A[y][x]);
		if(x<499) A[y][x]=LCM(A[y][x+1],A[y][x]);
		A[y][x]++;
	}
	
	
	FOR(y,N) {
		FOR(x,N) cout<<A[y][x]<<" ";
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

