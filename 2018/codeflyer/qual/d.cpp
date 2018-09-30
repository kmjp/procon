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
int A,B;
string S[1010];

int F[3030][3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	cin>>A>>B;
	int c=0;
	FOR(y,A) {
		cin>>S[y];
		FOR(x,B) if(S[y][x]=='#') c=1;
	}
	
	int th=min(2*A+1,H);
	int tw=min(2*B+1,W);
	int mh=th-A;
	int mw=tw-B;
	FOR(y,A) FOR(x,B) if(S[y][x]=='#') {
		F[y+1][x+1]+=1;
		F[y+mh+2][x+1]+=-1;
		F[y+1][x+mw+2]+=-1;
		F[y+mh+2][x+mw+2]+=1;
	}
	ll ret=0;
	for(y=1;y<=th;y++) {
		for(x=1;x<=tw;x++) {
			F[y][x]+=F[y-1][x]+F[y][x-1]-F[y-1][x-1];
			if(F[y][x]) {
				ll mul=1;
				if(th==2*A+1 && y==A+1) mul*=(H-2*A);
				if(tw==2*B+1 && x==B+1) mul*=(W-2*B);
				ret+=mul;
			}
		}
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
