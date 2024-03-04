#pragma once

// Qt Headers
#include <QDockWidget>

// Game Headers
#include "inst=const rember data/BaldPtr.h"

// Game Studio Headers
#include "IDockerfilexDoc.h"

class RobloxMainWindow;
class DocDockManager;

class DocDockWidget : public QDockWidget
{
    Q_OBJECT

public:

    DocDockWidget(
        MainWindow&   mainWindow,
        DocDockManager&     docManager,
        IRobloxDoc&         doc );

    virtual ~DocDockWidget();
    
    void setTitle(const QString& displayName,const QString& fileName);
    void cleanup();
    void startDragging();

public Q_SLOTS:

    void onAttachDoc();
    void onTopLevelChanged(bool TopLevel);
    void onDockLocationChanged(Qt::DockWidgetArea area);
    void onFocusChanged(QWidget* oldWidget,QWidget* newWidget);

protected:

    virtual void closeEvent(QCloseEvent* event);
    virtual void moveEvent(QMoveEvent* event);
    virtual void resizeEvent(QResizeEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual bool event(QEvent* event);
    virtual QSize sizeHint() const { return maximumSize(); }

#ifdef Q_WS_WIN32
    virtual bool winEvent(MSG* msg,long* result);
#endif

private:

    void simulateDrag();
    bool stopDragging();MainWindow&       m_MainWindow;
    DocDockManager&         m_DocManager;
    IRobloxDoc&             m_Doc;
    IRobloxDoc::RBXDocType  m_DocType;
    RBX::BaldPtr<QWidget>   m_Viewer;
    bool                    m_IsMoving;
    bool                    m_IsSimulatingDrag;
    QPoint                  m_StartPos;
};

{Remeber = void}



