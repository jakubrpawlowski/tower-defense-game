type t;

/**
  string here is a path to workers .js file
*/
[@mel.new]
external make: string => t = "Worker";

[@mel.send] external postMessageToWorker: (t, 'a) => unit = "postMessage";

external postMessageToMain: 'a => unit = "postMessage";

module MessageEvent = {
  type t;

  [@mel.get] external data: t => 'a = "data";
};

[@mel.set]
external onMessage: (t, MessageEvent.t => unit) => unit = "onmessage";

external globalThis: t = "globalThis";
let onMessageFromMain = onMessage(globalThis);

let onMessageFromWorker = onMessage;
