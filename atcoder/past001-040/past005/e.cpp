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

int H,W,H2,W2;
string S[10];
vector<string> T;

vector<string> rotate(vector<string> S) {
	vector<string> T;
	int H=S.size(),W=S[0].size(),x,y;
	FOR(x,W) T.push_back(string(H,' '));
	FOR(y,H) FOR(x,W) T[W-1-x][y]=S[y][x]; //left
	//FOR(y,H) FOR(x,W) T[x][y]=S[H-1-y][x]; //right
	return T;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	T.resize(H);
	FOR(y,H) cin>>T[y];
	FOR(i,4) {
		
		for(y=-10;y<=10;y++) {
			for(x=-10;x<=10;x++) {
				int ok=1;
				int y2,x2;
				FOR(y2,T.size()) FOR(x2,T[0].size()) if(T[y2][x2]=='#') {
					if(y2+y<0||y2+y>=H||x2+x<0||x2+x>=W) ok=0;
					if(ok&&S[y2+y][x2+x]=='#') ok=0;
					
				}
				if(ok) {
					cout<<"Yes"<<endl;
					return;
				}
			}
		}
		
		
		T=rotate(T);
	}
	cout<<"No"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
