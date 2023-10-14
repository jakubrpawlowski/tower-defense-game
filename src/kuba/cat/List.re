let rec makeWithDefault = default =>
  fun
  | i when i <= 0 => []
  | i => [default, ...makeWithDefault(default, i - 1)];

let rec length =
  fun
  | [] => 0
  | [_head, ...tail] => 1 + length(tail);

let rec at = (i, l) =>
  switch (i, l) {
  | (_, []) => None
  | (0, [head, ..._]) => Some(head)
  | (i, [_head, ...tail]) when i > 0 => at(i - 1, tail)
  | _ => None
  };

let rec map = f =>
  fun
  | [] => []
  | [head, ...tail] => [f(head), ...map(f, tail)];

let rec filter = f =>
  fun
  | [] => []
  | [head, ...tail] when f(head) => [head, ...filter(f, tail)]
  | [_head, ...tail] => filter(f, tail);

let rec mapOption = f =>
  fun
  | [] => []
  | [head, ...tail] =>
    switch (f(head)) {
    | Some(a) => [a, ...mapOption(f, tail)]
    | None => mapOption(f, tail)
    };

let rec filterOption = f =>
  fun
  | [] => []
  | [head, ...tail] =>
    switch (f(head)) {
    | Some(_) => [head, ...filterOption(f, tail)]
    | None => filterOption(f, tail)
    };
