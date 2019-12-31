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
vector<pair<ll,ll>> V;
ll X[2010],Y[2020];
int did[2020];
template<class C> C veccross(pair<C,C> p1,pair<C,C> p2,pair<C,C> p3) {
	p3.first-=p1.first;p2.first-=p1.first;
	p3.second-=p1.second;p2.second-=p1.second;
	return p3.first*p2.second-p2.first*p3.second;
}

template<class C> vector<int> convex_hull(vector< pair<C, C> >& vp) {
	ll EPS=0;
	vector<pair<pair<C, C>, int> > sorted;
	vector<int> res;
	int i,k=0,rb;
	
	if(vp.size()<=2) {
		if(vp.size()>=1) res.push_back(0);
		if(vp.size()>=2 && vp[0]!=vp[1]) res.push_back(1);
		return res;
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
	return res;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		V.push_back({X[i],Y[i]});
	}
	if(N<=1) return _P("0\n");
	if(N<=2) return _P("1\n");
	if(N<=3) return _P("3\n");
	
	auto C=convex_hull(V);
	x=C.size();
	y=N-C.size();
	int ret=x;
	if(y) ret+=x;
	else ret+=x-3;
	if(y>1) ret+=(y-1)*3;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
