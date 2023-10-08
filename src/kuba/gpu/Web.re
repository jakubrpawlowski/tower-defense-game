let workerJSFilePath = "worker.js";

let myWorker = Worker.make(workerJSFilePath);

"123" |> Worker.postMessage(myWorker);

module App = {
  [@react.component]
  let make = () => <h1> "Hello!"->React.string </h1>;
};

ReactDOM.querySelector("#root")
|> Cat.Option.foldLazy(
     () =>
       Js.Console.error(
         "Failed to start React: couldn't find the #root element",
       ),
     ReactDOM.render(<App />),
   );
