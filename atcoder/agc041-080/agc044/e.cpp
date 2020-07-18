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
ll A[202020];
ll B[202020];
ll C[202020];
double E[202020];

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
		while(k>1 && veccross(vp[res[k-2]],vp[res[k-1]],sorted[i].first)<=0) k--;
		res[k++]=sorted[i].second;
	}
	/* top */
	for(rb=k, i=vp.size()-2;i>=0;i--) {
		while(k>rb && veccross(vp[res[k-2]],vp[res[k-1]],sorted[i].first)<=0) k--;
		res[k++]=sorted[i].second;
	}
	res.resize(k-1);
	return res;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	x=max_element(A,A+N)-A;
	rotate(A,A+x,A+N);
	rotate(B,B+x,B+N);
	A[N]=A[0];
	B[N]=B[0];
	for(i=1;i<N;i++) C[i+1]=2*C[i]+2*B[i]-C[i-1];
	
	vector<pair<ll,ll>> V;
	FOR(i,N+1) V.push_back({i,A[i]-C[i]});
	auto W=convex_hull(V);
	
	double ret=0;
	FOR(i,W.size()) {
		int L=W[i],R=W[i+1];
		//cout<<L<<":"<<V[L].second<<"  "<<R<<":"<<V[R].second<<endl;
		for(x=L;x<R;x++) {
			//cout<<x<<" "<<(1.0*(V[L].second*(R-x)+V[R].second*(x-L))/(R-L))<<" "<<C[x]<<endl;
			ret+=1.0*(V[L].second*(R-x)+V[R].second*(x-L))/(R-L)+C[x];
		}
		if(R==N) break;
	}
	
	
	_P("%.12lf\n",ret/N);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
