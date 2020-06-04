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
ll A[202020],B[202020];

int up(int a,int b,int c) {
	ll x1=b-a;
	ll y1=B[b]-B[a];
	ll x2=c-a;
	ll y2=B[c]-B[a];
	return y2*x1-x2*y1<=0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	deque<int> D;
	D.push_back(0);
	ll ret=-1LL<<40;
	for(i=1;i<N;i++) {
		while(D.size()>=2 && up(D[D.size()-2],D[D.size()-1],i)) D.pop_back();
		
		int L=0,R=D.size();
		while(R-L>=3) {
			int M1=(2*L+R)/3;
			int M2=(2*R+L)/3;
			
			ll Y1=B[D[M1]];
			ll Y2=B[D[M2]];
			
			if((A[i]-Y1)*(i-D[M2])<(A[i]-Y2)*(i-D[M1])) {
				L=M1;
			}
			else if((A[i]-Y1)*(i-D[M2])>(A[i]-Y2)*(i-D[M1])) {
				R=M2;
			}
			else {
				L=M1,R=M2;
			}
		}
		D.push_back(i);
		
		/*
		FORR(d,D) cout<<d<<":"<<B[d]<<" ";
		cout<<endl;
		*/
		for(j=L;j<R;j++) {
			x=D[j];
			ll y=B[x];
			//cout<<x<<" "<<y<<" "<<A[i]-y<<endl;
			if(A[i]-y>=0) {
				ret=max(ret,(A[i]-y)/(i-x)+((A[i]-y)%(i-x)!=0));
			}
			else {
				ret=max(ret,(A[i]-y)/(i-x));
			}
		}
		cout<<ret<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
