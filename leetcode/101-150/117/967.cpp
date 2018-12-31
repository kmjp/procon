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

class Solution {
public:
	int B;
	
	string cap(string a) {
		FORR(c,a) if(c>='A' && c<='Z') c-='A'-'a';
		return a;
	}
	string vow(string a) {
		FORR(c,a) {
			if(c>='A' && c<='Z') c-='A'-'a';
			if(c=='i' || c=='u' || c=='e' || c=='o') c='a';
		}
		return a;
	}
	
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
		map<string,string> Q,C,V;
		vector<string> R;
		FORR(s,wordlist) {
			Q[s]=s;
			if(C.count(cap(s))==0) C[cap(s)]=s;
			if(V.count(vow(s))==0) V[vow(s)]=s;
		}
		FORR(c,queries) {
			if(Q.count(c)) R.push_back(c);
			else if(C.count(cap(c))) R.push_back(C[cap(c)]);
			else if(V.count(vow(c))) R.push_back(V[vow(c)]);
			else R.push_back("");
		}
		return R;
		
		
    }
    
};
