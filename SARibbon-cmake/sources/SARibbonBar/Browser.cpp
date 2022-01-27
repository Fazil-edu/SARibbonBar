#include "Browser.h"
#include <QDebug>
#include <QtCore/QVariant>
#include <QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QListView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "SARibbonMainWindow.h"
#include "SARibbonPannel.h"
#include <QStandardItemModel>
#include <QButtonGroup>
#include <QInputDialog>
#include <QLineEdit>
#include <QDateTime>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include "SARibbonCustomizeData.h"
#include "SARibbonBar.h"
#include <QFile>
#include <QMessageBox>
#include <QGroupBox>
#include <QSplitter>

////////////////////////////////////////////////////////////////////////////////////////////////////////
///SARibbonCustomizeWidget_2
////////////////////////////////////////////////////////////////////////////////////////////////////////


class BrowserUi
{
public:
	QPushButton * submitButton;
	QPushButton * clearButton;
	QTableView * tableView;
	QSplitter * splitter;
	QTextEdit * sqlTexttEdit;
	QGroupBox * submitClearTextEditGb;
	QHBoxLayout * submitAndClearButtonLayout;
	QVBoxLayout * submitClearTextEditGbLayout;
	QVBoxLayout * mainLayout;
	QMenu * helpMenu;

	void setupUi(QWidget *Browser)
	{
		if (Browser->objectName().isEmpty()) {
			Browser->setObjectName(QStringLiteral("Browser"));
		}
		Browser->resize(800, 600);
		mainLayout = new QVBoxLayout(Browser);
		mainLayout->setObjectName(QStringLiteral("mainLayout"));
		
		submitAndClearButtonLayout = new QHBoxLayout();
		submitAndClearButtonLayout->setObjectName(QStringLiteral("submitAndClearButtonLayout"));
		
		sqlTexttEdit = new QTextEdit(Browser);
		sqlTexttEdit->setObjectName(QStringLiteral("sqlTexttEdit"));
		
		submitButton = new QPushButton(Browser);
		submitButton->setObjectName(QStringLiteral("submitButton"));

		clearButton = new QPushButton(Browser);
		clearButton->setObjectName(QStringLiteral("clearButton"));

		submitClearTextEditGb = new QGroupBox(Browser);
		submitClearTextEditGb->setObjectName(QStringLiteral("submitClearTextEditGb"));
		submitClearTextEditGb->setTitle("SQL Query");
		
		submitClearTextEditGbLayout = new QVBoxLayout();

		tableView = new QTableView(Browser);
		tableView->setObjectName(QStringLiteral("tableViewSelect"));

		splitter = new QSplitter();
		
		submitAndClearButtonLayout->addWidget(submitButton);
		submitAndClearButtonLayout->addWidget(clearButton);
		submitClearTextEditGbLayout->addWidget(sqlTexttEdit);
		submitClearTextEditGbLayout->addLayout(submitAndClearButtonLayout);
		submitClearTextEditGb->setLayout(submitClearTextEditGbLayout);
		
		splitter->addWidget(tableView);
		mainLayout->addWidget(splitter);
		mainLayout->addWidget(submitClearTextEditGb);
		retranslateUi(Browser);
	} // setupUi


	void retranslateUi(QWidget *browserWidget)
	{
		browserWidget->setWindowTitle("Qt SQL Browser");
		sqlTexttEdit->setText(QString());
		submitButton->setText("Submit");
		clearButton->setText("Clear");
	} 
};



Browser::Browser(SARibbonMainWindow *ribbonWindow, QWidget *parent, Qt::WindowFlags f) : QWidget(parent, f)
, ui(new BrowserUi)

{
	ui->setupUi(this);
	initConnection();
}

Browser::~Browser()
{
	delete ui;
}

void Browser::initConnection()
{
	//connect(ui->comboBoxActionIndex, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged)
	//	, this, &SARibbonCustomizeWidget_2::onComboBoxActionIndexCurrentIndexChanged);
	//    connect(ui->radioButtonGroup, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked)
	//        , this, &SARibbonCustomizeWidget_2::onRadioButtonGroupButtonClicked);
	//connect(ui->radioButtonGroup, static_cast<void (QButtonGroup::*)(QAbstractButton *)>(&QButtonGroup::buttonClicked)
	//	, this, &SARibbonCustomizeWidget_2::onRadioButtonGroupButtonClicked);
	//connect(ui->pushButtonNewCategory, &QPushButton::clicked
	//	, this, &SARibbonCustomizeWidget_2::onPushButtonNewCategoryClicked);
	//connect(ui->pushButtonNewPannel, &QPushButton::clicked
	//	, this, &SARibbonCustomizeWidget_2::onPushButtonNewPannelClicked);
	//connect(ui->submitButton, &QPushButton::clicked
	//	, this, &SARibbonCustomizeWidget_2::onPushButtonRenameClicked);
	//connect(ui->pushButtonAdd, &QPushButton::clicked
	//	, this, &SARibbonCustomizeWidget_2::onPushButtonAddClicked);
	//connect(ui->pushButtonDelete, &QPushButton::clicked
	//	, this, &SARibbonCustomizeWidget_2::onPushButtonDeleteClicked);
	//connect(ui->listViewSelect, &QAbstractItemView::clicked
	//	, this, &SARibbonCustomizeWidget_2::onListViewSelectClicked);
	//connect(ui->treeViewResult, &QAbstractItemView::clicked
	//	, this, &SARibbonCustomizeWidget_2::onTreeViewResultClicked);
	//connect(ui->toolButtonUp, &QToolButton::clicked
	//	, this, &SARibbonCustomizeWidget_2::onToolButtonUpClicked);
	//connect(ui->toolButtonDown, &QToolButton::clicked
	//	, this, &SARibbonCustomizeWidget_2::onToolButtonDownClicked);
	//connect(m_d->mRibbonModel, &QStandardItemModel::itemChanged
	//	, this, &SARibbonCustomizeWidget_2::onItemChanged);
	//connect(ui->lineEditSearchAction, &QLineEdit::textEdited
	//	, this, &SARibbonCustomizeWidget_2::onLineEditSearchActionTextEdited);
	//connect(ui->pushButtonReset, &QPushButton::clicked
	//	, this, &SARibbonCustomizeWidget_2::onPushButtonResetClicked);
}