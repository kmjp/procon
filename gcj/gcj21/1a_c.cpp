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

int N,Q;
string A[3];
int S[3];

__int128 C_[125][125];
__int128 comb(int P_,int Q_) {
	if(P_<0 || P_>120 || Q_<0 || Q_>P_) return 0;
	return C_[P_][Q_];
}


ostream& operator<<(ostream& os, __int128 v) {
	if(v==0) {
		return (os<<'0');
	}
	if(v<0) {
		os<<'-';
		v=-v;
	}
	
	string T;
	while(v) {
		T+=(char)('0'+(v%10));
		v/=10;
	}
	reverse(ALL(T));
	return (os<<T);
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>A[i]>>S[i];
	}
	
	string T;
	__int128 X=1,Y=1;
	
	if(N==1) {
		T=A[0];
		X=S[0];
		if(S[0]*2<Q) {
			X=Q-S[0];
			FORR(c,T) {
				if(c=='F') c='T';
				else c='F';
			}
		}
	}
	else if(N==2) {
		if(S[0]>S[1]) {
			T=A[0];
		}
		else {
			T=A[1];
		}
		int same=0;
		
		FOR(i,Q) if(A[0][i]==A[1][i]) same++;
		int dif=Q-same;
		int sameac=(S[0]+S[1]-dif)/2;
		X=(max(S[0],S[1])-sameac);
		if(sameac*2<same) {
			sameac=same-sameac;
			FOR(i,Q) if(A[0][i]==A[1][i]) {
				if(T[i]=='F') T[i]='T';
				else T[i]='F';
			}
		}
		
		Y=1;
		X+=sameac;
	}
	else {
		int AB=0,AC=0,BC=0,ABC=0;
		FOR(i,Q) {
			if(A[0][i]==A[1][i]&&A[0][i]==A[2][i]) ABC++;
			else if(A[0][i]==A[1][i]) AB++;
			else if(A[0][i]==A[2][i]) AC++;
			else BC++;
		}
		__int128 pat[16]={};
		int w,x,y,z;
		Y=0;
		for(x=0;x<=AB;x++) for(y=0;y<=AC;y++) for(z=0;z<=BC;z++) {
			int AA=x+y+(BC-z);
			int BB=x+(AC-y)+z;
			int CC=(AB-x)+y+z;
			int w=S[0]-AA;
			if(S[1]-BB!=w) continue;
			if(S[2]-CC!=w) continue;
			if(w<0||w>ABC) continue;
			__int128 p=comb(ABC,w)*comb(AB,x)*comb(AC,y)*comb(BC,z);
			Y+=p;
			int mask;
			FOR(mask,16) {
				int sc=0;
				sc+=(mask&1)?(ABC-w):w;
				sc+=(mask&2)?(AB-x):x;
				sc+=(mask&4)?(AC-y):y;
				sc+=(mask&8)?(BC-z):z;
				pat[mask]+=sc*p;
			}
		}
		int ma=max_element(pat,pat+16)-pat;
		X=pat[ma];
		FOR(i,Q) {
			if(A[0][i]==A[1][i]&&A[0][i]==A[2][i]) {
				if(ma&1) T+=(char)('T'+'F'-A[0][i]);
				else T+=A[0][i];
			}
			else if(A[0][i]==A[1][i]) {
				if(ma&2) T+=A[2][i];
				else T+=A[0][i];
			}
			else if(A[0][i]==A[2][i]) {
				if(ma&4) T+=A[1][i];
				else T+=A[0][i];
			}
			else {
				if(ma&8) T+=A[0][i];
				else T+=A[1][i];
			}
		}
		
	}
	
	__int128 G=__gcd(X,Y);
	X/=G;
	Y/=G;
	cout<<"Case #"<<_loop<<": "<<T<<" "<<X<<"/"<<Y<<endl;
}

void init() {
	int i,j;
	FOR(i,121) C_[i][0]=C_[i][i]=1;
	for(i=1;i<121;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j]);
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


