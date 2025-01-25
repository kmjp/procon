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

int H,W;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	if(H*W==1) {
		cout<<"! 1 1"<<endl;
		return;
	}
	if(H==1||W==1) {
		int v;
		cout<<"? 1 1"<<endl;
		cin>>v;
		FOR(y,H) FOR(x,W) if(y*y+x*x==v) {
			cout<<"! "<<y+1<<" "<<x+1<<endl;
			return;
		}
	}
	else {
		int a,b;
		cout<<"? 1 1"<<endl;
		cin>>a;
		cout<<"? 1 2"<<endl;
		cin>>b;
		FOR(y,H) FOR(x,W) if(y*y+x*x==a&&y*y+(x-1)*(x-1)==b) {
			cout<<"! "<<y+1<<" "<<x+1<<endl;
			return;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
