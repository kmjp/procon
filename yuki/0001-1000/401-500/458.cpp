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

const int prime_max = 20000;
int NP,prime[100000],divp[prime_max];
map<int,int> M;

void cprime() {
	for(int i=2;i<20000;i++) if(divp[i]==0) {
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>i&&j<prime_max;j+=i) divp[j]=i;
	}
}
int N;
int ma[20202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	MINUS(ma);
	ma[0]=0;
	FOR(i,NP) {
		x=prime[i];
		for(j=20000-x;j>=0;j--) if(ma[j]>=0) ma[j+x]=max(ma[j+x],ma[j]+1);
	}
	
	cin>>N;
	cout<<ma[N]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
