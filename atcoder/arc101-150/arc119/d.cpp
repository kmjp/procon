#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int H,W;
string S[2525];
set<int> E[5050];
vector<int> R[2525],C[2525];
int vis[5050];
int in[5050];

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit(int num=um) {int i; FOR(i,num) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<5050> uf;


void dfs(int cur,int id) {
	if(cur<2500) R[id].push_back(cur);
	else C[id].push_back(cur);
	vis[cur]=1;
	FORR(e,E[cur]) if(vis[e]==0) dfs(e,id);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) if(S[y][x]=='R') {
			if(uf[y]!=uf[x+2500]) {
				E[y].insert(2500+x);
				E[2500+x].insert(y);
				in[y]++;
				in[x+2500]++;
				uf(y,x+2500);
			}
		}
	}
	int SH[2]={H,H};
	int SW[2]={W,W};
	FOR(y,H) if(vis[y]==0&&E[y].size()) {
		dfs(y,y);
		SH[0]-=R[y].size();
		SW[0]-=C[y].size()-1;
		SH[1]-=R[y].size()-1;
		SW[1]-=C[y].size();
	}
	
	FOR(y,H) if(R[y].size()) {
		if(SH[0]*SW[0]<=SH[1]*SW[1]) {
			in[C[y][0]]+=100;
		}
		else {
			in[R[y][0]]+=100;
		}
	}
	
	vector<vector<int>> ret;
	queue<int> cand;
	FOR(y,H) if(in[y]==1) cand.push(y);
	FOR(x,W) if(in[x+2500]==1) cand.push(x+2500);
	while(cand.size()) {
		int cur=cand.front();
		cand.pop();
		FORR(e,E[cur]) {
			in[e]--;
			E[e].erase(cur);
			if(in[e]==1) cand.push(e);
			if(e<cur) ret.push_back({1,e,cur-2500});
			else ret.push_back({0,cur,e-2500});
		}
	}
	
	cout<<ret.size()<<endl;
	FORR(r,ret) {
		cout<<"XY"[r[0]]<<" "<<r[1]+1<<" "<<r[2]+1<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
