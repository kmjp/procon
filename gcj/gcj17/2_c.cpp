#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W;
string S[51];
int mask[2501];
int NID;
int ID[51][51];
int LR[51][51];
int UD[51][51];

class SCC {
public:
	static const int MV = 5000;
	vector<vector<int> > SC; int NV,GR[MV],rev[MV];
private:
	vector<int> E[MV], RE[MV], NUM; int vis[MV];
public:
	void init(int NV) { this->NV=NV; for(int i=0;i<MV;i++) { E[i].clear(); RE[i].clear();}}
	void add_edge(int x,int y) { E[x].push_back(y); RE[y].push_back(x); }
	void dfs(int cu) { vis[cu]=1; for(int i=0;i<E[cu].size();i++) if(!vis[E[cu][i]]) dfs(E[cu][i]); NUM.push_back(cu); }
	void revdfs(int cu, int ind) { int i; vis[cu]=1; GR[cu]=ind; SC[ind].push_back(cu); rev[cu]=ind;
		FOR(i,RE[cu].size()) if(!vis[RE[cu][i]]) revdfs(RE[cu][i],ind);}
	void scc() {
		int c=0; SC.clear(); SC.resize(MV); NUM.clear();
		ZERO(vis); for(int i=0;i<NV;i++) if(!vis[i]) dfs(i);
		ZERO(vis); for(int i=NUM.size()-1;i>=0;i--) if(!vis[NUM[i]]){
			SC[c].clear(); revdfs(NUM[i],c); sort(SC[c].begin(),SC[c].end()); c++;
		}
		SC.resize(c);
	}
};

class TwoSat {
	int NV;
	SCC sc;
public:
	vector<int> val;
	void init(int NV) { this->NV=NV*2; sc.init(NV*2); val.resize(NV);}
	void add_edge(int x,int y) { // k+0:normal k+NV:inverse
		sc.add_edge((x+NV/2)%NV,y);
		sc.add_edge((y+NV/2)%NV,x);
	}
	bool sat() { // empty:false 
		sc.scc();
		for(int i=0;i<NV/2;i++) if(sc.GR[i]==sc.GR[i+NV/2]) return false;
		for(int i=0;i<NV/2;i++) val[i]=sc.GR[i]>sc.GR[i+NV/2];
		return true;
	}
};
void dfs(int cy,int cx,int dy,int dx,int id,int dir) {
	cy+=dy;
	cx+=dx;
	if(cy<0 || cy>=H || cx<0 || cx>=W) return;
	if(S[cy][cx]=='+') mask[id] &= 3^(1<<dir);
	if(S[cy][cx]=='#' || S[cy][cx]=='+') return;
	
	if(S[cy][cx]=='/') {
		if((dx==0&&dy==-1)||(dx==-1&&dy==0)) {
			if(LR[cy][cx]>=0) {
				mask[LR[cy][cx]%10000] &= 3^(1<<(LR[cy][cx]/10000));
				mask[id] &= 3^(1<<dir);
				LR[cy][cx]=-1;
			}
			else {
				LR[cy][cx]=dir*10000+id;
			}
		}
		else {
			if(UD[cy][cx]>=0) {
				mask[UD[cy][cx]%10000] &= 3^(1<<(UD[cy][cx]/10000));
				mask[id] &= 3^(1<<dir);
				UD[cy][cx]=-1;
			}
			else {
				UD[cy][cx]=dir*10000+id;
			}
		}
		if(dy==0&&dx==1)  dfs(cy,cx,-1,0,id,dir);
		if(dy==0&&dx==-1) dfs(cy,cx,1,0,id,dir);
		if(dy==1&&dx==0)  dfs(cy,cx,0,-1,id,dir);
		if(dy==-1&&dx==0) dfs(cy,cx,0,1,id,dir);
	}
	else if(S[cy][cx]=='\\') {
		if((dx==0&&dy==-1)||(dx==1&&dy==0)) {
			if(LR[cy][cx]>=0) {
				mask[LR[cy][cx]%10000] &= 3^(1<<(LR[cy][cx]/10000));
				mask[id] &= 3^(1<<dir);
				LR[cy][cx]=-1;
			}
			else {
				LR[cy][cx]=dir*10000+id;
			}
		}
		else {
			if(UD[cy][cx]>=0) {
				mask[UD[cy][cx]%10000] &= 3^(1<<(UD[cy][cx]/10000));
				mask[id] &= 3^(1<<dir);
				UD[cy][cx]=-1;
			}
			else {
				UD[cy][cx]=dir*10000+id;
			}
		}
		if(dy==0&&dx==1)  dfs(cy,cx,1,0,id,dir);
		if(dy==0&&dx==-1) dfs(cy,cx,-1,0,id,dir);
		if(dy==1&&dx==0)  dfs(cy,cx,0,1,id,dir);
		if(dy==-1&&dx==0) dfs(cy,cx,0,-1,id,dir);
	}
	else if(S[cy][cx]=='.') {
		if(dx==0) {
			if(LR[cy][cx]>=0) {
				mask[LR[cy][cx]%10000] &= 3^(1<<(LR[cy][cx]/10000));
				mask[id] &= 3^(1<<dir);
				LR[cy][cx]=-1;
			}
			else {
				LR[cy][cx]=dir*10000+id;
			}
		}
		else {
			if(UD[cy][cx]>=0) {
				mask[UD[cy][cx]%10000] &= 3^(1<<(UD[cy][cx]/10000));
				mask[id] &= 3^(1<<dir);
				UD[cy][cx]=-1;
			}
			else {
				UD[cy][cx]=dir*10000+id;
			}
		}
		dfs(cy,cx,dy,dx,id,dir);
	}
}


