#include "sortingbuttons.h"

SortingButtons::SortingButtons(QObject *parent) : QObject(parent), buttonGroup(new QButtonGroup) {
    // connect a sorting button being clicked to the handleButtonClick function.
    connect(buttonGroup, &QButtonGroup::buttonClicked, this, &SortingButtons::handleButtonClicked);
}

void SortingButtons::setTable(Table* _table) {
    table = _table;
}

void SortingButtons::addButtonToGroup(QPushButton *button) {
    buttonGroup->addButton(button);
    button->setStyleSheet(defaultStyle);
}

void SortingButtons::handleButtonClicked(QAbstractButton *button) {
    // Ensure all buttons have the default style
    foreach (QAbstractButton *btn, buttonGroup->buttons()) {
        btn->setStyleSheet(defaultStyle);
    }

    button->setStyleSheet(selectedStyle); // set the clicked button as active style
    selectedButtonName = button->objectName().toStdString();
    table->sortData(selectedButtonName); // sort based on attribute
}

std::string SortingButtons::getSelectedButtonName() {
    return selectedButtonName;
}
