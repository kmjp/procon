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
set<int> S;

int gr[505050];

int hoge(int v) {
	if(gr[v]>=0) return gr[v];
	
	int mask=0;
	for(int i=1;i<=min(50,v);i++) {
		int L=max(0,i-2);
		int R=max(0,v-(i+1));
		mask |= 1<<(hoge(L)^hoge(R));
	}
	gr[v]=0;
	while(mask & (1<<gr[v])) gr[v]++;
	return gr[v];
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(gr);
	cin>>N;
	FOR(i,N) cin>>x, S.insert(x);
	
	int pre=*S.begin(),first=*S.begin();
	int nim=0;
	FORR(s,S) {
		if(s>pre+1) {
			nim ^= hoge(pre-first+1);
			first=s;
		}
		pre=s;
	}
	nim ^= hoge(pre-first+1);
	
	if(nim==0) cout<<"Second"<<endl;
	else cout<<"First"<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
