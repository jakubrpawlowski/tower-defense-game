open Function;

module Coordinate = {
  /**
    (1, 1), (1, 2), (1, 3),
    (2, 1), (2, 2), (2, 3),
    (3, 1), (3, 2), (3, 3)
  */
  type t = (int, int);

  let sum: (t, t) => t =
    ((downA, rightA), (downB, rightB)) => (downA + downB, rightA + rightB);

  /**
    (3,3) |> difference(~destination=(1,1)) // (-2, -2)
    (1,1) |> difference(~destination=(3,2)) // (2, 1)
    (3,1) |> difference(~destination=(1,2)) // (-2, 1)
   */
  let difference: (~destination: t, t) => t =
    (~destination as (downA, rightA), (downB, rightB)) => (
      downA - downB,
      rightA - rightB,
    );

  let abs = ((down, right)) => (down |> abs, right |> abs);
};

module Distance = {
  type t = int;

  let fromCoorinate: Coordinate.t => t =
    Coordinate.abs
    >> (
      fun
      | (vertical, horizontal) when vertical == horizontal => vertical * 14
      | (vertical, horizontal) when vertical > horizontal =>
        horizontal * 14 + (vertical - horizontal) * 10
      | (smaller, bigger) => smaller * 14 + (bigger - smaller) * 10
    );
};

module Matrix = {
  /**
    [ ['a, 'a, 'a],
      ['a, 'a, 'a],
      ['a, 'a, 'a] ]
  */
  type t('a) = list(list('a));

  let makeWithDefault: (~down: int, ~right: int, 'a) => option(t('a)) =
    (~down, ~right) =>
      switch (down, right) {
      | _ when down <= 0 || right <= 0 => (_ => None)
      | _ =>
        List.makeWithDefault(_, right)
        >> List.makeWithDefault(_, down)
        >> Option.pure
      };

  let at: (Coordinate.t, t('a)) => option('a) =
    ((down, right)) => List.at(down) >> Option.flatMap(List.at(right));
};

module Neighbors = {
  let offsets = Matrix_Neighbors.offsets;

  let get = (c, m) =>
    offsets
    |> List.map(Coordinate.sum(c))
    |> List.filterOption(Matrix.at(_, m));
};

include Matrix;
