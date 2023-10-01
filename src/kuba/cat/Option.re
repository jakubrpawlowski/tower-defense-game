let pure = a => Some(a);

let fold = (default, f) =>
  fun
  | None => default
  | Some(a) => f(a);

let flatMap = f =>
  fun
  | Some(a) => a |> f
  | None => None;
