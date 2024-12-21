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
ll X[202020],H[202020];

const ll EPS=0;
template<class C> C veccross(pair<C,C> p1,pair<C,C> p2,pair<C,C> p3) {
	p3.first-=p1.first;p2.first-=p1.first;
	p3.second-=p1.second;p2.second-=p1.second;
	return p3.first*p2.second-p2.first*p3.second;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	double ret=-1;
	ll tp=-1;
	ll tq=1;
	
	vector<pair<ll,ll>> V;
	FOR(i,N) {
		cin>>X[i]>>H[i];
		pair<ll,ll> P={X[i],H[i]};
		while(V.size()>1 && veccross(V[V.size()-2],V[V.size()-1],P)<=-EPS) V.pop_back();
		
		if(V.size()>=1) {
			//double a=H[i]-(H[i]-V.back().second)/(double)(X[i]-V.back().first)*X[i];
			ll p=H[i]*(X[i]-V.back().first)-(H[i]-V.back().second)*X[i];
			ll q=(X[i]-V.back().first);
			
			ll g=__gcd(abs(p),q);
			p/=g;
			q/=g;
			
			if(p>=0) {
				if(__int128(p)*tq>__int128(tp)*q) {
					tp=p;
					tq=q;
				}
				
			}
		}
		V.push_back(P);
		
	}
	
	
	
	
	if(tp<0) {
		cout<<-1<<endl;
	}
	else {
		_P("%.12lf\n",(double)tp/(double)tq);
	}
	
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
