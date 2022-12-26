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
ll A,B;
string S[202],T[202];
int LR,UD;

void countmiss() {
	int i,j,k,l,r,x,y; string s;
	FOR(y,H) S[y]=T[y];
	LD=UD=0;
	FOR(y,H/2) FOR(x,W/2) {
		if(S[y][x]!=S[H-1-y][x]) UD++;
		if(S[y][W-1-x]!=S[H-1-y][W-1-x]) UD++;
		if(S[y][x]!=S[y][W-1-x]) LR++;
		if(S[H-1-y][x]!=S[H-1-y][W-1-x]) LR++;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>A>>B;
	FOR(y,H) cin>>T[y];
	
	ll ma=0;
	// first LR
	{
		countmiss();
		ll tmp=0;
		FOR(y,H) FOR(x,W) if(S[y][x]=='S' && S[y][W-1-x]=='.') {
			S[y][x]='.';
			LR--;
			if(LR==0) tmp+=B;
			if(S[H-1-y][x]=='S') UD++;
			else UD--;
			if(UD==0) tmp+=A;
		}
		FOR(y,H) FOR(i,W) {
			if(i%2==0) x=i/2;
			else x=W-1-(i/2);
			if(S[y][x]=='S' && S[H-1-y][x]=='.') {
				S[y][x]='.';
				UD--;
				if(UD==0) tmp+=A;
				if(S[y][W-1-x]=='S') LR++;
				else LR--;
				if(LR==0) tmp+=B;
			}
		}
		FOR(y,H/2) FOR(x,W/2) if(S[y][x]=='S') tmp+=max(2*A+B,2*B+A);
		ma=tmp;
	}
	{
		countmiss();
		ll tmp=0;
		FOR(y,H) FOR(x,W) if(S[y][x]=='S' && S[H-1-y][x]=='.') {
			S[y][x]='.';
			UD--;
			if(UD==0) tmp+=A;
			if(S[y][W-1-x]=='S') LR++;
			else LR--;
			if(LR==0) tmp+=B;
		}
		FOR(x,W) FOR(i,H) {
			if(i%2==0) y=i/2;
			else y=H-1-(i/2);
			
			if(S[y][x]=='S' && S[y][W-1-x]=='.') {
				S[y][x]='.';
				LR--;
				if(LR==0) tmp+=B;
				if(S[H-1-y][x]=='S') UD++;
				else UD--;
				if(UD==0) tmp+=A;
			}
		}
		FOR(y,H/2) FOR(x,W/2) if(S[y][x]=='S') tmp+=max(2*A+B,2*B+A);
		ma=max(ma,tmp);
	}
	
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
