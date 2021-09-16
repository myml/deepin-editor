#include "ut_window.h"
#include "dsettingsoption.h"
#include "ddialog.h"
test_window::test_window()
{

}

TEST_F(test_window, Window)
{
    Window window1;
    
}

int option_stub_para=0;
QPointer<DSettingsOption> option_stub()
{
    QPointer<DSettingsOption> p = new DSettingsOption;
    if(option_stub_para==0)
        p->setValue("window_maximum");
    else if(option_stub_para==1)
        p->setValue("fullscreen");
    else
        p->setValue("normal");
    return p;
}
TEST_F(test_window, showCenterWindow_01)
{
    Stub stub;
    stub.set(ADDR(DSettings,option),option_stub);

    Window * window1 = new Window();
    option_stub_para=0;
    window1->showCenterWindow(true);

    EXPECT_NE(window1->isVisible(),false);
    EXPECT_NE(window1,nullptr);

    window1->deleteLater();

    
}

TEST_F(test_window, showCenterWindow_02)
{
    Window * window1 = new Window();

    Stub stub;
    stub.set(ADDR(DSettings,option),option_stub);

    option_stub_para=1;
    window1->showCenterWindow(true);

    EXPECT_NE(window1->isVisible(),false);
    EXPECT_NE(window1,nullptr);

    window1->deleteLater();


}

TEST_F(test_window, showCenterWindow_03)
{
    Window * window1 = new Window();

    Stub stub;
    stub.set(ADDR(DSettings,option),option_stub);

    option_stub_para=2;
    window1->showCenterWindow(true);

    EXPECT_NE(window1->isVisible(),false);
    EXPECT_NE(window1,nullptr);

    window1->deleteLater();

}


//initTitlebar
TEST_F(test_window, initTitlebar)
{
    Window * window1 = new Window();
    window1->initTitlebar();

    EXPECT_NE(window1,nullptr);
    EXPECT_NE(window1->m_menu,nullptr);

    window1->deleteLater();


    
}
TEST_F(test_window, checkBlockShutdown)
{
    Window * window1 = new Window();
    EXPECT_NE(window1->checkBlockShutdown(),true);

    EXPECT_NE(window1,nullptr);

    window1->deleteLater();

    
}
//getTabIndex
TEST_F(test_window, getTabIndex)
{
    Window * window1 = new Window();
    EXPECT_NE(window1->getTabIndex("aadd"),1);

    EXPECT_NE(window1,nullptr);

    window1->deleteLater();

    
}
int *stub1_exec()
{

    return nullptr;
}
//activeTab
TEST_F(test_window, activeTab)
{
    Window * window1 = new Window();
    window1->activeTab(0);

    EXPECT_NE(window1->m_tabbar->currentIndex(),1);
    EXPECT_NE(window1,nullptr);

    window1->deleteLater();

    
}
//addTab
TEST_F(test_window, addTab)
{
    Window * window1 = new Window();
    window1->addTab("aabb",true);

    EXPECT_NE(window1->m_tabbar->currentIndex(),1);
    EXPECT_NE(window1,nullptr);

    window1->deleteLater();

    
}
//openFile
//TEST_F(test_window, openFile)
//{
//    window = new Window();
//    EditWrapper * a = new EditWrapper();
//    window->addTabWithWrapper(a,"aa","aad","aadd",0);
//    window->addTabWithWrapper(a,"bb","aad","aadd",1);
//    Stub stub;
//    stub.set((int (QDialog::*)(const QPoint &, int *))ADDR(QDialog, exec), stub1_exec);
//    // stub.set((QAction *(QMenu::*)(const QPoint &, QAction *))ADDR(QMenu, exec), stub_exec);
//    window->openFile();
//    
//}
TEST_F(test_window, saveFile)
{
    Window * window1 = new Window();
    EXPECT_NE(window1->saveFile(),true);

    EXPECT_NE(window1,nullptr);

    window1->deleteLater();

    
}

int exec_ret = 1;
int exec_stub()
{
    return exec_ret;
}

bool isDraft=false;
bool isDraftFile_stub()
{
    return isDraft;
}

bool isModified=false;
bool isModified_stub()
{
    return isModified;
}
TEST_F(test_window, closeTab_01)
{
    Window * window = new Window();
    window->addBlankTab("aabb");

    typedef int (*Fptr)(QDialog *);
    Fptr fptr = (Fptr)(&QDialog::exec);
    Stub stub;
    stub.set(fptr,exec_stub);

    Stub s2;
    s2.set(ADDR(EditWrapper,isDraftFile),isDraftFile_stub);
    Stub s3;
    s3.set(ADDR(EditWrapper,isModified),isModified_stub);


    isDraft = true;
    isModified = true;
    exec_ret = 0;
    window->closeTab();


    EXPECT_NE(window,nullptr);

    window->deleteLater();

    
}

