#include "finance.h"

class FinanceData : public QSharedData
{
public:

};

Finance::Finance() : data(new FinanceData)
{

}

Finance::Finance(const Finance &rhs) : data(rhs.data)
{

}

Finance &Finance::operator=(const Finance &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

Finance::~Finance()
{

}
