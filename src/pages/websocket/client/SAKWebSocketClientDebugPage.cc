﻿/*
 * Copyright 2020 Qter(qsaker@qq.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part
 * of QtSwissArmyKnife project.
 *
 * QtSwissArmyKnife is licensed according to the terms in
 * the file LICENCE in the root of the source code directory.
 */
#include <QDebug>
#include <QWidget>
#include <QHBoxLayout>

#include "SAKCommonDataStructure.hh"
#include "SAKWebSocketClientDevice.hh"
#include "SAKWebSocketClientDebugPage.hh"
#include "SAKWebSocketClientDeviceController.hh"

SAKWebSocketClientDebugPage::SAKWebSocketClientDebugPage(int type, QString name, QWidget *parent)
    :SAKDebugPage(type, name, parent)
{
    mWebSocketClientDeviceController = new SAKWebSocketClientDeviceController(this, this);
    initializingPage();
}

SAKWebSocketClientDebugPage::~SAKWebSocketClientDebugPage()
{
    mWebSocketClientDeviceController->deleteLater();
}

SAKDebugPageController *SAKWebSocketClientDebugPage::deviceController()
{
    return mWebSocketClientDeviceController;
}

SAKDebugPageDevice *SAKWebSocketClientDebugPage::createDevice()
{
    SAKWebSocketClientDevice *device = new SAKWebSocketClientDevice(this);
    return device;
}
