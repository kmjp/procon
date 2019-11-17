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

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};

vector<string> split(const string &str, char delim=' '){
	vector<string> res;
	size_t current = 0, found;
	while((found = str.find_first_of(delim, current)) != string::npos){
		res.push_back(string(str, current, found - current));
		current = found + 1;
	}
	res.push_back(string(str, current, str.size() - current));
	return res;
}

vector<string> cand[100];
vector<string> ret;
vector<int> C;

void dfs(int cur,string S) {
	if(cur==C.size()) {
		S.pop_back();
		ret.push_back(S);
		return;
	}
	int i;
	FOR(i,cand[C[cur]].size()) {
		string T=S+cand[C[cur]][i]+" ";
		dfs(cur+1,T);
	}
	
}

class Solution {
public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
		map<string,vector<string>> M;
		map<string,int> W;
		vector<string> D;
		int x=0;
		UF<100> uf;
		FORR(s,synonyms) {
			if(W.count(s[0])==0) W[s[0]]=x++, D.push_back(s[0]);
			if(W.count(s[1])==0) W[s[1]]=x++, D.push_back(s[1]);
		}
		vector<string> S=split(text);
		C.clear();
		FORR(s,S) {
			if(W.count(s)==0) W[s]=x++, D.push_back(s);
			C.push_back(W[s]);
		}
		FORR(s,synonyms) {
			uf(W[s[0]],W[s[1]]);
		}
		
		int i,y,a,b;
		FOR(i,x) cand[i].clear();
		FOR(a,x) FOR(b,x) if(uf[a]==uf[b]) cand[a].push_back(D[b]);
		
		ret.clear();
		dfs(0,"");
		sort(ALL(ret));
		ret.erase(unique(ALL(ret)),ret.end());
		
		return ret;
    }
};


