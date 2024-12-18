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

int T,H,W;

int ask(int y,int x) {
	cout<<"? "<<y+1<<" "<<x+1<<endl;
	cin>>y;
	return y;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		int r=ask(0,0);
		
		int ay=min(r,H-1);
		int ax=r-ay;
		int bx=min(r,W-1);
		int by=r-bx;
		
		int a=ask(ay,ax);
		
		if(a%2==0) {
			ay-=a/2;
			ax+=a/2;
			if(ay>=0&&ay<H&&ax>=0&&ax<W&&ask(ay,ax)==0) {
				cout<<"! "<<(ay+1)<<" "<<(ax+1)<<endl;
				continue;
			}
		}
		int b=ask(by,bx);
		
		by+=b/2;
		bx-=b/2;
		cout<<"! "<<(by+1)<<" "<<(bx+1)<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
