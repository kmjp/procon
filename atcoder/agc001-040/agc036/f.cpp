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

int NG[501],OK[501];
int N;
ll mo;
vector<vector<int>> V;

ll from[505],to[505];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>mo;
	MINUS(NG);
	MINUS(OK);
	
	FOR(i,2*N) {
		FOR(j,2*N) {
			if(i*i+j*j<=4*N*N) {
				if(i*i+j*j>=N*N) OK[i]=j;
				else NG[i]=j;
			}
		}
		OK[i]++;
		NG[i]++;
		if(NG[i]>0) V.push_back({NG[i],OK[i],i});
		else V.push_back({OK[i],0,i});
	}
	sort(ALL(V));
	
	ll ret=0;
	FOR(i,N+1) {
		ZERO(from);
		from[0]=1;
		int num=0;
		FOR(j,2*N) {
			x=V[j][2];
			ZERO(to);
			
			FOR(y,i+1) if(from[y]) {
				
				int ok=num-y;
				if(NG[x]==0) {
					(to[y]+=from[y]*max(0,V[j][0]-(j-ok)))%=mo;
				}
				else {
					// ok
					(to[y]+=from[y]*(OK[x]-N-i-ok))%=mo;
					// ng
					(to[y+1]+=from[y]*max(0,V[j][0]-(j-ok)))%=mo;
				}
			}
			
			
			swap(from,to);
			if(NG[x]) num++;
		}
		
		if(i%2) ret+=mo-from[i];
		else ret+=from[i];
	}
	
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
