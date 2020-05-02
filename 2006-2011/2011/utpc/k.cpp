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
vector<pair<int,int>> E[101010],RE[101010];
vector<int> B;
int base[101010];
int RB[101010];
int F[101010],FI[101010];
ll FD[101010];
int T[101010];
ll TD[101010];
ll mat[1010][1010];


void dfs_check(int cur) {
	if(base[cur]==-2) return;
	base[cur]=-2;
	FORR(e,E[cur]) dfs_check(e.first);
}
void dfs_rcheck(int cur) {
	if(base[cur]==-1) return;
	base[cur]=-1;
	FORR(e,RE[cur]) dfs_rcheck(e.first);
}

pair<int,ll> dfs(int cur,int from,int id,int d) {
	if(base[cur]>=0) return {cur,d};
	F[cur]=from;
	FI[cur]=id;
	FD[cur]=d;
	auto p=dfs(E[cur][0].first,from,id,d+E[cur][0].second);
	T[cur]=p.first;
	TD[cur]=p.second-d;
	return p;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		RE[y-1].push_back({x-1,r});
	}
	dfs_check(0);
	FOR(i,N) if(base[i]==0) return _P("-1\n");
	dfs_rcheck(0);
	FOR(i,N) if(base[i]==-2) return _P("-1\n");
	
	MINUS(F);
	MINUS(FI);
	MINUS(T);
	FOR(i,N) if(i==0 || E[i].size()>1 || RE[i].size()>1) {
		base[i]=B.size();
		B.push_back(i);
	}
	
	FOR(x,1010) FOR(y,1010) mat[x][y]=(x==y?0:1LL<<60);
	
	x=0;
	FOR(i,N) if(base[i]>=0) {
		FORR(e,E[i]) {
			auto ret=dfs(e.first,i,x++,e.second);
			mat[base[i]][base[ret.first]]=min(mat[base[i]][base[ret.first]],ret.second);
		}
	}
	r=B.size();
	FOR(j,r) FOR(x,r) FOR(y,r) mat[x][y]=min(mat[x][y],mat[x][j]+mat[j][y]);
	
	ll sum=0;
	FOR(i,N) {
		int nex=(i+1)%N;
		//cout<<"!"<<i<<" "<<sum<<endl;
		if(FI[i]>=0 && FI[nex]>=0 && FI[i]==FI[nex]&&TD[i]>TD[nex]) {
			sum+=TD[i]-TD[nex];
			continue;
		}
		if(T[i]>=0) {
			x=T[i];
			sum+=TD[i];
		}
		else {
			x=i;
		}
		if(F[nex]>=0) {
			y=F[nex];
			sum+=FD[nex];
		}
		else {
			y=nex;
		}
		sum+=mat[base[x]][base[y]];
	}
	cout<<sum<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
