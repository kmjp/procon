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

template<class V,int NV> class RMQ {
private:
	V table[NV+1][1<<NV];
	int LG[1<<NV];
	int NV2;
public:
	static V const def=-(1<<30);
	V comp(V l,V r){ return max(l,r);};
	RMQ() {
		int i,x;
		NV2=1<<NV;
		LG[1]=0;
		for(i=2;i<NV2;i++) LG[i]=LG[i/2]+1;
		FOR(i,NV) FOR(x,NV2) table[i][x]=def;
	}
	void set(int x,V v){ table[0][x]=v;}
	void build() {
		int i,j,x,y;
		FOR(i,NV) FOR(x,NV2) table[i+1][x]=comp(table[i][x],(x+(1<<i)<NV2)?table[i][x+(1<<i)]:def);
	}
	V query(int L,int R) { //[L,R),
		L=max(0,L), R=min(R,NV2);
		if(R<=L) return def;
		int WL=LG[R-L];
		return comp(table[WL][L],table[WL][R-(1<<WL)]);
	}
	
};
RMQ<int,18> LR,UD;


int H,W,Q;
int A[505050],B[505050];

map<int,ll> memo[50505][4];

ll dfs(int y,int x,int dir) {
	if(memo[y][dir].count(x)) return memo[y][dir][x];
	ll ret=0;
	int i;
	if(dir==0) { //up
		if(UD.query(0,y)<B[x]) return memo[y][dir][x]=y;
		int ty=0;
		for(i=17;i>=0;i--) if(UD.query(ty+(1<<i),y)>B[x]) ty+=1<<i;
		ret=y-ty+max(dfs(ty,x,1),dfs(ty,x,3));
		
	}
	else if(dir==1) { //right
		if(LR.query(x+1,W)<A[y]) return memo[y][dir][x]=W-1-x;
		int tx=W-1;
		for(i=17;i>=0;i--) if(LR.query(x+1,tx-(1<<i)+1)>A[y]) tx-=1<<i;
		ret=tx-x+max(dfs(y,tx,0),dfs(y,tx,2));
	}
	else if(dir==2) { //down
		if(UD.query(y+1,H)<B[x]) return memo[y][dir][x]=H-1-y;
		int ty=H-1;
		for(i=17;i>=0;i--) if(UD.query(y+1,ty-(1<<i)+1)>B[x]) ty-=1<<i;
		ret=ty-y+max(dfs(ty,x,1),dfs(ty,x,3));
	}
	else if(dir==3) { //left
		if(LR.query(0,x)<A[y]) return memo[y][dir][x]=x;
		int tx=0;
		for(i=17;i>=0;i--) if(LR.query(tx+(1<<i),x)>A[y]) tx+=1<<i;
		ret=x-tx+max(dfs(y,tx,0),dfs(y,tx,2));
	}
	//cout<<y<<" "<<x<<" "<<dir<<" "<<ret<<endl;
	return memo[y][dir][x]=ret;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>Q;
	FOR(y,H) {
		cin>>A[y];
		UD.set(y,A[y]);
	}
	FOR(x,W) {
		cin>>B[x];
		LR.set(x,B[x]);
	}
	UD.build();
	LR.build();
	while(Q--) {
		cin>>y>>x;
		y--,x--;
		cout<<max({dfs(y,x,0),dfs(y,x,1),dfs(y,x,2),dfs(y,x,3)})<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
