let compose = (f, g, a) => f(g(a));

let flipCompose = (f, g, a) => g(f(a));
/**
  and then
*/
let (>>) = flipCompose;
