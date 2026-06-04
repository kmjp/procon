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

int N,M;
set<int> E[202020];

vector<vector<int>> V;
int C[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].insert(y-1);
		E[y-1].insert(x-1);
	}
	queue<int> Q;
	FOR(i,N) if(E[i].size()==3) Q.push(i);
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		if(E[cur].size()!=3) continue;
		vector<int> A={cur};
		FORR(e,E[cur]) {
			A.push_back(e);
			E[e].erase(cur);
			if(E[e].size()==3) Q.push(e);
		}
		V.push_back(A);
		E[cur].clear();
	}
	x=0;
	FOR(i,N) if(E[i].size()) {
		C[i]=x++;
	}
	assert(x);
	reverse(ALL(V));
	FORR(v,V) {
		C[v[0]]=6-C[v[1]]-C[v[2]]-C[v[3]];
	}
	cout<<"Yes"<<endl;
	FOR(i,N) cout<<C[i]+1<<" ";
	cout<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
