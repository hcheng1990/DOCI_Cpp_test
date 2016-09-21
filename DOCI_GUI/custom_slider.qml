import QtQuick 2.0
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0
import "custom_gradient.js" as MyGradient

Rectangle {
    property var sliderHeight: 640
    property var textHeight: 20
    Rectangle {
        id: base
        width: 50
        height: 200
    }
    Component{
        id: gradientRect
        Rectangle {
            width: 50
            height: sliderHeight-textHeight*2
            y: textHeight;
            rotation: 180
            //color: "steelblue"
            gradient: Gradient {
                id:gradient
            }
        }
    }
    Component {
        id:stopComponent
        GradientStop {}
    }
    Component.onCompleted: {
        MyGradient.newRectangle(0,1);
    }
    RangeSlider {
        objectName: "slider"
        id: slider
        stepSize: .01;
        snapMode: RangeSlider.SnapAlways
        width: 50
        height: sliderHeight-textHeight*2
        y: textHeight
        orientation: Qt.Vertical
        signal qmlSignal(double val1, double val2);
        second.onPositionChanged:  {
            if(parseInt(maxVal.text)<parseInt(minVal.text))
                maxVal.text = minVal.text
            topVal.text = Math.round(((parseInt(maxVal.text)-parseInt(minVal.text)) * second.position + parseInt(minVal.text)));
            botVal.text = Math.round(((parseInt(maxVal.text)-parseInt(minVal.text)) * first.position + parseInt(minVal.text)));
            topVal.y = Math.round((1-second.position)*560+textHeight+10);
            MyGradient.newRectangle(first.position,second.position);
            slider.qmlSignal(parseFloat(topVal.text),parseFloat(botVal.text));
        }
        first.onPositionChanged:  {
            /*
            slider.qmlSignal1(first.position);
            */
            if(parseInt(maxVal.text)<parseInt(minVal.text))
                minVal.text = maxVal.text
            topVal.text = Math.round(((parseInt(maxVal.text)-parseInt(minVal.text)) * second.position + parseInt(minVal.text)));
            botVal.text = Math.round(((parseInt(maxVal.text)-parseInt(minVal.text)) * first.position + parseInt(minVal.text)));
            botVal.y = Math.round((1-first.position)*560+textHeight+10);
            MyGradient.newRectangle(first.position,second.position);
            slider.qmlSignal(parseFloat(topVal.text),parseFloat(botVal.text));
        }
        Component.onCompleted: {
            topVal.y = Math.round((1-second.position)*560+textHeight+10);
            botVal.y = Math.round((1-first.position)*560+textHeight+10);
        }
    }
    TextInput {
        id: maxVal
        width: 50
        height: textHeight
        text: "1000"
        x: 0
        y: 0
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment:  Text.AlignVCenter
        font.pointSize: 12
        validator: RegExpValidator { regExp: /^[1-9][0-9]+$/ }
        onTextChanged: {
            if(parseInt(maxVal.text)>65535)
                maxVal.text = 65535;
            else if(parseInt(maxVal.text)<0)
                maxVal.text = 0;
            topVal.text = Math.round(((parseInt(maxVal.text)-parseInt(minVal.text)) * slider.second.position + parseInt(minVal.text)));
            botVal.text = Math.round(((parseInt(maxVal.text)-parseInt(minVal.text)) * slider.first.position + parseInt(minVal.text)));
            slider.qmlSignal(parseFloat(topVal.text),parseFloat(botVal.text));
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                maxVal.selectAll();
                maxVal.focus = true;
            }
        }

    }
    TextInput {
        id: minVal
        width: 50
        height: textHeight
        text: "600"
        x: 0
        y: sliderHeight-textHeight
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment:  Text.AlignVCenter
        font.pointSize: 12
        validator: RegExpValidator { regExp: /^[1-9][0-9]+$/ }
        onTextChanged: {
            if(parseInt(minVal.text)>65535)
                minVal.text = 65535;
            else if(parseInt(minVal.text)<0)
                minVal.text = 0;
            topVal.text = Math.round(((parseInt(maxVal.text)-parseInt(minVal.text)) * slider.second.position + parseInt(minVal.text)));
            botVal.text = Math.round(((parseInt(maxVal.text)-parseInt(minVal.text)) * slider.first.position + parseInt(minVal.text)));
            slider.qmlSignal(parseFloat(topVal.text),parseFloat(botVal.text));
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                minVal.selectAll();
                minVal.focus = true;
            }
        }
    }
    Text {
        id: botVal
        text: "0"
        x: 50
        y: 586
        width:50
        height: textHeight
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment:  Text.AlignVCenter
        font.pointSize: 12

    }
    Text {
        id: topVal
        text: "1000"
        x: 50
        y: 26
        width:50
        height: textHeight
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment:  Text.AlignVCenter
        font.pointSize: 12
    }
}
