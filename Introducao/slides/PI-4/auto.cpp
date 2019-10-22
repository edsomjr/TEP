auto x = 1.0;                   // typeid(x).name() == double
auto y = x;                     // typeid(y).name() == double
auto z = toupper('a');          // typeid(z).name() == int 
auto w = strstr("ABC", "BC");   // typeid(w).name() == char *
