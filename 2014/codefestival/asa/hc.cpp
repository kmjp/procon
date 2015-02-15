#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll p[3];
int H,W,K,Q;
int A[502][502];
int S[502][502][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p[0]=1;
	p[1]=1LL<<20;
	p[2]=1LL<<40;
	
	
	cin>>H>>W>>K;
	FOR(y,H) FOR(x,W) cin>>A[y+1][x+1], S[y+1][x+1][A[y+1][x+1]]++;
	FOR(i,101) {
		FOR(y,H) FOR(x,W) S[y+1][x+1][i] += S[y+1][x][i];
		FOR(y,H) FOR(x,W) S[y+1][x+1][i] += S[y][x+1][i];
	}
	
	cin>>Q;
	while(Q--) {
		int x1,y1,x2,y2;
		cin>>l>>y1>>x1>>y2>>x2;
		if(l==1) {
			if(x1==x2) {
				if(y1<y2) {
					for(x=x1;x<=W;x++) S[y1][x][A[y1][x1]]--;
					for(x=x1;x<=W;x++) S[y1][x][A[y2][x2]]++;
				}
				else {
					for(x=x1;x<=W;x++) S[y2][x][A[y1][x1]]++;
					for(x=x1;x<=W;x++) S[y2][x][A[y2][x2]]--;
				}
			}
			else {
				if(x1<x2) {
					for(y=y1;y<=H;y++) S[y][x1][A[y1][x1]]--;
					for(y=y1;y<=H;y++) S[y][x1][A[y2][x2]]++;
				}
				else {
					for(y=y1;y<=H;y++) S[y][x2][A[y1][x1]]++;
					for(y=y1;y<=H;y++) S[y][x2][A[y2][x2]]--;
				}
			}
			swap(A[y1][x1],A[y2][x2]);
		}
		else {
			
			x=y=0;
			FOR(i,101) {
				j = S[y2][x2][i]-S[y2][x1-1][i]-S[y1-1][x2][i]+S[y1-1][x1-1][i];
				if(j>=x) y=i,x=j;
			}
			cout << y << " " << x << endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
