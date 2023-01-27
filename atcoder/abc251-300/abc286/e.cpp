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
ll A[303];
pair<ll,ll> C[303][303];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(x,N) FOR(y,N) {
		if(x==y) C[x][y]={0LL,A[x]};
		else C[x][y]={1000,1LL<<50};
	}
	FOR(y,N) {
		cin>>s;
		FOR(x,N) {
			if(s[x]=='Y') {
				C[y][x]={1LL,A[x]+A[y]};
			}
		}
	}
	FOR(k,N) FOR(x,N) FOR(y,N) if(x!=k&&x!=y&&k!=y) {
		pair<ll,ll> p={C[x][k].first+C[k][y].first,C[x][k].second+C[k][y].second-A[k]};
		if(p.first<C[x][y].first||(p.first==C[x][y].first&&p.second>C[x][y].second)) C[x][y]=p;
	}
	
	int Q;
	cin>>Q;
	while(Q--) {
		cin>>x>>y;
		x--,y--;
		if(C[x][y].first>300) {
			cout<<"Impossible"<<endl;
		}
		else {
			cout<<C[x][y].first<<" "<<C[x][y].second<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
