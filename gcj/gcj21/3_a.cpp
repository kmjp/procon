#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


int N;
string D;

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>D;
	N=D.size();
	sort(ALL(D));
	ll ret=1LL<<60;
	
	if(N%2) {
		if(D[0]=='0') {
			FOR(i,N) {
				if(D[i]!='0') {
					swap(D[0],D[i]);
					break;
				}
			}
		}
		reverse(D.begin()+(N+1)/2,D.end());
		ll a=0,b=0;
		FOR(i,N) {
			if(i<=N/2) {
				a=a*10+D[i]-'0';
			}
			else {
				b=b*10+D[i]-'0';
			}
		}
		ret=abs(a-b);
	}
	else {
		int C[10]={};
		FORR(d,D) C[d-'0']++;
		
		FOR(i,10) if(C[i]%2) break;
		if(i==10) ret=0;
		
		FOR(y,10) if(C[y]) {
			C[y]--;
			FOR(x,y) if(C[x]) {
				C[x]--;
				int E[10]={};
				int ok=0;
				for(i=1;i<=8;i++) {
					E[i]=C[i]%2;
					if(C[i]>=2) ok=1;
				}
				
				for(E[0]=C[0]%2;E[0]<=C[0];E[0]+=2) {
					for(E[9]=C[9]%2;E[9]<=C[9];E[9]+=2) {
						if(ok==0&&E[9]==C[9]&&C[0]!=E[0]) continue;
						if(ok==0&&E[9]==C[9]&&x==0) continue;
						vector<int> V;
						FOR(i,10) FOR(j,E[i]) V.push_back(i);
						i=V.size();
						reverse(V.begin()+i/2,V.end());
						ll a=y,b=x;
						FOR(i,V.size()) {
							if(i<V.size()/2) {
								a=a*10+V[i];
							}
							else {
								b=b*10+V[i];
							}
						}
						ret=min(ret,abs(a-b));
					}
				}
				C[x]++;
			}
			C[y]++;
		}
		
	}
	
	
	_P("Case #%d: %lld\n",_loop,ret);
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


