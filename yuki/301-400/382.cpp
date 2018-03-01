#include <bits/stdc++.h>
#include <sys/time.h>
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

ll S;
int N,P;
bitset<128> E[130];
int A[200];

static unsigned long long seed = 88172645463325252ULL;
int xor_rand() {
	seed ^= (seed << 13);
	seed ^= (seed >> 7);
	seed ^= (seed << 17);
	return seed & 0xFFFFFF;
}

ll nex(){ return S=(S*12345)%1000003;}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=nex()%120+2;
	P=nex();
	FOR(i,N) for(j=i+1;j<N;j++) if(nex()>=P) E[i].set(j), E[j].set(i);
	FOR(i,N) A[i]=i;
	
	struct timeval tv1,tv2;
	gettimeofday(&tv1,NULL);
	
	vector<int> R;
	R.push_back(0);
	y=0;
	while(1) {
		gettimeofday(&tv2,NULL);
		if((tv2.tv_sec-tv1.tv_sec)*1000000+(tv2.tv_usec-tv1.tv_usec)>7000000) break;
		seed = tv2.tv_usec;
		FOR(i,5000) {
			y++;
			bitset<128> B;
			vector<int> T;
			FOR(j,N-1) swap(A[j],A[j+xor_rand() % (N-j)]);
			FOR(j,N) if(B.test(A[j])==0) {
				T.push_back(A[j]+1);
				B |= E[A[j]];
			}
			if(R.size()<T.size()) R=T;
		}
	}
	if(R.size()==N) return _P("-1\n");
	_P("%d\n",R.size()+1);
	sort(ALL(R));
	FOR(i,R.size()) _P("%d%c",R[i],(i==R.size()-1)?'\n':' ');
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
