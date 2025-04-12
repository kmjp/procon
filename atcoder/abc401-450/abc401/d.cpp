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

int N,K;
string S;

int Lmi[202020];
int Lma[202020];
int Rmi[202020];
int Rma[202020];
string T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S;
	
	FOR(i,N) if(S[i]=='?') {
		if(i&&S[i-1]=='o') S[i]='.';
		if(i+1<N&&S[i+1]=='o') S[i]='.';
	}
	FOR(i,N) {
		Lmi[i+1]=Lmi[i]+(S[i]=='o');
		if(Lma[i]%2==1) Lma[i+1]=Lma[i]+(S[i]!='o');
		else Lma[i+1]=Lma[i]+(S[i]!='.');
	}
	for(i=N-1;i>=0;i--) {
		Rmi[i+1]=Rmi[i+2]+(S[i]=='o');
		if(Rma[i+2]%2==1) Rma[i+1]=Rma[i+2]+(S[i]!='o');
		else Rma[i+1]=Rma[i+2]+(S[i]!='.');
	}
	
	T=S;
	FOR(i,N) if(T[i]=='?') {
		if(Lmi[N]==K) {
			T[i]='.';
			continue;
		}
		x=(Lma[i]+1)/2+(Rma[i+2]+1)/2;
		y=(Lma[i])/2+(Rma[i+2])/2;
		if(x>=K&&y+1>=K) T[i]='?';
		else if(y+1>=K) T[i]='o';
		else if(x>=K) T[i]='.';
		else assert(0);
	}
	cout<<T<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
