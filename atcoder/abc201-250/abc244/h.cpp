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

int Q;
ll X[202020],Y[202020],A[202020],B[202020];

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

template<class V,int NV> class SegTree_1 {
public:
	vector<vector<pair<V,V>>> val;
	
	SegTree_1(){val.resize(NV*2);};
	V getval(int x,int y,ll A,ll B,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l || val[k].empty()) return -1LL<<62;
		if(x<=l && r<=y) {
			ll ma=-1LL<<62;
			if(val[k].size()<=10) {
				FORR2(X,Y,val[k]) ma=max(ma,X*A+Y*B);
			}
			else {
				vector<pair<int,int>> cand={{0,val[k].size()/2},{val[k].size()/2,val[k].size()-1}};
				FORR2(L,R,cand) {
					ma=max(ma,A*val[k][L].first+B*val[k][L].second);
					ma=max(ma,A*val[k][R].first+B*val[k][R].second);
					while(R-L>=6) {
						int M1=(L*2+R)/3;
						int M2=(L+R*2)/3;
						ll V1=A*val[k][M1].first+B*val[k][M1].second;
						ll V2=A*val[k][M2].first+B*val[k][M2].second;
						ma=max({ma,V1,V2});
						if(V1<=V2) L=M1;
						if(V1>=V2) R=M2;
						
					}
					while(L<=R) {
						ma=max(ma,A*val[k][L].first+B*val[k][L].second);
						L++;
					}
				}
				
			}
			return ma;
		}
		return max(getval(x,y,A,B,l,(l+r)/2,k*2),getval(x,y,A,B,(l+r)/2,r,k*2+1));
	}
	void build() {
		int i,j;
		for(i=NV-1;i>=1;i--) {
			vector<pair<ll,ll>> W;
			FORR(v,val[i*2]) W.push_back(v);
			FORR(v,val[i*2+1]) W.push_back(v);
			if(W.size()) {
				auto a=convex_hull(W);
				FORR(b,a) val[i].push_back(W[b]);
			}
		}
	}
};

SegTree_1<ll,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	FOR(i,Q) {
		cin>>X[i]>>Y[i]>>A[i]>>B[i];
		st.val[(1<<20)+i]={{X[i],Y[i]}};
	}
	st.build();
	FOR(i,Q) cout<<st.getval(0,i+1,A[i],B[i])<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
