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
    string sortSentence(string s) {
		vector<string> S=split(s);
		vector<string> T(S.size());
		FORR(s,S) {
			int x=s.back()-'1';
			s.pop_back();
			T[x]=s;
		}
		string ret;
		FORR(t,T) {
			if(ret.size()) ret+=" ";
			ret+=t;
		}
		return ret;
		
		
		
		
        
    }
};
