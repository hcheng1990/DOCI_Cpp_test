
var stopsList = [];
var m = 64;
function newRectangle(val1,val2) {
    deleteRectangle();
    var rect = gradientRect.createObject(base);
    //rect.color = Qt.rgba(0,0,1,1);
    createMyGradient(val1,val2,rect);
}

function createMyGradient(val1,val2,rect) {
    var rgb = getRGBvalues();
    var r = rgb[0];
    var g = rgb[1];
    var b = rgb[2];
    for (var i = 0; i < m; i++){
        stopsList[i] = stopComponent.createObject(gradientRect, {
            "color": Qt.rgba(r[i], g[i], b[i], 1),
            "position": (val2*(i)+val1*(m-1-i))/(m-1)
        });
        /*
        console.log("r:" + r[i] + " g:" + g[i], ' b: ' + b[i] + " color: " +
                    stopsList[i].color + " Position: " + stopsList[i].position);
        */
    }

    rect.gradient.stops = stopsList;
}
function getRGBvalues(){
    var n = Math.ceil(m/4);
    var u = [];
    for (var i = 0; i < n; i++){
        u.push((i+1)/n);
    }
    for (var i = 0; i < n-1; i++){
        u.push(1);
    }
    for (var i = 0; i < n; i++){
        u.push((n-i)/n);
    }
    var g = new Array(u.length);
    var r = new Array(u.length);
    var b = new Array(u.length);
    for (var i = 0; i < u.length; i++){
        g[i] = Math.ceil(n/2) - ((m%4)==1) + (i+1);
        r[i] = g[i] + n;
        b[i] = g[i] - n;
    }
    var new_g = g.filter(function(x) {
        return x <= m;
    });
    var new_r = r.filter(function(x) {
        return x <= m;
    });
    var new_b = b.filter(function(x) {
        return x >= 1;
    });
    var final_r = Array.apply(null, Array(m)).map(Number.prototype.valueOf,0);
    var final_g = Array.apply(null, Array(m)).map(Number.prototype.valueOf,0);
    var final_b = Array.apply(null, Array(m)).map(Number.prototype.valueOf,0);
    for (var i = 0; i < new_r.length; i++){
        final_r[new_r[i]-1] = u[i];
    }
    for (var i = 0; i < new_g.length; i++){
        final_g[new_g[i]-1] = u[i];
    }
    for (var i = 0; i < new_b.length; i++){
        final_b[new_b[i]-1] = u[u.length-new_b.length+i];
    }
    return [final_r,final_g,final_b];
}
function deleteRectangle() {
    if(base.children.length > 0){
        for (var i = 0; i < base.children.length; i++){
            base.children[i].destroy();
        }
    }
}
