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
int A[606];
vector<double> V[606];
double C[605][605];
double CS[605][605];

vector<double> merge_sort(int L,int R) {
	if(R<L) return vector<double>();
	if(L==R) return V[L];
	int M=(L+R)/2;
	
	auto S=merge_sort(L,M);
	auto T=merge_sort(M+1,R);
	if(S.empty()) return T;
	if(T.empty()) return S;
	int a=S.size(),b=T.size();
	vector<double> U(a+b);
	int x,y;
	FOR(x,a+1) FOR(y,b+1) {
		if(x==a&&y==b) continue;
		if(x==a) {
			double p=1-CS[x+y][a];
			U[x+y]+=p*T[y];
		}
		else if(y==b) {
			double p=1-CS[x+y][b];
			U[x+y]+=p*S[x];
		}
		else {
			double p=C[x+y][x];
			U[x+y]+=p*(S[x]+T[y])*0.5;
		}
	}
	return U;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	C[0][0]=CS[0][1]=1;
	for(x=1;x<=602;x++) {
		FOR(y,602) {
			C[x][y]+=C[x-1][y]*0.5;
			if(y) C[x][y]+=C[x-1][y-1]*0.5;
			CS[x][y+1]=CS[x][y]+C[x][y];
		}
	}
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	
	FOR(i,N) {
		double ret=1;
		FOR(j,N) {
			V[j].clear();
			if(A[i]==A[j]) V[j].push_back(i==j);
			if(A[j]<A[i]) ret+=1.0;
		}
		vector<double> v=merge_sort(0,N-1);
		FOR(j,v.size()) ret+=j*v[j];
		_P("%.12lf\n",ret);
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
