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

const ll EPS=0;
template<class C> C veccross(pair<C,C> p1,pair<C,C> p2,pair<C,C> p3) {
	p3.first-=p1.first;p2.first-=p1.first;
	p3.second-=p1.second;p2.second-=p1.second;
	return p3.first*p2.second-p2.first*p3.second;
}

template<class C> vector<int> convex_hull(vector< pair<C, C> >& vp) {
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


int N;
int X[101010],Y[101010],C[101010];
ll mo=1000000007;
vector<pair<ll,ll>> V;
int num[3],num2[3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i]>>C[i];
		V.push_back({X[i],Y[i]});
		num[C[i]]++;
	}
	auto R=convex_hull(V);
	vector<pair<int,int>> cs,cs2;
	FORR(r,R) {
		if(cs.empty()||cs.back().first!=C[r]) cs.push_back({C[r],0});
		cs.back().second++;
		num[C[r]]--;
		num2[C[r]]++;
	}
	
	ll ret=1;
	if(cs.size()>1 && cs[0].first==cs.back().first) {
		cs[0].second+=cs.back().second;
		cs.pop_back();
	}
	
	// all0
	if(num2[1]==0 && num2[2]==0) {
		ret=2*(1+1LL*num2[0]*(num2[0]-1)/2)%mo;
	}
	else if(num2[1]==0 || num2[2]==0) {
		ret=1;
		FORR(c,cs) if(c.first==0) ret=(ret+1LL*c.second*(c.second+1)/2)%mo;
	}
	else {
		vector<int> CC;
		FORR(c,cs) if(c.first) {
			if(CC.empty()||CC.back()!=c.first) CC.push_back(c.first);
		}
		if(CC.size()>3) return _P("0\n");
		FOR(i,cs.size()) if(cs[i].first==0) {
			if(cs[(i+1)%cs.size()].first!=cs[(i+cs.size()-1)%cs.size()].first) ret=ret*(1+cs[i].second)%mo;
		}
	}
	
	
	FOR(i,num[0]) ret=ret*2%mo;
	
	if(num[1]+num2[1]==0) ret+=mo-1;
	if(num[2]+num2[2]==0) ret+=mo-1;
	
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
