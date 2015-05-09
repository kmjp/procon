#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int R,C,K,N;

int X[102000];
int Y[102000];

int RR[102000];
int CC[102000];
map<int,int> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>R>>C>>K>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		X[i]--,Y[i]--;
		RR[X[i]]++;
		CC[Y[i]]++;
	}
	FOR(i,C) M[CC[i]]++;
	
	ll ret=0;
	FOR(i,R) ret += M[K-RR[i]];
	FOR(i,N) {
		if(RR[X[i]]+CC[Y[i]]==K+1) ret++;
		if(RR[X[i]]+CC[Y[i]]==K) ret--;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
