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

// ŽQÆ‚àXV‚àrange
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val;
	vector<int> clean;
	SegTree_3(){ val.resize(NV*2); clean.resize(NV*2);}
	
	ll getval(int v,int l=0,int r=NV,int k=1) {
		if(r<=v || v<l) return 0;
		ll ret=val[k];
		if(clean[k]==0 && r-l>=2) ret+=getval(v,l,(l+r)/2,k*2)+getval(v,(l+r)/2,r,k*2+1);
		return ret;
	}
	
	void add(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r || x>=y) return;
		if(x<=l && r<=y) {
			val[k]+=v;
		}
		else if(l < y && x < r) {
			if(clean[k]==1) {
				clean[k]=0;
				val[2*k]=val[2*k+1]=0;
				clean[2*k]=clean[2*k+1]=1;
			}
			add(x,y,v,l,(l+r)/2,k*2);
			add(x,y,v,(l+r)/2,r,k*2+1);
		}
	}
	void clear(int x,int y,int l=0,int r=NV,int k=1) {
		if(l>=r || x>=y) return;
		if(x<=l && r<=y) {
			val[k]=0;
			clean[k]=1;
		}
		else if(l < y && x < r) {
			if(clean[k]==1) {
				clean[k]=0;
				val[2*k]=val[2*k+1]=0;
				clean[2*k]=clean[2*k+1]=1;
			}
			val[2*k]+=val[k];
			val[2*k+1]+=val[k];
			val[k]=0;
			clear(x,y,l,(l+r)/2,k*2);
			clear(x,y,(l+r)/2,r,k*2+1);
		}
	}
};

int N,L,M;
vector<vector<int>> V;
SegTree_3<ll,1<<17> bta,btb;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L;
	j=0;
	FOR(i,N) {
		cin>>x>>y;
		if(x!=j) j=x,V.push_back(vector<int>());
		V.back().push_back(y);
	}
	
	ll mix=0, miv=0;
	FORR(v,V) {
		FORR(r,v) {
			bta.add(0,r,-1);
			bta.add(r+1,L+1,1);
			btb.add(0,r,r);
			btb.add(r+1,L+1,-r);
		}
		
		int LL=0,RR=L;
		while(LL+6<=RR) {
			int x1=(LL*2+RR)/3;
			int x2=(LL+RR*2)/3;
			ll v1=bta.getval(x1)*x1+btb.getval(x1);
			ll v2=bta.getval(x2)*x2+btb.getval(x2);
			if(v1<=v2) RR=x2;
			else LL=x1;
		}
		
		miv=1LL<<60;
		for(x=LL;x<=RR;x++) {
			ll v=bta.getval(x)*x+btb.getval(x);
			if(v<miv) miv=v,mix=x;
			if(v>miv) break;
		}
		bta.clear(mix+1,L+1);
		btb.clear(mix+1,L+1);
		btb.add(mix+1,L+1,miv);
	}
	
	cout<<miv<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
