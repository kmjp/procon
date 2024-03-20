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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<pair<int,int>> E;
	FOR(i,200000/5-1) {
		
		if(i==10000) {
			E.push_back({i*5,i*5+1});
			E.push_back({i*5+1,i*5+2});
			E.push_back({i*5+2-5,i*5+1});
		}
		else if(i==10001) {
			E.push_back({i*5-2,i*5+1-2});
			E.push_back({i*5+1-2,i*5+2-2});
			E.push_back({i*5+2-2,i*5+3-2});
			E.push_back({i*5+3-2,i*5+4-2});
			E.push_back({i*5+1-5,i*5+2-2});
		}
		else if(i<10000) {
			E.push_back({i*5,i*5+1});
			E.push_back({i*5+1,i*5+2});
			E.push_back({i*5+2,i*5+3});
			E.push_back({i*5+3,i*5+4});
			if(i) E.push_back({i*5+2-5,i*5+2});
		}
		else if(i>10001) {
			E.push_back({i*5-2,i*5+1-2});
			E.push_back({i*5+1-2,i*5+2-2});
			E.push_back({i*5+2-2,i*5+3-2});
			E.push_back({i*5+3-2,i*5+4-2});
			E.push_back({i*5+2-5-2,i*5+2-2});
		}
	}
	cout<<E.size()+1<<endl;
	FORR2(a,b,E) cout<<a+1<<" "<<b+1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
