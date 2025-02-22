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

int T,N;
ll A[505050];
int Q;
ll P[505050],V[505050];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME],val[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	void set(int e,V v) { add(e,v-val[e]);}
	int lower_bound(V val) {
		V tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<val) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
};
BIT<int,20> bit;

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=-1;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<int,1<<20> stma,stmi;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		vector<ll> Vs;
		FOR(i,N) {
			cin>>A[i];
			A[i]=(A[i]<<20)+i;
			Vs.push_back(A[i]);
		}
		cin>>Q;
		FOR(i,Q) {
			cin>>P[i]>>V[i];
			P[i]--;
			V[i]=(V[i]<<20)+P[i];
			Vs.push_back(V[i]);
		}
		sort(ALL(Vs));
		set<int> S;
		FOR(i,N) {
			A[i]=lower_bound(ALL(Vs),A[i])-Vs.begin();
			bit.add(A[i],1);
			stma.update(i,A[i]);
			stmi.update(i,Vs.size()-A[i]);
			if(i&&A[i]<A[i-1]) S.insert(i);
		}
		
		FOR(i,Q+1) {
			
			if(S.empty()) {
				cout<<"-1 -1"<<endl;
			}
			else {
				x=*S.begin()-1;
				y=*S.rbegin();
				int tma=stma.getval(x,y+1);
				int tmi=Vs.size()-stmi.getval(x,y+1);
				cout<<bit(tmi)<<" "<<bit(tma)<<endl;
			}
			
			
			if(i==Q) break;
			x=P[i];
			bit.add(A[x],-1);
			A[x]=V[i]=lower_bound(ALL(Vs),V[i])-Vs.begin();
			S.erase(x);
			S.erase(x+1);
			if(x&&A[x-1]>A[x]) S.insert(x);
			if(x+1<N&&A[x]>A[x+1]) S.insert(x+1);
			bit.add(A[x],1);
			stma.update(x,A[x]);
			stmi.update(x,Vs.size()-A[x]);
		}
		
		
		FOR(i,N) {
			bit.add(A[i],-1);
			stma.update(i,-1);
			stmi.update(i,-1);
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
