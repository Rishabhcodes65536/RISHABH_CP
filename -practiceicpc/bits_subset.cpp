#include <bits/stdc++.h>

using namespace std;


void sum_of_all_subset ( vector< int > &s ){
    int n = s.size() ;
    int results[ ( 1 << n ) ] ;     // ( 1 << n )= 2^n

    //initialize results to 0
    memset( results, 0, sizeof( results ) ) ;

    // iterate through all subsets
 
    for( int i = 0 ; i < ( 1 << n ) ; ++ i ) {    // for each subset, O(2^n)
        for ( int j = 0; j < n ; ++ j ) {       // check membership, O(n)
            if ( ( i & ( 1 << j ) ) != 0 )    // test if bit ‘j’ is turned on in subset ‘i’?
                results[i] += s [j] ;          // if yes, process ‘j’
        }
        cout<<results[i]<<" ";
    }
    
}

int main(){
    int n;
    cin>>n;
    vector <int> v(n);
    for(int i=0;i<n;i++){
       cin>>v[i];
    }
    sum_of_all_subset(v);
}