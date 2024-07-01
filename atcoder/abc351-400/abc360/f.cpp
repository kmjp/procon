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
int L[101010],R[101010];
vector<int> C={0,1,1000000000};

template<class V,int NV> class SegTree_3 {
public:
	vector<pair<V,int> > val;
	vector<pair<V,int> > ma;
	static V const def=-(1LL<<50);
	SegTree_3(){
		int i;
		val.resize(NV*2); ma.resize(NV*2);
		FOR(i,NV) val[i+NV]=ma[i+NV]=make_pair(0,-i);
		FOR(i,NV) val[i]=make_pair(0,0);
		for(i=NV-1;i>=1;i--) ma[i]=max(ma[2*i],ma[2*i+1]);
	};
	
	pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return make_pair(def,0);
		if(x<=l && r<=y) return ma[k];
		auto a=max(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
		a.first += val[k].first;
		return a;
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k].first+=v;
			ma[k].first+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=max(ma[k*2],ma[k*2+1]);
			ma[k].first += val[k].first;
		}
	}
};
SegTree_3<ll,1<<20> st;

vector<int> ev[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>L[i]>>R[i];
		C.push_back(L[i]+1);
		if(R[i]+1<=1000000000) C.push_back(R[i]+1);
		C.push_back(L[i]);
		C.push_back(R[i]);
	}
	sort(ALL(C));
	int ma=0;
	int LL=0,RR=1;
	C.erase(unique(ALL(C)),C.end());
	int NC=C.size();
	FOR(i,N) {
		L[i]=lower_bound(ALL(C),L[i])-C.begin();
		R[i]=lower_bound(ALL(C),R[i])-C.begin();
		if(R[i]>L[i]+1) {
			st.update(L[i]+1,R[i],1);
			ev[L[i]].push_back(i);
			ev[L[i]+1].push_back(i);
			ev[R[i]].push_back(i);
		}
	}
	
	FOR(i,C.size()) {
		int c=C[i];
		FORR(e,ev[i]) {
			if(i==L[e]) {
				st.update(L[e]+1,R[e],-1);
			}
			else if(i==L[e]+1) {
				st.update(R[e]+1,NC,1);
			}
			else {
				st.update(R[e]+1,NC,-1);
			}
		}
		auto p=st.getval(i+1,NC);
		if(p.first>ma) {
			ma=p.first;
			LL=c;
			RR=C[-p.second];
		}
	}
	cout<<LL<<" "<<RR<<endl;
	
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
