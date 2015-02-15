#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sys/time.h>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

class Trie {
public:
	vector<vector<int> > V;
	int find(string s) {
		int cur=0;
		ITR(it,s) if((cur=V[cur][*it])==0) return -1;
		return cur;
	}
	void create(vector<string> S) {
		V.clear();
		V.push_back(vector<int>(256));
		sort(S.begin(),S.end());
		ITR(it,S) {
			int cur=0;
			ITR(c,(*it)) {
				if(V[cur][*c]==0) V.push_back(vector<int>(256)),V[cur][*c]=V.size()-1;
				cur=V[cur][*c];
			}
		}
	}
};

int M,N;
ll mo=1000000007;
const int CN=1001;
ll C[CN][CN];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	vector<string> S;
	string s;
	
	FOR(x,CN) C[x][0]=C[x][x]=1;
	for(i=1;i<CN;i++) for(j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	
	cin>>M>>N;
	FOR(i,M) cin>>s, S.push_back(s);
	sort(S.begin(),S.end());
	
	Trie tr;
	tr.create(S);
	vector<int> NN=vector<int>(tr.V.size(),0);
	vector<int> str=vector<int>(tr.V.size(),0);
	
	FOR(i,S.size()) str[tr.find(S[i])]++;
	
	ll ret=1;
	int pat=0;
	for(i=tr.V.size()-1;i>=0;i--) {
		vector<int> cand;
		if(str[i]) NN[i]++,cand.push_back(1);
		for(j='A';j<='Z';j++) if(tr.V[i][j]>0) NN[i]+=NN[tr.V[i][j]], cand.push_back(NN[tr.V[i][j]]);
		NN[i]=min(N,NN[i]);
		pat += NN[i];
		
		ll dpdp[101][101];
		ZERO(dpdp);
		dpdp[0][NN[i]]=1;
		FOR(j,cand.size()) {
			FOR(x,NN[i]+1) FOR(y,min(cand[j],x)+1) {
				dpdp[j+1][x-y] += dpdp[j][x]*C[N-x][cand[j]-y]%mo*C[x][y];
				dpdp[j+1][x-y] %= mo;
			}
		}
		ret=ret*dpdp[cand.size()][0]%mo;
	}
	
	_P("Case #%d: %d %lld\n",_loop,pat,ret);
}

void init() {
}

int main(int argc,char** argv){
	int loop,loops;
	long long span;
	char tmpline[1000];
	struct timeval start,end,ts;
	
	if(argc>1) freopen(argv[1], "r", stdin);
	gettimeofday(&ts,NULL);
	cin>>loops;
	init();
	
	for(loop=1;loop<=loops;loop++) {
		gettimeofday(&start,NULL); solve(loop); gettimeofday(&end,NULL);
		span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
		fprintf(stderr,"Case : %d                                     time: %lld ms\n",loop,span/1000);
	}
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	fprintf(stderr,"**Total time: %lld ms\n",span/1000);
	
	return 0;
}


