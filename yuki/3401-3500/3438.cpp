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

int T;
int N;
vector<pair<ll,ll>> P;

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
ll A[202020],B[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		P.resize(N);
		FOR(i,N) {
			cin>>P[i].first>>P[i].second;
			A[i]=B[i]=-1LL<<60;
		}
		
		auto V=convex_hull(P);
		if(V.size()==2) {
			int a=V[0];
			int b=V[1];
			A[a]=P[a].first-P[b].first;
			B[a]=P[a].second-P[b].second;
			A[b]=-A[a];
			B[b]=-B[a];
			
		}
		else {
			V.push_back(V[0]);
			V.push_back(V[1]);
			for(i=1;i<V.size()-1;i++) {
				int p=V[i-1];
				int c=V[i];
				int n=V[i+1];
				B[c]=P[n].first-P[p].first;
				A[c]=-(P[n].second-P[p].second);
			}
		}
		
		FOR(i,N) {
			if(A[i]==-1LL<<60) {
				cout<<"No"<<endl;
			}
			else {
				cout<<A[i]<<" "<<B[i]<<endl;
				/*
				FOR(j,N) cout<<(A[i]*P[j].first+B[i]*P[j].second)<<" ";
				cout<<endl;
				*/
			}
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
