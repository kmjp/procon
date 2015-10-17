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

int N;
ll T[1010],S[1010],F[1010];
ll met[2020];

// p1-p2‚Æp3-p4‚ÌŒð·”»’è
int cross(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4) {
	ll XX[3],YY[3];
	XX[0]=x2-x1; YY[0]=y2-y1;
	XX[1]=x3-x1; YY[1]=y3-y1;
	XX[2]=x4-x1; YY[2]=y4-y1;
	ll c1=XX[0]*YY[1]-XX[1]*YY[0];
	ll c2=XX[0]*YY[2]-XX[2]*YY[0];
	if((c1<0&&c2<0)||(c1>0&&c2>0)) return 0;
	XX[0]=x4-x3; YY[0]=y4-y3;
	XX[1]=x1-x3; YY[1]=y1-y3;
	XX[2]=x2-x3; YY[2]=y2-y3;
	c1=XX[0]*YY[1]-XX[1]*YY[0];
	c2=XX[0]*YY[2]-XX[2]*YY[0];
	if((c1<0&&c2<0)||(c1>0&&c2>0)) return 0;
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>T[i]>>S[i]>>F[i];
	
	FOR(y,N) FOR(x,y) {
		if((F[y]-S[y])*(F[x]-S[x])>0) {
			int m=0,rev=0;
			if(S[y]>F[y]) rev=1,S[y]*=-1,F[y]*=-1,S[x]*=-1,F[x]*=-1;
			FOR(i,2) {
				if(S[y]<=S[x] && S[x]<=F[y] && T[y]+S[x]-S[y]==T[x]) m=1;
				if(S[y]<=F[x] && F[x]<=F[y] && T[y]+F[x]-S[y]==T[x]+F[x]-S[x]) m=1;
				swap(x,y);
			}
			
			if(rev) S[y]*=-1,F[y]*=-1,S[x]*=-1,F[x]*=-1;
			met[x]+=m;
			met[y]+=m;
		}
		else if(cross(T[y],S[y],T[y]+abs(F[y]-S[y]),F[y],T[x],S[x],T[x]+abs(F[x]-S[x]),F[x])) {
			met[x]++, met[y]++;
		}
	}
	FOR(x,N) _P("%d ",met[x]);
	_P("\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
