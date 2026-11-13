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
int N,T[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>N;
		set<pair<int,pair<int,int>>> E,S;
		int sum=0;
		for(i=2;E.size()<=N;i+=3) {
			for(x=1;x<=i;x+=3) {
				y=i-x;
				E.insert({x+y,{x,y}});
				S.insert({x+y,{x,y}});
				S.insert({x+y+1,{x,y+1}});
				S.insert({x+y+1,{x+1,y}});
				S.insert({x+y+4,{x+1,y+1}});
				
			}
		}
		
		FOR(i,N) {
			cin>>k;
			if(k==1&&S.size()) {
				auto p=*S.begin();
				S.erase(p);
				E.erase(p);
				x=p.second.first, y=p.second.second;
				cout<<x<<" "<<y<<endl;
			}
			else {
				auto p=*E.begin();
				S.erase(p);
				E.erase(p);
				x=p.second.first, y=p.second.second;
				cout<<x<<" "<<y<<endl;
				
			}
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
