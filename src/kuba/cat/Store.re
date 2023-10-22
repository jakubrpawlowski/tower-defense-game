type t('a) = {
  state: 'a,
  setState: 'a => unit,
};

let create = (initialState: 'a) =>
  initialState
  |> ref
  |> (state => {state: state^, setState: newValue => state := newValue});
