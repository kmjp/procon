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

const int prime_max = 1000000;
int NP,prime[100000],divp[prime_max];
int K,N;

// ２回以上行うならNP,prime,divを要クリア
void cprime() {
	int i,j;
	for(i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime[NP++]=i;
		for(j=i;j<prime_max;j+=i) divp[j]=i;
	}
}

int hash(int v) {
	while(v>=10) v=v/10+v%10;
	return v;
}

vector<pair<int,int> > V;
void solve() {
	int i,j,k,l,r,x,y; string s;
	cprime();
	
	cin>>K>>N;
	for(i=K;i<=N;i++) if(divp[i]==i) {
		j=i;
		while(j>=10) j=j/10+j%10;
		V.push_back(make_pair(i,j));
	}
	
	x=y=-1;
	FOR(i,V.size()) {
		int mask=0;
		FOR(j,100) {
			if(i+j>=V.size()) break;
			if(mask & (1<<(V[i+j].second))) break;
			if((j+1)>=y) x=V[i].first,y=j+1;
			mask |= 1<<(V[i+j].second);
		}
	}
	
	
	_P("%d\n",x);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
