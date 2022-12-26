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

int N,M,P;
int S,G;
vector<int> E[202020];
int D[101010][2][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>P;
	cin>>S>>G;
	S--,G--;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	FOR(i,N) D[i][0][0]=D[i][1][0]=D[i][0][1]=D[i][1][1]=(1<<30)-1;
	queue<int> Q;
	D[S][0][0]=D[G][1][0]=0;
	Q.push(S*4);
	Q.push(G*4+2);
	while(Q.size()) {
		int cur=Q.front()/4;
		int id=Q.front()/2%2;
		int odd=Q.front()%2;
		int co=D[cur][id][odd]+1;
		Q.pop();
		FORR(e,E[cur]) if(D[e][id][odd^1]>co) {
			D[e][id][odd^1]=co;
			Q.push(e*4+id*2+(odd^1));
		}
	}
	
	vector<int> V;
	FOR(i,N) {
		int ok=0;
		FOR(x,2) FOR(y,2) {
			ll co=D[i][0][x]+D[i][1][y];
			if(co<=P&&(P-co)%2==0) ok=1;
			
		}
		if(ok) V.push_back(i);
	}
	
	if(V.empty()) {
		cout<<-1<<endl;
	}
	else {
		cout<<V.size()<<endl;
		FORR(v,V) cout<<v+1<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
