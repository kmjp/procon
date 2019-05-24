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

ll N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll ret=0;
	
	if(N==1) return _P("0\n");
	if(N==2) return _P("4\n");
	if(N==3) return _P("11\n");
	
	int L=1,R=N;
	ret+=R+R-1;
	L=2;
	int cur=R;
	while(L+3<=R) {
		if(cur==R) {
			ret+=1LL*R*L+1LL*(R-1)*(L+1);
			cur=L;
			R-=2;
		}
		else {
			ret+=1LL*R*L+1LL*(R-1)*(L+1);
			cur=R;
			L+=2;
		}
	}
	if(L+1==R) ret+=1LL*L*R;
	if(L+2==R) {
		if(cur==L) {
			ret+=1LL*(L+L+1)*R;
		}
		else {
			ret+=1LL*L*(R+R-1);
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
