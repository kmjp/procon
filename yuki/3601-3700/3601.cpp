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
ll H,W,SY,SX,GY,GX;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W>>SY>>SX>>GY>>GX;
		SY--,SX--,GY--,GX--;
		if(GY>SY) {
			GY=H-1-GY;
			SY=H-1-SY;
		}
		if(GX>SX) {
			GX=W-1-GX;
			SX=W-1-SX;
		}
		if(GX==SX) {
			swap(GX,GY);
			swap(SX,SY);
			swap(H,W);
		}
		ll L=SX,R=W-1-SX;
		ll U=SY,D=H-1-SY;
		ll ret=2*H*W-2;
		ret-=L+R+U+D+min(L,U)+min(L,D)+min(R,U)+min(R,D);
		
		if(SX!=GX&&SY!=GY&&SX+SY!=GX+GY&&SX-SY!=GX-GY) {
			ret-=2;
		}
		else if(SX-SY==GX-GY) {
			ret-=1;
			ret+=min(L,U)-(SX-GX);
		}
		else if(SY==GY) {
			ret-=1;
			ret+=2*GX;
			ll A=SX-GX+1,B1=min(SX,max(SY,H-1-SY)),B2=min(SX,max(SY,H-1-SY)*2);
			if(A<=B1) {
				ret-=B1-A+1;
				A=B1+1;
			}
			while(A%2) A++;
			while(B2%2) B2--;
			if(A<=B2) ret-=(B2-A)/2+1;
		}
		else {
			assert(0);
		}
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
