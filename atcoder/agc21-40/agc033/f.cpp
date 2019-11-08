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
vector<int> E[2020];
set<int> S[2020];

int D[2020][2020];
bitset<2020> B[2020],C[2020];
ll ret;

void dfs(int cur,int pre,int id,int d) {
	D[id][cur]=d;
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,id,d+1);
}

void add(int a,int b) {
	if(a==b || S[a].count(b)) return;
	
	int i;
	FOR(i,2) {
		FORR(e,S[a]) {
			if(D[a][e]+D[e][b]==D[a][b]) {
				add(e,b);
				return;
			}
			if(D[a][b]+D[b][e]==D[a][e]) {
				vector<pair<int,int>> V;
				vector<int> W;
				V.push_back({a,b});
				V.push_back({b,e});
				
				int te=e;
				S[a].erase(te);
				S[te].erase(a);
				FORR(e,S[a]) if(D[a][b]+D[b][e]==D[a][e]) W.push_back(e);
				FORR(w,W) S[a].erase(w),S[w].erase(a),V.push_back({b,w});
				FORR(v,V) add(v.first,v.second);
				return;
			}
		}
		swap(a,b);
	}
	S[a].insert(b);
	S[b].insert(a);
}

void dfs2(int cur,int pre,int root) {
	FORR(e,S[cur]) if(D[root][e]+D[e][cur]==D[root][cur]) B[cur] |= B[e];
	FORR(e,E[cur]) if(e!=pre) dfs2(e,cur,root);
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(i,N) dfs(i,i,i,0);
	
	FOR(i,M) {
		cin>>x>>y;
		add(x-1,y-1);
	}
	
	FOR(i,N) {
		FOR(x,N) {
			B[x]=B[2000];
			B[x][x]=1;
		}
		dfs2(i,i,i);
		FOR(x,N) C[x]|=B[x];
	}
	FOR(i,N) ret+=C[i].count()-1;
	
	cout<<ret/2<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
