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
int P[101010];
vector<int> rev[101010];
int did[101010],clear[101010];
int in[101010];

int D[101010],pre[101010];

void dfs(int cur) {
	if(clear[P[cur]]==0) {
		cout<<cur<<" "<<P[cur]<<endl;
		clear[P[cur]]=1;
	}
	FORR(e,rev[cur]) dfs(e);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=1;i<=N;i++) {
		cin>>P[i];
		in[P[i]]++;
	}
	queue<int> Q;
	for(i=1;i<=N;i++) {
		if(in[i]==0) Q.push(i);
	}
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		did[x]=1;
		rev[P[x]].push_back(x);
		if(D[P[x]]<D[x]+1) {
			D[P[x]]=D[x]+1;
			pre[P[x]]=x;
		}
		in[P[x]]--;
		if(in[P[x]]==0) Q.push(P[x]);
	}
	int ma=0;
	int best=0;
	for(i=1;i<=N;i++) if(in[i]&&did[i]==0) {
		vector<int> L;
		int ok=i;
		L.push_back(i);
		while(P[L.back()]!=i) {
			if(D[L.back()]) ok=L.back();
			if(D[P[L.back()]]) ok=P[L.back()];
			
			L.push_back(P[L.back()]);
		}
		L.clear();
		L.push_back(ok);
		while(P[L.back()]!=ok) L.push_back(P[L.back()]);
		for(x=L.size()-2;x>=0;x--) {
			cout<<L[x]<<" "<<L[x+1]<<endl;
			clear[L[x+1]]=1;
		}
		
		FORR(l,L) {
			did[l]=1;
			FORR(e,rev[l]) dfs(e);
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
