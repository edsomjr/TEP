#define CATCH_CONFIG_MAIN

#include <algorithm>
#include <set>

#include "catch.hpp"
#include "trie.h"

SCENARIO( "naive trie construction", "[string]" )
{
    GIVEN ( "a pattern" )
    {
        string pattern;

        WHEN ( "pattern is equals to 'banana'" )
        {
            pattern = "banana";
            build_naive(pattern);

            THEN( "the trie has all substrings of pattern" )
            {
                for (size_t i = 0; i < pattern.size(); ++i)
                    for (size_t j = 1; j < pattern.size(); ++j)
                        REQUIRE( trie_search(pattern.substr(i, j - i + 1)) );
            }

            THEN( "words with chars different from 'a, b, c' are not substrings of pattern" )
            {
                REQUIRE( trie_search("anam") == false);
                REQUIRE( trie_search("bama") == false);
                REQUIRE( trie_search("aman") == false);
                REQUIRE( trie_search("dana") == false);
            }
        }

        WHEN ( "pattern is equals a non-empty string" )
        {
            THEN( "each node corresponde to a unique substring of pattern" )
            {
                pattern = "banana";
                build_naive(pattern);

                set<string> S;

                for (size_t i = 0; i < pattern.size(); ++i)
                for (size_t j = i; j < pattern.size(); ++j)
                    S.insert(pattern.substr(i, j - i + 1));

                REQUIRE( unique_substrings() == S.size() );

                pattern = "aaaaaaa";
                build_naive(pattern);

                S.clear();

                for (size_t i = 0; i < pattern.size(); ++i)
                for (size_t j = i; j < pattern.size(); ++j)
                    S.insert(pattern.substr(i, j - i + 1));

                REQUIRE( unique_substrings() == S.size() );

                pattern = "abcdefghijklm";
                build_naive_with_marker(pattern);

                S.clear();

                for (size_t i = 0; i < pattern.size(); ++i)
                for (size_t j = i; j < pattern.size(); ++j)
                    S.insert(pattern.substr(i, j - i + 1));

                REQUIRE( unique_substrings() == S.size() );

                pattern = "ababababababababababababab";
                build_naive_with_marker(pattern);

                S.clear();

                for (size_t i = 0; i < pattern.size(); ++i)
                for (size_t j = i; j < pattern.size(); ++j)
                    S.insert(pattern.substr(i, j - i + 1));

                REQUIRE( unique_substrings() == S.size() );

                pattern = "a";
                build_naive_with_marker(pattern);

                S.clear();

                for (size_t i = 0; i < pattern.size(); ++i)
                for (size_t j = i; j < pattern.size(); ++j)
                    S.insert(pattern.substr(i, j - i + 1));

                REQUIRE( unique_substrings() == S.size() ); 
            }
        }
    }
}

