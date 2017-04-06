#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "MP.h"

SCENARIO( "borders computation", "[string]" )
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

                REQUIRE( borders1(pattern) == bords );
                REQUIRE( borders2(pattern) == bords );
            }
        }

        WHEN ( "all characteres in pattern are the same" )
        {
            pattern = "aaaaaaaaa";

            THEN( "the size of the borders are an increasing sequence" )
            {
                vector<int> bords(pattern.size() + 1);

                for (size_t i = 1; i < bords.size(); ++i)
                    bords[i] = i - 1;
 
                bords[0] = -1;

                REQUIRE( borders1(pattern) == bords );
                REQUIRE( borders2(pattern) == bords );
            }
        }
 
        WHEN ( "pattern equals 'ababa'" )
        {
            pattern = "ababa";

            THEN( "the size of the borders are an non-decreasing sequence" )
            {
                vector<int> bords(pattern.size() + 1);

                for (size_t i = 3; i < bords.size(); ++i)
                    bords[i] = i - 2;
 
                bords[0] = -1;

                REQUIRE( borders1(pattern) == bords );
                REQUIRE( borders2(pattern) == bords );
            }
        }
 
        WHEN ( "pattern equals 'abababababb'" )
        {
            pattern = "abababababb";

            THEN( "the size of the borders are almost an non-decreasing sequence" )
            {
                vector<int> bords(pattern.size() + 1);

                for (size_t i = 3; i < bords.size(); ++i)
                    bords[i] = i - 2;
 
                bords[0] = -1;
                bords[11] = 0;

                REQUIRE( borders1(pattern) == bords );
                REQUIRE( borders2(pattern) == bords );
            }
        }
 
        WHEN ( "pattern equals 'ababaababa'" )
        {
            pattern = "ababaababa";

            THEN( "the size of the borders are { 0, 0, 1, 2, 3, 1, 2, 3, 4, 5 } " )
            {
                vector<int> bords { -1, 0, 0, 1, 2, 3, 1, 2, 3, 4, 5 };

                REQUIRE( borders1(pattern) == bords );
                REQUIRE( borders2(pattern) == bords );
            }
        }
 
        WHEN ( "pattern equals 'seventy seven'" )
        {
            pattern = "seventy seven";

            THEN( "the size of the borders are an non-decreasing sequence" )
            {
                vector<int> bords(pattern.size() + 1);

                for (size_t i = 9; i < bords.size(); ++i)
                    bords[i] = i - 8;
 
                bords[0] = -1;

                REQUIRE( borders1(pattern) == bords );
                REQUIRE( borders2(pattern) == bords );
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
                REQUIRE( MP1(text, pattern) == 0 );
                REQUIRE( MP2(text, pattern) == 0 );
            }
        }

        WHEN ( "pattern occurs only one time" )
        {
            THEN( "return must be one" )
            {
                pattern = "abcde";
                REQUIRE( MP1(text, pattern) == 1 );
                REQUIRE( MP2(text, pattern) == 1 );

                pattern = "abcdf";
                REQUIRE( MP1(text, pattern) == 1 );
                REQUIRE( MP2(text, pattern) == 1 );

                pattern = "f";
                REQUIRE( MP1(text, pattern) == 1 );
                REQUIRE( MP2(text, pattern) == 1 );
            }
        }

        WHEN ( "pattern equals text" )
        {
            pattern = text;

            THEN( "return must be one" )
            {
                REQUIRE( MP1(text, pattern) == 1 );
                REQUIRE( MP2(text, pattern) == 1 );
            }
        }
 
        WHEN ( "pattern occurs multiple times" )
        {
            THEN( "return must report the exact count" )
            {
                pattern = "a";
                REQUIRE( MP1(text, pattern) == 4 );
                REQUIRE( MP2(text, pattern) == 4 );

                pattern = "ab";
                REQUIRE( MP1(text, pattern) == 4 );
                REQUIRE( MP2(text, pattern) == 4 );

                pattern = "abc";
                REQUIRE( MP1(text, pattern) == 4 );
                REQUIRE( MP2(text, pattern) == 4 );

                pattern = "abcd";
                REQUIRE( MP1(text, pattern) == 3 );
                REQUIRE( MP2(text, pattern) == 3 );
            }
        }
 
        WHEN ( "text repeats the same charactere c and pattern is just c" )
        {
            text = "aaaaaaaaaaaaaaaaaaaa";
            pattern = "a";
 
            THEN( "return must be the text size" )
            {
                REQUIRE( MP1(text, pattern) == text.size() );
                REQUIRE( MP2(text, pattern) == text.size() );
            }
        }
 
        WHEN ( "text repeats the same charactere c and pattern is just c m times" )
        {
            text = "aaaaaaaaaaaaaaaaaaaa";
 
            THEN( "return must be the text size minus m plus one" )
            {
                pattern = "aaa";
                REQUIRE( MP1(text, pattern) == text.size() - pattern.size() + 1 );
                REQUIRE( MP2(text, pattern) == text.size() - pattern.size() + 1 );

                pattern = "aa";
                REQUIRE( MP1(text, pattern) == text.size() - pattern.size() + 1 );
                REQUIRE( MP2(text, pattern) == text.size() - pattern.size() + 1 );

                pattern = "aaaaa";
                REQUIRE( MP1(text, pattern) == text.size() - pattern.size() + 1 );
                REQUIRE( MP2(text, pattern) == text.size() - pattern.size() + 1 );
            }
        }
 
    }
}

