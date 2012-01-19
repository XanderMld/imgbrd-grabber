/********************************************************************************
** Form generated from reading UI file 'searchtab.ui'
**
** Created: Thu 19. Jan 20:10:09 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHTAB_H
#define UI_SEARCHTAB_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QSplitter>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_searchTab
{
public:
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelTags;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *layoutFields;
    QLabel *label;
    QPushButton *buttonSearch;
    QSpinBox *spinPage;
    QPushButton *buttonTags;
    QPushButton *pushButton;
    QWidget *widgetMeant;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *labelMeant;
    QWidget *widgetPlus;
    QGridLayout *layoutPlus;
    QSpinBox *spinColumns;
    QHBoxLayout *layoutSourcesList;
    QLabel *label_7;
    QLabel *label_8;
    QSpinBox *spinImagesPerPage;
    QLabel *label_6;
    QVBoxLayout *verticalLayout;
    QGridLayout *layoutResults;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonFirstPage;
    QPushButton *buttonPreviousPage;
    QPushButton *buttonSourcesList;
    QCheckBox *checkMergeResults;
    QLabel *labelMergeResults;
    QPushButton *buttonGetpage;
    QPushButton *buttonNextPage;
    QPushButton *buttonLastPage;

    void setupUi(QWidget *searchTab)
    {
        if (searchTab->objectName().isEmpty())
            searchTab->setObjectName(QString::fromUtf8("searchTab"));
        searchTab->resize(798, 531);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(searchTab->sizePolicy().hasHeightForWidth());
        searchTab->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        searchTab->setWindowIcon(icon);
        verticalLayout_2 = new QVBoxLayout(searchTab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        splitter = new QSplitter(searchTab);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        scrollArea = new QScrollArea(splitter);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setLineWidth(0);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 16, 496));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy1);
        scrollAreaWidgetContents->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        labelTags = new QLabel(scrollAreaWidgetContents);
        labelTags->setObjectName(QString::fromUtf8("labelTags"));
        sizePolicy1.setHeightForWidth(labelTags->sizePolicy().hasHeightForWidth());
        labelTags->setSizePolicy(sizePolicy1);
        labelTags->setContextMenuPolicy(Qt::CustomContextMenu);
        labelTags->setText(QString::fromUtf8(""));
        labelTags->setTextFormat(Qt::RichText);

        verticalLayout_3->addWidget(labelTags);

        scrollArea->setWidget(scrollAreaWidgetContents);
        splitter->addWidget(scrollArea);
        widget_2 = new QWidget(splitter);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        verticalLayout_4 = new QVBoxLayout(widget_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(9, 0, 0, 0);
        layoutFields = new QHBoxLayout();
        layoutFields->setSpacing(6);
        layoutFields->setObjectName(QString::fromUtf8("layoutFields"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        layoutFields->addWidget(label);

        buttonSearch = new QPushButton(widget_2);
        buttonSearch->setObjectName(QString::fromUtf8("buttonSearch"));

        layoutFields->addWidget(buttonSearch);

        spinPage = new QSpinBox(widget_2);
        spinPage->setObjectName(QString::fromUtf8("spinPage"));
        spinPage->setMinimumSize(QSize(60, 0));
        spinPage->setMinimum(1);
        spinPage->setMaximum(1000);

        layoutFields->addWidget(spinPage);

        buttonTags = new QPushButton(widget_2);
        buttonTags->setObjectName(QString::fromUtf8("buttonTags"));

        layoutFields->addWidget(buttonTags);

        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(30, 16777215));
        pushButton->setCheckable(true);

        layoutFields->addWidget(pushButton);


        verticalLayout_4->addLayout(layoutFields);

        widgetMeant = new QWidget(widget_2);
        widgetMeant->setObjectName(QString::fromUtf8("widgetMeant"));
        horizontalLayout_2 = new QHBoxLayout(widgetMeant);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widgetMeant);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        labelMeant = new QLabel(widgetMeant);
        labelMeant->setObjectName(QString::fromUtf8("labelMeant"));
        labelMeant->setText(QString::fromUtf8(""));
        labelMeant->setTextFormat(Qt::RichText);

        horizontalLayout_2->addWidget(labelMeant);

        horizontalLayout_2->setStretch(1, 1);

        verticalLayout_4->addWidget(widgetMeant);

        widgetPlus = new QWidget(widget_2);
        widgetPlus->setObjectName(QString::fromUtf8("widgetPlus"));
        widgetPlus->setEnabled(true);
        widgetPlus->setStyleSheet(QString::fromUtf8("#widgetPlus { border: 1px solid #bbb; border-radius: 5px; }"));
        layoutPlus = new QGridLayout(widgetPlus);
        layoutPlus->setObjectName(QString::fromUtf8("layoutPlus"));
        spinColumns = new QSpinBox(widgetPlus);
        spinColumns->setObjectName(QString::fromUtf8("spinColumns"));
        spinColumns->setMinimum(1);
        spinColumns->setMaximum(10);

        layoutPlus->addWidget(spinColumns, 0, 3, 1, 1);

        layoutSourcesList = new QHBoxLayout();
        layoutSourcesList->setObjectName(QString::fromUtf8("layoutSourcesList"));

        layoutPlus->addLayout(layoutSourcesList, 2, 0, 1, 4);

        label_7 = new QLabel(widgetPlus);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        layoutPlus->addWidget(label_7, 0, 2, 1, 1);

        label_8 = new QLabel(widgetPlus);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        layoutPlus->addWidget(label_8, 1, 0, 1, 1);

        spinImagesPerPage = new QSpinBox(widgetPlus);
        spinImagesPerPage->setObjectName(QString::fromUtf8("spinImagesPerPage"));
        spinImagesPerPage->setMinimum(1);
        spinImagesPerPage->setMaximum(1000);
        spinImagesPerPage->setValue(20);

        layoutPlus->addWidget(spinImagesPerPage, 0, 1, 1, 1);

        label_6 = new QLabel(widgetPlus);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        layoutPlus->addWidget(label_6, 0, 0, 1, 1);


        verticalLayout_4->addWidget(widgetPlus);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        layoutResults = new QGridLayout();
        layoutResults->setObjectName(QString::fromUtf8("layoutResults"));

        verticalLayout->addLayout(layoutResults);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_4->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        buttonFirstPage = new QPushButton(widget_2);
        buttonFirstPage->setObjectName(QString::fromUtf8("buttonFirstPage"));
        buttonFirstPage->setEnabled(false);
        buttonFirstPage->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(buttonFirstPage);

        buttonPreviousPage = new QPushButton(widget_2);
        buttonPreviousPage->setObjectName(QString::fromUtf8("buttonPreviousPage"));
        buttonPreviousPage->setEnabled(false);
        buttonPreviousPage->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(buttonPreviousPage);

        buttonSourcesList = new QPushButton(widget_2);
        buttonSourcesList->setObjectName(QString::fromUtf8("buttonSourcesList"));

        horizontalLayout->addWidget(buttonSourcesList);

        checkMergeResults = new QCheckBox(widget_2);
        checkMergeResults->setObjectName(QString::fromUtf8("checkMergeResults"));
        checkMergeResults->setChecked(true);

        horizontalLayout->addWidget(checkMergeResults);

        labelMergeResults = new QLabel(widget_2);
        labelMergeResults->setObjectName(QString::fromUtf8("labelMergeResults"));

        horizontalLayout->addWidget(labelMergeResults);

        buttonGetpage = new QPushButton(widget_2);
        buttonGetpage->setObjectName(QString::fromUtf8("buttonGetpage"));

        horizontalLayout->addWidget(buttonGetpage);

        buttonNextPage = new QPushButton(widget_2);
        buttonNextPage->setObjectName(QString::fromUtf8("buttonNextPage"));
        buttonNextPage->setEnabled(false);
        buttonNextPage->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(buttonNextPage);

        buttonLastPage = new QPushButton(widget_2);
        buttonLastPage->setObjectName(QString::fromUtf8("buttonLastPage"));
        buttonLastPage->setEnabled(false);
        buttonLastPage->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(buttonLastPage);

        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(4, 1);
        horizontalLayout->setStretch(5, 1);

        verticalLayout_4->addLayout(horizontalLayout);

        splitter->addWidget(widget_2);

        verticalLayout_2->addWidget(splitter);

        QWidget::setTabOrder(scrollArea, buttonSearch);
        QWidget::setTabOrder(buttonSearch, spinPage);
        QWidget::setTabOrder(spinPage, buttonTags);
        QWidget::setTabOrder(buttonTags, pushButton);
        QWidget::setTabOrder(pushButton, spinImagesPerPage);
        QWidget::setTabOrder(spinImagesPerPage, spinColumns);
        QWidget::setTabOrder(spinColumns, buttonFirstPage);
        QWidget::setTabOrder(buttonFirstPage, buttonPreviousPage);
        QWidget::setTabOrder(buttonPreviousPage, buttonSourcesList);
        QWidget::setTabOrder(buttonSourcesList, checkMergeResults);
        QWidget::setTabOrder(checkMergeResults, buttonGetpage);
        QWidget::setTabOrder(buttonGetpage, buttonNextPage);
        QWidget::setTabOrder(buttonNextPage, buttonLastPage);

        retranslateUi(searchTab);
        QObject::connect(buttonGetpage, SIGNAL(clicked()), searchTab, SLOT(getPage()));
        QObject::connect(buttonTags, SIGNAL(clicked()), searchTab, SLOT(load()));
        QObject::connect(buttonSourcesList, SIGNAL(clicked()), searchTab, SLOT(openSourcesWindow()));
        QObject::connect(labelTags, SIGNAL(linkHovered(QString)), searchTab, SLOT(linkHovered(QString)));
        QObject::connect(labelTags, SIGNAL(customContextMenuRequested(QPoint)), searchTab, SLOT(contextMenu()));
        QObject::connect(labelTags, SIGNAL(linkActivated(QString)), searchTab, SLOT(linkClicked(QString)));
        QObject::connect(buttonNextPage, SIGNAL(clicked()), searchTab, SLOT(nextPage()));
        QObject::connect(buttonLastPage, SIGNAL(clicked()), searchTab, SLOT(lastPage()));
        QObject::connect(buttonPreviousPage, SIGNAL(clicked()), searchTab, SLOT(previousPage()));
        QObject::connect(buttonFirstPage, SIGNAL(clicked()), searchTab, SLOT(firstPage()));
        QObject::connect(pushButton, SIGNAL(clicked(bool)), widgetPlus, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(searchTab);
    } // setupUi

    void retranslateUi(QWidget *searchTab)
    {
        searchTab->setWindowTitle(QApplication::translate("searchTab", "Nouvel onglet", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("searchTab", "Recherche", 0, QApplication::UnicodeUTF8));
        buttonSearch->setText(QApplication::translate("searchTab", "Plus", 0, QApplication::UnicodeUTF8));
        buttonTags->setText(QApplication::translate("searchTab", "Ok", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("searchTab", "+", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("searchTab", "Peut-\303\252tre avez-vous voulu dire :", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("searchTab", "Nombre de colonnes", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("searchTab", "Post-filtrage", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("searchTab", "Images par page", 0, QApplication::UnicodeUTF8));
        buttonFirstPage->setText(QApplication::translate("searchTab", "<<", 0, QApplication::UnicodeUTF8));
        buttonPreviousPage->setText(QApplication::translate("searchTab", "<", 0, QApplication::UnicodeUTF8));
        buttonSourcesList->setText(QApplication::translate("searchTab", "Sources", 0, QApplication::UnicodeUTF8));
        checkMergeResults->setText(QApplication::translate("searchTab", "Fusionner les r\303\251sultats", 0, QApplication::UnicodeUTF8));
        labelMergeResults->setText(QString());
        buttonGetpage->setText(QApplication::translate("searchTab", "Prendre cette page", 0, QApplication::UnicodeUTF8));
        buttonNextPage->setText(QApplication::translate("searchTab", ">", 0, QApplication::UnicodeUTF8));
        buttonLastPage->setText(QApplication::translate("searchTab", ">>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class searchTab: public Ui_searchTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHTAB_H
