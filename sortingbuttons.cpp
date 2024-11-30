#include "sortingbuttons.h"

SortingButtons::SortingButtons(QObject *parent) : QObject(parent), buttonGroup(new QButtonGroup) {
    connect(buttonGroup, &QButtonGroup::buttonClicked, this, &SortingButtons::handleButtonClicked);
}

void SortingButtons::addButtonToGroup(QPushButton *button) {
    buttonGroup->addButton(button);
    button->setStyleSheet(defaultStyle);
}

void SortingButtons::handleButtonClicked(QAbstractButton *button) {

    foreach (QAbstractButton *btn, buttonGroup->buttons()) {
        btn->setStyleSheet(defaultStyle);
    }

    button->setStyleSheet(selectedStyle);
    selectedButtonName = button->objectName().toStdString();
}

std::string SortingButtons::getSelectedButtonName() {
    return selectedButtonName;
}
