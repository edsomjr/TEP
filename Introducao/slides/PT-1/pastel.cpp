#include "pastel.h" 

const float Pastel::_preco = 2.50f;

Pastel::Pastel(const string& sabor) : _sabor(sabor)
{
}
    
string 
Pastel::nome() const
{
    return "Pastel de " + _sabor;
}

float 
Pastel::preco() const
{
    return _preco;
}
