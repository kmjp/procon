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
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		int ok=0;
		
		FOR(x,2) FOR(y,2) {
			if(x==0&&S[0]=='1') continue;
			if(x==1&&S[0]=='0') continue;
			if(y==0&&S[1]=='1') continue;
			if(y==1&&S[1]=='0') continue;
			int from[2][2]={};
			from[x][y]=1;
			
			for(i=2;i<N;i++) {
				int to[2][2]={};
				int a,b,c;
				FOR(a,2) FOR(b,2) if(from[a][b]) {
					FOR(c,2) {
						if(c==0&&S[i]=='1') continue;
						if(c==1&&S[i]=='0') continue;
						if(a==b&&b==c) continue;
						to[b][c]=1;
					}
				}
				swap(from,to);
			}
			
			if(from[0][0]&&x==1) ok=1;
			if(from[1][1]&&x==0) ok=1;
			if(from[0][1]&&x==0) ok=1;
			if(from[0][1]&&x==1&&y==0) ok=1;
			if(from[1][0]&&x==1) ok=1;
			if(from[1][0]&&x==0&&y==1) ok=1;
		}
		
		
		if(ok) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