TEST_F(test_window, closeTab_02)
{
    Window * window = new Window();
    window->addBlankTab("aabb");

    typedef int (*Fptr)(QDialog *);
    Fptr fptr = (Fptr)(&QDialog::exec);
    Stub stub;
    stub.set(fptr,exec_stub);

    Stub s2;
    s2.set(ADDR(EditWrapper,isDraftFile),isDraftFile_stub);
    Stub s3;
    s3.set(ADDR(EditWrapper,isModified),isModified_stub);

    isDraft = true;
    isModified = true;
    exec_ret = 1;
    window->closeTab();

    EXPECT_NE(window,nullptr);

    window->deleteLater();
}


TEST_F(test_window, closeTab_03)
{
    Window * window = new Window();
    window->addBlankTab("aabb");

    typedef int (*Fptr)(QDialog *);
    Fptr fptr = (Fptr)(&QDialog::exec);
    Stub stub;
    stub.set(fptr,exec_stub);

    Stub s2;
    s2.set(ADDR(EditWrapper,isDraftFile),isDraftFile_stub);
    Stub s3;
    s3.set(ADDR(EditWrapper,isModified),isModified_stub);

    isDraft = true;
    isModified = true;
    exec_ret = 2;
    window->closeTab();

    EXPECT_NE(window,nullptr);

    window->deleteLater();
}

TEST_F(test_window, closeTab_04)
{
    Window * window = new Window();
    window->addBlankTab("aabb");

    typedef int (*Fptr)(QDialog *);
    Fptr fptr = (Fptr)(&QDialog::exec);
    Stub stub;
    stub.set(fptr,exec_stub);

    Stub s2;
    s2.set(ADDR(EditWrapper,isDraftFile),isDraftFile_stub);
    Stub s3;
    s3.set(ADDR(EditWrapper,isModified),isModified_stub);

    isDraft = false;
    isModified = true;
    exec_ret = 1;
    window->closeTab();

    EXPECT_NE(window,nullptr);
    window->deleteLater();
}


TEST_F(test_window, closeTab_05)
{
    Window * window = new Window();
    window->addBlankTab("aabb");

    typedef int (*Fptr)(QDialog *);
    Fptr fptr = (Fptr)(&QDialog::exec);
    Stub stub;
    stub.set(fptr,exec_stub);

    Stub s2;
    s2.set(ADDR(EditWrapper,isDraftFile),isDraftFile_stub);
    Stub s3;
    s3.set(ADDR(EditWrapper,isModified),isModified_stub);

    isDraft = false;
    isModified = true;
    exec_ret = 2;
    window->closeTab();

    EXPECT_NE(window,nullptr);
    window->deleteLater();
}

//saveAsFileToDisk
TEST_F(test_window, saveAsFileToDisk)
{
    Window * window1 = new Window();
    EXPECT_NE(window1->saveAsFileToDisk(),"1");

    EXPECT_NE(window1,nullptr);

    window1->deleteLater();

    
}
//saveBlankFileToDisk
TEST_F(test_window, saveBlankFileToDisk)
{
    Window * window1 = new Window();
    EXPECT_NE(window1->saveBlankFileToDisk(),"1");

    EXPECT_NE(window1,nullptr);

    window1->deleteLater();

    
}
//saveAsOtherTabFile
TEST_F(test_window, saveAsOtherTabFile)
{
//    Window * window = StartManager::instance()->createWindow();
//    window->addBlankTab("");
//    window->addBlankTab("");
//    window->addBlankTab("");
//    EditWrapper *wrapper = window->currentWrapper();
//    window->saveAsOtherTabFile(wrapper);
////    delete window;
//    window = nullptr;

    
}
//changeSettingDialogComboxFontNumber
TEST_F(test_window, changeSettingDialogComboxFontNumber)
{
    EditWrapper * e = new EditWrapper();
    Window * window1 = new Window();
    window1->changeSettingDialogComboxFontNumber(3);


    EXPECT_NE(window1,nullptr);
    EXPECT_NE(e,nullptr);
    window1->deleteLater();
    e->deleteLater();

    
}
//popupFindBar
TEST_F(test_window, popupFindBar)
{
    Window * window1 = new Window();
    EditWrapper *pEditWrapper = new EditWrapper();
    window1->addTabWithWrapper(pEditWrapper, "aa", "aad", "aadd", 0);
    window1->addBlankTab();
    window1->currentWrapper()->textEditor()->setPlainText(QString("12345"));
    window1->popupFindBar();

    window1->currentWrapper()->textEditor()->document()->clear();
    window1->popupFindBar();

    EXPECT_NE(window1->m_tabbar->count(),0);

    EXPECT_NE(window1,nullptr);
    window1->deleteLater();
    EXPECT_NE(pEditWrapper,nullptr);
    pEditWrapper->deleteLater();


    
}

