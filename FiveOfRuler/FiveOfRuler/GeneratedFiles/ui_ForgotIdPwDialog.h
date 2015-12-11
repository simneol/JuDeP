/********************************************************************************
** Form generated from reading UI file 'ForgotIdPwDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORGOTIDPWDIALOG_H
#define UI_FORGOTIDPWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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

class Ui_ForgotIdPwDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *idLayout;
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *userButton;
    QRadioButton *technicianButton;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *emailLabel;
    QLineEdit *emailLineEdit;
    QLabel *questionLabel;
    QLineEdit *questionLineEdit;
    QPushButton *findButton;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *idRadioButton;
    QRadioButton *pwRadioButton;

    void setupUi(QDialog *ForgotIdPwDialog)
    {
        if (ForgotIdPwDialog->objectName().isEmpty())
            ForgotIdPwDialog->setObjectName(QStringLiteral("ForgotIdPwDialog"));
        ForgotIdPwDialog->resize(267, 234);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ForgotIdPwDialog->sizePolicy().hasHeightForWidth());
        ForgotIdPwDialog->setSizePolicy(sizePolicy);
        verticalLayoutWidget = new QWidget(ForgotIdPwDialog);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 50, 241, 171));
        idLayout = new QVBoxLayout(verticalLayoutWidget);
        idLayout->setObjectName(QStringLiteral("idLayout"));
        idLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(verticalLayoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 20, 211, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        userButton = new QRadioButton(horizontalLayoutWidget);
        userButton->setObjectName(QStringLiteral("userButton"));

        horizontalLayout->addWidget(userButton);

        technicianButton = new QRadioButton(horizontalLayoutWidget);
        technicianButton->setObjectName(QStringLiteral("technicianButton"));

        horizontalLayout->addWidget(technicianButton);

        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 70, 211, 58));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        emailLabel = new QLabel(formLayoutWidget);
        emailLabel->setObjectName(QStringLiteral("emailLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, emailLabel);

        emailLineEdit = new QLineEdit(formLayoutWidget);
        emailLineEdit->setObjectName(QStringLiteral("emailLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, emailLineEdit);

        questionLabel = new QLabel(formLayoutWidget);
        questionLabel->setObjectName(QStringLiteral("questionLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, questionLabel);

        questionLineEdit = new QLineEdit(formLayoutWidget);
        questionLineEdit->setObjectName(QStringLiteral("questionLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, questionLineEdit);


        idLayout->addWidget(groupBox);

        findButton = new QPushButton(verticalLayoutWidget);
        findButton->setObjectName(QStringLiteral("findButton"));

        idLayout->addWidget(findButton);

        horizontalLayoutWidget_2 = new QWidget(ForgotIdPwDialog);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 10, 248, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        idRadioButton = new QRadioButton(horizontalLayoutWidget_2);
        idRadioButton->setObjectName(QStringLiteral("idRadioButton"));
        idRadioButton->setChecked(true);

        horizontalLayout_2->addWidget(idRadioButton);

        pwRadioButton = new QRadioButton(horizontalLayoutWidget_2);
        pwRadioButton->setObjectName(QStringLiteral("pwRadioButton"));

        horizontalLayout_2->addWidget(pwRadioButton);


        retranslateUi(ForgotIdPwDialog);

        QMetaObject::connectSlotsByName(ForgotIdPwDialog);
    } // setupUi

    void retranslateUi(QDialog *ForgotIdPwDialog)
    {
        ForgotIdPwDialog->setWindowTitle(QApplication::translate("ForgotIdPwDialog", "Forgot ID / PW", 0));
        groupBox->setTitle(QApplication::translate("ForgotIdPwDialog", "User Information", 0));
        userButton->setText(QApplication::translate("ForgotIdPwDialog", "User", 0));
        technicianButton->setText(QApplication::translate("ForgotIdPwDialog", "Technician", 0));
        emailLabel->setText(QApplication::translate("ForgotIdPwDialog", "E-mail", 0));
        questionLabel->setText(QApplication::translate("ForgotIdPwDialog", "Question", 0));
        findButton->setText(QApplication::translate("ForgotIdPwDialog", "Find my ID/PW", 0));
        idRadioButton->setText(QApplication::translate("ForgotIdPwDialog", "ID", 0));
        pwRadioButton->setText(QApplication::translate("ForgotIdPwDialog", "PW", 0));
    } // retranslateUi

};

namespace Ui {
    class ForgotIdPwDialog: public Ui_ForgotIdPwDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORGOTIDPWDIALOG_H
