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

int H,W;
string C[155];

int cost[155][155];
int E[155][155];
int B[155][155],R[155][155];
const ll mo=998244353;
vector<vector<int>> T[155][155];
ll D[155][155][2];
ll dp[155][155][2];

pair<ll,ll> hoge(int sy,int sx) {
	int y,x;
	FOR(y,H+2) FOR(x,W+2) {
		D[y][x][0]=D[y][x][1]=1LL<<60;
		dp[y][x][0]=dp[y][x][1]=0;
	}
	
	D[sy][sx][0]=0;
	dp[sy][sx][0]=1;
	priority_queue<pair<ll,ll>> Q;
	Q.push({0,sy*10000+sx*10+0});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cy=Q.top().second/10000;
		int cx=Q.top().second/10%1000;
		int num=Q.top().second%10;
		Q.pop();
		if(D[cy][cx][num]!=co) continue;
		FORR(t,T[cy][cx]) {
			int ty=t[0];
			int tx=t[1];
			int nnum=t[2]^num;
			if(D[ty][tx][nnum]>co+cost[ty][tx]) {
				D[ty][tx][nnum]=co+cost[ty][tx];
				Q.push({-D[ty][tx][nnum],ty*10000+tx*10+nnum});
				dp[ty][tx][nnum]=0;
				
			}
			if(D[ty][tx][nnum]==co+cost[ty][tx]) {
				(dp[ty][tx][nnum]+=dp[cy][cx][num])%=mo;
			}
		}
	}
	return {D[sy][sx][1],dp[sy][sx][1]};
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	int SY,SX,GY,GX;
	FOR(y,H) {
		cin>>C[y];
		FOR(x,W) {
			if(C[y][x]=='S') SY=y,SX=x;
			if(C[y][x]=='G') GY=y,GX=x;
		}
	}
	if(SX>GX) {
		FOR(y,H) reverse(ALL(C[y]));
		SX=W-1-SX;
		GX=W-1-GX;
	}
	if(SY>GY) {
		for(y=0;y*2<H;y++) swap(C[y],C[H-1-y]);
		SY=H-1-SY;
		GY=H-1-GY;
	}
	FOR(y,H) FOR(x,W) {
		if(C[y][x]=='.') cost[y][x]=1;
		else cost[y][x]=1<<20;
	}
	
	SY++,SX++,GY++,GX++;
	for(x=SX;x<=GX+1;x++) B[SY-1][x]=1;
	for(x=SX+1;x<=GX;x++) R[SY][x]=1;
	for(y=SY-1;y<=GY;y++) B[y][GX+1]=1;
	for(y=SY;y<=GY-1;y++) R[y][GX]=1;
	
	vector<pair<int,int>> edge;
	FOR(y,H) edge.push_back({y,0});
	FOR(y,H) edge.push_back({y,W-1});
	for(x=1;x<W-1;x++) edge.push_back({0,x});
	for(x=1;x<W-1;x++) edge.push_back({H-1,x});
	
	FOR(i,edge.size()) FOR(j,i) {
		int st=R[edge[i].first+1][edge[i].second+1]&&(edge[i].first==0||edge[i].second==W-1);
		st^=R[edge[j].first+1][edge[j].second+1]&&(edge[j].first==0||edge[j].second==W-1);
		T[edge[i].first][edge[i].second].push_back({edge[j].first,edge[j].second,st});
		T[edge[j].first][edge[j].second].push_back({edge[i].first,edge[i].second,st});
	}
	
	int dy[8]={1,1,1,0,0,-1,-1,-1};
	int dx[8]={-1,0,1,-1,1,-1,0,1};
	FOR(y,H) FOR(x,W) {
		FOR(i,8) {
			int ty=y+dy[i];
			int tx=x+dx[i];
			if(ty<0||ty>=H||tx<0||tx>=W) continue;
			int st=(B[ty+1][tx+1]&R[y+1][x+1])|(R[ty+1][tx+1]&B[y+1][x+1]);
			T[y][x].push_back({ty,tx,st});
		}
		sort(ALL(T[y][x]));
		T[y][x].erase(unique(ALL(T[y][x])),T[y][x].end());
	}
	
	ll mi=1<<30;
	ll cnt=0;
	FOR(y,H) FOR(x,W) {
		if(R[y+1][x+1]) {
			pair<ll,ll> ret=hoge(y,x);
			if(ret.first<mi) {
				mi=ret.first;
				cnt=0;
			}
			if(ret.first==mi) cnt+=ret.second;
			cost[y][x]=1<<20;
		}
	}
	
	if(mi>=1<<20) {
		cout<<"No"<<endl;
	}
	else {
		cnt=cnt%mo*(mo+1)/2%mo;
		cout<<"Yes"<<endl;
		cout<<mi<<" "<<cnt%mo<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
