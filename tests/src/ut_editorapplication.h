#ifndef UT_EditorApplication_H
#define UT_EditorApplication_H

#include "gtest/gtest.h"
#include <QObject>


class UT_EditorApplication: public QObject, public::testing::Test
{
        Q_OBJECT
public:
    UT_EditorApplication();
};



#endif // UT_EditorApplication_H
