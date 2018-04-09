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

int N,X,Y;
ll D[101010],V[101010];
vector<ll> nor[101010];
vector<ll> slo[101010];

bool cmp(vector<ll>& L,vector<ll>& R) {
	if(L[0]*R[1]<L[1]*R[0]) return true;
	if(L[0]*R[1]==L[1]*R[0]) return L[2]<R[2];
	return false;
}
bool cmp2(vector<ll>& L,vector<ll> R) {
	if(L[0]*R[1]<L[1]*R[0]) return true;
	if(L[0]*R[1]==L[1]*R[0]) return L[2]<R[2];
	return false;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>Y;
	FOR(i,N) {
		cin>>D[i]>>V[i];
		nor[i]={D[i],V[i],i};
		slo[i]={D[i],V[i]-Y,i};
	}
	sort(nor,nor+N,cmp);
	sort(slo,slo+N,cmp);
	
	FOR(i,N) {
		vector<ll> A={D[i],V[i]+X,(ll)i};
		vector<ll> B={D[i],V[i],(ll)i};
		x=y=0;
		x=lower_bound(nor,nor+N,A,cmp2)-nor;
		y=lower_bound(slo,slo+N,B,cmp2)-slo;
		cout<<min(x,y)+1<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
