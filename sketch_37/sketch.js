$(document).ready(function() {
    $(".typography").lettering();
});


function changeTsize(){
    var big = document.getElementsByClassName('.char1 .char3 .char5 .char7 .char9')
}

// function tsize() {

//  $('char1').css("font-size","10px");
// }
// console.log("hello")

$("button").click(function(){
    for(var i = 1; i<14; i++){
        if(i%2===0){

            $(".char"+i).css({"font-size": "10px"});
        }
    }
    console.log("yo");
});
// window.onload = tsize;