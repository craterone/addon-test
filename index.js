const addon = require('./build/Release/hello')

const hello = ()=>{
    return addon.hello();
}

module.exports = {
    hello
};
  