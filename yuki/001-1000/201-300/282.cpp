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
int id[501];
char res[501][10];
pair<int,int> H[501];

void solve() {
	int i,j,k,l,r,x,y; string s;
	int ON;
	
	cin>>N;
	
	ON=N;
	if(N%2) N++;
	FOR(i,N) H[i].second=i+1;
	
	FOR(x,N-1) {
		id[N-1]=N-1;
		FOR(j,N-1) {
			if(j<N/2) id[j]=(x+j)%(N-1);
			else id[N-2-(j-N/2)]=(x+j)%(N-1);
		}
		_P("?");
		FOR(i,ON) {
			if(i+N/2<ON) _P(" %d %d",id[i]+1,id[i+N/2]+1);
			else _P(" 0 0");
		}
		_P("\n");
		fflush(stdout);
		FOR(i,ON) cin>>res[i];
		
		FOR(i,N/2-ON%2) {
			if(res[i][0]=='<') H[id[i+N/2]].first++;
			if(res[i][0]=='>') H[id[i]].first++;
		}
	}
	sort(H,H+ON);
	_P("!");
	FOR(i,ON) _P(" %d",H[i].second);
	_P("\n");
	fflush(stdout);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