//popupReplaceBar
TEST_F(test_window, popupReplaceBar)
{
    Window * window1 = new Window();
    EditWrapper *pEditWrapper = new EditWrapper();
    window1->addTabWithWrapper(pEditWrapper, "aa", "aad", "aadd", 0);
    window1->addBlankTab();
    window1->currentWrapper()->textEditor()->setPlainText(QString("12345"));
    window1->popupReplaceBar();

    window1->currentWrapper()->textEditor()->document()->clear();
    window1->popupReplaceBar();

    EXPECT_NE(window1->m_replaceBar->isVisible(),false);


    EXPECT_NE(window1,nullptr);
    window1->deleteLater();
    EXPECT_NE(pEditWrapper,nullptr);
    pEditWrapper->deleteLater();
}

//popupJumpLineBar
TEST_F(test_window, popupJumpLineBar)
{
    Window * window1 = new Window();
    window1->popupJumpLineBar();

    EditWrapper *pEditWrapper = new EditWrapper();
    window1->addTabWithWrapper(pEditWrapper, "aa", "aad", "aadd", 0);
    window1->addBlankTab();
    window1->currentWrapper()->textEditor()->setPlainText(QString("12345"));
    window1->popupJumpLineBar();

    window1->currentWrapper()->textEditor()->document()->clear();
    window1->popupJumpLineBar();

    EXPECT_NE(window1->m_jumpLineBar->isVisible(),false);


    EXPECT_NE(window1,nullptr);
    window1->deleteLater();
    EXPECT_NE(pEditWrapper,nullptr);
    pEditWrapper->deleteLater();

    
}

//updateJumpLineBar
TEST_F(test_window, updateJumpLineBar)
{
//    Window * window = new Window();
//    window->updateJumpLineBar();


    
}

//popupSettingsDialog
TEST_F(test_window, popupSettingsDialog)
{
//    Window * window = new Window();
//    window->popupSettingsDialog();
//    delete window;
//    window = nullptr;

    
}
//popupPrintDialog

TEST_F(test_window, popupPrintDialog)
{
//    Window * window = new Window();
//    window->popupPrintDialog();
//    delete window;
//    window = nullptr;

    
}
TEST_F(test_window, popupThemePanel)
{
    Window * window1 = new Window();
    window1->popupThemePanel();

    EXPECT_NE(window1->m_themePanel->isVisible(),false);

    EXPECT_NE(window1,nullptr);
    window1->deleteLater();

    
}
//toggleFullscreen
TEST_F(test_window, toggleFullscreen)
{
    Window * window1 = new Window();
    window1->toggleFullscreen();

    EXPECT_NE(window1,nullptr);
    window1->deleteLater();

    
}
TEST_F(test_window, remberPositionSave)
{
//    Window * window = new Window();
//    window->remberPositionSave();
//    delete window;
//    window = nullptr;

    
}
//remberPositionRestore
TEST_F(test_window, remberPositionRestore)
{
    Window * window1 = new Window();
    window1->remberPositionRestore();

    EXPECT_NE(window1->m_remberPositionFilePath.isEmpty(),false);

    EXPECT_NE(window1,nullptr);
    window1->deleteLater();

    
}
//displayShortcuts
TEST_F(test_window, displayShortcuts)
{
    Window * window1 = new Window();
    window1->displayShortcuts();

    EXPECT_NE(window1->m_shortcutViewProcess,nullptr);

    EXPECT_NE(window1,nullptr);
    window1->deleteLater();

    
}
//setChildrenFocus
TEST_F(test_window, setChildrenFocus)
{
    Window * window1 = new Window();
    window1->setChildrenFocus(false);

    EXPECT_NE(window1,nullptr);
    window1->deleteLater();

    
}
//addBlankTab
TEST_F(test_window, addBlankTab)
{
    Window * window1 = new Window();
    window1->addBlankTab("aabb");

    EXPECT_NE(window1->m_tabbar->count(),0);

    EXPECT_NE(window1,nullptr);
    window1->deleteLater();

    
}
//handleTabCloseRequested
TEST_F(test_window, addTabWithWrapper)
{
    edit = new EditWrapper();
    window = new Window();
    window->addTabWithWrapper(edit,"aabb","aabb","aabb");

    EXPECT_NE(window->m_tabbar->count(),0);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(edit,nullptr);
    edit->deleteLater();

    
}
TEST_F(test_window, handleTabCloseRequested)
{
//    StartManager::instance()->createWindow()->addTabWithWrapper(edit,"aabb","aabb",0);
//    StartManager::instance()->createWindow()->handleTabCloseRequested(0);

    
}
//handleTabsClosed
TEST_F(test_window, handleTabsClosed)
{
    QStringList aa;
    window = new Window();
    window->handleTabsClosed(aa);

    EXPECT_NE(window->m_tabbar->count(),1);

    EXPECT_NE(window,nullptr);
    window->deleteLater();

    
}
//handleCurrentChanged
TEST_F(test_window, handleCurrentChanged)
{
    QStringList aa;
    window = new Window();
    window->handleCurrentChanged(0);

    EXPECT_NE(window->m_findBar->isVisible(),true);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
}
//slot_setTitleFocus
TEST_F(test_window, slot_setTitleFocus)
{
//    QStringList aa;
    //window = new Window();
//    StartManager::instance()->createWindow()->slot_setTitleFocus();
    //window->slot_setTitleFocus();

    
}
//resizeEvent
TEST_F(test_window, resizeEvent)
{
    QStringList aa;
    window = new Window();
    QResizeEvent * eve= new QResizeEvent(QSize(100,100),QSize(50,50));
    window->resizeEvent(eve);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    delete eve;eve=nullptr;

    
}
//closeEvent
TEST_F(test_window, keyPressEvent)
{
    QStringList aa;
    window = new Window();
    QKeyEvent * eve;
    //window->keyPressEvent(eve);

    EXPECT_NE(window,nullptr);
    window->deleteLater();

    
}
//hideEvent
TEST_F(test_window, hideEvent)
{
    QStringList aa;
    window = new Window();
    QHideEvent * eve;
    window->hideEvent(eve);

    EXPECT_NE(window->m_replaceBar->isVisible(),true);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
}

