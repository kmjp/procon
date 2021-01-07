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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>Y;
	
	if(X==0&&Y==0) {
		cout<<"1 1"<<endl;
	}
	else if(X==0) {
		cout<<2*Y<<" "<<Y<<endl;
	}
	else if(Y==0) {
		cout<<X<<" "<<2*X<<endl;
	}
	else if(X==Y) {
		cout<<-1<<endl;
	}
	else if(X>Y) {
		cout<<X<<" "<<X+Y<<endl;
	}
	else {
		cout<<X+Y<<" "<<Y<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
