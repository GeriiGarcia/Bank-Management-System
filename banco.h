#include "cuenta.h"


class banco
{
public:
    banco();
    ~banco();

    void crearCuenta(); 

private:
    vector <cuenta> cu[0];

};

banco::banco(/* args */)
{
}

banco::~banco()
{
}
