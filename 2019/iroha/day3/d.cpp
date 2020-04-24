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

int H;
string S[10];
int SY,SX,TY,TX;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H;
	FOR(y,H) cin>>S[y];
	SY=SX=1,TY=TX=-1;
	FOR(i,1000) {
		if(abs(SY-TY)+abs(SX-TX)!=1) {
			cout<<"-"<<endl;
		}
		else {
			FOR(j,4) {
				int dd[4]={1,0,-1,0};
				int ny=SY+dd[j];
				int nx=SX+dd[j^1];
				if(nx==TX&&ny==TY) continue;
				if(S[ny][nx]=='#') continue;
				
				SY=ny;
				SX=nx;
				if(j==0) cout<<"D"<<endl;
				if(j==1) cout<<"R"<<endl;
				if(j==2) cout<<"U"<<endl;
				if(j==3) cout<<"L"<<endl;
				break;
			}
			assert(j<4);
		}
		cin>>TY>>TX;
		TY--,TX--;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
