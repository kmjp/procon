#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T;
int TSX,TSY,TGX,TGY;
int ASX,ASY,AGX,AGY;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>TSX>>TSY>>TGX>>TGY;
		cin>>ASX>>ASY>>AGX>>AGY;
		double TL=hypot(TGX-TSX,TGY-TSY);
		double AL=hypot(AGX-ASX,AGY-ASY);
		double tdx=(TGX-TSX)/TL;
		double tdy=(TGY-TSY)/TL;
		double adx=(AGX-ASX)/AL;
		double ady=(AGY-ASY)/AL;
		
		double ret=1<<20;
		double L=0,R=min(TL,AL);
		FOR(i,100) {
			double M1=(L*2+R)/3,M2=(L+R*2)/3;
			double v1=hypot(TSX+M1*tdx-ASX-M1*adx,TSY+M1*tdy-ASY-M1*ady);
			double v2=hypot(TSX+M2*tdx-ASX-M2*adx,TSY+M2*tdy-ASY-M2*ady);
			ret=min(ret,v1);
			ret=min(ret,v2);
			if(v1<=v2) R=M2;
			if(v1>=v2) L=M1;
		}
		L=min(TL,AL),R=max(TL,AL);
		FOR(i,100) {
			double M1=(L*2+R)/3,M2=(L+R*2)/3;
			double v1=hypot(TSX+min(TL,M1)*tdx-ASX-min(AL,M1)*adx,TSY+min(TL,M1)*tdy-ASY-min(M1,AL)*ady);
			double v2=hypot(TSX+min(TL,M2)*tdx-ASX-min(AL,M2)*adx,TSY+min(TL,M2)*tdy-ASY-min(M2,AL)*ady);
			ret=min(ret,v1);
			ret=min(ret,v2);
			if(v1<=v2) R=M2;
			if(v1>=v2) L=M1;
		}
		_P("%.12lf\n",ret);
	}
		
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
