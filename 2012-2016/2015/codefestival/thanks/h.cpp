#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W,K;
string S[400];
int tot[11][400][400];
ll ret;

ll sum(int top,int left,int bot,int right,int n) {
	return tot[n][bot+1][right+1]-tot[n][top][right+1]-tot[n][bot+1][left]+tot[n][top][left];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) tot[S[y][x]-'0'][y+1][x+1]++, tot[10][y+1][x+1]+=S[y][x]-'0';
	}
	FOR(i,11) FOR(y,H) FOR(x,W) tot[i][y+1][x+1] += tot[i][y+1][x]+tot[i][y][x+1]-tot[i][y][x];
	
	int top,left,right,bottom;
	FOR(top,H-2) FOR(left,W-2) {
		int right=left+2;
		for(bottom=H-1;bottom>=top+2;bottom--) {
			while(right<W && sum(top,left,bottom,right,10)<=K) right++;
			for(r=right;r<W;r++) {
				ll ts=sum(top,left,bottom,r,10);
				if(ts>=K+10) break;
				ret += sum(top+1,left+1,bottom-1,r-1,ts-K);
			}
		}
		
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
