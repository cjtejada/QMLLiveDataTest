import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtGraphicalEffects 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    onBeforeRendering: Work.start()

    property double angle: 0

    Connections{
        target: Work
        onResult: needle.angle = r * 10
    }

    Text{
        id: res
    }

    Rectangle{
        id: rect
        anchors.centerIn: parent
        height: 300
        width: 300
        color: "lightblue"
        radius: 300
        transform: Rotation { origin.x: 30; origin.y: 30; axis { x: 0; y: 1; z: 0 } angle: 0 }

        Image{
            property double angle: 0
            id:needle
            source: "qrc:/../../needle.png"
            height: 300
            width: 300
            anchors.centerIn: parent
            transform: Rotation { origin.x: 150; origin.y: 150; axis { x: 0; y:0 ; z: 1 } angle: needle.angle }
            smooth: true;
        }
    }
}
