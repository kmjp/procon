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
int A[402020];
int X[402020];
int Y[402020];
int Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		A[i]--;
	}
	FOR(i,N) {
		x=A[i];
		if(x<i) {
			X[0]++;
			X[i-x]--;
			X[i+1]++;
		}
		else {
			X[i+1]++;
			X[N-(x-i)]--;
		}
	}
	FOR(i,N) {
		x=A[N-1-i];
		if(x<i) {
			Y[0]++;
			Y[i-x]--;
			Y[i+1]++;
		}
		else {
			Y[i+1]++;
			Y[N-(x-i)]--;
		}
	}
	FOR(i,N) X[i+1]+=X[i],Y[i+1]+=Y[i];
	x=y=0;
	cout<<X[0]<<endl;
	
	cin>>Q;
	while(Q--) {
		cin>>i;
		if(i==1||i==2) {
			cin>>k;
			if(i==1) y+=N-k;
			if(i==2) y+=k;
			y%=N;
		}
		else {
			x^=1;
			y=N-1-y;
		}
		
		if(x==0) {
			cout<<X[(N-y)%N]<<endl;
		}
		else {
			cout<<Y[N-1-y]<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
