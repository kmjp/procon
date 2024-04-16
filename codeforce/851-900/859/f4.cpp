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
int H,W,Y1,X1,Y2,X2;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W>>Y1>>X1>>Y2>>X2>>s;
		Y1--,X1--,Y2--,X2--;
		int dy=s[0]=='D'?1:-1;
		int dx=s[1]=='L'?-1:1;
		set<pair<int,int>> M[3][3];
		int num=0;
		while(1) {
			if(M[dy+1][dx+1].count({Y1,X1})) {
				num=-1;
				break;
			}
			M[dy+1][dx+1].insert({Y1,X1});
			int sy=(Y2-Y1)/dy;
			int sx=(X2-X1)/dx;
			if(sy==sx&&sy>=0) break;
			
			if(dy==1) {
				sy=H-1-Y1;
			}
			else {
				sy=Y1;
			}
			if(dx==1) {
				sx=W-1-X1;
			}
			else {
				sx=X1;
			}
			i=min(sx,sy);
			Y1+=i*dy;
			X1+=i*dx;
			if(i==sy) dy=-dy;
			if(i==sx) dx=-dx;
			num++;
		}
		cout<<num<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
