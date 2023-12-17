const { SerialPort } = require('serialport');
const {ReadlineParser } = require('@serialport/parser-readline');
const robot = require('robotjs');

// Substitua "COMx" pelo número da porta serial do Arduino (você pode verificar na IDE Arduino)
const port = new SerialPort({path:'COM3', baudRate: 9600 });
const parser = port.pipe(new ReadlineParser({ delimiter: '\n' }))

parser.on('data', (data) => {
  if (data.trim() === 'record') {
    robot.keyTap('f10', 'alt');
  }
  if (data.trim() === 'volume_down') {
    robot.keyTap('audio_vol_down');
  }
  if (data.trim() === 'volume_up') {
    robot.keyTap('audio_vol_up');
  }
  if (data.trim() === 'mute') {
    robot.keyTap('audio_mute');
  }
  if (data.trim() === 'audio_next') {
    robot.keyTap('audio_next');
  }
});
