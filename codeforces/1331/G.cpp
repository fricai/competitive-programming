#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
 
int main( ) {
    std::cout << std::fixed << std::setprecision(2);
   std::vector<double> input( 11 ) , results( 11 ) ;
   for ( int i = 0 ; i < input.size( ) ; i++ ) 
      std::cin >> input[i];
   std::transform( input.begin( ) , input.end( ) , results.begin( ) ,
	 [ ]( double n )-> double { return sqrt( abs( n ) ) + 5 * pow( n , 3 ) ; } ) ;
   for ( int i = 10 ; i > -1 ; i-- ) {
      std::cout << "f(" << int(input[ i ]) << ") = " ; 
      if ( results[ i ] > 400 ) std::cout << "MAGNA NIMIS!" ;
      else  std::cout << results[ i ];
      std::cout << std::endl ;
   }
   return 0 ;
}