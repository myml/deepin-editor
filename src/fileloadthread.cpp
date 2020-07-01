/*
 * Copyright (C) 2017 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     rekols <rekols@foxmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "fileloadthread.h"
#include "utils.h"

#include <QCoreApplication>
#include <QPlainTextEdit>
#include <QTextDocument>
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <QTextCodec>

FileLoadThread::FileLoadThread(const QString &filepath, QObject *parent)
    : QThread(parent),
      m_filePath(filepath)
{

}

FileLoadThread::~FileLoadThread()
{
}

void FileLoadThread::run()
{
    QFile file(m_filePath);

        uchar *pContent = nullptr;
        QString content = "";

        if (file.open(QIODevice::ReadOnly)) {
            // reads all remaining data from the file.
            QByteArray fileContent = file.read(1024);

            // read the encode.
            QByteArray encode = Utils::detectEncode(fileContent);
            if(encode =="Big5")
            {
                encode="gb18030";
            }

            pContent = file.map(0,file.size());

            if (pContent) {
                content = QString::fromUtf8((char*)pContent,file.size());
                emit loadFinished(encode, content);
            }
            emit toTellFileClosed();
        }
        file.close();
}
