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

int N,M;
int H[303030];
ll S[303030];
int L[303030],R[303030];
ll X[303030];
int Lr[303030],Rl[303030];
int ret[303030];
pair<int,int> P[303030];
vector<pair<ll,int>> Q;

int SL[303030],SR[303030],avail[303030];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=-(1<<30);
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
SegTree_1<int,1<<20> ma,mat;

ll F(int L,int R) {
	if(R<L) return -1;
	return 2*(S[R]-S[L])*(R-L);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>H[i];
		S[i+1]=S[i]+H[i];
		ma.update(i,H[i]);
		SL[i]=SR[i]=i;
		P[i]={H[i],i};
	}
	
	
	FOR(i,M) {
		cin>>L[i]>>R[i]>>X[i];
		L[i]--;
		if(F(L[i],R[i])<X[i]) {
			ret[i]=-1;
		}
		else {
			Lr[i]=R[i];
			for(j=20;j>=0;j--) if(F(L[i],Lr[i]-(1<<j))>=X[i]) Lr[i]-=1<<j;
			Rl[i]=L[i];
			for(j=20;j>=0;j--) if(F(Rl[i]+(1<<j),R[i])>=X[i]) Rl[i]+=1<<j;
			ret[i]=min(ma.getval(L[i],Lr[i]),ma.getval(Rl[i],R[i]));
			Q.push_back({X[i],i});
		}
	}
	
	sort(P,P+N);
	vector<vector<ll>> ev;
	FOR(i,N) {
		x=P[i].second;
		avail[x]=1;
		if(x && avail[x-1]) {
			SL[x]=SL[x-1];
			SR[SL[x-1]]=x;
		}
		if(avail[x+1]) {
			SR[SL[x]]=SR[x+1];
			SL[SR[x+1]]=SL[x];
		}
		ev.push_back({F(SL[x],SR[SL[x]]+1),SL[x],SR[SL[x]]+1});
	}
	
	sort(ALL(Q));
	reverse(ALL(Q));
	sort(ALL(ev));
	FORR(q,Q) {
		x=q.second;
		while(ev.size() && ev.back()[0]>=X[x]) {
			ll a=ma.getval(ev.back()[1],ev.back()[2]);
			//cout<<"add "<<ev.back()[1]<<" "<<ev.back()[2]<<" "<<ev.back()[0]<<" "<<a<<endl;
			mat.update(ev.back()[1],-a);
			ev.pop_back();
		}
		
		//cout<<x<<" "<<L[x]<<" "<<Rl[x]<<endl;
		//for(j=L[x]+1;j<Rl[x];j++) cout<<"  "<<j<<" "<<-mat.getval(j,j+1)<<endl;
		ret[x]=min(ret[x],-mat.getval(L[x]+1,Rl[x]));
		
	}
	
	FOR(i,M) cout<<ret[i]<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
