#include <bits/stdc++.h>
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

int L;
string C;
int num[62];
//string R="Atcod3rIsGreatAtcod3rIsGreatAtcod3rIsGreatAtcod3rIsGreatAtcod3rIsGreatAtcod3rIsGreatAtcod3rIsGreatAtcod3rIsGreatAtcod3rIsG";
string R;
int dpdp[130][130];
string ret;

int edit(string& AA,string& BB) {
	int x,y,ma=0;
	FOR(x,130) FOR(y,130) dpdp[x][y]=1<<20;
	dpdp[0][0]=0;
	
	FOR(x,AA.size()+1) FOR(y,BB.size()+1) {
		dpdp[x+1][y+1]=min(dpdp[x+1][y+1],dpdp[x][y]+1);
		dpdp[x+1][y]=min(dpdp[x+1][y],dpdp[x][y]+1);
		dpdp[x][y+1]=min(dpdp[x][y+1],dpdp[x][y]+1);
		if(x<AA.size() && y<BB.size()) {
			if(AA[x]==BB[y]) dpdp[x+1][y+1]=min(dpdp[x+1][y+1],dpdp[x][y]);
		}
	}
	return dpdp[AA.size()][BB.size()];
}

int ask(string S) {
	static int num=0;
	num++;
	//assert(num<=849);
	cout<<"? "<<S<<endl;
	
	int x;
	if(R.size()) {
		x=edit(R,S);
	}
	else {
		cin>>x;
	}
	//cerr<<num<<" "<<R<<" "<<S<<" "<<x<<endl;
	if(x==0) {
		cerr<<num<<endl;
		cout<<"! "<<S<<endl;
		exit(0);
	}
	return x;
}

string hoge(string A,string B) {
	int pos=0;
	FORR(b,B) {
		while(1) {
			string C=A.substr(0,pos)+b+A.substr(pos);
			int r=ask(C);
			pos++;
			if(r==L-C.size()) {
				A=C;
				break;
			}
		}
	}
	return A;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	FOR(i,26) C+='a'+i;
	FOR(i,26) C+='A'+i;
	FOR(i,10) C+='0'+i;
	vector<pair<int,string>> cand;
	FOR(i,62) {
		num[i]=128-ask(string(128,C[i]));
		L+=num[i];
		if(num[i]) cand.push_back({num[i],string(num[i],C[i])});
	}
	
	
	while(cand.size()>1) {
		sort(ALL(cand));
		reverse(ALL(cand));
		string A=hoge(cand[cand.size()-1].second,cand[cand.size()-2].second);
		cand.pop_back();
		cand.pop_back();
		cand.push_back({A.size(),A});
		
	}
	
	ask(cand[0].second);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
