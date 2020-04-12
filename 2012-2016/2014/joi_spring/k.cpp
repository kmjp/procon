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
ll X[3030],Y[3030];
int C[3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	double pi=atan(1)*4;
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i]>>C[i];
	}
	
	ll ret=0;
	FOR(i,N) {
		int L[3]={},R[3]={};
		vector<pair<double,int>> V;
		FOR(j,N) if(j!=i) {
			double d=atan2(Y[j]-Y[i],X[j]-X[i]);
			if(d>=0) {
				L[C[j]]++;
				V.push_back({d,j*10+C[j]});
				V.push_back({d+pi,j*10+3+C[j]});
			}
			else {
				R[C[j]]++;
				V.push_back({d+pi,j*10+3+C[j]});
				V.push_back({d+2*pi,j*10+C[j]});
			}
		}
		sort(ALL(V));
		FORR(v,V) {
			x=v.second%10;
			if(x>=3) {
				R[x-3]--;
				L[x-3]++;
			}
			else {
				L[x]--;
				ll a=0,b=0;
				a=L[(C[i]+1)%3]*L[(C[i]+2)%3];
				b=R[(x+1)%3]*R[(x+2)%3];
				//if(a&&b) cout<<i<<" "<<v.second/10<<" "<<a<<" "<<b<<endl;
				ret+=a*b;
				R[x]++;
			}
		}
	}
	cout<<ret/2<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
