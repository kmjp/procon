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
vector<int> E[101010];
int S,T;

int D[101010][3];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		x--;y--;
		E[x].push_back(y);
	}
	cin>>S>>T;
	S--,T--;
	FOR(i,N) D[i][0]=D[i][1]=D[i][2]=1<<30;
	queue<int> Q;
	D[S][0]=0;
	Q.push(S*3);
	while(Q.size()) {
		int cur=Q.front()/3;
		int m=Q.front()%3;
		int n=(m+1)%3;
		Q.pop();
		FORR(e,E[cur]) {
			if(D[e][n]>D[cur][m]+1) {
				D[e][n]=D[cur][m]+1;
				Q.push(e*3+n);
			}
		}
	}
	
	if(D[T][0]<1<<30) cout<<D[T][0]/3<<endl;
	else cout<<-1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
