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
//--------------------------

int M;
string S[3];
vector<int> V[3][10];
int mi[3][10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M;
	FOR(i,3) {
		cin>>S[i];
		FOR(j,M) {
			V[i][S[i][j]-'0'].push_back(j);
			V[i][S[i][j]-'0'].push_back(j+M);
			V[i][S[i][j]-'0'].push_back(j+2*M);
		}
	}
	int ret=101010;
	FOR(j,10) {
		FOR(i,3) {
			sort(ALL(V[i][j]));
			if(V[i][j].size()>3) V[i][j].resize(3);
		}
		FORR(a,V[0][j]) {
			FORR(b,V[1][j]) {
				FORR(c,V[2][j]) {
					if(a!=b&&b!=c&&a!=c) ret=min(ret,max({a,b,c}));
				}
			}
		}
		
		
	}
	if(ret>3*M) ret=-1;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
