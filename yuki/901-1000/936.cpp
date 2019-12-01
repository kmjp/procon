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

ll mo=1000000007;
int N,K;
ll from[5][5][5][5];
ll to[5][5][5][5];
int win[5][5][5][5];



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,5) FOR(j,5) FOR(x,5) FOR(y,5) if(i+j>0 && x+y>0) {
		if((i+x)%5+y==0) win[i][j][x][y]=1;
		if((i+y)%5+x==0) win[i][j][x][y]=1;
		if((j+x)%5+y==0) win[i][j][x][y]=1;
		if((j+y)%5+x==0) win[i][j][x][y]=1;
	}
	
	
	cin>>N>>K;
	cin>>i>>j>>x>>y;
	
	from[i][j][x][y]=1;
	ll ret=0;
	while(K--) {
		ZERO(to);
		//UŒ‚
		FOR(i,5) FOR(j,5) FOR(x,5) FOR(y,5) if(from[i][j][x][y]) {
			ll v=from[i][j][x][y];
			if(N==0) {
				if(i&&x) {
					if((i+x)%5+y==0) (ret+=v)%=mo;
					else (to[i][j][(i+x)%5][y]+=v)%=mo;
				}
				if(i&&y) {
					if((i+y)%5+x==0) (ret+=v)%=mo;
					else (to[i][j][x][(i+y)%5]+=v)%=mo;
				}
				if(j&&x) {
					if((j+x)%5+y==0) (ret+=v)%=mo;
					else (to[i][j][(j+x)%5][y]+=v)%=mo;
				}
				if(j&&y) {
					if((j+y)%5+x==0) (ret+=v)%=mo;
					else (to[i][j][x][(j+y)%5]+=v)%=mo;
				}
				int a,b;
				FOR(a,5) FOR(b,5) {
					if(a+b==0) continue;
					if(a+b>i+j) continue;
					if((a+b)%5!=(i+j)%5) continue;
					if(a==i&&b==j) continue;
					if(a==j&&b==i) continue;
					(to[a][b][x][y]+=v)%=mo;
				}
			}
			else {
				//•KŸ‚È‚ç‚»‚ê‚ÅI—¹
				if(win[x][y][i][j]) continue;
				
				int pat=0;
				if(i&&x&&win[(x+i)%5][j][x][y]==0) (to[(i+x)%5][j][x][y]+=v)%=mo, pat++;
				if(i&&y&&win[(y+i)%5][j][x][y]==0) (to[(i+y)%5][j][x][y]+=v)%=mo, pat++;
				if(j&&x&&win[i][(x+j)%5][x][y]==0) (to[i][(j+x)%5][x][y]+=v)%=mo, pat++;
				if(j&&y&&win[i][(y+j)%5][x][y]==0) (to[i][(j+y)%5][x][y]+=v)%=mo, pat++;
				
				int a,b;
				FOR(a,5) FOR(b,5) {
					if(a+b==0) continue;
					if(a+b>x+y) continue;
					if((a+b)%5!=(x+y)%5) continue;
					if(a==x&&b==y) continue;
					if(a==y&&b==x) continue;
					if(win[i][j][a][b]) continue;
					(to[i][j][a][b]+=v)%=mo;
					pat++;
				}
				if(pat==0) {
					//‚Ç‚¤‚â‚Á‚Ä‚à•‰‚¯‚é
					if(i&&x) (to[(i+x)%5][j][x][y]+=v)%=mo;
					if(i&&y) (to[(i+y)%5][j][x][y]+=v)%=mo;
					if(j&&x) (to[i][(j+x)%5][x][y]+=v)%=mo;
					if(j&&y) (to[i][(j+y)%5][x][y]+=v)%=mo;
					
					int a,b;
					FOR(a,5) FOR(b,5) {
						if(a+b==0) continue;
						if(a+b>x+y) continue;
						if((a+b)%5!=(x+y)%5) continue;
						if(a==x&&b==y) continue;
						if(a==y&&b==x) continue;
						(to[i][j][a][b]+=v)%=mo;
					}
					
				}
			}
		}
		swap(from,to);
		N^=1;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
