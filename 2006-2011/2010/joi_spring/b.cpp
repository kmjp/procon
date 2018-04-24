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

int L,N;
vector<int> XpY[2],XmY[2];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>L>>N;
	FOR(i,N) {
		cin>>x>>y;
		int d=(x+y)%2;
		XpY[d].push_back(x+y);
		XmY[d].push_back(x-y);
	}
	ll ret=0;
	FOR(i,2) {
		sort(ALL(XpY[i]));
		XpY[i].erase(unique(ALL(XpY[i])),XpY[i].end());
		sort(ALL(XmY[i]));
		XmY[i].erase(unique(ALL(XmY[i])),XmY[i].end());
		
		FORR(m,XmY[i]) {
			ret+=L-abs(m);
		}
		FORR(p,XpY[i]) {
			if(p<L) {
				ret+=p+1;
				ret-=lower_bound(ALL(XmY[i]),p+1)-lower_bound(ALL(XmY[i]),-p);
			}
			else {
				ret+=(2*L-1)-p;
				ret-=lower_bound(ALL(XmY[i]),(2*L-2-p)+1)-lower_bound(ALL(XmY[i]),-(2*L-2-p));
			}
		}
	}
	cout<<ret<<endl;
}




int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
