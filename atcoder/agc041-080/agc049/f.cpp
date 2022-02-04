#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll A[202020],B[202020],C[202020];
ll V[202020];
ll DA[202020];
ll E[202020];
ll S[6][5<<20];
ll offset[5<<20];
const int OFF=2500000;

ll getcnt(int i,int T) {
	// pos=iÇ≈Tñ¢ñûóvëfêî
	ll sum=0;
	for(int k=1;k<=5;k++) {
		int j=min(OFF,T-2*k*i-1);
		if(j>=-OFF) {
			sum+=S[k][j+OFF];
		}
	}
	return sum;
}

ll getsum(int pos,int v) {
	// posà»ç~Ç≈vÇÃå¬êî
	ll sum=offset[v+OFF];
	for(int k=1;k<=5;k++) if(abs(v)%(2*k)==k) {
		ll R=min(OFF,v-2*k*pos);
		ll L=v-2*k*(200000)-1;
		if(R>=-OFF&&R>L) {
			sum+=S[k][R+OFF];
			if(L>=-OFF) sum-=S[k][L+OFF];
		}
	}
	return sum;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N) {
		cin>>B[i];
		V[0]+=B[i];
		DA[0]--;
		DA[B[i]+1]+=2;
	}
	ll CS=0;
	FOR(i,N) {
		cin>>C[i];
		CS+=C[i]*A[i]*A[i];
		S[C[i]][OFF+C[i]*(-2*A[i]+1)]++;
	}
	
	for(i=1;i<=200000;i++) {
		DA[i]+=DA[i-1];
		V[i]=V[i-1]+DA[i];
	}
	for(i=1;i<2*OFF+3;i++) {
		FOR(j,6) S[j][i]+=S[j][i-1];
	}
	FOR(i,200001) E[i]=max(0LL,V[i]-1LL*N*i+V[0])/2;
	
	ll ret=CS;
	/*
	multiset<ll> M;
	for(i=200000;i>=0;i--) {
		FOR(j,N) M.insert(C[j]*(2*(i-A[j])+1));
		while(M.size()>E[i]) M.erase(prev(M.end()));
	}
	FORR(m,M) {
		cout<<m<<endl;
		ret+=m;
	}
	cout<<ret<<endl;
	return;
	*/
	int T=-OFF+5;
	//T=-200;
	for(i=200000;i>=0;i--) {
		ll DE=E[i]-E[i+1];
		ll V=getcnt(i,T);
		ll pre=V;
		while(V<DE) {
			ll NV=getcnt(i,T+1);
			ll CS=getsum(i+1,T);
			offset[T+OFF]+=-CS; //posà»ç~ÇÃTÇÃécå¬êîÇãÛÇ…Ç∑ÇÈ
			if(NV-pre) {
				//cout<<i<<"::  "<<T<<" "<<(NV-pre)<<endl;
			}
			V+=NV-pre;
			pre=NV;
			
			T++;
		}
		
		while(DE<V) {
			ll dif=V-DE;
			ll CS=getsum(i,T-1);
			//if(CS) cout<<i<<"## "<<T<<" "<<CS<<" "<<dif<<endl;
			if(dif<=CS) {
				offset[T-1+OFF]-=dif;
				V-=dif;
				break;
			}
			else {
				V-=CS;
				T--;
			}
		}
		assert(V==DE);
	}
	//cout<<T<<endl;
	for(i=-OFF;i<T;i++) {
		ll CS=getsum(0,i);
		//if(CS) cout<<"$ "<<i<<" "<<CS<<endl;
		ret+=1LL*i*CS;
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
