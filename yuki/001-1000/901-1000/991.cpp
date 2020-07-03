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

ll X;
ll N;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X;
	if(X==0) {
		cout<<"3 2 129"<<endl;
		cout<<"+ 12 34"<<endl;
		cout<<"10"<<endl;
		cout<<"20"<<endl;
		cout<<"30"<<endl;
		return;
	}
	
	ll K=X+1;
	x=1;
	for(x=1;x<=100000;x++) {
		for(y=max(1,x-2);y<=min(100000,x+2);y++) {
			if(1LL*x*y>X && 1LL*x*y-(x-1)<=X) {
				ll d=x*y-X;
				cout<<y<<" "<<x<<" "<<K<<endl;
				cout<<"*";
				FOR(i,d) {
					if(i==d-1) cout<<" "<<X;
					else cout<<" 1";
					X--;
				}
				FOR(i,x-d) cout<<" "<<K;
				cout<<endl;
				cout<<1<<endl;
				FOR(i,y-1) cout<<K<<endl;
				return;
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
