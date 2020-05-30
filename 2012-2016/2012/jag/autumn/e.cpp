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
string S[51];
vector<pair<int,int>> cand[26];
int ok[51][51][51][51];

int dp[51][51][51][51];

int hoge(int y1,int x1,int y2,int x2) {
	if(ok[y1][x1][y2][x2]==0) return -99999;
	if(dp[y1][x1][y2][x2]!=-1) return dp[y1][x1][y2][x2];
	int ret=0;
	ret=max(ret,hoge(y1+1,x1,y2,x2));
	ret=max(ret,hoge(y1,x1+1,y2,x2));
	if(S[y1][x1]>='a' && S[y1][x1]<='z') {
		int tar=S[y1][x1]-'a';
		FORR(p,cand[tar]) if(ok[y1][x1][p.first][p.second]&&ok[p.first][p.second][y2][x2]){
			int a=max({hoge(y1+1,x1,p.first-1,p.second),hoge(y1+1,x1,p.first,p.second-1),hoge(y1,x1+1,p.first-1,p.second),hoge(y1,x1+1,p.first,p.second-1)});
			if(p.first+p.second-(y1+x1)==1) a=max(a,0);
			ret=max(ret,1+a+hoge(p.first,p.second,y2,x2));
		}
	}
	//cout<<y1<<x1<<y2<<x2<<" "<<ret<<endl;
	
	return dp[y1][x1][y2][x2]=ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	while(1) {
		cin>>H>>W;
		if(H==0) return;
		ZERO(ok);
		MINUS(dp);
		FOR(i,26) cand[i].clear();
		
		FOR(y,H) {
			cin>>S[y];
			FOR(x,W) if(S[y][x]>='A' && S[y][x]<='Z') cand[S[y][x]-'A'].push_back({y,x});
		}
		FOR(y,H) FOR(x,W) if(S[y][x]!='#') {
			ok[y][x][y][x]=1;
			int y2,x2;
			for(y2=y;y2<H;y2++) for(x2=x;x2<W;x2++) if(ok[y][x][y2][x2]) {
				if(y2+1<H&&S[y2+1][x2]!='#') ok[y][x][y2+1][x2]=1;
				if(x2+1<W&&S[y2][x2+1]!='#') ok[y][x][y2][x2+1]=1;
				
			}
		}
		x=hoge(0,0,H-1,W-1);
		if(x<0) x=-1;
		cout<<x<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
