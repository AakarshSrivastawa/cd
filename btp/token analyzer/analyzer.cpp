#include <bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define ld long double
#define N 100001
//int mid= start + (end  -  start)/2 to handle  edge cases where they overflow
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
const ll M = 1e9+7;
const ll maxN = 200001;
ll fact[maxN] = {}, smallestPrimeFactor[maxN] = {}, isPrimeSieve[maxN] = {};
mt19937_64 my_rand(chrono::steady_clock::now().time_since_epoch().count());
inline bool comp(ll x,ll y) { return x<y; } // INITIALLY IN DEFAULT INCREASING ORDER (SMALL TO BIG)
inline ll mod(ll x) {ll a1=(x%M); if(a1<0){a1+=M;} return a1;}
inline ll power(ll x, unsigned ll y, ll p = LLONG_MAX) {ll res=1; x=x%p; if(x==0) {return 0;} while(y>0){ if(y&1){res=(res*x)%p;} y=y>>1; x=(x*x)%p;} return res;} // CALCULATING POWER IN LOG(Y) TIME COMPLEXITY
inline ll inversePrimeModular(ll a, ll p) {return power(a,p-2,p);}
inline void calcFact(ll n = maxN-1) { fact[0] = 1; for(ll i=1; i<=n; i++){ fact[i] = fact[i-1]*i; fact[i] = mod(fact[i]); }}
inline ll ncr(ll n, ll r) { if(n<r) return 0; return mod(inversePrimeModular(mod(fact[n-r]*fact[r]),M)*fact[n]); }
inline ll ceil(ll a, ll b) { if(b==0) return LLONG_MAX; ll ans = (a+b-1)/b; return ans; }
void sieve(ll n = maxN-1) { for(ll i=1; i<=n; i++) smallestPrimeFactor[i] = i; for(ll i=2; (i*i)<=n; i++) { if(smallestPrimeFactor[i]==i) { for(ll j=(i*i); j<=n; j+=i) { smallestPrimeFactor[j] = min(smallestPrimeFactor[j], i); } } } for(ll i=2; i<=n; i++) { if(smallestPrimeFactor[i]==i) isPrimeSieve[i] = 1; } }

#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x << " : "; _print_(x);cerr << endl;
#else
#define dbg(x)
#endif
void _print_(ll t) {cerr << t;}
void _print_(int t) {cerr << t;}
void _print_(string t) {cerr << t;}
void _print_(char t) {cerr << t;}
void _print_(ld t) {cerr << t;}
void _print_(double t) {cerr << t;}
template <class T, class V> void _print_(pair <T, V> p);
template <class T> void _print_(vector <T> v);
template <class T> void _print_(set <T> v);
template <class T, class V> void _print_(map <T, V> v);
template <class T> void _print_(multiset <T> v);
template <class T, class V> void _print_(pair <T, V> p) {cerr << "{"; _print_(p.ff); cerr << ","; _print_(p.ss); cerr << "}";}
template <class T> void _print_(vector <T> v) {cerr << "[ "; for (T i : v) {_print_(i); cerr << " ";} cerr << "]";}
template <class T> void _print_(set <T> v) {cerr << "[ "; for (T i : v) {_print_(i); cerr << " ";} cerr << "]";}
template <class T> void _print_(multiset <T> v) {cerr << "[ "; for (T i : v) {_print_(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print_(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print_(i); cerr << " ";} cerr << "]";}

void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
    #endif 
}
bool isPunctuator(string s){
	if (s == "+" || s == "-" || s == "*" ||
    s == "/" || s == "," || s == ";" || s == ">" ||
    s == "<" || s == "=" || s == "(" || s == ")" ||
    s == "[" || s == "]" || s == "{" || s == "}" ||
    s == "&" || s == "|" || s == "<<") return true;
  
	return false;
}
bool isKeyword(string s){
vector<string> v= {"asm","double","new","switch", 
"auto","else","operator","template", 
"break","enum","private","this",
"case","extern","protected","throw",
"catch","float","public","try",
"char","for","register","typedef",
"class","friend","return","union",
"const","goto","short","unsigned",
"continue","if","signed","virtual",
"default","inline","sizeof","void",
" delete","int","static","volatile", "do","long","struct", "while", "main", "int", "if", "return", "cout"}; 
return any_of(all(v), [&s](string x){return x == s;});
}



bool isNumber(string s){
	auto it = s.begin();
	while(it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

bool inf(char ch){
	if(ch == '$' || ch == '@' || ch == '#') return true;
	return false;
}

bool isValidIdentifier(string s){
	auto it = s.begin();
	if(isdigit(*it) || *it == '_') return false;
	while(it!=s.end())
	{
		if(inf(*it)) return false;
		it++;
	}
		return true;
}

bool isComment(string s){
	int i = 0;
	while( i <s.size() && s[i] == ' ' ) i++;
	if(i < s.size() && s[i] == '/'){
		if(i + 1 < s.size() && s[i+1] == '/') return true;
		else if(i + 1< s.size() && s[i+1] == '*'){
			string v;
			if(s.size() >=2 && s[s.size() -1 ] == '/' && s[s.size() - 2] == '*') return true;
			while(getline(cin, v)){
				if(v.size() >= 2 && v[v.size() -1 ] == '/' && v[v.size() - 2] == '*'){break;}
			}
		return true;
		}
	}
	return false;
}

int main(){
	init_code();
	string s;
	vector<string> words;
	set<string> ans;
	while(getline(cin, s)) {
		if(isComment(s)) continue;
		string temp;
		for(char x: s) {
			if(x == ' ' && temp != "") {
				words.push_back(temp);
				temp = "";
				continue;
			}
			else if(x  != ' ') {
				temp += x;
			}
		}
		if(temp != "")
			words.pb(temp);
	}
	int no_tokens = words.size();
	for(auto word: words){
		if(word[word.size() - 1] == ';') {
			no_tokens++;
			ans.insert(";");
			string temp;
			for(int i = 0; i < word.size() - 1; i++) temp += word[i];
			ans.insert(temp);
		}else {
			if(word != " ")
			ans.insert(word);
		}
	}
	vector<string> tokens, identifiers, constants, punctuators;
	for(auto word: ans){
		if(isKeyword(word)) tokens.pb(word);
		else if(isPunctuator(word)) punctuators.pb(word);
		else if(isNumber(word)) constants.pb(word);
		else identifiers.pb(word);
	}
	cout<<"Total number of tokens: " << no_tokens <<endl;
	vector<string> valid_ids, inval;
	for(auto id:identifiers){
		if(isValidIdentifier(id)) valid_ids.pb(id);
		else inval.pb(id);
	}
	cout << "Punctuators: ";
	for (int i = 0; i < punctuators.size(); i++) {
		cout << punctuators[i] << " ";
	}
	cout << endl;

	cout << "valid_ids: ";
	for (int i = 0; i < valid_ids.size(); i++) {
		cout << valid_ids[i] << " ";
	}
	cout <<endl;
	
	cout << "tokens: ";
	for (int i = 0; i < tokens.size(); i++) {
		cout << tokens[i] << " ";
	}
	cout << endl;

	cout << "constants: ";
	for (int i = 0; i < constants.size(); i++) {
		cout << constants[i] << " ";
	}
	cout << endl;

	cout << "Invalids: ";
	for (int i = 0; i < inval.size(); i++) {
		cout << inval[i] << " ";
	}
	cout << endl;

	return 0;
}