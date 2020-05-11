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

int Q;
ll K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>K;
		int ma=-1;
		vector<int> R;
		FOR(j,63) if(K&(1LL<<j)) ma=j;
		
		K^=1LL<<ma;
		FOR(j,ma) R.push_back(1+j*2);
		
		int added=0;
		for(j=63;j>=0;j--) if(K&(1LL<<j)) {
			if(j&&(K&(1LL<<(j-1)))&&added>=2) {
				K^=(1LL<<j);
				K^=(1LL<<(j-1));
				x=R.back();
				R.pop_back();
				y=R.back();
				R.pop_back();
				R.push_back((j-1)*2);
				R.push_back(y);
				R.push_back(x);
			}
			else {
				K^=(1LL<<j);
				R.push_back(j*2);
			}
			added++;
		}
		
		cout<<R.size();
		FORR(r,R) cout<<" "<<r;
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
