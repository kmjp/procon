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

int N,M,A,B;
string S;
vector<int> E[202020],RE[202020],C[202020][26];
int ok[202020],D[202020],pre[202020];
vector<int> cand;
vector<int> ncand;
queue<int> Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		RE[y-1].push_back(x-1);
	}
	cin>>A>>B;
	A--,B--;
	
	ok[B]=1;
	Q.push(B);
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		FORR(e,RE[x]) if(ok[e]==0) ok[e]=1, Q.push(e);
	}
	if(ok[A]==0) return _P("No way\n");
	
	FOR(i,N) {
		FORR(e,E[i]) if(ok[e]) C[i][S[e]-'a'].push_back(e);
		D[i]=202020;
	}
	
	cand.push_back(A);
	int d=0;
	D[A]=0;
	while(1) {
		if(count(ALL(cand),B)) break;
		d++;
		
		ncand.clear();
		FOR(i,26) {
			FORR(c,cand) FORR(e,C[c][i]) if(D[e]!=d) D[e]=d, pre[e]=c,ncand.push_back(e);
			if(ncand.size()) break;
		}
		swap(cand,ncand);
		
	}
	
	string ret;
	while(B!=A) ret+=S[B], B=pre[B];
	ret+=S[A];
	reverse(ALL(ret));
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
