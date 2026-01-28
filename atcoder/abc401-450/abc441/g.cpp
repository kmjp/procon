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

int N,Q;
const int DI=500;

int flip[252525];
ll val[252525];
ll add[DI],ma[DI];
ll F[DI];
int NF[DI];

void prop(int id) {
	int i;
	ma[id]=0;
	if(F[id]) {
		for(i=id*DI;i<(id+1)*DI;i++) {
			val[i]=0;
			flip[i]^=F[id]%2;
		}
	}
	NF[id]=0;
	for(i=id*DI;i<(id+1)*DI;i++) {
		if(flip[i]==0) {
			val[i]+=add[id];
			ma[id]=max(ma[id],val[i]);
			NF[id]++;
		}
	}
	F[id]=add[id]=0;
	
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,DI) prop(i);
	
	cin>>N>>Q;
	while(Q--) {
		int T,L,R,X;
		cin>>T>>L>>R;
		L--;
		if(T==1) {
			cin>>X;
			if(L/DI==R/DI) {
				prop(L/DI);
				for(i=L;i<R;i++) {
					if(flip[i]==0) val[i]+=X;
				}
				prop(L/DI);
			}
			else {
				if(L%DI) {
					prop(L/DI);
					while(L%DI) {
						if(flip[L]==0) val[L]+=X;
						L++;
					}
					prop(L/DI-1);
				}
				if(R%DI) {
					prop(R/DI);
					while(R%DI) {
						R--;
						if(flip[R]==0) val[R]+=X;
					}
					prop(R/DI);
				}
				for(i=L/DI;i<R/DI;i++) {
					add[i]+=X;
					if(NF[i]) ma[i]+=X;
				}
				
			}
		}
		else if(T==2) {
			if(L/DI==R/DI) {
				prop(L/DI);
				for(i=L;i<R;i++) {
					flip[i]^=1;
					val[i]=0;
				}
				prop(L/DI);
			}
			else {
				if(L%DI) {
					prop(L/DI);
					while(L%DI) {
						flip[L]^=1;
						val[L]=0;
						L++;
					}
					prop(L/DI-1);
				}
				if(R%DI) {
					prop(R/DI);
					while(R%DI) {
						R--;
						flip[R]^=1;
						val[R]=0;
					}
					prop(R/DI);
				}
				for(i=L/DI;i<R/DI;i++) {
					F[i]++;
					add[i]=0;
					ma[i]=0;
					NF[i]=DI-NF[i];
				}
				
			}
		}
		else {
			ll ret=0;
			prop(L/DI);
			while(L%DI&&L<R) {
				if(flip[L]==0) ret=max(ret,val[L]);
				L++;
			}
			while(L+DI<R) {
				ret=max(ret,ma[L/DI]);
				L+=DI;
			}
			prop(L/DI);
			while(L<R) {
				if(flip[L]==0) ret=max(ret,val[L]);
				L++;
			}
			cout<<ret<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
