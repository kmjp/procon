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

int N;
string S;
vector<int> E[202020];

vector<pair<int,int>> V[202020];
vector<pair<int,int>> L[202020],R[202020];
int A[202020],B[202020];
ll ret=0;
map<int,pair<int,int>> memo[202020];

pair<int,int> dfs(int cur,int pre) {
	V[cur].resize(E[cur].size());
	
	int D=0, is=S[cur], i;
	FOR(i,E[cur].size()) {
		int r=E[cur][i];
		if(r!=pre) {
			V[cur][i]=dfs(r,cur);
			V[cur][i].first++;
			D=max(D,V[cur][i].first);
			is|=V[cur][i].second;
		}
	}
	return memo[cur][pre] = make_pair(D,is);
}

void dfs2(int cur,int pre,pair<int,int> par) {
	par.first++;
	int i;
	
	FOR(i,E[cur].size()) {
		int r=E[cur][i];
		if(r==pre) V[cur][i]=par;
	}
	L[cur].resize(E[cur].size());
	R[cur].resize(E[cur].size());
	L[cur][0].second = R[cur].back().second = S[cur];
	for(i=1;i<L[cur].size();i++) {
		L[cur][i].first=max(L[cur][i-1].first,V[cur][i-1].first);
		L[cur][i].second=L[cur][i-1].second | V[cur][i-1].second;
	}
	for(i=R[cur].size()-2;i>=0;i--) {
		R[cur][i].first=max(R[cur][i+1].first,V[cur][i+1].first);
		R[cur][i].second=R[cur][i+1].second | V[cur][i+1].second;
	}
	FOR(i,E[cur].size()) {
		int r=E[cur][i];
		if(r!=pre) {
			pair<int,int> p={max(L[cur][i].first,R[cur][i].first),L[cur][i].second|R[cur][i].second};
			memo[cur][r]=p;
			dfs2(r,cur,p);
		}
	}
	
}

void centerv(int a) {
	vector<pair<int,int>> C=V[a];
	
	C.push_back({0,S[a]});
	C.push_back({0,S[a]});
	
	sort(ALL(C));
	reverse(ALL(C));
	int Rmax=C[1].first;
	int Rmin=201010;
	FORR(v,C) if(v.second) Rmin=min(Rmin,v.first);
	
	if(Rmin<=Rmax) {
		ret+=Rmax-Rmin+1;
	}
}

void centere(int a,int b) {
	pair<int,int> p[2]={memo[a][b],memo[b][a]};
	
	if(p[0].first<p[1].first) {
		ret+=p[0].second;
	}
	else if(p[0].first>p[1].first) {
		ret+=p[1].second;
	}
	else {
		ret++;
	}

}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>A[i]>>B[i];
		A[i]--, B[i]--;
		E[A[i]].push_back(B[i]);
		E[B[i]].push_back(A[i]);
	}
	cin>>S;
	FORR(c,S) c-='0';
	
	auto p=dfs(0,-1);
	dfs2(0,-1,{0,0});
	FOR(i,N) centerv(i);
	FOR(i,N-1) centere(A[i],B[i]);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
