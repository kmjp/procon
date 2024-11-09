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

int T,N,D,L[2020];

bitset<2020> B[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>D;
		FOR(i,N) cin>>L[i];
		sort(L,L+N);
		if(L[N-1]+L[N-2]>D) {
			cout<<"No"<<endl;
			continue;
		}
		FOR(i,D+1) B[i].reset();
		B[0][0]=1;
		FOR(i,N-1) {
			for(j=D;j>=0;j--) {
				if(j+L[i]<=D) B[j+L[i]]|=B[j];
				B[j]|=B[j]<<L[i];
			}
		}
		int ok=B[0][D-L[N-1]];
		for(i=0;i<=D;i++) if(i>=L[N-1]&&D-i>=L[N-1]&&B[i][D-i]) ok=1;
		if(ok) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
