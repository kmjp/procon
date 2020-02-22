#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
vector<int> E[100010];

int NN[100100],P[100100],B[100100];

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N;
	FOR(i,N-1) {
		cin>>x;
		E[x].push_back(i+1);
	}
	
	for(i=N-1;i>=0;i--) {
		NN[i]=1;
		FOR(j,E[i].size()) {
			NN[i]+=NN[E[i][j]];
			B[i]=max(B[i],NN[E[i][j]]);
		}
		B[i]=max(B[i],N-NN[i]);
	}
	FOR(i,N) _P("%d\n",B[i]);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
