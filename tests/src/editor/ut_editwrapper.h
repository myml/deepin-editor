/*
* Copyright (C) 2019 ~ 2020 Deepin Technology Co., Ltd.
*
* Author:     liumaochuan <liumaochuan@uniontech.com>
* Maintainer: liumaochuan <liumaochuan@uniontech.com>
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef UT_Editwrapper_H
#define UT_Editwrapper_H

#include "../../src/startmanager.h"
#include "../../src/editor/dtextedit.h"
#include "../../src/common/settings.h"
#include "../../src/widgets/window.h"
#include "../../src/editor/editwrapper.h"
#include "../../src/controls/tabbar.h"
#include "../../src/common/utils.h"
#include "../../src/encodes/detectcode.h"
#include "../stub.h"
#include "gtest/gtest.h"
#include <QObject>
#include <DFileDialog>
#include <QFileDialog>
#include <QDialog>

DWIDGET_USE_NAMESPACE

class UT_Editwrapper: public QObject, public::testing::Test
{
public:
    UT_Editwrapper();
    QByteArray FileLoadThreadRun(const QString &strFilePath, QByteArray *encode);
};

#endif // UT_Editwrapper_H
