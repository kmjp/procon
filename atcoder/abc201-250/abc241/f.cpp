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

int H,W,N;
int SX,SY,GX,GY;
set<pair<int,int>> HS,VS;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>N>>SY>>SX>>GY>>GX;
	SY--,SX--,GY--,GX--;
	FOR(i,N) {
		cin>>y>>x;
		HS.insert({y-1,x-1});
		VS.insert({x-1,y-1});
	}
	HS.insert({H,0});
	HS.insert({-1,0});
	VS.insert({W,0});
	VS.insert({-1,0});
	map<pair<int,int>,int> step;
	queue<pair<int,int>> Q;
	step[{SY,SX}]=0;
	Q.push({SY,SX});
	
	while(Q.size()) {
		int cy=Q.front().first;
		int cx=Q.front().second;
		Q.pop();
		r=step[{cy,cx}];
		if(cy==GY&&cx==GX) {
			cout<<r<<endl;
			return;
		}
		auto it=HS.lower_bound({cy,cx});
		int tx=(it->first==cy?it->second-1:W);
		if(tx<W&&step.count({cy,tx})==0) {
			step[{cy,tx}]=r+1;
			Q.push({cy,tx});
		}
		it--;
		tx=(it->first==cy?it->second+1:-1);
		if(tx>=0&&step.count({cy,tx})==0) {
			step[{cy,tx}]=r+1;
			Q.push({cy,tx});
		}
		it=VS.lower_bound({cx,cy});
		int ty=(it->first==cx?it->second-1:H);
		if(ty<H&&step.count({ty,cx})==0) {
			step[{ty,cx}]=r+1;
			Q.push({ty,cx});
		}
		it--;
		ty=(it->first==cx?it->second+1:-1);
		if(ty>=0&&step.count({ty,cx})==0) {
			step[{ty,cx}]=r+1;
			Q.push({ty,cx});
		}
		
	}
	cout<<-1<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
