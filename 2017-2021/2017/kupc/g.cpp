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
vector<int> E[101];
int mat[101][101];
ll X;
vector<int> C[2];

void dfs(int cur,int pre,int d) {
	C[d].push_back(cur);
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,d^1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>s;
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
		mat[x][y]=mat[y][x]=1;
	}
	vector<int> V;
	
	if(s=="encode") {
		dfs(1,1,0);
		
		if(C[0].size()<C[1].size()) swap(C[0],C[1]);
		if(C[1].size()) C[1].pop_back();
		cin>>X;
		
		vector<pair<int,int>> E;
		FOR(i,2) {
			V=C[i];
			
			if(V.size()<10) continue;
			FOR(j,V.size()-1) E.push_back({V[j],V[j+1]});
			E.push_back({V[2],V[V.size()-2]});
			for(j=4;j<V.size()-2;j++) {
				if(X%2) E.push_back({V[2],V[j]});
				X/=2;
			}
		}
		
		
		cout<<E.size()<<endl;
		FORR(e,E) cout<<e.first<<" "<<e.second<<endl;
	}
	else {
		FOR(i,N+1) FOR(x,N+1) FOR(y,N+1) mat[x][y]|=mat[x][i]&&mat[i][y];
		vector<vector<int>> Vs;
		int order=0;
		X=0;
		for(int step=0;step<2;step++) {
			for(x=1;x<=N;x++) if(E[x].size()==1 && E[E[x][0]].size()==2) {
				for(y=1;y<=N;y++) if(mat[x][y] && x!=y && E[y].size()==1 && E[E[y][0]].size()>2) {
					V.clear();
					r=E[E[x][0]][0];
					if(r==x) r=E[E[x][0]][1];
					int cur=E[y][0];
					int pre=y;
					while(1) {
						V.push_back(cur);
						int nex=-1;
						FORR(e,E[cur]) {
							if(e==pre || e==r) continue;
							assert(nex==-1);
							nex=e;
						}
						if(nex==-1) break;
						pre=cur;
						cur=nex;
					}
					if(step==0 && V.size()<=45) continue;
					if(step==1 && V.size()>45) continue;
					
					reverse(ALL(V));
					for(i=1;i<V.size()-1;i++) {
						if(order>60) continue;
						if(count(ALL(E[V[i]]),r)) X |= 1LL<<order;
						order++;
					}
				}
			}
		}
		
		cout<<X<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
