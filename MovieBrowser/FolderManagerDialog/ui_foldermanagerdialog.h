/********************************************************************************
** Form generated from reading UI file 'foldermanagerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOLDERMANAGERDIALOG_H
#define UI_FOLDERMANAGERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FolderManagerDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTreeView *treeDirView;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QRadioButton *radioButton_monitoring_on;
    QRadioButton *radioButton_monitoring_off;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QDialogButtonBox *dialogButtonBox;
    QButtonGroup *monitorButtonGroup;

    void setupUi(QDialog *FolderManagerDialog)
    {
        if (FolderManagerDialog->objectName().isEmpty())
            FolderManagerDialog->setObjectName(QString::fromUtf8("FolderManagerDialog"));
        FolderManagerDialog->resize(573, 442);
        layoutWidget = new QWidget(FolderManagerDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 528, 361));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        treeDirView = new QTreeView(layoutWidget);
        treeDirView->setObjectName(QString::fromUtf8("treeDirView"));

        verticalLayout->addWidget(treeDirView);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        radioButton_monitoring_on = new QRadioButton(layoutWidget);
        monitorButtonGroup = new QButtonGroup(FolderManagerDialog);
        monitorButtonGroup->setObjectName(QString::fromUtf8("monitorButtonGroup"));
        monitorButtonGroup->addButton(radioButton_monitoring_on);
        radioButton_monitoring_on->setObjectName(QString::fromUtf8("radioButton_monitoring_on"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon/arrow_refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioButton_monitoring_on->setIcon(icon);

        verticalLayout_2->addWidget(radioButton_monitoring_on);

        radioButton_monitoring_off = new QRadioButton(layoutWidget);
        monitorButtonGroup->addButton(radioButton_monitoring_off);
        radioButton_monitoring_off->setObjectName(QString::fromUtf8("radioButton_monitoring_off"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/icon/cross.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioButton_monitoring_off->setIcon(icon1);

        verticalLayout_2->addWidget(radioButton_monitoring_off);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout_3->addWidget(listWidget);


        verticalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout_2->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(308, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        dialogButtonBox = new QDialogButtonBox(layoutWidget);
        dialogButtonBox->setObjectName(QString::fromUtf8("dialogButtonBox"));
        dialogButtonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_3->addWidget(dialogButtonBox);


        verticalLayout_5->addLayout(horizontalLayout_3);


        retranslateUi(FolderManagerDialog);

        QMetaObject::connectSlotsByName(FolderManagerDialog);
    } // setupUi

    void retranslateUi(QDialog *FolderManagerDialog)
    {
        FolderManagerDialog->setWindowTitle(QCoreApplication::translate("FolderManagerDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("FolderManagerDialog", "\343\203\225\343\202\251\343\203\253\343\203\200\343\203\252\343\202\271\343\203\210", nullptr));
        label_2->setText(QCoreApplication::translate("FolderManagerDialog", "\351\201\270\346\212\236\343\201\225\343\202\214\343\201\237\343\203\225\343\202\251\343\203\253\343\203\200", nullptr));
        radioButton_monitoring_on->setText(QCoreApplication::translate("FolderManagerDialog", "\345\270\270\346\231\202\347\233\243\350\246\226", nullptr));
        radioButton_monitoring_off->setText(QCoreApplication::translate("FolderManagerDialog", "\347\233\243\350\246\226\343\201\213\343\202\211\345\244\226\343\201\231", nullptr));
        label_3->setText(QCoreApplication::translate("FolderManagerDialog", "\347\233\243\350\246\226\343\203\225\343\202\251\343\203\253\343\203\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FolderManagerDialog: public Ui_FolderManagerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOLDERMANAGERDIALOG_H
