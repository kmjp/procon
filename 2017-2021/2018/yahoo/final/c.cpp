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

int N,Q;
set<int> E[101010];
vector<int> QQ[101010];
int QD[101010];
int VD[101010];

ll ret[101010];
int NV[101010];
map<int,int> MP[101010];
vector<int> C[101010];

int dfs(int cur,int pre) {
	NV[cur]=1;
	FORR(e,E[cur]) if(e!=pre) NV[cur]+=dfs(e,cur);
	return NV[cur];
}

int dfs2(int cur,int pre,int TNV) {
	int tot=1;
	int ok=1;
	FORR(e,E[cur]) if(e!=pre) {
		int c = dfs2(e,cur,TNV);
		if(c!=-1) return c;
		tot += NV[e];
		if(NV[e]*2>TNV) ok=0;
	}
	if((TNV-tot)*2>TNV) ok=0;
	if(ok) return cur;
	return -1;
}
void dfs3(int cur,int pre,int base,int d) {
	C[base].push_back(cur);
	MP[base][d]++;
	VD[cur]=d;
	FORR(e,E[cur]) if(e!=pre) dfs3(e,cur,base,d+1);
}

void split(int cur) {
	int TNV = dfs(cur,-1);
	if(TNV==0) return;
	int center=dfs2(cur,-1,TNV);
	
	MP[center].clear();
	MP[center][0]++;
	set<int> T;
	swap(T,E[center]);
	FORR(e,T) E[e].erase(center);
	FORR(e,T) {
		MP[e].clear();
		C[e].clear();
		dfs3(e,center,e,1);
		FORR(m,MP[e]) MP[center][m.first]+=m.second;
	}
	
	FORR(q,QQ[center]) ret[q]+=MP[center][QD[q]];
	FORR(e,T) {
		FORR(m,MP[e]) MP[center][m.first]-=m.second;
		FORR(v,C[e]) FORR(q,QQ[v]) ret[q]+=MP[center][QD[q]-VD[v]];
		FORR(m,MP[e]) MP[center][m.first]+=m.second;
	}
	
	FORR(e,T) split(e);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].insert(y-1);
		E[y-1].insert(x-1);
	}
	FOR(i,Q) {
		cin>>x>>QD[i];
		QQ[x-1].push_back(i);
	}
	
	split(0);
	
	FOR(i,Q) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
