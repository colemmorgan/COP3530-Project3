#ifndef SORTINGBUTTONS_H
#define SORTINGBUTTONS_H

#include <QButtonGroup>
#include <QPushButton>
#include <QWidget>

class SortingButtons : public QObject
{
public:
    SortingButtons(QObject *parent = nullptr);
    void addButtonToGroup(QPushButton *button);


private slots:
    void handleButtonClicked(QAbstractButton *button);
private:
    QButtonGroup *buttonGroup;
    const QString defaultStyle = "background-color: #; color: white; border-right: 1px solid #505050;";
    const QString selectedStyle = "background-color: #006F88; color: white; border-right: 1px solid #242424;";
};

#endif // SORTINGBUTTONS_H
