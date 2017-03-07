#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "edit.h"

SCENARIO( "edit distance computation", "[string]" )
{
    GIVEN ( "two strings s and t" )
    {
        string s, t = "banana";

        WHEN ( "s is the empty string" )
        {
            s = "";

            THEN( "then the edit cost equals size of t insertions" )
            {
                c_i = 2;

                REQUIRE( edit(s, t) == c_i * t.size() );

                t = "";

                REQUIRE( edit(s, t) == c_i * t.size() );
            }
        }

        WHEN ( "t is the empty string" )
        {
            s = "bacanas";
            t = "";

            THEN( "then the edit cost equals size of s deletions" )
            {
                c_r = 3;

                REQUIRE( edit(s, t) == c_r * s.size() );

                s = "";

                REQUIRE( edit(s, t) == c_r * s.size() );
            }
        }

        WHEN ( "s and t are equals" )
        {
            s = "bacanas";
            t = s;

            THEN( "then the edit cost is zero" )
            {
                REQUIRE( edit(s, t) == 0 );
            }
        }

        WHEN ( "the costs are all equals" )
        {
            c_i = c_r = c_s = 7;

            s = "bacanas";
            t = "banana";

            THEN( "then the edit() is simmetrical" )
            {
                REQUIRE( edit(s, t) == edit(t, s) );

                c_i = 1;
                c_r = 2;
                c_s = 3;

                REQUIRE( edit(s, t) != edit(t, s) );
            }
        }

        WHEN ( "s and t have the same size and differs by only one character" )
        {
            s = "bacana";
            t = "banana";

            THEN( "then the edit cost equals one substitution" )
            {
                REQUIRE( edit(s, t) == c_s );
            }
        }

        WHEN ( "s has more characteres then t and all chars of t are in s" )
        {
            s = "aspectos";
            t = "seco";

            THEN( "then the edit cost equals to the neeed deletions" )
            {
                REQUIRE( edit(s, t) == c_r * (s.size() - t.size()) );
            }
        }

        WHEN ( "s has less characteres then t and all chars of s are in t" )
        {
            s = "fga";
            t = "formigas";

            THEN( "then the edit cost equals to the neeed insertions" )
            {
                REQUIRE( edit(s, t) == c_i * (t.size() - s.size()) );
            }
        }


    }
}

