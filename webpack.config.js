const path = require('path');

module.exports = {
  entry: {
    main: './_build/default/src/kuba/gpu/ui/src/kuba/gpu/Web.js',
    worker: './_build/default/src/kuba/cpu/engine/src/kuba/cpu/Web.js'
  },
  output: {
    filename: '[name].js',
    path: path.resolve(__dirname, 'public')
  },
  mode: 'development',
  devServer: {
    static: {
      directory: path.join(__dirname, 'public')
    },
    compress: true,
    port: 9000
  }
};
