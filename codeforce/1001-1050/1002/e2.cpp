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
int A[303030],B[303030];
int pos[303030];
int dif[303030];
vector<int> add[606060];
int tim[303030];


static ll const def=1<<20;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2); ma.resize(NV*2);
		FOR(i,NV) val[i+NV]=ma[i+NV]={0,-i}; //ƒL[‚Ì~‡¸‡‚Í‚±‚Ì•„†‚ÅŽw’è
		for(i=NV-1;i>=1;i--) ma[i]=min(ma[2*i],ma[2*i+1]);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return {def,-k};
		if(x<=l && r<=y) return ma[k];
		auto p=min(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
		p.first+=val[k].first;
		return p;
	}
	
	void reset(int x,int y, int l=0,int r=NV,int k=1) { //ŒJ‚è•Ô‚µŽg‚¤‚Æ‚«‚Íupdate‚æ‚èreset‚ª—Ç‚¢
		if(l>=r||y<=x||y<=l||x>=r) return;
		val[k].first=ma[k].first=0;
		if(r-l!=1) {
			reset(x,y,l,(l+r)/2,k*2);
			reset(x,y,(l+r)/2,r,k*2+1);
			ma[k]=min(ma[2*k],ma[2*k+1]);
		}
	}
	void update(int x,int y, int v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		if(x<=l && r<=y) {
			val[k].first+=v;
			ma[k].first+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=min(ma[2*k],ma[2*k+1]);
			ma[k].first+=val[k].first;
		}
	}
};
SegTree_3<pair<int,int>,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		map<int,int> rev;
		FOR(i,2*H*W+2) add[i].clear();
		tim[0]=0;
		for(i=1;i<=H*W;i++) {
			cin>>A[i];
			pos[i]=-1;
			tim[i]=1<<20;
		}
		for(i=1;i<=H*W;i++) {
			cin>>B[i];
			rev[B[i]]=i;
		}
		
		for(i=1;i<=H*W;i++) {
			if(rev.count(A[i])==0) break;
			pos[i]=rev[A[i]];
		}
		if(pos[1]==1) tim[0]=1<<20;
		
		int sum=0;
		int ok=1;
		int ma=0;
		for(i=1;i<=H*W;i++) {
			int dif=pos[i]-pos[i-1]-1;
			//‡”Ô‚ª‹t“]‚È‚ç•s‰Â
			if(dif<0) break;
			//Œã‚ë‚É‘}“ü•s‰Â‚È‚Ì‚ÉŒ„ŠÔ‚ª‚ ‚é‚È‚ç•s‰Â
			if(dif&&!ok) break;
			sum+=dif;
			
			if(dif) {
				for(x=pos[i-1]+1;x<pos[i];x++) add[i-1].push_back(B[x]);
				tim[i-1]=(W-(i-1)%W)%W;
			}
			
			//Œã‚ë‚É‘}“ü‰Â”\‚©H
			if(i%W==0||(i+sum)%W==0||i/W!=(i+sum)/W) ok=1;
			else ok=0;
			if(ok) ma=i;
		}
		add[ma].clear();
		for(x=pos[ma]+1;x<=H*W;x++) add[ma].push_back(B[x]);
		if(pos[ma]<H*W) tim[ma]=(W-(ma)%W)%W;
		x=0;
		st.reset(0,ma+1);
		for(i=0;i<=ma;i++) {
			st.update(i,i+1,tim[i]);
			x+=add[i].size();
		}
		vector<pair<int,int>> ret;
		while(1) {
			auto p=st.getval(0,ma+1);
			if(p.first>0) break;
			x=-p.second;
			ret.push_back({1+(x+W-1)/W,add[x].back()});
			add[x].pop_back();
			st.update(x+1,ma+1,-1);
			if(add[x].empty()) st.update(x,x+1,1<<20);
		}
		cout<<H*W-ma<<endl;
		assert(ret.size()==H*W-ma);
		FORR2(a,b,ret) cout<<a<<" "<<b<<endl;
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
