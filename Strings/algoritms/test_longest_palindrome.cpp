#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "longest_palindrome.h"

SCENARIO( "longest palindrome subsequence", "[string]" )
{
    GIVEN ( "a string s" )
    {
        string s;

        WHEN ( "s is the empty string" )
        {
            s = "";

            THEN( "then the longest palindrome has size zero" )
            {
                REQUIRE( longest_palindrome(s) == 0 );
            }
        }

        WHEN ( "s is a palindrome" )
        {
            THEN( "then the longest pallindrome size equals the size of s" )
            {
                s = "mussum";
                REQUIRE( longest_palindrome(s) == s.size() );

                s = "aba";
                REQUIRE( longest_palindrome(s) == s.size() );

                s = "a";
                REQUIRE( longest_palindrome(s) == s.size() );

                s = "aa";
                REQUIRE( longest_palindrome(s) == s.size() );

                s = "abbbacabbba";
                REQUIRE( longest_palindrome(s) == s.size() );
            }
        }

        WHEN ( "all characteres of s are different" )
        {
            s = "abcedfghijk";

            THEN( "then the longest palindrome has size one" )
            {
                REQUIRE( longest_palindrome(s) == 1 );
            }
        }

        WHEN ( "s = \"anao\" " )
        {
            s = "anao";

            THEN( "then longest palindrome size equals 3" )
            {
                REQUIRE( longest_palindrome(s) == 3 );
            }
        }
        
        WHEN ( "s = \"tomo\" " )
        {
            s = "tomo";

            THEN( "then longest palindrome size equals 3" )
            {
                REQUIRE( longest_palindrome(s) == 3 );
            }
        }

        WHEN ( "s = \"reentrei\" " )
        {
            s = "reentrei";

            THEN( "then longest palindrome size equals 4" )
            {
                REQUIRE( longest_palindrome(s) == 4 );
            }
        }

        WHEN ( "s = \"FGA\" " )
        {
            s = "FGA";

            THEN( "then longest palindrome size equals 1" )
            {
                REQUIRE( longest_palindrome(s) == 1 );
            }
        }
    } 
}

SCENARIO( "longest palindrome subsequence string", "[string]" )
{
    GIVEN ( "a string s" )
    {
        string s;

        WHEN ( "s is the empty string" )
        {
            s = "";

            THEN( "then the longest palindrome equals s" )
            {
                REQUIRE( longest_palindrome_str(s) == s );
            }
        }

        WHEN ( "s is a palindrome" )
        {
            THEN( "then the longest pallindrome size equals s" )
            {
                s = "mussum";
                REQUIRE( longest_palindrome_str(s) == s );

                s = "aba";
                REQUIRE( longest_palindrome_str(s) == s );

                s = "a";
                REQUIRE( longest_palindrome_str(s) == s );

                s = "aa";
                REQUIRE( longest_palindrome_str(s) == s );

                s = "abbbacabbba";
                REQUIRE( longest_palindrome_str(s) == s );
            }
        }

        WHEN ( "s = \"anao\" " )
        {
            s = "anao";

            THEN( "then longest palindrome equals \"ana\"" )
            {
                REQUIRE( longest_palindrome_str(s) == "ana" );
            }
        }
        
        WHEN ( "s = \"tomo\" " )
        {
            s = "tomo";

            THEN( "then longest palindrome equals \"omo\" " )
            {
                REQUIRE( longest_palindrome_str(s) == "omo" );
            }
        }

        WHEN ( "s = \"reentrei\" " )
        {
            s = "reentrei";

            THEN( "then longest palindrome equals \"reer\" " )
            {
                REQUIRE( longest_palindrome_str(s) == "reer" );
            }
        }
    } 
}
