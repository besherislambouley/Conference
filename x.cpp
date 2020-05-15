/*
 * loop through the input from the last to the first day 
 * for each preson save following informations 
 * mx [i] = the day a scientist i should make his invention 
 * crnt [i] = the last journalist the scientist i met 
 * who [i] = the first journalist the scientist i met 
 * now loop from the first to last day to know the journalists which learned about an invention
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 270
//#define mp make_pair
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
#define gc getchar_unlocked
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+7;
const ld pai=acos(-1);
int n , m , k ;
vpi v [1000009] ; 
pi que[1000009] , crnt [1000009] ;
int mx [1000009] , who [1000009] , done [1000009] ; 
int is ( int x ) {
	return x < k ;
}
int main () {
	mem ( mx , -1 ) ;
	mem ( who, -1 ) ;
	scanf("%d%d%d",&n,&m,&k);
	for ( int i = 0 ; i < m ; i ++ ) {
		scanf("%d%d",&que[i].fi,&que[i].se);
		que [i].fi -- , que [i].se -- ;
		v [ que [i].fi ] .pb ( { que [i] .se , i } ) ;
		v [ que [i].se ] .pb ( { que [i] .fi , i } ) ;
	}
	for ( int i = m - 1 ; i >= 0 ; i -- ) {
		int a = que [i].fi , b = que [i].se ;
		int A = is ( a ) , B = is ( b ) ;
		if ( !A && !B ) C ;
		if (  A && !B ) {
			if ( mx [a] == -1 ) {
				mx [a] = i ;
				who[a] = b ;	
			}
			crnt [a] = { i , b } ;
		}
		if ( !A &&  B ) {
			if ( mx [b] == -1 ) {
				mx [b] = i ;
				who[b] = a ;
			}
			crnt [b] = { i , a } ;
		}
		if ( A && B ) {
			if ( mx [a] == -1 && mx [b] != -1 ) {
				mx [a] = i ;
				who[a] = crnt [b].se ;
			       crnt [a] = crnt [b] ; 	
			}
			else if ( mx [a] != -1 && mx [b] == -1 ) {
				mx [b] = i ;
				who[b] = crnt [a].se ; 
				crnt [b] = crnt [a] ;
			}
			else if ( mx [a] != -1 && mx [b] != -1 ) {
				crnt [a] = crnt [b] = min ( crnt [a] , crnt [b] ) ; 
			}
		}
	}
	vpi v ;
	for ( int i = 0 ; i < m ; i ++ ) {
		int a = que [i].fi , b = que [i].se ;
		if ( mx [a] == i ) done [a] = 1 ;
		if ( mx [b] == i ) done [b] = 1 ;
		done [a] = done [b] = max ( done [a] , done [b] ) ;
	}
	vi ans ;
	for ( int i = k ; i < n ; i ++ ) {
		if ( done [i] ) ans .pb ( i ) ;
	}
	for ( int i = 0 ; i < k ; i ++ ) printf("%d ", mx [i] + ( mx [i] != -1 ) ) ;
	cout << endl ;
	cout << ans.size() << " "  ;
	for ( auto u : ans ) printf("%d ",u+1);
	cout << endl ;
	for ( int i = 0 ; i < k ; i ++ ) printf("%d ", who [i] + ( who[i] != -1 ) ) ;
	cout << endl ; 
}