//TextEdit
//void backupFile();
TEST_F(test_window, backupFile)
{
    window = new Window();
    window->backupFile();

    EXPECT_NE(window->m_qlistTemFile.isEmpty(),false);

    EXPECT_NE(window,nullptr);
    window->deleteLater();

    
}

//void closeAllFiles();
TEST_F(test_window, closeAllFiles)
{
    window = new Window();
    EXPECT_NE(window->closeAllFiles(),false);

    EXPECT_NE(window->m_tabbar->count(),1);

    EXPECT_NE(window,nullptr);
    window->deleteLater();

    
}

//void addTemFileTab(QString qstrPath,QString qstrName,QString qstrTruePath,bool bIsTemFile = false);
TEST_F(test_window, addTemFileTab)
{
    window = new Window();
    window->addTemFileTab("aa","bb","cc");

    EXPECT_NE(window->m_tabbar->count(),1);

    EXPECT_NE(window,nullptr);
    window->deleteLater();

    
}
//Window(DMainWindow *parent = nullptr);
//~Window() override;

////跟新文件修改状态
//void updateModifyStatus(const QString &path, bool isModified);
TEST_F(test_window, updateModifyStatus)
{
    window = new Window();
    window->updateModifyStatus("aa",false);
    window->updateModifyStatus("aa",true);

    EXPECT_NE(window,nullptr);
    window->deleteLater();

    
}
////跟新tab文件名称
//void updateSaveAsFileName(QString strOldFilePath, QString strNewFilePath);
TEST_F(test_window, updateSaveAsFileName)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    window->addTabWithWrapper(a,"aa","aad","aadd",0);
    window->addTabWithWrapper(a,"bb","aad","aadd",1);
    window->updateSaveAsFileName("aa","bb");

    EXPECT_NE(window->m_tabbar->indexOf("aa"),1);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    
}

//int getTabIndex(const QString &file);
//void activeTab(int index);

//Tabbar* getTabbar();
TEST_F(test_window, getTabbar)
{
    window = new Window();
    EXPECT_NE(window->getTabbar(),nullptr);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    
}

//void addTab(const QString &filepath, bool activeTab = false);
//void addTabWithWrapper(EditWrapper *wrapper, const QString &filepath, const QString &qstrTruePath,
//                       const QString &tabName, int index = -1);
//bool closeTab();
//void restoreTab();
TEST_F(test_window, restoreTab)
{
    window = new Window();
    window->restoreTab();
    EXPECT_NE(window->m_closeFileHistory.isEmpty(),false);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    
}

//void clearBlack();

