/********************************************************************************
** Form generated from reading UI file 'QNAWriteDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QNAWRITEDIALOG_H
#define UI_QNAWRITEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_QNAWriteDialog
{
public:
    QDialogButtonBox *sendcansel;
    QScrollBar *scroll;
    QLabel *label;
    QLineEdit *head;
    QTextEdit *content;

    void setupUi(QDialog *QNAWriteDialog)
    {
        if (QNAWriteDialog->objectName().isEmpty())
            QNAWriteDialog->setObjectName(QStringLiteral("QNAWriteDialog"));
        QNAWriteDialog->resize(400, 354);
        sendcansel = new QDialogButtonBox(QNAWriteDialog);
        sendcansel->setObjectName(QStringLiteral("sendcansel"));
        sendcansel->setGeometry(QRect(230, 300, 156, 23));
        sendcansel->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        scroll = new QScrollBar(QNAWriteDialog);
        scroll->setObjectName(QStringLiteral("scroll"));
        scroll->setGeometry(QRect(330, 90, 20, 191));
        scroll->setAcceptDrops(false);
        scroll->setAutoFillBackground(false);
        scroll->setOrientation(Qt::Vertical);
        label = new QLabel(QNAWriteDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 56, 12));
        head = new QLineEdit(QNAWriteDialog);
        head->setObjectName(QStringLiteral("head"));
        head->setGeometry(QRect(60, 60, 291, 20));
        content = new QTextEdit(QNAWriteDialog);
        content->setObjectName(QStringLiteral("content"));
        content->setGeometry(QRect(60, 90, 271, 191));

        retranslateUi(QNAWriteDialog);

        QMetaObject::connectSlotsByName(QNAWriteDialog);
    } // setupUi

    void retranslateUi(QDialog *QNAWriteDialog)
    {
        QNAWriteDialog->setWindowTitle(QApplication::translate("QNAWriteDialog", "Dialog", 0));
        label->setText(QApplication::translate("QNAWriteDialog", "QnA", 0));
    } // retranslateUi

};

namespace Ui {
    class QNAWriteDialog: public Ui_QNAWriteDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QNAWRITEDIALOG_H
