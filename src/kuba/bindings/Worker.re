type t;

/**
  string here is a path to workers .js file
*/
[@mel.new]
external make: string => t = "Worker";

[@mel.send] external postMessageToWorker: (t, 'a) => unit = "postMessage";

module MessageEvent = {
  type t;

  [@mel.get] external data: t => 'a = "data";
};

[@mel.set]
external onMessageFromWorker: (t, MessageEvent.t => unit) => unit =
  "onmessage";

external postMessageToMain: 'a => unit = "postMessage";

external onMessageFromMain: MessageEvent.t => unit = "onmessage";
