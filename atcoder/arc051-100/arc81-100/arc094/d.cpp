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
ll A,B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>A>>B;
		if(A>B) swap(A,B);
		ll ret=2*(A-1);
		
		int num=0;
		for(i=29;i>=0;i--) {
			num+=1<<i;
			if(A+num>B) {
				num-=1<<i;
				continue;
			}
			int ng=0;
			for(x=num/2-2;x<=num/2+2;x++) {
				if(x<=0 || x>num) continue;
				if((A+x)*(A+num-x)>=A*B) ng=1;
			}
			if(ng) num-=1<<i;
		}
		ret+=num;
		
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
