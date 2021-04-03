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


class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
		vector<string> A=split(sentence1);
		vector<string> B=split(sentence2);
        if(A==B) return 1;
        if(A.size()<B.size()) swap(A,B);
        
        for(int pre=0;pre<=B.size();pre++) {
			int suf=B.size()-pre;
			int ok=1;
			int i;
			FOR(i,pre) if(A[i]!=B[i]) ok=0;
			FOR(i,suf) if(A[A.size()-1-i]!=B[B.size()-1-i]) ok=0;
			if(ok) return 1;
		}
        
        return 0;
        
        
        
    }
};
