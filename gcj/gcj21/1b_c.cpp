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

int T,N,B;
ll P;

ll memo[21][21][16][21];
ll p10[16];
int D[20];

ll expected(int t) {
	int T14=0;
	int T13=0;
	int L=0;
	int left=0;
	int i;
	D[t]++;
	FOR(i,N) {
		if(D[i]==14) T14++;
		if(D[i]==13) T13++;
		if(D[i]<13&&D[i]>0) L=D[i];
		if(D[i]==0) left++;
	}
	D[t]--;
	return memo[T14][T13][L][left];
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	ZERO(D);
	
	FOR(i,N*B) {
		cin>>x;
		ll ma=-1;
		int tar=0;
		FOR(j,N) {
			ll cur=-1;
			if(D[j]==14) {
				cur=x*p10[14]+expected(j);
			}
			else if(D[j]==13) {
				cur=x*p10[13]+expected(j);
			}
			else if(D[j]<13&&(j==0||D[j-1]>=13)) {
				cur=x*p10[D[j]]+expected(j);
			}
			if(cur>ma) ma=cur, tar=j+1;
		}
		D[tar-1]++;
		cout<<tar<<endl;
		
	}
	
	
}



ll dfs(int T,int T2,int L,int left) {
	ll& ret=memo[T][T2][L][left];
	if(ret>=0) return ret;
	if(T==0&&T2==0&&L==0&&left==0) return memo[T][T2][L][left]=0;
	ret=0;
	int i;
	FOR(i,10) {
		ll ma=0;
		if(T) ma=max(ma,i*p10[14]+dfs(T-1,T2,L,left));
		if(T2) ma=max(ma,i*p10[13]+dfs(T+1,T2-1,L,left));
		if(L) {
			if(L==12) ma=max(ma,i*p10[L]+dfs(T,T2+1,0,left));
			else ma=max(ma,i*p10[L]+dfs(T,T2,L+1,left));
		}
		if(left&&L==0) ma=max(ma,i+dfs(T,T2,1,left-1));
		ret+=ma;
	}
	ret/=10;
	return ret;
	
}

void init() {
	int i;
	p10[0]=1;
	FOR(i,15) p10[i+1]=p10[i]*10;
	
	MINUS(memo);
	dfs(0,0,0,N);
}

int main(int argc,char** argv){
	int loop,loops;
	long long span;
	char tmpline[1000];
	struct timeval start,end,ts;
	
	if(argc>1) freopen(argv[1], "r", stdin);
	gettimeofday(&ts,NULL);
	cin>>loops>>N>>B>>P;
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


