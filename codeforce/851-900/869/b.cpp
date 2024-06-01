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

int T,N,M;
vector<int> E[2020];
int vis[2020];
vector<int> R;
vector<int> ok;
set<int> SE[2020];
void dfs(int cur,int pre,int tar) {
	if(ok.size()) return;
	if(cur==tar&&pre!=cur) {
		ok=R;
		return;
	}
	if(vis[cur]) {
		return;
	}
	vis[cur]=1;
	R.push_back(cur);
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,tar);
	R.pop_back();
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N) E[i].clear(),SE[i].clear();
		ok.clear();
		FOR(i,M) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
			SE[x-1].insert(y-1);
			SE[y-1].insert(x-1);
		}
		vector<pair<int,int>> ret;
		FOR(i,N) if(E[i].size()>=4) {
			ZERO(vis);
			R.clear();
			dfs(i,i,i);
			if(ok.empty()) continue;
			
			for(j=2;j<ok.size();j++) {
				if(SE[i].count(ok[j])) {
					while(ok.size()>j+1) ok.pop_back();
					break;
				}
			}
			FOR(j,ok.size()) ret.push_back({ok[j],ok[(j+1)%ok.size()]});
			int lef=2;
			FORR(e,E[i]) if(lef&&e!=ok[1]&&e!=ok.back()) {
				ret.push_back({i,e});
				lef--;
			}
			break;
		}
		
		if(ret.size()) {
			cout<<"YES"<<endl;
			cout<<ret.size()<<endl;
			FORR2(a,b,ret) cout<<a+1<<" "<<b+1<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
			
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
