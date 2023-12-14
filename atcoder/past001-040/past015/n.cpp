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

int N,M;
vector<int> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	double S=0;
	FOR(i,M) {
		cin>>x;
		while(x--) {
			V.push_back(i);
			S+=i;
		}
	}
	S/=N;
	if(N%2==0) {
		x=N/2-1;
		y=N/2;
	}
	else {
		x=y=N/2;
	}
	
	double A=(V[x]+V[y])/2.0;
	if(S>A) {
		FORR(v,V) v=M-1-v;
		reverse(ALL(V));
	}
	S=A=0;
	FORR(v,V) S+=v;
	S/=N;
	A=(V[x]+V[y])/2.0;
	double dif=A-S;
	
	FOR(i,N) {
		if(i<=x&&V[i]==V[x]) continue;
		if(i==y) continue;
		dif-=1.0/N;
	}
	
	if(dif<0) dif=0;
	_P("%.12lf\n",dif);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
