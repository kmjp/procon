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

int N,p,q;
ll X[101010],Y[101010];

const ll EPS=0;
template<class C> C veccross(pair<C,C> p1,pair<C,C> p2,pair<C,C> p3) {
	p3.first-=p1.first;p2.first-=p1.first;
	p3.second-=p1.second;p2.second-=p1.second;
	return p3.first*p2.second-p2.first*p3.second;
}

template<class C> vector< pair<C, C> > convex_hull(vector< pair<C, C> >& vp) {
	vector<pair<pair<C, C>, int> > sorted;
	vector<int> res;
	int i,k=0,rb;
	
	vector< pair<C, C> > R;
	if(vp.size()<=2) {
		if(vp.size()>=1) R.push_back(vp[0]);
		if(vp.size()>=2 && vp[0]!=vp[1]) R.push_back(vp[1]);
		return R;
	}
	
	FOR(i,vp.size()) sorted.push_back(make_pair(vp[i],i));
	sort(sorted.begin(),sorted.end());
	
	res.resize(vp.size()*2);
	/* bottom */
	FOR(i,vp.size()) {
		while(k>1 && veccross(vp[res[k-2]],vp[res[k-1]],sorted[i].first)<=-EPS) k--;
		res[k++]=sorted[i].second;
	}
	/* top */
	for(rb=k, i=vp.size()-2;i>=0;i--) {
		while(k>rb && veccross(vp[res[k-2]],vp[res[k-1]],sorted[i].first)<=-EPS) k--;
		res[k++]=sorted[i].second;
	}
	res.resize(k-1);
	FORR(v,res) R.push_back(vp[v]);
	
	return R;
}

bool comp(pair<ll,ll> &L,pair<ll,ll> &R) {
	if(L==R) return 0;
	if(L.second==0 && L.first>0) return 1;
	if(R.second==0 && R.first>0) return 0;
	if(L.second>0 && R.second<=0) return 1;
	if(R.second>0 && L.second<=0) return 0;
	if(L.second>=0 && R.second<0) return 1;
	if(R.second>=0 && L.second<0) return 0;
	return L.first*R.second-L.second*R.first>0;
}

//反時計回りに直す
vector<pair<ll,ll>> unticlockwise(vector<pair<ll,ll>> V) {
	ll ret=0;
	int i;
	FOR(i,V.size()) ret+=V[i].first*V[(i+1)%V.size()].second-V[i].second*V[(i+1)%V.size()].first;
	if(ret<0) reverse(ALL(V));
	
	//さらに左下スタートに直す
	int tar=0;
	FOR(i,V.size()) {
		if(V[i].second<V[tar].second) tar=i;
		else if(V[i].second==V[tar].second&&V[i].first<V[tar].first) tar=i;
	}
	rotate(V.begin(),V.begin()+tar,V.end());
	
	return V;
}

vector<pair<ll,ll>> Minkowski_sum(vector<pair<ll,ll>> L,vector<pair<ll,ll>> R) {
	vector<pair<ll,ll>> V;
	int i,tar=0;
	L=unticlockwise(L);
	R=unticlockwise(R);
	
	FOR(i,L.size()-1) V.push_back({L[i+1].first-L[i].first,L[i+1].second-L[i].second});
	V.push_back({L[0].first-L.back().first,L[0].second-L.back().second});
	FOR(i,R.size()-1) V.push_back({R[i+1].first-R[i].first,R[i+1].second-R[i].second});
	V.push_back({R[0].first-R.back().first,R[0].second-R.back().second});
	vector<pair<ll,ll>> P={{L[0].first+R[0].first,L[0].second+R[0].second}};
	sort(ALL(V),comp);
	FORR2(dx,dy,V) {
		P.push_back({P.back().first+dx,P.back().second+dy});
	}
	return P;
}


vector<pair<ll,ll>> dfs(int L,int R) {
	if(L+1==R) {
		return {};
	}
	
	int M=(L+R)/2;
	auto Q1=dfs(L,M);
	auto Q2=dfs(M,R);
	vector<pair<ll,ll>> P1,P2;
	int i;
	for(i=L;i<M;i++) P1.push_back({X[i]*q,Y[i]*q});
	for(i=M;i<R;i++) P2.push_back({X[i]*p,Y[i]*p});
	
	auto Q=Minkowski_sum(convex_hull(P1),convex_hull(P2));
	FORR(a,Q1) Q.push_back(a);
	FORR(a,Q2) Q.push_back(a);
	
	
	
	return convex_hull(Q);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	
	cin>>N>>p>>q;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
	}
	auto Q=dfs(0,N);
	Q.push_back(Q[0]);
	ll ret=0;
	FOR(i,Q.size()-1) {
		ret+=Q[i].first*Q[i+1].second-Q[i+1].first*Q[i].second;
	}
	ret=abs(ret);
	ll D=2*(p+q)*(p+q);
	ll g=__gcd(ret,D);
	cout<<ret/g<<" "<<D/g<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
