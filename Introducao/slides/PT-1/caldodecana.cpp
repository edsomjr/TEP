#include "caldodecana.h" 

CaldoDeCana::CaldoDeCana(Quantidade qtd) : _qtd(qtd) { }

string CaldoDeCana::nome() const {
    string descricao = "Caldo de cana ";
    
    switch (_qtd) {
    case COPO_200_ML:
        return descricao + "200 ml";
    
    case COPO_300_ML:
        return descricao + "300 ml";
    
    case COPO_500_ML:
        return descricao + "500 ml";
    
    default:
        return descricao + "jarra 1L";
    }
}

float CaldoDeCana::preco() const {

    switch (_qtd) {
    case COPO_200_ML:
        return 1.5f;
    
    case COPO_300_ML:
        return 2.0f;
    
    case COPO_500_ML:
        return 3.0f;
    
    default:
        return 5.0f;
    }    
}
    
Quantidade CaldoDeCana::qtd() const {
    return _qtd;
}
