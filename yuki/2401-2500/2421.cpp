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

int N;
string X[101010];
ll L[101010],R[101010];

int Q;
ll QT[101010],QL[101010],QR[101010];
string QX[101010];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;
map<string,set<pair<int,int>>> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<ll> Xs={0};
	FOR(i,N) {
		cin>>X[i]>>L[i]>>R[i];
		L[i]=L[i]*3-1;
		R[i]=R[i]*3+1;
		Xs.push_back(L[i]);
		Xs.push_back(R[i]);
		
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>QT[i];
		if(QT[i]==1) {
			cin>>QX[i]>>QL[i];
			QL[i]*=3;
			Xs.push_back(QL[i]);
		}
		if(QT[i]==2) {
			cin>>QL[i];
			QL[i]*=3;
			Xs.push_back(QL[i]);
		}
		if(QT[i]==3) {
			cin>>QX[i]>>QL[i]>>QR[i];
			QL[i]=QL[i]*3-1;
			QR[i]=QR[i]*3+1;
			Xs.push_back(QL[i]);
			Xs.push_back(QR[i]);
		}
	}
	sort(ALL(Xs));
	Xs.erase(unique(ALL(Xs)),Xs.end());
	FOR(i,N) {
		L[i]=lower_bound(ALL(Xs),L[i])-Xs.begin();
		R[i]=lower_bound(ALL(Xs),R[i])-Xs.begin();
		M[X[i]].insert({L[i],0});
		M[X[i]].insert({R[i],1});
		bt.add(L[i],1);
		bt.add(R[i],-1);
	}
	FOR(i,Q) {
		if(QT[i]==1) {
			x=lower_bound(ALL(Xs),QL[i])-Xs.begin();
			auto it=M[QX[i]].lower_bound({x,0});
			if(it==M[QX[i]].end()||it->second==0) {
				cout<<"No"<<endl;
			}
			else {
				cout<<"Yes"<<endl;
			}
		}
		else if(QT[i]==2) {
			x=lower_bound(ALL(Xs),QL[i])-Xs.begin();
			cout<<bt(x)<<endl;
		}
		else {
			QL[i]=lower_bound(ALL(Xs),QL[i])-Xs.begin();
			QR[i]=lower_bound(ALL(Xs),QR[i])-Xs.begin();
			M[QX[i]].insert({QL[i],0});
			M[QX[i]].insert({QR[i],1});
			bt.add(QL[i],1);
			bt.add(QR[i],-1);
		}

	}
	
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
