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
int A;
map<int,int> M;
unordered_map<int,int> U;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int mi=1<<30;
	FOR(i,N) {
		cin>>A;
		mi=min(mi,A);
		vector<int> V;
		for(j=1;j*j<=A;j++) if(A%j==0) V.push_back(j),V.push_back(A/j);
		
		FORR(v,V) U[v]=__gcd(U[v],A);
	}
	int ret=0;
	FORR2(a,b,U) if(a==b&&a<=mi) ret++;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
