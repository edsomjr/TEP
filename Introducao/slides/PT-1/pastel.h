#ifndef PASTEL_H
#define PASTEL_H

#include "item.h" 

class Pastel : public Item {
public:
    Pastel(const string& sabor);
    
    string nome() const;
    float preco() const;
    
private:
    static const float _preco;
    string _sabor;
};

#endif
