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
vector<pair<int,int>> E[101010];
int D[101010];

int vis[202020];
int ng[201010];
int cand[201010];
map<int,int> num;
int te;

void dfs(int cur,int ne,int d) {
	D[cur]=d;
	FORR(e,E[cur]) if(e.second!=ne) {
		if(vis[e.second]) continue;
		vis[e.second]=1;
		if(D[e.first]>=0) {
			if((D[cur]-D[e.first])%2==1) {
				ng[cur]++;
				ng[e.first]--;
			}
			else {
				te++;
				cand[cur]++;
				cand[e.first]--;
			}
		}
		else {
			dfs(e.first,e.second,d+1);
			cand[cur]+=cand[e.first];
			ng[cur]+=ng[e.first];
		}
	}
	//cout<<cur<<" "<<d<<" "<<ng[cur]<<" "<<cand[cur]<<endl;
	if(ne!=-1) {
		if(ng[cur]==0) num[cand[cur]]++;
	}
}


pair<int,int> hoge(int i) {
	num.clear();
	te=0;
	dfs(i,-1,0);
	/*
	cout<<te<<" ";
	FORR(n,num) cout<<n.first<<":"<<n.second<<" ";
	cout<<endl;
	*/
	if(te==0) return {1,num[0]};
	if(te==1) return {0,1+num[1]};
	return {0,num[te]};
}




void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back({y-1,i});
		E[y-1].push_back({x-1,i});
	}
	
	MINUS(D);
	pair<int,int> ret={1,0};
	FOR(i,N) if(D[i]<0) {
		auto p=hoge(i);
		ret={ret.first*p.first,ret.second*p.first+ret.first*p.second};
	}
	cout<<ret.second<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
