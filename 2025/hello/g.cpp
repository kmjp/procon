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
int H,W;
string S[2020202];
vector<pair<int,int>> V[5];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		FOR(y,H) cin>>S[y];
		FOR(i,5) V[i].clear();
		
		for(y=-1;y<=H;y++) for(x=-1;x<=W;x++) {
			i=((y+5)*2+(x+5))%5;
			if(y>=0&&y<H&&x>=0&&x<W&&S[y][x]=='#') {
				V[i].push_back({y,x});
			}
			else {
				int ty[4]={y+1,y,y-1,y};
				int tx[4]={x,x+1,x,x-1};
				FOR(j,4) if(ty[j]>=0&&ty[j]<H&&tx[j]>=0&&tx[j]<W&&S[ty[j]][tx[j]]=='#') V[i].push_back({ty[j],tx[j]});
			}
			
		}
		vector<pair<int,int>> R=V[0];
		FOR(i,5) if(V[i].size()<R.size()) R=V[i];
		FORR2(y,x,R) S[y][x]='S';
		FOR(y,H) cout<<S[y]<<"\n";
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
