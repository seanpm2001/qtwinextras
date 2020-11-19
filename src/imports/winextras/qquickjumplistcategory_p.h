/****************************************************************************
 **
 ** Copyright (C) 2016 Ivan Vizir <define-true-false@yandex.com>
 ** Copyright (C) 2016 The Qt Company Ltd.
 ** Contact: https://www.qt.io/licensing/
 **
 ** This file is part of the QtWinExtras module of the Qt Toolkit.
 **
 ** $QT_BEGIN_LICENSE:LGPL$
 ** Commercial License Usage
 ** Licensees holding valid commercial Qt licenses may use this file in
 ** accordance with the commercial license agreement provided with the
 ** Software or, alternatively, in accordance with the terms contained in
 ** a written agreement between you and The Qt Company. For licensing terms
 ** and conditions see https://www.qt.io/terms-conditions. For further
 ** information use the contact form at https://www.qt.io/contact-us.
 **
 ** GNU Lesser General Public License Usage
 ** Alternatively, this file may be used under the terms of the GNU Lesser
 ** General Public License version 3 as published by the Free Software
 ** Foundation and appearing in the file LICENSE.LGPL3 included in the
 ** packaging of this file. Please review the following information to
 ** ensure the GNU Lesser General Public License version 3 requirements
 ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
 **
 ** GNU General Public License Usage
 ** Alternatively, this file may be used under the terms of the GNU
 ** General Public License version 2.0 or (at your option) the GNU General
 ** Public license version 3 or any later version approved by the KDE Free
 ** Qt Foundation. The licenses are as published by the Free Software
 ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
 ** included in the packaging of this file. Please review the following
 ** information to ensure the GNU General Public License requirements will
 ** be met: https://www.gnu.org/licenses/gpl-2.0.html and
 ** https://www.gnu.org/licenses/gpl-3.0.html.
 **
 ** $QT_END_LICENSE$
 **
 ****************************************************************************/

#ifndef QQUICKJUMPLISTCATEGORY_P_H
#define QQUICKJUMPLISTCATEGORY_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include "qquickjumplistitem_p.h"

#include <QObject>
#include <QList>
#include <QQmlListProperty>
#include <QWinJumpListCategory>
#include <QWinJumpListItem>

QT_BEGIN_NAMESPACE

class QQuickJumpListCategory : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<QObject> data READ data)
    Q_PROPERTY(QQmlListProperty<QQuickJumpListItem> items READ items)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(bool visible READ isVisible WRITE setVisible NOTIFY visibilityChanged)
    Q_CLASSINFO("DefaultProperty", "data")

public:
    explicit QQuickJumpListCategory(QObject *parent = nullptr);
    ~QQuickJumpListCategory();

    QString title() const;
    void setTitle(const QString &title);

    bool isVisible() const;
    void setVisible(bool visible);

    QQmlListProperty<QObject> data();
    QQmlListProperty<QQuickJumpListItem> items();

    QList<QWinJumpListItem *> toItemList() const;

Q_SIGNALS:
    void itemsChanged();
    void titleChanged();
    void visibilityChanged();

private:
    static void data_append(QQmlListProperty<QObject> *property, QObject *object);
    static qsizetype items_count(QQmlListProperty<QQuickJumpListItem> *property);
    static QQuickJumpListItem *items_at(QQmlListProperty<QQuickJumpListItem> *property,
                                        qsizetype index);

    bool m_visible = true;
    QString m_title;
    QList<QQuickJumpListItem *> m_items;
};

QT_END_NAMESPACE

#endif // QQUICKJUMPLISTCATEGORY_P_H