//EditWrapper* createEditor();
TEST_F(test_window, createEditor)
{
    window = new Window();
    EXPECT_NE(window->createEditor(),nullptr);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    
}
//EditWrapper* currentWrapper();
TEST_F(test_window, currentWrapper)
{
    window = new Window();
    EXPECT_EQ(window->currentWrapper(),nullptr);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    
}
//EditWrapper* wrapper(const QString &filePath);
//TextEdit* getTextEditor(const QString &filepath);
TEST_F(test_window, getTextEditor)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    window->addTabWithWrapper(a,"aa","aad","aadd",0);
    window->addTabWithWrapper(a,"bb","aad","aadd",1);
    EXPECT_NE(window->getTextEditor("aa"),nullptr);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();
    
}
//void focusActiveEditor();
TEST_F(test_window, focusActiveEditor)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    window->addTabWithWrapper(a,"aa","aad","aadd",0);
    window->addTabWithWrapper(a,"bb","aad","aadd",1);
    window->focusActiveEditor();

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();
    
}
//void removeWrapper(const QString &filePath, bool isDelete = false);
TEST_F(test_window, removeWrapper)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    window->addTabWithWrapper(a,"aa","aad","aadd",0);
    window->addTabWithWrapper(a,"bb","aad","aadd",1);
    window->removeWrapper("aa",true);
    window->removeWrapper("bb",false);

    EXPECT_EQ(window->m_wrappers.value("aa"),nullptr);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();

    
}

TEST_F(test_window, decrementFontSize)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    window->m_settings =Settings::instance();
    window->decrementFontSize();

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();
    
}
//void incrementFontSize();
TEST_F(test_window, incrementFontSize)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    window->m_settings =Settings::instance();
    window->incrementFontSize();


    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();
    
}
//void resetFontSize();
TEST_F(test_window, resetFontSize)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    window->m_settings =Settings::instance();
    window->resetFontSize();

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();
    
}
//void setFontSizeWithConfig(EditWrapper *editor);
TEST_F(test_window, setFontSizeWithConfig)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    window->m_settings =Settings::instance();
    window->setFontSizeWithConfig(a);

    EXPECT_NE(window->m_fontSize,10);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();
    
}



//public slots:
//void addBlankTab();
//void addBlankTab(const QString &blankFile);
//void handleTabCloseRequested(int index);
//void handleTabsClosed(QStringList tabList);
//void handleCurrentChanged(const int &index);

//void handleJumpLineBarExit();
TEST_F(test_window, handleJumpLineBarExit)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    window->m_settings =Settings::instance();
    window->handleJumpLineBarExit();

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();


    
}
//void handleJumpLineBarJumpToLine(const QString &filepath, int line, bool focusEditor);
TEST_F(test_window, handleJumpLineBarJumpToLine)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    window->addTabWithWrapper(a,"aa","aad","aadd",0);
    window->addTabWithWrapper(a,"bb","aad","aadd",1);
    window->m_settings =Settings::instance();
    window->handleJumpLineBarJumpToLine("aa",1,true);
    window->handleJumpLineBarJumpToLine("aa",1,false);


    EXPECT_NE(window->m_wrappers.contains("aa"),false);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();

    
}

//void handleBackToPosition(const QString &file, int row, int column, int scrollOffset);
TEST_F(test_window, handleBackToPosition)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    window->addTabWithWrapper(a,"aa","aad","aadd",0);
    window->addTabWithWrapper(a,"bb","aad","aadd",1);
    window->m_settings =Settings::instance();
    window->handleBackToPosition("aa",1,1,1);

    EXPECT_NE(window->m_wrappers.contains("bb"),false);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();
    
}

//void handleFindNext();
TEST_F(test_window, handleFindNextSearchKeyword)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    window->addTabWithWrapper(a,"aa","aad","aadd",0);
    window->addTabWithWrapper(a,"bb","aad","aadd",1);
    window->m_settings =Settings::instance();
    window->handleFindNextSearchKeyword("");

    EXPECT_NE(window->m_wrappers.contains("aadd"),true);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();
    
}
//void handleFindPrev();
TEST_F(test_window, handleFindPrevSearchKeyword)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    window->addTabWithWrapper(a,"aa","aad","aadd",0);
    window->addTabWithWrapper(a,"bb","aad","aadd",1);
    window->m_settings =Settings::instance();
    window->handleFindPrevSearchKeyword("");

    EXPECT_NE(window->m_wrappers.contains("aad"),true);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();

    
}
//void slotFindbarClose();
TEST_F(test_window, slotFindbarClose)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    window->addTabWithWrapper(a,"aa","aad","aadd",0);
    window->addTabWithWrapper(a,"bb","aad","aadd",1);
    window->m_settings =Settings::instance();
    window->slotFindbarClose();

    EXPECT_NE(window->m_findBar->isVisible(),true);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();

    
}
//void slotReplacebarClose();
TEST_F(test_window, slotReplacebarClose)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    window->addTabWithWrapper(a,"aa","aad","aadd",0);
    window->addTabWithWrapper(a,"bb","aad","aadd",1);
    window->m_settings =Settings::instance();
    window->slotReplacebarClose();

    EXPECT_NE(window->m_replaceBar->isVisible(),true);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();

    
}

