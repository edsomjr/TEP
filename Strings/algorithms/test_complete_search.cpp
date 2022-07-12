#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "complete_search.h"

SCENARIO( "substring searching by brute force", "[string]" )
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
                REQUIRE( occurrences(text, pattern) == 0 );
            }
        }

        WHEN ( "pattern occurs only one time" )
        {
            THEN( "return must be one" )
            {
                pattern = "abcde";
                REQUIRE( occurrences(text, pattern) == 1 );

                pattern = "abcdf";
                REQUIRE( occurrences(text, pattern) == 1 );

                pattern = "f";
                REQUIRE( occurrences(text, pattern) == 1 );
            }
        }
 
        WHEN ( "pattern equals text" )
        {
            pattern = text;

            THEN( "return must be one" )
            {
                REQUIRE( occurrences(text, pattern) == 1 );
            }
        }
 
        WHEN ( "pattern occurs multiple times" )
        {
            THEN( "return must report the exact count" )
            {
                pattern = "a";
                REQUIRE( occurrences(text, pattern) == 4 );

                pattern = "ab";
                REQUIRE( occurrences(text, pattern) == 4 );

                pattern = "abc";
                REQUIRE( occurrences(text, pattern) == 4 );

                pattern = "abcd";
                REQUIRE( occurrences(text, pattern) == 3 );
            }
        }
 
        WHEN ( "text repeats the same charactere c and pattern is just c" )
        {
            text = "aaaaaaaaaaaaaaaaaaaa";
            pattern = "a";
 
            THEN( "return must be the text size" )
            {
                REQUIRE( occurrences(text, pattern) == text.size() );
            }
        }
 
        WHEN ( "text repeats the same charactere c and pattern is just c m times" )
        {
            text = "aaaaaaaaaaaaaaaaaaaa";
 
            THEN( "return must be the text size minus m plus one" )
            {
                pattern = "aaa";
                REQUIRE( occurrences(text, pattern) == text.size() - pattern.size() + 1 );

                pattern = "aa";
                REQUIRE( occurrences(text, pattern) == text.size() - pattern.size() + 1 );

                pattern = "aaaaa";
                REQUIRE( occurrences(text, pattern) == text.size() - pattern.size() + 1 );
            }
        }
 
    }
}

