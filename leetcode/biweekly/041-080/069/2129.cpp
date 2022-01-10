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
    string capitalizeTitle(string title) {
		auto a=split(title);
		string S;
		FORR(v,a) {
			S+=" ";
			if(v.size()==1||v.size()==2) {
				FORR(c,v) {
					if(c>='A'&&c<='Z') c+='a'-'A';
				}
			}
			else {
				FORR(c,v) {
					if(c>='A'&&c<='Z') c+='a'-'A';
				}
				v[0]+='A'-'a';
			}
			S+=v;
		}
		return S.substr(1);			
			
		
        
    }
};

