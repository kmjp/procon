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

ll B,L,N;
string S;
vector<string> T;

struct Node {
	string T;
	ll len;
	ll rep;
	vector<int> C;
	vector<ll> num;
};


Node node[101010];
int cur;
int nex;

int dfs() {
	int cnode=nex++;
	node[cnode].num.push_back(0);
	node[cnode].rep=1;
	while(cur<T.size()) {
		if(T[cur]==")") {
			cur++;
			node[cnode].rep=atoll(T[cur].c_str());
			cur++;
			break;
		}
		else if(T[cur]=="(") {
			cur++;
			int tn=dfs();
			node[cnode].len+=node[tn].len*node[tn].rep;
			node[cnode].C.push_back(tn);
			node[cnode].num.push_back(node[cnode].num.back()+node[tn].len*node[tn].rep);
		}
		else {
			
			if(node[cnode].C.size() && node[node[cnode].C.back()].T.size()) {
				int tn=node[cnode].C.back();
				node[tn].T+=T[cur];
				node[tn].len+=T[cur].size();
				node[cnode].len+=T[cur].size();
				node[cnode].num.back()+=T[cur].size();
			}
			else {
				int tn=nex++;
				node[tn].T=T[cur];
				node[tn].len=T[cur].size();
				node[tn].rep=1;
				node[cnode].len+=T[cur].size();
				node[cnode].C.push_back(tn);
				node[cnode].num.push_back(node[cnode].num.back()+node[tn].len*node[tn].rep);
			}
			
			cur++;
		}
	}
	
	if(node[cnode].C.size()==1 && node[cnode].rep==1) return node[cnode].C[0];
	
	return cnode;
}

char dfs2(int cur,ll v) {
	assert(v<=node[cur].len*node[cur].rep);
	v-=(v-1)/node[cur].len*node[cur].len;
	
	if(node[cur].T.size()) return node[cur].T[v-1];
	int x=lower_bound(ALL(node[cur].num),v)-node[cur].num.begin();
	return dfs2(node[cur].C[x-1],v-node[cur].num[x-1]);
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>B>>L>>N>>S;
	FOR(i,N) {
		if(S[i]=='(' || S[i]==')') {
			T.push_back(S.substr(i,1));
		}
		else if(S[i]>='A' && S[i]<='z') {
			j=i;
			while(j<N&&(S[j]>='A' && S[j]<='z')) j++;
			T.push_back(S.substr(i,j-i));
			i=j-1;
		}
		else if(S[i]>='0' && S[i]<='9') {
			j=i;
			while(j<N&&(S[j]>='0' && S[j]<='9')) j++;
			T.push_back(S.substr(i,j-i));
			i=j-1;
		}
	}
	
	int start=dfs();
	/*
	FOR(i,nex) {
		cout<<i<<" "<<node[i].T<<" "<<node[i].len<<" "<<node[i].rep<<"   [[";
		FORR(v,node[i].C) cout<<v;
		cout<<"]]"<<endl;
	}
	*/
	ll TL=node[start].len*node[start].rep;
	if(B<0) B+=TL;
	
	FOR(i,L) cout<<dfs2(start,B+i+1);
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
