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
ll X[202020],Y[202020];
int Q;
ll A[202020],B[202020];
int ret[202020];

template<class C> C veccross(pair<C,C> p1,pair<C,C> p2,pair<C,C> p3) {
	p3.first-=p1.first;p2.first-=p1.first;
	p3.second-=p1.second;p2.second-=p1.second;
	return p3.first*p2.second-p2.first*p3.second;
}

template<class C> pair<vector<int>,vector<int>> convex_hull(vector< pair<C, C> >& vp) {
	vector<pair<pair<C, C>, int> > sorted;
	vector<int> A,B;
	int i,k=0,rb;
	
	
	FOR(i,vp.size()) sorted.push_back(make_pair(vp[i],i));
	sort(sorted.begin(),sorted.end());
	
	A.resize(vp.size()*2);
	B.resize(vp.size()*2);
	/* bottom */
	FOR(i,vp.size()) {
		while(k>1 && veccross(vp[A[k-2]],vp[A[k-1]],sorted[i].first)<=0) k--;
		A[k++]=sorted[i].second;
	}
	A.resize(k);
	k=0;
	/* top */
	for(i=vp.size()-1;i>=0;i--) {
		while(k>1 && veccross(vp[B[k-2]],vp[B[k-1]],sorted[i].first)<=0) k--;
		B[k++]=sorted[i].second;
	}
	B.resize(k);
	reverse(ALL(B));
	return {A,B};
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<pair<ll,ll>> P,V,W;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		P.push_back({X[i],Y[i]});
	}
	auto a=convex_hull(P);
	FORR(v,a.first) V.push_back({X[v],Y[v]});
	FORR(v,a.second) W.push_back({X[v],Y[v]});
	
	if(V[0].first==V[1].first) V.erase(V.begin());
	if(V[V.size()-2].first==V[V.size()-1].first) V.erase(V.begin()+V.size()-1);
	if(W[0].first==W[1].first) W.erase(W.begin());
	if(W[W.size()-2].first==W[W.size()-1].first) W.erase(W.begin()+W.size()-1);
	/*
	FORR2(x,y,V) cout<<x<<","<<y<<" ";
	cout<<endl;
	FORR2(x,y,W) cout<<x<<","<<y<<" ";
	cout<<endl;
	*/
	cin>>Q;
	FOR(i,Q) {
		ll X,Y;
		cin>>X>>Y;
		
		if(X<V[0].first||X>V.back().first) {
			cout<<"OUT"<<endl;
			continue;
		}
		
		if(X==V[0].first) {
			if(Y>V[0].second||Y<W[0].second) {
				cout<<"OUT"<<endl;
			}
			else {
				cout<<"ON"<<endl;
			}
			continue;
		}
		if(X==V.back().first) {
			if(Y>V.back().second||Y<W.back().second) {
				cout<<"OUT"<<endl;
			}
			else {
				cout<<"ON"<<endl;
			}
			continue;
		}
		
		int a=lower_bound(ALL(V),make_pair(X+1,-1LL<<60))-V.begin();
		int b=lower_bound(ALL(W),make_pair(X+1,-1LL<<60))-W.begin();
		
		long double y1=V[a-1].second+(long double)1.0*(V[a].second-V[a-1].second)*(X-V[a-1].first)/(V[a].first-V[a-1].first);
		long double y2=W[b-1].second+(long double)1.0*(W[b].second-W[b-1].second)*(X-W[b-1].first)/(W[b].first-W[b-1].first);
		if(abs(y1-Y)<1e-10||abs(y2-Y)<1e-10) {
			cout<<"ON"<<endl;
		}
		else if(Y<=y1&&Y>=y2) {
			cout<<"IN"<<endl;
		}
		else {
			cout<<"OUT"<<endl;
		}
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
