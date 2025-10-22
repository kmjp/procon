#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

ll A,B,C,D;

__int128 F(__int128 v) {
	v*=A;
	__int128 ret=v/B;
	v%=B;
	if(v*2>=B) ret++;
	return ret;
	
}
__int128 G(__int128 v) {
	v*=C;
	__int128 ret=v/D;
	v%=D;
	if(v*2>=D) ret++;
	return ret;
	
}

template<class V> V floor_sum(V N,V M,V A,V B) {
	// sum(i=0...N-1) floor((A*i+B)/M)
	if(A<0) return floor_sum(N,M,-A,B+(N-1)*A); //A‚ª•‰‚Ìê‡ŒX‚«‚ð‹t‚É‚·‚é
	
	V ret=0;
	if(B>=M) ret+=N*(B/M), B%=M;
	if(A>=M) ret+=N*(N-1)/2*(A/M), A%=M;
	
	V Y=(A*N+B)/M;
	if(Y==0) return ret;
	//floor(Y/M)‚É’B‚·‚éX
	V X=Y*M-B;
	//X‚Ì‰E‘¤‚ÍYŒÂ‚¸‚Â
	ret+=(N-(X+A-1)/A)*Y;
	// 90“x‰ñ“]AY=N‚Ìƒ‰ƒCƒ“‚Í–³Ž‹‚·‚é
	ret+=floor_sum(Y,A,M,(A-X%A)%A);
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C>>D;
	if(A*D==B*C) {
		cout<<-1<<endl;
		return;
	}
	if(A*D>B*C) {
		swap(A,C);
		swap(B,D);
	}
	__int128 N=0;
	for(i=59;i>=0;i--) {
		__int128 p=C*(N+(1LL<<i))*B-D*(N+(1LL<<i))*A;
		__int128 q=B*D;
		if(p<=q) N+=1LL<<i;
	}
	ll ret=floor_sum<__int128>(N,2*D,2*C,D)-floor_sum<__int128>(N,2*B,2*A,B);
	cout<<(ll)N-ret-1<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
