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

int Q;
ll D,K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>D>>K;
		int rx=1010,ry=1010;
		
		set<pair<int,int>> S;
		FOR(i,D+1) {
			S.insert({i,D-i});
			S.insert({-i,D-i});
			S.insert({i,-(D-i)});
			S.insert({-i,-(D-i)});
		}
		FORR2(x,y,S) {
			int a=0,b=0;
			FORR2(xx,yy,S) {
				if(xx*xx+yy*yy<x*x+y*y) a++;
				if(xx*xx+yy*yy<=x*x+y*y) b++;
			}
			if(a<K&&b>=K) rx=x,ry=y;
		}
		if(rx==1010) cout<<"No"<<endl;
		else {
			cout<<"Yes"<<endl;
			cout<<rx<<" "<<ry<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
