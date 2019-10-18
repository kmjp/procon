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
ll L,R;
ll A[202020];
int mask[62];

ll hoge(ll v,int d,int fix) {
	if(d<0) return 1;
	
	ll ret=0;
	if(mask[d]==0) {
		
		if(v&(1LL<<d)) {
			ret+=1LL<<(d-fix);
			v ^= 1LL<<d;
		}
		ret+=hoge(v,d-1,fix);
	}
	else if(mask[d]==1) {
		fix--;
		if(v&(1LL<<d)) {
			ret+=1LL<<(d-fix);
		}
		else {
			ret+=hoge(v,d-1,fix);
		}
	}
	else if(mask[d]==2) {
		fix--;
		if(v&(1LL<<d)) {
			v ^= 1LL<<d;
			ret+=hoge(v,d-1,fix);
		}
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L>>R;
	FOR(i,N) cin>>A[i];
	FOR(i,N-1) {
		for(j=61;j>=0;j--) {
			if((A[i]&(1LL<<j)) && (A[i+1]&(1LL<<j))==0) {
				mask[j] |= 2;
				break;
			}
			if((A[i]&(1LL<<j))==0 && (A[i+1]&(1LL<<j))) {
				mask[j] |= 1;
				break;
			}
		}
	}
	int fix=0;
	FOR(j,62) {
		if(mask[j]==3) return _P("0\n");
		if(mask[j]) fix++;
	}
	cout<<hoge(R,61,fix)-(L?hoge(L-1,61,fix):0)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