//void handleReplaceAll(const QString &replaceText, const QString &withText);
TEST_F(test_window, handleReplaceAll)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    window->addTabWithWrapper(a,"aa","aad","aadd",0);
    window->addTabWithWrapper(a,"bb","aad","aadd",1);
    window->m_settings =Settings::instance();
    window->handleReplaceAll("","");


    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();
    
}
//void handleReplaceNext(const QString &replaceText, const QString &withText);
TEST_F(test_window, handleReplaceNext)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    window->addTabWithWrapper(a,"aa","aad","aadd",0);
    window->addTabWithWrapper(a,"bb","aad","aadd",1);
    window->m_settings =Settings::instance();
    window->handleReplaceNext("a", "", "");

    EXPECT_EQ(window->m_keywordForSearch,"");

    EXPECT_NE(window->m_findBar->isVisible(),true);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();
    
}
//void handleReplaceRest(const QString &replaceText, const QString &withText);
TEST_F(test_window, handleReplaceRest)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    window->addTabWithWrapper(a,"aa","aad","aadd",0);
    window->addTabWithWrapper(a,"bb","aad","aadd",1);
    window->m_settings =Settings::instance();
    window->handleReplaceRest("","");

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();
    
}
//void handleReplaceSkip();
TEST_F(test_window, handleReplaceSkip)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    window->addTabWithWrapper(a,"aa","aad","aadd",0);
    window->addTabWithWrapper(a,"bb","aad","aadd",1);
    window->m_settings =Settings::instance();
    window->handleReplaceSkip("aa", "");

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();
    
}

//void handleRemoveSearchKeyword();
TEST_F(test_window, handleRemoveSearchKeyword)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    window->addTabWithWrapper(a,"aa","aad","aadd",0);
    window->addTabWithWrapper(a,"bb","aad","aadd",1);
    window->m_settings =Settings::instance();
    window->handleRemoveSearchKeyword();


    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();
    
}
//void handleUpdateSearchKeyword(QWidget *widget, const QString &file, const QString &keyword);
TEST_F(test_window, handleUpdateSearchKeyword)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    window->addTabWithWrapper(a,"aa","aad","aadd",0);
    window->addTabWithWrapper(a,"bb","aad","aadd",1);
    window->m_settings =Settings::instance();
    window->handleUpdateSearchKeyword(window,"aa","");

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();
    
}


//void addBottomWidget(QWidget *widget);
//void removeBottomWidget();

//void loadTheme(const QString &path);
TEST_F(test_window, loadTheme)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    window->addTabWithWrapper(a,"aa","aad","aadd",0);
    window->addTabWithWrapper(a,"bb","aad","aadd",1);
    window->m_settings =Settings::instance();
    window->loadTheme("window");

    EXPECT_NE(window->m_themePath,"1");

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();
    
}


//void showNewEditor(EditWrapper *wrapper);
TEST_F(test_window, showNewEditor)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    window->addTabWithWrapper(a,"aa","aad","aadd",0);
    window->addTabWithWrapper(a,"bb","aad","aadd",1);
    window->m_settings =Settings::instance();
    window->showNewEditor(a);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();
    
}
//void showNotify(const QString &message);
TEST_F(test_window, showNotify)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    window->addTabWithWrapper(a,"aa","aad","aadd",0);
    window->addTabWithWrapper(a,"bb","aad","aadd",1);
    window->m_settings =Settings::instance();
    window->showNotify("ffffkkkk");

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();
    
}
//int getBlankFileIndex();
TEST_F(test_window, getBlankFileIndex)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    window->addTabWithWrapper(a,"aa","aad","aadd",0);
    window->addBlankTab();
    window->addTabWithWrapper(a,"bb","aad","aadd",1);
    window->m_settings =Settings::instance();
    EXPECT_NE(window->getBlankFileIndex(),0);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();
    
}

//DDialog *createDialog(const QString &title, const QString &content);
TEST_F(test_window, createDialog)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    window->addTabWithWrapper(a,"aa","aad","aadd",0);
    window->addBlankTab();
    window->addTabWithWrapper(a,"bb","aad","aadd",1);
    window->m_settings =Settings::instance();
    EXPECT_NE(window->createDialog("dd","ddd"),nullptr);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();
    
}

//void slotLoadContentTheme(DGuiApplicationHelper::ColorType themeType);
TEST_F(test_window, slotLoadContentTheme)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    window->addTabWithWrapper(a,"aa","aad","aadd",0);
    window->addBlankTab();
    window->addTabWithWrapper(a,"bb","aad","aadd",1);
    window->m_settings =Settings::instance();
    window->slotLoadContentTheme(DGuiApplicationHelper::ColorType::DarkType);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();
    
}

//void slotSettingResetTheme(const QString &path);
TEST_F(test_window, slotSettingResetTheme)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    window->addTabWithWrapper(a,"aa","aad","aadd",0);
    window->addBlankTab();
    window->addTabWithWrapper(a,"bb","aad","aadd",1);
    window->m_settings =Settings::instance();
    window->slotSettingResetTheme("DGuiApplicationHelper::ColorType::DarkType");

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();
    
}

