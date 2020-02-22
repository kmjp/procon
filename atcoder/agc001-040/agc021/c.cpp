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
int OH,OW,OA,OB;

string S[1010];

void output() {
	int y;
	cout<<"YES"<<endl;
	FOR(y,OH) cout<<S[y]<<endl;
	exit(0);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>A>>B;
	if(H*W<2*(A+B)) return _P("NO\n");
	OH=H,OW=W,OA=A,OB=B;
	
	FOR(y,H) S[y]=string(W,'.');
	if(H%2==1) {
		for(x=0;x<W-1&&A;x+=2) S[H-1][x]='<', S[H-1][x+1]='>', A--;
		H--;
	}
	if(W%2==1) {
		for(y=0;y<H-1&&B;y+=2) S[y][W-1]='^', S[y+1][W-1]='v', B--;
		W--;
	}
	
	for(y=0;y<H;y+=2) {
		for(x=0;x<W;x+=2) {
			if(A) {
				S[y][x]='<', S[y][x+1]='>', A--;
				if(A) S[y+1][x]='<', S[y+1][x+1]='>', A--;
			}
			else if(B) {
				S[y][x]='^', S[y+1][x]='v', B--;
				if(B) S[y][x+1]='^', S[y+1][x+1]='v', B--;
			}
		}
	}
	if(A==0 && B==0) output();
	
	H=OH,W=OW,A=OA,B=OB;
	if(H%2 && W%2 && H>=3 && W>=3 && A>=2 && B>=2) {
		A-=2;
		B-=2;
		FOR(y,H) S[y]=string(W,'.');
		S[H-3][W-3]=S[H-1][W-2]='<';
		S[H-3][W-2]=S[H-1][W-1]='>';
		S[H-2][W-3]=S[H-3][W-1]='^';
		S[H-1][W-3]=S[H-2][W-1]='v';
		for(y=0;y<H-3&&B;y+=2) S[y][W-1]='^',S[y+1][W-1]='v',B--;
		for(x=0;x<W-3&&A;x+=2) S[H-1][x]='<',S[H-1][x+1]='>',A--;
		for(y=0;y<H-1;y+=2) {
			for(x=0;x<W-1;x+=2) {
				if(S[y][x]!='.') continue;
				if(A) {
					S[y][x]='<', S[y][x+1]='>', A--;
					if(A) S[y+1][x]='<', S[y+1][x+1]='>', A--;
				}
				else if(B) {
					S[y][x]='^', S[y+1][x]='v', B--;
					if(B) S[y][x+1]='^', S[y+1][x+1]='v', B--;
				}
			}
		}
		if(A==0 && B==0) output();
	}
	
	
	cout<<"NO"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
