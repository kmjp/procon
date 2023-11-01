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

ll X,Y;

void enemy() {
	string s;
	int x,y;
	cin>>s;
	if(s=="A") {
		cin>>x>>y;
		if(x==1) X-=y;
		else Y-=y;
	}
	else if(s=="B") {
		X=Y=0;
	}
	else {
		exit(0);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>Y;
	if((X+1==Y&&X%2)||(Y+1==X&&Y%2)) {
		cout<<"Second"<<endl;
		enemy();
	}
	else {
		cout<<"First"<<endl;
	}
	while(1) {
		if(X==Y) {
			cout<<"B"<<endl;
			X=Y=0;
		}
		else if(X>Y) {
			if(Y==0) {
				x=X;
			}
			else if(Y%2) {
				x=X-(Y+1);
			}
			else {
				x=X-(Y-1);
			}
			cout<<"A 1 "<<x<<endl;
			X-=x;
		}
		else {
			if(X==0) {
				y=Y;
			}
			else if(X%2) {
				y=Y-(X+1);
			}
			else {
				y=Y-(X-1);
			}
			cout<<"A 2 "<<y<<endl;
			Y-=y;
		}
		enemy();
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
