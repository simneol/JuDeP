/********************************************************************************
** Form generated from reading UI file 'RegisterDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *typeGroupBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *userRadioButton;
    QRadioButton *technicianButton;
    QGroupBox *infoGroupBox;
    QWidget *formLayoutWidget;
    QFormLayout *infoLayout;
    QLabel *idLabel;
    QLabel *pwLabel;
    QLabel *nameLabel;
    QLabel *dateLabel;
    QLabel *questionLabel;
    QLabel *answerLabel;
    QLabel *addressLabel;
    QLabel *emailLabel;
    QLineEdit *pwLineEdit;
    QLineEdit *emailLineEdit;
    QComboBox *questionComboBox;
    QLineEdit *answerLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *idLineEdit;
    QPushButton *idDuplicationCheck;
    QPushButton *registerButton;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName(QStringLiteral("RegisterDialog"));
        RegisterDialog->resize(414, 505);
        verticalLayoutWidget = new QWidget(RegisterDialog);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 391, 491));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        typeGroupBox = new QGroupBox(verticalLayoutWidget);
        typeGroupBox->setObjectName(QStringLiteral("typeGroupBox"));
        horizontalLayoutWidget = new QWidget(typeGroupBox);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 20, 331, 33));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        userRadioButton = new QRadioButton(horizontalLayoutWidget);
        userRadioButton->setObjectName(QStringLiteral("userRadioButton"));
        userRadioButton->setChecked(true);

        horizontalLayout->addWidget(userRadioButton);

        technicianButton = new QRadioButton(horizontalLayoutWidget);
        technicianButton->setObjectName(QStringLiteral("technicianButton"));

        horizontalLayout->addWidget(technicianButton);

        infoGroupBox = new QGroupBox(typeGroupBox);
        infoGroupBox->setObjectName(QStringLiteral("infoGroupBox"));
        infoGroupBox->setGeometry(QRect(10, 60, 371, 381));
        formLayoutWidget = new QWidget(infoGroupBox);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 30, 351, 341));
        infoLayout = new QFormLayout(formLayoutWidget);
        infoLayout->setObjectName(QStringLiteral("infoLayout"));
        infoLayout->setContentsMargins(0, 0, 0, 0);
        idLabel = new QLabel(formLayoutWidget);
        idLabel->setObjectName(QStringLiteral("idLabel"));

        infoLayout->setWidget(0, QFormLayout::LabelRole, idLabel);

        pwLabel = new QLabel(formLayoutWidget);
        pwLabel->setObjectName(QStringLiteral("pwLabel"));

        infoLayout->setWidget(1, QFormLayout::LabelRole, pwLabel);

        nameLabel = new QLabel(formLayoutWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        infoLayout->setWidget(2, QFormLayout::LabelRole, nameLabel);

        dateLabel = new QLabel(formLayoutWidget);
        dateLabel->setObjectName(QStringLiteral("dateLabel"));

        infoLayout->setWidget(3, QFormLayout::LabelRole, dateLabel);

        questionLabel = new QLabel(formLayoutWidget);
        questionLabel->setObjectName(QStringLiteral("questionLabel"));

        infoLayout->setWidget(4, QFormLayout::LabelRole, questionLabel);

        answerLabel = new QLabel(formLayoutWidget);
        answerLabel->setObjectName(QStringLiteral("answerLabel"));

        infoLayout->setWidget(5, QFormLayout::LabelRole, answerLabel);

        addressLabel = new QLabel(formLayoutWidget);
        addressLabel->setObjectName(QStringLiteral("addressLabel"));

        infoLayout->setWidget(6, QFormLayout::LabelRole, addressLabel);

        emailLabel = new QLabel(formLayoutWidget);
        emailLabel->setObjectName(QStringLiteral("emailLabel"));

        infoLayout->setWidget(7, QFormLayout::LabelRole, emailLabel);

        pwLineEdit = new QLineEdit(formLayoutWidget);
        pwLineEdit->setObjectName(QStringLiteral("pwLineEdit"));
        pwLineEdit->setEchoMode(QLineEdit::Password);

        infoLayout->setWidget(1, QFormLayout::FieldRole, pwLineEdit);

        emailLineEdit = new QLineEdit(formLayoutWidget);
        emailLineEdit->setObjectName(QStringLiteral("emailLineEdit"));

        infoLayout->setWidget(7, QFormLayout::FieldRole, emailLineEdit);

        questionComboBox = new QComboBox(formLayoutWidget);
        questionComboBox->setObjectName(QStringLiteral("questionComboBox"));

        infoLayout->setWidget(4, QFormLayout::FieldRole, questionComboBox);

        answerLineEdit = new QLineEdit(formLayoutWidget);
        answerLineEdit->setObjectName(QStringLiteral("answerLineEdit"));

        infoLayout->setWidget(5, QFormLayout::FieldRole, answerLineEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        idLineEdit = new QLineEdit(formLayoutWidget);
        idLineEdit->setObjectName(QStringLiteral("idLineEdit"));

        horizontalLayout_2->addWidget(idLineEdit);

        idDuplicationCheck = new QPushButton(formLayoutWidget);
        idDuplicationCheck->setObjectName(QStringLiteral("idDuplicationCheck"));

        horizontalLayout_2->addWidget(idDuplicationCheck);


        infoLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout_2);


        verticalLayout->addWidget(typeGroupBox);

        registerButton = new QPushButton(verticalLayoutWidget);
        registerButton->setObjectName(QStringLiteral("registerButton"));

        verticalLayout->addWidget(registerButton);

        QWidget::setTabOrder(userRadioButton, technicianButton);
        QWidget::setTabOrder(technicianButton, pwLineEdit);
        QWidget::setTabOrder(pwLineEdit, questionComboBox);
        QWidget::setTabOrder(questionComboBox, answerLineEdit);
        QWidget::setTabOrder(answerLineEdit, emailLineEdit);
        QWidget::setTabOrder(emailLineEdit, registerButton);

        retranslateUi(RegisterDialog);

        questionComboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QApplication::translate("RegisterDialog", "RegisterDialog", 0));
        typeGroupBox->setTitle(QApplication::translate("RegisterDialog", "RegisterType", 0));
        userRadioButton->setText(QApplication::translate("RegisterDialog", "User", 0));
        technicianButton->setText(QApplication::translate("RegisterDialog", "Technician", 0));
        infoGroupBox->setTitle(QApplication::translate("RegisterDialog", "Infomation", 0));
        idLabel->setText(QApplication::translate("RegisterDialog", "ID", 0));
        pwLabel->setText(QApplication::translate("RegisterDialog", "Password", 0));
        nameLabel->setText(QApplication::translate("RegisterDialog", "Name", 0));
        dateLabel->setText(QApplication::translate("RegisterDialog", "Date Of Birth", 0));
        questionLabel->setText(QApplication::translate("RegisterDialog", "Question", 0));
        answerLabel->setText(QApplication::translate("RegisterDialog", "Answer", 0));
        addressLabel->setText(QApplication::translate("RegisterDialog", "Address", 0));
        emailLabel->setText(QApplication::translate("RegisterDialog", "E-mail", 0));
        questionComboBox->clear();
        questionComboBox->insertItems(0, QStringList()
         << QApplication::translate("RegisterDialog", "\353\202\264 \354\226\264\353\240\270\354\235\204 \354\240\201 \353\263\204\353\252\205\354\235\200?", 0)
         << QApplication::translate("RegisterDialog", "\353\202\264\352\260\200 \353\213\244\353\205\224\353\215\230 \354\264\210\353\223\261\355\225\231\352\265\220 \354\235\264\353\246\204\354\235\200?", 0)
         << QApplication::translate("RegisterDialog", "\353\202\264 \353\263\264\353\254\274 1\355\230\270\353\212\224?", 0)
        );
        questionComboBox->setCurrentText(QApplication::translate("RegisterDialog", "\353\202\264 \354\226\264\353\240\270\354\235\204 \354\240\201 \353\263\204\353\252\205\354\235\200?", 0));
        idDuplicationCheck->setText(QApplication::translate("RegisterDialog", "Chk!", 0));
        registerButton->setText(QApplication::translate("RegisterDialog", "Register !", 0));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
