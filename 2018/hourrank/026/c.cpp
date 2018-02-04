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

int N;
ll A[505050];
ll ma;

template<typename V> struct ConvexHull {
	deque<pair<V,V>> Q;
	int cmptype=0; // 0-min 1-max
	V calc(pair<V,V> p, V x) {
		return p.first*x+p.second;
	}
	int dodo(pair<V,V> A,pair<V,V> B, pair<V,V> C) { // max or min
		return cmptype^((B.second-C.second)*(B.first-A.first)<=(A.second-B.second)*(C.first-B.first));
	}
	void add(V a, V b) { // add ax+b
		Q.push_back({a,b});
		int v;
		while((v=Q.size())>=3 && dodo(Q[v-3],Q[v-2],Q[v-1]))
			Q[v-2]=Q[v-1], Q.pop_back();
	}
	void add(vector<pair<V,V>> v) {
		sort(v.begin(),v.end());
		if(cmptype==1) reverse(v.begin(),v.end());
		for(auto r=v.begin();r!=v.end();r++) add(r->first,r->second);
	}
	
	
	V query(V x) {
		int L=-1,R=Q.size()-1;
		while(R-L>1) {
			int M=(L+R)/2;
			(cmptype^((calc(Q[M],x)<=calc(Q[M+1],x)))?L:R)=M;
		}
		return calc(Q[R],x);
	}
};

void dfs(int L,int R) {
	if(R-L<=1) return ;
	if(R-L==2) {
		ma=max(ma,A[L]*A[L+1]);
		return;
	}
	
	int M=L+(R-L)/2;
	dfs(L,M);
	dfs(M,R);
	vector<pair<ll,ll>> V;
	ll a=0,b=0;
	int i;
	//cout<<"go "<<L<<M<<R<<endl;
	for(i=M;i<R;i++) {
		b+=A[i]*a;
		a+=A[i];
		//cout<<"!"<<a<<"x+"<<b<<endl;
		V.push_back({a,b});
	}
	sort(ALL(V));
	
	ConvexHull<ll> ch;
	FORR(v,V) {
		//cout<<"++ "<<v.first<<"x+"<<v.second<<endl;
		ch.add(v.first,v.second);
	}
	//FOR(i,30) cout<<i<<" "<<ch.query(i)<<endl;
	
	a=0,b=0;
	for(i=M-1;i>=L;i--) {
		b+=A[i]*a;
		a+=A[i];
		//cout<<L<<i<<M<<" "<<a<<"x+"<<b<<"  "<<(ch.query(a)+b)<<endl;
		ma=max(ma,ch.query(a)+b);
	}
	
	
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	
	dfs(0,N);
	
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
