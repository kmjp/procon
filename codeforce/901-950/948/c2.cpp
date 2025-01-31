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

int T,N;
ll A[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		set<int> As;
		FOR(i,N) {
			cin>>A[i];
			As.insert(A[i]);
		}
		sort(A,A+N);
		ll g=1;
		FOR(i,N) {
			g=g*A[i]/__gcd(g,A[i]);
			if(g>A[N-1]) break;
		}
		if(g!=A[N-1]) {
			cout<<N<<endl;
			continue;
		}
		set<int> S;
		for(i=1;i*i<=A[N-1];i++) if(A[N-1]%i==0) {
			S.insert(i);
			S.insert(A[N-1]/i);
		}
		map<int,int> from,to;
		FOR(i,N) {
			x=A[i];
			to=from;
			to[x]=1;
			FORR2(a,b,from) {
				y=a/__gcd(a,x)*x;
				to[y]=max(to[y],b+1);
			}
			from=to;
		}
		
		int ma=0;
		FORR2(a,b,from) {
			if(As.count(a)==0) ma=max(ma,b);
		}
		cout<<ma<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
