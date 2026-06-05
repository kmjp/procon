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
ll state;
ll M,F;
ll P[3030303],C[3030303];
vector<int> E[3030303];

int freq[3101010];
int cnt[3101010];
int ma=0;

int L[3030303],R[3030303],rev[3030330];
int id;
ll ret;
const ll mo=998244353;


void clear(int e) {
	for(int v=L[e];v<R[e];v++) {
		int u=rev[v];
		cnt[C[u]]=0;
	}
	int i;
	FOR(i,ma+1) freq[i]=0;
	ma=0;
}

void add(int v) {
	int c=C[v];
	if(cnt[c]!=0) freq[cnt[c]]--;
	cnt[c]++;
	freq[cnt[c]]++;
	ma=max(ma,cnt[c]);
	
}


void dfs2(int cur) {
	FORR(e,E[cur]) if(e!=E[cur].back()) {
		dfs2(e);
		clear(e);
	}
	
	if(E[cur].size()) {
		dfs2(E[cur].back());
		FORR(e,E[cur]) if(e!=E[cur].back()) {
			for(int v=L[e];v<R[e];v++) add(rev[v]);
		}
	}
	add(cur);
	ret+=1LL*(ma^(cur+1))*(freq[ma]^(cur+1));
	ret%=mo;
	
}
void dfs(int cur) {
	L[cur]=id++;
	rev[L[cur]]=cur;
	FORR(e,E[cur]) dfs(e);
	R[cur]=id;
	int i;
	FOR(i,E[cur].size()) {
		if(R[E[cur][i]]-L[E[cur][i]]>R[E[cur][0]]-L[E[cur][0]]) {
			swap(E[cur][i],E[cur][0]);
		}
	}
	reverse(ALL(E[cur]));
}
	

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>state>>M>>F;
	for(i=1;i<N;i++) {
		if(i<M) {
			cin>>P[i];
			P[i]--;
		}
		else {
			P[i]=state%i;
			state = (state * 1103515245 + 12345) % (1LL<<31);
		}
		E[P[i]].push_back(i);
	}
	FOR(i,N) {
		if(i<M) {
			cin>>C[i];
			C[i]--;
		}
		else {
			C[i]=state%F;
			state = (state * 1103515245 + 12345) % (1LL<<31);
		}
	}
	dfs(0);
	dfs2(0);
	
	cout<<ret<<endl;
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