//void slotSigThemeChanged(const QString &path);
TEST_F(test_window, slotSigThemeChanged)
{
    Window *pWindow = new Window();
    EditWrapper *pEditWrapper = new EditWrapper();
    pWindow->addTabWithWrapper(pEditWrapper, "aa", "aad", "aadd", 0);
    pWindow->addBlankTab();
    pWindow->addTabWithWrapper(pEditWrapper, "bb", "aad", "aadd", 1);
    pWindow->m_settings = Settings::instance();
    DGuiApplicationHelper::instance()->setThemeType(DGuiApplicationHelper::LightType);
    //pWindow->slotSigThemeChanged(DEEPIN_THEME);
    //pWindow->slotSigThemeChanged(DEEPIN_DARK_THEME);

    DGuiApplicationHelper::instance()->setThemeType(DGuiApplicationHelper::DarkType);
    //pWindow->slotSigThemeChanged(DEEPIN_THEME);
    //pWindow->slotSigThemeChanged(DEEPIN_DARK_THEME);


    EXPECT_NE(pWindow,nullptr);
    pWindow->deleteLater();
    EXPECT_NE(pEditWrapper,nullptr);
    pEditWrapper->deleteLater();

    
}

//void slot_saveReadingPath();
TEST_F(test_window, slot_saveReadingPath)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    window->addTabWithWrapper(a,"aa","aad","aadd",0);
    window->addBlankTab();
    window->addTabWithWrapper(a,"bb","aad","aadd",1);
    window->m_settings =Settings::instance();
    window->slot_saveReadingPath();

    EXPECT_NE(window->m_reading_list.isEmpty(),true);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();
    
}
//void slot_beforeReplace(QString _);
TEST_F(test_window, slot_beforeReplace)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    window->addTabWithWrapper(a,"aa","aad","aadd",0);
    window->addBlankTab();
    window->addTabWithWrapper(a,"bb","aad","aadd",1);
    window->m_settings =Settings::instance();
    window->slot_beforeReplace("d");

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();
    
}
//void slot_setTitleFocus();

//private:
//void handleFocusWindowChanged(QWindow *w);
TEST_F(test_window, handleFocusWindowChanged)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    QWindow * q = new QWindow();
    window->addTabWithWrapper(a,"aa","aad","aadd",0);
    window->addBlankTab();
    window->addTabWithWrapper(a,"bb","aad","aadd",1);
    window->m_settings =Settings::instance();
    window->handleFocusWindowChanged(q);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();
    EXPECT_NE(q,nullptr);
    q->deleteLater();
    
}
//void updateThemePanelGeomerty();
TEST_F(test_window, updateThemePanelGeomerty)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    QWindow * q = new QWindow();
    window->addTabWithWrapper(a,"aa","aad","aadd",0);
    window->addBlankTab();
    window->addTabWithWrapper(a,"bb","aad","aadd",1);
    window->m_settings =Settings::instance();
    window->updateThemePanelGeomerty();

    EXPECT_NE(window->m_themePanel->geometry().x(),0);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();
    EXPECT_NE(q,nullptr);
    q->deleteLater();

    
}

//void checkTabbarForReload();
TEST_F(test_window, checkTabbarForReload)
{
    window = new Window();
    EditWrapper * a = new EditWrapper();
    QWindow * q = new QWindow();
    window->addTabWithWrapper(a,"aa","aad","aadd",0);
    window->addBlankTab();
    window->addTabWithWrapper(a,"bb","aad","aadd",1);
    window->m_settings =Settings::instance();
    window->checkTabbarForReload();

    EXPECT_NE(window->m_tabbar->currentName(),"aa");

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(a,nullptr);
    a->deleteLater();
    EXPECT_NE(q,nullptr);
    q->deleteLater();

    
}

//void slotSigAdjustFont();
TEST_F(test_window, slotSigAdjustFont)
{
    window = new Window();
    EditWrapper *pEditWrapper = new EditWrapper();
    window->addTabWithWrapper(pEditWrapper, "aa", "aad", "aadd", 0);
    window->addBlankTab();
    window->addTabWithWrapper(pEditWrapper,"bb", "aad", "aadd", 1);
    window->slotSigAdjustFont(QString());

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(pEditWrapper,nullptr);
    pEditWrapper->deleteLater();

    
}

//void slotSigAdjustFontSize();
TEST_F(test_window, slotSigAdjustFontSize)
{
    window = new Window();
    EditWrapper *pEditWrapper = new EditWrapper();
    window->addTabWithWrapper(pEditWrapper, "aa", "aad", "aadd", 0);
    window->addBlankTab();
    window->addTabWithWrapper(pEditWrapper, "bb", "aad", "aadd", 1);
    window->slotSigAdjustFontSize(14);

    EXPECT_EQ(window->m_fontSize,14);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(pEditWrapper,nullptr);
    pEditWrapper->deleteLater();

    
}

