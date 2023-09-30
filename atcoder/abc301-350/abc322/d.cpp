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

vector<string> rotate(vector<string> S) {
	vector<string> T;
	int H=S.size(),W=S[0].size(),x,y;
	FOR(x,W) T.push_back(string(H,' '));
	FOR(y,H) FOR(x,W) T[W-1-x][y]=S[y][x]; //left
	//FOR(y,H) FOR(x,W) T[x][y]=S[H-1-y][x]; //right
	return T;
}

vector<string> S[3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int sum=0;
	FOR(i,3) {
		S[i].resize(4);
		FOR(y,4) {
			cin>>S[i][y];
			FORR(c,S[i][y]) if(c=='#') sum++;
		}
	}
	if(sum!=16) {
		cout<<"No"<<endl;
		return;
	}
	FOR(i,128) {
		if(i%4) x=0;
		else if(i%16) x=1;
		else x=2;
		S[x]=rotate(S[x]);
		int dx[3],dy[3];
		for(dx[0]=-3;dx[0]<=3;dx[0]++)
		for(dx[1]=-3;dx[1]<=3;dx[1]++)
		for(dx[2]=-3;dx[2]<=3;dx[2]++)
		for(dy[0]=-3;dy[0]<=3;dy[0]++)
		for(dy[1]=-3;dy[1]<=3;dy[1]++)
		for(dy[2]=-3;dy[2]<=3;dy[2]++) {
			int ok[4][4]={};
			FOR(j,3) FOR(y,4) FOR(x,4) if(S[j][y][x]=='#') {
				if(dx[j]+x>=0&&dx[j]+x<=3) {
					if(dy[j]+y>=0&&dy[j]+y<=3) {
						ok[dy[j]+y][dx[j]+x]++;
					}
				}
			}
			int sum=0;
			FOR(y,4) FOR(x,4) sum+=ok[y][x]==1;
			if(sum==16) {
				cout<<"Yes"<<endl;
				return;
			}
			
		}
		
	}
	cout<<"No"<<endl;
}
	


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
