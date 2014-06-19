/***************************************************************************
 *   Copyright 2014 Marco Martin <mart@kde.org>                            *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 ***************************************************************************/

#ifndef COLORSCOPE_H
#define COLORSCOPE_H

#include <QQuickItem>
#include <QWeakPointer>
#include <QtCore/QVariant>
#include <Plasma/Plasma>
#include <Plasma/Theme>

class QQuickItem;


class ColorScope : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(Plasma::Theme::ColorGroup colorGroup READ colorGroup WRITE setColorGroup)
    Q_PROPERTY(QColor textColor READ textColor NOTIFY colorsChanged)
    Q_PROPERTY(QColor highlightColor READ highlightColor NOTIFY colorsChanged)
    Q_PROPERTY(QColor backgroundColor READ backgroundColor NOTIFY colorsChanged)

public:
    ColorScope(QQuickItem *parent = 0);
    ~ColorScope();

    void setColorGroup(Plasma::Theme::ColorGroup group);
    Plasma::Theme::ColorGroup colorGroup() const;

    QColor textColor() const;
    QColor highlightColor() const;
    QColor backgroundColor() const;
    
    ////NEEDED BY QML TO CREATE ATTACHED PROPERTIES
    static ColorScope *qmlAttachedProperties(QObject *object);

Q_SIGNALS:
    void colorGroupChanged();
    void colorsChanged();

private:
    Plasma::Theme m_theme;
    Plasma::Theme::ColorGroup m_group;
    static ColorScope *s_colorScope;
};

QML_DECLARE_TYPEINFO(ColorScope, QML_HAS_ATTACHED_PROPERTIES)

#endif