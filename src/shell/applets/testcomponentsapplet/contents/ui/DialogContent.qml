/*
 *  Copyright 2013 Sebastian Kügler <sebas@kde.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

import QtQuick 2.0
import QtQuick.Window 2.0

import org.kde.plasma.core 0.1 as PlasmaCore
import org.kde.plasma.components 0.1 as PlasmaComponents
import org.kde.plasma.extras 0.1 as PlasmaExtras
import org.kde.qtextracomponents 0.1 as QtExtras

// DialogContent

Item {
    id: dialogsPage
    width: 300
    height: 200
    signal closeMe()
    Rectangle {
        color: "green"
        //anchors.margins: 24
        opacity: 0
        anchors.fill: parent
    }
    Column {
        anchors.fill: parent
        spacing: 12
        PlasmaExtras.Title {
            id: tx
            text: "Test Dialog"
        }
        PlasmaComponents.TextArea {
            anchors { left: parent.left; right: parent.right; top: tx.bottom; }
            width: parent.width
            height: 80
        }
        PlasmaComponents.Button {
            id: thanks
            anchors { horizontalCenter: parent.horizontalCenter; bottom: parent.bottom; bottomMargin: 24; }
            iconSource: "dialog-ok"
            text: "Thanks."
            //onClicked: dialogsPage.parent.visible = false;
            onClicked: closeMe()
        }
    }
}