SCENARIO( "naive trie construction with end-marker", "[string]" )
{
    GIVEN ( "a pattern" )
    {
        string pattern;

        WHEN ( "pattern is equals to 'banana'" )
        {
            pattern = "banana";
            build_naive_with_marker(pattern);

            THEN( "the trie has all substrings of pattern" )
            {
                for (size_t i = 0; i < pattern.size(); ++i)
                    for (size_t j = 1; j < pattern.size(); ++j)
                        REQUIRE( not trie_search_positions(pattern.substr(i, j - i + 1)).empty() );
            }

            THEN( "words with chars different from 'a, b, c' are not substrings of pattern" )
            {
                REQUIRE( trie_search_positions("anam").empty() );
                REQUIRE( trie_search_positions("bama").empty() );
                REQUIRE( trie_search_positions("aman").empty() );
                REQUIRE( trie_search_positions("dana").empty() );
            }
 
            THEN( "the 'ana' e 'na' are found in two different positions" )
            {
                vector<int> pos { 1, 3 };
                auto p = trie_search_positions("ana");
                sort(p.begin(), p.end());

                REQUIRE( pos == p );

                vector<int> pos2 { 2, 4 };
                p = trie_search_positions("na");
                sort(p.begin(), p.end());

                REQUIRE( pos2 == p );
            }
        }

        WHEN ( "pattern is equals a non-empty string" )
        {
            THEN( "each node corresponde to a unique substring of pattern" )
            {
                pattern = "banana";
                build_naive_with_marker(pattern);

                set<string> S;

                for (size_t i = 0; i < pattern.size(); ++i)
                for (size_t j = i; j < pattern.size(); ++j)
                    S.insert(pattern.substr(i, j - i + 1));

                REQUIRE( unique_substrings() == S.size() );

                pattern = "aaaaaaa";
                build_naive_with_marker(pattern);

                S.clear();

                for (size_t i = 0; i < pattern.size(); ++i)
                for (size_t j = i; j < pattern.size(); ++j)
                    S.insert(pattern.substr(i, j - i + 1));

                REQUIRE( unique_substrings() == S.size() );

                pattern = "abcdefghijklm";
                build_naive_with_marker(pattern);

                S.clear();

                for (size_t i = 0; i < pattern.size(); ++i)
                for (size_t j = i; j < pattern.size(); ++j)
                    S.insert(pattern.substr(i, j - i + 1));

                REQUIRE( unique_substrings() == S.size() );

                pattern = "ababababababababababababab";
                build_naive_with_marker(pattern);

                S.clear();

                for (size_t i = 0; i < pattern.size(); ++i)
                for (size_t j = i; j < pattern.size(); ++j)
                    S.insert(pattern.substr(i, j - i + 1));

                REQUIRE( unique_substrings() == S.size() );

                pattern = "a";
                build_naive_with_marker(pattern);

                S.clear();

                for (size_t i = 0; i < pattern.size(); ++i)
                for (size_t j = i; j < pattern.size(); ++j)
                    S.insert(pattern.substr(i, j - i + 1));

                REQUIRE( unique_substrings() == S.size() );
            }
        }
    }
}

SCENARIO( "online trie construction", "[string]" )
{
    GIVEN ( "a pattern" )
    {
        string pattern;

        WHEN ( "pattern is equals to 'banana'" )
        {
            pattern = "banana";
            build_online(pattern);

            THEN( "the trie has all substrings of pattern" )
            {
                for (size_t i = 0; i < pattern.size(); ++i)
                    for (size_t j = 1; j < pattern.size(); ++j)
                        REQUIRE( trie_search(pattern.substr(i, j - i + 1)) );
            }

            THEN( "words with chars different from 'a, b, c' are not substrings of pattern" )
            {
                REQUIRE( trie_search("anam") == false);
                REQUIRE( trie_search("bama") == false);
                REQUIRE( trie_search("aman") == false);
                REQUIRE( trie_search("dana") == false);
            }
        }

        WHEN ( "pattern is equals a non-empty string" )
        {
            THEN( "each node corresponde to a unique substring of pattern" )
            {
                pattern = "banana";
                build_online(pattern);

                set<string> S;

                for (size_t i = 0; i < pattern.size(); ++i)
                for (size_t j = i; j < pattern.size(); ++j)
                    S.insert(pattern.substr(i, j - i + 1));

                REQUIRE( unique_substrings() == S.size() );

                pattern = "aaaaaaa";
                build_online(pattern);

                S.clear();

                for (size_t i = 0; i < pattern.size(); ++i)
                for (size_t j = i; j < pattern.size(); ++j)
                    S.insert(pattern.substr(i, j - i + 1));

                REQUIRE( unique_substrings() == S.size() );

                pattern = "abcdefghijklm";
                build_online(pattern);

                S.clear();

                for (size_t i = 0; i < pattern.size(); ++i)
                for (size_t j = i; j < pattern.size(); ++j)
                    S.insert(pattern.substr(i, j - i + 1));

                REQUIRE( unique_substrings() == S.size() );

                pattern = "ababababababababababababab";
                build_online(pattern);

                S.clear();

                for (size_t i = 0; i < pattern.size(); ++i)
                for (size_t j = i; j < pattern.size(); ++j)
                    S.insert(pattern.substr(i, j - i + 1));

                REQUIRE( unique_substrings() == S.size() );

                pattern = "a";
                build_online(pattern);

                S.clear();

                for (size_t i = 0; i < pattern.size(); ++i)
                for (size_t j = i; j < pattern.size(); ++j)
                    S.insert(pattern.substr(i, j - i + 1));

                REQUIRE( unique_substrings() == S.size() ); 
            }
        }
    }
}


