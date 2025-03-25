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
vector<int> E[102];
int did[102][102];
vector<int> X[2];
int C[101];
void dfs(int cur,int pre,int c) {
	C[cur]=c;
	X[c].push_back(cur);
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,c^1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
		did[x][y]=did[y][x]=1;
	}
	dfs(1,1,0);
	
	int NE=X[0].size()*X[1].size()-(N-1);
	if(NE%2==1) {
		cout<<"First"<<endl;
	}
	else {
		cout<<"Second"<<endl;
		cin>>x>>y;
		if(x==-1) return;
		did[x][y]=did[y][x]=1;
	}
	while(1) {
		for(y=1;y<=N;y++) for(x=1;x<y;x++) if(did[x][y]==0&&C[x]!=C[y]) {
			cout<<x<<" "<<y<<endl;
			did[x][y]=did[y][x]=1;
			goto out;
		}
		assert(0);
		out:
		cin>>x>>y;
		if(x==-1) return;
		did[x][y]=did[y][x]=1;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
