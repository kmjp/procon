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
int A[101],P[101];
vector<int> R;

void go(int x) {
	R.push_back(x);
	int y=(x+A[x])%N;
	swap(A[x],A[y]);
	P[A[x]]=x;
	P[A[y]]=y;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		P[A[i]]=i;
	}
	
	for(i=1;i<N-1;i++) {
		while((P[i]+1)%N!=P[i+1]) {
			for(j=1;j<=i;j++) go(P[j]);
		}
	}
	
	
	while(1) {
		FOR(i,N) if(A[i]!=i) break;
		if(i==N) break;
		go(P[1]);
	}
	
	FOR(i,N) assert(A[i]==i);
	
	cout<<R.size()<<endl;
	FORR(c,R) cout<<c<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
