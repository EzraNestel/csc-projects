
var x = document.getElementById("canvasOne");
var ctx = x.getContext("2d");



function move() {
    setInterval(thing,30)
}

function thing(){
    ctx.font = "30px Arial";
    ctx.fillText("Sheesh",Math.random()*1000,Math.random()*680 + 10);
    ctx.stroke();
}