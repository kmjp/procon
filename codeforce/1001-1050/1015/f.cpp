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
int N;
int A[505050],B[505050],C[505050],reA[505050],reB[505050];
vector<int> block[505050];

template<class V,int NV> class SegTree_ma {
public:
	vector<V> val;
	static V const def=-3;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_ma(){val=vector<V>(NV*2,def);};
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

template<class V,int NV> class SegTree_mi {
public:
	vector<V> val;
	static V const def=1<<20;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_mi(){val=vector<V>(NV*2,def);};
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
SegTree_ma<int,1<<20> stma;
SegTree_mi<int,1<<20> stmi;
vector<pair<int,int>> ev[505050];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N+2) {
			stma.update(i,-1);
			reA[i]=reB[i]=-1;
			stmi.update(i,N);
			ev[i].clear();
		}
		
		FOR(i,N) {
			cin>>A[i];
			reA[A[i]]=i;
		}
		FOR(i,N) {
			cin>>B[i];
			if(B[i]) {
				reB[B[i]]=i;
			}
		}
		//Bが逆転しないか確認
		for(i=1;i<=N;i++) if(reB[i]>=0) {
			//元々自身より小さい値が、前から後ろに移動した
			if(stma.getval(0,reA[i])>reB[i]) break;
			stma.update(reA[i],reB[i]);
		}
		if(i<=N) {
			cout<<"-1"<<endl;
			continue;
		}
		
		//行先未確定の要素の左端
		FOR(i,N+1) stma.update(i,-1);
		FOR(i,N) {
			if(reB[A[i]]>=0) {
				stma.update(A[i],reB[A[i]]);
			}
			else {
				//より小さい要素の移動先の右
				C[i]=stma.getval(0,A[i])+1;
			}
		}
		//行先未確定の要素の右端
		for(i=N-1;i>=0;i--) {
			if(reB[A[i]]>=0) {
				stmi.update(A[i],reB[A[i]]);
			}
			else {
				//より小さい要素の移動先の右
				x=stmi.getval(A[i],N+1)-1;
				if(x<C[i]) break;
				//C[i]～x
				ev[C[i]].push_back({-x,-A[i]});
			}
		}
		if(i>=0) {
			cout<<"-1"<<endl;
			continue;
		}
		priority_queue<pair<int,int>> Q;
		FOR(i,N) {
			FORR(v,ev[i]) Q.push(v);
			if(B[i]==0) {
				if(Q.empty()) break;
				if(-Q.top().first<i) break;
				B[i]=-Q.top().second;
				Q.pop();
			}
		}
		if(i<N) {
			cout<<"-1"<<endl;
			continue;
		}
		FOR(i,N) cout<<B[i]<<" ";
		cout<<endl;
		
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
