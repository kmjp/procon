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

ll X,Y,Z;
vector<ll> ret;

ll F[120];

void update(vector<ll> cand) {
	assert(cand[0]==X);
	assert(cand.back()==Y);
	int num=0;
	int i;
	for(i=1;i<cand.size()-1;i++) if(cand[i]==Z) num++;
	if(num==0) return;
	if(ret.empty()||ret.size()>cand.size()) ret=cand;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>Y>>Z;
	
	if(X==0&&Y==0) {
		if(Z==0) {
			cout<<3<<endl;
			cout<<"0 0 0"<<endl;
		}
		else {
			cout<<4<<endl;
			cout<<"0 "<<Z<<" "<<Z<<" 0"<<endl;
		}
		return;
	}
	if(X==0&&Z==0) {
		cout<<5<<endl;
		cout<<"0 "<<Y<<" "<<Y<<" "<<0<<" "<<Y<<endl;
		return;
	}
	if(Y==0&&Z==0) {
		cout<<5<<endl;
		cout<<X<<" "<<0<<" "<<X<<" "<<X<<" "<<0<<endl;
		return;
	}
	
	F[1]=1;
	for(i=2;i<=110;i++) F[i]=F[i-1]+F[i-2];
	
	// 0を含むタイプ
	FOR(x,80) FOR(y,80) {
		ll xv,yv;
		if(X==0) {
			xv=0;
		}
		else {
			if(F[x]==0) continue;
			if(X%F[x]) continue;
			xv=X/F[x];
		}
		if(Y==0) {
			yv=0;
		}
		else {
			if(F[y]==0) continue;
			if(Y%F[y]) continue;
			yv=Y/F[y];
		}
		if(xv!=yv) continue;
		int a,c;
		FOR(a,2) FOR(c,2)  {
			vector<ll> C;
			FOR(i,a) {
				C.push_back(xv);
				C.push_back(xv);
				C.push_back(0);
			}
			for(i=1;i<=x;i++) C.push_back(xv*F[i]);
			reverse(ALL(C));
			C.push_back(0);
			FOR(i,c) {
				C.push_back(yv);
				C.push_back(yv);
				C.push_back(0);
			}
			for(i=1;i<=y;i++) C.push_back(yv*F[i]);
			update(C);
		}
	}
	// 0を含まないタイプ
	for(x=1;x<=80;x++) for(y=1;y<=80;y++) {
		__int128 A00=F[x];
		__int128 A01=F[x-1];
		__int128 A10=F[y-1];
		__int128 A11=F[y];
		// A00*s+A01*t=X
		// A10*s+A11*t=Y
		__int128 D=A00*A11-A01*A10;
		__int128 P=A11*X-A01*Y;
		__int128 Q=A10*X-A00*Y;
		if(D==0) continue;
		if(P%D||Q%D) continue;
		P/=D;
		Q/=-D;
		if(P<0||Q<0) continue;
		assert(P*A00+Q*A01==X);
		assert(P*A10+Q*A11==Y);
		vector<ll> C;
		for(i=x;i>0;i--) C.push_back(P*F[i]+Q*F[i-1]);
		for(i=1;i<=y;i++) C.push_back(P*F[i-1]+Q*F[i]);
		update(C);
	}
	
	// X==Yの場合
	if(X==Y) {
		if(Z==0) {
			ret={X,Z,Y};
		}
		else if(Z<=Y) {
			ret={X,Z,Y-Z,Y};
		}
	}

	if(ret.empty()) {
		cout<<-1<<endl;
	}
	else {
		cout<<ret.size()<<endl;
		FORR(r,ret) cout<<r<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
