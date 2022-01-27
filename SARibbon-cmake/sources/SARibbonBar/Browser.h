#ifndef Browser_H
#define Browser_H
#include "SARibbonGlobal.h"
#include <QWidget>


class BrowserUi;
class SARibbonMainWindow;


class SA_RIBBON_EXPORT Browser : public QWidget
{
	Q_OBJECT
public:
	Browser(SARibbonMainWindow *ribbonWindow, QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
	~Browser();

private:
	void initConnection();

	BrowserUi *ui;
};
#endif // Browser_H
