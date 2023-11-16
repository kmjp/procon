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
ll F[2020][2020];
vector<int> E[2020];
vector<pair<pair<int,int>,ll>> Es;

int dfs(int cur,int pre) {
	int C=1;
	
	FORR(e,E[cur]) if(e!=pre) {
		C+=dfs(e,cur);
	}
	FORR(e,E[cur]) if(e==pre) {
		Es.push_back({{cur,pre},(F[pre][pre]-F[pre][cur])/C});
	}
	
	return C;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N;
	set<int> L,R;
	FOR(x,N) {
		if(x) R.insert(x);
		FOR(y,x+1) {
			cin>>F[x][y];
			F[y][x]=F[x][y];
		}
	}
	L.insert(0);
	priority_queue<pair<ll,pair<int,int>>> Q;
	FOR(i,N) if(i) Q.push({F[0][i],{0,i}});
	while(R.size()) {
		//ˆê”Ô‹ß‚¢‚à‚Ì‚ð’T‚·
		while(1) {
			auto p=Q.top();
			x=p.second.first;
			y=p.second.second;
			if(L.count(x)&&L.count(y)) {
				Q.pop();
			}
			else {
				break;
			}
		}
		auto p=Q.top();
		x=p.second.first;
		y=p.second.second;
		Q.pop();
		E[x].push_back(y);
		E[y].push_back(x);
		R.erase(y);
		L.insert(y);
		FORR(r,R) Q.push({F[y][r],{y,r}});
	}
	dfs(0,-1);
	
	FORR2(a,b,Es) {
		cout<<a.first+1<<" "<<a.second+1<<" "<<b<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
