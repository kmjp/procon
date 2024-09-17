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

int N;
vector<int> E[101010];
string S;

ll ret;
int vis[101010];
int NV[101010];
vector<int> D;
template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;




int dfs(int cur,int pre) {
	NV[cur]=1;
	FORR(e,E[cur]) if(e!=pre && vis[e]==0) NV[cur]+=dfs(e,cur);
	return NV[cur];
}

int dfs2(int cur,int pre,int TNV) {
	int tot=1;
	int ok=1;
	FORR(e,E[cur]) if(e!=pre && vis[e]==0) {
		int c = dfs2(e,cur,TNV);
		if(c!=-1) return c;
		tot += NV[e];
		if(NV[e]*2>TNV) ok=0;
	}
	if((TNV-tot)*2>TNV) ok=0;
	if(ok) return cur;
	return -1;
}

void dfs3(int cur,int pre,int d) {
	if(S[cur]=='1') d++;
	else d--;
	D.push_back(d);
	FORR(e,E[cur]) if(e!=pre && vis[e]==0) dfs3(e,cur,d);
}

void split(int cur,int id) {
	int TNV = dfs(cur,-1);
	if(TNV==0) return;
	int center=dfs2(cur,-1,TNV);
	
	vector<int> V;
	int x;
	if(S[center]=='1') {
		x=1;
		ret++;
		
	}
	else {
		x=-1;
	}
	bt.add((1<<19)+x,1);
	V.push_back(x);
	D.clear();
	FORR(e,E[center]) if(vis[e]==0) {
		D.clear();
		dfs3(e,center,0);
		FORR(d,D) ret+=bt((1<<20)-1)-bt((1<<19)-d);
		FORR(d,D) {
			V.push_back(d+x);
			bt.add((1<<19)+d+x,1);
		}
	}
	FORR(v,V) bt.add((1<<19)+v,-1);
	vis[center]=1;
	FORR(e,E[center]) if(vis[e]==0) split(e,id+1);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	cin>>S;
	split(0,0);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
