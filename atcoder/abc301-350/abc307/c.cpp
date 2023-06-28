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

int HA,HB,HX;
int WA,WB,WX;
string A[11],B[11],X[11];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int num=0;
	cin>>HA>>WA;
	FOR(y,HA) {
		cin>>A[y];
		FORR(c,A[y]) if(c=='#') num++;
	}
	cin>>HB>>WB;
	FOR(y,HB) {
		cin>>B[y];
		FORR(c,B[y]) if(c=='#') num++;
	}
	cin>>HX>>WX;
	FOR(y,HX) cin>>X[y];
	
	for(int ay=-10;ay<=10;ay++) {
		for(int ax=-10;ax<=10;ax++) {
			for(int by=-10;by<=10;by++) {
				for(int bx=-10;bx<=10;bx++) {
					int ok=1;
					int did=0;
					FOR(y,HX) FOR(x,WX) {
						int t=0;
						if(ay+y>=0&&ay+y<HA&&ax+x>=0&&ax+x<WA&&A[ay+y][ax+x]=='#') t++;
						if(by+y>=0&&by+y<HB&&bx+x>=0&&bx+x<WB&&B[by+y][bx+x]=='#') t++;
						did+=t;
						if(X[y][x]=='#'&&t==0) ok=0;
						if(X[y][x]=='.'&&t) ok=0;
					}
					if(ok&&did==num) {
						cout<<"Yes"<<endl;
						return;
					}
				}
			}
		}
	}	
	cout<<"No"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
