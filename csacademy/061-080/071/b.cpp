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
int A[505][505];
int B[505][505];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	vector<vector<int>> V;
	FOR(y,H) FOR(x,W) {
		cin>>A[y][x];
		B[y][x]=1;
		V.push_back({A[y][x],y,x});
	}
	sort(ALL(V));
	reverse(ALL(V));
	FORR(v,V) {
		int cy=v[1];
		int cx=v[2];
		int ty=cy,tx=cx;
		for(y=max(0,cy-1);y<=min(H-1,cy+1);y++) {
			for(x=max(0,cx-1);x<=min(W-1,cx+1);x++) {
				if(A[y][x]<A[ty][tx]) ty=y,tx=x;
			}
		}
		if(ty!=cy || tx!=cx) {
			B[ty][tx] += B[cy][cx];
			B[cy][cx]=0;
		}
	}
	FOR(y,H) FOR(x,W) _P("%d%c",B[y][x],(x==W-1)?'\n':' ');
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
