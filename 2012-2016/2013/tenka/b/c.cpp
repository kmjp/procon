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

int H,W,A,B;

int from[1<<8][19][19][2];
int to[1<<8][19][19][2];

template<class T> void chmax(T &a, const T &b) { a=max(a,b);}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>A>>B;
	int mask,mask2;
	
	FOR(mask2,1<<W) FOR(x,19) FOR(y,19) from[mask2][x][y][0]=from[mask2][x][y][1]=-100;
	
	FOR(mask,1<<(W-1)) FOR(mask2,1<<W) {
		int num=0;
		for(x=1;x<W-1;x++) {
			if((mask2&(1<<x))) continue;
			if((mask&(1<<(x-1)))==0) continue;
			if((mask&(1<<(x)))) continue;
			num++;
		}
		chmax(from[mask2][0][0][0],num);
	}
	int a,b;
	for(y=1;y<H;y++) FOR(x,W) {
		FOR(mask,1<<W) FOR(a,19) FOR(b,19) to[mask][a][b][0]=to[mask][a][b][1]=-100;
		FOR(mask,1<<W) FOR(a,19) FOR(b,19) {
			i=(mask>>x)&1;
			FOR(j,2) FOR(k,2) FOR(l,2) {
				int cur=from[mask][a][b][l];
				if(cur<0) continue;
				
				int nmask=(mask&(255-(1<<x)))|(k<<x);
				if(x==0) {
					if(l==1) continue;
					chmax(to[nmask][a][b][j],cur+(y<H-1&&i==1&&j==0&&k==0));
				}
				else if(x==W-1) {
					if(j==1) continue;
					chmax(to[nmask][a][b][j],cur+(y<H-1&&i==1&&l==1&&k==0));
				}
				else {
					if(y==H-1&&k) continue;
					int a2=a+((i==1)&&(j==0)&&(k==0)&&(l==1)&&(y!=H-1));
					int b2=b+((i==0)&&(j==1)&&(k==1)&&(l==0)&&(y!=H-1));
					int add=i==1&&j==0&&l==1&&y==H-1;
					if(a2<=18 && b2<=18) chmax(to[nmask][a2][b2][j],cur+add);
				}
			}
		}
		swap(from,to);
	}
	
	int ma=0;
	FOR(x,19) FOR(y,19) if(x>=A && y<=B) ma=max(ma,from[0][x][y][0]);
	
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
