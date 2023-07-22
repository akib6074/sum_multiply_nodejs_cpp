const addon = require('./build/Release/addon');
const multi = require('./build/Release/multiply');

const result = addon.add(5, 3);
const result_ = multi.multiply(3, 2);
console.log(result,result_);