//void slotSigAdjustTabSpaceNumber();
TEST_F(test_window, slotSigAdjustTabSpaceNumber)
{
    window = new Window();
    EditWrapper *pEditWrapper = new EditWrapper();
    window->addTabWithWrapper(pEditWrapper, "aa", "aad", "aadd", 0);
    window->addBlankTab();
    window->addTabWithWrapper(pEditWrapper, "bb", "aad", "aadd", 1);

    window->slotSigAdjustTabSpaceNumber(14);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(pEditWrapper,nullptr);
    pEditWrapper->deleteLater();
    
}

//void slotSigAdjustWordWrap();
TEST_F(test_window, slotSigAdjustWordWrap)
{
    window = new Window();
    EditWrapper *pEditWrapper = new EditWrapper();
    window->addTabWithWrapper(pEditWrapper, "aa", "aad", "aadd", 0);
    window->addBlankTab();
    window->addTabWithWrapper(pEditWrapper, "bb", "aad", "aadd", 1);

    window->slotSigAdjustWordWrap(true);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(pEditWrapper,nullptr);
    pEditWrapper->deleteLater();
    
}

//void slotSigAdjustBookmark();
TEST_F(test_window, slotSigAdjustBookmark)
{
    window = new Window();
    EditWrapper *pEditWrapper = new EditWrapper();
    window->addTabWithWrapper(pEditWrapper, "aa", "aad", "aadd", 0);
    window->addBlankTab();
    window->addTabWithWrapper(pEditWrapper, "bb", "aad", "aadd", 1);

    window->slotSigAdjustBookmark(true);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(pEditWrapper,nullptr);
    pEditWrapper->deleteLater();
    
}

//void slotSigShowBlankCharacter();
TEST_F(test_window, slotSigShowBlankCharacter)
{
    window = new Window();
    EditWrapper *pEditWrapper = new EditWrapper();
    window->addTabWithWrapper(pEditWrapper, "aa", "aad", "aadd", 0);
    window->addBlankTab();
    window->addTabWithWrapper(pEditWrapper, "bb", "aad", "aadd", 1);

    window->slotSigShowBlankCharacter(true);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(pEditWrapper,nullptr);
    pEditWrapper->deleteLater();
    
}

//void slotSigHightLightCurrentLine();
TEST_F(test_window, slotSigHightLightCurrentLine)
{
    window = new Window();
    EditWrapper *pEditWrapper = new EditWrapper();
    window->addTabWithWrapper(pEditWrapper, "aa", "aad", "aadd", 0);
    window->addBlankTab();
    window->addTabWithWrapper(pEditWrapper, "bb", "aad", "aadd", 1);

    window->slotSigHightLightCurrentLine(true);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(pEditWrapper,nullptr);
    pEditWrapper->deleteLater();
    
}

//void slotSigShowCodeFlodFlag();
TEST_F(test_window, slotSigShowCodeFlodFlag)
{
    window = new Window();
    EditWrapper *pEditWrapper = new EditWrapper();
    window->addTabWithWrapper(pEditWrapper, "aa", "aad", "aadd", 0);
    window->addBlankTab();
    window->addTabWithWrapper(pEditWrapper, "bb", "aad", "aadd", 1);

    window->slotSigShowCodeFlodFlag(true);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    EXPECT_NE(pEditWrapper,nullptr);
    pEditWrapper->deleteLater();
    
}

//void slotSigShowCodeFlodFlag();
TEST_F(test_window, slotSigChangeWindowSize)
{
    window = new Window();
    window->slotSigChangeWindowSize(QString());
    window->slotSigChangeWindowSize(QString("fullscreen"));
    window->slotSigChangeWindowSize(QString("window_maximum"));

    EXPECT_EQ(window->isVisible(),true);

    EXPECT_NE(window,nullptr);
    window->deleteLater();
    
}



TEST_F(test_window, printPage)
{
    QPainter* painter = new QPainter;
    QTextDocument* doc = new QTextDocument;
    QRectF body,pageContBox;
    Window::printPage(0,painter,doc,body,pageContBox);

    EXPECT_NE(window,nullptr);
    EXPECT_NE(window,nullptr);
    delete painter;painter=nullptr;
    doc->deleteLater();

}

TEST_F(test_window, delete_window)
{
    Window* w = new Window();
    w->m_shortcutViewProcess = new QProcess;

    EXPECT_NE(w,nullptr);
    w->deleteLater();
    //w->m_shortcutViewProcess will be deleted in ~Window;
}