#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int M[101];
vector<ll> D[10002];
int grundy[100002];
vector<ll> enumdiv(ll n) {
	vector<ll> V;
	for(ll i=2;i*i<=n;i++) {
		if(n%i==0) V.push_back(i);
		while(n%i==0) n/=i;
	}
	if(n>1) V.push_back(n);
	return V;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=10000;i++) D[i]=enumdiv(i);
	for(i=2;i<=10000;i++) {
		int mex[101]={};
		FOR(j,D[i].size()) {
			int p=D[i][j];
			mex[grundy[i/p]]++;
			if(i%(p*p)==0) mex[grundy[i/(p*p)]]++;
			while(mex[grundy[i]]) grundy[i]++;
		}
	}
	
	cin>>x;
	int nim=0;
	while(x--) cin>>y, nim ^= grundy[y];
	if(nim!=0) cout <<"Alice" <<endl;
	else cout <<"Bob" <<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
