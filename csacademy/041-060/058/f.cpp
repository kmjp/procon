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
int U[101010],V[101010];
map<pair<int,int>,int> M;
vector<int> E[101010];

int inloop[101010],rl[101010];
int NL;
int vis[101010];
vector<int> st;

int D[101010];
int ma;

int ret[101010];
int Rma[101010];
int Rdia[101010];
int Lma[101010];
int Ldia[101010];


void dfs(int cur,int pre) {
	if(vis[cur]==2) return;
	if(vis[cur]==1) {
		int x=st.size()-1,step=0;
		while(st[x]!=cur) {
			inloop[st[x]]=step;
			step++;
			vis[st[x]]=2;
			x--;
		}
		inloop[cur]=step++;
		vis[cur]=2;
		return;
	}
	vis[cur]=1;
	st.push_back(cur);
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur);
	st.pop_back();
}

int dfs2(int cur,int pre,int d) {
	vector<int> dv;
	int mad=d;
	FORR(e,E[cur]) {
		if(e==pre) continue;
		if(inloop[e]>=0) continue;
		dv.push_back(dfs2(e,cur,d+1));
	}
	dv.push_back(d);
	dv.push_back(d);
	sort(ALL(dv));
	reverse(ALL(dv));
	ma=max(ma,dv[0]);
	ma=max(ma,dv[0]+dv[1]-2*d);
	return dv[0];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	MINUS(inloop);
	FOR(i,N) {
		cin>>U[i]>>V[i];
		U[i]--;
		V[i]--;
		M[{U[i],V[i]}]=M[{V[i],U[i]}]=i;
		E[U[i]].push_back(V[i]);
		E[V[i]].push_back(U[i]);
	}
	MINUS(ret);
	dfs(0,-1);
	
	FOR(i,N) if(inloop[i]>=0) {
		NL++;
		D[inloop[i]]=dfs2(i,-1,0);
		rl[inloop[i]]=i;
	}
	
	int hoge=0;
	for(i=NL-1;i>=0;i--) {
		Rma[i]=max(Rma[i+1],(NL-1)-i+D[i]);
		Rdia[i]=max({Rdia[i+1],ma,hoge+D[i]-i});
		hoge=max(hoge,i+D[i]);
	}
	hoge=-10101010;
	FOR(i,NL) {
		Lma[i]=max((i)?Lma[i-1]:0,i+D[i]);
		Ldia[i]=max({(i)?Ldia[i-1]:0,ma,i+D[i]+hoge});
		hoge=max(hoge,D[i]-i);
		
		if(i<NL-1) {
			ret[M[{rl[i],rl[i+1]}]]=max({Rdia[i+1],Ldia[i],Lma[i]+Rma[i+1]+1});
		}
	}
	
	ret[M[{rl[NL-1],rl[0]}]]=Ldia[NL-1];
	
	FOR(i,N) cout<<ret[i]<<endl;
	
}



int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
