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

int H,W,K;
int A[202][202];
int S[202][202];
int ma;

int num(int X1,int Y1,int X2,int Y2) {
	int ret=0;
	ret+=S[Y1+K][X1+K]-S[Y1][X1+K]-S[Y1+K][X1]+S[Y1][X1];
	ret+=S[Y2+K][X2+K]-S[Y2][X2+K]-S[Y2+K][X2]+S[Y2][X2];
	
	int L=max(X1,X2),R=min(X1+K,X2+K);
	int U=max(Y1,Y2),D=min(Y1+K,Y2+K);
	if(L<R && U<D) ret-=S[D][R]-S[D][L]-S[U][R]+S[U][L];
	return ret;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(y,H) FOR(x,W) {
		cin>>A[y][x];
		S[y+1][x+1]=A[y][x]+S[y][x+1]+S[y+1][x]-S[y][x];
	}
	
	for(int w=K;w+K<=W;w++) {
		int ma1=0,ma2=0;
		for(y=0;y+K<=H;y++) {
			for(x=0;x+K<=w;x++) ma1=max(ma1,num(x,y,x,y));
			for(x=w;x+K<=W;x++) ma2=max(ma2,num(x,y,x,y));
		}
		ma=max(ma,ma1+ma2);
	}
	for(int h=K;h+K<=H;h++) {
		int ma1=0,ma2=0;
		for(x=0;x+K<=W;x++) {
			for(y=0;y+K<=h;y++) ma1=max(ma1,num(x,y,x,y));
			for(y=h;y+K<=H;y++) ma2=max(ma2,num(x,y,x,y));
		}
		ma=max(ma,ma1+ma2);
	}
	for(y=0;y+K<=H;y++) {
		for(x=0;x+K<=W;x++) {
			for(int y2=y;y2+K<=H && y2<y+K;y2++) {
				for(int x2=x-K+1;x2<x+K;x2++) {
					if(x2>=0 && y2>=0 && x2+K<=W && y2+K<=H) ma=max(ma,num(x,y,x2,y2));
				}
			}
		}
	}
	
	
	cout<<ma+(H*W-S[H][W])<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
