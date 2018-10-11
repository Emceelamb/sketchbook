var serialport = require('serialport');
var portName = process.argv[2]; 

var myPort = new serialport(portName, 9600);


var Readline = serialport.parsers.Readline;
var parser = new Readline();
myPort.pipe(parser);

myPort.on('open', showPortOpen);
parser.on('data', readSerialData);
myPort.on('close', showPortClose);
myPort.on('error', showError);

function showPortOpen(){
console.log('port open. data rate: ' + myPort.baudRate);
}

function readSerialDdata(data){
	console.log(data);
}

function readSerialData(data) {
	console.log(data);
}

function showPortClose(){
	console.log('port closed.');

}

function showError(error){
	console.log('Serial port error: ' +error);
}
