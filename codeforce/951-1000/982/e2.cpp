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

int T,N,A[101010],X[101010];

int gr(int A,int X) {
	int x,k;
	int A2=0;
	int good=0;
	for(x=29;x>=0;x--) {
		if(X&(1<<x)) {
			A2*=2;
			if(good||(A&(1<<x))) A2++;
		}
		else if(A&(1<<x)) good++;
	}
	for(k=1;k<=30;k++) if(A2==(1<<k)-2) return 0;
	for(k=0;k<=30;k++) if(A2==(1<<k)-1) return k;
	for(k=0;k<=30;k++) if(A2==(1<<k)) return (k^1);
	for(k=2;k<=30;k++) if(A2>(1<<k)&&A2<(1<<(k+1))-2) return k+1;
	
	return 0;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>A[i];
		FOR(i,N) cin>>X[i];
		int nim=0;
		FOR(i,N) nim^=gr(A[i],X[i]);
		if(nim) {
			cout<<"Alice"<<endl;
		}
		else {
			cout<<"Bob"<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
