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

int T;
int M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>M;
		
		for(i=1;;i++) {
			int d=0;
			int sum=0;
			x=i;
			while(x) {
				d++;
				sum+=x%10;
				if(x%10==0) {
					d=-1;
					break;
				}
				x/=10;
			}
			if(d<0) continue;
			
			int md=M+sum-d+1;
			ll  r=0;
			FOR(j,M-d) r=(r*10+1)%md;
			FOR(j,d) r=(r*10)%md;
			r=(r+i)%md;
			
			ll p10=1;
			FOR(j,M) {
				if((r+p10)%md==0) {
					string S(M-d,'1');
					S+=to_string(i);
					S[M-1-j]++;
					cout<<S<<endl;
					goto out;
				}
				p10=p10*10%md;
			}
			
		}
		out:
		;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
