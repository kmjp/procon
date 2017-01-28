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
int L,R;
ll sum[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	
	
	FOR(i,N) {
		cin>>L>>R;
		
		if(R<=1000) {
			for(j=1;j<=R;j++) {
				if(R/j!=(L-1)/j) sum[j]++, sum[j+1]--;
			}
		}
		else {
			for(j=1;j<=400;j++) {
				if(R/j!=(L-1)/j) sum[j]++, sum[j+1]--;
			}
			int preL=101010;
			for(x=1;x<=400;x++) {
				if(x*401>R) break;
				int TL=(L+(x-1))/x;
				int TR=R/x;
				TL=max(TL,401);
				TR=min(TR,preL-1);
				
				if(TL>TR) continue;
				sum[TL]++;
				sum[TR+1]--;
				preL=TL;
			}
			
		}
	}
	
	ll tot=0;
	for(i=1;i<=M;i++) {
		tot += sum[i];
		cout<<tot<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
