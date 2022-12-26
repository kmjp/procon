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

ll P,Q,R;
ll A,B,C;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>P>>Q>>R;
	cin>>A>>B>>C;
	C+=A+B;
	B+=A;
	
	ll mi=max({(A-1)*P+1,(B-1)*Q+1,(C-1)*R+1,0LL});
	ll ma=min({A*P,B*Q,C*R});
	if(mi>ma) return _P("-1\n");
	if((mi+P-1)/P!=A) return _P("-1\n");
	if((ma+P-1)/P!=A) return _P("-1\n");
	if((mi+Q-1)/Q!=B) return _P("-1\n");
	if((ma+Q-1)/Q!=B) return _P("-1\n");
	if((mi+R-1)/R!=C) return _P("-1\n");
	if((ma+R-1)/R!=C) return _P("-1\n");
	cout<<mi<<" "<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
