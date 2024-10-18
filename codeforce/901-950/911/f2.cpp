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
vector<int> L[20];
int P[202020];

vector<int> hoge(vector<int>& v,int step,int last) {
	vector<int> nex;
	int i;
	FOR(i,v.size()-last) {
		if(i&&step%2==0&&P[v[i]]>P[v[i-1]]) continue;
		if(i&&step%2==1&&P[v[i]]<P[v[i-1]]) continue;
		if(i+1<v.size()&&step%2==0&&P[v[i]]>P[v[i+1]]) continue;
		if(i+1<v.size()&&step%2==1&&P[v[i]]<P[v[i+1]]) continue;
		nex.push_back(v[i]);
	}
	return nex;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>P[i];
		L[0].push_back(i);
	}
	FOR(i,20) if(L[i].size()>1) L[i+1]=hoge(L[i],i,0);
	
	while(Q--) {
		int QL,QR;
		cin>>QL>>QR;
		if(QL>QR) swap(QL,QR);
		QL--;
		if(QL+1==QR) {
			cout<<P[QL]<<endl;
			continue;
		}
		vector<int> TL={QL},TR={QR-1};
		int CL=QL+1,CR=QR-2;
		int step=0;
		while(CL<=CR) {
			int CL2=lower_bound(ALL(L[step]),CL)-L[step].begin();
			int CR2=lower_bound(ALL(L[step]),CR)-L[step].begin();
			if(CR2-CL2<=10) break;
			vector<int> TL2,TR2;
			TL.push_back(CL);
			TL.push_back(L[step][CL2+1]);
			TR.push_back(CR);
			TR.push_back(L[step][CR2-1]);
			TL=hoge(TL,step,1);
			TR=hoge(TR,step,1);
			step++;
			x=lower_bound(ALL(L[step]),CL+1)-L[step].begin();
			y=lower_bound(ALL(L[step]),CR)-L[step].begin()-1;
			if(x>y) {
				CL=1,CR=0;
			}
			else {
				CL=L[step][x];
				CR=L[step][y];
			}
		}
		if(CL<=CR) {
			int CL2=lower_bound(ALL(L[step]),CL)-L[step].begin();
			int CR2=lower_bound(ALL(L[step]),CR)-L[step].begin();
			for(x=CL2;x<=CR2;x++) TL.push_back(L[step][x]);
		}
		reverse(ALL(TR));
		FORR(x,TR) TL.push_back(x);
		step%=2;
		
		while(TL.size()>1) {
			TL=hoge(TL,step,0);
			step^=1;
		}
		cout<<P[TL[0]]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
