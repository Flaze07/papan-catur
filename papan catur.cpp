#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <algorithm>

struct pos
{
    int x;//alphabet
    int y;//number
};

std::vector< std::string > pawn( pos posi, std::array< std::string, 8 >& board )
{
    std::vector< std::string > result;
    if( ( ( posi.x - 1 >= 0 ) && ( posi.y + 1 < 8 ) ) &&
        ( board.at( posi.y + 1 ).at( posi.x - 1 ) == 'p' ) ||
        ( board.at( posi.y + 1 ).at( posi.x - 1 ) == 'n' ) ||
        ( board.at( posi.y + 1 ).at( posi.x - 1 ) == 'b' ) ||
        ( board.at( posi.y + 1 ).at( posi.x - 1 ) == 'q' ) ||
        ( board.at( posi.y + 1 ).at( posi.x - 1 ) == 'k' )
      )
    {
        result.push_back( static_cast< char >( posi.x - 1 + 65 ) + " " + std::to_string( posi.y + 1 ) );
    }
    if( ( ( posi.x + 1 < 8 ) && ( posi.y + 1 < 8 ) ) &&
        ( board.at( posi.y + 1 ).at( posi.x + 1 ) == 'p' ) ||
        ( board.at( posi.y + 1 ).at( posi.x + 1 ) == 'n' ) ||
        ( board.at( posi.y + 1 ).at( posi.x + 1 ) == 'b' ) ||
        ( board.at( posi.y + 1 ).at( posi.x + 1 ) == 'q' ) ||
        ( board.at( posi.y + 1 ).at( posi.x + 1 ) == 'k' )
      )
    {
        result.push_back( static_cast< char >( posi.x + 1 + 65 ) + " " + std::to_string( posi.y + 1 ) );
    }
    return result;
}


int main()
{
    std::ios::sync_with_stdio( false );
    int test_case;
    std::cin >> test_case;
    while( test_case-- > 0 )
    {
        std::vector< std::string > res;
        std::array< std::string, 8 > arr;
        for( int i = 0; i < 8; ++i )
        {
            std::cin >> arr.at( i );
        }
        std::reverse( arr.begin(), arr.end() );
        for( int i = 0; i < 8; ++i )
        {
            for( int j = 0; j < 8; ++j )
            {
                if( arr.at( i ).at( j ) == 'P' )
                {
                    auto temp = pawn( pos{ j, i }, arr );
                    res.insert( res.begin(), temp.begin(), temp.end() );
                }
                //std::cout << "i : " << i << " j : " << j << '\n';
            }
        }
        //std::cout << "output\n";
        std::sort( res.begin(), res.end(), []( std::string a, std::string b ){ return a > b; } );
        std::cout << "res size " << res.size() << "\n";
        for( int i = 0; i < res.size(); ++i )
        {
            std::cout << res.at( i ) << '\n';
        }
        std::cout << "after\n";
    }
}
