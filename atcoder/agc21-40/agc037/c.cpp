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
ll A[202020],B[202020],D[202020];

int le(int v) {
	v--;
	if(v<0) v+=N;
	return v;
}
int ri(int v) {
	v++;
	if(v>=N) v-=N;
	return v;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	
	ll num=0;
	queue<int> Q;
	FOR(i,N) if(B[i]>B[le(i)]+B[ri(i)] && B[i]>A[i]) Q.push(i);
	while(Q.size()) {
		i=Q.front();
		Q.pop();
		
		//cout<<num<<" "<<i<<" "<<B[0]<<" "<<B[1]<<" "<<B[2]<<endl;
		
		ll L=B[le(i)];
		ll R=B[ri(i)];
		ll S=L+R;
		
		if(B[i]<=S) continue;
		if(B[i]<A[i]) return _P("-1\n");
		if(B[i]<=A[i]) continue;
		
		if(A[i]>S) {
			if((B[i]-A[i])%S) return _P("-1\n");
			num+=(B[i]-A[i])/S;
			B[i]=A[i];
		}
		else {
			ll v=B[i]/S;
			if(B[i]%S) {
				num+=v;
				B[i]%=S;
			}
			else {
				num+=v-1;
				B[i]=S;
			}
		}
		x=le(i);
		if(B[x]>B[le(x)]+B[ri(x)] && B[x]>A[x]) Q.push(x);
		x=ri(i);
		if(B[x]>B[le(x)]+B[ri(x)] && B[x]>A[x]) Q.push(x);
	}
	
	FOR(i,N) if(A[i]!=B[i]) return _P("-1\n");
	cout<<num<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
