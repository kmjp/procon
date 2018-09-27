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
int P[2020];
vector<int> E[2020];
int A[2020];
int D[2020];
vector<int> C,ret;
int RE[2020];
int L[2020],R[2020],eid;

void dfs(int cur,int d) {
	D[cur]=d;
	L[cur]=eid++;
	if(E[cur].size()==0) C.push_back(cur);
	FORR(e,E[cur]) dfs(e,d+1);
	R[cur]=eid;
}

int lca(int x,int y) {
	while(D[x]>D[y]) x=P[x];
	while(D[x]<D[y]) y=P[y];
	while(x!=y) {
		x=P[x];
		y=P[y];
	}
	return x;
}

int up(int x,int num) {
	while(num--) x=P[x];
	return x;
}

int rotate(int x) {
	static int count=24999;
	count--;
	assert(count>=0);
	//cout<<"rot "<<x<<endl;
	ret.push_back(x);
	vector<int> v;
	while(x) {
		v.push_back(x);
		x=P[x];
	}
	reverse(ALL(v));
	int i;
	FORR(x,v) {
		swap(A[x],A[P[x]]);
		RE[A[x]]=x;
		RE[A[P[x]]]=P[x];
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>P[i+1];
		E[P[i+1]].push_back(i+1);
	}
	FOR(i,N) {
		cin>>A[i];
		RE[A[i]]=i;
	}
	dfs(0,1);
	
	while(1) {
		int NG[2020]={};
		FOR(i,N) if(i!=A[i]) break;
		if(i==N) break;
		
		for(i=N-1;i>=0;i--) {
			FORR(e,E[i]) NG[i]|=NG[e] | (A[i]>A[e]);
			if(!(L[A[i]]<=L[i]&&L[i]<R[A[i]])) NG[i]=1;
		}
		
		x=A[0];
		for(i=N-1;i>=0;i--) if(L[x]<=L[i]&&L[i]<R[x]&&(NG[i]||!(L[x]<=L[A[i]]&&L[A[i]]<R[x]))) {
			rotate(i);
			break;
		}
		/*
		cout<<i<<"  ";
		FOR(i,N) cout<<i<<":"<<A[i]<<"  ";
		cout<<endl;
		*/
	}
	
	
	cout<<ret.size()<<endl;
	FORR(r,ret) cout<<r<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

