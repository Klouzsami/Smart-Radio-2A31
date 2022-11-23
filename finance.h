#ifndef FINANCE_H
#define FINANCE_H

#include <QDeclarativeItem>
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class FinanceData;

class Finance
{
    Q_OBJECT
public:
    Finance();
    Finance(const Finance &);
    Finance &operator=(const Finance &);
    ~Finance();

private:
    QSharedDataPointer<FinanceData> data;
};

#endif // FINANCE_H
