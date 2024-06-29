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

int N;
vector<int> V[4];

static ll const def=0;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val;
	vector<pair<V,int>> ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2);
		FOR(i,NV) ma[NV+i]={0,-i};
		for(i=NV-1;i>=1;i--) ma[i]=max(ma[i*2],ma[i*2+1]);
	};
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k].first+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=max(ma[k*2],ma[k*2+1]);
			ma[k].first+=val[k];
		}
	}
};
SegTree_3<int,1<<12> sta,stb;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x>>y;
		V[x].push_back(y);
	}
	FOR(i,4) sort(ALL(V[i]));
	int mi=1<<20;
	
	FOR(i,3030) {
		sta.update(i+1,1<<12,-1);
		stb.update(i+1,1<<12,-1);
	}
	
	FORR(v,V[1]) sta.update(v,1<<12,1);
	
	for(int lenb=1;lenb<=V[2].size()+V[3].size()+1;lenb++) {
		int vis[1515]={};
		multiset<pair<int,int>> M;
		
		FORR(v,V[2]) stb.update(min(lenb-1,v),1<<12,1);
		FOR(x,V[3].size()) {
			int v=V[3][x];
			sta.update(v-lenb,1<<12,1);
			vis[x]=0;
			if(sta.ma[1].first>0) {
				sta.update(v-lenb,1<<12,-1);
				vis[x]=1;
				stb.update(min(lenb-1,v),1<<12,1);
				sta.update(v,1<<12,1);
			}
			if(vis[x]==0) M.insert({v,x});
		}
		
		for(int a2=0;a2<=V[2].size();a2++) {
			int lena=V[1].size()+a2+V[3].size()+1;
			int b2=V[2].size()-a2;
			
			if(a2>0) {
				int v=V[2][V[2].size()-a2];
				stb.update(min(lenb-1,v),1<<12,-1);
				sta.update(v-lenb,1<<12,1);
			}
			
			while(sta.ma[1].first>0) {
				auto it=M.lower_bound({-sta.ma[1].second+1,0});
				if(it==M.begin()) break;
				it--;
				x=it->second;
				M.erase(it);
				int v=V[3][x];
				vis[x]=1;
				sta.update(v-lenb,1<<12,-1);
				stb.update(min(lenb-1,v),1<<12,1);
				sta.update(v,1<<12,1);
				
			}
			
			if(sta.ma[1].first<=0&&stb.ma[1].first<=0) {
				mi=min(mi,lena+lenb);
			}
			
		}
		FOR(x,V[3].size()) {
			int v=V[3][x];
			if(vis[x]==0) sta.update(v-lenb,1<<12,-1);
			else {
				stb.update(min(lenb-1,v),1<<12,-1);
				sta.update(v,1<<12,-1);
			}
		}
		
		FORR(v,V[2]) sta.update(v-lenb,1<<12,-1);
	}
	
	
	if(mi==1<<20) mi=-1;
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
