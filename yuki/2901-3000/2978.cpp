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

int N,Q;

int ask(int L1,int L2) {
	int x;
	cout<<"? "<<L1<<" "<<N<<" "<<L2<<" "<<N<<endl;
	cin>>x;
	return x;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	if(ask(1,2)) {
		x=1,y=2;
	}
	else {
		x=2,y=1;
	}
	for(i=3;i<N;i+=2) {
		int a,b;
		if(ask(i,i+1)) {
			a=i,b=i+1;
		}
		else {
			a=i+1,b=i;
		}
		if(ask(a,x)) x=a;
		if(ask(y,b)) y=b;
	}
	cout<<"! "<<x<<" "<<x<<" "<<y<<" "<<N<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
