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

int H,W;
int GX,GY;
int A[250][250];
vector<pair<int,ll>> D[250][250];
int Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	cin>>GY>>GX;
	GY--,GX--;
	FOR(y,H) FOR(x,W) {
		cin>>A[y][x];
		if(y!=GY || x!=GX) D[y][x].push_back({0,1LL<<60});
	}
	
	D[GY][GX].push_back({1,A[GY][GX]});
	set<pair<int,int>> C;
	C.insert({GY,GX});
	int step=1;
	while(C.size()) {
		set<pair<int,int>> C2;
		FORR(c,C) {
			int cy=c.first;
			int cx=c.second;
			int dd[4]={1,0,-1,0};
			ll co;
			if(D[cy][cx].back().first==step) co=D[cy][cx].back().second;
			if(D[cy][cx].back().first==step+1) co=D[cy][cx][D[cy][cx].size()-2].second;
			
			FOR(i,4) {
				int ty=cy+dd[i];
				int tx=cx+dd[i^1];
				if(ty<0 || ty>=H || tx<0 || tx>=W) continue;
				ll co2=co+A[ty][tx];
				if(co2<D[ty][tx].back().second) {
					if(D[ty][tx].back().first==step+1) {
						D[ty][tx].back().second=co2;
					}
					else {
						D[ty][tx].push_back({step+1,co2});
						C2.insert({ty,tx});
					}
				}
			}
		}
		step++;
		swap(C,C2);
	}
	
	
	cin>>Q;
	while(Q--) {
		ll K;
		cin>>y>>x>>K;
		y--,x--;
		ll mi=1LL<<60;
		FORR(d,D[y][x]) {
			mi=min(mi,K*K*d.first+d.second);
		}
		cout<<mi<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
