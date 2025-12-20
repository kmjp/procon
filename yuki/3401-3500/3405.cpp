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
vector<int> Es[202020];
int P[202020];
vector<pair<int,int>> E2[202020];
vector<int> E[202020];
int NC[202020];
vector<pair<int,int>> cand;

void dfs(int cur,int pre) {
	P[cur]=pre;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		E2[cur].push_back({E[e].size(),e});
		NC[cur]++;
	}
	sort(ALL(E2[cur]));
	reverse(ALL(E2[cur]));
}

pair<int,int> dfs2(int cur,int pre,int k) {
	int sum=0;
	int more=0;
	while(E2[cur].size()&&E2[cur].back().first<k) E2[cur].pop_back();
	FORR2(a,e,E2[cur]) {
		auto p=dfs2(e,cur,k);
		//cout<<cur<<" "<<k<<" "<<e<<" "<<p.first<<" "<<p.second<<endl;
		sum+=p.second;
		if(p.first!=p.second) more++;
	}
	if(NC[cur]-more>=k) {
		//cout<<cur<<"  "<<sum+1<<" "<<sum+1<<endl;
		return {sum+1,sum+1};
	}
	else if(NC[cur]-more+1>=k) {
		//cout<<cur<<"  "<<sum<<" "<<sum+1<<endl;
		return {sum,sum+1};
	}
	else {
		//cout<<cur<<"  "<<sum<<" "<<sum<<endl;

		return {sum,sum};
	}
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>k;
		FOR(j,k) {
			cin>>x;
			Es[x].push_back(i);
			E[i].push_back(x);
		}
		cand.push_back({k,i});
	}
	FOR(i,N) {
		FORR(e,E[i]) {
			if(Es[e][0]==i) e=Es[e][1];
			else e=Es[e][0];
		}
	}
	dfs(0,0);
	sort(ALL(cand));
	reverse(ALL(cand));
	
	for(i=1;i<=N-1;i++) {
		while(cand.size()&&cand.back().first<i) cand.pop_back();
		
		int ret=0;
		FORR2(a,b,cand) if(b==0||E[P[b]].size()<i) {
			auto p=dfs2(b,b,i);
			if(b==0) ret+=p.first;
			else ret+=p.second;
		}
		cout<<ret<<" ";
	}
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
