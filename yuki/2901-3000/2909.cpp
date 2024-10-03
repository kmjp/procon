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

int N,M,K;

ll X[101010],Y[101010];
ll A[101010],B[101010];
struct node {
	pair<ll,ll> P;
	int left,right;
	int axis;
	int num;
	ll L,R,U,D;
};

struct KDTree_2D {
	vector<node> nodes;
	static ll dist(pair<ll,ll> a, pair<ll,ll> b) {
		a.first -= b.first;
		a.second -= b.second;
		return a.first*a.first+a.second*a.second;
	}
	static ll possible(ll x,ll y,ll L,ll R,ll U,ll D) {
		ll dx=(x<L)?L-x:((x<R)?0:x-R);
		ll dy=(y<U)?U-y:((y<D)?0:y-D);
		return dx*dx+dy*dy;
	}
	int build(vector<pair<ll,ll>>& vs) {
		if(vs.empty()) return -1;
		nodes.push_back({});
		int cur=nodes.size()-1;
		node n;
		n.L=n.U=1LL<<60;
		n.R=n.D=-1LL<<60;
		n.num=vs.size();
		FORR2(a,b,vs) {
			n.L=min(n.L,a);
			n.R=max(n.R,a);
			n.U=min(n.U,b);
			n.D=max(n.D,b);
		}
		int axis = n.axis = (n.R-n.L)<=(n.D-n.U);
		if(axis) FORR2(a,b,vs) swap(a,b);
		sort(ALL(vs));
		if(axis) FORR2(a,b,vs) swap(a,b);
		int mid=vs.size()/2;
		n.P=vs[mid];
		int i;
		vector<pair<ll,ll>> VL,VR;
		FOR(i,mid) VL.push_back(vs[i]);
		for(i=mid+1;i<vs.size();i++) VR.push_back(vs[i]);
		
		n.left = build(VL);
		n.right = build(VR);
		nodes[cur]=n;
		return cur;
	}
	
	pair<ll,ll> search(pair<ll,ll> p,int cur=0) {
		if(cur==-1||cur>=nodes.size()) return {-1LL<<30,-1LL<<30};
		}
		node& n=nodes[cur];
		auto dp=n.P;
		ll d=dist(dp,p);

		int fi,se;
		if((n.axis==0&&p.first<n.P.first)||(n.axis==1&&p.second<n.P.second)) {
			fi=n.left;
			se=n.right;
		}
		else {
			se=n.left;
			fi=n.right;
		}
		
		auto v1=search(p,fi);
		if(chmin(d,dist(v1,p))) dp=v1;
		
		if(se!=-1&&possible(p.first,p.second,nodes[se].L,nodes[se].R,nodes[se].U,nodes[se].D)<d) {
			auto v1=search(p,se);
			if(chmin(d,dist(v1,p))) dp=v1;
		}
		return dp;
		
	}
};



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	cin>>A[0]>>B[0];
	
	vector<pair<ll,ll>> V;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		V.push_back({X[i],Y[i]});
	}
	
	KDTree_2D kd;
	kd.build(V);
	
	double ret=0;
	pair<ll,ll> p=kd.search({A[0],B[0]});
	
	FOR(i,K) {
		cin>>A[i+1]>>B[i+1];
		pair<ll,ll> q=kd.search({A[i+1],B[i+1]});
		double a=2*hypot(A[0]-A[i+1],B[0]-B[i+1]);
		double b=2*(hypot(A[0]-p.first,B[0]-p.second)+hypot(A[i+1]-q.first,B[i+1]-q.second));
		ret+=min(a,b);
	}
	_P("%.12lf\n",ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
