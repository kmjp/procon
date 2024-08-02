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

ll T,N,A[55];

vector<pair<int,int>> R;
void go(int a,int b) {
	R.push_back({a+1,b+1});
	A[a]+=A[b];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		R.clear();
		int ma=0,mi=0;
		int nmi=0,nma=0;
		FOR(i,N) {
			cin>>A[i];
			if(A[i]<A[mi]) mi=i;
			if(A[i]>A[ma]) ma=i;
			if(A[i]<0) nmi++;
			if(A[i]>0) nma++;
		}
		
		
		if(A[mi]!=A[ma]) {
			if(nmi>=13) {
				FOR(i,5) go(mi,mi);
			}
			else if(nma>=13) {
				FOR(i,5) go(ma,ma);
			}
			if(abs(A[mi])>abs(A[ma])) {
				FOR(i,N) if(A[i]>0) go(i,mi);
				for(i=N-2;i>=0;i--) {
					mi=0;
					FOR(j,N) if(A[j]<A[mi]) mi=j;
					go(i,mi);
				}
			}
			else {
				FOR(i,N) if(A[i]<0) go(i,ma);
				for(i=1;i<N;i++) {
					ma=0;
					FOR(j,N) if(A[j]>A[ma]) ma=j;
					go(i,ma);
				}
			}
		}
		
		
		FOR(i,N-1) assert(A[i]<=A[i+1]);
		
		cout<<R.size()<<endl;
		FORR2(a,b,R) cout<<a<<" "<<b<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
