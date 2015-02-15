#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int N,A[30];
int H,W;
int BB[300][300],BB2[300][300];
int L[300],R[300],T[300],B[300];
vector<int> V,MA[18];

int mat[20],late[20];
int dpdp[20][1<<19],ms[1<<18];

void solve() {
	int f,i,j,k,l,x,y,mask,mask2;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	sort(A,A+N);
	
	V.push_back(1);
	for(i=1;i<N;i++) {
		if(A[i]==A[i-1]) V.back()++;
		else V.push_back(1);
	}
	
	FOR(i,N) L[i]=T[i]=301,R[i]=B[i]=-1;
	cin>>H>>W;
	
	FOR(y,H) FOR(x,W) {
		cin>>BB[y][x];
		i=BB[y][x];
		L[i]=min(L[i],x);
		R[i]=max(R[i],x);
		T[i]=min(T[i],y);
		B[i]=max(B[i],y);
	}
	FOR(i,N) for(y=T[i];y<=B[i];y++) for(x=L[i];x<=R[i];x++) if(BB[y][x]!=i) mat[BB[y][x]] |= 1<<i;
	
	FOR(i,N) FOR(x,N) FOR(y,N) mat[x] |= ((mat[x]>>i)&(mat[i]>>y)&1)<<y;
	FOR(i,N) if(mat[i] & (1<<i)) return _P("0\n");
	FOR(mask2,1<<N) FOR(x,N) if(mask2&(1<<x)) ms[mask2]|=mat[x];
	FOR(mask,1<<N) MA[__builtin_popcount(mask)].push_back(mask);
	
	dpdp[0][0]=1;
	FOR(i,V.size()) {
		FOR(mask,1<<N) if(dpdp[i][mask]) {
			FOR(j,MA[V[i]].size()) {
				mask2=MA[V[i]][j];
				if((mask&mask2)==0 && (ms[mask2]&mask)==ms[mask2] && (ms[mask2]&mask2)==0) dpdp[i+1][mask|mask2]=1;
			}
		}
	}
	cout << dpdp[V.size()][(1<<N)-1] << endl;
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


