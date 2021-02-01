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
int vcant[202020],vng[202020]; //自身が戻れない頂点か、子方向に戻れない頂点があるか

vector<int> cant[202020]; //子頂点方向で戻れない頂点
vector<int> ng[202020]; //子頂点方向で不可頂点

//戻れない辺を持つ子をカウント
pair<int,int> dfs(int cur,int pre) { //戻れない辺の有無・不可頂点の有無
	sort(ALL(E[cur]));
	int mc=0;
	FORR(e,E[cur]) if(e<pre) vcant[cur]=1;
	FORR(e,E[cur]) if(e!=pre) {
		auto p=dfs(e,cur);
		mc=max(mc,e);
		if(p.first) cant[cur].push_back(e), vcant[cur]=1;
		if(p.second) ng[cur].push_back(e);
	}
	
	vng[cur]=ng[cur].size()>0;
	if(vng[cur]==0&&cant[cur].size()>=2) {
		vng[cur]=1;
	}
	if(vng[cur]==0&&cant[cur].size()==1) {
		//隣接点のうち最小でないし子のうち最大でもない
		if(cant[cur][0]!=E[cur][0] && cant[cur][0]!=mc) {
			vng[cur]=1;
		}
	}
	
	return {vcant[cur], vng[cur]};
}

void dfs2(int cur,int pre,int pcant,int png) {
	
	if(pcant) cant[cur].push_back(pre);
	if(png) ng[cur].push_back(pre);
	
	/*
	cout<<"--------------"<<cur<<" "<<pre<<" "<<pcant<<" "<<png<<endl;
	FORR(c,cant[cur]) cout<<"cant"<<c<<" ";
	FORR(c,ng[cur]) cout<<"ng"<<c<<" ";
	cout<<endl;
	*/
	vng[cur]=ng[cur].size()>0;
	if(vng[cur]==0&&cant[cur].size()>=2) {
		vng[cur]=1;
	}
	if(vng[cur]==0&&cant[cur].size()==1) {
		//隣接点のうち最小でないし子のうち最大でもない
		if(cant[cur][0]!=E[cur][0] && cant[cur][0]!=E[cur].back()) {
			vng[cur]=1;
		}
	}
	
	FORR(e,E[cur]) if(e!=pre) {
		int ncant=0, nng=0;
		
		if(ng[cur].size()>=2||(ng[cur].size()==1&&vng[e]==0)) {
			nng=1;
		}
		else if(cant[cur].size()>=3||(cant[cur].size()==2&&vcant[e]==0)) {
			nng=1;
		}
		else if((cant[cur].size()==1&&vcant[e]==0)||(cant[cur].size()==2&&vcant[e]==1)) {
			int tar=cant[cur][0];
			if(tar==e) tar=cant[cur][1];
			if(tar!=E[cur][0]&&tar!=E[cur].back()&&!(e==E[cur].back()&&tar==E[cur][E[cur].size()-2])) {
				nng=1;
			}
		}
		
		if(nng==0) {
			if(cant[cur].size()>=2) ncant=1;
			if(cant[cur].size()>=1&&cant[cur][0]!=e) ncant=1;
			if(e!=E[cur][0]) ncant=1;
		}
		
		
		
		
		dfs2(e,cur,ncant,nng);
	}
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,0);
	dfs2(0,0,0,0);
	FOR(i,N) {
		if(vng[i]) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
