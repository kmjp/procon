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
int P[11202020],E[11202020],C[11202020];

int V[11202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=2;i<=10000000;i++) if(V[i]==0) {
		for(j=i;j<=10000000;j+=i) V[j]=i;
	}
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i]>>E[i];
		C[P[i]]=E[i];
	}
	int D=N;
	for(int r=1;r<=P[N-1]/2;r++) {
		x=r;
		while(x>1) {
			if(C[V[x]]==0) D++;
			C[V[x]]++;
			if(C[V[x]]==0) D--;
			x/=V[x];
		}
		x=P[N-1]+1-r;
		while(x>1) {
			if(C[V[x]]==0) D++;
			C[V[x]]--;
			if(C[V[x]]==0) D--;
			x/=V[x];
		}
		if(D==0) {
			cout<<P[N-1]<<" "<<r<<endl;
			return;
		}
		
	}
	cout<<"-1 -1"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
