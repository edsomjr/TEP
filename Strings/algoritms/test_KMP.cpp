#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "KMP.h"

SCENARIO( "strong borders computation", "[string]" )
{
    GIVEN ( "a pattern" )
    {
        string pattern;

        WHEN ( "all characteres in pattern are differente" )
        {
            pattern = "abcdef";

            THEN( "all borders have size zero" )
            {
                vector<int> bords(pattern.size() + 1);
                bords[0] = -1;

                REQUIRE( strong_borders(pattern) == bords );
            }
        }

        WHEN ( "all characteres in pattern are the same" )
        {
            pattern = "aaaaaaaaa";

            THEN( "the size of the borders are an non-decreasing sequence" )
            {
                vector<int> bords(pattern.size() + 1, -1);
                bords[9] = 8;

                REQUIRE( strong_borders(pattern) == bords );
            }
        }
 
        WHEN ( "pattern equals 'ababa'" )
        {
            pattern = "ababa";

            THEN( "the only non-trivial strong border occurs on entire pattern" )
            {
                vector<int> bords { -1, 0, -1, 0, -1, 3 };

                REQUIRE( strong_borders(pattern) == bords );
            }
        }
 
        WHEN ( "pattern equals 'abababababb'" )
        {
            pattern = "abababababb";

            THEN( "the size of the borders are a alternating sequency of 0s and -1s, except in j = 10" )
            {
                vector<int> bords { -1, 0, -1, 0, -1, 0, -1, 0, -1, 0, 8, 0 };

                REQUIRE( strong_borders(pattern) == bords );
            }
        }
 
        WHEN ( "pattern equals 'seventy seven'" )
        {
            pattern = "seventy seven";

            THEN( "the only non-trivial strong border occurs on entire pattern" )
            {
                vector<int> bords { -1, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 5 };

                REQUIRE( strong_borders(pattern) == bords );
            }
        }
    }
}

SCENARIO( "substring searching using MP algorithm", "[string]" )
{
    GIVEN ( "A text and a pattern" )
    {
        string text = "abcabcdabcdeabcdf";
        string pattern;

        WHEN ( "pattern don't occurs in text" )
        {
            pattern = "abcdef";

            THEN( "return must be zero" )
            {
                REQUIRE( KMP(text, pattern) == 0 );
            }
        }

        WHEN ( "pattern occurs only one time" )
        {
            THEN( "return must be one" )
            {
                pattern = "abcde";
                REQUIRE( KMP(text, pattern) == 1 );

                pattern = "abcdf";
                REQUIRE( KMP(text, pattern) == 1 );

                pattern = "f";
                REQUIRE( KMP(text, pattern) == 1 );
            }
        }

        WHEN ( "pattern equals text" )
        {
            pattern = text;

            THEN( "return must be one" )
            {
                REQUIRE( KMP(text, pattern) == 1 );
            }
        }
 
        WHEN ( "pattern occurs multiple times" )
        {
            THEN( "return must report the exact count" )
            {
                pattern = "a";
                REQUIRE( KMP(text, pattern) == 4 );

                pattern = "ab";
                REQUIRE( KMP(text, pattern) == 4 );

                pattern = "abc";
                REQUIRE( KMP(text, pattern) == 4 );

                pattern = "abcd";
                REQUIRE( KMP(text, pattern) == 3 );
            }
        }
 
        WHEN ( "text repeats the same charactere c and pattern is just c" )
        {
            text = "aaaaaaaaaaaaaaaaaaaa";
            pattern = "a";
 
            THEN( "return must be the text size" )
            {
                REQUIRE( KMP(text, pattern) == text.size() );
            }
        }
 
        WHEN ( "text repeats the same charactere c and pattern is just c m times" )
        {
            text = "aaaaaaaaaaaaaaaaaaaa";
 
            THEN( "return must be the text size minus m plus one" )
            {
                pattern = "aaa";
                REQUIRE( KMP(text, pattern) == text.size() - pattern.size() + 1 );

                pattern = "aa";
                REQUIRE( KMP(text, pattern) == text.size() - pattern.size() + 1 );

                pattern = "aaaaa";
                REQUIRE( KMP(text, pattern) == text.size() - pattern.size() + 1 );
            }
        }
 
    }
}

