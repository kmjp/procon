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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,19> num[19],sum[19];
int pos[202020][19];

int N,Q;
ll A[201010];
ll C[201010],X[201010],L[201010],R[201010];
ll K[201010];
int pre[202020];
vector<ll> As;

template<class V,int NV> class SegTree_1 {
public:
	vector<vector<V>> val;
	vector<int> LV;
	vector<int> start;
	
	SegTree_1(){val.resize(NV*2);LV.resize(NV*2);start.resize(NV*2);};
	array<ll,3> getval(ll CL,ll CR,V v,int k=1) { // x<=i<y
		if(val[k].empty()) return {0,v,0};
		if(CR<=val[k][0]) return {0,v,0};
		if(CL>val[k].back()) return {0,v,0};
		
		int x=lower_bound(ALL(val[k]),CL)-val[k].begin();
		int y=lower_bound(ALL(val[k]),CR)-val[k].begin();
		if(x==y) return {0,v,0};
		ll nu=num[LV[k]](start[k]+y-1)-num[LV[k]](start[k]+x-1);
		ll su=sum[LV[k]](start[k]+y-1)-sum[LV[k]](start[k]+x-1);
		if(su<=v) {
			return {nu,v-su,0};
		}
		if(nu==1) return {1,v-su,1};
		
		auto p=getval(CL,CR,v,k*2+1);
		if(p[2]==1) return p;
		auto q=getval(CL,CR,p[1],k*2);
		q[0]+=p[0];
		return q;
	}
	void set(int entry,V v) {
		val[entry+NV].clear();
		val[entry+NV].push_back(v);
	}
	void build(int MV=NV) {
		int i;
		int cur=0;
		FOR(i,MV) {
			start[NV+i]=i;
			ll v=val[NV+i][0];
			if(v&((1<<20)-1)) pos[N+(v&((1<<20)-1))-1][0]=cur++;
			else pos[v>>20][0]=cur++;
		}
		int L=NV,R=NV+i;
		while(L>1) {
			L=L/2;
			R=(R+1)/2;
			int cur=0;
			for(int i=L;i<R;i++) {
				val[i].clear();
				LV[i]=LV[i*2]+1;
				start[i]=cur;
				int a=0,b=0;
				int x=i*2,y=i*2+1;
				while(a<val[x].size() || b<val[y].size()) {
					if(a==val[x].size()) {
						val[i].push_back(val[y][b++]);
					}
					else if(b==val[y].size()) {
						val[i].push_back(val[x][a++]);
					}
					else if(val[x][a]<val[y][b]) {
						val[i].push_back(val[x][a++]);
					}
					else {
						val[i].push_back(val[y][b++]);
					}
				}
				FORR(v,val[i]) {
					if(v&((1<<20)-1)) pos[N+(v&((1<<20)-1))-1][LV[i]]=cur++;
					else pos[v>>20][LV[i]]=cur++;
				}
			}
		}
	}
};
SegTree_1<ll,1<<18> st;




void solve() {
	int i,j,k,l,r,x,y; string s;
	
	srand(time(NULL));
	cin>>N>>Q;
	FOR(i,N) {
		cin>>A[i];
		As.push_back((A[i]<<20)+i);
	}
	FOR(i,Q) {
		cin>>C[i]>>X[i]>>L[i]>>R[i]>>K[i];
		C[i]--;
		L[i]--;
		As.push_back((X[i]<<20)+N+i);
	}
	sort(ALL(As));
	FOR(i,N) {
		pre[i]=i;
		x=lower_bound(ALL(As),(A[i]<<20)+i)-As.begin();
		st.set(x,(1LL*i)<<20);
	}
	FOR(i,Q) {
		x=lower_bound(ALL(As),(X[i]<<20)+N+i)-As.begin();
		st.set(x,(C[i]<<20)+1+i);
	}
	st.build(N+Q);
	FOR(i,N) {
		FOR(j,19) {
			num[j].add(pos[i][j],1);
			sum[j].add(pos[i][j],A[i]);
		}
	}
	
	FOR(i,Q) {
		x=C[i];
		FOR(j,19) {
			num[j].add(pos[pre[x]][j],-1);
			if(pre[x]<N) {
				sum[j].add(pos[x][j],-A[x]);
			}
			else {
				sum[j].add(pos[pre[x]][j],-X[pre[x]-N]);
			}
		}
		pre[x]=N+i;
		FOR(j,19) {
			num[j].add(pos[pre[x]][j],1);
			sum[j].add(pos[pre[x]][j],X[i]);
		}
		ll CL=L[i]<<20;
		ll CR=R[i]<<20;
		
		auto p=st.getval(CL,CR,K[i]-1);
		if(p[2]) cout<<p[0]<<endl;
		else cout<<-1<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
