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

int N;
int A[505][505];
int B[505][505];
vector<pair<pair<int,int>,int>> V;
void rot(int Y,int X,int H) {
	int y,x;
	FOR(y,H) FOR(x,H) B[y][x]=A[y+Y][x+X];
	FOR(y,H) FOR(x,H) A[x+Y][H-1-y+X]=B[y][x];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) FOR(x,N) cin>>A[y][x];
	double start=clock();
	srand(start*10);
	while((clock()-start)<CLOCKS_PER_SEC*1.5) {
		FOR(i,10) {
			if(N==1 || V.size()>490) break;
			int H=2;
			if(N>2) H+=rand()%(N-2);
			y=rand()%(N+1-H);
			x=rand()%(N+1-H);
			int L=0,R=0,U=0,D=0;
			for(int y2=y;y2<y+H;y2++) {
				for(int x2=x;x2<x+H;x2++) for(int x3=x2+1;x3<x+H;x3++) {
					if(A[y2][x2]<A[y2][x3]) L++;
					if(A[y2][x2]>A[y2][x3]) R++;
				}
			}
			for(int x2=x;x2<x+H;x2++) {
				for(int y2=y;y2<y+H;y2++) for(int y3=y2+1;y3<y+H;y3++) {
					if(A[y2][x2]<A[y3][x2]) U++;
					if(A[y2][x2]>A[y3][x2]) D++;
				}
			}
			
			int s[4]={L+U,L+D,R+D,R+U};
			if(s[0]<s[1] && s[2]<=s[1] && s[3]<=s[1]) {
				rot(y,x,H);
				V.push_back({{y,x},H});
			}
			else if(s[0]<s[2] && s[1]<=s[2] && s[3]<=s[2]) {
				rot(y,x,H);
				rot(y,x,H);
				V.push_back({{y,x},H});
				V.push_back({{y,x},H});
			}
			else if(s[0]<s[3] && s[1]<=s[3] && s[1]<=s[3]) {
				rot(y,x,H);
				rot(y,x,H);
				rot(y,x,H);
				V.push_back({{y,x},H});
				V.push_back({{y,x},H});
				V.push_back({{y,x},H});
			}
		}
		
	}
	_P("%d\n",V.size());
	FORR(r,V) _P("%d %d %d\n",r.first.first+1,r.first.second+1,r.second);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
