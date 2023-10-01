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
};

module Matrix = {
  /**
    [ ['a], ['a], ['a],
      ['a], ['a], ['a],
      ['a], ['a], ['a] ]
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
    |> List.mapOption(Matrix.at(_, m));
};

include Matrix;
