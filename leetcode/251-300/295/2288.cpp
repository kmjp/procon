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
	string concatvec(vector <string> expr) {
		int i;
		string st="";
		FOR(i,expr.size()) {
			if(i) st+=" ";
			st += expr[i];
		}
		return st;
	}

    string discountPrices(string sentence, int discount) {
		vector<string> S=split(sentence);
		FORR(s,S) {
			if(s[0]=='$'&&s.size()>1) {
				ll v=0;
				string t=s.substr(1);
				FORR(c,t) {
					if(c<'0'||c>'9') {
						v=-1;
						break;
					}
					v=v*10+c-'0';
				}
				if(v==-1) continue;
					v*=100-discount;
				if(v<10) {
					s="$0.0"+to_string(v);
				}
				else if(v<100) {
					s="$0."+to_string(v);
				}
				else {
					s="$"+to_string(v);
					s.insert(s.begin()+s.size()-2,'.');
				}
			}
		}
		
		return concatvec(S);
        
    }
};
