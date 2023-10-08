type t;

// string here is a path to workers .js file
[@mel.new] external make: string => t = "Worker";

[@mel.send] external postMessage: (t, 'a) => unit = "postMessage";

module MessageEvent = {
  type t;

  [@mel.get] external data: t => 'a = "data";
};

[@mel.set]
external onMessage: (t, MessageEvent.t => unit) => unit = "onmessage";
