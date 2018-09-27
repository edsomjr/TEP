#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item {
public:
    virtual ~Item() {}

    virtual string nome() const = 0;
    virtual float preco() const = 0;
};

#endif
