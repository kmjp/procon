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

int T,N,Q;

int ask(int i,int j,int k) {
	cout<<i<<" "<<j<<" "<<k<<endl;
	cin>>i;
	return i;
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	vector<int> V;
	x=ask(1,2,3);
	if(x==1) V={2,1,3};
	else if(x==2) V={1,2,3};
	else if(x==3) V={1,3,2};
	
	for(i=4;i<=N;i++) {
		int L=-1;
		int R=V.size();
		while(R-L>1) {
			if(R-L==2) {
				int M=(R+L)/2;
				if(L!=-1) {
					x=ask(V[L],V[M],i);
					assert(x!=V[L]);
					if(x==i) {
						R=M;
					}
					else {
						L=M;
					}
				}
				else {
					x=ask(V[M],V[R],i);
					assert(x!=V[R]);
					if(x==i) {
						L=M;
					}
					else {
						R=M;
					}
				}
			}
			else {
				int M1=(R+L*2)/3;
				int M2=(R*2+L)/3;
				x=ask(V[M1],V[M2],i);
				if(x==V[M1]) {
					R=M1;
				}
				else if(x==V[M2]) {
					L=M2;
				}
				else {
					L=M1,R=M2;
				}
			}
		}
		V.insert(V.begin()+L+1,i);
	}
	
	
	FOR(i,N) {
		cout<<V[i];
		if(i!=N-1) cout<<" ";
	}
	cout<<endl;
	cin>>x;
	assert(x==1);
	
}

void init() {
	cin>>N>>Q;
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


