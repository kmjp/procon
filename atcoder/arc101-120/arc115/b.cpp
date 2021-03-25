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
int C[505][505];

ll A[505];
ll B[505];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) {
		FOR(x,N) {
			cin>>C[y][x];
			if(C[0][0]+C[y][x]!=C[y][0]+C[0][x]) return _P("No\n");
		}
	}
	
	FOR(y,N) A[y]=C[y][0];
	FOR(x,N) B[x]=C[0][x]-A[0];
	ll mi=1LL<<60;
	FOR(x,N) mi=min(mi,B[x]);
	if(mi<0) {
		FOR(x,N) B[x]-=mi;
		FOR(y,N) A[y]+=mi;
		
	}
	
	cout<<"Yes"<<endl;
	FOR(y,N) cout<<A[y]<<" ";
	cout<<endl;
	FOR(y,N) cout<<B[y]<<" ";
	cout<<endl;
	
	
	
	
}



int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
