open Cat.Function;

let arena = 0 |> Cat.Matrix.makeWithDefault(~down=6, ~right=6);

Worker.postMessageToMain("lol");

Worker.onMessageFromMain(Worker.MessageEvent.data >> Js.log);
