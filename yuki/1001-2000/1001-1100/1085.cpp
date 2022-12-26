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

string T;
int D;

ll from[10],to[10];
const ll mo=1000000007;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int sum=0,num=0;
	cin>>T>>D;
	
	from[0]=1;
	
	FORR(c,T) {
		ZERO(to);
		FOR(i,10) if(c=='?' || c=='0'+i) {
			if(i==0) {
				FOR(j,10) (to[j]+=from[j])%=mo;
			}
			else {
				FOR(j,10) {
					x=i+j;
					if(x>9) x-=9;
					(to[x]+=from[j])%=mo;
				}
			}
		}
		swap(from,to);
	}
	cout<<from[D]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
