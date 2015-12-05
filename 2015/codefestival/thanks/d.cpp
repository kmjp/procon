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

int N;
int S[1010],T;
int know[51][51],ks[51],kn[51];
int M,A,B,C;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	MINUS(know);
	FOR(i,N) {
		cin>>S[i];
		T+=S[i];
		know[i][i]=ks[i]=S[i];
		kn[i]=N-1;
	}
	cin>>M;
	while(M--) {
		cin>>A>>B>>C;
		B--,C--;
		if(A==0) {
			if(know[B][C]==-1) {
				know[B][C]=S[C];
				ks[B]+=S[C];
				kn[B]--;
			}
		}
		else {
			if(know[B][C]==-1) _P("%d %d\n",max(0,min(100,T-ks[B]-(kn[B]-1)*100)),min(100,T-ks[B]));
			else _P("%d %d\n",S[C],S[C]);
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
