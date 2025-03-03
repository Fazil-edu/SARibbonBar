﻿#ifndef SARIBBONCATEGORYLAYOUT_H
#define SARIBBONCATEGORYLAYOUT_H
#include "SARibbonGlobal.h"
#include <QLayout>
#include <QList>
#include <QMap>
#include "SARibbonCategory.h"

class SARibbonPannel;
class SARibbonCategoryLayoutItem;
class SARibbonSeparatorWidget;
class SARibbonCategoryLayoutPrivate;

/**
 * @brief The SARibbonCategoryLayout class
 */
class SA_RIBBON_EXPORT SARibbonCategoryLayout : public QLayout
{
	Q_OBJECT
public:
	SARibbonCategoryLayout(SARibbonCategory *parent);
	~SARibbonCategoryLayout();

	SARibbonCategory *ribbonCategory();

	virtual void addItem(QLayoutItem *item) Q_DECL_OVERRIDE;
	virtual QLayoutItem *itemAt(int index) const Q_DECL_OVERRIDE;
	virtual QLayoutItem *takeAt(int index) Q_DECL_OVERRIDE;
	SARibbonCategoryLayoutItem *takePannelItem(int index);
	SARibbonCategoryLayoutItem *takePannel(SARibbonPannel *pannel);
	virtual int count() const Q_DECL_OVERRIDE;

	void addPannel(SARibbonPannel *pannel);

	void insertPannel(int index, SARibbonPannel *pannel);

	void setGeometry(const QRect& rect) Q_DECL_OVERRIDE;
	QSize sizeHint() const Q_DECL_OVERRIDE;
	QSize minimumSize() const Q_DECL_OVERRIDE;
	Qt::Orientations expandingDirections() const Q_DECL_OVERRIDE;
	void invalidate() Q_DECL_OVERRIDE;

	void updateGeometryArr();

	void doLayout();

	QList<SARibbonPannel *> pannels() const;

private slots:
	void onLeftScrollButtonClicked();
	void onRightScrollButtonClicked();

private:
	SARibbonCategoryLayoutPrivate *m_d;
};



/**
 * @brief SARibbonCategoryLayoutItem，SARibbonCategoryLayoutitem
 */
class SA_RIBBON_EXPORT SARibbonCategoryLayoutItem : public QWidgetItem
{
public:
	SARibbonCategoryLayoutItem(SARibbonPannel *w);
	SARibbonSeparatorWidget *separatorWidget;
	QRect mWillSetGeometry;                 ///< pannel,Geometry
	QRect mWillSetSeparatorGeometry;        ///< pannel,Separato,Geometry
};
#endif // SARIBBONCATEGORYLAYOUT_H
