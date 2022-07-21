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

int S,T,M;
vector<int> ES[303030];
int V[3030][3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T>>M;
	MINUS(V);
	FOR(i,M) {
		cin>>x>>y;
		x--;
		y-=S+1;
		ES[x].push_back(y);
	}
	FOR(i,S) {
		sort(ALL(ES[i]));
		FORR(b,ES[i]) FORR(a,ES[i]) {
			if(a>=b) break;
			if(V[a][b]>=0) {
				cout<<(i+1)<<" "<<(S+1+a)<<" "<<(V[a][b]+1)<<" "<<(S+1+b)<<endl;
				return;
			}
			V[a][b]=i;
		}
	}
	cout<<-1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
