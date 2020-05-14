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

int N,M;
int S,T;
vector<int> E[101010];
int D[2][303030];
int num[2][303030];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S>>T;
	S--,T--;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
		
	}
	FOR(i,N) D[0][i]=D[1][i]=1<<30;
	D[0][S]=D[1][T]=0;
	
	
	queue<int> Q;
	Q.push(S);
	Q.push(N+T);
	while(Q.size()) {
		int cur=Q.front()%N;
		int id=Q.front()/N;
		Q.pop();
		num[id][D[id][cur]]++;
		FORR(e,E[cur]) if(D[id][e]>D[id][cur]+1) {
			D[id][e]=D[id][cur]+1;
			Q.push(id*N+e);
		}
	}
	
	ll ret=0;
	int d=D[0][T];
	if(d>=2) FOR(i,d-1) ret+=1LL*num[0][i]*num[1][d-2-i];
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
