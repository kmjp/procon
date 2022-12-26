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

int N,M;
ll X[101010],Y[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	set<pair<int,int>> S;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
	}
	
	cin>>M;
	while(M--) {
		cin>>x>>y;
		if(x==0 && y==0) {
			cout<<"NO"<<endl;
			continue;
		}
		
		set<pair<ll,ll>> T;
		if(x==0) y=abs(y);
		if(x<0) x=-x,y=-y;
		FOR(i,N) {
			ll a,b;
			if(x==0) {
				a=X[i];
				b=(Y[i]%y+y)%y;
			}
			else {
				ll step=X[i]/x;
				a=X[i]-step*x;
				b=Y[i]-step*y;
				if(a<0) {
					a+=x;
					b+=y;
				}
			}
			if(T.count(make_pair(a,b))) T.erase(make_pair(a,b));
			else T.insert(make_pair(a,b));
			
		}
		
		if(T.empty()) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
		/*
		if(x==0) {
			set<int> T;
			FOR(i,N) {
				if(T.count(X[i])) T.insert(X[i]);
				else T.erase(X[i]);
			}
			if(T.empty()) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		else {
			set<pair<ll,ll>> T;
			FOR(i,N) {
				ll p=x*Y[i]-y*X[i];
				ll q=x;
				ll g=__gcd(abs(p),abs(q));
				p/=g;
				q/=g;
				if(q<0) p=-p,q=-q;
				cout<<p<<" "<<q<<endl;
				if(T.count(make_pair(p,q))) T.insert(make_pair(p,q));
				else T.erase(make_pair(p,q));
				
			}
			if(T.empty()) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		*/
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
