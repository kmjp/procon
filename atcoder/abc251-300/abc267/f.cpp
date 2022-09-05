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
vector<int> E[404040];
map<int,int> cand[404040];
int id[404040],D[404040];
int P[404040][20];
int Q;

pair<int,int> farthest(int cur,int pre,int d,vector<int>& D) {
	D[cur]=d;
	pair<int,int> r={d,cur};
	FORR(e,E[cur]) if(e!=pre) r=max(r, farthest(e,cur,d+1,D));
	return r;
}

//両端と間の頂点を返す
pair<int,vector<int>> diameter() { // diameter,center
	vector<int> D[2];
	D[0].resize(N);
	D[1].resize(N);
	auto v1=farthest(0,0,0,D[0]);
	auto v2=farthest(v1.second,v1.second,0,D[0]);
	v1=farthest(v2.second,v2.second,0,D[1]);
	pair<int,vector<int>> R;
	R.first = v2.first;
	//重心を取る場合
	for(int i=N-1;i>=0;i--) if(D[0][i]+D[1][i]==R.first && abs(D[0][i]-D[1][i])<=1) R.second.push_back(i);

	return R;
}

void dfs(int cur,int pre,int cid,int d) {
	P[cur][0]=pre;
	id[cur]=cid;
	D[cur]=d;
	cand[d][cid]=cur;
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,cid,d+1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int nex=N;
	FOR(i,N-1) {
		cin>>x>>y;
		x--,y--;
		E[x].push_back(nex);
		E[y].push_back(nex);
		E[nex].push_back(x);
		E[nex].push_back(y);
		nex++;
	}
	N=nex;
	int root=diameter().second[0];
	
	id[root]=-1;
	D[root]=0;
	cand[0][-1]=root;
	FOR(i,E[root].size()) dfs(E[root][i],root,i,1);
	P[root][0]=root;
	FOR(i,19) {
		FOR(j,N) P[j][i+1]=P[P[j][i]][i];
	}
	cin>>Q;
	while(Q--) {
		int U,K;
		cin>>U>>K;
		U--;
		K*=2;
		if(D[U]>=K) {
			FOR(i,19) if(K&(1<<i)) U=P[U][i];
			cout<<U+1<<endl;
		}
		else {
			int lef=K-D[U];
			if(cand[lef].empty()) {
				cout<<-1<<endl;
			}
			else if(cand[lef].begin()->first!=id[U]) {
				cout<<cand[lef].begin()->second+1<<endl;
			}
			else if(cand[lef].rbegin()->first!=id[U]) {
				cout<<cand[lef].rbegin()->second+1<<endl;
			}
			else {
				cout<<-1<<endl;
			}
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
