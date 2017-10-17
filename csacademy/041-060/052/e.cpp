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

int N;
vector<int> E[101010];
vector<int> F[101010];
int NG[101010];
int in[101010];
int did[101010];

int dfs(int cur,int pre) {
	F[cur].push_back(0);
	F[cur].push_back(0);
	F[cur].push_back(0);
	FORR(e,E[cur]) if(e!=pre) {
		F[cur].push_back(dfs(e,cur)+1);
	}
	sort(ALL(F[cur]));
	reverse(ALL(F[cur]));
	F[cur].resize(3);
	return F[cur][0];
}

void dfs2(int cur,int pre,int par) {
	F[cur].push_back(par);
	sort(ALL(F[cur]));
	reverse(ALL(F[cur]));
	
	FORR(e,E[cur]) if(e!=pre) {
		if(F[cur][0]==F[e][0]+1) dfs2(e,cur,F[cur][1]+1);
		else dfs2(e,cur,F[cur][0]+1);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
		in[x-1]++;
		in[y-1]++;
	}
	
	FOR(i,N) if(E[i].size()>=3) break;
	if(i==N) return _P("%d\n",N-1);
	dfs(0,-1);
	
	
	FORR(e,E[0]) {
		if(F[0][0]==F[e][0]+1) dfs2(e,0,F[0][1]+1);
		else dfs2(e,0,F[0][0]+1);
	}
	
	priority_queue<pair<int,int>> P;
	FOR(i,N) {
		sort(ALL(F[i]));
		reverse(ALL(F[i]));
		if(F[i][2]>0) {
			NG[i]=F[i][2]+1;
			P.push({NG[i],i});
		}
	}
	
	while(P.size()) {
		auto a=P.top();
		P.pop();
		x=a.second;
		if(NG[x]!=a.first) continue;
		FORR(e,E[x]) if(NG[e]<NG[x]-1) {
			NG[e]=NG[x]-1;
			P.push({NG[e],e});
		}
	}
	
	int ret=0;
	queue<int> Q;
	FOR(i,N) if(NG[i]==0 && in[i]==1) Q.push(i),did[i]++;
	while(Q.size()) {
		ret++;
		x=Q.front();
		Q.pop();
		FORR(e,E[x]) {
			if(did[e] || NG[e]) continue;
			in[e]--;
			if(in[e]==1) {
				did[e]++;
				Q.push(e);
			}
		}
		
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
