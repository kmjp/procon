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

int H,W,N,D;
vector<int> V[101010];
template<int um> class UF_pop {
	public:
	vector<int> par,rank,cnt; vector<vector<int>> hist;
	UF_pop() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; hist.clear(); FOR(i,um) rank[i]=0,par[i]=i,cnt[i]=1;}
	int operator[](int x) {return (par[x]==x)?(x):operator[](par[x]);}
	int count(int x) {return cnt[operator[](x)];}
	void pop() {
		if(hist.size()) {
			auto a=hist.back();
			hist.pop_back();
			par[a[0]]=a[1]; rank[a[0]]=a[2]; cnt[a[0]]=a[3];
			par[a[4]]=a[5]; rank[a[4]]=a[6]; cnt[a[4]]=a[7];
		}
	}
	void operator()(int x,int y) {
		x=operator[](x); y=operator[](y);
		hist.push_back({x,par[x],rank[x],cnt[x],y,par[y],rank[y],cnt[y]});
		if(x==y) return;
		if(rank[x]<rank[y]) par[x]=y, cnt[y]+=cnt[x];
		else rank[x]+=(rank[x]==rank[y]), par[y]=x, cnt[x]+=cnt[y];
	}
};
UF_pop<101010> uf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>N>>D;
	FOR(y,H) V[y].resize(W);
	int num=0;
	
	FOR(i,N) {
		cin>>y>>x;
		x--,y--;
		V[y][x]=1;
		for(int y2=y-D;y2<=y+D;y2++) if(y2>=0&&y2<H) {
			for(int x2=x-(D-abs(y2-y));x2<=x+(D-abs(y2-y));x2++) if(x2>=0&&x2<W) {
				if(V[y2][x2]&&uf[y2*W+x2]!=uf[y*W+x]) {
					if(uf.count(y2*W+x2)==1&&uf.count(y*W+x)==1) num++;
					if(uf.count(y2*W+x2)>1&&uf.count(y*W+x)>1) num--;
					
					uf(y2*W+x2,y*W+x);
				}
			}
		}
	}
	int mi=1<<20,ma=-1;
	FOR(y,H) FOR(x,W) if(V[y][x]==0) {
		int step=0;
		int cnum=num;
		for(int y2=y-D;y2<=y+D;y2++) if(y2>=0&&y2<H) {
			for(int x2=x-(D-abs(y2-y));x2<=x+(D-abs(y2-y));x2++) if(x2>=0&&x2<W) {
				if(V[y2][x2]&&uf[y2*W+x2]!=uf[y*W+x]) {
					if(uf.count(y2*W+x2)==1&&uf.count(y*W+x)==1) cnum++;
					if(uf.count(y2*W+x2)>1&&uf.count(y*W+x)>1) cnum--;
					step++;
					uf(y2*W+x2,y*W+x);
				}
			}
		}
		mi=min(mi,cnum);
		ma=max(ma,cnum);
		FOR(j,step) uf.pop();
	}
	cout<<mi<<" "<<ma<<endl;
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
