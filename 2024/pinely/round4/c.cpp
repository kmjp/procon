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

int T,N,A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>A[i];
		vector<int> V;
		
		FOR(i,40) {
			sort(A,A+N);
			if(A[0]%2!=A[N-1]%2) break;
			if(A[0]==0&&A[N-1]==0) break;
			x=(A[0]+A[N-1])/2;
			V.push_back(x);
			FOR(j,N) A[j]=abs(A[j]-x);
			sort(A,A+N);
		}
		if(A[0]||A[N-1]) {
			cout<<-1<<endl;
		}
		else {
			FOR(i,N) assert(A[i]==0);
			cout<<V.size()<<endl;
			FORR(v,V) cout<<v<<" ";
			cout<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
