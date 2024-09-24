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

int T;
int X,Y,M;
set<int> E[202020];
int okA[202020],okB[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>X>>Y>>M;
		FOR(i,X+Y) E[i].clear();
		FOR(i,M) {
			cin>>x>>y;
			E[x-1].insert(y-1);
		}
		
		int sa=0,sb=0;
		while(1) {
			sa=sb=0;
			FOR(i,Y) {
				okB[i]=(rand()<rand());
				sb+=okB[i];
			}
			FOR(i,X) {
				x=0;
				FORR(e,E[i]) x^=okB[e];
				okA[i]=x;
				sa+=x;
			}
			
			if(sa+sb>=(X+Y+1)/2) break;
		}
		cout<<sa<<" "<<sb<<endl;
		FOR(i,X) if(okA[i]) cout<<i+1<<" ";
		cout<<endl;
		FOR(i,Y) if(okB[i]) cout<<i+1<<" ";
		cout<<endl;
	}
		
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
