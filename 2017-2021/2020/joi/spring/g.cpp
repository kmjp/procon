//#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

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

template<class V,int NV> class SegTree_Pair {
public:
	vector<pair<V,int> > val;
	static V const def=0;
	pair<V,int> comp(pair<V,int> l,pair<V,int> r){ return max(l,r);}
	SegTree_Pair(){
		val.resize(NV*2,make_pair(-1,0));
	};
	pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return make_pair(-1,NV);
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=make_pair(v,entry-NV);
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_Pair<int,1<<18> hei;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,19> bt;

int N;
int H[202020];
int TN[202020];

int cur;
int L[202020],R[202020],CH[202020],P[202020];
vector<int> fin[202020];
vector<int> E[202020];
int M;
int X[202020],Y[202020],C[202020];
multiset<pair<int,int>> node[202020];

ll dp[202020];
ll sum;



void dfs2(int cur) {
	FORR(e,E[cur]) {
		dfs2(e);
		
		dp[cur]+=dp[e];
		if(node[cur].size()<node[e].size()) swap(node[e],node[cur]);
		FORR(n,node[e]) node[cur].insert(n);
	}
	FORR(e,E[cur]) {
		bt.add(L[cur],dp[e]);
		bt.add(L[e],-dp[e]);
		bt.add(R[e],dp[e]);
		bt.add(R[cur],-dp[e]);
	}
	while(node[cur].size()) {
		int i=node[cur].begin()->second;
		if(cur&&Y[i]>=CH[P[cur]]) break;
		node[cur].erase(node[cur].begin());
		dp[cur]=max(dp[cur],bt(X[i])+C[i]);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>H[i];
		hei.update(i,H[i]+1);
	}
	
	L[0]=0;
	R[0]=N;
	cur=1;
	FOR(i,cur) {
		x=L[i];
		y=R[i];
		auto t=hei.getval(x,y);
		CH[i]=t.first;
		fin[i].push_back(y);
		while(1) {
			auto t2=hei.getval(x,y);
			if(t2.first!=t.first) break;
			fin[i].push_back(t2.second);
			TN[t2.second]=i;
			y=t2.second;
		}
		fin[i].push_back(x-1);
		reverse(ALL(fin[i]));
		FOR(x,fin[i].size()-1) if(fin[i][x]+1<fin[i][x+1]) {
			L[cur]=fin[i][x]+1;
			R[cur]=fin[i][x+1];
			P[cur]=i;
			E[i].push_back(cur);
			cur++;
		}
	}
	cin>>M;
	FOR(i,M) {
		cin>>X[i]>>Y[i]>>C[i];
		X[i]--;
		node[TN[X[i]]].insert({Y[i],i});
		sum+=C[i];
	}
	dfs2(0);
	
	cout<<(sum-dp[0])<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
