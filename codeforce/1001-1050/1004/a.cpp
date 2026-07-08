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

int T,N;
int X[202020];
vector<int> V[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		x=y=0;
		FOR(i,N+1) V[i].clear();
		FOR(i,N) {
			cin>>X[i];
			V[X[i]].push_back(i+1);
		}
		x=y=0;
		for(i=1;i<=N;i++) if(V[i].size()==0) {
			x=i;
			break;
		}
		if(x==0) {
			FOR(x,N) {
				if(X[x]==1) i=x+1;
				if(X[x]==N) j=x+1;
			}
			cout<<"? "<<i<<" "<<j<<endl;
			cin>>x;
			cout<<"? "<<j<<" "<<i<<endl;
			cin>>y;
			if(x>=N-1&&y>=N-1) {
				cout<<"! B"<<endl;
			}
			else {
				cout<<"! A"<<endl;
			}
		}
		else {
			y=x+1;
			if(y>N) y=1;
			cout<<"? "<<x<<" "<<y<<endl;
			cin>>x;
			if(x) {
				cout<<"! B"<<endl;
			}
			else {
				cout<<"! A"<<endl;
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
