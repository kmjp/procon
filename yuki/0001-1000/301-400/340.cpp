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

int H,W,N;
vector<int> L[1000000];
int R[1000001],B[1000001];
int dist[1000001],vis[1000001];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W>>H>>N;
	FOR(i,N) {
		cin>>x;
		int pre=-1;
		FOR(j,x+1) {
			cin>>y;
			if(pre!=-1) {
				if(abs(y-pre)<W) R[min(y,pre)]=max(R[min(y,pre)],abs(y-pre));
				else B[min(y,pre)]=max(B[min(y,pre)],abs(y-pre)/W);
			}
			pre=y;
		}
	}
	
	FOR(y,H) FOR(x,W) {
		int id=y*W+x;
		dist[id]=1<<30;
		if(x) R[id]=max(R[id],R[id-1]-1);
		if(y) B[id]=max(B[id],B[id-W]-1);
		if(R[id] && x<W-1) L[id].push_back(id+1),L[id+1].push_back(id);
		if(B[id] && y<H-1) L[id].push_back(id+W),L[id+W].push_back(id);
	}
	
	dist[0]=0;
	queue<int> Q;
	Q.push(0);
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		FORR(r,L[cur]) if(dist[r]>dist[cur]+1) {
			dist[r]=dist[cur]+1;
			Q.push(r);
		}
	}
	if(dist[W*H-1]<1<<20) _P("%d\n",dist[W*H-1]);
	else _P("Odekakedekinai..\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