void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	
	ZERO(mask);
	NID=0;
	MINUS(LR);
	MINUS(UD);

	FOR(y,H) FOR(x,W) if(S[y][x]=='|' || S[y][x]=='-') {
		S[y][x]='+';
		ID[y][x]=NID;
		mask[NID]=3;
		NID++;
	}
	FOR(y,H) FOR(x,W) if(S[y][x]=='+') {
		dfs(y,x,0,1,ID[y][x],0);
		dfs(y,x,0,-1,ID[y][x],0);
		dfs(y,x,1,0,ID[y][x],1);
		dfs(y,x,-1,0,ID[y][x],1);
	}
	
	TwoSat ts;
	ts.init(NID);
	
	FOR(y,H) FOR(x,W) if(S[y][x]=='.') {
		if(LR[y][x]<0 && UD[y][x]<0) return _P("Case #%d: IMPOSSIBLE\n",_loop);
		if(UD[y][x]<0) UD[y][x]=LR[y][x];
		if(LR[y][x]<0) LR[y][x]=UD[y][x];
		ts.add_edge(LR[y][x]/10000*NID+LR[y][x]%10000,UD[y][x]/10000*NID+UD[y][x]%10000);
	}
	FOR(i,NID) {
		if(mask[i]==0) return _P("Case #%d: IMPOSSIBLE\n",_loop);
		if(mask[i]==1) ts.add_edge(i,i);
		if(mask[i]==2) ts.add_edge(i+NID,i+NID);
	}
	
	if(!ts.sat()) return _P("Case #%d: IMPOSSIBLE\n",_loop);
	FOR(y,H) FOR(x,W) if(S[y][x]=='+') {
		if(ts.val[ID[y][x]]==1) S[y][x]='-';
		else S[y][x]='|';
	}
	
	_P("Case #%d: POSSIBLE\n",_loop);
	FOR(y,H) _P("%s\n",S[y].c_str());
}

void init() {
}

int main(int argc,char** argv){
	int loop,loops;
	long long span;
	char tmpline[1000];
	struct timeval start,end,ts;
	
	if(argc>1) freopen(argv[1], "r", stdin);
	gettimeofday(&ts,NULL);
	cin>>loops;
	init();
	
	for(loop=1;loop<=loops;loop++) {
		gettimeofday(&start,NULL); solve(loop); gettimeofday(&end,NULL);
		span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
		fprintf(stderr,"Case : %d                                     time: %lld ms\n",loop,span/1000);
	}
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	fprintf(stderr,"**Total time: %lld ms\n",span/1000);
	
	return 0;
}


