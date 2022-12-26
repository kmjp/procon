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
int P[101010];
vector<int> E[101010];
int A[101010],B[101010];

map<int,int> M[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>P[i+1];
		E[P[i+1]-1].push_back(i+1);
	}
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	
	for(i=N-1;i>=0;i--) {
		FORR(e,E[i]) {
			if(M[i].size()<M[e].size()) swap(M[i],M[e]);
			FORR2(a,b,M[e]) M[i][a]=b;
		}
		y=B[i];
		while(y) {
			auto it=M[i].lower_bound(A[i]);
			if(it==M[i].begin()) break;
			it--;
			x=min(y,it->second);
			it->second-=x;
			y-=x;
			if(it->second==0) M[i].erase(it);
		}
		M[i][A[i]]=B[i];
	}
	
	ll ret=0;
	FORR2(m,v,M[0]) ret+=v;
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
