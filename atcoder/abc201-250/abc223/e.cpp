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


ll X,Y,A,B,C;

void go(ll X,ll Y,ll A,ll B,ll C) {
	A=(A+(X-1))/X;
	Y-=A;
	if(Y<=0) return;
	B=(B+Y-1)/Y;
	C=(C+Y-1)/Y;
	if(B+C<=X) {
		cout<<"Yes"<<endl;
		exit(0);
	}
}
void go2(ll X,ll Y,ll A,ll B,ll C) {
	A=(A+X-1)/X;
	B=(B+X-1)/X;
	C=(C+X-1)/X;
	if(A+B+C<=Y) {
		cout<<"Yes"<<endl;
		exit(0);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>Y>>A>>B>>C;
	go(X,Y,A,B,C);
	go(X,Y,B,A,C);
	go(X,Y,C,A,B);
	go(Y,X,A,B,C);
	go(Y,X,B,A,C);
	go(Y,X,C,A,B);
	go2(X,Y,A,B,C);
	go2(Y,X,A,B,C);
	cout<<"No"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
