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
int X[202020],Y[202020];
vector<int> XpY,XmY;

template<class V,int NV> class SegTree_1_ma {
public:
	vector<V> val;
	static V const def=-(1<<30);
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1_ma(){val=vector<V>(NV*2,def);};
	void reinit(){ FORR(v,val) v=-(1<<30);}
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(v,val[entry]); //上書きかチェック
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1_ma<int,1<<20> stp,stm;
int ma[202020],mi[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<pair<ll,int>> P;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		XpY.push_back(X[i]+Y[i]);
		XmY.push_back(X[i]-Y[i]);
		P.push_back({X[i],Y[i]});
	}
	sort(ALL(P));
	sort(ALL(XpY));
	sort(ALL(XmY));
	int ret=1<<30;
	FOR(i,N) {
		X[i]=P[i].first;
		Y[i]=P[i].second;
		ma[i]=max(ma[i],abs(X[i]+Y[i]-*XpY.begin()));
		ma[i]=max(ma[i],abs(X[i]+Y[i]-*XpY.rbegin()));
		ma[i]=max(ma[i],abs(X[i]-Y[i]-*XmY.begin()));
		ma[i]=max(ma[i],abs(X[i]-Y[i]-*XmY.rbegin()));
		
		mi[i]=1<<30;
		mi[i]=min(mi[i],abs(X[i]+Y[i]-stp.getval(0,Y[i]+1)));
		mi[i]=min(mi[i],abs(X[i]-Y[i]-stm.getval(Y[i],N+1)));
		stp.update(Y[i],Y[i]+X[i]);
		stm.update(Y[i],X[i]-Y[i]);
	}
	stp.reinit();
	stm.reinit();
	for(i=N-1;i>=0;i--) {
		mi[i]=min(mi[i],abs(X[i]+Y[i]+stp.getval(Y[i],N+1)));
		mi[i]=min(mi[i],abs(-X[i]+Y[i]-stm.getval(0,Y[i]+1)));
		stp.update(Y[i],-Y[i]-X[i]);
		stm.update(Y[i],-X[i]+Y[i]);
		//cout<<X[i]<<" "<<Y[i]<<" "<<ma[i]<<" "<<mi[i]<<endl;
		ret=min(ret,ma[i]-mi[i]);
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
