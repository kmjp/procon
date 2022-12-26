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

const int prime_max = 1000001;
vector<int> prime;
int NP,divp[prime_max];
int gr[1010101];
	int N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
		set<int> S;
		
		S.insert(0);
		if(divp[i-2]==0 && i-2>=2) {
			S.insert(gr[2]);
			S.insert(gr[i-2]);
		}
		while(S.count(gr[i])) gr[i]++;
	}
	
	int xo=0;
	cin>>N;
	FOR(i,N) {
		cin>>x;
		xo^=gr[x];
	}
	if(xo) cout<<"An"<<endl;
	else cout<<"Ai"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
