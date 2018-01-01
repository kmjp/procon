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

int N,M,K;
int D[101],rev[101];
vector<int> E[101];
int dist[1<<16];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,N) rev[i]=-1;
	FOR(i,M) {
		cin>>D[i];
		D[i]--;
		rev[D[i]]=i;
	}
	FOR(i,N) {
		FOR(j,K) {
			cin>>x;
			E[i].push_back(rev[x-1]);
		}
	}
	FOR(i,1<<M) dist[i]=10101010;
	queue<int> Q;
	dist[(1<<M)-1]=0;
	Q.push((1<<M)-1);
	while(Q.size()) {
		int mask=Q.front();
		Q.pop();
		FOR(i,K) {
			int mask2=0;
			FOR(j,M) if(mask&(1<<j)) {
				x=E[D[j]][i];
				if(x>=0) mask2 |= 1<<x;
			}
			if(dist[mask2]>dist[mask]+1) {
				dist[mask2]=dist[mask]+1;
				Q.push(mask2);
			}
		}
	}
	cout<<dist[0]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
