#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W;
string S[2020];
int len[2020][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	
	FOR(y,H-1) {
		int same=W,ns=W;
		for(x=W-1;x>=0;x--) {
			if(S[y][x]==S[y+1][x]) {
				len[y][x]=ns-x;
				same=x;
			}
			else {
				len[y][x]=same-x;
				ns=x;
			}
		}
	}
	
	int ma=max(H,W);
	int step=0;
	FOR(i,W) {
		vector<pair<int,int>> V;
		V.push_back({-1,-1});
		for(y=1;y<=H;y++) {
			
			x=len[y-1][i];
			int f=y;
			while(V.back().second>=x) {
				f=V.back().first;
				ma=max(ma,V.back().second*(y-f+1));
				V.pop_back();
			}
			V.push_back({f,x});
		}
	}
	cout<<ma<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
