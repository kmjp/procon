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
double A[202020],B[202020],C[202020];

const double EPS=1e-20;
template<class C> C veccross(pair<C,C> p1,pair<C,C> p2,pair<C,C> p3) {
	p3.first-=p1.first;p2.first-=p1.first;
	p3.second-=p1.second;p2.second-=p1.second;
	return p3.first*p2.second-p2.first*p3.second;
}

template<class C> vector<int> convex_hull_bottom(vector< pair<C, C> >& vp) {
	vector<pair<pair<C, C>, int> > sorted;
	vector<int> res;
	int i,k=0,rb;
	
	FOR(i,vp.size()) sorted.push_back(make_pair(vp[i],i));
	sort(sorted.begin(),sorted.end());
	
	res.resize(vp.size()*2);
	/* bottom */
	FOR(i,vp.size()) {
		while(k>1 && veccross(vp[res[k-2]],vp[res[k-1]],sorted[i].first)>=EPS) k--;
		res[k++]=sorted[i].second;
	}
	res.resize(k);
	return res;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<pair<double,double>> V,W;
	double ret=1e20;
	FOR(i,N) {
		cin>>A[i]>>B[i]>>C[i];
		ret=min(ret,max(A[i],B[i])/C[i]);
		V.push_back({A[i]/C[i],B[i]/C[i]});
	}
	
	auto A=convex_hull_bottom(V);
	N=A.size();
	FOR(i,N) W.push_back(V[A[i]]);
	V=W;
	FOR(i,N-1) {
		if(V[i].second>V[i].first&&V[i+1].first>V[i+1].second) {
			double dx=V[i+1].first-V[i].first;
			double dy=V[i+1].second-V[i].second;
			double a=0,b=1;
			FOR(j,100) {
				double m=(a+b)/2;
				double nx=V[i].first+dx*m;
				double ny=V[i].second+dy*m;
				if(ny>nx) a=m;
				else b=m;
			}
			ret=min(ret,V[i].first+dx*a);
		}
	}
	
	
	_P("%.12lf\n",1/ret);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
