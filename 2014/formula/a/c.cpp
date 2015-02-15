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

int N,K,L;
int MM[1000010];
int F[1000010];

void solve() {
	int f,i,j,k,l,x,y;
	cin>>N>>K;
	L=K;
	
	
	FOR(i,N) {
		FOR(j,K) cin>>x,MM[j*N+i]=x;
		j=0;
		vector<int> NN;
		
		FOR(y,N*K) {
			if(F[MM[y]]==1) continue;
			if(++j>L) break;
			if(MM[y]>0) {
				NN.push_back(MM[y]);
				F[MM[y]]=1;
			}
		}
		sort(NN.begin(),NN.end());
		FOR(j,NN.size()) {
			_P("%d",NN[j]);
			if(j!=NN.size()-1) _P(" ");
		}
		_P("\n");
		L-=NN.size();
	}
}



int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


